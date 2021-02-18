/*
 *
 * Copyright (C) 2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * @file zes_ldrddi.cpp
 *
 */
#include "ze_loader.h"

namespace loader
{
    ///////////////////////////////////////////////////////////////////////////////
    zes_driver_factory_t                zes_driver_factory;
    zes_device_factory_t                zes_device_factory;
    zes_sched_factory_t                 zes_sched_factory;
    zes_perf_factory_t                  zes_perf_factory;
    zes_pwr_factory_t                   zes_pwr_factory;
    zes_freq_factory_t                  zes_freq_factory;
    zes_engine_factory_t                zes_engine_factory;
    zes_standby_factory_t               zes_standby_factory;
    zes_firmware_factory_t              zes_firmware_factory;
    zes_mem_factory_t                   zes_mem_factory;
    zes_fabric_port_factory_t           zes_fabric_port_factory;
    zes_temp_factory_t                  zes_temp_factory;
    zes_psu_factory_t                   zes_psu_factory;
    zes_fan_factory_t                   zes_fan_factory;
    zes_led_factory_t                   zes_led_factory;
    zes_ras_factory_t                   zes_ras_factory;
    zes_diag_factory_t                  zes_diag_factory;

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesDeviceGetProperties
    __zedlllocal ze_result_t ZE_APICALL
    zesDeviceGetProperties(
        zes_device_handle_t hDevice,                    ///< [in] Sysman handle of the device.
        zes_device_properties_t* pProperties            ///< [in,out] Structure that will contain information about the device.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_device_object_t*>( hDevice )->dditable;
        auto pfnGetProperties = dditable->zes.Device.pfnGetProperties;
        if( nullptr == pfnGetProperties )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDevice = reinterpret_cast<zes_device_object_t*>( hDevice )->handle;

        // forward to device-driver
        result = pfnGetProperties( hDevice, pProperties );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesDeviceGetState
    __zedlllocal ze_result_t ZE_APICALL
    zesDeviceGetState(
        zes_device_handle_t hDevice,                    ///< [in] Sysman handle of the device.
        zes_device_state_t* pState                      ///< [in,out] Structure that will contain information about the device.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_device_object_t*>( hDevice )->dditable;
        auto pfnGetState = dditable->zes.Device.pfnGetState;
        if( nullptr == pfnGetState )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDevice = reinterpret_cast<zes_device_object_t*>( hDevice )->handle;

        // forward to device-driver
        result = pfnGetState( hDevice, pState );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesDeviceReset
    __zedlllocal ze_result_t ZE_APICALL
    zesDeviceReset(
        zes_device_handle_t hDevice,                    ///< [in] Sysman handle for the device
        ze_bool_t force                                 ///< [in] If set to true, all applications that are currently using the
                                                        ///< device will be forcibly killed.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_device_object_t*>( hDevice )->dditable;
        auto pfnReset = dditable->zes.Device.pfnReset;
        if( nullptr == pfnReset )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDevice = reinterpret_cast<zes_device_object_t*>( hDevice )->handle;

        // forward to device-driver
        result = pfnReset( hDevice, force );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesDeviceProcessesGetState
    __zedlllocal ze_result_t ZE_APICALL
    zesDeviceProcessesGetState(
        zes_device_handle_t hDevice,                    ///< [in] Sysman handle for the device
        uint32_t* pCount,                               ///< [in,out] pointer to the number of processes.
                                                        ///< if count is zero, then the driver shall update the value with the
                                                        ///< total number of processes currently attached to the device.
                                                        ///< if count is greater than the number of processes currently attached to
                                                        ///< the device, then the driver shall update the value with the correct
                                                        ///< number of processes.
        zes_process_state_t* pProcesses                 ///< [in,out][optional][range(0, *pCount)] array of process information.
                                                        ///< if count is less than the number of processes currently attached to
                                                        ///< the device, then the driver shall only retrieve information about that
                                                        ///< number of processes. In this case, the return code will ::ZE_RESULT_ERROR_INVALID_SIZE.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_device_object_t*>( hDevice )->dditable;
        auto pfnProcessesGetState = dditable->zes.Device.pfnProcessesGetState;
        if( nullptr == pfnProcessesGetState )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDevice = reinterpret_cast<zes_device_object_t*>( hDevice )->handle;

        // forward to device-driver
        result = pfnProcessesGetState( hDevice, pCount, pProcesses );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesDevicePciGetProperties
    __zedlllocal ze_result_t ZE_APICALL
    zesDevicePciGetProperties(
        zes_device_handle_t hDevice,                    ///< [in] Sysman handle of the device.
        zes_pci_properties_t* pProperties               ///< [in,out] Will contain the PCI properties.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_device_object_t*>( hDevice )->dditable;
        auto pfnPciGetProperties = dditable->zes.Device.pfnPciGetProperties;
        if( nullptr == pfnPciGetProperties )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDevice = reinterpret_cast<zes_device_object_t*>( hDevice )->handle;

        // forward to device-driver
        result = pfnPciGetProperties( hDevice, pProperties );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesDevicePciGetState
    __zedlllocal ze_result_t ZE_APICALL
    zesDevicePciGetState(
        zes_device_handle_t hDevice,                    ///< [in] Sysman handle of the device.
        zes_pci_state_t* pState                         ///< [in,out] Will contain the PCI properties.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_device_object_t*>( hDevice )->dditable;
        auto pfnPciGetState = dditable->zes.Device.pfnPciGetState;
        if( nullptr == pfnPciGetState )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDevice = reinterpret_cast<zes_device_object_t*>( hDevice )->handle;

        // forward to device-driver
        result = pfnPciGetState( hDevice, pState );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesDevicePciGetBars
    __zedlllocal ze_result_t ZE_APICALL
    zesDevicePciGetBars(
        zes_device_handle_t hDevice,                    ///< [in] Sysman handle of the device.
        uint32_t* pCount,                               ///< [in,out] pointer to the number of PCI bars.
                                                        ///< if count is zero, then the driver shall update the value with the
                                                        ///< total number of PCI bars that are setup.
                                                        ///< if count is greater than the number of PCI bars that are setup, then
                                                        ///< the driver shall update the value with the correct number of PCI bars.
        zes_pci_bar_properties_t* pProperties           ///< [in,out][optional][range(0, *pCount)] array of information about setup
                                                        ///< PCI bars.
                                                        ///< if count is less than the number of PCI bars that are setup, then the
                                                        ///< driver shall only retrieve information about that number of PCI bars.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_device_object_t*>( hDevice )->dditable;
        auto pfnPciGetBars = dditable->zes.Device.pfnPciGetBars;
        if( nullptr == pfnPciGetBars )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDevice = reinterpret_cast<zes_device_object_t*>( hDevice )->handle;

        // forward to device-driver
        result = pfnPciGetBars( hDevice, pCount, pProperties );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesDevicePciGetStats
    __zedlllocal ze_result_t ZE_APICALL
    zesDevicePciGetStats(
        zes_device_handle_t hDevice,                    ///< [in] Sysman handle of the device.
        zes_pci_stats_t* pStats                         ///< [in,out] Will contain a snapshot of the latest stats.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_device_object_t*>( hDevice )->dditable;
        auto pfnPciGetStats = dditable->zes.Device.pfnPciGetStats;
        if( nullptr == pfnPciGetStats )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDevice = reinterpret_cast<zes_device_object_t*>( hDevice )->handle;

        // forward to device-driver
        result = pfnPciGetStats( hDevice, pStats );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesDeviceEnumDiagnosticTestSuites
    __zedlllocal ze_result_t ZE_APICALL
    zesDeviceEnumDiagnosticTestSuites(
        zes_device_handle_t hDevice,                    ///< [in] Sysman handle of the device.
        uint32_t* pCount,                               ///< [in,out] pointer to the number of components of this type.
                                                        ///< if count is zero, then the driver shall update the value with the
                                                        ///< total number of components of this type that are available.
                                                        ///< if count is greater than the number of components of this type that
                                                        ///< are available, then the driver shall update the value with the correct
                                                        ///< number of components.
        zes_diag_handle_t* phDiagnostics                ///< [in,out][optional][range(0, *pCount)] array of handle of components of
                                                        ///< this type.
                                                        ///< if count is less than the number of components of this type that are
                                                        ///< available, then the driver shall only retrieve that number of
                                                        ///< component handles.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_device_object_t*>( hDevice )->dditable;
        auto pfnEnumDiagnosticTestSuites = dditable->zes.Device.pfnEnumDiagnosticTestSuites;
        if( nullptr == pfnEnumDiagnosticTestSuites )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDevice = reinterpret_cast<zes_device_object_t*>( hDevice )->handle;

        // forward to device-driver
        result = pfnEnumDiagnosticTestSuites( hDevice, pCount, phDiagnostics );

        if( ZE_RESULT_SUCCESS != result )
            return result;

        try
        {
            // convert driver handles to loader handles
            for( size_t i = 0; ( nullptr != phDiagnostics ) && ( i < *pCount ); ++i )
                phDiagnostics[ i ] = reinterpret_cast<zes_diag_handle_t>(
                    zes_diag_factory.getInstance( phDiagnostics[ i ], dditable ) );
        }
        catch( std::bad_alloc& )
        {
            result = ZE_RESULT_ERROR_OUT_OF_HOST_MEMORY;
        }

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesDiagnosticsGetProperties
    __zedlllocal ze_result_t ZE_APICALL
    zesDiagnosticsGetProperties(
        zes_diag_handle_t hDiagnostics,                 ///< [in] Handle for the component.
        zes_diag_properties_t* pProperties              ///< [in,out] Structure describing the properties of a diagnostics test
                                                        ///< suite
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_diag_object_t*>( hDiagnostics )->dditable;
        auto pfnGetProperties = dditable->zes.Diagnostics.pfnGetProperties;
        if( nullptr == pfnGetProperties )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDiagnostics = reinterpret_cast<zes_diag_object_t*>( hDiagnostics )->handle;

        // forward to device-driver
        result = pfnGetProperties( hDiagnostics, pProperties );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesDiagnosticsGetTests
    __zedlllocal ze_result_t ZE_APICALL
    zesDiagnosticsGetTests(
        zes_diag_handle_t hDiagnostics,                 ///< [in] Handle for the component.
        uint32_t* pCount,                               ///< [in,out] pointer to the number of tests.
                                                        ///< if count is zero, then the driver shall update the value with the
                                                        ///< total number of tests that are available.
                                                        ///< if count is greater than the number of tests that are available, then
                                                        ///< the driver shall update the value with the correct number of tests.
        zes_diag_test_t* pTests                         ///< [in,out][optional][range(0, *pCount)] array of information about
                                                        ///< individual tests sorted by increasing value of ::zes_diag_test_t.index.
                                                        ///< if count is less than the number of tests that are available, then the
                                                        ///< driver shall only retrieve that number of tests.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_diag_object_t*>( hDiagnostics )->dditable;
        auto pfnGetTests = dditable->zes.Diagnostics.pfnGetTests;
        if( nullptr == pfnGetTests )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDiagnostics = reinterpret_cast<zes_diag_object_t*>( hDiagnostics )->handle;

        // forward to device-driver
        result = pfnGetTests( hDiagnostics, pCount, pTests );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesDiagnosticsRunTests
    __zedlllocal ze_result_t ZE_APICALL
    zesDiagnosticsRunTests(
        zes_diag_handle_t hDiagnostics,                 ///< [in] Handle for the component.
        uint32_t start,                                 ///< [in] The index of the first test to run. Set to
                                                        ///< ::ZES_DIAG_FIRST_TEST_INDEX to start from the beginning.
        uint32_t end,                                   ///< [in] The index of the last test to run. Set to
                                                        ///< ::ZES_DIAG_LAST_TEST_INDEX to complete all tests after the start test.
        zes_diag_result_t* pResult                      ///< [in,out] The result of the diagnostics
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_diag_object_t*>( hDiagnostics )->dditable;
        auto pfnRunTests = dditable->zes.Diagnostics.pfnRunTests;
        if( nullptr == pfnRunTests )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDiagnostics = reinterpret_cast<zes_diag_object_t*>( hDiagnostics )->handle;

        // forward to device-driver
        result = pfnRunTests( hDiagnostics, start, end, pResult );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesDeviceEnumEngineGroups
    __zedlllocal ze_result_t ZE_APICALL
    zesDeviceEnumEngineGroups(
        zes_device_handle_t hDevice,                    ///< [in] Sysman handle of the device.
        uint32_t* pCount,                               ///< [in,out] pointer to the number of components of this type.
                                                        ///< if count is zero, then the driver shall update the value with the
                                                        ///< total number of components of this type that are available.
                                                        ///< if count is greater than the number of components of this type that
                                                        ///< are available, then the driver shall update the value with the correct
                                                        ///< number of components.
        zes_engine_handle_t* phEngine                   ///< [in,out][optional][range(0, *pCount)] array of handle of components of
                                                        ///< this type.
                                                        ///< if count is less than the number of components of this type that are
                                                        ///< available, then the driver shall only retrieve that number of
                                                        ///< component handles.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_device_object_t*>( hDevice )->dditable;
        auto pfnEnumEngineGroups = dditable->zes.Device.pfnEnumEngineGroups;
        if( nullptr == pfnEnumEngineGroups )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDevice = reinterpret_cast<zes_device_object_t*>( hDevice )->handle;

        // forward to device-driver
        result = pfnEnumEngineGroups( hDevice, pCount, phEngine );

        if( ZE_RESULT_SUCCESS != result )
            return result;

        try
        {
            // convert driver handles to loader handles
            for( size_t i = 0; ( nullptr != phEngine ) && ( i < *pCount ); ++i )
                phEngine[ i ] = reinterpret_cast<zes_engine_handle_t>(
                    zes_engine_factory.getInstance( phEngine[ i ], dditable ) );
        }
        catch( std::bad_alloc& )
        {
            result = ZE_RESULT_ERROR_OUT_OF_HOST_MEMORY;
        }

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesEngineGetProperties
    __zedlllocal ze_result_t ZE_APICALL
    zesEngineGetProperties(
        zes_engine_handle_t hEngine,                    ///< [in] Handle for the component.
        zes_engine_properties_t* pProperties            ///< [in,out] The properties for the specified engine group.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_engine_object_t*>( hEngine )->dditable;
        auto pfnGetProperties = dditable->zes.Engine.pfnGetProperties;
        if( nullptr == pfnGetProperties )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hEngine = reinterpret_cast<zes_engine_object_t*>( hEngine )->handle;

        // forward to device-driver
        result = pfnGetProperties( hEngine, pProperties );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesEngineGetActivity
    __zedlllocal ze_result_t ZE_APICALL
    zesEngineGetActivity(
        zes_engine_handle_t hEngine,                    ///< [in] Handle for the component.
        zes_engine_stats_t* pStats                      ///< [in,out] Will contain a snapshot of the engine group activity
                                                        ///< counters.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_engine_object_t*>( hEngine )->dditable;
        auto pfnGetActivity = dditable->zes.Engine.pfnGetActivity;
        if( nullptr == pfnGetActivity )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hEngine = reinterpret_cast<zes_engine_object_t*>( hEngine )->handle;

        // forward to device-driver
        result = pfnGetActivity( hEngine, pStats );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesDeviceEventRegister
    __zedlllocal ze_result_t ZE_APICALL
    zesDeviceEventRegister(
        zes_device_handle_t hDevice,                    ///< [in] The device handle.
        zes_event_type_flags_t events                   ///< [in] List of events to listen to.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_device_object_t*>( hDevice )->dditable;
        auto pfnEventRegister = dditable->zes.Device.pfnEventRegister;
        if( nullptr == pfnEventRegister )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDevice = reinterpret_cast<zes_device_object_t*>( hDevice )->handle;

        // forward to device-driver
        result = pfnEventRegister( hDevice, events );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesDriverEventListen
    __zedlllocal ze_result_t ZE_APICALL
    zesDriverEventListen(
        ze_driver_handle_t hDriver,                     ///< [in] handle of the driver instance
        uint32_t timeout,                               ///< [in] if non-zero, then indicates the maximum time (in milliseconds) to
                                                        ///< yield before returning ::ZE_RESULT_SUCCESS or ::ZE_RESULT_NOT_READY;
                                                        ///< if zero, then will check status and return immediately;
                                                        ///< if UINT32_MAX, then function will not return until events arrive.
        uint32_t count,                                 ///< [in] Number of device handles in phDevices.
        zes_device_handle_t* phDevices,                 ///< [in][range(0, count)] Device handles to listen to for events. Only
                                                        ///< devices from the provided driver handle can be specified in this list.
        uint32_t* pNumDeviceEvents,                     ///< [in,out] Will contain the actual number of devices in phDevices that
                                                        ///< generated events. If non-zero, check pEvents to determine the devices
                                                        ///< and events that were received.
        zes_event_type_flags_t* pEvents                 ///< [in,out] An array that will continue the list of events for each
                                                        ///< device listened in phDevices.
                                                        ///< This array must be at least as big as count.
                                                        ///< For every device handle in phDevices, this will provide the events
                                                        ///< that occurred for that device at the same position in this array. If
                                                        ///< no event was received for a given device, the corresponding array
                                                        ///< entry will be zero.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<ze_driver_object_t*>( hDriver )->dditable;
        auto pfnEventListen = dditable->zes.Driver.pfnEventListen;
        if( nullptr == pfnEventListen )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDriver = reinterpret_cast<ze_driver_object_t*>( hDriver )->handle;

        // convert loader handles to driver handles
        for( size_t i = 0; ( nullptr != phDevices ) && ( i < count ); ++i )
            phDevices[ i ] = reinterpret_cast<zes_device_object_t*>( phDevices[ i ] )->handle;

        // forward to device-driver
        result = pfnEventListen( hDriver, timeout, count, phDevices, pNumDeviceEvents, pEvents );

        // convert driver handles back to loader handles
        for ( size_t i = 0; ( nullptr != phDevices ) && ( i < count ); ++i )
            phDevices[ i ] = reinterpret_cast<zes_device_handle_t>( zes_device_factory.getInstance( phDevices[ i ], dditable ) );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesDriverEventListenEx
    __zedlllocal ze_result_t ZE_APICALL
    zesDriverEventListenEx(
        ze_driver_handle_t hDriver,                     ///< [in] handle of the driver instance
        uint64_t timeout,                               ///< [in] if non-zero, then indicates the maximum time (in milliseconds) to
                                                        ///< yield before returning ::ZE_RESULT_SUCCESS or ::ZE_RESULT_NOT_READY;
                                                        ///< if zero, then will check status and return immediately;
                                                        ///< if UINT64_MAX, then function will not return until events arrive.
        uint32_t count,                                 ///< [in] Number of device handles in phDevices.
        zes_device_handle_t* phDevices,                 ///< [in][range(0, count)] Device handles to listen to for events. Only
                                                        ///< devices from the provided driver handle can be specified in this list.
        uint32_t* pNumDeviceEvents,                     ///< [in,out] Will contain the actual number of devices in phDevices that
                                                        ///< generated events. If non-zero, check pEvents to determine the devices
                                                        ///< and events that were received.
        zes_event_type_flags_t* pEvents                 ///< [in,out] An array that will continue the list of events for each
                                                        ///< device listened in phDevices.
                                                        ///< This array must be at least as big as count.
                                                        ///< For every device handle in phDevices, this will provide the events
                                                        ///< that occurred for that device at the same position in this array. If
                                                        ///< no event was received for a given device, the corresponding array
                                                        ///< entry will be zero.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<ze_driver_object_t*>( hDriver )->dditable;
        auto pfnEventListenEx = dditable->zes.Driver.pfnEventListenEx;
        if( nullptr == pfnEventListenEx )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDriver = reinterpret_cast<ze_driver_object_t*>( hDriver )->handle;

        // convert loader handles to driver handles
        for( size_t i = 0; ( nullptr != phDevices ) && ( i < count ); ++i )
            phDevices[ i ] = reinterpret_cast<zes_device_object_t*>( phDevices[ i ] )->handle;

        // forward to device-driver
        result = pfnEventListenEx( hDriver, timeout, count, phDevices, pNumDeviceEvents, pEvents );

        // convert driver handles back to loader handles
        for ( size_t i = 0; ( nullptr != phDevices ) && ( i < count ); ++i )
            phDevices[ i ] = reinterpret_cast<zes_device_handle_t>( zes_device_factory.getInstance( phDevices[ i ], dditable ) );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesDeviceEnumFabricPorts
    __zedlllocal ze_result_t ZE_APICALL
    zesDeviceEnumFabricPorts(
        zes_device_handle_t hDevice,                    ///< [in] Sysman handle of the device.
        uint32_t* pCount,                               ///< [in,out] pointer to the number of components of this type.
                                                        ///< if count is zero, then the driver shall update the value with the
                                                        ///< total number of components of this type that are available.
                                                        ///< if count is greater than the number of components of this type that
                                                        ///< are available, then the driver shall update the value with the correct
                                                        ///< number of components.
        zes_fabric_port_handle_t* phPort                ///< [in,out][optional][range(0, *pCount)] array of handle of components of
                                                        ///< this type.
                                                        ///< if count is less than the number of components of this type that are
                                                        ///< available, then the driver shall only retrieve that number of
                                                        ///< component handles.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_device_object_t*>( hDevice )->dditable;
        auto pfnEnumFabricPorts = dditable->zes.Device.pfnEnumFabricPorts;
        if( nullptr == pfnEnumFabricPorts )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDevice = reinterpret_cast<zes_device_object_t*>( hDevice )->handle;

        // forward to device-driver
        result = pfnEnumFabricPorts( hDevice, pCount, phPort );

        if( ZE_RESULT_SUCCESS != result )
            return result;

        try
        {
            // convert driver handles to loader handles
            for( size_t i = 0; ( nullptr != phPort ) && ( i < *pCount ); ++i )
                phPort[ i ] = reinterpret_cast<zes_fabric_port_handle_t>(
                    zes_fabric_port_factory.getInstance( phPort[ i ], dditable ) );
        }
        catch( std::bad_alloc& )
        {
            result = ZE_RESULT_ERROR_OUT_OF_HOST_MEMORY;
        }

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesFabricPortGetProperties
    __zedlllocal ze_result_t ZE_APICALL
    zesFabricPortGetProperties(
        zes_fabric_port_handle_t hPort,                 ///< [in] Handle for the component.
        zes_fabric_port_properties_t* pProperties       ///< [in,out] Will contain properties of the Fabric Port.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_fabric_port_object_t*>( hPort )->dditable;
        auto pfnGetProperties = dditable->zes.FabricPort.pfnGetProperties;
        if( nullptr == pfnGetProperties )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hPort = reinterpret_cast<zes_fabric_port_object_t*>( hPort )->handle;

        // forward to device-driver
        result = pfnGetProperties( hPort, pProperties );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesFabricPortGetLinkType
    __zedlllocal ze_result_t ZE_APICALL
    zesFabricPortGetLinkType(
        zes_fabric_port_handle_t hPort,                 ///< [in] Handle for the component.
        zes_fabric_link_type_t* pLinkType               ///< [in,out] Will contain details about the link attached to the Fabric
                                                        ///< port.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_fabric_port_object_t*>( hPort )->dditable;
        auto pfnGetLinkType = dditable->zes.FabricPort.pfnGetLinkType;
        if( nullptr == pfnGetLinkType )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hPort = reinterpret_cast<zes_fabric_port_object_t*>( hPort )->handle;

        // forward to device-driver
        result = pfnGetLinkType( hPort, pLinkType );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesFabricPortGetConfig
    __zedlllocal ze_result_t ZE_APICALL
    zesFabricPortGetConfig(
        zes_fabric_port_handle_t hPort,                 ///< [in] Handle for the component.
        zes_fabric_port_config_t* pConfig               ///< [in,out] Will contain configuration of the Fabric Port.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_fabric_port_object_t*>( hPort )->dditable;
        auto pfnGetConfig = dditable->zes.FabricPort.pfnGetConfig;
        if( nullptr == pfnGetConfig )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hPort = reinterpret_cast<zes_fabric_port_object_t*>( hPort )->handle;

        // forward to device-driver
        result = pfnGetConfig( hPort, pConfig );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesFabricPortSetConfig
    __zedlllocal ze_result_t ZE_APICALL
    zesFabricPortSetConfig(
        zes_fabric_port_handle_t hPort,                 ///< [in] Handle for the component.
        const zes_fabric_port_config_t* pConfig         ///< [in] Contains new configuration of the Fabric Port.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_fabric_port_object_t*>( hPort )->dditable;
        auto pfnSetConfig = dditable->zes.FabricPort.pfnSetConfig;
        if( nullptr == pfnSetConfig )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hPort = reinterpret_cast<zes_fabric_port_object_t*>( hPort )->handle;

        // forward to device-driver
        result = pfnSetConfig( hPort, pConfig );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesFabricPortGetState
    __zedlllocal ze_result_t ZE_APICALL
    zesFabricPortGetState(
        zes_fabric_port_handle_t hPort,                 ///< [in] Handle for the component.
        zes_fabric_port_state_t* pState                 ///< [in,out] Will contain the current state of the Fabric Port
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_fabric_port_object_t*>( hPort )->dditable;
        auto pfnGetState = dditable->zes.FabricPort.pfnGetState;
        if( nullptr == pfnGetState )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hPort = reinterpret_cast<zes_fabric_port_object_t*>( hPort )->handle;

        // forward to device-driver
        result = pfnGetState( hPort, pState );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesFabricPortGetThroughput
    __zedlllocal ze_result_t ZE_APICALL
    zesFabricPortGetThroughput(
        zes_fabric_port_handle_t hPort,                 ///< [in] Handle for the component.
        zes_fabric_port_throughput_t* pThroughput       ///< [in,out] Will contain the Fabric port throughput counters.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_fabric_port_object_t*>( hPort )->dditable;
        auto pfnGetThroughput = dditable->zes.FabricPort.pfnGetThroughput;
        if( nullptr == pfnGetThroughput )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hPort = reinterpret_cast<zes_fabric_port_object_t*>( hPort )->handle;

        // forward to device-driver
        result = pfnGetThroughput( hPort, pThroughput );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesDeviceEnumFans
    __zedlllocal ze_result_t ZE_APICALL
    zesDeviceEnumFans(
        zes_device_handle_t hDevice,                    ///< [in] Sysman handle of the device.
        uint32_t* pCount,                               ///< [in,out] pointer to the number of components of this type.
                                                        ///< if count is zero, then the driver shall update the value with the
                                                        ///< total number of components of this type that are available.
                                                        ///< if count is greater than the number of components of this type that
                                                        ///< are available, then the driver shall update the value with the correct
                                                        ///< number of components.
        zes_fan_handle_t* phFan                         ///< [in,out][optional][range(0, *pCount)] array of handle of components of
                                                        ///< this type.
                                                        ///< if count is less than the number of components of this type that are
                                                        ///< available, then the driver shall only retrieve that number of
                                                        ///< component handles.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_device_object_t*>( hDevice )->dditable;
        auto pfnEnumFans = dditable->zes.Device.pfnEnumFans;
        if( nullptr == pfnEnumFans )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDevice = reinterpret_cast<zes_device_object_t*>( hDevice )->handle;

        // forward to device-driver
        result = pfnEnumFans( hDevice, pCount, phFan );

        if( ZE_RESULT_SUCCESS != result )
            return result;

        try
        {
            // convert driver handles to loader handles
            for( size_t i = 0; ( nullptr != phFan ) && ( i < *pCount ); ++i )
                phFan[ i ] = reinterpret_cast<zes_fan_handle_t>(
                    zes_fan_factory.getInstance( phFan[ i ], dditable ) );
        }
        catch( std::bad_alloc& )
        {
            result = ZE_RESULT_ERROR_OUT_OF_HOST_MEMORY;
        }

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesFanGetProperties
    __zedlllocal ze_result_t ZE_APICALL
    zesFanGetProperties(
        zes_fan_handle_t hFan,                          ///< [in] Handle for the component.
        zes_fan_properties_t* pProperties               ///< [in,out] Will contain the properties of the fan.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_fan_object_t*>( hFan )->dditable;
        auto pfnGetProperties = dditable->zes.Fan.pfnGetProperties;
        if( nullptr == pfnGetProperties )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hFan = reinterpret_cast<zes_fan_object_t*>( hFan )->handle;

        // forward to device-driver
        result = pfnGetProperties( hFan, pProperties );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesFanGetConfig
    __zedlllocal ze_result_t ZE_APICALL
    zesFanGetConfig(
        zes_fan_handle_t hFan,                          ///< [in] Handle for the component.
        zes_fan_config_t* pConfig                       ///< [in,out] Will contain the current configuration of the fan.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_fan_object_t*>( hFan )->dditable;
        auto pfnGetConfig = dditable->zes.Fan.pfnGetConfig;
        if( nullptr == pfnGetConfig )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hFan = reinterpret_cast<zes_fan_object_t*>( hFan )->handle;

        // forward to device-driver
        result = pfnGetConfig( hFan, pConfig );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesFanSetDefaultMode
    __zedlllocal ze_result_t ZE_APICALL
    zesFanSetDefaultMode(
        zes_fan_handle_t hFan                           ///< [in] Handle for the component.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_fan_object_t*>( hFan )->dditable;
        auto pfnSetDefaultMode = dditable->zes.Fan.pfnSetDefaultMode;
        if( nullptr == pfnSetDefaultMode )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hFan = reinterpret_cast<zes_fan_object_t*>( hFan )->handle;

        // forward to device-driver
        result = pfnSetDefaultMode( hFan );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesFanSetFixedSpeedMode
    __zedlllocal ze_result_t ZE_APICALL
    zesFanSetFixedSpeedMode(
        zes_fan_handle_t hFan,                          ///< [in] Handle for the component.
        const zes_fan_speed_t* speed                    ///< [in] The fixed fan speed setting
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_fan_object_t*>( hFan )->dditable;
        auto pfnSetFixedSpeedMode = dditable->zes.Fan.pfnSetFixedSpeedMode;
        if( nullptr == pfnSetFixedSpeedMode )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hFan = reinterpret_cast<zes_fan_object_t*>( hFan )->handle;

        // forward to device-driver
        result = pfnSetFixedSpeedMode( hFan, speed );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesFanSetSpeedTableMode
    __zedlllocal ze_result_t ZE_APICALL
    zesFanSetSpeedTableMode(
        zes_fan_handle_t hFan,                          ///< [in] Handle for the component.
        const zes_fan_speed_table_t* speedTable         ///< [in] A table containing temperature/speed pairs.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_fan_object_t*>( hFan )->dditable;
        auto pfnSetSpeedTableMode = dditable->zes.Fan.pfnSetSpeedTableMode;
        if( nullptr == pfnSetSpeedTableMode )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hFan = reinterpret_cast<zes_fan_object_t*>( hFan )->handle;

        // forward to device-driver
        result = pfnSetSpeedTableMode( hFan, speedTable );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesFanGetState
    __zedlllocal ze_result_t ZE_APICALL
    zesFanGetState(
        zes_fan_handle_t hFan,                          ///< [in] Handle for the component.
        zes_fan_speed_units_t units,                    ///< [in] The units in which the fan speed should be returned.
        int32_t* pSpeed                                 ///< [in,out] Will contain the current speed of the fan in the units
                                                        ///< requested. A value of -1 indicates that the fan speed cannot be
                                                        ///< measured.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_fan_object_t*>( hFan )->dditable;
        auto pfnGetState = dditable->zes.Fan.pfnGetState;
        if( nullptr == pfnGetState )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hFan = reinterpret_cast<zes_fan_object_t*>( hFan )->handle;

        // forward to device-driver
        result = pfnGetState( hFan, units, pSpeed );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesDeviceEnumFirmwares
    __zedlllocal ze_result_t ZE_APICALL
    zesDeviceEnumFirmwares(
        zes_device_handle_t hDevice,                    ///< [in] Sysman handle of the device.
        uint32_t* pCount,                               ///< [in,out] pointer to the number of components of this type.
                                                        ///< if count is zero, then the driver shall update the value with the
                                                        ///< total number of components of this type that are available.
                                                        ///< if count is greater than the number of components of this type that
                                                        ///< are available, then the driver shall update the value with the correct
                                                        ///< number of components.
        zes_firmware_handle_t* phFirmware               ///< [in,out][optional][range(0, *pCount)] array of handle of components of
                                                        ///< this type.
                                                        ///< if count is less than the number of components of this type that are
                                                        ///< available, then the driver shall only retrieve that number of
                                                        ///< component handles.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_device_object_t*>( hDevice )->dditable;
        auto pfnEnumFirmwares = dditable->zes.Device.pfnEnumFirmwares;
        if( nullptr == pfnEnumFirmwares )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDevice = reinterpret_cast<zes_device_object_t*>( hDevice )->handle;

        // forward to device-driver
        result = pfnEnumFirmwares( hDevice, pCount, phFirmware );

        if( ZE_RESULT_SUCCESS != result )
            return result;

        try
        {
            // convert driver handles to loader handles
            for( size_t i = 0; ( nullptr != phFirmware ) && ( i < *pCount ); ++i )
                phFirmware[ i ] = reinterpret_cast<zes_firmware_handle_t>(
                    zes_firmware_factory.getInstance( phFirmware[ i ], dditable ) );
        }
        catch( std::bad_alloc& )
        {
            result = ZE_RESULT_ERROR_OUT_OF_HOST_MEMORY;
        }

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesFirmwareGetProperties
    __zedlllocal ze_result_t ZE_APICALL
    zesFirmwareGetProperties(
        zes_firmware_handle_t hFirmware,                ///< [in] Handle for the component.
        zes_firmware_properties_t* pProperties          ///< [in,out] Pointer to an array that will hold the properties of the
                                                        ///< firmware
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_firmware_object_t*>( hFirmware )->dditable;
        auto pfnGetProperties = dditable->zes.Firmware.pfnGetProperties;
        if( nullptr == pfnGetProperties )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hFirmware = reinterpret_cast<zes_firmware_object_t*>( hFirmware )->handle;

        // forward to device-driver
        result = pfnGetProperties( hFirmware, pProperties );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesFirmwareFlash
    __zedlllocal ze_result_t ZE_APICALL
    zesFirmwareFlash(
        zes_firmware_handle_t hFirmware,                ///< [in] Handle for the component.
        void* pImage,                                   ///< [in] Image of the new firmware to flash.
        uint32_t size                                   ///< [in] Size of the flash image.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_firmware_object_t*>( hFirmware )->dditable;
        auto pfnFlash = dditable->zes.Firmware.pfnFlash;
        if( nullptr == pfnFlash )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hFirmware = reinterpret_cast<zes_firmware_object_t*>( hFirmware )->handle;

        // forward to device-driver
        result = pfnFlash( hFirmware, pImage, size );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesDeviceEnumFrequencyDomains
    __zedlllocal ze_result_t ZE_APICALL
    zesDeviceEnumFrequencyDomains(
        zes_device_handle_t hDevice,                    ///< [in] Sysman handle of the device.
        uint32_t* pCount,                               ///< [in,out] pointer to the number of components of this type.
                                                        ///< if count is zero, then the driver shall update the value with the
                                                        ///< total number of components of this type that are available.
                                                        ///< if count is greater than the number of components of this type that
                                                        ///< are available, then the driver shall update the value with the correct
                                                        ///< number of components.
        zes_freq_handle_t* phFrequency                  ///< [in,out][optional][range(0, *pCount)] array of handle of components of
                                                        ///< this type.
                                                        ///< if count is less than the number of components of this type that are
                                                        ///< available, then the driver shall only retrieve that number of
                                                        ///< component handles.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_device_object_t*>( hDevice )->dditable;
        auto pfnEnumFrequencyDomains = dditable->zes.Device.pfnEnumFrequencyDomains;
        if( nullptr == pfnEnumFrequencyDomains )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDevice = reinterpret_cast<zes_device_object_t*>( hDevice )->handle;

        // forward to device-driver
        result = pfnEnumFrequencyDomains( hDevice, pCount, phFrequency );

        if( ZE_RESULT_SUCCESS != result )
            return result;

        try
        {
            // convert driver handles to loader handles
            for( size_t i = 0; ( nullptr != phFrequency ) && ( i < *pCount ); ++i )
                phFrequency[ i ] = reinterpret_cast<zes_freq_handle_t>(
                    zes_freq_factory.getInstance( phFrequency[ i ], dditable ) );
        }
        catch( std::bad_alloc& )
        {
            result = ZE_RESULT_ERROR_OUT_OF_HOST_MEMORY;
        }

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesFrequencyGetProperties
    __zedlllocal ze_result_t ZE_APICALL
    zesFrequencyGetProperties(
        zes_freq_handle_t hFrequency,                   ///< [in] Handle for the component.
        zes_freq_properties_t* pProperties              ///< [in,out] The frequency properties for the specified domain.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_freq_object_t*>( hFrequency )->dditable;
        auto pfnGetProperties = dditable->zes.Frequency.pfnGetProperties;
        if( nullptr == pfnGetProperties )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hFrequency = reinterpret_cast<zes_freq_object_t*>( hFrequency )->handle;

        // forward to device-driver
        result = pfnGetProperties( hFrequency, pProperties );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesFrequencyGetAvailableClocks
    __zedlllocal ze_result_t ZE_APICALL
    zesFrequencyGetAvailableClocks(
        zes_freq_handle_t hFrequency,                   ///< [in] Sysman handle of the device.
        uint32_t* pCount,                               ///< [in,out] pointer to the number of frequencies.
                                                        ///< if count is zero, then the driver shall update the value with the
                                                        ///< total number of frequencies that are available.
                                                        ///< if count is greater than the number of frequencies that are available,
                                                        ///< then the driver shall update the value with the correct number of frequencies.
        double* phFrequency                             ///< [in,out][optional][range(0, *pCount)] array of frequencies in units of
                                                        ///< MHz and sorted from slowest to fastest.
                                                        ///< if count is less than the number of frequencies that are available,
                                                        ///< then the driver shall only retrieve that number of frequencies.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_freq_object_t*>( hFrequency )->dditable;
        auto pfnGetAvailableClocks = dditable->zes.Frequency.pfnGetAvailableClocks;
        if( nullptr == pfnGetAvailableClocks )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hFrequency = reinterpret_cast<zes_freq_object_t*>( hFrequency )->handle;

        // forward to device-driver
        result = pfnGetAvailableClocks( hFrequency, pCount, phFrequency );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesFrequencyGetRange
    __zedlllocal ze_result_t ZE_APICALL
    zesFrequencyGetRange(
        zes_freq_handle_t hFrequency,                   ///< [in] Handle for the component.
        zes_freq_range_t* pLimits                       ///< [in,out] The range between which the hardware can operate for the
                                                        ///< specified domain.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_freq_object_t*>( hFrequency )->dditable;
        auto pfnGetRange = dditable->zes.Frequency.pfnGetRange;
        if( nullptr == pfnGetRange )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hFrequency = reinterpret_cast<zes_freq_object_t*>( hFrequency )->handle;

        // forward to device-driver
        result = pfnGetRange( hFrequency, pLimits );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesFrequencySetRange
    __zedlllocal ze_result_t ZE_APICALL
    zesFrequencySetRange(
        zes_freq_handle_t hFrequency,                   ///< [in] Handle for the component.
        const zes_freq_range_t* pLimits                 ///< [in] The limits between which the hardware can operate for the
                                                        ///< specified domain.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_freq_object_t*>( hFrequency )->dditable;
        auto pfnSetRange = dditable->zes.Frequency.pfnSetRange;
        if( nullptr == pfnSetRange )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hFrequency = reinterpret_cast<zes_freq_object_t*>( hFrequency )->handle;

        // forward to device-driver
        result = pfnSetRange( hFrequency, pLimits );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesFrequencyGetState
    __zedlllocal ze_result_t ZE_APICALL
    zesFrequencyGetState(
        zes_freq_handle_t hFrequency,                   ///< [in] Handle for the component.
        zes_freq_state_t* pState                        ///< [in,out] Frequency state for the specified domain.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_freq_object_t*>( hFrequency )->dditable;
        auto pfnGetState = dditable->zes.Frequency.pfnGetState;
        if( nullptr == pfnGetState )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hFrequency = reinterpret_cast<zes_freq_object_t*>( hFrequency )->handle;

        // forward to device-driver
        result = pfnGetState( hFrequency, pState );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesFrequencyGetThrottleTime
    __zedlllocal ze_result_t ZE_APICALL
    zesFrequencyGetThrottleTime(
        zes_freq_handle_t hFrequency,                   ///< [in] Handle for the component.
        zes_freq_throttle_time_t* pThrottleTime         ///< [in,out] Will contain a snapshot of the throttle time counters for the
                                                        ///< specified domain.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_freq_object_t*>( hFrequency )->dditable;
        auto pfnGetThrottleTime = dditable->zes.Frequency.pfnGetThrottleTime;
        if( nullptr == pfnGetThrottleTime )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hFrequency = reinterpret_cast<zes_freq_object_t*>( hFrequency )->handle;

        // forward to device-driver
        result = pfnGetThrottleTime( hFrequency, pThrottleTime );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesFrequencyOcGetCapabilities
    __zedlllocal ze_result_t ZE_APICALL
    zesFrequencyOcGetCapabilities(
        zes_freq_handle_t hFrequency,                   ///< [in] Handle for the component.
        zes_oc_capabilities_t* pOcCapabilities          ///< [in,out] Pointer to the capabilities structure
                                                        ///< ::zes_oc_capabilities_t.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_freq_object_t*>( hFrequency )->dditable;
        auto pfnOcGetCapabilities = dditable->zes.Frequency.pfnOcGetCapabilities;
        if( nullptr == pfnOcGetCapabilities )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hFrequency = reinterpret_cast<zes_freq_object_t*>( hFrequency )->handle;

        // forward to device-driver
        result = pfnOcGetCapabilities( hFrequency, pOcCapabilities );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesFrequencyOcGetFrequencyTarget
    __zedlllocal ze_result_t ZE_APICALL
    zesFrequencyOcGetFrequencyTarget(
        zes_freq_handle_t hFrequency,                   ///< [in] Handle for the component.
        double* pCurrentOcFrequency                     ///< [out] Overclocking Frequency in MHz, if extended moded is supported,
                                                        ///< will returned in 1 Mhz granularity, else, in multiples of 50 Mhz. This
                                                        ///< cannot be greater than ::zes_oc_capabilities_t.maxOcFrequency.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_freq_object_t*>( hFrequency )->dditable;
        auto pfnOcGetFrequencyTarget = dditable->zes.Frequency.pfnOcGetFrequencyTarget;
        if( nullptr == pfnOcGetFrequencyTarget )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hFrequency = reinterpret_cast<zes_freq_object_t*>( hFrequency )->handle;

        // forward to device-driver
        result = pfnOcGetFrequencyTarget( hFrequency, pCurrentOcFrequency );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesFrequencyOcSetFrequencyTarget
    __zedlllocal ze_result_t ZE_APICALL
    zesFrequencyOcSetFrequencyTarget(
        zes_freq_handle_t hFrequency,                   ///< [in] Handle for the component.
        double CurrentOcFrequency                       ///< [in] Overclocking Frequency in MHz, if extended moded is supported, it
                                                        ///< could be set in 1 Mhz granularity, else, in multiples of 50 Mhz. This
                                                        ///< cannot be greater than ::zes_oc_capabilities_t.maxOcFrequency.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_freq_object_t*>( hFrequency )->dditable;
        auto pfnOcSetFrequencyTarget = dditable->zes.Frequency.pfnOcSetFrequencyTarget;
        if( nullptr == pfnOcSetFrequencyTarget )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hFrequency = reinterpret_cast<zes_freq_object_t*>( hFrequency )->handle;

        // forward to device-driver
        result = pfnOcSetFrequencyTarget( hFrequency, CurrentOcFrequency );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesFrequencyOcGetVoltageTarget
    __zedlllocal ze_result_t ZE_APICALL
    zesFrequencyOcGetVoltageTarget(
        zes_freq_handle_t hFrequency,                   ///< [in] Handle for the component.
        double* pCurrentVoltageTarget,                  ///< [out] Overclock voltage in Volts. This cannot be greater than
                                                        ///< ::zes_oc_capabilities_t.maxOcVoltage.
        double* pCurrentVoltageOffset                   ///< [out] This voltage offset is applied to all points on the
                                                        ///< voltage/frequency curve, include the new overclock voltageTarget. It
                                                        ///< can be in the range (::zes_oc_capabilities_t.minOcVoltageOffset,
                                                        ///< ::zes_oc_capabilities_t.maxOcVoltageOffset).
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_freq_object_t*>( hFrequency )->dditable;
        auto pfnOcGetVoltageTarget = dditable->zes.Frequency.pfnOcGetVoltageTarget;
        if( nullptr == pfnOcGetVoltageTarget )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hFrequency = reinterpret_cast<zes_freq_object_t*>( hFrequency )->handle;

        // forward to device-driver
        result = pfnOcGetVoltageTarget( hFrequency, pCurrentVoltageTarget, pCurrentVoltageOffset );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesFrequencyOcSetVoltageTarget
    __zedlllocal ze_result_t ZE_APICALL
    zesFrequencyOcSetVoltageTarget(
        zes_freq_handle_t hFrequency,                   ///< [in] Handle for the component.
        double CurrentVoltageTarget,                    ///< [in] Overclock voltage in Volts. This cannot be greater than
                                                        ///< ::zes_oc_capabilities_t.maxOcVoltage.
        double CurrentVoltageOffset                     ///< [in] This voltage offset is applied to all points on the
                                                        ///< voltage/frequency curve, include the new overclock voltageTarget. It
                                                        ///< can be in the range (::zes_oc_capabilities_t.minOcVoltageOffset,
                                                        ///< ::zes_oc_capabilities_t.maxOcVoltageOffset).
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_freq_object_t*>( hFrequency )->dditable;
        auto pfnOcSetVoltageTarget = dditable->zes.Frequency.pfnOcSetVoltageTarget;
        if( nullptr == pfnOcSetVoltageTarget )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hFrequency = reinterpret_cast<zes_freq_object_t*>( hFrequency )->handle;

        // forward to device-driver
        result = pfnOcSetVoltageTarget( hFrequency, CurrentVoltageTarget, CurrentVoltageOffset );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesFrequencyOcSetMode
    __zedlllocal ze_result_t ZE_APICALL
    zesFrequencyOcSetMode(
        zes_freq_handle_t hFrequency,                   ///< [in] Handle for the component.
        zes_oc_mode_t CurrentOcMode                     ///< [in] Current Overclocking Mode ::zes_oc_mode_t.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_freq_object_t*>( hFrequency )->dditable;
        auto pfnOcSetMode = dditable->zes.Frequency.pfnOcSetMode;
        if( nullptr == pfnOcSetMode )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hFrequency = reinterpret_cast<zes_freq_object_t*>( hFrequency )->handle;

        // forward to device-driver
        result = pfnOcSetMode( hFrequency, CurrentOcMode );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesFrequencyOcGetMode
    __zedlllocal ze_result_t ZE_APICALL
    zesFrequencyOcGetMode(
        zes_freq_handle_t hFrequency,                   ///< [in] Handle for the component.
        zes_oc_mode_t* pCurrentOcMode                   ///< [out] Current Overclocking Mode ::zes_oc_mode_t.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_freq_object_t*>( hFrequency )->dditable;
        auto pfnOcGetMode = dditable->zes.Frequency.pfnOcGetMode;
        if( nullptr == pfnOcGetMode )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hFrequency = reinterpret_cast<zes_freq_object_t*>( hFrequency )->handle;

        // forward to device-driver
        result = pfnOcGetMode( hFrequency, pCurrentOcMode );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesFrequencyOcGetIccMax
    __zedlllocal ze_result_t ZE_APICALL
    zesFrequencyOcGetIccMax(
        zes_freq_handle_t hFrequency,                   ///< [in] Handle for the component.
        double* pOcIccMax                               ///< [in,out] Will contain the maximum current limit in Amperes on
                                                        ///< successful return.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_freq_object_t*>( hFrequency )->dditable;
        auto pfnOcGetIccMax = dditable->zes.Frequency.pfnOcGetIccMax;
        if( nullptr == pfnOcGetIccMax )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hFrequency = reinterpret_cast<zes_freq_object_t*>( hFrequency )->handle;

        // forward to device-driver
        result = pfnOcGetIccMax( hFrequency, pOcIccMax );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesFrequencyOcSetIccMax
    __zedlllocal ze_result_t ZE_APICALL
    zesFrequencyOcSetIccMax(
        zes_freq_handle_t hFrequency,                   ///< [in] Handle for the component.
        double ocIccMax                                 ///< [in] The new maximum current limit in Amperes.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_freq_object_t*>( hFrequency )->dditable;
        auto pfnOcSetIccMax = dditable->zes.Frequency.pfnOcSetIccMax;
        if( nullptr == pfnOcSetIccMax )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hFrequency = reinterpret_cast<zes_freq_object_t*>( hFrequency )->handle;

        // forward to device-driver
        result = pfnOcSetIccMax( hFrequency, ocIccMax );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesFrequencyOcGetTjMax
    __zedlllocal ze_result_t ZE_APICALL
    zesFrequencyOcGetTjMax(
        zes_freq_handle_t hFrequency,                   ///< [in] Handle for the component.
        double* pOcTjMax                                ///< [in,out] Will contain the maximum temperature limit in degrees Celsius
                                                        ///< on successful return.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_freq_object_t*>( hFrequency )->dditable;
        auto pfnOcGetTjMax = dditable->zes.Frequency.pfnOcGetTjMax;
        if( nullptr == pfnOcGetTjMax )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hFrequency = reinterpret_cast<zes_freq_object_t*>( hFrequency )->handle;

        // forward to device-driver
        result = pfnOcGetTjMax( hFrequency, pOcTjMax );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesFrequencyOcSetTjMax
    __zedlllocal ze_result_t ZE_APICALL
    zesFrequencyOcSetTjMax(
        zes_freq_handle_t hFrequency,                   ///< [in] Handle for the component.
        double ocTjMax                                  ///< [in] The new maximum temperature limit in degrees Celsius.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_freq_object_t*>( hFrequency )->dditable;
        auto pfnOcSetTjMax = dditable->zes.Frequency.pfnOcSetTjMax;
        if( nullptr == pfnOcSetTjMax )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hFrequency = reinterpret_cast<zes_freq_object_t*>( hFrequency )->handle;

        // forward to device-driver
        result = pfnOcSetTjMax( hFrequency, ocTjMax );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesDeviceEnumLeds
    __zedlllocal ze_result_t ZE_APICALL
    zesDeviceEnumLeds(
        zes_device_handle_t hDevice,                    ///< [in] Sysman handle of the device.
        uint32_t* pCount,                               ///< [in,out] pointer to the number of components of this type.
                                                        ///< if count is zero, then the driver shall update the value with the
                                                        ///< total number of components of this type that are available.
                                                        ///< if count is greater than the number of components of this type that
                                                        ///< are available, then the driver shall update the value with the correct
                                                        ///< number of components.
        zes_led_handle_t* phLed                         ///< [in,out][optional][range(0, *pCount)] array of handle of components of
                                                        ///< this type.
                                                        ///< if count is less than the number of components of this type that are
                                                        ///< available, then the driver shall only retrieve that number of
                                                        ///< component handles.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_device_object_t*>( hDevice )->dditable;
        auto pfnEnumLeds = dditable->zes.Device.pfnEnumLeds;
        if( nullptr == pfnEnumLeds )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDevice = reinterpret_cast<zes_device_object_t*>( hDevice )->handle;

        // forward to device-driver
        result = pfnEnumLeds( hDevice, pCount, phLed );

        if( ZE_RESULT_SUCCESS != result )
            return result;

        try
        {
            // convert driver handles to loader handles
            for( size_t i = 0; ( nullptr != phLed ) && ( i < *pCount ); ++i )
                phLed[ i ] = reinterpret_cast<zes_led_handle_t>(
                    zes_led_factory.getInstance( phLed[ i ], dditable ) );
        }
        catch( std::bad_alloc& )
        {
            result = ZE_RESULT_ERROR_OUT_OF_HOST_MEMORY;
        }

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesLedGetProperties
    __zedlllocal ze_result_t ZE_APICALL
    zesLedGetProperties(
        zes_led_handle_t hLed,                          ///< [in] Handle for the component.
        zes_led_properties_t* pProperties               ///< [in,out] Will contain the properties of the LED.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_led_object_t*>( hLed )->dditable;
        auto pfnGetProperties = dditable->zes.Led.pfnGetProperties;
        if( nullptr == pfnGetProperties )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hLed = reinterpret_cast<zes_led_object_t*>( hLed )->handle;

        // forward to device-driver
        result = pfnGetProperties( hLed, pProperties );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesLedGetState
    __zedlllocal ze_result_t ZE_APICALL
    zesLedGetState(
        zes_led_handle_t hLed,                          ///< [in] Handle for the component.
        zes_led_state_t* pState                         ///< [in,out] Will contain the current state of the LED.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_led_object_t*>( hLed )->dditable;
        auto pfnGetState = dditable->zes.Led.pfnGetState;
        if( nullptr == pfnGetState )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hLed = reinterpret_cast<zes_led_object_t*>( hLed )->handle;

        // forward to device-driver
        result = pfnGetState( hLed, pState );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesLedSetState
    __zedlllocal ze_result_t ZE_APICALL
    zesLedSetState(
        zes_led_handle_t hLed,                          ///< [in] Handle for the component.
        ze_bool_t enable                                ///< [in] Set to TRUE to turn the LED on, FALSE to turn off.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_led_object_t*>( hLed )->dditable;
        auto pfnSetState = dditable->zes.Led.pfnSetState;
        if( nullptr == pfnSetState )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hLed = reinterpret_cast<zes_led_object_t*>( hLed )->handle;

        // forward to device-driver
        result = pfnSetState( hLed, enable );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesLedSetColor
    __zedlllocal ze_result_t ZE_APICALL
    zesLedSetColor(
        zes_led_handle_t hLed,                          ///< [in] Handle for the component.
        const zes_led_color_t* pColor                   ///< [in] New color of the LED.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_led_object_t*>( hLed )->dditable;
        auto pfnSetColor = dditable->zes.Led.pfnSetColor;
        if( nullptr == pfnSetColor )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hLed = reinterpret_cast<zes_led_object_t*>( hLed )->handle;

        // forward to device-driver
        result = pfnSetColor( hLed, pColor );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesDeviceEnumMemoryModules
    __zedlllocal ze_result_t ZE_APICALL
    zesDeviceEnumMemoryModules(
        zes_device_handle_t hDevice,                    ///< [in] Sysman handle of the device.
        uint32_t* pCount,                               ///< [in,out] pointer to the number of components of this type.
                                                        ///< if count is zero, then the driver shall update the value with the
                                                        ///< total number of components of this type that are available.
                                                        ///< if count is greater than the number of components of this type that
                                                        ///< are available, then the driver shall update the value with the correct
                                                        ///< number of components.
        zes_mem_handle_t* phMemory                      ///< [in,out][optional][range(0, *pCount)] array of handle of components of
                                                        ///< this type.
                                                        ///< if count is less than the number of components of this type that are
                                                        ///< available, then the driver shall only retrieve that number of
                                                        ///< component handles.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_device_object_t*>( hDevice )->dditable;
        auto pfnEnumMemoryModules = dditable->zes.Device.pfnEnumMemoryModules;
        if( nullptr == pfnEnumMemoryModules )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDevice = reinterpret_cast<zes_device_object_t*>( hDevice )->handle;

        // forward to device-driver
        result = pfnEnumMemoryModules( hDevice, pCount, phMemory );

        if( ZE_RESULT_SUCCESS != result )
            return result;

        try
        {
            // convert driver handles to loader handles
            for( size_t i = 0; ( nullptr != phMemory ) && ( i < *pCount ); ++i )
                phMemory[ i ] = reinterpret_cast<zes_mem_handle_t>(
                    zes_mem_factory.getInstance( phMemory[ i ], dditable ) );
        }
        catch( std::bad_alloc& )
        {
            result = ZE_RESULT_ERROR_OUT_OF_HOST_MEMORY;
        }

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesMemoryGetProperties
    __zedlllocal ze_result_t ZE_APICALL
    zesMemoryGetProperties(
        zes_mem_handle_t hMemory,                       ///< [in] Handle for the component.
        zes_mem_properties_t* pProperties               ///< [in,out] Will contain memory properties.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_mem_object_t*>( hMemory )->dditable;
        auto pfnGetProperties = dditable->zes.Memory.pfnGetProperties;
        if( nullptr == pfnGetProperties )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hMemory = reinterpret_cast<zes_mem_object_t*>( hMemory )->handle;

        // forward to device-driver
        result = pfnGetProperties( hMemory, pProperties );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesMemoryGetState
    __zedlllocal ze_result_t ZE_APICALL
    zesMemoryGetState(
        zes_mem_handle_t hMemory,                       ///< [in] Handle for the component.
        zes_mem_state_t* pState                         ///< [in,out] Will contain the current health and allocated memory.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_mem_object_t*>( hMemory )->dditable;
        auto pfnGetState = dditable->zes.Memory.pfnGetState;
        if( nullptr == pfnGetState )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hMemory = reinterpret_cast<zes_mem_object_t*>( hMemory )->handle;

        // forward to device-driver
        result = pfnGetState( hMemory, pState );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesMemoryGetBandwidth
    __zedlllocal ze_result_t ZE_APICALL
    zesMemoryGetBandwidth(
        zes_mem_handle_t hMemory,                       ///< [in] Handle for the component.
        zes_mem_bandwidth_t* pBandwidth                 ///< [in,out] Will contain the current health, free memory, total memory
                                                        ///< size.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_mem_object_t*>( hMemory )->dditable;
        auto pfnGetBandwidth = dditable->zes.Memory.pfnGetBandwidth;
        if( nullptr == pfnGetBandwidth )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hMemory = reinterpret_cast<zes_mem_object_t*>( hMemory )->handle;

        // forward to device-driver
        result = pfnGetBandwidth( hMemory, pBandwidth );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesDeviceEnumPerformanceFactorDomains
    __zedlllocal ze_result_t ZE_APICALL
    zesDeviceEnumPerformanceFactorDomains(
        zes_device_handle_t hDevice,                    ///< [in] Sysman handle of the device.
        uint32_t* pCount,                               ///< [in,out] pointer to the number of components of this type.
                                                        ///< if count is zero, then the driver shall update the value with the
                                                        ///< total number of components of this type that are available.
                                                        ///< if count is greater than the number of components of this type that
                                                        ///< are available, then the driver shall update the value with the correct
                                                        ///< number of components.
        zes_perf_handle_t* phPerf                       ///< [in,out][optional][range(0, *pCount)] array of handle of components of
                                                        ///< this type.
                                                        ///< if count is less than the number of components of this type that are
                                                        ///< available, then the driver shall only retrieve that number of
                                                        ///< component handles.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_device_object_t*>( hDevice )->dditable;
        auto pfnEnumPerformanceFactorDomains = dditable->zes.Device.pfnEnumPerformanceFactorDomains;
        if( nullptr == pfnEnumPerformanceFactorDomains )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDevice = reinterpret_cast<zes_device_object_t*>( hDevice )->handle;

        // forward to device-driver
        result = pfnEnumPerformanceFactorDomains( hDevice, pCount, phPerf );

        if( ZE_RESULT_SUCCESS != result )
            return result;

        try
        {
            // convert driver handles to loader handles
            for( size_t i = 0; ( nullptr != phPerf ) && ( i < *pCount ); ++i )
                phPerf[ i ] = reinterpret_cast<zes_perf_handle_t>(
                    zes_perf_factory.getInstance( phPerf[ i ], dditable ) );
        }
        catch( std::bad_alloc& )
        {
            result = ZE_RESULT_ERROR_OUT_OF_HOST_MEMORY;
        }

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesPerformanceFactorGetProperties
    __zedlllocal ze_result_t ZE_APICALL
    zesPerformanceFactorGetProperties(
        zes_perf_handle_t hPerf,                        ///< [in] Handle for the Performance Factor domain.
        zes_perf_properties_t* pProperties              ///< [in,out] Will contain information about the specified Performance
                                                        ///< Factor domain.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_perf_object_t*>( hPerf )->dditable;
        auto pfnGetProperties = dditable->zes.PerformanceFactor.pfnGetProperties;
        if( nullptr == pfnGetProperties )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hPerf = reinterpret_cast<zes_perf_object_t*>( hPerf )->handle;

        // forward to device-driver
        result = pfnGetProperties( hPerf, pProperties );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesPerformanceFactorGetConfig
    __zedlllocal ze_result_t ZE_APICALL
    zesPerformanceFactorGetConfig(
        zes_perf_handle_t hPerf,                        ///< [in] Handle for the Performance Factor domain.
        double* pFactor                                 ///< [in,out] Will contain the actual Performance Factor being used by the
                                                        ///< hardware (may not be the same as the requested Performance Factor).
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_perf_object_t*>( hPerf )->dditable;
        auto pfnGetConfig = dditable->zes.PerformanceFactor.pfnGetConfig;
        if( nullptr == pfnGetConfig )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hPerf = reinterpret_cast<zes_perf_object_t*>( hPerf )->handle;

        // forward to device-driver
        result = pfnGetConfig( hPerf, pFactor );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesPerformanceFactorSetConfig
    __zedlllocal ze_result_t ZE_APICALL
    zesPerformanceFactorSetConfig(
        zes_perf_handle_t hPerf,                        ///< [in] Handle for the Performance Factor domain.
        double factor                                   ///< [in] The new Performance Factor.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_perf_object_t*>( hPerf )->dditable;
        auto pfnSetConfig = dditable->zes.PerformanceFactor.pfnSetConfig;
        if( nullptr == pfnSetConfig )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hPerf = reinterpret_cast<zes_perf_object_t*>( hPerf )->handle;

        // forward to device-driver
        result = pfnSetConfig( hPerf, factor );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesDeviceEnumPowerDomains
    __zedlllocal ze_result_t ZE_APICALL
    zesDeviceEnumPowerDomains(
        zes_device_handle_t hDevice,                    ///< [in] Sysman handle of the device.
        uint32_t* pCount,                               ///< [in,out] pointer to the number of components of this type.
                                                        ///< if count is zero, then the driver shall update the value with the
                                                        ///< total number of components of this type that are available.
                                                        ///< if count is greater than the number of components of this type that
                                                        ///< are available, then the driver shall update the value with the correct
                                                        ///< number of components.
        zes_pwr_handle_t* phPower                       ///< [in,out][optional][range(0, *pCount)] array of handle of components of
                                                        ///< this type.
                                                        ///< if count is less than the number of components of this type that are
                                                        ///< available, then the driver shall only retrieve that number of
                                                        ///< component handles.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_device_object_t*>( hDevice )->dditable;
        auto pfnEnumPowerDomains = dditable->zes.Device.pfnEnumPowerDomains;
        if( nullptr == pfnEnumPowerDomains )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDevice = reinterpret_cast<zes_device_object_t*>( hDevice )->handle;

        // forward to device-driver
        result = pfnEnumPowerDomains( hDevice, pCount, phPower );

        if( ZE_RESULT_SUCCESS != result )
            return result;

        try
        {
            // convert driver handles to loader handles
            for( size_t i = 0; ( nullptr != phPower ) && ( i < *pCount ); ++i )
                phPower[ i ] = reinterpret_cast<zes_pwr_handle_t>(
                    zes_pwr_factory.getInstance( phPower[ i ], dditable ) );
        }
        catch( std::bad_alloc& )
        {
            result = ZE_RESULT_ERROR_OUT_OF_HOST_MEMORY;
        }

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesPowerGetProperties
    __zedlllocal ze_result_t ZE_APICALL
    zesPowerGetProperties(
        zes_pwr_handle_t hPower,                        ///< [in] Handle for the component.
        zes_power_properties_t* pProperties             ///< [in,out] Structure that will contain property data.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_pwr_object_t*>( hPower )->dditable;
        auto pfnGetProperties = dditable->zes.Power.pfnGetProperties;
        if( nullptr == pfnGetProperties )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hPower = reinterpret_cast<zes_pwr_object_t*>( hPower )->handle;

        // forward to device-driver
        result = pfnGetProperties( hPower, pProperties );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesPowerGetEnergyCounter
    __zedlllocal ze_result_t ZE_APICALL
    zesPowerGetEnergyCounter(
        zes_pwr_handle_t hPower,                        ///< [in] Handle for the component.
        zes_power_energy_counter_t* pEnergy             ///< [in,out] Will contain the latest snapshot of the energy counter and
                                                        ///< timestamp when the last counter value was measured.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_pwr_object_t*>( hPower )->dditable;
        auto pfnGetEnergyCounter = dditable->zes.Power.pfnGetEnergyCounter;
        if( nullptr == pfnGetEnergyCounter )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hPower = reinterpret_cast<zes_pwr_object_t*>( hPower )->handle;

        // forward to device-driver
        result = pfnGetEnergyCounter( hPower, pEnergy );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesPowerGetLimits
    __zedlllocal ze_result_t ZE_APICALL
    zesPowerGetLimits(
        zes_pwr_handle_t hPower,                        ///< [in] Handle for the component.
        zes_power_sustained_limit_t* pSustained,        ///< [in,out][optional] The sustained power limit. If this is null, the
                                                        ///< current sustained power limits will not be returned.
        zes_power_burst_limit_t* pBurst,                ///< [in,out][optional] The burst power limit. If this is null, the current
                                                        ///< peak power limits will not be returned.
        zes_power_peak_limit_t* pPeak                   ///< [in,out][optional] The peak power limit. If this is null, the peak
                                                        ///< power limits will not be returned.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_pwr_object_t*>( hPower )->dditable;
        auto pfnGetLimits = dditable->zes.Power.pfnGetLimits;
        if( nullptr == pfnGetLimits )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hPower = reinterpret_cast<zes_pwr_object_t*>( hPower )->handle;

        // forward to device-driver
        result = pfnGetLimits( hPower, pSustained, pBurst, pPeak );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesPowerSetLimits
    __zedlllocal ze_result_t ZE_APICALL
    zesPowerSetLimits(
        zes_pwr_handle_t hPower,                        ///< [in] Handle for the component.
        const zes_power_sustained_limit_t* pSustained,  ///< [in][optional] The sustained power limit. If this is null, no changes
                                                        ///< will be made to the sustained power limits.
        const zes_power_burst_limit_t* pBurst,          ///< [in][optional] The burst power limit. If this is null, no changes will
                                                        ///< be made to the burst power limits.
        const zes_power_peak_limit_t* pPeak             ///< [in][optional] The peak power limit. If this is null, no changes will
                                                        ///< be made to the peak power limits.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_pwr_object_t*>( hPower )->dditable;
        auto pfnSetLimits = dditable->zes.Power.pfnSetLimits;
        if( nullptr == pfnSetLimits )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hPower = reinterpret_cast<zes_pwr_object_t*>( hPower )->handle;

        // forward to device-driver
        result = pfnSetLimits( hPower, pSustained, pBurst, pPeak );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesPowerGetEnergyThreshold
    __zedlllocal ze_result_t ZE_APICALL
    zesPowerGetEnergyThreshold(
        zes_pwr_handle_t hPower,                        ///< [in] Handle for the component.
        zes_energy_threshold_t* pThreshold              ///< [in,out] Returns information about the energy threshold setting -
                                                        ///< enabled/energy threshold/process ID.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_pwr_object_t*>( hPower )->dditable;
        auto pfnGetEnergyThreshold = dditable->zes.Power.pfnGetEnergyThreshold;
        if( nullptr == pfnGetEnergyThreshold )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hPower = reinterpret_cast<zes_pwr_object_t*>( hPower )->handle;

        // forward to device-driver
        result = pfnGetEnergyThreshold( hPower, pThreshold );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesPowerSetEnergyThreshold
    __zedlllocal ze_result_t ZE_APICALL
    zesPowerSetEnergyThreshold(
        zes_pwr_handle_t hPower,                        ///< [in] Handle for the component.
        double threshold                                ///< [in] The energy threshold to be set in joules.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_pwr_object_t*>( hPower )->dditable;
        auto pfnSetEnergyThreshold = dditable->zes.Power.pfnSetEnergyThreshold;
        if( nullptr == pfnSetEnergyThreshold )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hPower = reinterpret_cast<zes_pwr_object_t*>( hPower )->handle;

        // forward to device-driver
        result = pfnSetEnergyThreshold( hPower, threshold );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesDeviceEnumPsus
    __zedlllocal ze_result_t ZE_APICALL
    zesDeviceEnumPsus(
        zes_device_handle_t hDevice,                    ///< [in] Sysman handle of the device.
        uint32_t* pCount,                               ///< [in,out] pointer to the number of components of this type.
                                                        ///< if count is zero, then the driver shall update the value with the
                                                        ///< total number of components of this type that are available.
                                                        ///< if count is greater than the number of components of this type that
                                                        ///< are available, then the driver shall update the value with the correct
                                                        ///< number of components.
        zes_psu_handle_t* phPsu                         ///< [in,out][optional][range(0, *pCount)] array of handle of components of
                                                        ///< this type.
                                                        ///< if count is less than the number of components of this type that are
                                                        ///< available, then the driver shall only retrieve that number of
                                                        ///< component handles.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_device_object_t*>( hDevice )->dditable;
        auto pfnEnumPsus = dditable->zes.Device.pfnEnumPsus;
        if( nullptr == pfnEnumPsus )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDevice = reinterpret_cast<zes_device_object_t*>( hDevice )->handle;

        // forward to device-driver
        result = pfnEnumPsus( hDevice, pCount, phPsu );

        if( ZE_RESULT_SUCCESS != result )
            return result;

        try
        {
            // convert driver handles to loader handles
            for( size_t i = 0; ( nullptr != phPsu ) && ( i < *pCount ); ++i )
                phPsu[ i ] = reinterpret_cast<zes_psu_handle_t>(
                    zes_psu_factory.getInstance( phPsu[ i ], dditable ) );
        }
        catch( std::bad_alloc& )
        {
            result = ZE_RESULT_ERROR_OUT_OF_HOST_MEMORY;
        }

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesPsuGetProperties
    __zedlllocal ze_result_t ZE_APICALL
    zesPsuGetProperties(
        zes_psu_handle_t hPsu,                          ///< [in] Handle for the component.
        zes_psu_properties_t* pProperties               ///< [in,out] Will contain the properties of the power supply.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_psu_object_t*>( hPsu )->dditable;
        auto pfnGetProperties = dditable->zes.Psu.pfnGetProperties;
        if( nullptr == pfnGetProperties )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hPsu = reinterpret_cast<zes_psu_object_t*>( hPsu )->handle;

        // forward to device-driver
        result = pfnGetProperties( hPsu, pProperties );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesPsuGetState
    __zedlllocal ze_result_t ZE_APICALL
    zesPsuGetState(
        zes_psu_handle_t hPsu,                          ///< [in] Handle for the component.
        zes_psu_state_t* pState                         ///< [in,out] Will contain the current state of the power supply.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_psu_object_t*>( hPsu )->dditable;
        auto pfnGetState = dditable->zes.Psu.pfnGetState;
        if( nullptr == pfnGetState )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hPsu = reinterpret_cast<zes_psu_object_t*>( hPsu )->handle;

        // forward to device-driver
        result = pfnGetState( hPsu, pState );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesDeviceEnumRasErrorSets
    __zedlllocal ze_result_t ZE_APICALL
    zesDeviceEnumRasErrorSets(
        zes_device_handle_t hDevice,                    ///< [in] Sysman handle of the device.
        uint32_t* pCount,                               ///< [in,out] pointer to the number of components of this type.
                                                        ///< if count is zero, then the driver shall update the value with the
                                                        ///< total number of components of this type that are available.
                                                        ///< if count is greater than the number of components of this type that
                                                        ///< are available, then the driver shall update the value with the correct
                                                        ///< number of components.
        zes_ras_handle_t* phRas                         ///< [in,out][optional][range(0, *pCount)] array of handle of components of
                                                        ///< this type.
                                                        ///< if count is less than the number of components of this type that are
                                                        ///< available, then the driver shall only retrieve that number of
                                                        ///< component handles.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_device_object_t*>( hDevice )->dditable;
        auto pfnEnumRasErrorSets = dditable->zes.Device.pfnEnumRasErrorSets;
        if( nullptr == pfnEnumRasErrorSets )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDevice = reinterpret_cast<zes_device_object_t*>( hDevice )->handle;

        // forward to device-driver
        result = pfnEnumRasErrorSets( hDevice, pCount, phRas );

        if( ZE_RESULT_SUCCESS != result )
            return result;

        try
        {
            // convert driver handles to loader handles
            for( size_t i = 0; ( nullptr != phRas ) && ( i < *pCount ); ++i )
                phRas[ i ] = reinterpret_cast<zes_ras_handle_t>(
                    zes_ras_factory.getInstance( phRas[ i ], dditable ) );
        }
        catch( std::bad_alloc& )
        {
            result = ZE_RESULT_ERROR_OUT_OF_HOST_MEMORY;
        }

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesRasGetProperties
    __zedlllocal ze_result_t ZE_APICALL
    zesRasGetProperties(
        zes_ras_handle_t hRas,                          ///< [in] Handle for the component.
        zes_ras_properties_t* pProperties               ///< [in,out] Structure describing RAS properties
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_ras_object_t*>( hRas )->dditable;
        auto pfnGetProperties = dditable->zes.Ras.pfnGetProperties;
        if( nullptr == pfnGetProperties )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hRas = reinterpret_cast<zes_ras_object_t*>( hRas )->handle;

        // forward to device-driver
        result = pfnGetProperties( hRas, pProperties );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesRasGetConfig
    __zedlllocal ze_result_t ZE_APICALL
    zesRasGetConfig(
        zes_ras_handle_t hRas,                          ///< [in] Handle for the component.
        zes_ras_config_t* pConfig                       ///< [in,out] Will be populed with the current RAS configuration -
                                                        ///< thresholds used to trigger events
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_ras_object_t*>( hRas )->dditable;
        auto pfnGetConfig = dditable->zes.Ras.pfnGetConfig;
        if( nullptr == pfnGetConfig )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hRas = reinterpret_cast<zes_ras_object_t*>( hRas )->handle;

        // forward to device-driver
        result = pfnGetConfig( hRas, pConfig );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesRasSetConfig
    __zedlllocal ze_result_t ZE_APICALL
    zesRasSetConfig(
        zes_ras_handle_t hRas,                          ///< [in] Handle for the component.
        const zes_ras_config_t* pConfig                 ///< [in] Change the RAS configuration - thresholds used to trigger events
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_ras_object_t*>( hRas )->dditable;
        auto pfnSetConfig = dditable->zes.Ras.pfnSetConfig;
        if( nullptr == pfnSetConfig )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hRas = reinterpret_cast<zes_ras_object_t*>( hRas )->handle;

        // forward to device-driver
        result = pfnSetConfig( hRas, pConfig );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesRasGetState
    __zedlllocal ze_result_t ZE_APICALL
    zesRasGetState(
        zes_ras_handle_t hRas,                          ///< [in] Handle for the component.
        ze_bool_t clear,                                ///< [in] Set to 1 to clear the counters of this type
        zes_ras_state_t* pState                         ///< [in,out] Breakdown of where errors have occurred
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_ras_object_t*>( hRas )->dditable;
        auto pfnGetState = dditable->zes.Ras.pfnGetState;
        if( nullptr == pfnGetState )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hRas = reinterpret_cast<zes_ras_object_t*>( hRas )->handle;

        // forward to device-driver
        result = pfnGetState( hRas, clear, pState );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesDeviceEnumSchedulers
    __zedlllocal ze_result_t ZE_APICALL
    zesDeviceEnumSchedulers(
        zes_device_handle_t hDevice,                    ///< [in] Sysman handle of the device.
        uint32_t* pCount,                               ///< [in,out] pointer to the number of components of this type.
                                                        ///< if count is zero, then the driver shall update the value with the
                                                        ///< total number of components of this type that are available.
                                                        ///< if count is greater than the number of components of this type that
                                                        ///< are available, then the driver shall update the value with the correct
                                                        ///< number of components.
        zes_sched_handle_t* phScheduler                 ///< [in,out][optional][range(0, *pCount)] array of handle of components of
                                                        ///< this type.
                                                        ///< if count is less than the number of components of this type that are
                                                        ///< available, then the driver shall only retrieve that number of
                                                        ///< component handles.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_device_object_t*>( hDevice )->dditable;
        auto pfnEnumSchedulers = dditable->zes.Device.pfnEnumSchedulers;
        if( nullptr == pfnEnumSchedulers )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDevice = reinterpret_cast<zes_device_object_t*>( hDevice )->handle;

        // forward to device-driver
        result = pfnEnumSchedulers( hDevice, pCount, phScheduler );

        if( ZE_RESULT_SUCCESS != result )
            return result;

        try
        {
            // convert driver handles to loader handles
            for( size_t i = 0; ( nullptr != phScheduler ) && ( i < *pCount ); ++i )
                phScheduler[ i ] = reinterpret_cast<zes_sched_handle_t>(
                    zes_sched_factory.getInstance( phScheduler[ i ], dditable ) );
        }
        catch( std::bad_alloc& )
        {
            result = ZE_RESULT_ERROR_OUT_OF_HOST_MEMORY;
        }

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesSchedulerGetProperties
    __zedlllocal ze_result_t ZE_APICALL
    zesSchedulerGetProperties(
        zes_sched_handle_t hScheduler,                  ///< [in] Handle for the component.
        zes_sched_properties_t* pProperties             ///< [in,out] Structure that will contain property data.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_sched_object_t*>( hScheduler )->dditable;
        auto pfnGetProperties = dditable->zes.Scheduler.pfnGetProperties;
        if( nullptr == pfnGetProperties )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hScheduler = reinterpret_cast<zes_sched_object_t*>( hScheduler )->handle;

        // forward to device-driver
        result = pfnGetProperties( hScheduler, pProperties );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesSchedulerGetCurrentMode
    __zedlllocal ze_result_t ZE_APICALL
    zesSchedulerGetCurrentMode(
        zes_sched_handle_t hScheduler,                  ///< [in] Sysman handle for the component.
        zes_sched_mode_t* pMode                         ///< [in,out] Will contain the current scheduler mode.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_sched_object_t*>( hScheduler )->dditable;
        auto pfnGetCurrentMode = dditable->zes.Scheduler.pfnGetCurrentMode;
        if( nullptr == pfnGetCurrentMode )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hScheduler = reinterpret_cast<zes_sched_object_t*>( hScheduler )->handle;

        // forward to device-driver
        result = pfnGetCurrentMode( hScheduler, pMode );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesSchedulerGetTimeoutModeProperties
    __zedlllocal ze_result_t ZE_APICALL
    zesSchedulerGetTimeoutModeProperties(
        zes_sched_handle_t hScheduler,                  ///< [in] Sysman handle for the component.
        ze_bool_t getDefaults,                          ///< [in] If TRUE, the driver will return the system default properties for
                                                        ///< this mode, otherwise it will return the current properties.
        zes_sched_timeout_properties_t* pConfig         ///< [in,out] Will contain the current parameters for this mode.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_sched_object_t*>( hScheduler )->dditable;
        auto pfnGetTimeoutModeProperties = dditable->zes.Scheduler.pfnGetTimeoutModeProperties;
        if( nullptr == pfnGetTimeoutModeProperties )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hScheduler = reinterpret_cast<zes_sched_object_t*>( hScheduler )->handle;

        // forward to device-driver
        result = pfnGetTimeoutModeProperties( hScheduler, getDefaults, pConfig );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesSchedulerGetTimesliceModeProperties
    __zedlllocal ze_result_t ZE_APICALL
    zesSchedulerGetTimesliceModeProperties(
        zes_sched_handle_t hScheduler,                  ///< [in] Sysman handle for the component.
        ze_bool_t getDefaults,                          ///< [in] If TRUE, the driver will return the system default properties for
                                                        ///< this mode, otherwise it will return the current properties.
        zes_sched_timeslice_properties_t* pConfig       ///< [in,out] Will contain the current parameters for this mode.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_sched_object_t*>( hScheduler )->dditable;
        auto pfnGetTimesliceModeProperties = dditable->zes.Scheduler.pfnGetTimesliceModeProperties;
        if( nullptr == pfnGetTimesliceModeProperties )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hScheduler = reinterpret_cast<zes_sched_object_t*>( hScheduler )->handle;

        // forward to device-driver
        result = pfnGetTimesliceModeProperties( hScheduler, getDefaults, pConfig );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesSchedulerSetTimeoutMode
    __zedlllocal ze_result_t ZE_APICALL
    zesSchedulerSetTimeoutMode(
        zes_sched_handle_t hScheduler,                  ///< [in] Sysman handle for the component.
        zes_sched_timeout_properties_t* pProperties,    ///< [in] The properties to use when configurating this mode.
        ze_bool_t* pNeedReload                          ///< [in,out] Will be set to TRUE if a device driver reload is needed to
                                                        ///< apply the new scheduler mode.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_sched_object_t*>( hScheduler )->dditable;
        auto pfnSetTimeoutMode = dditable->zes.Scheduler.pfnSetTimeoutMode;
        if( nullptr == pfnSetTimeoutMode )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hScheduler = reinterpret_cast<zes_sched_object_t*>( hScheduler )->handle;

        // forward to device-driver
        result = pfnSetTimeoutMode( hScheduler, pProperties, pNeedReload );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesSchedulerSetTimesliceMode
    __zedlllocal ze_result_t ZE_APICALL
    zesSchedulerSetTimesliceMode(
        zes_sched_handle_t hScheduler,                  ///< [in] Sysman handle for the component.
        zes_sched_timeslice_properties_t* pProperties,  ///< [in] The properties to use when configurating this mode.
        ze_bool_t* pNeedReload                          ///< [in,out] Will be set to TRUE if a device driver reload is needed to
                                                        ///< apply the new scheduler mode.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_sched_object_t*>( hScheduler )->dditable;
        auto pfnSetTimesliceMode = dditable->zes.Scheduler.pfnSetTimesliceMode;
        if( nullptr == pfnSetTimesliceMode )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hScheduler = reinterpret_cast<zes_sched_object_t*>( hScheduler )->handle;

        // forward to device-driver
        result = pfnSetTimesliceMode( hScheduler, pProperties, pNeedReload );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesSchedulerSetExclusiveMode
    __zedlllocal ze_result_t ZE_APICALL
    zesSchedulerSetExclusiveMode(
        zes_sched_handle_t hScheduler,                  ///< [in] Sysman handle for the component.
        ze_bool_t* pNeedReload                          ///< [in,out] Will be set to TRUE if a device driver reload is needed to
                                                        ///< apply the new scheduler mode.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_sched_object_t*>( hScheduler )->dditable;
        auto pfnSetExclusiveMode = dditable->zes.Scheduler.pfnSetExclusiveMode;
        if( nullptr == pfnSetExclusiveMode )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hScheduler = reinterpret_cast<zes_sched_object_t*>( hScheduler )->handle;

        // forward to device-driver
        result = pfnSetExclusiveMode( hScheduler, pNeedReload );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesSchedulerSetComputeUnitDebugMode
    __zedlllocal ze_result_t ZE_APICALL
    zesSchedulerSetComputeUnitDebugMode(
        zes_sched_handle_t hScheduler,                  ///< [in] Sysman handle for the component.
        ze_bool_t* pNeedReload                          ///< [in,out] Will be set to TRUE if a device driver reload is needed to
                                                        ///< apply the new scheduler mode.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_sched_object_t*>( hScheduler )->dditable;
        auto pfnSetComputeUnitDebugMode = dditable->zes.Scheduler.pfnSetComputeUnitDebugMode;
        if( nullptr == pfnSetComputeUnitDebugMode )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hScheduler = reinterpret_cast<zes_sched_object_t*>( hScheduler )->handle;

        // forward to device-driver
        result = pfnSetComputeUnitDebugMode( hScheduler, pNeedReload );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesDeviceEnumStandbyDomains
    __zedlllocal ze_result_t ZE_APICALL
    zesDeviceEnumStandbyDomains(
        zes_device_handle_t hDevice,                    ///< [in] Sysman handle of the device.
        uint32_t* pCount,                               ///< [in,out] pointer to the number of components of this type.
                                                        ///< if count is zero, then the driver shall update the value with the
                                                        ///< total number of components of this type that are available.
                                                        ///< if count is greater than the number of components of this type that
                                                        ///< are available, then the driver shall update the value with the correct
                                                        ///< number of components.
        zes_standby_handle_t* phStandby                 ///< [in,out][optional][range(0, *pCount)] array of handle of components of
                                                        ///< this type.
                                                        ///< if count is less than the number of components of this type that are
                                                        ///< available, then the driver shall only retrieve that number of
                                                        ///< component handles.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_device_object_t*>( hDevice )->dditable;
        auto pfnEnumStandbyDomains = dditable->zes.Device.pfnEnumStandbyDomains;
        if( nullptr == pfnEnumStandbyDomains )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDevice = reinterpret_cast<zes_device_object_t*>( hDevice )->handle;

        // forward to device-driver
        result = pfnEnumStandbyDomains( hDevice, pCount, phStandby );

        if( ZE_RESULT_SUCCESS != result )
            return result;

        try
        {
            // convert driver handles to loader handles
            for( size_t i = 0; ( nullptr != phStandby ) && ( i < *pCount ); ++i )
                phStandby[ i ] = reinterpret_cast<zes_standby_handle_t>(
                    zes_standby_factory.getInstance( phStandby[ i ], dditable ) );
        }
        catch( std::bad_alloc& )
        {
            result = ZE_RESULT_ERROR_OUT_OF_HOST_MEMORY;
        }

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesStandbyGetProperties
    __zedlllocal ze_result_t ZE_APICALL
    zesStandbyGetProperties(
        zes_standby_handle_t hStandby,                  ///< [in] Handle for the component.
        zes_standby_properties_t* pProperties           ///< [in,out] Will contain the standby hardware properties.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_standby_object_t*>( hStandby )->dditable;
        auto pfnGetProperties = dditable->zes.Standby.pfnGetProperties;
        if( nullptr == pfnGetProperties )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hStandby = reinterpret_cast<zes_standby_object_t*>( hStandby )->handle;

        // forward to device-driver
        result = pfnGetProperties( hStandby, pProperties );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesStandbyGetMode
    __zedlllocal ze_result_t ZE_APICALL
    zesStandbyGetMode(
        zes_standby_handle_t hStandby,                  ///< [in] Handle for the component.
        zes_standby_promo_mode_t* pMode                 ///< [in,out] Will contain the current standby mode.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_standby_object_t*>( hStandby )->dditable;
        auto pfnGetMode = dditable->zes.Standby.pfnGetMode;
        if( nullptr == pfnGetMode )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hStandby = reinterpret_cast<zes_standby_object_t*>( hStandby )->handle;

        // forward to device-driver
        result = pfnGetMode( hStandby, pMode );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesStandbySetMode
    __zedlllocal ze_result_t ZE_APICALL
    zesStandbySetMode(
        zes_standby_handle_t hStandby,                  ///< [in] Handle for the component.
        zes_standby_promo_mode_t mode                   ///< [in] New standby mode.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_standby_object_t*>( hStandby )->dditable;
        auto pfnSetMode = dditable->zes.Standby.pfnSetMode;
        if( nullptr == pfnSetMode )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hStandby = reinterpret_cast<zes_standby_object_t*>( hStandby )->handle;

        // forward to device-driver
        result = pfnSetMode( hStandby, mode );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesDeviceEnumTemperatureSensors
    __zedlllocal ze_result_t ZE_APICALL
    zesDeviceEnumTemperatureSensors(
        zes_device_handle_t hDevice,                    ///< [in] Sysman handle of the device.
        uint32_t* pCount,                               ///< [in,out] pointer to the number of components of this type.
                                                        ///< if count is zero, then the driver shall update the value with the
                                                        ///< total number of components of this type that are available.
                                                        ///< if count is greater than the number of components of this type that
                                                        ///< are available, then the driver shall update the value with the correct
                                                        ///< number of components.
        zes_temp_handle_t* phTemperature                ///< [in,out][optional][range(0, *pCount)] array of handle of components of
                                                        ///< this type.
                                                        ///< if count is less than the number of components of this type that are
                                                        ///< available, then the driver shall only retrieve that number of
                                                        ///< component handles.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_device_object_t*>( hDevice )->dditable;
        auto pfnEnumTemperatureSensors = dditable->zes.Device.pfnEnumTemperatureSensors;
        if( nullptr == pfnEnumTemperatureSensors )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hDevice = reinterpret_cast<zes_device_object_t*>( hDevice )->handle;

        // forward to device-driver
        result = pfnEnumTemperatureSensors( hDevice, pCount, phTemperature );

        if( ZE_RESULT_SUCCESS != result )
            return result;

        try
        {
            // convert driver handles to loader handles
            for( size_t i = 0; ( nullptr != phTemperature ) && ( i < *pCount ); ++i )
                phTemperature[ i ] = reinterpret_cast<zes_temp_handle_t>(
                    zes_temp_factory.getInstance( phTemperature[ i ], dditable ) );
        }
        catch( std::bad_alloc& )
        {
            result = ZE_RESULT_ERROR_OUT_OF_HOST_MEMORY;
        }

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesTemperatureGetProperties
    __zedlllocal ze_result_t ZE_APICALL
    zesTemperatureGetProperties(
        zes_temp_handle_t hTemperature,                 ///< [in] Handle for the component.
        zes_temp_properties_t* pProperties              ///< [in,out] Will contain the temperature sensor properties.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_temp_object_t*>( hTemperature )->dditable;
        auto pfnGetProperties = dditable->zes.Temperature.pfnGetProperties;
        if( nullptr == pfnGetProperties )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hTemperature = reinterpret_cast<zes_temp_object_t*>( hTemperature )->handle;

        // forward to device-driver
        result = pfnGetProperties( hTemperature, pProperties );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesTemperatureGetConfig
    __zedlllocal ze_result_t ZE_APICALL
    zesTemperatureGetConfig(
        zes_temp_handle_t hTemperature,                 ///< [in] Handle for the component.
        zes_temp_config_t* pConfig                      ///< [in,out] Returns current configuration.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_temp_object_t*>( hTemperature )->dditable;
        auto pfnGetConfig = dditable->zes.Temperature.pfnGetConfig;
        if( nullptr == pfnGetConfig )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hTemperature = reinterpret_cast<zes_temp_object_t*>( hTemperature )->handle;

        // forward to device-driver
        result = pfnGetConfig( hTemperature, pConfig );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesTemperatureSetConfig
    __zedlllocal ze_result_t ZE_APICALL
    zesTemperatureSetConfig(
        zes_temp_handle_t hTemperature,                 ///< [in] Handle for the component.
        const zes_temp_config_t* pConfig                ///< [in] New configuration.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_temp_object_t*>( hTemperature )->dditable;
        auto pfnSetConfig = dditable->zes.Temperature.pfnSetConfig;
        if( nullptr == pfnSetConfig )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hTemperature = reinterpret_cast<zes_temp_object_t*>( hTemperature )->handle;

        // forward to device-driver
        result = pfnSetConfig( hTemperature, pConfig );

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zesTemperatureGetState
    __zedlllocal ze_result_t ZE_APICALL
    zesTemperatureGetState(
        zes_temp_handle_t hTemperature,                 ///< [in] Handle for the component.
        double* pTemperature                            ///< [in,out] Will contain the temperature read from the specified sensor
                                                        ///< in degrees Celsius.
        )
    {
        ze_result_t result = ZE_RESULT_SUCCESS;

        // extract driver's function pointer table
        auto dditable = reinterpret_cast<zes_temp_object_t*>( hTemperature )->dditable;
        auto pfnGetState = dditable->zes.Temperature.pfnGetState;
        if( nullptr == pfnGetState )
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        // convert loader handle to driver handle
        hTemperature = reinterpret_cast<zes_temp_object_t*>( hTemperature )->handle;

        // forward to device-driver
        result = pfnGetState( hTemperature, pTemperature );

        return result;
    }

} // namespace loader

#if defined(__cplusplus)
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Device table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zesGetDeviceProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zes_device_dditable_t* pDdiTable                ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( loader::context->drivers.size() < 1 )
        return ZE_RESULT_ERROR_UNINITIALIZED;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( loader::context->version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    // Load the device-driver DDI tables
    for( auto& drv : loader::context->drivers )
    {
        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<zes_pfnGetDeviceProcAddrTable_t>(
                GET_FUNCTION_PTR( drv.handle, "zesGetDeviceProcAddrTable") );
            result = getTable( version, &drv.dditable.zes.Device );
        }
    }

    if( ZE_RESULT_SUCCESS == result )
    {
        if( ( loader::context->drivers.size() > 1 ) || loader::context->forceIntercept )
        {
            // return pointers to loader's DDIs
            pDdiTable->pfnGetProperties                            = loader::zesDeviceGetProperties;
            pDdiTable->pfnGetState                                 = loader::zesDeviceGetState;
            pDdiTable->pfnReset                                    = loader::zesDeviceReset;
            pDdiTable->pfnProcessesGetState                        = loader::zesDeviceProcessesGetState;
            pDdiTable->pfnPciGetProperties                         = loader::zesDevicePciGetProperties;
            pDdiTable->pfnPciGetState                              = loader::zesDevicePciGetState;
            pDdiTable->pfnPciGetBars                               = loader::zesDevicePciGetBars;
            pDdiTable->pfnPciGetStats                              = loader::zesDevicePciGetStats;
            pDdiTable->pfnEnumDiagnosticTestSuites                 = loader::zesDeviceEnumDiagnosticTestSuites;
            pDdiTable->pfnEnumEngineGroups                         = loader::zesDeviceEnumEngineGroups;
            pDdiTable->pfnEventRegister                            = loader::zesDeviceEventRegister;
            pDdiTable->pfnEnumFabricPorts                          = loader::zesDeviceEnumFabricPorts;
            pDdiTable->pfnEnumFans                                 = loader::zesDeviceEnumFans;
            pDdiTable->pfnEnumFirmwares                            = loader::zesDeviceEnumFirmwares;
            pDdiTable->pfnEnumFrequencyDomains                     = loader::zesDeviceEnumFrequencyDomains;
            pDdiTable->pfnEnumLeds                                 = loader::zesDeviceEnumLeds;
            pDdiTable->pfnEnumMemoryModules                        = loader::zesDeviceEnumMemoryModules;
            pDdiTable->pfnEnumPerformanceFactorDomains             = loader::zesDeviceEnumPerformanceFactorDomains;
            pDdiTable->pfnEnumPowerDomains                         = loader::zesDeviceEnumPowerDomains;
            pDdiTable->pfnEnumPsus                                 = loader::zesDeviceEnumPsus;
            pDdiTable->pfnEnumRasErrorSets                         = loader::zesDeviceEnumRasErrorSets;
            pDdiTable->pfnEnumSchedulers                           = loader::zesDeviceEnumSchedulers;
            pDdiTable->pfnEnumStandbyDomains                       = loader::zesDeviceEnumStandbyDomains;
            pDdiTable->pfnEnumTemperatureSensors                   = loader::zesDeviceEnumTemperatureSensors;
        }
        else
        {
            // return pointers directly to driver's DDIs
            *pDdiTable = loader::context->drivers.front().dditable.zes.Device;
        }
    }

    // If the validation layer is enabled, then intercept the loader's DDIs
    if(( ZE_RESULT_SUCCESS == result ) && ( nullptr != loader::context->validationLayer ))
    {
        auto getTable = reinterpret_cast<zes_pfnGetDeviceProcAddrTable_t>(
            GET_FUNCTION_PTR(loader::context->validationLayer, "zesGetDeviceProcAddrTable") );
        result = getTable( version, pDdiTable );
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Driver table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zesGetDriverProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zes_driver_dditable_t* pDdiTable                ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( loader::context->drivers.size() < 1 )
        return ZE_RESULT_ERROR_UNINITIALIZED;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( loader::context->version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    // Load the device-driver DDI tables
    for( auto& drv : loader::context->drivers )
    {
        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<zes_pfnGetDriverProcAddrTable_t>(
                GET_FUNCTION_PTR( drv.handle, "zesGetDriverProcAddrTable") );
            result = getTable( version, &drv.dditable.zes.Driver );
        }
    }

    if( ZE_RESULT_SUCCESS == result )
    {
        if( ( loader::context->drivers.size() > 1 ) || loader::context->forceIntercept )
        {
            // return pointers to loader's DDIs
            pDdiTable->pfnEventListen                              = loader::zesDriverEventListen;
            pDdiTable->pfnEventListenEx                            = loader::zesDriverEventListenEx;
        }
        else
        {
            // return pointers directly to driver's DDIs
            *pDdiTable = loader::context->drivers.front().dditable.zes.Driver;
        }
    }

    // If the validation layer is enabled, then intercept the loader's DDIs
    if(( ZE_RESULT_SUCCESS == result ) && ( nullptr != loader::context->validationLayer ))
    {
        auto getTable = reinterpret_cast<zes_pfnGetDriverProcAddrTable_t>(
            GET_FUNCTION_PTR(loader::context->validationLayer, "zesGetDriverProcAddrTable") );
        result = getTable( version, pDdiTable );
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Diagnostics table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zesGetDiagnosticsProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zes_diagnostics_dditable_t* pDdiTable           ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( loader::context->drivers.size() < 1 )
        return ZE_RESULT_ERROR_UNINITIALIZED;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( loader::context->version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    // Load the device-driver DDI tables
    for( auto& drv : loader::context->drivers )
    {
        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<zes_pfnGetDiagnosticsProcAddrTable_t>(
                GET_FUNCTION_PTR( drv.handle, "zesGetDiagnosticsProcAddrTable") );
            result = getTable( version, &drv.dditable.zes.Diagnostics );
        }
    }

    if( ZE_RESULT_SUCCESS == result )
    {
        if( ( loader::context->drivers.size() > 1 ) || loader::context->forceIntercept )
        {
            // return pointers to loader's DDIs
            pDdiTable->pfnGetProperties                            = loader::zesDiagnosticsGetProperties;
            pDdiTable->pfnGetTests                                 = loader::zesDiagnosticsGetTests;
            pDdiTable->pfnRunTests                                 = loader::zesDiagnosticsRunTests;
        }
        else
        {
            // return pointers directly to driver's DDIs
            *pDdiTable = loader::context->drivers.front().dditable.zes.Diagnostics;
        }
    }

    // If the validation layer is enabled, then intercept the loader's DDIs
    if(( ZE_RESULT_SUCCESS == result ) && ( nullptr != loader::context->validationLayer ))
    {
        auto getTable = reinterpret_cast<zes_pfnGetDiagnosticsProcAddrTable_t>(
            GET_FUNCTION_PTR(loader::context->validationLayer, "zesGetDiagnosticsProcAddrTable") );
        result = getTable( version, pDdiTable );
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Engine table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zesGetEngineProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zes_engine_dditable_t* pDdiTable                ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( loader::context->drivers.size() < 1 )
        return ZE_RESULT_ERROR_UNINITIALIZED;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( loader::context->version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    // Load the device-driver DDI tables
    for( auto& drv : loader::context->drivers )
    {
        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<zes_pfnGetEngineProcAddrTable_t>(
                GET_FUNCTION_PTR( drv.handle, "zesGetEngineProcAddrTable") );
            result = getTable( version, &drv.dditable.zes.Engine );
        }
    }

    if( ZE_RESULT_SUCCESS == result )
    {
        if( ( loader::context->drivers.size() > 1 ) || loader::context->forceIntercept )
        {
            // return pointers to loader's DDIs
            pDdiTable->pfnGetProperties                            = loader::zesEngineGetProperties;
            pDdiTable->pfnGetActivity                              = loader::zesEngineGetActivity;
        }
        else
        {
            // return pointers directly to driver's DDIs
            *pDdiTable = loader::context->drivers.front().dditable.zes.Engine;
        }
    }

    // If the validation layer is enabled, then intercept the loader's DDIs
    if(( ZE_RESULT_SUCCESS == result ) && ( nullptr != loader::context->validationLayer ))
    {
        auto getTable = reinterpret_cast<zes_pfnGetEngineProcAddrTable_t>(
            GET_FUNCTION_PTR(loader::context->validationLayer, "zesGetEngineProcAddrTable") );
        result = getTable( version, pDdiTable );
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's FabricPort table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zesGetFabricPortProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zes_fabric_port_dditable_t* pDdiTable           ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( loader::context->drivers.size() < 1 )
        return ZE_RESULT_ERROR_UNINITIALIZED;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( loader::context->version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    // Load the device-driver DDI tables
    for( auto& drv : loader::context->drivers )
    {
        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<zes_pfnGetFabricPortProcAddrTable_t>(
                GET_FUNCTION_PTR( drv.handle, "zesGetFabricPortProcAddrTable") );
            result = getTable( version, &drv.dditable.zes.FabricPort );
        }
    }

    if( ZE_RESULT_SUCCESS == result )
    {
        if( ( loader::context->drivers.size() > 1 ) || loader::context->forceIntercept )
        {
            // return pointers to loader's DDIs
            pDdiTable->pfnGetProperties                            = loader::zesFabricPortGetProperties;
            pDdiTable->pfnGetLinkType                              = loader::zesFabricPortGetLinkType;
            pDdiTable->pfnGetConfig                                = loader::zesFabricPortGetConfig;
            pDdiTable->pfnSetConfig                                = loader::zesFabricPortSetConfig;
            pDdiTable->pfnGetState                                 = loader::zesFabricPortGetState;
            pDdiTable->pfnGetThroughput                            = loader::zesFabricPortGetThroughput;
        }
        else
        {
            // return pointers directly to driver's DDIs
            *pDdiTable = loader::context->drivers.front().dditable.zes.FabricPort;
        }
    }

    // If the validation layer is enabled, then intercept the loader's DDIs
    if(( ZE_RESULT_SUCCESS == result ) && ( nullptr != loader::context->validationLayer ))
    {
        auto getTable = reinterpret_cast<zes_pfnGetFabricPortProcAddrTable_t>(
            GET_FUNCTION_PTR(loader::context->validationLayer, "zesGetFabricPortProcAddrTable") );
        result = getTable( version, pDdiTable );
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Fan table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zesGetFanProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zes_fan_dditable_t* pDdiTable                   ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( loader::context->drivers.size() < 1 )
        return ZE_RESULT_ERROR_UNINITIALIZED;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( loader::context->version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    // Load the device-driver DDI tables
    for( auto& drv : loader::context->drivers )
    {
        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<zes_pfnGetFanProcAddrTable_t>(
                GET_FUNCTION_PTR( drv.handle, "zesGetFanProcAddrTable") );
            result = getTable( version, &drv.dditable.zes.Fan );
        }
    }

    if( ZE_RESULT_SUCCESS == result )
    {
        if( ( loader::context->drivers.size() > 1 ) || loader::context->forceIntercept )
        {
            // return pointers to loader's DDIs
            pDdiTable->pfnGetProperties                            = loader::zesFanGetProperties;
            pDdiTable->pfnGetConfig                                = loader::zesFanGetConfig;
            pDdiTable->pfnSetDefaultMode                           = loader::zesFanSetDefaultMode;
            pDdiTable->pfnSetFixedSpeedMode                        = loader::zesFanSetFixedSpeedMode;
            pDdiTable->pfnSetSpeedTableMode                        = loader::zesFanSetSpeedTableMode;
            pDdiTable->pfnGetState                                 = loader::zesFanGetState;
        }
        else
        {
            // return pointers directly to driver's DDIs
            *pDdiTable = loader::context->drivers.front().dditable.zes.Fan;
        }
    }

    // If the validation layer is enabled, then intercept the loader's DDIs
    if(( ZE_RESULT_SUCCESS == result ) && ( nullptr != loader::context->validationLayer ))
    {
        auto getTable = reinterpret_cast<zes_pfnGetFanProcAddrTable_t>(
            GET_FUNCTION_PTR(loader::context->validationLayer, "zesGetFanProcAddrTable") );
        result = getTable( version, pDdiTable );
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Firmware table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zesGetFirmwareProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zes_firmware_dditable_t* pDdiTable              ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( loader::context->drivers.size() < 1 )
        return ZE_RESULT_ERROR_UNINITIALIZED;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( loader::context->version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    // Load the device-driver DDI tables
    for( auto& drv : loader::context->drivers )
    {
        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<zes_pfnGetFirmwareProcAddrTable_t>(
                GET_FUNCTION_PTR( drv.handle, "zesGetFirmwareProcAddrTable") );
            result = getTable( version, &drv.dditable.zes.Firmware );
        }
    }

    if( ZE_RESULT_SUCCESS == result )
    {
        if( ( loader::context->drivers.size() > 1 ) || loader::context->forceIntercept )
        {
            // return pointers to loader's DDIs
            pDdiTable->pfnGetProperties                            = loader::zesFirmwareGetProperties;
            pDdiTable->pfnFlash                                    = loader::zesFirmwareFlash;
        }
        else
        {
            // return pointers directly to driver's DDIs
            *pDdiTable = loader::context->drivers.front().dditable.zes.Firmware;
        }
    }

    // If the validation layer is enabled, then intercept the loader's DDIs
    if(( ZE_RESULT_SUCCESS == result ) && ( nullptr != loader::context->validationLayer ))
    {
        auto getTable = reinterpret_cast<zes_pfnGetFirmwareProcAddrTable_t>(
            GET_FUNCTION_PTR(loader::context->validationLayer, "zesGetFirmwareProcAddrTable") );
        result = getTable( version, pDdiTable );
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Frequency table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zesGetFrequencyProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zes_frequency_dditable_t* pDdiTable             ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( loader::context->drivers.size() < 1 )
        return ZE_RESULT_ERROR_UNINITIALIZED;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( loader::context->version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    // Load the device-driver DDI tables
    for( auto& drv : loader::context->drivers )
    {
        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<zes_pfnGetFrequencyProcAddrTable_t>(
                GET_FUNCTION_PTR( drv.handle, "zesGetFrequencyProcAddrTable") );
            result = getTable( version, &drv.dditable.zes.Frequency );
        }
    }

    if( ZE_RESULT_SUCCESS == result )
    {
        if( ( loader::context->drivers.size() > 1 ) || loader::context->forceIntercept )
        {
            // return pointers to loader's DDIs
            pDdiTable->pfnGetProperties                            = loader::zesFrequencyGetProperties;
            pDdiTable->pfnGetAvailableClocks                       = loader::zesFrequencyGetAvailableClocks;
            pDdiTable->pfnGetRange                                 = loader::zesFrequencyGetRange;
            pDdiTable->pfnSetRange                                 = loader::zesFrequencySetRange;
            pDdiTable->pfnGetState                                 = loader::zesFrequencyGetState;
            pDdiTable->pfnGetThrottleTime                          = loader::zesFrequencyGetThrottleTime;
            pDdiTable->pfnOcGetCapabilities                        = loader::zesFrequencyOcGetCapabilities;
            pDdiTable->pfnOcGetFrequencyTarget                     = loader::zesFrequencyOcGetFrequencyTarget;
            pDdiTable->pfnOcSetFrequencyTarget                     = loader::zesFrequencyOcSetFrequencyTarget;
            pDdiTable->pfnOcGetVoltageTarget                       = loader::zesFrequencyOcGetVoltageTarget;
            pDdiTable->pfnOcSetVoltageTarget                       = loader::zesFrequencyOcSetVoltageTarget;
            pDdiTable->pfnOcSetMode                                = loader::zesFrequencyOcSetMode;
            pDdiTable->pfnOcGetMode                                = loader::zesFrequencyOcGetMode;
            pDdiTable->pfnOcGetIccMax                              = loader::zesFrequencyOcGetIccMax;
            pDdiTable->pfnOcSetIccMax                              = loader::zesFrequencyOcSetIccMax;
            pDdiTable->pfnOcGetTjMax                               = loader::zesFrequencyOcGetTjMax;
            pDdiTable->pfnOcSetTjMax                               = loader::zesFrequencyOcSetTjMax;
        }
        else
        {
            // return pointers directly to driver's DDIs
            *pDdiTable = loader::context->drivers.front().dditable.zes.Frequency;
        }
    }

    // If the validation layer is enabled, then intercept the loader's DDIs
    if(( ZE_RESULT_SUCCESS == result ) && ( nullptr != loader::context->validationLayer ))
    {
        auto getTable = reinterpret_cast<zes_pfnGetFrequencyProcAddrTable_t>(
            GET_FUNCTION_PTR(loader::context->validationLayer, "zesGetFrequencyProcAddrTable") );
        result = getTable( version, pDdiTable );
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Led table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zesGetLedProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zes_led_dditable_t* pDdiTable                   ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( loader::context->drivers.size() < 1 )
        return ZE_RESULT_ERROR_UNINITIALIZED;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( loader::context->version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    // Load the device-driver DDI tables
    for( auto& drv : loader::context->drivers )
    {
        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<zes_pfnGetLedProcAddrTable_t>(
                GET_FUNCTION_PTR( drv.handle, "zesGetLedProcAddrTable") );
            result = getTable( version, &drv.dditable.zes.Led );
        }
    }

    if( ZE_RESULT_SUCCESS == result )
    {
        if( ( loader::context->drivers.size() > 1 ) || loader::context->forceIntercept )
        {
            // return pointers to loader's DDIs
            pDdiTable->pfnGetProperties                            = loader::zesLedGetProperties;
            pDdiTable->pfnGetState                                 = loader::zesLedGetState;
            pDdiTable->pfnSetState                                 = loader::zesLedSetState;
            pDdiTable->pfnSetColor                                 = loader::zesLedSetColor;
        }
        else
        {
            // return pointers directly to driver's DDIs
            *pDdiTable = loader::context->drivers.front().dditable.zes.Led;
        }
    }

    // If the validation layer is enabled, then intercept the loader's DDIs
    if(( ZE_RESULT_SUCCESS == result ) && ( nullptr != loader::context->validationLayer ))
    {
        auto getTable = reinterpret_cast<zes_pfnGetLedProcAddrTable_t>(
            GET_FUNCTION_PTR(loader::context->validationLayer, "zesGetLedProcAddrTable") );
        result = getTable( version, pDdiTable );
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Memory table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zesGetMemoryProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zes_memory_dditable_t* pDdiTable                ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( loader::context->drivers.size() < 1 )
        return ZE_RESULT_ERROR_UNINITIALIZED;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( loader::context->version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    // Load the device-driver DDI tables
    for( auto& drv : loader::context->drivers )
    {
        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<zes_pfnGetMemoryProcAddrTable_t>(
                GET_FUNCTION_PTR( drv.handle, "zesGetMemoryProcAddrTable") );
            result = getTable( version, &drv.dditable.zes.Memory );
        }
    }

    if( ZE_RESULT_SUCCESS == result )
    {
        if( ( loader::context->drivers.size() > 1 ) || loader::context->forceIntercept )
        {
            // return pointers to loader's DDIs
            pDdiTable->pfnGetProperties                            = loader::zesMemoryGetProperties;
            pDdiTable->pfnGetState                                 = loader::zesMemoryGetState;
            pDdiTable->pfnGetBandwidth                             = loader::zesMemoryGetBandwidth;
        }
        else
        {
            // return pointers directly to driver's DDIs
            *pDdiTable = loader::context->drivers.front().dditable.zes.Memory;
        }
    }

    // If the validation layer is enabled, then intercept the loader's DDIs
    if(( ZE_RESULT_SUCCESS == result ) && ( nullptr != loader::context->validationLayer ))
    {
        auto getTable = reinterpret_cast<zes_pfnGetMemoryProcAddrTable_t>(
            GET_FUNCTION_PTR(loader::context->validationLayer, "zesGetMemoryProcAddrTable") );
        result = getTable( version, pDdiTable );
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's PerformanceFactor table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zesGetPerformanceFactorProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zes_performance_factor_dditable_t* pDdiTable    ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( loader::context->drivers.size() < 1 )
        return ZE_RESULT_ERROR_UNINITIALIZED;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( loader::context->version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    // Load the device-driver DDI tables
    for( auto& drv : loader::context->drivers )
    {
        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<zes_pfnGetPerformanceFactorProcAddrTable_t>(
                GET_FUNCTION_PTR( drv.handle, "zesGetPerformanceFactorProcAddrTable") );
            result = getTable( version, &drv.dditable.zes.PerformanceFactor );
        }
    }

    if( ZE_RESULT_SUCCESS == result )
    {
        if( ( loader::context->drivers.size() > 1 ) || loader::context->forceIntercept )
        {
            // return pointers to loader's DDIs
            pDdiTable->pfnGetProperties                            = loader::zesPerformanceFactorGetProperties;
            pDdiTable->pfnGetConfig                                = loader::zesPerformanceFactorGetConfig;
            pDdiTable->pfnSetConfig                                = loader::zesPerformanceFactorSetConfig;
        }
        else
        {
            // return pointers directly to driver's DDIs
            *pDdiTable = loader::context->drivers.front().dditable.zes.PerformanceFactor;
        }
    }

    // If the validation layer is enabled, then intercept the loader's DDIs
    if(( ZE_RESULT_SUCCESS == result ) && ( nullptr != loader::context->validationLayer ))
    {
        auto getTable = reinterpret_cast<zes_pfnGetPerformanceFactorProcAddrTable_t>(
            GET_FUNCTION_PTR(loader::context->validationLayer, "zesGetPerformanceFactorProcAddrTable") );
        result = getTable( version, pDdiTable );
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Power table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zesGetPowerProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zes_power_dditable_t* pDdiTable                 ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( loader::context->drivers.size() < 1 )
        return ZE_RESULT_ERROR_UNINITIALIZED;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( loader::context->version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    // Load the device-driver DDI tables
    for( auto& drv : loader::context->drivers )
    {
        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<zes_pfnGetPowerProcAddrTable_t>(
                GET_FUNCTION_PTR( drv.handle, "zesGetPowerProcAddrTable") );
            result = getTable( version, &drv.dditable.zes.Power );
        }
    }

    if( ZE_RESULT_SUCCESS == result )
    {
        if( ( loader::context->drivers.size() > 1 ) || loader::context->forceIntercept )
        {
            // return pointers to loader's DDIs
            pDdiTable->pfnGetProperties                            = loader::zesPowerGetProperties;
            pDdiTable->pfnGetEnergyCounter                         = loader::zesPowerGetEnergyCounter;
            pDdiTable->pfnGetLimits                                = loader::zesPowerGetLimits;
            pDdiTable->pfnSetLimits                                = loader::zesPowerSetLimits;
            pDdiTable->pfnGetEnergyThreshold                       = loader::zesPowerGetEnergyThreshold;
            pDdiTable->pfnSetEnergyThreshold                       = loader::zesPowerSetEnergyThreshold;
        }
        else
        {
            // return pointers directly to driver's DDIs
            *pDdiTable = loader::context->drivers.front().dditable.zes.Power;
        }
    }

    // If the validation layer is enabled, then intercept the loader's DDIs
    if(( ZE_RESULT_SUCCESS == result ) && ( nullptr != loader::context->validationLayer ))
    {
        auto getTable = reinterpret_cast<zes_pfnGetPowerProcAddrTable_t>(
            GET_FUNCTION_PTR(loader::context->validationLayer, "zesGetPowerProcAddrTable") );
        result = getTable( version, pDdiTable );
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Psu table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zesGetPsuProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zes_psu_dditable_t* pDdiTable                   ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( loader::context->drivers.size() < 1 )
        return ZE_RESULT_ERROR_UNINITIALIZED;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( loader::context->version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    // Load the device-driver DDI tables
    for( auto& drv : loader::context->drivers )
    {
        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<zes_pfnGetPsuProcAddrTable_t>(
                GET_FUNCTION_PTR( drv.handle, "zesGetPsuProcAddrTable") );
            result = getTable( version, &drv.dditable.zes.Psu );
        }
    }

    if( ZE_RESULT_SUCCESS == result )
    {
        if( ( loader::context->drivers.size() > 1 ) || loader::context->forceIntercept )
        {
            // return pointers to loader's DDIs
            pDdiTable->pfnGetProperties                            = loader::zesPsuGetProperties;
            pDdiTable->pfnGetState                                 = loader::zesPsuGetState;
        }
        else
        {
            // return pointers directly to driver's DDIs
            *pDdiTable = loader::context->drivers.front().dditable.zes.Psu;
        }
    }

    // If the validation layer is enabled, then intercept the loader's DDIs
    if(( ZE_RESULT_SUCCESS == result ) && ( nullptr != loader::context->validationLayer ))
    {
        auto getTable = reinterpret_cast<zes_pfnGetPsuProcAddrTable_t>(
            GET_FUNCTION_PTR(loader::context->validationLayer, "zesGetPsuProcAddrTable") );
        result = getTable( version, pDdiTable );
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Ras table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zesGetRasProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zes_ras_dditable_t* pDdiTable                   ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( loader::context->drivers.size() < 1 )
        return ZE_RESULT_ERROR_UNINITIALIZED;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( loader::context->version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    // Load the device-driver DDI tables
    for( auto& drv : loader::context->drivers )
    {
        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<zes_pfnGetRasProcAddrTable_t>(
                GET_FUNCTION_PTR( drv.handle, "zesGetRasProcAddrTable") );
            result = getTable( version, &drv.dditable.zes.Ras );
        }
    }

    if( ZE_RESULT_SUCCESS == result )
    {
        if( ( loader::context->drivers.size() > 1 ) || loader::context->forceIntercept )
        {
            // return pointers to loader's DDIs
            pDdiTable->pfnGetProperties                            = loader::zesRasGetProperties;
            pDdiTable->pfnGetConfig                                = loader::zesRasGetConfig;
            pDdiTable->pfnSetConfig                                = loader::zesRasSetConfig;
            pDdiTable->pfnGetState                                 = loader::zesRasGetState;
        }
        else
        {
            // return pointers directly to driver's DDIs
            *pDdiTable = loader::context->drivers.front().dditable.zes.Ras;
        }
    }

    // If the validation layer is enabled, then intercept the loader's DDIs
    if(( ZE_RESULT_SUCCESS == result ) && ( nullptr != loader::context->validationLayer ))
    {
        auto getTable = reinterpret_cast<zes_pfnGetRasProcAddrTable_t>(
            GET_FUNCTION_PTR(loader::context->validationLayer, "zesGetRasProcAddrTable") );
        result = getTable( version, pDdiTable );
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Scheduler table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zesGetSchedulerProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zes_scheduler_dditable_t* pDdiTable             ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( loader::context->drivers.size() < 1 )
        return ZE_RESULT_ERROR_UNINITIALIZED;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( loader::context->version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    // Load the device-driver DDI tables
    for( auto& drv : loader::context->drivers )
    {
        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<zes_pfnGetSchedulerProcAddrTable_t>(
                GET_FUNCTION_PTR( drv.handle, "zesGetSchedulerProcAddrTable") );
            result = getTable( version, &drv.dditable.zes.Scheduler );
        }
    }

    if( ZE_RESULT_SUCCESS == result )
    {
        if( ( loader::context->drivers.size() > 1 ) || loader::context->forceIntercept )
        {
            // return pointers to loader's DDIs
            pDdiTable->pfnGetProperties                            = loader::zesSchedulerGetProperties;
            pDdiTable->pfnGetCurrentMode                           = loader::zesSchedulerGetCurrentMode;
            pDdiTable->pfnGetTimeoutModeProperties                 = loader::zesSchedulerGetTimeoutModeProperties;
            pDdiTable->pfnGetTimesliceModeProperties               = loader::zesSchedulerGetTimesliceModeProperties;
            pDdiTable->pfnSetTimeoutMode                           = loader::zesSchedulerSetTimeoutMode;
            pDdiTable->pfnSetTimesliceMode                         = loader::zesSchedulerSetTimesliceMode;
            pDdiTable->pfnSetExclusiveMode                         = loader::zesSchedulerSetExclusiveMode;
            pDdiTable->pfnSetComputeUnitDebugMode                  = loader::zesSchedulerSetComputeUnitDebugMode;
        }
        else
        {
            // return pointers directly to driver's DDIs
            *pDdiTable = loader::context->drivers.front().dditable.zes.Scheduler;
        }
    }

    // If the validation layer is enabled, then intercept the loader's DDIs
    if(( ZE_RESULT_SUCCESS == result ) && ( nullptr != loader::context->validationLayer ))
    {
        auto getTable = reinterpret_cast<zes_pfnGetSchedulerProcAddrTable_t>(
            GET_FUNCTION_PTR(loader::context->validationLayer, "zesGetSchedulerProcAddrTable") );
        result = getTable( version, pDdiTable );
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Standby table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zesGetStandbyProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zes_standby_dditable_t* pDdiTable               ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( loader::context->drivers.size() < 1 )
        return ZE_RESULT_ERROR_UNINITIALIZED;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( loader::context->version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    // Load the device-driver DDI tables
    for( auto& drv : loader::context->drivers )
    {
        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<zes_pfnGetStandbyProcAddrTable_t>(
                GET_FUNCTION_PTR( drv.handle, "zesGetStandbyProcAddrTable") );
            result = getTable( version, &drv.dditable.zes.Standby );
        }
    }

    if( ZE_RESULT_SUCCESS == result )
    {
        if( ( loader::context->drivers.size() > 1 ) || loader::context->forceIntercept )
        {
            // return pointers to loader's DDIs
            pDdiTable->pfnGetProperties                            = loader::zesStandbyGetProperties;
            pDdiTable->pfnGetMode                                  = loader::zesStandbyGetMode;
            pDdiTable->pfnSetMode                                  = loader::zesStandbySetMode;
        }
        else
        {
            // return pointers directly to driver's DDIs
            *pDdiTable = loader::context->drivers.front().dditable.zes.Standby;
        }
    }

    // If the validation layer is enabled, then intercept the loader's DDIs
    if(( ZE_RESULT_SUCCESS == result ) && ( nullptr != loader::context->validationLayer ))
    {
        auto getTable = reinterpret_cast<zes_pfnGetStandbyProcAddrTable_t>(
            GET_FUNCTION_PTR(loader::context->validationLayer, "zesGetStandbyProcAddrTable") );
        result = getTable( version, pDdiTable );
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Temperature table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_UNINITIALIZED
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zesGetTemperatureProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    zes_temperature_dditable_t* pDdiTable           ///< [in,out] pointer to table of DDI function pointers
    )
{
    if( loader::context->drivers.size() < 1 )
        return ZE_RESULT_ERROR_UNINITIALIZED;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( loader::context->version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    // Load the device-driver DDI tables
    for( auto& drv : loader::context->drivers )
    {
        if( ZE_RESULT_SUCCESS == result )
        {
            auto getTable = reinterpret_cast<zes_pfnGetTemperatureProcAddrTable_t>(
                GET_FUNCTION_PTR( drv.handle, "zesGetTemperatureProcAddrTable") );
            result = getTable( version, &drv.dditable.zes.Temperature );
        }
    }

    if( ZE_RESULT_SUCCESS == result )
    {
        if( ( loader::context->drivers.size() > 1 ) || loader::context->forceIntercept )
        {
            // return pointers to loader's DDIs
            pDdiTable->pfnGetProperties                            = loader::zesTemperatureGetProperties;
            pDdiTable->pfnGetConfig                                = loader::zesTemperatureGetConfig;
            pDdiTable->pfnSetConfig                                = loader::zesTemperatureSetConfig;
            pDdiTable->pfnGetState                                 = loader::zesTemperatureGetState;
        }
        else
        {
            // return pointers directly to driver's DDIs
            *pDdiTable = loader::context->drivers.front().dditable.zes.Temperature;
        }
    }

    // If the validation layer is enabled, then intercept the loader's DDIs
    if(( ZE_RESULT_SUCCESS == result ) && ( nullptr != loader::context->validationLayer ))
    {
        auto getTable = reinterpret_cast<zes_pfnGetTemperatureProcAddrTable_t>(
            GET_FUNCTION_PTR(loader::context->validationLayer, "zesGetTemperatureProcAddrTable") );
        result = getTable( version, pDdiTable );
    }

    return result;
}


#if defined(__cplusplus)
};
#endif
