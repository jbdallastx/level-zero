/*
 *
 * Copyright (C) 2020 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * @file ze_trcddi.cpp
 *
 */

#include <iostream>
#include "ze_tracing_layer.h"

namespace tracing_layer
{
    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeInit
    __zedlllocal ze_result_t ZE_APICALL
    zeInit(
        ze_init_flags_t flags                           ///< [in] initialization flags.
                                                        ///< must be 0 (default) or a combination of ::ze_init_flag_t.
        )
    {
        if( nullptr == context.zeDdiTable.Global.pfnInit)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Global.pfnInit, flags);

        // capture parameters
        ze_init_params_t tracerParams = {
            &flags
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnInitCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnInitCb_t, Global, pfnInitCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Global.pfnInit,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.pflags);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeDriverGet
    __zedlllocal ze_result_t ZE_APICALL
    zeDriverGet(
        uint32_t* pCount,                               ///< [in,out] pointer to the number of driver instances.
                                                        ///< if count is zero, then the loader will update the value with the total
                                                        ///< number of drivers available.
                                                        ///< if count is non-zero, then the loader will only retrieve that number
                                                        ///< of drivers.
                                                        ///< if count is larger than the number of drivers available, then the
                                                        ///< loader will update the value with the correct number of drivers available.
        ze_driver_handle_t* phDrivers                   ///< [in,out][optional][range(0, *pCount)] array of driver instance handles
        )
    {
        if( nullptr == context.zeDdiTable.Driver.pfnGet)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Driver.pfnGet, pCount, phDrivers);

        // capture parameters
        ze_driver_get_params_t tracerParams = {
            &pCount,
            &phDrivers
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnDriverGetCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnDriverGetCb_t, Driver, pfnGetCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Driver.pfnGet,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.ppCount,
                                                  *tracerParams.pphDrivers);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeDriverGetApiVersion
    __zedlllocal ze_result_t ZE_APICALL
    zeDriverGetApiVersion(
        ze_driver_handle_t hDriver,                     ///< [in] handle of the driver instance
        ze_api_version_t* version                       ///< [out] api version
        )
    {
        if( nullptr == context.zeDdiTable.Driver.pfnGetApiVersion)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Driver.pfnGetApiVersion, hDriver, version);

        // capture parameters
        ze_driver_get_api_version_params_t tracerParams = {
            &hDriver,
            &version
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnDriverGetApiVersionCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnDriverGetApiVersionCb_t, Driver, pfnGetApiVersionCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Driver.pfnGetApiVersion,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phDriver,
                                                  *tracerParams.pversion);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeDriverGetProperties
    __zedlllocal ze_result_t ZE_APICALL
    zeDriverGetProperties(
        ze_driver_handle_t hDriver,                     ///< [in] handle of the driver instance
        ze_driver_properties_t* pDriverProperties       ///< [in,out] query result for driver properties
        )
    {
        if( nullptr == context.zeDdiTable.Driver.pfnGetProperties)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Driver.pfnGetProperties, hDriver, pDriverProperties);

        // capture parameters
        ze_driver_get_properties_params_t tracerParams = {
            &hDriver,
            &pDriverProperties
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnDriverGetPropertiesCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnDriverGetPropertiesCb_t, Driver, pfnGetPropertiesCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Driver.pfnGetProperties,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phDriver,
                                                  *tracerParams.ppDriverProperties);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeDriverGetIpcProperties
    __zedlllocal ze_result_t ZE_APICALL
    zeDriverGetIpcProperties(
        ze_driver_handle_t hDriver,                     ///< [in] handle of the driver instance
        ze_driver_ipc_properties_t* pIpcProperties      ///< [out] query result for IPC properties
        )
    {
        if( nullptr == context.zeDdiTable.Driver.pfnGetIpcProperties)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Driver.pfnGetIpcProperties, hDriver, pIpcProperties);

        // capture parameters
        ze_driver_get_ipc_properties_params_t tracerParams = {
            &hDriver,
            &pIpcProperties
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnDriverGetIpcPropertiesCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnDriverGetIpcPropertiesCb_t, Driver, pfnGetIpcPropertiesCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Driver.pfnGetIpcProperties,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phDriver,
                                                  *tracerParams.ppIpcProperties);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeDriverGetExtensionProperties
    __zedlllocal ze_result_t ZE_APICALL
    zeDriverGetExtensionProperties(
        ze_driver_handle_t hDriver,                     ///< [in] handle of the driver instance
        uint32_t* pCount,                               ///< [in,out] pointer to the number of extension properties.
                                                        ///< if count is zero, then the driver will update the value with the total
                                                        ///< number of extension properties available.
                                                        ///< if count is non-zero, then driver will only retrieve that number of
                                                        ///< extension properties.
                                                        ///< if count is larger than the number of extension properties available,
                                                        ///< then the driver will update the value with the correct number of
                                                        ///< extension properties available.
        ze_driver_extension_properties_t* pExtensionProperties  ///< [in,out][optional][range(0, *pCount)] array of query results for
                                                        ///< extension properties
        )
    {
        if( nullptr == context.zeDdiTable.Driver.pfnGetExtensionProperties)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Driver.pfnGetExtensionProperties, hDriver, pCount, pExtensionProperties);

        // capture parameters
        ze_driver_get_extension_properties_params_t tracerParams = {
            &hDriver,
            &pCount,
            &pExtensionProperties
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnDriverGetExtensionPropertiesCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnDriverGetExtensionPropertiesCb_t, Driver, pfnGetExtensionPropertiesCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Driver.pfnGetExtensionProperties,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phDriver,
                                                  *tracerParams.ppCount,
                                                  *tracerParams.ppExtensionProperties);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeDeviceGet
    __zedlllocal ze_result_t ZE_APICALL
    zeDeviceGet(
        ze_driver_handle_t hDriver,                     ///< [in] handle of the driver instance
        uint32_t* pCount,                               ///< [in,out] pointer to the number of devices.
                                                        ///< if count is zero, then the driver will update the value with the total
                                                        ///< number of devices available.
                                                        ///< if count is non-zero, then driver will only retrieve that number of devices.
                                                        ///< if count is larger than the number of devices available, then the
                                                        ///< driver will update the value with the correct number of devices available.
        ze_device_handle_t* phDevices                   ///< [in,out][optional][range(0, *pCount)] array of handle of devices
        )
    {
        if( nullptr == context.zeDdiTable.Device.pfnGet)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Device.pfnGet, hDriver, pCount, phDevices);

        // capture parameters
        ze_device_get_params_t tracerParams = {
            &hDriver,
            &pCount,
            &phDevices
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnDeviceGetCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnDeviceGetCb_t, Device, pfnGetCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Device.pfnGet,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phDriver,
                                                  *tracerParams.ppCount,
                                                  *tracerParams.pphDevices);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeDeviceGetSubDevices
    __zedlllocal ze_result_t ZE_APICALL
    zeDeviceGetSubDevices(
        ze_device_handle_t hDevice,                     ///< [in] handle of the device object
        uint32_t* pCount,                               ///< [in,out] pointer to the number of sub-devices.
                                                        ///< if count is zero, then the driver will update the value with the total
                                                        ///< number of sub-devices available.
                                                        ///< if count is non-zero, then driver will only retrieve that number of sub-devices.
                                                        ///< if count is larger than the number of sub-devices available, then the
                                                        ///< driver will update the value with the correct number of sub-devices available.
        ze_device_handle_t* phSubdevices                ///< [in,out][optional][range(0, *pCount)] array of handle of sub-devices
        )
    {
        if( nullptr == context.zeDdiTable.Device.pfnGetSubDevices)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Device.pfnGetSubDevices, hDevice, pCount, phSubdevices);

        // capture parameters
        ze_device_get_sub_devices_params_t tracerParams = {
            &hDevice,
            &pCount,
            &phSubdevices
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnDeviceGetSubDevicesCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnDeviceGetSubDevicesCb_t, Device, pfnGetSubDevicesCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Device.pfnGetSubDevices,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phDevice,
                                                  *tracerParams.ppCount,
                                                  *tracerParams.pphSubdevices);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeDeviceGetProperties
    __zedlllocal ze_result_t ZE_APICALL
    zeDeviceGetProperties(
        ze_device_handle_t hDevice,                     ///< [in] handle of the device
        ze_device_properties_t* pDeviceProperties       ///< [in,out] query result for device properties
        )
    {
        if( nullptr == context.zeDdiTable.Device.pfnGetProperties)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Device.pfnGetProperties, hDevice, pDeviceProperties);

        // capture parameters
        ze_device_get_properties_params_t tracerParams = {
            &hDevice,
            &pDeviceProperties
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnDeviceGetPropertiesCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnDeviceGetPropertiesCb_t, Device, pfnGetPropertiesCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Device.pfnGetProperties,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phDevice,
                                                  *tracerParams.ppDeviceProperties);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeDeviceGetComputeProperties
    __zedlllocal ze_result_t ZE_APICALL
    zeDeviceGetComputeProperties(
        ze_device_handle_t hDevice,                     ///< [in] handle of the device
        ze_device_compute_properties_t* pComputeProperties  ///< [in,out] query result for compute properties
        )
    {
        if( nullptr == context.zeDdiTable.Device.pfnGetComputeProperties)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Device.pfnGetComputeProperties, hDevice, pComputeProperties);

        // capture parameters
        ze_device_get_compute_properties_params_t tracerParams = {
            &hDevice,
            &pComputeProperties
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnDeviceGetComputePropertiesCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnDeviceGetComputePropertiesCb_t, Device, pfnGetComputePropertiesCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Device.pfnGetComputeProperties,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phDevice,
                                                  *tracerParams.ppComputeProperties);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeDeviceGetModuleProperties
    __zedlllocal ze_result_t ZE_APICALL
    zeDeviceGetModuleProperties(
        ze_device_handle_t hDevice,                     ///< [in] handle of the device
        ze_device_module_properties_t* pModuleProperties///< [in,out] query result for module properties
        )
    {
        if( nullptr == context.zeDdiTable.Device.pfnGetModuleProperties)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Device.pfnGetModuleProperties, hDevice, pModuleProperties);

        // capture parameters
        ze_device_get_module_properties_params_t tracerParams = {
            &hDevice,
            &pModuleProperties
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnDeviceGetModulePropertiesCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnDeviceGetModulePropertiesCb_t, Device, pfnGetModulePropertiesCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Device.pfnGetModuleProperties,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phDevice,
                                                  *tracerParams.ppModuleProperties);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeDeviceGetCommandQueueGroupProperties
    __zedlllocal ze_result_t ZE_APICALL
    zeDeviceGetCommandQueueGroupProperties(
        ze_device_handle_t hDevice,                     ///< [in] handle of the device
        uint32_t* pCount,                               ///< [in,out] pointer to the number of command queue group properties.
                                                        ///< if count is zero, then the driver will update the value with the total
                                                        ///< number of command queue group properties available.
                                                        ///< if count is non-zero, then driver will only retrieve that number of
                                                        ///< command queue group properties.
                                                        ///< if count is larger than the number of command queue group properties
                                                        ///< available, then the driver will update the value with the correct
                                                        ///< number of command queue group properties available.
        ze_command_queue_group_properties_t* pCommandQueueGroupProperties   ///< [in,out][optional][range(0, *pCount)] array of query results for
                                                        ///< command queue group properties
        )
    {
        if( nullptr == context.zeDdiTable.Device.pfnGetCommandQueueGroupProperties)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Device.pfnGetCommandQueueGroupProperties, hDevice, pCount, pCommandQueueGroupProperties);

        // capture parameters
        ze_device_get_command_queue_group_properties_params_t tracerParams = {
            &hDevice,
            &pCount,
            &pCommandQueueGroupProperties
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnDeviceGetCommandQueueGroupPropertiesCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnDeviceGetCommandQueueGroupPropertiesCb_t, Device, pfnGetCommandQueueGroupPropertiesCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Device.pfnGetCommandQueueGroupProperties,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phDevice,
                                                  *tracerParams.ppCount,
                                                  *tracerParams.ppCommandQueueGroupProperties);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeDeviceGetMemoryProperties
    __zedlllocal ze_result_t ZE_APICALL
    zeDeviceGetMemoryProperties(
        ze_device_handle_t hDevice,                     ///< [in] handle of the device
        uint32_t* pCount,                               ///< [in,out] pointer to the number of memory properties.
                                                        ///< if count is zero, then the driver will update the value with the total
                                                        ///< number of memory properties available.
                                                        ///< if count is non-zero, then driver will only retrieve that number of
                                                        ///< memory properties.
                                                        ///< if count is larger than the number of memory properties available,
                                                        ///< then the driver will update the value with the correct number of
                                                        ///< memory properties available.
        ze_device_memory_properties_t* pMemProperties   ///< [in,out][optional][range(0, *pCount)] array of query results for
                                                        ///< memory properties
        )
    {
        if( nullptr == context.zeDdiTable.Device.pfnGetMemoryProperties)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Device.pfnGetMemoryProperties, hDevice, pCount, pMemProperties);

        // capture parameters
        ze_device_get_memory_properties_params_t tracerParams = {
            &hDevice,
            &pCount,
            &pMemProperties
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnDeviceGetMemoryPropertiesCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnDeviceGetMemoryPropertiesCb_t, Device, pfnGetMemoryPropertiesCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Device.pfnGetMemoryProperties,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phDevice,
                                                  *tracerParams.ppCount,
                                                  *tracerParams.ppMemProperties);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeDeviceGetMemoryAccessProperties
    __zedlllocal ze_result_t ZE_APICALL
    zeDeviceGetMemoryAccessProperties(
        ze_device_handle_t hDevice,                     ///< [in] handle of the device
        ze_device_memory_access_properties_t* pMemAccessProperties  ///< [in,out] query result for memory access properties
        )
    {
        if( nullptr == context.zeDdiTable.Device.pfnGetMemoryAccessProperties)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Device.pfnGetMemoryAccessProperties, hDevice, pMemAccessProperties);

        // capture parameters
        ze_device_get_memory_access_properties_params_t tracerParams = {
            &hDevice,
            &pMemAccessProperties
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnDeviceGetMemoryAccessPropertiesCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnDeviceGetMemoryAccessPropertiesCb_t, Device, pfnGetMemoryAccessPropertiesCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Device.pfnGetMemoryAccessProperties,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phDevice,
                                                  *tracerParams.ppMemAccessProperties);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeDeviceGetCacheProperties
    __zedlllocal ze_result_t ZE_APICALL
    zeDeviceGetCacheProperties(
        ze_device_handle_t hDevice,                     ///< [in] handle of the device
        uint32_t* pCount,                               ///< [in,out] pointer to the number of cache properties.
                                                        ///< if count is zero, then the driver will update the value with the total
                                                        ///< number of cache properties available.
                                                        ///< if count is non-zero, then driver will only retrieve that number of
                                                        ///< cache properties.
                                                        ///< if count is larger than the number of cache properties available, then
                                                        ///< the driver will update the value with the correct number of cache
                                                        ///< properties available.
        ze_device_cache_properties_t* pCacheProperties  ///< [in,out][optional][range(0, *pCount)] array of query results for cache
                                                        ///< properties
        )
    {
        if( nullptr == context.zeDdiTable.Device.pfnGetCacheProperties)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Device.pfnGetCacheProperties, hDevice, pCount, pCacheProperties);

        // capture parameters
        ze_device_get_cache_properties_params_t tracerParams = {
            &hDevice,
            &pCount,
            &pCacheProperties
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnDeviceGetCachePropertiesCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnDeviceGetCachePropertiesCb_t, Device, pfnGetCachePropertiesCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Device.pfnGetCacheProperties,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phDevice,
                                                  *tracerParams.ppCount,
                                                  *tracerParams.ppCacheProperties);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeDeviceGetImageProperties
    __zedlllocal ze_result_t ZE_APICALL
    zeDeviceGetImageProperties(
        ze_device_handle_t hDevice,                     ///< [in] handle of the device
        ze_device_image_properties_t* pImageProperties  ///< [in,out] query result for image properties
        )
    {
        if( nullptr == context.zeDdiTable.Device.pfnGetImageProperties)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Device.pfnGetImageProperties, hDevice, pImageProperties);

        // capture parameters
        ze_device_get_image_properties_params_t tracerParams = {
            &hDevice,
            &pImageProperties
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnDeviceGetImagePropertiesCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnDeviceGetImagePropertiesCb_t, Device, pfnGetImagePropertiesCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Device.pfnGetImageProperties,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phDevice,
                                                  *tracerParams.ppImageProperties);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeDeviceGetExternalMemoryProperties
    __zedlllocal ze_result_t ZE_APICALL
    zeDeviceGetExternalMemoryProperties(
        ze_device_handle_t hDevice,                     ///< [in] handle of the device
        ze_device_external_memory_properties_t* pExternalMemoryProperties   ///< [in,out] query result for external memory properties
        )
    {
        if( nullptr == context.zeDdiTable.Device.pfnGetExternalMemoryProperties)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Device.pfnGetExternalMemoryProperties, hDevice, pExternalMemoryProperties);

        // capture parameters
        ze_device_get_external_memory_properties_params_t tracerParams = {
            &hDevice,
            &pExternalMemoryProperties
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnDeviceGetExternalMemoryPropertiesCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnDeviceGetExternalMemoryPropertiesCb_t, Device, pfnGetExternalMemoryPropertiesCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Device.pfnGetExternalMemoryProperties,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phDevice,
                                                  *tracerParams.ppExternalMemoryProperties);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeDeviceGetP2PProperties
    __zedlllocal ze_result_t ZE_APICALL
    zeDeviceGetP2PProperties(
        ze_device_handle_t hDevice,                     ///< [in] handle of the device performing the access
        ze_device_handle_t hPeerDevice,                 ///< [in] handle of the peer device with the allocation
        ze_device_p2p_properties_t* pP2PProperties      ///< [in,out] Peer-to-Peer properties between source and peer device
        )
    {
        if( nullptr == context.zeDdiTable.Device.pfnGetP2PProperties)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Device.pfnGetP2PProperties, hDevice, hPeerDevice, pP2PProperties);

        // capture parameters
        ze_device_get_p2_p_properties_params_t tracerParams = {
            &hDevice,
            &hPeerDevice,
            &pP2PProperties
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnDeviceGetP2PPropertiesCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnDeviceGetP2PPropertiesCb_t, Device, pfnGetP2PPropertiesCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Device.pfnGetP2PProperties,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phDevice,
                                                  *tracerParams.phPeerDevice,
                                                  *tracerParams.ppP2PProperties);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeDeviceCanAccessPeer
    __zedlllocal ze_result_t ZE_APICALL
    zeDeviceCanAccessPeer(
        ze_device_handle_t hDevice,                     ///< [in] handle of the device performing the access
        ze_device_handle_t hPeerDevice,                 ///< [in] handle of the peer device with the allocation
        ze_bool_t* value                                ///< [out] returned access capability
        )
    {
        if( nullptr == context.zeDdiTable.Device.pfnCanAccessPeer)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Device.pfnCanAccessPeer, hDevice, hPeerDevice, value);

        // capture parameters
        ze_device_can_access_peer_params_t tracerParams = {
            &hDevice,
            &hPeerDevice,
            &value
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnDeviceCanAccessPeerCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnDeviceCanAccessPeerCb_t, Device, pfnCanAccessPeerCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Device.pfnCanAccessPeer,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phDevice,
                                                  *tracerParams.phPeerDevice,
                                                  *tracerParams.pvalue);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeDeviceGetStatus
    __zedlllocal ze_result_t ZE_APICALL
    zeDeviceGetStatus(
        ze_device_handle_t hDevice                      ///< [in] handle of the device
        )
    {
        if( nullptr == context.zeDdiTable.Device.pfnGetStatus)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Device.pfnGetStatus, hDevice);

