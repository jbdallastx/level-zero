/*
 *
 * Copyright (C) 2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */
#include "ze_loader.h"

#include "driver_discovery.h"

namespace loader
{
    ///////////////////////////////////////////////////////////////////////////////
    context_t *context;

    ///////////////////////////////////////////////////////////////////////////////
    HMODULE LoadDriverUserDefinedPath( void )
    {
        HMODULE driver = nullptr;

#if !defined _RELEASE

        LONG success = ERROR_SUCCESS;
        HKEY key = nullptr;
        BYTE path[ _MAX_PATH ];
        DWORD size = _MAX_PATH;

        success = RegOpenKeyExA(
            HKEY_LOCAL_MACHINE, 
            "SOFTWARE\\Intel\\VPU\\LevelZero",
            0, 
            KEY_READ, 
            &key );

        if( ERROR_SUCCESS == success )
        {
            success = RegQueryValueExA(
                key, 
                "UserDefinedDriverPath",
                NULL, 
                NULL,
                path,
                &size );

            RegCloseKey( key );
        }

        // Attempt to load driver from user specified path
        if( size > 0 )
        {
            driver = LOAD_DRIVER_LIBRARY( (char*)path );
        }
#endif  // !_RELEASE

        return driver;
    }

    ///////////////////////////////////////////////////////////////////////////////
    HMODULE LoadDriverFromCurrentPath( void )
    {
        HMODULE driver = nullptr;

#if !defined _RELEASE

        char path[ _MAX_PATH ];
        DWORD size = _MAX_PATH;

        GetCurrentDirectory( _MAX_PATH, path );
        strcat( path, "\\ze_intel_vpu64.dll" );

        driver = LOAD_DRIVER_LIBRARY( path );

#endif  // !_RELEASE

        return driver;
    }

    ///////////////////////////////////////////////////////////////////////////////
    ze_result_t context_t::init()
    {
        driver_t driver;
        driver.handle = LoadDriverFromCurrentPath();

        if( NULL == driver.handle )
        {
            driver.handle = LoadDriverUserDefinedPath();
        }

        if( driver.handle )
        {
            drivers.push_back( driver );
        }
        else
        {
            auto discoveredDrivers = discoverEnabledDrivers();

            drivers.reserve( discoveredDrivers.size() + getenv_tobool( "ZE_ENABLE_NULL_DRIVER" ) );
            if( getenv_tobool( "ZE_ENABLE_NULL_DRIVER" ) )
            {
                auto handle = LOAD_DRIVER_LIBRARY( MAKE_LIBRARY_NAME( "ze_null", L0_LOADER_VERSION ) );
                if( NULL != handle )
                {
                    drivers.emplace_back();
                    drivers.rbegin()->handle = handle;
                }
            }

            for( auto name : discoveredDrivers )
            {
                auto handle = LOAD_DRIVER_LIBRARY( name.c_str() );
                if( NULL != handle )
                {
                    drivers.emplace_back();
                    drivers.rbegin()->handle = handle;
                }

            }

            if( getenv_tobool( "ZE_ENABLE_VALIDATION_LAYER" ) )
            {
                validationLayer = LOAD_DRIVER_LIBRARY( MAKE_LAYER_NAME( "ze_validation_layer" ) );
            }

            if( getenv_tobool( "ZE_ENABLE_TRACING_LAYER" ) )
            {
                tracingLayer = LOAD_DRIVER_LIBRARY( MAKE_LAYER_NAME( "ze_tracing_layer" ) );
            }

            forceIntercept = getenv_tobool( "ZE_ENABLE_LOADER_INTERCEPT" );
        }

        return ZE_RESULT_SUCCESS;
    };

    ///////////////////////////////////////////////////////////////////////////////
    context_t::~context_t()
    {
        FREE_DRIVER_LIBRARY( validationLayer );
        FREE_DRIVER_LIBRARY( tracingLayer );

        for( auto& drv : drivers )
        {
            FREE_DRIVER_LIBRARY( drv.handle );
        }
    };
}
