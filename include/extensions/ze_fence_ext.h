/*
*
* Copyright (C) 2021 Intel Corporation
*
* SPDX-License-Identifier: MIT
*
*/
#pragma once

#include "ze_api.h"

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zeFenceDeviceSignal_ext
typedef ze_result_t (ZE_APICALL *ze_pfnFenceDeviceSignal_ext_t)(
    ze_fence_handle_t,
    uint64_t
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Function-pointer for zeFenceDeviceSynchronize_ext
typedef ze_result_t (ZE_APICALL *ze_pfnFenceDeviceSynchronize_ext_t)(
    ze_command_queue_handle_t,
    ze_fence_handle_t,
    uint64_t
    );

///////////////////////////////////////////////////////////////////////////////
/// @brief Table of Fence extension functions pointers
typedef struct _ze_fence_dditable_ext_t
{
    ze_pfnFenceDeviceSignal_ext_t         pfnDeviceSignal;
    ze_pfnFenceDeviceSynchronize_ext_t    pfnDeviceSynchronize;
} ze_fence_dditable_ext_t;