        // capture parameters
        ze_device_get_status_params_t tracerParams = {
            &hDevice
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnDeviceGetStatusCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnDeviceGetStatusCb_t, Device, pfnGetStatusCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Device.pfnGetStatus,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phDevice);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeContextCreate
    __zedlllocal ze_result_t ZE_APICALL
    zeContextCreate(
        ze_driver_handle_t hDriver,                     ///< [in] handle of the driver object
        const ze_context_desc_t* desc,                  ///< [in] pointer to context descriptor
        ze_context_handle_t* phContext                  ///< [out] pointer to handle of context object created
        )
    {
        if( nullptr == context.zeDdiTable.Context.pfnCreate)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Context.pfnCreate, hDriver, desc, phContext);

        // capture parameters
        ze_context_create_params_t tracerParams = {
            &hDriver,
            &desc,
            &phContext
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnContextCreateCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnContextCreateCb_t, Context, pfnCreateCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Context.pfnCreate,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phDriver,
                                                  *tracerParams.pdesc,
                                                  *tracerParams.pphContext);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeContextDestroy
    __zedlllocal ze_result_t ZE_APICALL
    zeContextDestroy(
        ze_context_handle_t hContext                    ///< [in][release] handle of context object to destroy
        )
    {
        if( nullptr == context.zeDdiTable.Context.pfnDestroy)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Context.pfnDestroy, hContext);

        // capture parameters
        ze_context_destroy_params_t tracerParams = {
            &hContext
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnContextDestroyCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnContextDestroyCb_t, Context, pfnDestroyCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Context.pfnDestroy,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeContextGetStatus
    __zedlllocal ze_result_t ZE_APICALL
    zeContextGetStatus(
        ze_context_handle_t hContext                    ///< [in] handle of context object
        )
    {
        if( nullptr == context.zeDdiTable.Context.pfnGetStatus)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Context.pfnGetStatus, hContext);

        // capture parameters
        ze_context_get_status_params_t tracerParams = {
            &hContext
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnContextGetStatusCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnContextGetStatusCb_t, Context, pfnGetStatusCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Context.pfnGetStatus,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeCommandQueueCreate
    __zedlllocal ze_result_t ZE_APICALL
    zeCommandQueueCreate(
        ze_context_handle_t hContext,                   ///< [in] handle of the context object
        ze_device_handle_t hDevice,                     ///< [in] handle of the device object
        const ze_command_queue_desc_t* desc,            ///< [in] pointer to command queue descriptor
        ze_command_queue_handle_t* phCommandQueue       ///< [out] pointer to handle of command queue object created
        )
    {
        if( nullptr == context.zeDdiTable.CommandQueue.pfnCreate)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.CommandQueue.pfnCreate, hContext, hDevice, desc, phCommandQueue);

        // capture parameters
        ze_command_queue_create_params_t tracerParams = {
            &hContext,
            &hDevice,
            &desc,
            &phCommandQueue
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnCommandQueueCreateCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnCommandQueueCreateCb_t, CommandQueue, pfnCreateCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.CommandQueue.pfnCreate,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext,
                                                  *tracerParams.phDevice,
                                                  *tracerParams.pdesc,
                                                  *tracerParams.pphCommandQueue);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeCommandQueueDestroy
    __zedlllocal ze_result_t ZE_APICALL
    zeCommandQueueDestroy(
        ze_command_queue_handle_t hCommandQueue         ///< [in][release] handle of command queue object to destroy
        )
    {
        if( nullptr == context.zeDdiTable.CommandQueue.pfnDestroy)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.CommandQueue.pfnDestroy, hCommandQueue);

        // capture parameters
        ze_command_queue_destroy_params_t tracerParams = {
            &hCommandQueue
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnCommandQueueDestroyCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnCommandQueueDestroyCb_t, CommandQueue, pfnDestroyCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.CommandQueue.pfnDestroy,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phCommandQueue);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeCommandQueueExecuteCommandLists
    __zedlllocal ze_result_t ZE_APICALL
    zeCommandQueueExecuteCommandLists(
        ze_command_queue_handle_t hCommandQueue,        ///< [in] handle of the command queue
        uint32_t numCommandLists,                       ///< [in] number of command lists to execute
        ze_command_list_handle_t* phCommandLists,       ///< [in][range(0, numCommandLists)] list of handles of the command lists
                                                        ///< to execute
        ze_fence_handle_t hFence                        ///< [in][optional] handle of the fence to signal on completion
        )
    {
        if( nullptr == context.zeDdiTable.CommandQueue.pfnExecuteCommandLists)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.CommandQueue.pfnExecuteCommandLists, hCommandQueue, numCommandLists, phCommandLists, hFence);

        // capture parameters
        ze_command_queue_execute_command_lists_params_t tracerParams = {
            &hCommandQueue,
            &numCommandLists,
            &phCommandLists,
            &hFence
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnCommandQueueExecuteCommandListsCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnCommandQueueExecuteCommandListsCb_t, CommandQueue, pfnExecuteCommandListsCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.CommandQueue.pfnExecuteCommandLists,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phCommandQueue,
                                                  *tracerParams.pnumCommandLists,
                                                  *tracerParams.pphCommandLists,
                                                  *tracerParams.phFence);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeCommandQueueSynchronize
    __zedlllocal ze_result_t ZE_APICALL
    zeCommandQueueSynchronize(
        ze_command_queue_handle_t hCommandQueue,        ///< [in] handle of the command queue
        uint64_t timeout                                ///< [in] if non-zero, then indicates the maximum time (in nanoseconds) to
                                                        ///< yield before returning ::ZE_RESULT_SUCCESS or ::ZE_RESULT_NOT_READY;
                                                        ///< if zero, then immediately returns the status of the command queue;
                                                        ///< if UINT64_MAX, then function will not return until complete or device
                                                        ///< is lost.
                                                        ///< Due to external dependencies, timeout may be rounded to the closest
                                                        ///< value allowed by the accuracy of those dependencies.
        )
    {
        if( nullptr == context.zeDdiTable.CommandQueue.pfnSynchronize)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.CommandQueue.pfnSynchronize, hCommandQueue, timeout);

        // capture parameters
        ze_command_queue_synchronize_params_t tracerParams = {
            &hCommandQueue,
            &timeout
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnCommandQueueSynchronizeCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnCommandQueueSynchronizeCb_t, CommandQueue, pfnSynchronizeCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.CommandQueue.pfnSynchronize,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phCommandQueue,
                                                  *tracerParams.ptimeout);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeCommandListCreate
    __zedlllocal ze_result_t ZE_APICALL
    zeCommandListCreate(
        ze_context_handle_t hContext,                   ///< [in] handle of the context object
        ze_device_handle_t hDevice,                     ///< [in] handle of the device object
        const ze_command_list_desc_t* desc,             ///< [in] pointer to command list descriptor
        ze_command_list_handle_t* phCommandList         ///< [out] pointer to handle of command list object created
        )
    {
        if( nullptr == context.zeDdiTable.CommandList.pfnCreate)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.CommandList.pfnCreate, hContext, hDevice, desc, phCommandList);

        // capture parameters
        ze_command_list_create_params_t tracerParams = {
            &hContext,
            &hDevice,
            &desc,
            &phCommandList
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnCommandListCreateCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnCommandListCreateCb_t, CommandList, pfnCreateCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.CommandList.pfnCreate,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext,
                                                  *tracerParams.phDevice,
                                                  *tracerParams.pdesc,
                                                  *tracerParams.pphCommandList);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeCommandListCreateImmediate
    __zedlllocal ze_result_t ZE_APICALL
    zeCommandListCreateImmediate(
        ze_context_handle_t hContext,                   ///< [in] handle of the context object
        ze_device_handle_t hDevice,                     ///< [in] handle of the device object
        const ze_command_queue_desc_t* altdesc,         ///< [in] pointer to command queue descriptor
        ze_command_list_handle_t* phCommandList         ///< [out] pointer to handle of command list object created
        )
    {
        if( nullptr == context.zeDdiTable.CommandList.pfnCreateImmediate)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.CommandList.pfnCreateImmediate, hContext, hDevice, altdesc, phCommandList);

        // capture parameters
        ze_command_list_create_immediate_params_t tracerParams = {
            &hContext,
            &hDevice,
            &altdesc,
            &phCommandList
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnCommandListCreateImmediateCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnCommandListCreateImmediateCb_t, CommandList, pfnCreateImmediateCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.CommandList.pfnCreateImmediate,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext,
                                                  *tracerParams.phDevice,
                                                  *tracerParams.paltdesc,
                                                  *tracerParams.pphCommandList);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeCommandListDestroy
    __zedlllocal ze_result_t ZE_APICALL
    zeCommandListDestroy(
        ze_command_list_handle_t hCommandList           ///< [in][release] handle of command list object to destroy
        )
    {
        if( nullptr == context.zeDdiTable.CommandList.pfnDestroy)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.CommandList.pfnDestroy, hCommandList);

        // capture parameters
        ze_command_list_destroy_params_t tracerParams = {
            &hCommandList
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnCommandListDestroyCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnCommandListDestroyCb_t, CommandList, pfnDestroyCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.CommandList.pfnDestroy,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phCommandList);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeCommandListClose
    __zedlllocal ze_result_t ZE_APICALL
    zeCommandListClose(
        ze_command_list_handle_t hCommandList           ///< [in] handle of command list object to close
        )
    {
        if( nullptr == context.zeDdiTable.CommandList.pfnClose)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.CommandList.pfnClose, hCommandList);

        // capture parameters
        ze_command_list_close_params_t tracerParams = {
            &hCommandList
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnCommandListCloseCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnCommandListCloseCb_t, CommandList, pfnCloseCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.CommandList.pfnClose,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phCommandList);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeCommandListReset
    __zedlllocal ze_result_t ZE_APICALL
    zeCommandListReset(
        ze_command_list_handle_t hCommandList           ///< [in] handle of command list object to reset
        )
    {
        if( nullptr == context.zeDdiTable.CommandList.pfnReset)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.CommandList.pfnReset, hCommandList);

        // capture parameters
        ze_command_list_reset_params_t tracerParams = {
            &hCommandList
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnCommandListResetCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnCommandListResetCb_t, CommandList, pfnResetCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.CommandList.pfnReset,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phCommandList);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeCommandListAppendWriteGlobalTimestamp
    __zedlllocal ze_result_t ZE_APICALL
    zeCommandListAppendWriteGlobalTimestamp(
        ze_command_list_handle_t hCommandList,          ///< [in] handle of the command list
        uint64_t* dstptr,                               ///< [in,out] pointer to memory where timestamp value will be written; must
                                                        ///< be 8byte-aligned.
        ze_event_handle_t hSignalEvent,                 ///< [in][optional] handle of the event to signal on completion
        uint32_t numWaitEvents,                         ///< [in][optional] number of events to wait on before executing query;
                                                        ///< must be 0 if `nullptr == phWaitEvents`
        ze_event_handle_t* phWaitEvents                 ///< [in][optional][range(0, numWaitEvents)] handle of the events to wait
                                                        ///< on before executing query
        )
    {
        if( nullptr == context.zeDdiTable.CommandList.pfnAppendWriteGlobalTimestamp)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.CommandList.pfnAppendWriteGlobalTimestamp, hCommandList, dstptr, hSignalEvent, numWaitEvents, phWaitEvents);

        // capture parameters
        ze_command_list_append_write_global_timestamp_params_t tracerParams = {
            &hCommandList,
            &dstptr,
            &hSignalEvent,
            &numWaitEvents,
            &phWaitEvents
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnCommandListAppendWriteGlobalTimestampCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnCommandListAppendWriteGlobalTimestampCb_t, CommandList, pfnAppendWriteGlobalTimestampCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.CommandList.pfnAppendWriteGlobalTimestamp,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phCommandList,
                                                  *tracerParams.pdstptr,
                                                  *tracerParams.phSignalEvent,
                                                  *tracerParams.pnumWaitEvents,
                                                  *tracerParams.pphWaitEvents);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeCommandListAppendBarrier
    __zedlllocal ze_result_t ZE_APICALL
    zeCommandListAppendBarrier(
        ze_command_list_handle_t hCommandList,          ///< [in] handle of the command list
        ze_event_handle_t hSignalEvent,                 ///< [in][optional] handle of the event to signal on completion
        uint32_t numWaitEvents,                         ///< [in][optional] number of events to wait on before executing barrier;
                                                        ///< must be 0 if `nullptr == phWaitEvents`
        ze_event_handle_t* phWaitEvents                 ///< [in][optional][range(0, numWaitEvents)] handle of the events to wait
                                                        ///< on before executing barrier
        )
    {
        if( nullptr == context.zeDdiTable.CommandList.pfnAppendBarrier)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.CommandList.pfnAppendBarrier, hCommandList, hSignalEvent, numWaitEvents, phWaitEvents);

        // capture parameters
        ze_command_list_append_barrier_params_t tracerParams = {
            &hCommandList,
            &hSignalEvent,
            &numWaitEvents,
            &phWaitEvents
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnCommandListAppendBarrierCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnCommandListAppendBarrierCb_t, CommandList, pfnAppendBarrierCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.CommandList.pfnAppendBarrier,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phCommandList,
                                                  *tracerParams.phSignalEvent,
                                                  *tracerParams.pnumWaitEvents,
                                                  *tracerParams.pphWaitEvents);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeCommandListAppendMemoryRangesBarrier
    __zedlllocal ze_result_t ZE_APICALL
    zeCommandListAppendMemoryRangesBarrier(
        ze_command_list_handle_t hCommandList,          ///< [in] handle of the command list
        uint32_t numRanges,                             ///< [in] number of memory ranges
        const size_t* pRangeSizes,                      ///< [in][range(0, numRanges)] array of sizes of memory range
        const void** pRanges,                           ///< [in][range(0, numRanges)] array of memory ranges
        ze_event_handle_t hSignalEvent,                 ///< [in][optional] handle of the event to signal on completion
        uint32_t numWaitEvents,                         ///< [in][optional] number of events to wait on before executing barrier;
                                                        ///< must be 0 if `nullptr == phWaitEvents`
        ze_event_handle_t* phWaitEvents                 ///< [in][optional][range(0, numWaitEvents)] handle of the events to wait
                                                        ///< on before executing barrier
        )
    {
        if( nullptr == context.zeDdiTable.CommandList.pfnAppendMemoryRangesBarrier)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.CommandList.pfnAppendMemoryRangesBarrier, hCommandList, numRanges, pRangeSizes, pRanges, hSignalEvent, numWaitEvents, phWaitEvents);

        // capture parameters
        ze_command_list_append_memory_ranges_barrier_params_t tracerParams = {
            &hCommandList,
            &numRanges,
            &pRangeSizes,
            &pRanges,
            &hSignalEvent,
            &numWaitEvents,
            &phWaitEvents
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnCommandListAppendMemoryRangesBarrierCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnCommandListAppendMemoryRangesBarrierCb_t, CommandList, pfnAppendMemoryRangesBarrierCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.CommandList.pfnAppendMemoryRangesBarrier,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phCommandList,
                                                  *tracerParams.pnumRanges,
                                                  *tracerParams.ppRangeSizes,
                                                  *tracerParams.ppRanges,
                                                  *tracerParams.phSignalEvent,
                                                  *tracerParams.pnumWaitEvents,
                                                  *tracerParams.pphWaitEvents);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeContextSystemBarrier
    __zedlllocal ze_result_t ZE_APICALL
    zeContextSystemBarrier(
        ze_context_handle_t hContext,                   ///< [in] handle of context object
        ze_device_handle_t hDevice                      ///< [in] handle of the device
        )
    {
        if( nullptr == context.zeDdiTable.Context.pfnSystemBarrier)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Context.pfnSystemBarrier, hContext, hDevice);

        // capture parameters
        ze_context_system_barrier_params_t tracerParams = {
            &hContext,
            &hDevice
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnContextSystemBarrierCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnContextSystemBarrierCb_t, Context, pfnSystemBarrierCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Context.pfnSystemBarrier,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext,
                                                  *tracerParams.phDevice);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeCommandListAppendMemoryCopy
    __zedlllocal ze_result_t ZE_APICALL
    zeCommandListAppendMemoryCopy(
        ze_command_list_handle_t hCommandList,          ///< [in] handle of command list
        void* dstptr,                                   ///< [in] pointer to destination memory to copy to
        const void* srcptr,                             ///< [in] pointer to source memory to copy from
        size_t size,                                    ///< [in] size in bytes to copy
        ze_event_handle_t hSignalEvent,                 ///< [in][optional] handle of the event to signal on completion
        uint32_t numWaitEvents,                         ///< [in][optional] number of events to wait on before launching; must be 0
                                                        ///< if `nullptr == phWaitEvents`
        ze_event_handle_t* phWaitEvents                 ///< [in][optional][range(0, numWaitEvents)] handle of the events to wait
                                                        ///< on before launching
        )
    {
        if( nullptr == context.zeDdiTable.CommandList.pfnAppendMemoryCopy)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.CommandList.pfnAppendMemoryCopy, hCommandList, dstptr, srcptr, size, hSignalEvent, numWaitEvents, phWaitEvents);

        // capture parameters
        ze_command_list_append_memory_copy_params_t tracerParams = {
            &hCommandList,
            &dstptr,
            &srcptr,
            &size,
            &hSignalEvent,
            &numWaitEvents,
            &phWaitEvents
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnCommandListAppendMemoryCopyCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnCommandListAppendMemoryCopyCb_t, CommandList, pfnAppendMemoryCopyCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.CommandList.pfnAppendMemoryCopy,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phCommandList,
                                                  *tracerParams.pdstptr,
                                                  *tracerParams.psrcptr,
                                                  *tracerParams.psize,
                                                  *tracerParams.phSignalEvent,
                                                  *tracerParams.pnumWaitEvents,
                                                  *tracerParams.pphWaitEvents);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeCommandListAppendMemoryFill
    __zedlllocal ze_result_t ZE_APICALL
    zeCommandListAppendMemoryFill(
        ze_command_list_handle_t hCommandList,          ///< [in] handle of command list
        void* ptr,                                      ///< [in] pointer to memory to initialize
        const void* pattern,                            ///< [in] pointer to value to initialize memory to
        size_t pattern_size,                            ///< [in] size in bytes of the value to initialize memory to
        size_t size,                                    ///< [in] size in bytes to initialize
        ze_event_handle_t hSignalEvent,                 ///< [in][optional] handle of the event to signal on completion
        uint32_t numWaitEvents,                         ///< [in][optional] number of events to wait on before launching; must be 0
                                                        ///< if `nullptr == phWaitEvents`
        ze_event_handle_t* phWaitEvents                 ///< [in][optional][range(0, numWaitEvents)] handle of the events to wait
                                                        ///< on before launching
        )
    {
        if( nullptr == context.zeDdiTable.CommandList.pfnAppendMemoryFill)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.CommandList.pfnAppendMemoryFill, hCommandList, ptr, pattern, pattern_size, size, hSignalEvent, numWaitEvents, phWaitEvents);

        // capture parameters
        ze_command_list_append_memory_fill_params_t tracerParams = {
            &hCommandList,
            &ptr,
            &pattern,
            &pattern_size,
            &size,
            &hSignalEvent,
            &numWaitEvents,
            &phWaitEvents
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnCommandListAppendMemoryFillCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnCommandListAppendMemoryFillCb_t, CommandList, pfnAppendMemoryFillCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.CommandList.pfnAppendMemoryFill,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phCommandList,
                                                  *tracerParams.pptr,
                                                  *tracerParams.ppattern,
                                                  *tracerParams.ppattern_size,
                                                  *tracerParams.psize,
                                                  *tracerParams.phSignalEvent,
                                                  *tracerParams.pnumWaitEvents,
                                                  *tracerParams.pphWaitEvents);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeCommandListAppendMemoryCopyRegion
    __zedlllocal ze_result_t ZE_APICALL
    zeCommandListAppendMemoryCopyRegion(
        ze_command_list_handle_t hCommandList,          ///< [in] handle of command list
        void* dstptr,                                   ///< [in] pointer to destination memory to copy to
        const ze_copy_region_t* dstRegion,              ///< [in] pointer to destination region to copy to
        uint32_t dstPitch,                              ///< [in] destination pitch in bytes
        uint32_t dstSlicePitch,                         ///< [in] destination slice pitch in bytes. This is required for 3D region
                                                        ///< copies where ::ze_copy_region_t.depth is not 0, otherwise it's
                                                        ///< ignored.
        const void* srcptr,                             ///< [in] pointer to source memory to copy from
        const ze_copy_region_t* srcRegion,              ///< [in] pointer to source region to copy from
        uint32_t srcPitch,                              ///< [in] source pitch in bytes
        uint32_t srcSlicePitch,                         ///< [in] source slice pitch in bytes. This is required for 3D region
                                                        ///< copies where ::ze_copy_region_t.depth is not 0, otherwise it's
                                                        ///< ignored.
        ze_event_handle_t hSignalEvent,                 ///< [in][optional] handle of the event to signal on completion
        uint32_t numWaitEvents,                         ///< [in][optional] number of events to wait on before launching; must be 0
                                                        ///< if `nullptr == phWaitEvents`
        ze_event_handle_t* phWaitEvents                 ///< [in][optional][range(0, numWaitEvents)] handle of the events to wait
                                                        ///< on before launching
        )
    {
        if( nullptr == context.zeDdiTable.CommandList.pfnAppendMemoryCopyRegion)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.CommandList.pfnAppendMemoryCopyRegion, hCommandList, dstptr, dstRegion, dstPitch, dstSlicePitch, srcptr, srcRegion, srcPitch, srcSlicePitch, hSignalEvent, numWaitEvents, phWaitEvents);

        // capture parameters
        ze_command_list_append_memory_copy_region_params_t tracerParams = {
            &hCommandList,
            &dstptr,
            &dstRegion,
            &dstPitch,
            &dstSlicePitch,
            &srcptr,
            &srcRegion,
            &srcPitch,
            &srcSlicePitch,
            &hSignalEvent,
            &numWaitEvents,
            &phWaitEvents
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnCommandListAppendMemoryCopyRegionCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnCommandListAppendMemoryCopyRegionCb_t, CommandList, pfnAppendMemoryCopyRegionCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.CommandList.pfnAppendMemoryCopyRegion,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phCommandList,
                                                  *tracerParams.pdstptr,
                                                  *tracerParams.pdstRegion,
                                                  *tracerParams.pdstPitch,
                                                  *tracerParams.pdstSlicePitch,
                                                  *tracerParams.psrcptr,
                                                  *tracerParams.psrcRegion,
                                                  *tracerParams.psrcPitch,
                                                  *tracerParams.psrcSlicePitch,
                                                  *tracerParams.phSignalEvent,
                                                  *tracerParams.pnumWaitEvents,
                                                  *tracerParams.pphWaitEvents);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeCommandListAppendMemoryCopyFromContext
    __zedlllocal ze_result_t ZE_APICALL
    zeCommandListAppendMemoryCopyFromContext(
        ze_command_list_handle_t hCommandList,          ///< [in] handle of command list
        void* dstptr,                                   ///< [in] pointer to destination memory to copy to
        ze_context_handle_t hContextSrc,                ///< [in] handle of source context object
        const void* srcptr,                             ///< [in] pointer to source memory to copy from
        size_t size,                                    ///< [in] size in bytes to copy
        ze_event_handle_t hSignalEvent,                 ///< [in][optional] handle of the event to signal on completion
        uint32_t numWaitEvents,                         ///< [in][optional] number of events to wait on before launching; must be 0
                                                        ///< if `nullptr == phWaitEvents`
        ze_event_handle_t* phWaitEvents                 ///< [in][optional][range(0, numWaitEvents)] handle of the events to wait
                                                        ///< on before launching
        )
    {
        if( nullptr == context.zeDdiTable.CommandList.pfnAppendMemoryCopyFromContext)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.CommandList.pfnAppendMemoryCopyFromContext, hCommandList, dstptr, hContextSrc, srcptr, size, hSignalEvent, numWaitEvents, phWaitEvents);

        // capture parameters
        ze_command_list_append_memory_copy_from_context_params_t tracerParams = {
            &hCommandList,
            &dstptr,
            &hContextSrc,
            &srcptr,
            &size,
            &hSignalEvent,
            &numWaitEvents,
            &phWaitEvents
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnCommandListAppendMemoryCopyFromContextCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnCommandListAppendMemoryCopyFromContextCb_t, CommandList, pfnAppendMemoryCopyFromContextCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.CommandList.pfnAppendMemoryCopyFromContext,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phCommandList,
                                                  *tracerParams.pdstptr,
                                                  *tracerParams.phContextSrc,
                                                  *tracerParams.psrcptr,
                                                  *tracerParams.psize,
                                                  *tracerParams.phSignalEvent,
                                                  *tracerParams.pnumWaitEvents,
                                                  *tracerParams.pphWaitEvents);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeCommandListAppendImageCopy
    __zedlllocal ze_result_t ZE_APICALL
    zeCommandListAppendImageCopy(
        ze_command_list_handle_t hCommandList,          ///< [in] handle of command list
        ze_image_handle_t hDstImage,                    ///< [in] handle of destination image to copy to
        ze_image_handle_t hSrcImage,                    ///< [in] handle of source image to copy from
        ze_event_handle_t hSignalEvent,                 ///< [in][optional] handle of the event to signal on completion
        uint32_t numWaitEvents,                         ///< [in][optional] number of events to wait on before launching; must be 0
                                                        ///< if `nullptr == phWaitEvents`
        ze_event_handle_t* phWaitEvents                 ///< [in][optional][range(0, numWaitEvents)] handle of the events to wait
                                                        ///< on before launching
        )
    {
        if( nullptr == context.zeDdiTable.CommandList.pfnAppendImageCopy)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.CommandList.pfnAppendImageCopy, hCommandList, hDstImage, hSrcImage, hSignalEvent, numWaitEvents, phWaitEvents);

        // capture parameters
        ze_command_list_append_image_copy_params_t tracerParams = {
            &hCommandList,
            &hDstImage,
            &hSrcImage,
            &hSignalEvent,
            &numWaitEvents,
            &phWaitEvents
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnCommandListAppendImageCopyCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnCommandListAppendImageCopyCb_t, CommandList, pfnAppendImageCopyCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.CommandList.pfnAppendImageCopy,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phCommandList,
                                                  *tracerParams.phDstImage,
                                                  *tracerParams.phSrcImage,
                                                  *tracerParams.phSignalEvent,
                                                  *tracerParams.pnumWaitEvents,
                                                  *tracerParams.pphWaitEvents);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeCommandListAppendImageCopyRegion
    __zedlllocal ze_result_t ZE_APICALL
    zeCommandListAppendImageCopyRegion(
        ze_command_list_handle_t hCommandList,          ///< [in] handle of command list
        ze_image_handle_t hDstImage,                    ///< [in] handle of destination image to copy to
        ze_image_handle_t hSrcImage,                    ///< [in] handle of source image to copy from
        const ze_image_region_t* pDstRegion,            ///< [in][optional] destination region descriptor
        const ze_image_region_t* pSrcRegion,            ///< [in][optional] source region descriptor
        ze_event_handle_t hSignalEvent,                 ///< [in][optional] handle of the event to signal on completion
        uint32_t numWaitEvents,                         ///< [in][optional] number of events to wait on before launching; must be 0
                                                        ///< if `nullptr == phWaitEvents`
        ze_event_handle_t* phWaitEvents                 ///< [in][optional][range(0, numWaitEvents)] handle of the events to wait
                                                        ///< on before launching
        )
    {
        if( nullptr == context.zeDdiTable.CommandList.pfnAppendImageCopyRegion)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.CommandList.pfnAppendImageCopyRegion, hCommandList, hDstImage, hSrcImage, pDstRegion, pSrcRegion, hSignalEvent, numWaitEvents, phWaitEvents);

        // capture parameters
        ze_command_list_append_image_copy_region_params_t tracerParams = {
            &hCommandList,
            &hDstImage,
            &hSrcImage,
            &pDstRegion,
            &pSrcRegion,
            &hSignalEvent,
            &numWaitEvents,
            &phWaitEvents
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnCommandListAppendImageCopyRegionCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnCommandListAppendImageCopyRegionCb_t, CommandList, pfnAppendImageCopyRegionCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.CommandList.pfnAppendImageCopyRegion,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phCommandList,
                                                  *tracerParams.phDstImage,
                                                  *tracerParams.phSrcImage,
                                                  *tracerParams.ppDstRegion,
                                                  *tracerParams.ppSrcRegion,
                                                  *tracerParams.phSignalEvent,
                                                  *tracerParams.pnumWaitEvents,
                                                  *tracerParams.pphWaitEvents);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeCommandListAppendImageCopyToMemory
    __zedlllocal ze_result_t ZE_APICALL
    zeCommandListAppendImageCopyToMemory(
        ze_command_list_handle_t hCommandList,          ///< [in] handle of command list
        void* dstptr,                                   ///< [in] pointer to destination memory to copy to
        ze_image_handle_t hSrcImage,                    ///< [in] handle of source image to copy from
        const ze_image_region_t* pSrcRegion,            ///< [in][optional] source region descriptor
        ze_event_handle_t hSignalEvent,                 ///< [in][optional] handle of the event to signal on completion
        uint32_t numWaitEvents,                         ///< [in][optional] number of events to wait on before launching; must be 0
                                                        ///< if `nullptr == phWaitEvents`
        ze_event_handle_t* phWaitEvents                 ///< [in][optional][range(0, numWaitEvents)] handle of the events to wait
                                                        ///< on before launching
        )
    {
        if( nullptr == context.zeDdiTable.CommandList.pfnAppendImageCopyToMemory)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.CommandList.pfnAppendImageCopyToMemory, hCommandList, dstptr, hSrcImage, pSrcRegion, hSignalEvent, numWaitEvents, phWaitEvents);

        // capture parameters
        ze_command_list_append_image_copy_to_memory_params_t tracerParams = {
            &hCommandList,
            &dstptr,
            &hSrcImage,
            &pSrcRegion,
            &hSignalEvent,
            &numWaitEvents,
            &phWaitEvents
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnCommandListAppendImageCopyToMemoryCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnCommandListAppendImageCopyToMemoryCb_t, CommandList, pfnAppendImageCopyToMemoryCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.CommandList.pfnAppendImageCopyToMemory,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phCommandList,
                                                  *tracerParams.pdstptr,
                                                  *tracerParams.phSrcImage,
                                                  *tracerParams.ppSrcRegion,
                                                  *tracerParams.phSignalEvent,
                                                  *tracerParams.pnumWaitEvents,
                                                  *tracerParams.pphWaitEvents);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeCommandListAppendImageCopyFromMemory
    __zedlllocal ze_result_t ZE_APICALL
    zeCommandListAppendImageCopyFromMemory(
        ze_command_list_handle_t hCommandList,          ///< [in] handle of command list
        ze_image_handle_t hDstImage,                    ///< [in] handle of destination image to copy to
        const void* srcptr,                             ///< [in] pointer to source memory to copy from
        const ze_image_region_t* pDstRegion,            ///< [in][optional] destination region descriptor
        ze_event_handle_t hSignalEvent,                 ///< [in][optional] handle of the event to signal on completion
        uint32_t numWaitEvents,                         ///< [in][optional] number of events to wait on before launching; must be 0
                                                        ///< if `nullptr == phWaitEvents`
        ze_event_handle_t* phWaitEvents                 ///< [in][optional][range(0, numWaitEvents)] handle of the events to wait
                                                        ///< on before launching
        )
    {
        if( nullptr == context.zeDdiTable.CommandList.pfnAppendImageCopyFromMemory)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.CommandList.pfnAppendImageCopyFromMemory, hCommandList, hDstImage, srcptr, pDstRegion, hSignalEvent, numWaitEvents, phWaitEvents);

        // capture parameters
        ze_command_list_append_image_copy_from_memory_params_t tracerParams = {
            &hCommandList,
            &hDstImage,
            &srcptr,
            &pDstRegion,
            &hSignalEvent,
            &numWaitEvents,
            &phWaitEvents
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnCommandListAppendImageCopyFromMemoryCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnCommandListAppendImageCopyFromMemoryCb_t, CommandList, pfnAppendImageCopyFromMemoryCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.CommandList.pfnAppendImageCopyFromMemory,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phCommandList,
                                                  *tracerParams.phDstImage,
                                                  *tracerParams.psrcptr,
                                                  *tracerParams.ppDstRegion,
                                                  *tracerParams.phSignalEvent,
                                                  *tracerParams.pnumWaitEvents,
                                                  *tracerParams.pphWaitEvents);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeCommandListAppendMemoryPrefetch
    __zedlllocal ze_result_t ZE_APICALL
    zeCommandListAppendMemoryPrefetch(
        ze_command_list_handle_t hCommandList,          ///< [in] handle of command list
        const void* ptr,                                ///< [in] pointer to start of the memory range to prefetch
        size_t size                                     ///< [in] size in bytes of the memory range to prefetch
        )
    {
        if( nullptr == context.zeDdiTable.CommandList.pfnAppendMemoryPrefetch)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.CommandList.pfnAppendMemoryPrefetch, hCommandList, ptr, size);

        // capture parameters
        ze_command_list_append_memory_prefetch_params_t tracerParams = {
            &hCommandList,
            &ptr,
            &size
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnCommandListAppendMemoryPrefetchCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnCommandListAppendMemoryPrefetchCb_t, CommandList, pfnAppendMemoryPrefetchCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.CommandList.pfnAppendMemoryPrefetch,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phCommandList,
                                                  *tracerParams.pptr,
                                                  *tracerParams.psize);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeCommandListAppendMemAdvise
    __zedlllocal ze_result_t ZE_APICALL
    zeCommandListAppendMemAdvise(
        ze_command_list_handle_t hCommandList,          ///< [in] handle of command list
        ze_device_handle_t hDevice,                     ///< [in] device associated with the memory advice
        const void* ptr,                                ///< [in] Pointer to the start of the memory range
        size_t size,                                    ///< [in] Size in bytes of the memory range
        ze_memory_advice_t advice                       ///< [in] Memory advice for the memory range
        )
    {
        if( nullptr == context.zeDdiTable.CommandList.pfnAppendMemAdvise)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.CommandList.pfnAppendMemAdvise, hCommandList, hDevice, ptr, size, advice);

        // capture parameters
        ze_command_list_append_mem_advise_params_t tracerParams = {
            &hCommandList,
            &hDevice,
            &ptr,
            &size,
            &advice
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnCommandListAppendMemAdviseCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnCommandListAppendMemAdviseCb_t, CommandList, pfnAppendMemAdviseCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.CommandList.pfnAppendMemAdvise,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phCommandList,
                                                  *tracerParams.phDevice,
                                                  *tracerParams.pptr,
                                                  *tracerParams.psize,
                                                  *tracerParams.padvice);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeEventPoolCreate
    __zedlllocal ze_result_t ZE_APICALL
    zeEventPoolCreate(
        ze_context_handle_t hContext,                   ///< [in] handle of the context object
        const ze_event_pool_desc_t* desc,               ///< [in] pointer to event pool descriptor
        uint32_t numDevices,                            ///< [in][optional] number of device handles; must be 0 if `nullptr ==
                                                        ///< phDevices`
        ze_device_handle_t* phDevices,                  ///< [in][optional][range(0, numDevices)] array of device handles which
                                                        ///< have visibility to the event pool.
                                                        ///< if nullptr, then event pool is visible to all devices supported by the
                                                        ///< driver instance.
        ze_event_pool_handle_t* phEventPool             ///< [out] pointer handle of event pool object created
        )
    {
        if( nullptr == context.zeDdiTable.EventPool.pfnCreate)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.EventPool.pfnCreate, hContext, desc, numDevices, phDevices, phEventPool);

        // capture parameters
        ze_event_pool_create_params_t tracerParams = {
            &hContext,
            &desc,
            &numDevices,
            &phDevices,
            &phEventPool
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnEventPoolCreateCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnEventPoolCreateCb_t, EventPool, pfnCreateCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.EventPool.pfnCreate,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext,
                                                  *tracerParams.pdesc,
                                                  *tracerParams.pnumDevices,
                                                  *tracerParams.pphDevices,
                                                  *tracerParams.pphEventPool);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeEventPoolDestroy
    __zedlllocal ze_result_t ZE_APICALL
    zeEventPoolDestroy(
        ze_event_pool_handle_t hEventPool               ///< [in][release] handle of event pool object to destroy
        )
    {
        if( nullptr == context.zeDdiTable.EventPool.pfnDestroy)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.EventPool.pfnDestroy, hEventPool);

        // capture parameters
        ze_event_pool_destroy_params_t tracerParams = {
            &hEventPool
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnEventPoolDestroyCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnEventPoolDestroyCb_t, EventPool, pfnDestroyCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.EventPool.pfnDestroy,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phEventPool);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeEventCreate
    __zedlllocal ze_result_t ZE_APICALL
    zeEventCreate(
        ze_event_pool_handle_t hEventPool,              ///< [in] handle of the event pool
        const ze_event_desc_t* desc,                    ///< [in] pointer to event descriptor
        ze_event_handle_t* phEvent                      ///< [out] pointer to handle of event object created
        )
    {
        if( nullptr == context.zeDdiTable.Event.pfnCreate)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Event.pfnCreate, hEventPool, desc, phEvent);

        // capture parameters
        ze_event_create_params_t tracerParams = {
            &hEventPool,
            &desc,
            &phEvent
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnEventCreateCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnEventCreateCb_t, Event, pfnCreateCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Event.pfnCreate,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phEventPool,
                                                  *tracerParams.pdesc,
                                                  *tracerParams.pphEvent);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeEventDestroy
    __zedlllocal ze_result_t ZE_APICALL
    zeEventDestroy(
        ze_event_handle_t hEvent                        ///< [in][release] handle of event object to destroy
        )
    {
        if( nullptr == context.zeDdiTable.Event.pfnDestroy)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Event.pfnDestroy, hEvent);

        // capture parameters
        ze_event_destroy_params_t tracerParams = {
            &hEvent
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnEventDestroyCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnEventDestroyCb_t, Event, pfnDestroyCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Event.pfnDestroy,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phEvent);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeEventPoolGetIpcHandle
    __zedlllocal ze_result_t ZE_APICALL
    zeEventPoolGetIpcHandle(
        ze_event_pool_handle_t hEventPool,              ///< [in] handle of event pool object
        ze_ipc_event_pool_handle_t* phIpc               ///< [out] Returned IPC event handle
        )
    {
        if( nullptr == context.zeDdiTable.EventPool.pfnGetIpcHandle)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.EventPool.pfnGetIpcHandle, hEventPool, phIpc);

        // capture parameters
        ze_event_pool_get_ipc_handle_params_t tracerParams = {
            &hEventPool,
            &phIpc
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnEventPoolGetIpcHandleCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnEventPoolGetIpcHandleCb_t, EventPool, pfnGetIpcHandleCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.EventPool.pfnGetIpcHandle,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phEventPool,
                                                  *tracerParams.pphIpc);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeEventPoolOpenIpcHandle
    __zedlllocal ze_result_t ZE_APICALL
    zeEventPoolOpenIpcHandle(
        ze_context_handle_t hContext,                   ///< [in] handle of the context object to associate with the IPC event pool
                                                        ///< handle
        ze_ipc_event_pool_handle_t hIpc,                ///< [in] IPC event pool handle
        ze_event_pool_handle_t* phEventPool             ///< [out] pointer handle of event pool object created
        )
    {
        if( nullptr == context.zeDdiTable.EventPool.pfnOpenIpcHandle)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.EventPool.pfnOpenIpcHandle, hContext, hIpc, phEventPool);

        // capture parameters
        ze_event_pool_open_ipc_handle_params_t tracerParams = {
            &hContext,
            &hIpc,
            &phEventPool
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnEventPoolOpenIpcHandleCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnEventPoolOpenIpcHandleCb_t, EventPool, pfnOpenIpcHandleCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.EventPool.pfnOpenIpcHandle,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext,
                                                  *tracerParams.phIpc,
                                                  *tracerParams.pphEventPool);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeEventPoolCloseIpcHandle
    __zedlllocal ze_result_t ZE_APICALL
    zeEventPoolCloseIpcHandle(
        ze_event_pool_handle_t hEventPool               ///< [in][release] handle of event pool object
        )
    {
        if( nullptr == context.zeDdiTable.EventPool.pfnCloseIpcHandle)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.EventPool.pfnCloseIpcHandle, hEventPool);

        // capture parameters
        ze_event_pool_close_ipc_handle_params_t tracerParams = {
            &hEventPool
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnEventPoolCloseIpcHandleCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnEventPoolCloseIpcHandleCb_t, EventPool, pfnCloseIpcHandleCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.EventPool.pfnCloseIpcHandle,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phEventPool);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeCommandListAppendSignalEvent
    __zedlllocal ze_result_t ZE_APICALL
    zeCommandListAppendSignalEvent(
        ze_command_list_handle_t hCommandList,          ///< [in] handle of the command list
        ze_event_handle_t hEvent                        ///< [in] handle of the event
        )
    {
        if( nullptr == context.zeDdiTable.CommandList.pfnAppendSignalEvent)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.CommandList.pfnAppendSignalEvent, hCommandList, hEvent);

        // capture parameters
        ze_command_list_append_signal_event_params_t tracerParams = {
            &hCommandList,
            &hEvent
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnCommandListAppendSignalEventCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnCommandListAppendSignalEventCb_t, CommandList, pfnAppendSignalEventCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.CommandList.pfnAppendSignalEvent,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phCommandList,
                                                  *tracerParams.phEvent);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeCommandListAppendWaitOnEvents
    __zedlllocal ze_result_t ZE_APICALL
    zeCommandListAppendWaitOnEvents(
        ze_command_list_handle_t hCommandList,          ///< [in] handle of the command list
        uint32_t numEvents,                             ///< [in] number of events to wait on before continuing
        ze_event_handle_t* phEvents                     ///< [in][range(0, numEvents)] handles of the events to wait on before
                                                        ///< continuing
        )
    {
        if( nullptr == context.zeDdiTable.CommandList.pfnAppendWaitOnEvents)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.CommandList.pfnAppendWaitOnEvents, hCommandList, numEvents, phEvents);

        // capture parameters
        ze_command_list_append_wait_on_events_params_t tracerParams = {
            &hCommandList,
            &numEvents,
            &phEvents
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnCommandListAppendWaitOnEventsCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnCommandListAppendWaitOnEventsCb_t, CommandList, pfnAppendWaitOnEventsCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.CommandList.pfnAppendWaitOnEvents,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phCommandList,
                                                  *tracerParams.pnumEvents,
                                                  *tracerParams.pphEvents);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeEventHostSignal
    __zedlllocal ze_result_t ZE_APICALL
    zeEventHostSignal(
        ze_event_handle_t hEvent                        ///< [in] handle of the event
        )
    {
        if( nullptr == context.zeDdiTable.Event.pfnHostSignal)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Event.pfnHostSignal, hEvent);

        // capture parameters
        ze_event_host_signal_params_t tracerParams = {
            &hEvent
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnEventHostSignalCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnEventHostSignalCb_t, Event, pfnHostSignalCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Event.pfnHostSignal,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phEvent);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeEventHostSynchronize
    __zedlllocal ze_result_t ZE_APICALL
    zeEventHostSynchronize(
        ze_event_handle_t hEvent,                       ///< [in] handle of the event
        uint64_t timeout                                ///< [in] if non-zero, then indicates the maximum time (in nanoseconds) to
                                                        ///< yield before returning ::ZE_RESULT_SUCCESS or ::ZE_RESULT_NOT_READY;
                                                        ///< if zero, then operates exactly like ::zeEventQueryStatus;
                                                        ///< if UINT64_MAX, then function will not return until complete or device
                                                        ///< is lost.
                                                        ///< Due to external dependencies, timeout may be rounded to the closest
                                                        ///< value allowed by the accuracy of those dependencies.
        )
    {
        if( nullptr == context.zeDdiTable.Event.pfnHostSynchronize)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Event.pfnHostSynchronize, hEvent, timeout);

        // capture parameters
        ze_event_host_synchronize_params_t tracerParams = {
            &hEvent,
            &timeout
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnEventHostSynchronizeCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnEventHostSynchronizeCb_t, Event, pfnHostSynchronizeCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Event.pfnHostSynchronize,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phEvent,
                                                  *tracerParams.ptimeout);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeEventQueryStatus
    __zedlllocal ze_result_t ZE_APICALL
    zeEventQueryStatus(
        ze_event_handle_t hEvent                        ///< [in] handle of the event
        )
    {
        if( nullptr == context.zeDdiTable.Event.pfnQueryStatus)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Event.pfnQueryStatus, hEvent);

        // capture parameters
        ze_event_query_status_params_t tracerParams = {
            &hEvent
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnEventQueryStatusCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnEventQueryStatusCb_t, Event, pfnQueryStatusCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Event.pfnQueryStatus,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phEvent);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeCommandListAppendEventReset
    __zedlllocal ze_result_t ZE_APICALL
    zeCommandListAppendEventReset(
        ze_command_list_handle_t hCommandList,          ///< [in] handle of the command list
        ze_event_handle_t hEvent                        ///< [in] handle of the event
        )
    {
        if( nullptr == context.zeDdiTable.CommandList.pfnAppendEventReset)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.CommandList.pfnAppendEventReset, hCommandList, hEvent);

        // capture parameters
        ze_command_list_append_event_reset_params_t tracerParams = {
            &hCommandList,
            &hEvent
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnCommandListAppendEventResetCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnCommandListAppendEventResetCb_t, CommandList, pfnAppendEventResetCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.CommandList.pfnAppendEventReset,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phCommandList,
                                                  *tracerParams.phEvent);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeEventHostReset
    __zedlllocal ze_result_t ZE_APICALL
    zeEventHostReset(
        ze_event_handle_t hEvent                        ///< [in] handle of the event
        )
    {
        if( nullptr == context.zeDdiTable.Event.pfnHostReset)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Event.pfnHostReset, hEvent);

        // capture parameters
        ze_event_host_reset_params_t tracerParams = {
            &hEvent
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnEventHostResetCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnEventHostResetCb_t, Event, pfnHostResetCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Event.pfnHostReset,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phEvent);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeEventQueryKernelTimestamp
    __zedlllocal ze_result_t ZE_APICALL
    zeEventQueryKernelTimestamp(
        ze_event_handle_t hEvent,                       ///< [in] handle of the event
        ze_kernel_timestamp_result_t* dstptr            ///< [in,out] pointer to memory for where timestamp result will be written.
        )
    {
        if( nullptr == context.zeDdiTable.Event.pfnQueryKernelTimestamp)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Event.pfnQueryKernelTimestamp, hEvent, dstptr);

        // capture parameters
        ze_event_query_kernel_timestamp_params_t tracerParams = {
            &hEvent,
            &dstptr
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnEventQueryKernelTimestampCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnEventQueryKernelTimestampCb_t, Event, pfnQueryKernelTimestampCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Event.pfnQueryKernelTimestamp,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phEvent,
                                                  *tracerParams.pdstptr);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeCommandListAppendQueryKernelTimestamps
    __zedlllocal ze_result_t ZE_APICALL
    zeCommandListAppendQueryKernelTimestamps(
        ze_command_list_handle_t hCommandList,          ///< [in] handle of the command list
        uint32_t numEvents,                             ///< [in] the number of timestamp events to query
        ze_event_handle_t* phEvents,                    ///< [in][range(0, numEvents)] handles of timestamp events to query
        void* dstptr,                                   ///< [in,out] pointer to memory where ::ze_kernel_timestamp_result_t will
                                                        ///< be written; must be size-aligned.
        const size_t* pOffsets,                         ///< [in][optional][range(0, numEvents)] offset, in bytes, to write
                                                        ///< results; address must be 4byte-aligned and offsets must be
                                                        ///< size-aligned.
        ze_event_handle_t hSignalEvent,                 ///< [in][optional] handle of the event to signal on completion
        uint32_t numWaitEvents,                         ///< [in][optional] number of events to wait on before executing query;
                                                        ///< must be 0 if `nullptr == phWaitEvents`
        ze_event_handle_t* phWaitEvents                 ///< [in][optional][range(0, numWaitEvents)] handle of the events to wait
                                                        ///< on before executing query
        )
    {
        if( nullptr == context.zeDdiTable.CommandList.pfnAppendQueryKernelTimestamps)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.CommandList.pfnAppendQueryKernelTimestamps, hCommandList, numEvents, phEvents, dstptr, pOffsets, hSignalEvent, numWaitEvents, phWaitEvents);

        // capture parameters
        ze_command_list_append_query_kernel_timestamps_params_t tracerParams = {
            &hCommandList,
            &numEvents,
            &phEvents,
            &dstptr,
            &pOffsets,
            &hSignalEvent,
            &numWaitEvents,
            &phWaitEvents
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnCommandListAppendQueryKernelTimestampsCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnCommandListAppendQueryKernelTimestampsCb_t, CommandList, pfnAppendQueryKernelTimestampsCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.CommandList.pfnAppendQueryKernelTimestamps,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phCommandList,
                                                  *tracerParams.pnumEvents,
                                                  *tracerParams.pphEvents,
                                                  *tracerParams.pdstptr,
                                                  *tracerParams.ppOffsets,
                                                  *tracerParams.phSignalEvent,
                                                  *tracerParams.pnumWaitEvents,
                                                  *tracerParams.pphWaitEvents);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeFenceCreate
    __zedlllocal ze_result_t ZE_APICALL
    zeFenceCreate(
        ze_command_queue_handle_t hCommandQueue,        ///< [in] handle of command queue
        const ze_fence_desc_t* desc,                    ///< [in] pointer to fence descriptor
        ze_fence_handle_t* phFence                      ///< [out] pointer to handle of fence object created
        )
    {
        if( nullptr == context.zeDdiTable.Fence.pfnCreate)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Fence.pfnCreate, hCommandQueue, desc, phFence);

        // capture parameters
        ze_fence_create_params_t tracerParams = {
            &hCommandQueue,
            &desc,
            &phFence
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnFenceCreateCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnFenceCreateCb_t, Fence, pfnCreateCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Fence.pfnCreate,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phCommandQueue,
                                                  *tracerParams.pdesc,
                                                  *tracerParams.pphFence);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeFenceDestroy
    __zedlllocal ze_result_t ZE_APICALL
    zeFenceDestroy(
        ze_fence_handle_t hFence                        ///< [in][release] handle of fence object to destroy
        )
    {
        if( nullptr == context.zeDdiTable.Fence.pfnDestroy)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Fence.pfnDestroy, hFence);

        // capture parameters
        ze_fence_destroy_params_t tracerParams = {
            &hFence
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnFenceDestroyCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnFenceDestroyCb_t, Fence, pfnDestroyCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Fence.pfnDestroy,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phFence);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeFenceHostSynchronize
    __zedlllocal ze_result_t ZE_APICALL
    zeFenceHostSynchronize(
        ze_fence_handle_t hFence,                       ///< [in] handle of the fence
        uint64_t timeout                                ///< [in] if non-zero, then indicates the maximum time (in nanoseconds) to
                                                        ///< yield before returning ::ZE_RESULT_SUCCESS or ::ZE_RESULT_NOT_READY;
                                                        ///< if zero, then operates exactly like ::zeFenceQueryStatus;
                                                        ///< if UINT64_MAX, then function will not return until complete or device
                                                        ///< is lost.
                                                        ///< Due to external dependencies, timeout may be rounded to the closest
                                                        ///< value allowed by the accuracy of those dependencies.
        )
    {
        if( nullptr == context.zeDdiTable.Fence.pfnHostSynchronize)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Fence.pfnHostSynchronize, hFence, timeout);

        // capture parameters
        ze_fence_host_synchronize_params_t tracerParams = {
            &hFence,
            &timeout
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnFenceHostSynchronizeCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnFenceHostSynchronizeCb_t, Fence, pfnHostSynchronizeCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Fence.pfnHostSynchronize,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phFence,
                                                  *tracerParams.ptimeout);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeFenceQueryStatus
    __zedlllocal ze_result_t ZE_APICALL
    zeFenceQueryStatus(
        ze_fence_handle_t hFence                        ///< [in] handle of the fence
        )
    {
        if( nullptr == context.zeDdiTable.Fence.pfnQueryStatus)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Fence.pfnQueryStatus, hFence);

        // capture parameters
        ze_fence_query_status_params_t tracerParams = {
            &hFence
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnFenceQueryStatusCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnFenceQueryStatusCb_t, Fence, pfnQueryStatusCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Fence.pfnQueryStatus,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phFence);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeFenceReset
    __zedlllocal ze_result_t ZE_APICALL
    zeFenceReset(
        ze_fence_handle_t hFence                        ///< [in] handle of the fence
        )
    {
        if( nullptr == context.zeDdiTable.Fence.pfnReset)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Fence.pfnReset, hFence);

        // capture parameters
        ze_fence_reset_params_t tracerParams = {
            &hFence
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnFenceResetCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnFenceResetCb_t, Fence, pfnResetCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Fence.pfnReset,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phFence);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeImageGetProperties
    __zedlllocal ze_result_t ZE_APICALL
    zeImageGetProperties(
        ze_device_handle_t hDevice,                     ///< [in] handle of the device
        const ze_image_desc_t* desc,                    ///< [in] pointer to image descriptor
        ze_image_properties_t* pImageProperties         ///< [out] pointer to image properties
        )
    {
        if( nullptr == context.zeDdiTable.Image.pfnGetProperties)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Image.pfnGetProperties, hDevice, desc, pImageProperties);

        // capture parameters
        ze_image_get_properties_params_t tracerParams = {
            &hDevice,
            &desc,
            &pImageProperties
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnImageGetPropertiesCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnImageGetPropertiesCb_t, Image, pfnGetPropertiesCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Image.pfnGetProperties,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phDevice,
                                                  *tracerParams.pdesc,
                                                  *tracerParams.ppImageProperties);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeImageCreate
    __zedlllocal ze_result_t ZE_APICALL
    zeImageCreate(
        ze_context_handle_t hContext,                   ///< [in] handle of the context object
        ze_device_handle_t hDevice,                     ///< [in] handle of the device
        const ze_image_desc_t* desc,                    ///< [in] pointer to image descriptor
        ze_image_handle_t* phImage                      ///< [out] pointer to handle of image object created
        )
    {
        if( nullptr == context.zeDdiTable.Image.pfnCreate)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Image.pfnCreate, hContext, hDevice, desc, phImage);

        // capture parameters
        ze_image_create_params_t tracerParams = {
            &hContext,
            &hDevice,
            &desc,
            &phImage
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnImageCreateCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnImageCreateCb_t, Image, pfnCreateCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Image.pfnCreate,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext,
                                                  *tracerParams.phDevice,
                                                  *tracerParams.pdesc,
                                                  *tracerParams.pphImage);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeImageDestroy
    __zedlllocal ze_result_t ZE_APICALL
    zeImageDestroy(
        ze_image_handle_t hImage                        ///< [in][release] handle of image object to destroy
        )
    {
        if( nullptr == context.zeDdiTable.Image.pfnDestroy)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Image.pfnDestroy, hImage);

        // capture parameters
        ze_image_destroy_params_t tracerParams = {
            &hImage
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnImageDestroyCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnImageDestroyCb_t, Image, pfnDestroyCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Image.pfnDestroy,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phImage);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeMemAllocShared
    __zedlllocal ze_result_t ZE_APICALL
    zeMemAllocShared(
        ze_context_handle_t hContext,                   ///< [in] handle of the context object
        const ze_device_mem_alloc_desc_t* device_desc,  ///< [in] pointer to device memory allocation descriptor
        const ze_host_mem_alloc_desc_t* host_desc,      ///< [in] pointer to host memory allocation descriptor
        size_t size,                                    ///< [in] size in bytes to allocate; must be less-than
                                                        ///< ::ze_device_properties_t.maxMemAllocSize.
        size_t alignment,                               ///< [in] minimum alignment in bytes for the allocation; must be a power of
                                                        ///< two.
        ze_device_handle_t hDevice,                     ///< [in][optional] device handle to associate with
        void** pptr                                     ///< [out] pointer to shared allocation
        )
    {
        if( nullptr == context.zeDdiTable.Mem.pfnAllocShared)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Mem.pfnAllocShared, hContext, device_desc, host_desc, size, alignment, hDevice, pptr);

        // capture parameters
        ze_mem_alloc_shared_params_t tracerParams = {
            &hContext,
            &device_desc,
            &host_desc,
            &size,
            &alignment,
            &hDevice,
            &pptr
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnMemAllocSharedCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnMemAllocSharedCb_t, Mem, pfnAllocSharedCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Mem.pfnAllocShared,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext,
                                                  *tracerParams.pdevice_desc,
                                                  *tracerParams.phost_desc,
                                                  *tracerParams.psize,
                                                  *tracerParams.palignment,
                                                  *tracerParams.phDevice,
                                                  *tracerParams.ppptr);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeMemAllocDevice
    __zedlllocal ze_result_t ZE_APICALL
    zeMemAllocDevice(
        ze_context_handle_t hContext,                   ///< [in] handle of the context object
        const ze_device_mem_alloc_desc_t* device_desc,  ///< [in] pointer to device memory allocation descriptor
        size_t size,                                    ///< [in] size in bytes to allocate; must be less-than
                                                        ///< ::ze_device_properties_t.maxMemAllocSize.
        size_t alignment,                               ///< [in] minimum alignment in bytes for the allocation; must be a power of
                                                        ///< two.
        ze_device_handle_t hDevice,                     ///< [in] handle of the device
        void** pptr                                     ///< [out] pointer to device allocation
        )
    {
        if( nullptr == context.zeDdiTable.Mem.pfnAllocDevice)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Mem.pfnAllocDevice, hContext, device_desc, size, alignment, hDevice, pptr);

        // capture parameters
        ze_mem_alloc_device_params_t tracerParams = {
            &hContext,
            &device_desc,
            &size,
            &alignment,
            &hDevice,
            &pptr
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnMemAllocDeviceCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnMemAllocDeviceCb_t, Mem, pfnAllocDeviceCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Mem.pfnAllocDevice,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext,
                                                  *tracerParams.pdevice_desc,
                                                  *tracerParams.psize,
                                                  *tracerParams.palignment,
                                                  *tracerParams.phDevice,
                                                  *tracerParams.ppptr);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeMemAllocHost
    __zedlllocal ze_result_t ZE_APICALL
    zeMemAllocHost(
        ze_context_handle_t hContext,                   ///< [in] handle of the context object
        const ze_host_mem_alloc_desc_t* host_desc,      ///< [in] pointer to host memory allocation descriptor
        size_t size,                                    ///< [in] size in bytes to allocate; must be less-than
                                                        ///< ::ze_device_properties_t.maxMemAllocSize.
        size_t alignment,                               ///< [in] minimum alignment in bytes for the allocation; must be a power of
                                                        ///< two.
        void** pptr                                     ///< [out] pointer to host allocation
        )
    {
        if( nullptr == context.zeDdiTable.Mem.pfnAllocHost)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Mem.pfnAllocHost, hContext, host_desc, size, alignment, pptr);

        // capture parameters
        ze_mem_alloc_host_params_t tracerParams = {
            &hContext,
            &host_desc,
            &size,
            &alignment,
            &pptr
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnMemAllocHostCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnMemAllocHostCb_t, Mem, pfnAllocHostCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Mem.pfnAllocHost,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext,
                                                  *tracerParams.phost_desc,
                                                  *tracerParams.psize,
                                                  *tracerParams.palignment,
                                                  *tracerParams.ppptr);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeMemFree
    __zedlllocal ze_result_t ZE_APICALL
    zeMemFree(
        ze_context_handle_t hContext,                   ///< [in] handle of the context object
        void* ptr                                       ///< [in][release] pointer to memory to free
        )
    {
        if( nullptr == context.zeDdiTable.Mem.pfnFree)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Mem.pfnFree, hContext, ptr);

        // capture parameters
        ze_mem_free_params_t tracerParams = {
            &hContext,
            &ptr
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnMemFreeCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnMemFreeCb_t, Mem, pfnFreeCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Mem.pfnFree,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext,
                                                  *tracerParams.pptr);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeMemGetAllocProperties
    __zedlllocal ze_result_t ZE_APICALL
    zeMemGetAllocProperties(
        ze_context_handle_t hContext,                   ///< [in] handle of the context object
        const void* ptr,                                ///< [in] memory pointer to query
        ze_memory_allocation_properties_t* pMemAllocProperties, ///< [in,out] query result for memory allocation properties
        ze_device_handle_t* phDevice                    ///< [out][optional] device associated with this allocation
        )
    {
        if( nullptr == context.zeDdiTable.Mem.pfnGetAllocProperties)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Mem.pfnGetAllocProperties, hContext, ptr, pMemAllocProperties, phDevice);

        // capture parameters
        ze_mem_get_alloc_properties_params_t tracerParams = {
            &hContext,
            &ptr,
            &pMemAllocProperties,
            &phDevice
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnMemGetAllocPropertiesCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnMemGetAllocPropertiesCb_t, Mem, pfnGetAllocPropertiesCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Mem.pfnGetAllocProperties,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext,
                                                  *tracerParams.pptr,
                                                  *tracerParams.ppMemAllocProperties,
                                                  *tracerParams.pphDevice);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeMemGetAddressRange
    __zedlllocal ze_result_t ZE_APICALL
    zeMemGetAddressRange(
        ze_context_handle_t hContext,                   ///< [in] handle of the context object
        const void* ptr,                                ///< [in] memory pointer to query
        void** pBase,                                   ///< [in,out][optional] base address of the allocation
        size_t* pSize                                   ///< [in,out][optional] size of the allocation
        )
    {
        if( nullptr == context.zeDdiTable.Mem.pfnGetAddressRange)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Mem.pfnGetAddressRange, hContext, ptr, pBase, pSize);

        // capture parameters
        ze_mem_get_address_range_params_t tracerParams = {
            &hContext,
            &ptr,
            &pBase,
            &pSize
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnMemGetAddressRangeCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnMemGetAddressRangeCb_t, Mem, pfnGetAddressRangeCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Mem.pfnGetAddressRange,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext,
                                                  *tracerParams.pptr,
                                                  *tracerParams.ppBase,
                                                  *tracerParams.ppSize);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeMemGetIpcHandle
    __zedlllocal ze_result_t ZE_APICALL
    zeMemGetIpcHandle(
        ze_context_handle_t hContext,                   ///< [in] handle of the context object
        const void* ptr,                                ///< [in] pointer to the device memory allocation
        ze_ipc_mem_handle_t* pIpcHandle                 ///< [out] Returned IPC memory handle
        )
    {
        if( nullptr == context.zeDdiTable.Mem.pfnGetIpcHandle)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Mem.pfnGetIpcHandle, hContext, ptr, pIpcHandle);

        // capture parameters
        ze_mem_get_ipc_handle_params_t tracerParams = {
            &hContext,
            &ptr,
            &pIpcHandle
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnMemGetIpcHandleCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnMemGetIpcHandleCb_t, Mem, pfnGetIpcHandleCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Mem.pfnGetIpcHandle,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext,
                                                  *tracerParams.pptr,
                                                  *tracerParams.ppIpcHandle);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeMemOpenIpcHandle
    __zedlllocal ze_result_t ZE_APICALL
    zeMemOpenIpcHandle(
        ze_context_handle_t hContext,                   ///< [in] handle of the context object
        ze_device_handle_t hDevice,                     ///< [in] handle of the device to associate with the IPC memory handle
        ze_ipc_mem_handle_t handle,                     ///< [in] IPC memory handle
        ze_ipc_memory_flags_t flags,                    ///< [in] flags controlling the operation.
                                                        ///< must be 0 (default) or a valid combination of ::ze_ipc_memory_flag_t.
        void** pptr                                     ///< [out] pointer to device allocation in this process
        )
    {
        if( nullptr == context.zeDdiTable.Mem.pfnOpenIpcHandle)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Mem.pfnOpenIpcHandle, hContext, hDevice, handle, flags, pptr);

        // capture parameters
        ze_mem_open_ipc_handle_params_t tracerParams = {
            &hContext,
            &hDevice,
            &handle,
            &flags,
            &pptr
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnMemOpenIpcHandleCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnMemOpenIpcHandleCb_t, Mem, pfnOpenIpcHandleCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Mem.pfnOpenIpcHandle,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext,
                                                  *tracerParams.phDevice,
                                                  *tracerParams.phandle,
                                                  *tracerParams.pflags,
                                                  *tracerParams.ppptr);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeMemCloseIpcHandle
    __zedlllocal ze_result_t ZE_APICALL
    zeMemCloseIpcHandle(
        ze_context_handle_t hContext,                   ///< [in] handle of the context object
        const void* ptr                                 ///< [in][release] pointer to device allocation in this process
        )
    {
        if( nullptr == context.zeDdiTable.Mem.pfnCloseIpcHandle)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Mem.pfnCloseIpcHandle, hContext, ptr);

        // capture parameters
        ze_mem_close_ipc_handle_params_t tracerParams = {
            &hContext,
            &ptr
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnMemCloseIpcHandleCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnMemCloseIpcHandleCb_t, Mem, pfnCloseIpcHandleCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Mem.pfnCloseIpcHandle,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext,
                                                  *tracerParams.pptr);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeModuleCreate
    __zedlllocal ze_result_t ZE_APICALL
    zeModuleCreate(
        ze_context_handle_t hContext,                   ///< [in] handle of the context object
        ze_device_handle_t hDevice,                     ///< [in] handle of the device
        const ze_module_desc_t* desc,                   ///< [in] pointer to module descriptor
        ze_module_handle_t* phModule,                   ///< [out] pointer to handle of module object created
        ze_module_build_log_handle_t* phBuildLog        ///< [out][optional] pointer to handle of module's build log.
        )
    {
        if( nullptr == context.zeDdiTable.Module.pfnCreate)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Module.pfnCreate, hContext, hDevice, desc, phModule, phBuildLog);

        // capture parameters
        ze_module_create_params_t tracerParams = {
            &hContext,
            &hDevice,
            &desc,
            &phModule,
            &phBuildLog
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnModuleCreateCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnModuleCreateCb_t, Module, pfnCreateCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Module.pfnCreate,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext,
                                                  *tracerParams.phDevice,
                                                  *tracerParams.pdesc,
                                                  *tracerParams.pphModule,
                                                  *tracerParams.pphBuildLog);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeModuleDestroy
    __zedlllocal ze_result_t ZE_APICALL
    zeModuleDestroy(
        ze_module_handle_t hModule                      ///< [in][release] handle of the module
        )
    {
        if( nullptr == context.zeDdiTable.Module.pfnDestroy)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Module.pfnDestroy, hModule);

        // capture parameters
        ze_module_destroy_params_t tracerParams = {
            &hModule
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnModuleDestroyCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnModuleDestroyCb_t, Module, pfnDestroyCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Module.pfnDestroy,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phModule);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeModuleDynamicLink
    __zedlllocal ze_result_t ZE_APICALL
    zeModuleDynamicLink(
        uint32_t numModules,                            ///< [in] number of modules to be linked pointed to by phModules.
        ze_module_handle_t* phModules,                  ///< [in][range(0, numModules)] pointer to an array of modules to
                                                        ///< dynamically link together.
        ze_module_build_log_handle_t* phLinkLog         ///< [out][optional] pointer to handle of dynamic link log.
        )
    {
        if( nullptr == context.zeDdiTable.Module.pfnDynamicLink)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Module.pfnDynamicLink, numModules, phModules, phLinkLog);

        // capture parameters
        ze_module_dynamic_link_params_t tracerParams = {
            &numModules,
            &phModules,
            &phLinkLog
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnModuleDynamicLinkCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnModuleDynamicLinkCb_t, Module, pfnDynamicLinkCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Module.pfnDynamicLink,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.pnumModules,
                                                  *tracerParams.pphModules,
                                                  *tracerParams.pphLinkLog);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeModuleBuildLogDestroy
    __zedlllocal ze_result_t ZE_APICALL
    zeModuleBuildLogDestroy(
        ze_module_build_log_handle_t hModuleBuildLog    ///< [in][release] handle of the module build log object.
        )
    {
        if( nullptr == context.zeDdiTable.ModuleBuildLog.pfnDestroy)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.ModuleBuildLog.pfnDestroy, hModuleBuildLog);

        // capture parameters
        ze_module_build_log_destroy_params_t tracerParams = {
            &hModuleBuildLog
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnModuleBuildLogDestroyCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnModuleBuildLogDestroyCb_t, ModuleBuildLog, pfnDestroyCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.ModuleBuildLog.pfnDestroy,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phModuleBuildLog);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeModuleBuildLogGetString
    __zedlllocal ze_result_t ZE_APICALL
    zeModuleBuildLogGetString(
        ze_module_build_log_handle_t hModuleBuildLog,   ///< [in] handle of the module build log object.
        size_t* pSize,                                  ///< [in,out] size of build log string.
        char* pBuildLog                                 ///< [in,out][optional] pointer to null-terminated string of the log.
        )
    {
        if( nullptr == context.zeDdiTable.ModuleBuildLog.pfnGetString)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.ModuleBuildLog.pfnGetString, hModuleBuildLog, pSize, pBuildLog);

        // capture parameters
        ze_module_build_log_get_string_params_t tracerParams = {
            &hModuleBuildLog,
            &pSize,
            &pBuildLog
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnModuleBuildLogGetStringCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnModuleBuildLogGetStringCb_t, ModuleBuildLog, pfnGetStringCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.ModuleBuildLog.pfnGetString,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phModuleBuildLog,
                                                  *tracerParams.ppSize,
                                                  *tracerParams.ppBuildLog);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeModuleGetNativeBinary
    __zedlllocal ze_result_t ZE_APICALL
    zeModuleGetNativeBinary(
        ze_module_handle_t hModule,                     ///< [in] handle of the module
        size_t* pSize,                                  ///< [in,out] size of native binary in bytes.
        uint8_t* pModuleNativeBinary                    ///< [in,out][optional] byte pointer to native binary
        )
    {
        if( nullptr == context.zeDdiTable.Module.pfnGetNativeBinary)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Module.pfnGetNativeBinary, hModule, pSize, pModuleNativeBinary);

        // capture parameters
        ze_module_get_native_binary_params_t tracerParams = {
            &hModule,
            &pSize,
            &pModuleNativeBinary
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnModuleGetNativeBinaryCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnModuleGetNativeBinaryCb_t, Module, pfnGetNativeBinaryCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Module.pfnGetNativeBinary,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phModule,
                                                  *tracerParams.ppSize,
                                                  *tracerParams.ppModuleNativeBinary);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeModuleGetGlobalPointer
    __zedlllocal ze_result_t ZE_APICALL
    zeModuleGetGlobalPointer(
        ze_module_handle_t hModule,                     ///< [in] handle of the module
        const char* pGlobalName,                        ///< [in] name of global variable in module
        size_t* pSize,                                  ///< [in,out][optional] size of global variable
        void** pptr                                     ///< [in,out][optional] device visible pointer
        )
    {
        if( nullptr == context.zeDdiTable.Module.pfnGetGlobalPointer)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Module.pfnGetGlobalPointer, hModule, pGlobalName, pSize, pptr);

        // capture parameters
        ze_module_get_global_pointer_params_t tracerParams = {
            &hModule,
            &pGlobalName,
            &pSize,
            &pptr
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnModuleGetGlobalPointerCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnModuleGetGlobalPointerCb_t, Module, pfnGetGlobalPointerCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Module.pfnGetGlobalPointer,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phModule,
                                                  *tracerParams.ppGlobalName,
                                                  *tracerParams.ppSize,
                                                  *tracerParams.ppptr);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeModuleGetKernelNames
    __zedlllocal ze_result_t ZE_APICALL
    zeModuleGetKernelNames(
        ze_module_handle_t hModule,                     ///< [in] handle of the module
        uint32_t* pCount,                               ///< [in,out] pointer to the number of names.
                                                        ///< if count is zero, then the driver will update the value with the total
                                                        ///< number of names available.
                                                        ///< if count is non-zero, then driver will only retrieve that number of names.
                                                        ///< if count is larger than the number of names available, then the driver
                                                        ///< will update the value with the correct number of names available.
        const char** pNames                             ///< [in,out][optional][range(0, *pCount)] array of names of functions
        )
    {
        if( nullptr == context.zeDdiTable.Module.pfnGetKernelNames)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Module.pfnGetKernelNames, hModule, pCount, pNames);

        // capture parameters
        ze_module_get_kernel_names_params_t tracerParams = {
            &hModule,
            &pCount,
            &pNames
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnModuleGetKernelNamesCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnModuleGetKernelNamesCb_t, Module, pfnGetKernelNamesCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Module.pfnGetKernelNames,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phModule,
                                                  *tracerParams.ppCount,
                                                  *tracerParams.ppNames);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeModuleGetProperties
    __zedlllocal ze_result_t ZE_APICALL
    zeModuleGetProperties(
        ze_module_handle_t hModule,                     ///< [in] handle of the module
        ze_module_properties_t* pModuleProperties       ///< [in,out] query result for module properties.
        )
    {
        if( nullptr == context.zeDdiTable.Module.pfnGetProperties)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Module.pfnGetProperties, hModule, pModuleProperties);

        // capture parameters
        ze_module_get_properties_params_t tracerParams = {
            &hModule,
            &pModuleProperties
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnModuleGetPropertiesCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnModuleGetPropertiesCb_t, Module, pfnGetPropertiesCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Module.pfnGetProperties,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phModule,
                                                  *tracerParams.ppModuleProperties);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeKernelCreate
    __zedlllocal ze_result_t ZE_APICALL
    zeKernelCreate(
        ze_module_handle_t hModule,                     ///< [in] handle of the module
        const ze_kernel_desc_t* desc,                   ///< [in] pointer to kernel descriptor
        ze_kernel_handle_t* phKernel                    ///< [out] handle of the Function object
        )
    {
        if( nullptr == context.zeDdiTable.Kernel.pfnCreate)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Kernel.pfnCreate, hModule, desc, phKernel);

        // capture parameters
        ze_kernel_create_params_t tracerParams = {
            &hModule,
            &desc,
            &phKernel
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnKernelCreateCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnKernelCreateCb_t, Kernel, pfnCreateCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Kernel.pfnCreate,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phModule,
                                                  *tracerParams.pdesc,
                                                  *tracerParams.pphKernel);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeKernelDestroy
    __zedlllocal ze_result_t ZE_APICALL
    zeKernelDestroy(
        ze_kernel_handle_t hKernel                      ///< [in][release] handle of the kernel object
        )
    {
        if( nullptr == context.zeDdiTable.Kernel.pfnDestroy)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Kernel.pfnDestroy, hKernel);

        // capture parameters
        ze_kernel_destroy_params_t tracerParams = {
            &hKernel
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnKernelDestroyCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnKernelDestroyCb_t, Kernel, pfnDestroyCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Kernel.pfnDestroy,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phKernel);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeModuleGetFunctionPointer
    __zedlllocal ze_result_t ZE_APICALL
    zeModuleGetFunctionPointer(
        ze_module_handle_t hModule,                     ///< [in] handle of the module
        const char* pFunctionName,                      ///< [in] Name of function to retrieve function pointer for.
        void** pfnFunction                              ///< [out] pointer to function.
        )
    {
        if( nullptr == context.zeDdiTable.Module.pfnGetFunctionPointer)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Module.pfnGetFunctionPointer, hModule, pFunctionName, pfnFunction);

        // capture parameters
        ze_module_get_function_pointer_params_t tracerParams = {
            &hModule,
            &pFunctionName,
            &pfnFunction
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnModuleGetFunctionPointerCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnModuleGetFunctionPointerCb_t, Module, pfnGetFunctionPointerCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Module.pfnGetFunctionPointer,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phModule,
                                                  *tracerParams.ppFunctionName,
                                                  *tracerParams.ppfnFunction);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeKernelSetGroupSize
    __zedlllocal ze_result_t ZE_APICALL
    zeKernelSetGroupSize(
        ze_kernel_handle_t hKernel,                     ///< [in] handle of the kernel object
        uint32_t groupSizeX,                            ///< [in] group size for X dimension to use for this kernel
        uint32_t groupSizeY,                            ///< [in] group size for Y dimension to use for this kernel
        uint32_t groupSizeZ                             ///< [in] group size for Z dimension to use for this kernel
        )
    {
        if( nullptr == context.zeDdiTable.Kernel.pfnSetGroupSize)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Kernel.pfnSetGroupSize, hKernel, groupSizeX, groupSizeY, groupSizeZ);

        // capture parameters
        ze_kernel_set_group_size_params_t tracerParams = {
            &hKernel,
            &groupSizeX,
            &groupSizeY,
            &groupSizeZ
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnKernelSetGroupSizeCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnKernelSetGroupSizeCb_t, Kernel, pfnSetGroupSizeCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Kernel.pfnSetGroupSize,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phKernel,
                                                  *tracerParams.pgroupSizeX,
                                                  *tracerParams.pgroupSizeY,
                                                  *tracerParams.pgroupSizeZ);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeKernelSuggestGroupSize
    __zedlllocal ze_result_t ZE_APICALL
    zeKernelSuggestGroupSize(
        ze_kernel_handle_t hKernel,                     ///< [in] handle of the kernel object
        uint32_t globalSizeX,                           ///< [in] global width for X dimension
        uint32_t globalSizeY,                           ///< [in] global width for Y dimension
        uint32_t globalSizeZ,                           ///< [in] global width for Z dimension
        uint32_t* groupSizeX,                           ///< [out] recommended size of group for X dimension
        uint32_t* groupSizeY,                           ///< [out] recommended size of group for Y dimension
        uint32_t* groupSizeZ                            ///< [out] recommended size of group for Z dimension
        )
    {
        if( nullptr == context.zeDdiTable.Kernel.pfnSuggestGroupSize)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Kernel.pfnSuggestGroupSize, hKernel, globalSizeX, globalSizeY, globalSizeZ, groupSizeX, groupSizeY, groupSizeZ);

        // capture parameters
        ze_kernel_suggest_group_size_params_t tracerParams = {
            &hKernel,
            &globalSizeX,
            &globalSizeY,
            &globalSizeZ,
            &groupSizeX,
            &groupSizeY,
            &groupSizeZ
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnKernelSuggestGroupSizeCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnKernelSuggestGroupSizeCb_t, Kernel, pfnSuggestGroupSizeCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Kernel.pfnSuggestGroupSize,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phKernel,
                                                  *tracerParams.pglobalSizeX,
                                                  *tracerParams.pglobalSizeY,
                                                  *tracerParams.pglobalSizeZ,
                                                  *tracerParams.pgroupSizeX,
                                                  *tracerParams.pgroupSizeY,
                                                  *tracerParams.pgroupSizeZ);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeKernelSuggestMaxCooperativeGroupCount
    __zedlllocal ze_result_t ZE_APICALL
    zeKernelSuggestMaxCooperativeGroupCount(
        ze_kernel_handle_t hKernel,                     ///< [in] handle of the kernel object
        uint32_t* totalGroupCount                       ///< [out] recommended total group count.
        )
    {
        if( nullptr == context.zeDdiTable.Kernel.pfnSuggestMaxCooperativeGroupCount)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Kernel.pfnSuggestMaxCooperativeGroupCount, hKernel, totalGroupCount);

        // capture parameters
        ze_kernel_suggest_max_cooperative_group_count_params_t tracerParams = {
            &hKernel,
            &totalGroupCount
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnKernelSuggestMaxCooperativeGroupCountCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnKernelSuggestMaxCooperativeGroupCountCb_t, Kernel, pfnSuggestMaxCooperativeGroupCountCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Kernel.pfnSuggestMaxCooperativeGroupCount,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phKernel,
                                                  *tracerParams.ptotalGroupCount);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeKernelSetArgumentValue
    __zedlllocal ze_result_t ZE_APICALL
    zeKernelSetArgumentValue(
        ze_kernel_handle_t hKernel,                     ///< [in] handle of the kernel object
        uint32_t argIndex,                              ///< [in] argument index in range [0, num args - 1]
        size_t argSize,                                 ///< [in] size of argument type
        const void* pArgValue                           ///< [in][optional] argument value represented as matching arg type. If
                                                        ///< null then argument value is considered null.
        )
    {
        if( nullptr == context.zeDdiTable.Kernel.pfnSetArgumentValue)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Kernel.pfnSetArgumentValue, hKernel, argIndex, argSize, pArgValue);

        // capture parameters
        ze_kernel_set_argument_value_params_t tracerParams = {
            &hKernel,
            &argIndex,
            &argSize,
            &pArgValue
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnKernelSetArgumentValueCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnKernelSetArgumentValueCb_t, Kernel, pfnSetArgumentValueCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Kernel.pfnSetArgumentValue,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phKernel,
                                                  *tracerParams.pargIndex,
                                                  *tracerParams.pargSize,
                                                  *tracerParams.ppArgValue);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeKernelSetIndirectAccess
    __zedlllocal ze_result_t ZE_APICALL
    zeKernelSetIndirectAccess(
        ze_kernel_handle_t hKernel,                     ///< [in] handle of the kernel object
        ze_kernel_indirect_access_flags_t flags         ///< [in] kernel indirect access flags
        )
    {
        if( nullptr == context.zeDdiTable.Kernel.pfnSetIndirectAccess)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Kernel.pfnSetIndirectAccess, hKernel, flags);

        // capture parameters
        ze_kernel_set_indirect_access_params_t tracerParams = {
            &hKernel,
            &flags
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnKernelSetIndirectAccessCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnKernelSetIndirectAccessCb_t, Kernel, pfnSetIndirectAccessCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Kernel.pfnSetIndirectAccess,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phKernel,
                                                  *tracerParams.pflags);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeKernelGetIndirectAccess
    __zedlllocal ze_result_t ZE_APICALL
    zeKernelGetIndirectAccess(
        ze_kernel_handle_t hKernel,                     ///< [in] handle of the kernel object
        ze_kernel_indirect_access_flags_t* pFlags       ///< [out] query result for kernel indirect access flags.
        )
    {
        if( nullptr == context.zeDdiTable.Kernel.pfnGetIndirectAccess)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Kernel.pfnGetIndirectAccess, hKernel, pFlags);

        // capture parameters
        ze_kernel_get_indirect_access_params_t tracerParams = {
            &hKernel,
            &pFlags
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnKernelGetIndirectAccessCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnKernelGetIndirectAccessCb_t, Kernel, pfnGetIndirectAccessCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Kernel.pfnGetIndirectAccess,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phKernel,
                                                  *tracerParams.ppFlags);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeKernelGetSourceAttributes
    __zedlllocal ze_result_t ZE_APICALL
    zeKernelGetSourceAttributes(
        ze_kernel_handle_t hKernel,                     ///< [in] handle of the kernel object
        uint32_t* pSize,                                ///< [in,out] pointer to size of string in bytes.
                                                        ///< if size is zero, then the driver will update string argument.
                                                        ///< if size is non-zero, then driver will only retrieve string size in bytes.
                                                        ///< if size is larger than source attributes string, then the driver will
                                                        ///< update the string.
        char** pString                                  ///< [in,out][optional] pointer to null-terminated string where kernel
                                                        ///< source attributes are separated by space.
        )
    {
        if( nullptr == context.zeDdiTable.Kernel.pfnGetSourceAttributes)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Kernel.pfnGetSourceAttributes, hKernel, pSize, pString);

        // capture parameters
        ze_kernel_get_source_attributes_params_t tracerParams = {
            &hKernel,
            &pSize,
            &pString
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnKernelGetSourceAttributesCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnKernelGetSourceAttributesCb_t, Kernel, pfnGetSourceAttributesCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Kernel.pfnGetSourceAttributes,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phKernel,
                                                  *tracerParams.ppSize,
                                                  *tracerParams.ppString);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeKernelSetCacheConfig
    __zedlllocal ze_result_t ZE_APICALL
    zeKernelSetCacheConfig(
        ze_kernel_handle_t hKernel,                     ///< [in] handle of the kernel object
        ze_cache_config_flags_t flags                   ///< [in] cache configuration. 
                                                        ///< must be 0 (default configuration) or a valid combination of ::ze_cache_config_flag_t.
        )
    {
        if( nullptr == context.zeDdiTable.Kernel.pfnSetCacheConfig)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Kernel.pfnSetCacheConfig, hKernel, flags);

        // capture parameters
        ze_kernel_set_cache_config_params_t tracerParams = {
            &hKernel,
            &flags
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnKernelSetCacheConfigCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnKernelSetCacheConfigCb_t, Kernel, pfnSetCacheConfigCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Kernel.pfnSetCacheConfig,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phKernel,
                                                  *tracerParams.pflags);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeKernelGetProperties
    __zedlllocal ze_result_t ZE_APICALL
    zeKernelGetProperties(
        ze_kernel_handle_t hKernel,                     ///< [in] handle of the kernel object
        ze_kernel_properties_t* pKernelProperties       ///< [in,out] query result for kernel properties.
        )
    {
        if( nullptr == context.zeDdiTable.Kernel.pfnGetProperties)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Kernel.pfnGetProperties, hKernel, pKernelProperties);

        // capture parameters
        ze_kernel_get_properties_params_t tracerParams = {
            &hKernel,
            &pKernelProperties
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnKernelGetPropertiesCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnKernelGetPropertiesCb_t, Kernel, pfnGetPropertiesCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Kernel.pfnGetProperties,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phKernel,
                                                  *tracerParams.ppKernelProperties);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeKernelGetName
    __zedlllocal ze_result_t ZE_APICALL
    zeKernelGetName(
        ze_kernel_handle_t hKernel,                     ///< [in] handle of the kernel object
        size_t* pSize,                                  ///< [in,out] size of kernel name string, including null terminator, in
                                                        ///< bytes.
        char* pName                                     ///< [in,out][optional] char pointer to kernel name.
        )
    {
        if( nullptr == context.zeDdiTable.Kernel.pfnGetName)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Kernel.pfnGetName, hKernel, pSize, pName);

        // capture parameters
        ze_kernel_get_name_params_t tracerParams = {
            &hKernel,
            &pSize,
            &pName
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnKernelGetNameCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnKernelGetNameCb_t, Kernel, pfnGetNameCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Kernel.pfnGetName,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phKernel,
                                                  *tracerParams.ppSize,
                                                  *tracerParams.ppName);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeCommandListAppendLaunchKernel
    __zedlllocal ze_result_t ZE_APICALL
    zeCommandListAppendLaunchKernel(
        ze_command_list_handle_t hCommandList,          ///< [in] handle of the command list
        ze_kernel_handle_t hKernel,                     ///< [in] handle of the kernel object
        const ze_group_count_t* pLaunchFuncArgs,        ///< [in] thread group launch arguments
        ze_event_handle_t hSignalEvent,                 ///< [in][optional] handle of the event to signal on completion
        uint32_t numWaitEvents,                         ///< [in][optional] number of events to wait on before launching; must be 0
                                                        ///< if `nullptr == phWaitEvents`
        ze_event_handle_t* phWaitEvents                 ///< [in][optional][range(0, numWaitEvents)] handle of the events to wait
                                                        ///< on before launching
        )
    {
        if( nullptr == context.zeDdiTable.CommandList.pfnAppendLaunchKernel)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.CommandList.pfnAppendLaunchKernel, hCommandList, hKernel, pLaunchFuncArgs, hSignalEvent, numWaitEvents, phWaitEvents);

        // capture parameters
        ze_command_list_append_launch_kernel_params_t tracerParams = {
            &hCommandList,
            &hKernel,
            &pLaunchFuncArgs,
            &hSignalEvent,
            &numWaitEvents,
            &phWaitEvents
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnCommandListAppendLaunchKernelCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnCommandListAppendLaunchKernelCb_t, CommandList, pfnAppendLaunchKernelCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.CommandList.pfnAppendLaunchKernel,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phCommandList,
                                                  *tracerParams.phKernel,
                                                  *tracerParams.ppLaunchFuncArgs,
                                                  *tracerParams.phSignalEvent,
                                                  *tracerParams.pnumWaitEvents,
                                                  *tracerParams.pphWaitEvents);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeCommandListAppendLaunchCooperativeKernel
    __zedlllocal ze_result_t ZE_APICALL
    zeCommandListAppendLaunchCooperativeKernel(
        ze_command_list_handle_t hCommandList,          ///< [in] handle of the command list
        ze_kernel_handle_t hKernel,                     ///< [in] handle of the kernel object
        const ze_group_count_t* pLaunchFuncArgs,        ///< [in] thread group launch arguments
        ze_event_handle_t hSignalEvent,                 ///< [in][optional] handle of the event to signal on completion
        uint32_t numWaitEvents,                         ///< [in][optional] number of events to wait on before launching; must be 0
                                                        ///< if `nullptr == phWaitEvents`
        ze_event_handle_t* phWaitEvents                 ///< [in][optional][range(0, numWaitEvents)] handle of the events to wait
                                                        ///< on before launching
        )
    {
        if( nullptr == context.zeDdiTable.CommandList.pfnAppendLaunchCooperativeKernel)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.CommandList.pfnAppendLaunchCooperativeKernel, hCommandList, hKernel, pLaunchFuncArgs, hSignalEvent, numWaitEvents, phWaitEvents);

        // capture parameters
        ze_command_list_append_launch_cooperative_kernel_params_t tracerParams = {
            &hCommandList,
            &hKernel,
            &pLaunchFuncArgs,
            &hSignalEvent,
            &numWaitEvents,
            &phWaitEvents
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnCommandListAppendLaunchCooperativeKernelCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnCommandListAppendLaunchCooperativeKernelCb_t, CommandList, pfnAppendLaunchCooperativeKernelCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.CommandList.pfnAppendLaunchCooperativeKernel,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phCommandList,
                                                  *tracerParams.phKernel,
                                                  *tracerParams.ppLaunchFuncArgs,
                                                  *tracerParams.phSignalEvent,
                                                  *tracerParams.pnumWaitEvents,
                                                  *tracerParams.pphWaitEvents);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeCommandListAppendLaunchKernelIndirect
    __zedlllocal ze_result_t ZE_APICALL
    zeCommandListAppendLaunchKernelIndirect(
        ze_command_list_handle_t hCommandList,          ///< [in] handle of the command list
        ze_kernel_handle_t hKernel,                     ///< [in] handle of the kernel object
        const ze_group_count_t* pLaunchArgumentsBuffer, ///< [in] pointer to device buffer that will contain thread group launch
                                                        ///< arguments
        ze_event_handle_t hSignalEvent,                 ///< [in][optional] handle of the event to signal on completion
        uint32_t numWaitEvents,                         ///< [in][optional] number of events to wait on before launching; must be 0
                                                        ///< if `nullptr == phWaitEvents`
        ze_event_handle_t* phWaitEvents                 ///< [in][optional][range(0, numWaitEvents)] handle of the events to wait
                                                        ///< on before launching
        )
    {
        if( nullptr == context.zeDdiTable.CommandList.pfnAppendLaunchKernelIndirect)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.CommandList.pfnAppendLaunchKernelIndirect, hCommandList, hKernel, pLaunchArgumentsBuffer, hSignalEvent, numWaitEvents, phWaitEvents);

        // capture parameters
        ze_command_list_append_launch_kernel_indirect_params_t tracerParams = {
            &hCommandList,
            &hKernel,
            &pLaunchArgumentsBuffer,
            &hSignalEvent,
            &numWaitEvents,
            &phWaitEvents
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnCommandListAppendLaunchKernelIndirectCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnCommandListAppendLaunchKernelIndirectCb_t, CommandList, pfnAppendLaunchKernelIndirectCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.CommandList.pfnAppendLaunchKernelIndirect,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phCommandList,
                                                  *tracerParams.phKernel,
                                                  *tracerParams.ppLaunchArgumentsBuffer,
                                                  *tracerParams.phSignalEvent,
                                                  *tracerParams.pnumWaitEvents,
                                                  *tracerParams.pphWaitEvents);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeCommandListAppendLaunchMultipleKernelsIndirect
    __zedlllocal ze_result_t ZE_APICALL
    zeCommandListAppendLaunchMultipleKernelsIndirect(
        ze_command_list_handle_t hCommandList,          ///< [in] handle of the command list
        uint32_t numKernels,                            ///< [in] maximum number of kernels to launch
        ze_kernel_handle_t* phKernels,                  ///< [in][range(0, numKernels)] handles of the kernel objects
        const uint32_t* pCountBuffer,                   ///< [in] pointer to device memory location that will contain the actual
                                                        ///< number of kernels to launch; value must be less-than or equal-to
                                                        ///< numKernels
        const ze_group_count_t* pLaunchArgumentsBuffer, ///< [in][range(0, numKernels)] pointer to device buffer that will contain
                                                        ///< a contiguous array of thread group launch arguments
        ze_event_handle_t hSignalEvent,                 ///< [in][optional] handle of the event to signal on completion
        uint32_t numWaitEvents,                         ///< [in][optional] number of events to wait on before launching; must be 0
                                                        ///< if `nullptr == phWaitEvents`
        ze_event_handle_t* phWaitEvents                 ///< [in][optional][range(0, numWaitEvents)] handle of the events to wait
                                                        ///< on before launching
        )
    {
        if( nullptr == context.zeDdiTable.CommandList.pfnAppendLaunchMultipleKernelsIndirect)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.CommandList.pfnAppendLaunchMultipleKernelsIndirect, hCommandList, numKernels, phKernels, pCountBuffer, pLaunchArgumentsBuffer, hSignalEvent, numWaitEvents, phWaitEvents);

        // capture parameters
        ze_command_list_append_launch_multiple_kernels_indirect_params_t tracerParams = {
            &hCommandList,
            &numKernels,
            &phKernels,
            &pCountBuffer,
            &pLaunchArgumentsBuffer,
            &hSignalEvent,
            &numWaitEvents,
            &phWaitEvents
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnCommandListAppendLaunchMultipleKernelsIndirectCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnCommandListAppendLaunchMultipleKernelsIndirectCb_t, CommandList, pfnAppendLaunchMultipleKernelsIndirectCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.CommandList.pfnAppendLaunchMultipleKernelsIndirect,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phCommandList,
                                                  *tracerParams.pnumKernels,
                                                  *tracerParams.pphKernels,
                                                  *tracerParams.ppCountBuffer,
                                                  *tracerParams.ppLaunchArgumentsBuffer,
                                                  *tracerParams.phSignalEvent,
                                                  *tracerParams.pnumWaitEvents,
                                                  *tracerParams.pphWaitEvents);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeContextMakeMemoryResident
    __zedlllocal ze_result_t ZE_APICALL
    zeContextMakeMemoryResident(
        ze_context_handle_t hContext,                   ///< [in] handle of context object
        ze_device_handle_t hDevice,                     ///< [in] handle of the device
        void* ptr,                                      ///< [in] pointer to memory to make resident
        size_t size                                     ///< [in] size in bytes to make resident
        )
    {
        if( nullptr == context.zeDdiTable.Context.pfnMakeMemoryResident)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Context.pfnMakeMemoryResident, hContext, hDevice, ptr, size);

        // capture parameters
        ze_context_make_memory_resident_params_t tracerParams = {
            &hContext,
            &hDevice,
            &ptr,
            &size
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnContextMakeMemoryResidentCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnContextMakeMemoryResidentCb_t, Context, pfnMakeMemoryResidentCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Context.pfnMakeMemoryResident,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext,
                                                  *tracerParams.phDevice,
                                                  *tracerParams.pptr,
                                                  *tracerParams.psize);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeContextEvictMemory
    __zedlllocal ze_result_t ZE_APICALL
    zeContextEvictMemory(
        ze_context_handle_t hContext,                   ///< [in] handle of context object
        ze_device_handle_t hDevice,                     ///< [in] handle of the device
        void* ptr,                                      ///< [in] pointer to memory to evict
        size_t size                                     ///< [in] size in bytes to evict
        )
    {
        if( nullptr == context.zeDdiTable.Context.pfnEvictMemory)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Context.pfnEvictMemory, hContext, hDevice, ptr, size);

        // capture parameters
        ze_context_evict_memory_params_t tracerParams = {
            &hContext,
            &hDevice,
            &ptr,
            &size
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnContextEvictMemoryCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnContextEvictMemoryCb_t, Context, pfnEvictMemoryCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Context.pfnEvictMemory,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext,
                                                  *tracerParams.phDevice,
                                                  *tracerParams.pptr,
                                                  *tracerParams.psize);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeContextMakeImageResident
    __zedlllocal ze_result_t ZE_APICALL
    zeContextMakeImageResident(
        ze_context_handle_t hContext,                   ///< [in] handle of context object
        ze_device_handle_t hDevice,                     ///< [in] handle of the device
        ze_image_handle_t hImage                        ///< [in] handle of image to make resident
        )
    {
        if( nullptr == context.zeDdiTable.Context.pfnMakeImageResident)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Context.pfnMakeImageResident, hContext, hDevice, hImage);

        // capture parameters
        ze_context_make_image_resident_params_t tracerParams = {
            &hContext,
            &hDevice,
            &hImage
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnContextMakeImageResidentCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnContextMakeImageResidentCb_t, Context, pfnMakeImageResidentCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Context.pfnMakeImageResident,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext,
                                                  *tracerParams.phDevice,
                                                  *tracerParams.phImage);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeContextEvictImage
    __zedlllocal ze_result_t ZE_APICALL
    zeContextEvictImage(
        ze_context_handle_t hContext,                   ///< [in] handle of context object
        ze_device_handle_t hDevice,                     ///< [in] handle of the device
        ze_image_handle_t hImage                        ///< [in] handle of image to make evict
        )
    {
        if( nullptr == context.zeDdiTable.Context.pfnEvictImage)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Context.pfnEvictImage, hContext, hDevice, hImage);

        // capture parameters
        ze_context_evict_image_params_t tracerParams = {
            &hContext,
            &hDevice,
            &hImage
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnContextEvictImageCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnContextEvictImageCb_t, Context, pfnEvictImageCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Context.pfnEvictImage,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext,
                                                  *tracerParams.phDevice,
                                                  *tracerParams.phImage);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeSamplerCreate
    __zedlllocal ze_result_t ZE_APICALL
    zeSamplerCreate(
        ze_context_handle_t hContext,                   ///< [in] handle of the context object
        ze_device_handle_t hDevice,                     ///< [in] handle of the device
        const ze_sampler_desc_t* desc,                  ///< [in] pointer to sampler descriptor
        ze_sampler_handle_t* phSampler                  ///< [out] handle of the sampler
        )
    {
        if( nullptr == context.zeDdiTable.Sampler.pfnCreate)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Sampler.pfnCreate, hContext, hDevice, desc, phSampler);

        // capture parameters
        ze_sampler_create_params_t tracerParams = {
            &hContext,
            &hDevice,
            &desc,
            &phSampler
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnSamplerCreateCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnSamplerCreateCb_t, Sampler, pfnCreateCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Sampler.pfnCreate,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext,
                                                  *tracerParams.phDevice,
                                                  *tracerParams.pdesc,
                                                  *tracerParams.pphSampler);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeSamplerDestroy
    __zedlllocal ze_result_t ZE_APICALL
    zeSamplerDestroy(
        ze_sampler_handle_t hSampler                    ///< [in][release] handle of the sampler
        )
    {
        if( nullptr == context.zeDdiTable.Sampler.pfnDestroy)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.Sampler.pfnDestroy, hSampler);

        // capture parameters
        ze_sampler_destroy_params_t tracerParams = {
            &hSampler
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnSamplerDestroyCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnSamplerDestroyCb_t, Sampler, pfnDestroyCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.Sampler.pfnDestroy,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phSampler);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeVirtualMemReserve
    __zedlllocal ze_result_t ZE_APICALL
    zeVirtualMemReserve(
        ze_context_handle_t hContext,                   ///< [in] handle of the context object
        const void* pStart,                             ///< [in] pointer to start of region to reserve. If nullptr then
                                                        ///< implementation will choose a start address.
        size_t size,                                    ///< [in] size in bytes to reserve; must be page aligned.
        void** pptr                                     ///< [out] pointer to virtual reservation.
        )
    {
        if( nullptr == context.zeDdiTable.VirtualMem.pfnReserve)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.VirtualMem.pfnReserve, hContext, pStart, size, pptr);

        // capture parameters
        ze_virtual_mem_reserve_params_t tracerParams = {
            &hContext,
            &pStart,
            &size,
            &pptr
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnVirtualMemReserveCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnVirtualMemReserveCb_t, VirtualMem, pfnReserveCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.VirtualMem.pfnReserve,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext,
                                                  *tracerParams.ppStart,
                                                  *tracerParams.psize,
                                                  *tracerParams.ppptr);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeVirtualMemFree
    __zedlllocal ze_result_t ZE_APICALL
    zeVirtualMemFree(
        ze_context_handle_t hContext,                   ///< [in] handle of the context object
        const void* ptr,                                ///< [in] pointer to start of region to free.
        size_t size                                     ///< [in] size in bytes to free; must be page aligned.
        )
    {
        if( nullptr == context.zeDdiTable.VirtualMem.pfnFree)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.VirtualMem.pfnFree, hContext, ptr, size);

        // capture parameters
        ze_virtual_mem_free_params_t tracerParams = {
            &hContext,
            &ptr,
            &size
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnVirtualMemFreeCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnVirtualMemFreeCb_t, VirtualMem, pfnFreeCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.VirtualMem.pfnFree,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext,
                                                  *tracerParams.pptr,
                                                  *tracerParams.psize);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeVirtualMemQueryPageSize
    __zedlllocal ze_result_t ZE_APICALL
    zeVirtualMemQueryPageSize(
        ze_context_handle_t hContext,                   ///< [in] handle of the context object
        ze_device_handle_t hDevice,                     ///< [in] handle of the device object
        size_t size,                                    ///< [in] unaligned allocation size in bytes
        size_t* pagesize                                ///< [out] pointer to page size to use for start address and size
                                                        ///< alignments.
        )
    {
        if( nullptr == context.zeDdiTable.VirtualMem.pfnQueryPageSize)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.VirtualMem.pfnQueryPageSize, hContext, hDevice, size, pagesize);

        // capture parameters
        ze_virtual_mem_query_page_size_params_t tracerParams = {
            &hContext,
            &hDevice,
            &size,
            &pagesize
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnVirtualMemQueryPageSizeCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnVirtualMemQueryPageSizeCb_t, VirtualMem, pfnQueryPageSizeCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.VirtualMem.pfnQueryPageSize,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext,
                                                  *tracerParams.phDevice,
                                                  *tracerParams.psize,
                                                  *tracerParams.ppagesize);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zePhysicalMemCreate
    __zedlllocal ze_result_t ZE_APICALL
    zePhysicalMemCreate(
        ze_context_handle_t hContext,                   ///< [in] handle of the context object
        ze_device_handle_t hDevice,                     ///< [in] handle of the device object
        ze_physical_mem_desc_t* desc,                   ///< [in] pointer to physical memory descriptor.
        ze_physical_mem_handle_t* phPhysicalMemory      ///< [out] pointer to handle of physical memory object created
        )
    {
        if( nullptr == context.zeDdiTable.PhysicalMem.pfnCreate)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.PhysicalMem.pfnCreate, hContext, hDevice, desc, phPhysicalMemory);

        // capture parameters
        ze_physical_mem_create_params_t tracerParams = {
            &hContext,
            &hDevice,
            &desc,
            &phPhysicalMemory
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnPhysicalMemCreateCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnPhysicalMemCreateCb_t, PhysicalMem, pfnCreateCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.PhysicalMem.pfnCreate,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext,
                                                  *tracerParams.phDevice,
                                                  *tracerParams.pdesc,
                                                  *tracerParams.pphPhysicalMemory);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zePhysicalMemDestroy
    __zedlllocal ze_result_t ZE_APICALL
    zePhysicalMemDestroy(
        ze_context_handle_t hContext,                   ///< [in] handle of the context object
        ze_physical_mem_handle_t hPhysicalMemory        ///< [in][release] handle of physical memory object to destroy
        )
    {
        if( nullptr == context.zeDdiTable.PhysicalMem.pfnDestroy)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.PhysicalMem.pfnDestroy, hContext, hPhysicalMemory);

        // capture parameters
        ze_physical_mem_destroy_params_t tracerParams = {
            &hContext,
            &hPhysicalMemory
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnPhysicalMemDestroyCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnPhysicalMemDestroyCb_t, PhysicalMem, pfnDestroyCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.PhysicalMem.pfnDestroy,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext,
                                                  *tracerParams.phPhysicalMemory);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeVirtualMemMap
    __zedlllocal ze_result_t ZE_APICALL
    zeVirtualMemMap(
        ze_context_handle_t hContext,                   ///< [in] handle of the context object
        const void* ptr,                                ///< [in] pointer to start of virtual address range to map.
        size_t size,                                    ///< [in] size in bytes of virtual address range to map; must be page
                                                        ///< aligned.
        ze_physical_mem_handle_t hPhysicalMemory,       ///< [in] handle to physical memory object.
        size_t offset,                                  ///< [in] offset into physical memory allocation object; must be page
                                                        ///< aligned.
        ze_memory_access_attribute_t access             ///< [in] specifies page access attributes to apply to the virtual address
                                                        ///< range.
        )
    {
        if( nullptr == context.zeDdiTable.VirtualMem.pfnMap)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.VirtualMem.pfnMap, hContext, ptr, size, hPhysicalMemory, offset, access);

        // capture parameters
        ze_virtual_mem_map_params_t tracerParams = {
            &hContext,
            &ptr,
            &size,
            &hPhysicalMemory,
            &offset,
            &access
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnVirtualMemMapCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnVirtualMemMapCb_t, VirtualMem, pfnMapCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.VirtualMem.pfnMap,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext,
                                                  *tracerParams.pptr,
                                                  *tracerParams.psize,
                                                  *tracerParams.phPhysicalMemory,
                                                  *tracerParams.poffset,
                                                  *tracerParams.paccess);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeVirtualMemUnmap
    __zedlllocal ze_result_t ZE_APICALL
    zeVirtualMemUnmap(
        ze_context_handle_t hContext,                   ///< [in] handle of the context object
        const void* ptr,                                ///< [in] pointer to start of region to unmap.
        size_t size                                     ///< [in] size in bytes to unmap; must be page aligned.
        )
    {
        if( nullptr == context.zeDdiTable.VirtualMem.pfnUnmap)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.VirtualMem.pfnUnmap, hContext, ptr, size);

        // capture parameters
        ze_virtual_mem_unmap_params_t tracerParams = {
            &hContext,
            &ptr,
            &size
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnVirtualMemUnmapCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnVirtualMemUnmapCb_t, VirtualMem, pfnUnmapCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.VirtualMem.pfnUnmap,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext,
                                                  *tracerParams.pptr,
                                                  *tracerParams.psize);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeVirtualMemSetAccessAttribute
    __zedlllocal ze_result_t ZE_APICALL
    zeVirtualMemSetAccessAttribute(
        ze_context_handle_t hContext,                   ///< [in] handle of the context object
        const void* ptr,                                ///< [in] pointer to start of reserved virtual address region.
        size_t size,                                    ///< [in] size in bytes; must be page aligned.
        ze_memory_access_attribute_t access             ///< [in] specifies page access attributes to apply to the virtual address
                                                        ///< range.
        )
    {
        if( nullptr == context.zeDdiTable.VirtualMem.pfnSetAccessAttribute)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.VirtualMem.pfnSetAccessAttribute, hContext, ptr, size, access);

        // capture parameters
        ze_virtual_mem_set_access_attribute_params_t tracerParams = {
            &hContext,
            &ptr,
            &size,
            &access
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnVirtualMemSetAccessAttributeCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnVirtualMemSetAccessAttributeCb_t, VirtualMem, pfnSetAccessAttributeCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.VirtualMem.pfnSetAccessAttribute,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext,
                                                  *tracerParams.pptr,
                                                  *tracerParams.psize,
                                                  *tracerParams.paccess);
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @brief Intercept function for zeVirtualMemGetAccessAttribute
    __zedlllocal ze_result_t ZE_APICALL
    zeVirtualMemGetAccessAttribute(
        ze_context_handle_t hContext,                   ///< [in] handle of the context object
        const void* ptr,                                ///< [in] pointer to start of virtual address region for query.
        size_t size,                                    ///< [in] size in bytes; must be page aligned.
        ze_memory_access_attribute_t* access,           ///< [out] query result for page access attribute.
        size_t* outSize                                 ///< [out] query result for size of virtual address range, starting at ptr,
                                                        ///< that shares same access attribute.
        )
    {
        if( nullptr == context.zeDdiTable.VirtualMem.pfnGetAccessAttribute)
            return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

        ZE_HANDLE_TRACER_RECURSION(context.zeDdiTable.VirtualMem.pfnGetAccessAttribute, hContext, ptr, size, access, outSize);

        // capture parameters
        ze_virtual_mem_get_access_attribute_params_t tracerParams = {
            &hContext,
            &ptr,
            &size,
            &access,
            &outSize
        };

        tracing_layer::APITracerCallbackDataImp<ze_pfnVirtualMemGetAccessAttributeCb_t> apiCallbackData;

        ZE_GEN_PER_API_CALLBACK_STATE(apiCallbackData, ze_pfnVirtualMemGetAccessAttributeCb_t, VirtualMem, pfnGetAccessAttributeCb);


        return tracing_layer::APITracerWrapperImp(context.zeDdiTable.VirtualMem.pfnGetAccessAttribute,
                                                  &tracerParams,
                                                  apiCallbackData.apiOrdinal,
                                                  apiCallbackData.prologCallbacks,
                                                  apiCallbackData.epilogCallbacks,
                                                  *tracerParams.phContext,
                                                  *tracerParams.pptr,
                                                  *tracerParams.psize,
                                                  *tracerParams.paccess,
                                                  *tracerParams.poutSize);
    }

} // namespace tracing_layer

#if defined(__cplusplus)
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Global table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zeGetGlobalProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    ze_global_dditable_t* pDdiTable                 ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = tracing_layer::context.zeDdiTable.Global;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( tracing_layer::context.version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnInit                                     = pDdiTable->pfnInit;
    pDdiTable->pfnInit                                   = tracing_layer::zeInit;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Driver table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zeGetDriverProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    ze_driver_dditable_t* pDdiTable                 ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = tracing_layer::context.zeDdiTable.Driver;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( tracing_layer::context.version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnGet                                      = pDdiTable->pfnGet;
    pDdiTable->pfnGet                                    = tracing_layer::zeDriverGet;

    dditable.pfnGetApiVersion                            = pDdiTable->pfnGetApiVersion;
    pDdiTable->pfnGetApiVersion                          = tracing_layer::zeDriverGetApiVersion;

    dditable.pfnGetProperties                            = pDdiTable->pfnGetProperties;
    pDdiTable->pfnGetProperties                          = tracing_layer::zeDriverGetProperties;

    dditable.pfnGetIpcProperties                         = pDdiTable->pfnGetIpcProperties;
    pDdiTable->pfnGetIpcProperties                       = tracing_layer::zeDriverGetIpcProperties;

    dditable.pfnGetExtensionProperties                   = pDdiTable->pfnGetExtensionProperties;
    pDdiTable->pfnGetExtensionProperties                 = tracing_layer::zeDriverGetExtensionProperties;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Device table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zeGetDeviceProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    ze_device_dditable_t* pDdiTable                 ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = tracing_layer::context.zeDdiTable.Device;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( tracing_layer::context.version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnGet                                      = pDdiTable->pfnGet;
    pDdiTable->pfnGet                                    = tracing_layer::zeDeviceGet;

    dditable.pfnGetSubDevices                            = pDdiTable->pfnGetSubDevices;
    pDdiTable->pfnGetSubDevices                          = tracing_layer::zeDeviceGetSubDevices;

    dditable.pfnGetProperties                            = pDdiTable->pfnGetProperties;
    pDdiTable->pfnGetProperties                          = tracing_layer::zeDeviceGetProperties;

    dditable.pfnGetComputeProperties                     = pDdiTable->pfnGetComputeProperties;
    pDdiTable->pfnGetComputeProperties                   = tracing_layer::zeDeviceGetComputeProperties;

    dditable.pfnGetModuleProperties                      = pDdiTable->pfnGetModuleProperties;
    pDdiTable->pfnGetModuleProperties                    = tracing_layer::zeDeviceGetModuleProperties;

    dditable.pfnGetCommandQueueGroupProperties           = pDdiTable->pfnGetCommandQueueGroupProperties;
    pDdiTable->pfnGetCommandQueueGroupProperties         = tracing_layer::zeDeviceGetCommandQueueGroupProperties;

    dditable.pfnGetMemoryProperties                      = pDdiTable->pfnGetMemoryProperties;
    pDdiTable->pfnGetMemoryProperties                    = tracing_layer::zeDeviceGetMemoryProperties;

    dditable.pfnGetMemoryAccessProperties                = pDdiTable->pfnGetMemoryAccessProperties;
    pDdiTable->pfnGetMemoryAccessProperties              = tracing_layer::zeDeviceGetMemoryAccessProperties;

    dditable.pfnGetCacheProperties                       = pDdiTable->pfnGetCacheProperties;
    pDdiTable->pfnGetCacheProperties                     = tracing_layer::zeDeviceGetCacheProperties;

    dditable.pfnGetImageProperties                       = pDdiTable->pfnGetImageProperties;
    pDdiTable->pfnGetImageProperties                     = tracing_layer::zeDeviceGetImageProperties;

    dditable.pfnGetExternalMemoryProperties              = pDdiTable->pfnGetExternalMemoryProperties;
    pDdiTable->pfnGetExternalMemoryProperties            = tracing_layer::zeDeviceGetExternalMemoryProperties;

    dditable.pfnGetP2PProperties                         = pDdiTable->pfnGetP2PProperties;
    pDdiTable->pfnGetP2PProperties                       = tracing_layer::zeDeviceGetP2PProperties;

    dditable.pfnCanAccessPeer                            = pDdiTable->pfnCanAccessPeer;
    pDdiTable->pfnCanAccessPeer                          = tracing_layer::zeDeviceCanAccessPeer;

    dditable.pfnGetStatus                                = pDdiTable->pfnGetStatus;
    pDdiTable->pfnGetStatus                              = tracing_layer::zeDeviceGetStatus;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Context table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zeGetContextProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    ze_context_dditable_t* pDdiTable                ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = tracing_layer::context.zeDdiTable.Context;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( tracing_layer::context.version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnCreate                                   = pDdiTable->pfnCreate;
    pDdiTable->pfnCreate                                 = tracing_layer::zeContextCreate;

    dditable.pfnDestroy                                  = pDdiTable->pfnDestroy;
    pDdiTable->pfnDestroy                                = tracing_layer::zeContextDestroy;

    dditable.pfnGetStatus                                = pDdiTable->pfnGetStatus;
    pDdiTable->pfnGetStatus                              = tracing_layer::zeContextGetStatus;

    dditable.pfnSystemBarrier                            = pDdiTable->pfnSystemBarrier;
    pDdiTable->pfnSystemBarrier                          = tracing_layer::zeContextSystemBarrier;

    dditable.pfnMakeMemoryResident                       = pDdiTable->pfnMakeMemoryResident;
    pDdiTable->pfnMakeMemoryResident                     = tracing_layer::zeContextMakeMemoryResident;

    dditable.pfnEvictMemory                              = pDdiTable->pfnEvictMemory;
    pDdiTable->pfnEvictMemory                            = tracing_layer::zeContextEvictMemory;

    dditable.pfnMakeImageResident                        = pDdiTable->pfnMakeImageResident;
    pDdiTable->pfnMakeImageResident                      = tracing_layer::zeContextMakeImageResident;

    dditable.pfnEvictImage                               = pDdiTable->pfnEvictImage;
    pDdiTable->pfnEvictImage                             = tracing_layer::zeContextEvictImage;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's CommandQueue table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zeGetCommandQueueProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    ze_command_queue_dditable_t* pDdiTable          ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = tracing_layer::context.zeDdiTable.CommandQueue;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( tracing_layer::context.version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnCreate                                   = pDdiTable->pfnCreate;
    pDdiTable->pfnCreate                                 = tracing_layer::zeCommandQueueCreate;

    dditable.pfnDestroy                                  = pDdiTable->pfnDestroy;
    pDdiTable->pfnDestroy                                = tracing_layer::zeCommandQueueDestroy;

    dditable.pfnExecuteCommandLists                      = pDdiTable->pfnExecuteCommandLists;
    pDdiTable->pfnExecuteCommandLists                    = tracing_layer::zeCommandQueueExecuteCommandLists;

    dditable.pfnSynchronize                              = pDdiTable->pfnSynchronize;
    pDdiTable->pfnSynchronize                            = tracing_layer::zeCommandQueueSynchronize;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's CommandList table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zeGetCommandListProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    ze_command_list_dditable_t* pDdiTable           ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = tracing_layer::context.zeDdiTable.CommandList;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( tracing_layer::context.version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnCreate                                   = pDdiTable->pfnCreate;
    pDdiTable->pfnCreate                                 = tracing_layer::zeCommandListCreate;

    dditable.pfnCreateImmediate                          = pDdiTable->pfnCreateImmediate;
    pDdiTable->pfnCreateImmediate                        = tracing_layer::zeCommandListCreateImmediate;

    dditable.pfnDestroy                                  = pDdiTable->pfnDestroy;
    pDdiTable->pfnDestroy                                = tracing_layer::zeCommandListDestroy;

    dditable.pfnClose                                    = pDdiTable->pfnClose;
    pDdiTable->pfnClose                                  = tracing_layer::zeCommandListClose;

    dditable.pfnReset                                    = pDdiTable->pfnReset;
    pDdiTable->pfnReset                                  = tracing_layer::zeCommandListReset;

    dditable.pfnAppendWriteGlobalTimestamp               = pDdiTable->pfnAppendWriteGlobalTimestamp;
    pDdiTable->pfnAppendWriteGlobalTimestamp             = tracing_layer::zeCommandListAppendWriteGlobalTimestamp;

    dditable.pfnAppendBarrier                            = pDdiTable->pfnAppendBarrier;
    pDdiTable->pfnAppendBarrier                          = tracing_layer::zeCommandListAppendBarrier;

    dditable.pfnAppendMemoryRangesBarrier                = pDdiTable->pfnAppendMemoryRangesBarrier;
    pDdiTable->pfnAppendMemoryRangesBarrier              = tracing_layer::zeCommandListAppendMemoryRangesBarrier;

    dditable.pfnAppendMemoryCopy                         = pDdiTable->pfnAppendMemoryCopy;
    pDdiTable->pfnAppendMemoryCopy                       = tracing_layer::zeCommandListAppendMemoryCopy;

    dditable.pfnAppendMemoryFill                         = pDdiTable->pfnAppendMemoryFill;
    pDdiTable->pfnAppendMemoryFill                       = tracing_layer::zeCommandListAppendMemoryFill;

    dditable.pfnAppendMemoryCopyRegion                   = pDdiTable->pfnAppendMemoryCopyRegion;
    pDdiTable->pfnAppendMemoryCopyRegion                 = tracing_layer::zeCommandListAppendMemoryCopyRegion;

    dditable.pfnAppendMemoryCopyFromContext              = pDdiTable->pfnAppendMemoryCopyFromContext;
    pDdiTable->pfnAppendMemoryCopyFromContext            = tracing_layer::zeCommandListAppendMemoryCopyFromContext;

    dditable.pfnAppendImageCopy                          = pDdiTable->pfnAppendImageCopy;
    pDdiTable->pfnAppendImageCopy                        = tracing_layer::zeCommandListAppendImageCopy;

    dditable.pfnAppendImageCopyRegion                    = pDdiTable->pfnAppendImageCopyRegion;
    pDdiTable->pfnAppendImageCopyRegion                  = tracing_layer::zeCommandListAppendImageCopyRegion;

    dditable.pfnAppendImageCopyToMemory                  = pDdiTable->pfnAppendImageCopyToMemory;
    pDdiTable->pfnAppendImageCopyToMemory                = tracing_layer::zeCommandListAppendImageCopyToMemory;

    dditable.pfnAppendImageCopyFromMemory                = pDdiTable->pfnAppendImageCopyFromMemory;
    pDdiTable->pfnAppendImageCopyFromMemory              = tracing_layer::zeCommandListAppendImageCopyFromMemory;

    dditable.pfnAppendMemoryPrefetch                     = pDdiTable->pfnAppendMemoryPrefetch;
    pDdiTable->pfnAppendMemoryPrefetch                   = tracing_layer::zeCommandListAppendMemoryPrefetch;

    dditable.pfnAppendMemAdvise                          = pDdiTable->pfnAppendMemAdvise;
    pDdiTable->pfnAppendMemAdvise                        = tracing_layer::zeCommandListAppendMemAdvise;

    dditable.pfnAppendSignalEvent                        = pDdiTable->pfnAppendSignalEvent;
    pDdiTable->pfnAppendSignalEvent                      = tracing_layer::zeCommandListAppendSignalEvent;

    dditable.pfnAppendWaitOnEvents                       = pDdiTable->pfnAppendWaitOnEvents;
    pDdiTable->pfnAppendWaitOnEvents                     = tracing_layer::zeCommandListAppendWaitOnEvents;

    dditable.pfnAppendEventReset                         = pDdiTable->pfnAppendEventReset;
    pDdiTable->pfnAppendEventReset                       = tracing_layer::zeCommandListAppendEventReset;

    dditable.pfnAppendQueryKernelTimestamps              = pDdiTable->pfnAppendQueryKernelTimestamps;
    pDdiTable->pfnAppendQueryKernelTimestamps            = tracing_layer::zeCommandListAppendQueryKernelTimestamps;

    dditable.pfnAppendLaunchKernel                       = pDdiTable->pfnAppendLaunchKernel;
    pDdiTable->pfnAppendLaunchKernel                     = tracing_layer::zeCommandListAppendLaunchKernel;

    dditable.pfnAppendLaunchCooperativeKernel            = pDdiTable->pfnAppendLaunchCooperativeKernel;
    pDdiTable->pfnAppendLaunchCooperativeKernel          = tracing_layer::zeCommandListAppendLaunchCooperativeKernel;

    dditable.pfnAppendLaunchKernelIndirect               = pDdiTable->pfnAppendLaunchKernelIndirect;
    pDdiTable->pfnAppendLaunchKernelIndirect             = tracing_layer::zeCommandListAppendLaunchKernelIndirect;

    dditable.pfnAppendLaunchMultipleKernelsIndirect      = pDdiTable->pfnAppendLaunchMultipleKernelsIndirect;
    pDdiTable->pfnAppendLaunchMultipleKernelsIndirect    = tracing_layer::zeCommandListAppendLaunchMultipleKernelsIndirect;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Event table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zeGetEventProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    ze_event_dditable_t* pDdiTable                  ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = tracing_layer::context.zeDdiTable.Event;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( tracing_layer::context.version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnCreate                                   = pDdiTable->pfnCreate;
    pDdiTable->pfnCreate                                 = tracing_layer::zeEventCreate;

    dditable.pfnDestroy                                  = pDdiTable->pfnDestroy;
    pDdiTable->pfnDestroy                                = tracing_layer::zeEventDestroy;

    dditable.pfnHostSignal                               = pDdiTable->pfnHostSignal;
    pDdiTable->pfnHostSignal                             = tracing_layer::zeEventHostSignal;

    dditable.pfnHostSynchronize                          = pDdiTable->pfnHostSynchronize;
    pDdiTable->pfnHostSynchronize                        = tracing_layer::zeEventHostSynchronize;

    dditable.pfnQueryStatus                              = pDdiTable->pfnQueryStatus;
    pDdiTable->pfnQueryStatus                            = tracing_layer::zeEventQueryStatus;

    dditable.pfnHostReset                                = pDdiTable->pfnHostReset;
    pDdiTable->pfnHostReset                              = tracing_layer::zeEventHostReset;

    dditable.pfnQueryKernelTimestamp                     = pDdiTable->pfnQueryKernelTimestamp;
    pDdiTable->pfnQueryKernelTimestamp                   = tracing_layer::zeEventQueryKernelTimestamp;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's EventPool table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zeGetEventPoolProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    ze_event_pool_dditable_t* pDdiTable             ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = tracing_layer::context.zeDdiTable.EventPool;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( tracing_layer::context.version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnCreate                                   = pDdiTable->pfnCreate;
    pDdiTable->pfnCreate                                 = tracing_layer::zeEventPoolCreate;

    dditable.pfnDestroy                                  = pDdiTable->pfnDestroy;
    pDdiTable->pfnDestroy                                = tracing_layer::zeEventPoolDestroy;

    dditable.pfnGetIpcHandle                             = pDdiTable->pfnGetIpcHandle;
    pDdiTable->pfnGetIpcHandle                           = tracing_layer::zeEventPoolGetIpcHandle;

    dditable.pfnOpenIpcHandle                            = pDdiTable->pfnOpenIpcHandle;
    pDdiTable->pfnOpenIpcHandle                          = tracing_layer::zeEventPoolOpenIpcHandle;

    dditable.pfnCloseIpcHandle                           = pDdiTable->pfnCloseIpcHandle;
    pDdiTable->pfnCloseIpcHandle                         = tracing_layer::zeEventPoolCloseIpcHandle;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Fence table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zeGetFenceProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    ze_fence_dditable_t* pDdiTable                  ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = tracing_layer::context.zeDdiTable.Fence;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( tracing_layer::context.version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnCreate                                   = pDdiTable->pfnCreate;
    pDdiTable->pfnCreate                                 = tracing_layer::zeFenceCreate;

    dditable.pfnDestroy                                  = pDdiTable->pfnDestroy;
    pDdiTable->pfnDestroy                                = tracing_layer::zeFenceDestroy;

    dditable.pfnHostSynchronize                          = pDdiTable->pfnHostSynchronize;
    pDdiTable->pfnHostSynchronize                        = tracing_layer::zeFenceHostSynchronize;

    dditable.pfnQueryStatus                              = pDdiTable->pfnQueryStatus;
    pDdiTable->pfnQueryStatus                            = tracing_layer::zeFenceQueryStatus;

    dditable.pfnReset                                    = pDdiTable->pfnReset;
    pDdiTable->pfnReset                                  = tracing_layer::zeFenceReset;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Image table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zeGetImageProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    ze_image_dditable_t* pDdiTable                  ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = tracing_layer::context.zeDdiTable.Image;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( tracing_layer::context.version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnGetProperties                            = pDdiTable->pfnGetProperties;
    pDdiTable->pfnGetProperties                          = tracing_layer::zeImageGetProperties;

    dditable.pfnCreate                                   = pDdiTable->pfnCreate;
    pDdiTable->pfnCreate                                 = tracing_layer::zeImageCreate;

    dditable.pfnDestroy                                  = pDdiTable->pfnDestroy;
    pDdiTable->pfnDestroy                                = tracing_layer::zeImageDestroy;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Kernel table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zeGetKernelProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    ze_kernel_dditable_t* pDdiTable                 ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = tracing_layer::context.zeDdiTable.Kernel;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( tracing_layer::context.version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnCreate                                   = pDdiTable->pfnCreate;
    pDdiTable->pfnCreate                                 = tracing_layer::zeKernelCreate;

    dditable.pfnDestroy                                  = pDdiTable->pfnDestroy;
    pDdiTable->pfnDestroy                                = tracing_layer::zeKernelDestroy;

    dditable.pfnSetCacheConfig                           = pDdiTable->pfnSetCacheConfig;
    pDdiTable->pfnSetCacheConfig                         = tracing_layer::zeKernelSetCacheConfig;

    dditable.pfnSetGroupSize                             = pDdiTable->pfnSetGroupSize;
    pDdiTable->pfnSetGroupSize                           = tracing_layer::zeKernelSetGroupSize;

    dditable.pfnSuggestGroupSize                         = pDdiTable->pfnSuggestGroupSize;
    pDdiTable->pfnSuggestGroupSize                       = tracing_layer::zeKernelSuggestGroupSize;

    dditable.pfnSuggestMaxCooperativeGroupCount          = pDdiTable->pfnSuggestMaxCooperativeGroupCount;
    pDdiTable->pfnSuggestMaxCooperativeGroupCount        = tracing_layer::zeKernelSuggestMaxCooperativeGroupCount;

    dditable.pfnSetArgumentValue                         = pDdiTable->pfnSetArgumentValue;
    pDdiTable->pfnSetArgumentValue                       = tracing_layer::zeKernelSetArgumentValue;

    dditable.pfnSetIndirectAccess                        = pDdiTable->pfnSetIndirectAccess;
    pDdiTable->pfnSetIndirectAccess                      = tracing_layer::zeKernelSetIndirectAccess;

    dditable.pfnGetIndirectAccess                        = pDdiTable->pfnGetIndirectAccess;
    pDdiTable->pfnGetIndirectAccess                      = tracing_layer::zeKernelGetIndirectAccess;

    dditable.pfnGetSourceAttributes                      = pDdiTable->pfnGetSourceAttributes;
    pDdiTable->pfnGetSourceAttributes                    = tracing_layer::zeKernelGetSourceAttributes;

    dditable.pfnGetProperties                            = pDdiTable->pfnGetProperties;
    pDdiTable->pfnGetProperties                          = tracing_layer::zeKernelGetProperties;

    dditable.pfnGetName                                  = pDdiTable->pfnGetName;
    pDdiTable->pfnGetName                                = tracing_layer::zeKernelGetName;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Mem table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zeGetMemProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    ze_mem_dditable_t* pDdiTable                    ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = tracing_layer::context.zeDdiTable.Mem;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( tracing_layer::context.version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnAllocShared                              = pDdiTable->pfnAllocShared;
    pDdiTable->pfnAllocShared                            = tracing_layer::zeMemAllocShared;

    dditable.pfnAllocDevice                              = pDdiTable->pfnAllocDevice;
    pDdiTable->pfnAllocDevice                            = tracing_layer::zeMemAllocDevice;

    dditable.pfnAllocHost                                = pDdiTable->pfnAllocHost;
    pDdiTable->pfnAllocHost                              = tracing_layer::zeMemAllocHost;

    dditable.pfnFree                                     = pDdiTable->pfnFree;
    pDdiTable->pfnFree                                   = tracing_layer::zeMemFree;

    dditable.pfnGetAllocProperties                       = pDdiTable->pfnGetAllocProperties;
    pDdiTable->pfnGetAllocProperties                     = tracing_layer::zeMemGetAllocProperties;

    dditable.pfnGetAddressRange                          = pDdiTable->pfnGetAddressRange;
    pDdiTable->pfnGetAddressRange                        = tracing_layer::zeMemGetAddressRange;

    dditable.pfnGetIpcHandle                             = pDdiTable->pfnGetIpcHandle;
    pDdiTable->pfnGetIpcHandle                           = tracing_layer::zeMemGetIpcHandle;

    dditable.pfnOpenIpcHandle                            = pDdiTable->pfnOpenIpcHandle;
    pDdiTable->pfnOpenIpcHandle                          = tracing_layer::zeMemOpenIpcHandle;

    dditable.pfnCloseIpcHandle                           = pDdiTable->pfnCloseIpcHandle;
    pDdiTable->pfnCloseIpcHandle                         = tracing_layer::zeMemCloseIpcHandle;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Module table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zeGetModuleProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    ze_module_dditable_t* pDdiTable                 ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = tracing_layer::context.zeDdiTable.Module;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( tracing_layer::context.version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnCreate                                   = pDdiTable->pfnCreate;
    pDdiTable->pfnCreate                                 = tracing_layer::zeModuleCreate;

    dditable.pfnDestroy                                  = pDdiTable->pfnDestroy;
    pDdiTable->pfnDestroy                                = tracing_layer::zeModuleDestroy;

    dditable.pfnDynamicLink                              = pDdiTable->pfnDynamicLink;
    pDdiTable->pfnDynamicLink                            = tracing_layer::zeModuleDynamicLink;

    dditable.pfnGetNativeBinary                          = pDdiTable->pfnGetNativeBinary;
    pDdiTable->pfnGetNativeBinary                        = tracing_layer::zeModuleGetNativeBinary;

    dditable.pfnGetGlobalPointer                         = pDdiTable->pfnGetGlobalPointer;
    pDdiTable->pfnGetGlobalPointer                       = tracing_layer::zeModuleGetGlobalPointer;

    dditable.pfnGetKernelNames                           = pDdiTable->pfnGetKernelNames;
    pDdiTable->pfnGetKernelNames                         = tracing_layer::zeModuleGetKernelNames;

    dditable.pfnGetProperties                            = pDdiTable->pfnGetProperties;
    pDdiTable->pfnGetProperties                          = tracing_layer::zeModuleGetProperties;

    dditable.pfnGetFunctionPointer                       = pDdiTable->pfnGetFunctionPointer;
    pDdiTable->pfnGetFunctionPointer                     = tracing_layer::zeModuleGetFunctionPointer;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's ModuleBuildLog table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zeGetModuleBuildLogProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    ze_module_build_log_dditable_t* pDdiTable       ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = tracing_layer::context.zeDdiTable.ModuleBuildLog;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( tracing_layer::context.version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnDestroy                                  = pDdiTable->pfnDestroy;
    pDdiTable->pfnDestroy                                = tracing_layer::zeModuleBuildLogDestroy;

    dditable.pfnGetString                                = pDdiTable->pfnGetString;
    pDdiTable->pfnGetString                              = tracing_layer::zeModuleBuildLogGetString;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's PhysicalMem table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zeGetPhysicalMemProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    ze_physical_mem_dditable_t* pDdiTable           ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = tracing_layer::context.zeDdiTable.PhysicalMem;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( tracing_layer::context.version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnCreate                                   = pDdiTable->pfnCreate;
    pDdiTable->pfnCreate                                 = tracing_layer::zePhysicalMemCreate;

    dditable.pfnDestroy                                  = pDdiTable->pfnDestroy;
    pDdiTable->pfnDestroy                                = tracing_layer::zePhysicalMemDestroy;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's Sampler table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zeGetSamplerProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    ze_sampler_dditable_t* pDdiTable                ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = tracing_layer::context.zeDdiTable.Sampler;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( tracing_layer::context.version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnCreate                                   = pDdiTable->pfnCreate;
    pDdiTable->pfnCreate                                 = tracing_layer::zeSamplerCreate;

    dditable.pfnDestroy                                  = pDdiTable->pfnDestroy;
    pDdiTable->pfnDestroy                                = tracing_layer::zeSamplerDestroy;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
/// @brief Exported function for filling application's VirtualMem table
///        with current process' addresses
///
/// @returns
///     - ::ZE_RESULT_SUCCESS
///     - ::ZE_RESULT_ERROR_INVALID_NULL_POINTER
///     - ::ZE_RESULT_ERROR_UNSUPPORTED_VERSION
ZE_DLLEXPORT ze_result_t ZE_APICALL
zeGetVirtualMemProcAddrTable(
    ze_api_version_t version,                       ///< [in] API version requested
    ze_virtual_mem_dditable_t* pDdiTable            ///< [in,out] pointer to table of DDI function pointers
    )
{
    auto& dditable = tracing_layer::context.zeDdiTable.VirtualMem;

    if( nullptr == pDdiTable )
        return ZE_RESULT_ERROR_INVALID_NULL_POINTER;

    if( tracing_layer::context.version < version )
        return ZE_RESULT_ERROR_UNSUPPORTED_VERSION;

    ze_result_t result = ZE_RESULT_SUCCESS;

    dditable.pfnReserve                                  = pDdiTable->pfnReserve;
    pDdiTable->pfnReserve                                = tracing_layer::zeVirtualMemReserve;

    dditable.pfnFree                                     = pDdiTable->pfnFree;
    pDdiTable->pfnFree                                   = tracing_layer::zeVirtualMemFree;

    dditable.pfnQueryPageSize                            = pDdiTable->pfnQueryPageSize;
    pDdiTable->pfnQueryPageSize                          = tracing_layer::zeVirtualMemQueryPageSize;

    dditable.pfnMap                                      = pDdiTable->pfnMap;
    pDdiTable->pfnMap                                    = tracing_layer::zeVirtualMemMap;

    dditable.pfnUnmap                                    = pDdiTable->pfnUnmap;
    pDdiTable->pfnUnmap                                  = tracing_layer::zeVirtualMemUnmap;

    dditable.pfnSetAccessAttribute                       = pDdiTable->pfnSetAccessAttribute;
    pDdiTable->pfnSetAccessAttribute                     = tracing_layer::zeVirtualMemSetAccessAttribute;

    dditable.pfnGetAccessAttribute                       = pDdiTable->pfnGetAccessAttribute;
    pDdiTable->pfnGetAccessAttribute                     = tracing_layer::zeVirtualMemGetAccessAttribute;

    return result;
}

#if defined(__cplusplus)
};
#endif
