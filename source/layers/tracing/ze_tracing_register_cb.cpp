/*
 *
 * Copyright (C) 2021 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 * @file ze_tracing_register_cb.h
 *
 */

#include "tracing.h"
#include "ze_tracing_layer.h"
#include "layers/zel_tracing_api.h"
#include "layers/zel_tracing_ddi.h"
#include "layers/zel_tracing_register_cb.h"
#include "ze_api.h"

extern "C" { 

/// APIs to register callbacks for each core API

ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerInitRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnInitCb_t pfnInitCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Global.pfnInitCb = pfnInitCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerDriverGetRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnDriverGetCb_t pfnGetCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Driver.pfnGetCb = pfnGetCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerDriverGetApiVersionRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnDriverGetApiVersionCb_t pfnGetApiVersionCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Driver.pfnGetApiVersionCb = pfnGetApiVersionCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerDriverGetPropertiesRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnDriverGetPropertiesCb_t pfnGetPropertiesCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Driver.pfnGetPropertiesCb = pfnGetPropertiesCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerDriverGetIpcPropertiesRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnDriverGetIpcPropertiesCb_t pfnGetIpcPropertiesCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Driver.pfnGetIpcPropertiesCb = pfnGetIpcPropertiesCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerDriverGetExtensionPropertiesRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnDriverGetExtensionPropertiesCb_t pfnGetExtensionPropertiesCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Driver.pfnGetExtensionPropertiesCb = pfnGetExtensionPropertiesCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerDriverGetExtensionFunctionAddressRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnDriverGetExtensionFunctionAddressCb_t pfnGetExtensionFunctionAddressCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Driver.pfnGetExtensionFunctionAddressCb = pfnGetExtensionFunctionAddressCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerDeviceGetRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnDeviceGetCb_t pfnGetCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Device.pfnGetCb = pfnGetCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerDeviceGetSubDevicesRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnDeviceGetSubDevicesCb_t pfnGetSubDevicesCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Device.pfnGetSubDevicesCb = pfnGetSubDevicesCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerDeviceGetPropertiesRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnDeviceGetPropertiesCb_t pfnGetPropertiesCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Device.pfnGetPropertiesCb = pfnGetPropertiesCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerDeviceGetComputePropertiesRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnDeviceGetComputePropertiesCb_t pfnGetComputePropertiesCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Device.pfnGetComputePropertiesCb = pfnGetComputePropertiesCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerDeviceGetModulePropertiesRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnDeviceGetModulePropertiesCb_t pfnGetModulePropertiesCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Device.pfnGetModulePropertiesCb = pfnGetModulePropertiesCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerDeviceGetCommandQueueGroupPropertiesRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnDeviceGetCommandQueueGroupPropertiesCb_t pfnGetCommandQueueGroupPropertiesCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Device.pfnGetCommandQueueGroupPropertiesCb = pfnGetCommandQueueGroupPropertiesCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerDeviceGetMemoryPropertiesRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnDeviceGetMemoryPropertiesCb_t pfnGetMemoryPropertiesCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Device.pfnGetMemoryPropertiesCb = pfnGetMemoryPropertiesCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerDeviceGetMemoryAccessPropertiesRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnDeviceGetMemoryAccessPropertiesCb_t pfnGetMemoryAccessPropertiesCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Device.pfnGetMemoryAccessPropertiesCb = pfnGetMemoryAccessPropertiesCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerDeviceGetCachePropertiesRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnDeviceGetCachePropertiesCb_t pfnGetCachePropertiesCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Device.pfnGetCachePropertiesCb = pfnGetCachePropertiesCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerDeviceGetImagePropertiesRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnDeviceGetImagePropertiesCb_t pfnGetImagePropertiesCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Device.pfnGetImagePropertiesCb = pfnGetImagePropertiesCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerDeviceGetExternalMemoryPropertiesRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnDeviceGetExternalMemoryPropertiesCb_t pfnGetExternalMemoryPropertiesCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Device.pfnGetExternalMemoryPropertiesCb = pfnGetExternalMemoryPropertiesCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerDeviceGetP2PPropertiesRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnDeviceGetP2PPropertiesCb_t pfnGetP2PPropertiesCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Device.pfnGetP2PPropertiesCb = pfnGetP2PPropertiesCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerDeviceCanAccessPeerRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnDeviceCanAccessPeerCb_t pfnCanAccessPeerCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Device.pfnCanAccessPeerCb = pfnCanAccessPeerCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerDeviceGetStatusRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnDeviceGetStatusCb_t pfnGetStatusCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Device.pfnGetStatusCb = pfnGetStatusCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerDeviceGetGlobalTimestampsRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnDeviceGetGlobalTimestampsCb_t pfnGetGlobalTimestampsCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Device.pfnGetGlobalTimestampsCb = pfnGetGlobalTimestampsCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerContextCreateRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnContextCreateCb_t pfnCreateCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Context.pfnCreateCb = pfnCreateCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerContextCreateExRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnContextCreateExCb_t pfnCreateExCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Context.pfnCreateExCb = pfnCreateExCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerContextDestroyRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnContextDestroyCb_t pfnDestroyCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Context.pfnDestroyCb = pfnDestroyCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerContextGetStatusRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnContextGetStatusCb_t pfnGetStatusCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Context.pfnGetStatusCb = pfnGetStatusCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerCommandQueueCreateRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnCommandQueueCreateCb_t pfnCreateCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.CommandQueue.pfnCreateCb = pfnCreateCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerCommandQueueDestroyRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnCommandQueueDestroyCb_t pfnDestroyCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.CommandQueue.pfnDestroyCb = pfnDestroyCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerCommandQueueExecuteCommandListsRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnCommandQueueExecuteCommandListsCb_t pfnExecuteCommandListsCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.CommandQueue.pfnExecuteCommandListsCb = pfnExecuteCommandListsCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerCommandQueueSynchronizeRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnCommandQueueSynchronizeCb_t pfnSynchronizeCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.CommandQueue.pfnSynchronizeCb = pfnSynchronizeCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerCommandListCreateRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnCommandListCreateCb_t pfnCreateCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.CommandList.pfnCreateCb = pfnCreateCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerCommandListCreateImmediateRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnCommandListCreateImmediateCb_t pfnCreateImmediateCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.CommandList.pfnCreateImmediateCb = pfnCreateImmediateCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerCommandListDestroyRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnCommandListDestroyCb_t pfnDestroyCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.CommandList.pfnDestroyCb = pfnDestroyCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerCommandListCloseRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnCommandListCloseCb_t pfnCloseCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.CommandList.pfnCloseCb = pfnCloseCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerCommandListResetRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnCommandListResetCb_t pfnResetCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.CommandList.pfnResetCb = pfnResetCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerCommandListAppendWriteGlobalTimestampRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnCommandListAppendWriteGlobalTimestampCb_t pfnAppendWriteGlobalTimestampCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.CommandList.pfnAppendWriteGlobalTimestampCb = pfnAppendWriteGlobalTimestampCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerCommandListAppendBarrierRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnCommandListAppendBarrierCb_t pfnAppendBarrierCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.CommandList.pfnAppendBarrierCb = pfnAppendBarrierCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerCommandListAppendMemoryRangesBarrierRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnCommandListAppendMemoryRangesBarrierCb_t pfnAppendMemoryRangesBarrierCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.CommandList.pfnAppendMemoryRangesBarrierCb = pfnAppendMemoryRangesBarrierCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerContextSystemBarrierRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnContextSystemBarrierCb_t pfnSystemBarrierCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Context.pfnSystemBarrierCb = pfnSystemBarrierCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerCommandListAppendMemoryCopyRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnCommandListAppendMemoryCopyCb_t pfnAppendMemoryCopyCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.CommandList.pfnAppendMemoryCopyCb = pfnAppendMemoryCopyCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerCommandListAppendMemoryFillRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnCommandListAppendMemoryFillCb_t pfnAppendMemoryFillCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.CommandList.pfnAppendMemoryFillCb = pfnAppendMemoryFillCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerCommandListAppendMemoryCopyRegionRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnCommandListAppendMemoryCopyRegionCb_t pfnAppendMemoryCopyRegionCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.CommandList.pfnAppendMemoryCopyRegionCb = pfnAppendMemoryCopyRegionCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerCommandListAppendMemoryCopyFromContextRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnCommandListAppendMemoryCopyFromContextCb_t pfnAppendMemoryCopyFromContextCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.CommandList.pfnAppendMemoryCopyFromContextCb = pfnAppendMemoryCopyFromContextCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerCommandListAppendImageCopyRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnCommandListAppendImageCopyCb_t pfnAppendImageCopyCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.CommandList.pfnAppendImageCopyCb = pfnAppendImageCopyCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerCommandListAppendImageCopyRegionRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnCommandListAppendImageCopyRegionCb_t pfnAppendImageCopyRegionCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.CommandList.pfnAppendImageCopyRegionCb = pfnAppendImageCopyRegionCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerCommandListAppendImageCopyToMemoryRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnCommandListAppendImageCopyToMemoryCb_t pfnAppendImageCopyToMemoryCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.CommandList.pfnAppendImageCopyToMemoryCb = pfnAppendImageCopyToMemoryCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerCommandListAppendImageCopyFromMemoryRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnCommandListAppendImageCopyFromMemoryCb_t pfnAppendImageCopyFromMemoryCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.CommandList.pfnAppendImageCopyFromMemoryCb = pfnAppendImageCopyFromMemoryCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerCommandListAppendMemoryPrefetchRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnCommandListAppendMemoryPrefetchCb_t pfnAppendMemoryPrefetchCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.CommandList.pfnAppendMemoryPrefetchCb = pfnAppendMemoryPrefetchCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerCommandListAppendMemAdviseRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnCommandListAppendMemAdviseCb_t pfnAppendMemAdviseCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.CommandList.pfnAppendMemAdviseCb = pfnAppendMemAdviseCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerEventPoolCreateRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnEventPoolCreateCb_t pfnCreateCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.EventPool.pfnCreateCb = pfnCreateCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerEventPoolDestroyRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnEventPoolDestroyCb_t pfnDestroyCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.EventPool.pfnDestroyCb = pfnDestroyCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerEventCreateRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnEventCreateCb_t pfnCreateCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Event.pfnCreateCb = pfnCreateCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerEventDestroyRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnEventDestroyCb_t pfnDestroyCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Event.pfnDestroyCb = pfnDestroyCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerEventPoolGetIpcHandleRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnEventPoolGetIpcHandleCb_t pfnGetIpcHandleCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.EventPool.pfnGetIpcHandleCb = pfnGetIpcHandleCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerEventPoolOpenIpcHandleRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnEventPoolOpenIpcHandleCb_t pfnOpenIpcHandleCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.EventPool.pfnOpenIpcHandleCb = pfnOpenIpcHandleCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerEventPoolCloseIpcHandleRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnEventPoolCloseIpcHandleCb_t pfnCloseIpcHandleCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.EventPool.pfnCloseIpcHandleCb = pfnCloseIpcHandleCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerCommandListAppendSignalEventRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnCommandListAppendSignalEventCb_t pfnAppendSignalEventCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.CommandList.pfnAppendSignalEventCb = pfnAppendSignalEventCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerCommandListAppendWaitOnEventsRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnCommandListAppendWaitOnEventsCb_t pfnAppendWaitOnEventsCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.CommandList.pfnAppendWaitOnEventsCb = pfnAppendWaitOnEventsCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerEventHostSignalRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnEventHostSignalCb_t pfnHostSignalCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Event.pfnHostSignalCb = pfnHostSignalCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerEventHostSynchronizeRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnEventHostSynchronizeCb_t pfnHostSynchronizeCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Event.pfnHostSynchronizeCb = pfnHostSynchronizeCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerEventQueryStatusRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnEventQueryStatusCb_t pfnQueryStatusCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Event.pfnQueryStatusCb = pfnQueryStatusCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerCommandListAppendEventResetRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnCommandListAppendEventResetCb_t pfnAppendEventResetCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.CommandList.pfnAppendEventResetCb = pfnAppendEventResetCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerEventHostResetRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnEventHostResetCb_t pfnHostResetCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Event.pfnHostResetCb = pfnHostResetCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerEventQueryKernelTimestampRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnEventQueryKernelTimestampCb_t pfnQueryKernelTimestampCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Event.pfnQueryKernelTimestampCb = pfnQueryKernelTimestampCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerCommandListAppendQueryKernelTimestampsRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnCommandListAppendQueryKernelTimestampsCb_t pfnAppendQueryKernelTimestampsCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.CommandList.pfnAppendQueryKernelTimestampsCb = pfnAppendQueryKernelTimestampsCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerFenceCreateRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnFenceCreateCb_t pfnCreateCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Fence.pfnCreateCb = pfnCreateCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerFenceDestroyRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnFenceDestroyCb_t pfnDestroyCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Fence.pfnDestroyCb = pfnDestroyCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerFenceHostSynchronizeRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnFenceHostSynchronizeCb_t pfnHostSynchronizeCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Fence.pfnHostSynchronizeCb = pfnHostSynchronizeCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerFenceQueryStatusRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnFenceQueryStatusCb_t pfnQueryStatusCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Fence.pfnQueryStatusCb = pfnQueryStatusCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerFenceResetRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnFenceResetCb_t pfnResetCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Fence.pfnResetCb = pfnResetCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerImageGetPropertiesRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnImageGetPropertiesCb_t pfnGetPropertiesCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Image.pfnGetPropertiesCb = pfnGetPropertiesCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerImageCreateRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnImageCreateCb_t pfnCreateCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Image.pfnCreateCb = pfnCreateCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerImageDestroyRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnImageDestroyCb_t pfnDestroyCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Image.pfnDestroyCb = pfnDestroyCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerMemAllocSharedRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnMemAllocSharedCb_t pfnAllocSharedCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Mem.pfnAllocSharedCb = pfnAllocSharedCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerMemAllocDeviceRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnMemAllocDeviceCb_t pfnAllocDeviceCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Mem.pfnAllocDeviceCb = pfnAllocDeviceCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerMemAllocHostRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnMemAllocHostCb_t pfnAllocHostCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Mem.pfnAllocHostCb = pfnAllocHostCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerMemFreeRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnMemFreeCb_t pfnFreeCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Mem.pfnFreeCb = pfnFreeCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerMemGetAllocPropertiesRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnMemGetAllocPropertiesCb_t pfnGetAllocPropertiesCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Mem.pfnGetAllocPropertiesCb = pfnGetAllocPropertiesCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerMemGetAddressRangeRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnMemGetAddressRangeCb_t pfnGetAddressRangeCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Mem.pfnGetAddressRangeCb = pfnGetAddressRangeCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerMemGetIpcHandleRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnMemGetIpcHandleCb_t pfnGetIpcHandleCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Mem.pfnGetIpcHandleCb = pfnGetIpcHandleCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerMemOpenIpcHandleRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnMemOpenIpcHandleCb_t pfnOpenIpcHandleCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Mem.pfnOpenIpcHandleCb = pfnOpenIpcHandleCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerMemCloseIpcHandleRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnMemCloseIpcHandleCb_t pfnCloseIpcHandleCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Mem.pfnCloseIpcHandleCb = pfnCloseIpcHandleCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerModuleCreateRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnModuleCreateCb_t pfnCreateCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Module.pfnCreateCb = pfnCreateCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerModuleDestroyRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnModuleDestroyCb_t pfnDestroyCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Module.pfnDestroyCb = pfnDestroyCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerModuleDynamicLinkRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnModuleDynamicLinkCb_t pfnDynamicLinkCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Module.pfnDynamicLinkCb = pfnDynamicLinkCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerModuleBuildLogDestroyRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnModuleBuildLogDestroyCb_t pfnDestroyCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.ModuleBuildLog.pfnDestroyCb = pfnDestroyCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerModuleBuildLogGetStringRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnModuleBuildLogGetStringCb_t pfnGetStringCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.ModuleBuildLog.pfnGetStringCb = pfnGetStringCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerModuleGetNativeBinaryRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnModuleGetNativeBinaryCb_t pfnGetNativeBinaryCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Module.pfnGetNativeBinaryCb = pfnGetNativeBinaryCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerModuleGetGlobalPointerRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnModuleGetGlobalPointerCb_t pfnGetGlobalPointerCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Module.pfnGetGlobalPointerCb = pfnGetGlobalPointerCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerModuleGetKernelNamesRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnModuleGetKernelNamesCb_t pfnGetKernelNamesCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Module.pfnGetKernelNamesCb = pfnGetKernelNamesCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerModuleGetPropertiesRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnModuleGetPropertiesCb_t pfnGetPropertiesCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Module.pfnGetPropertiesCb = pfnGetPropertiesCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerKernelCreateRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnKernelCreateCb_t pfnCreateCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Kernel.pfnCreateCb = pfnCreateCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerKernelDestroyRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnKernelDestroyCb_t pfnDestroyCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Kernel.pfnDestroyCb = pfnDestroyCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerModuleGetFunctionPointerRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnModuleGetFunctionPointerCb_t pfnGetFunctionPointerCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Module.pfnGetFunctionPointerCb = pfnGetFunctionPointerCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerKernelSetGroupSizeRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnKernelSetGroupSizeCb_t pfnSetGroupSizeCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Kernel.pfnSetGroupSizeCb = pfnSetGroupSizeCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerKernelSuggestGroupSizeRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnKernelSuggestGroupSizeCb_t pfnSuggestGroupSizeCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Kernel.pfnSuggestGroupSizeCb = pfnSuggestGroupSizeCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerKernelSuggestMaxCooperativeGroupCountRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnKernelSuggestMaxCooperativeGroupCountCb_t pfnSuggestMaxCooperativeGroupCountCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Kernel.pfnSuggestMaxCooperativeGroupCountCb = pfnSuggestMaxCooperativeGroupCountCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerKernelSetArgumentValueRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnKernelSetArgumentValueCb_t pfnSetArgumentValueCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Kernel.pfnSetArgumentValueCb = pfnSetArgumentValueCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerKernelSetIndirectAccessRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnKernelSetIndirectAccessCb_t pfnSetIndirectAccessCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Kernel.pfnSetIndirectAccessCb = pfnSetIndirectAccessCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerKernelGetIndirectAccessRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnKernelGetIndirectAccessCb_t pfnGetIndirectAccessCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Kernel.pfnGetIndirectAccessCb = pfnGetIndirectAccessCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerKernelGetSourceAttributesRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnKernelGetSourceAttributesCb_t pfnGetSourceAttributesCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Kernel.pfnGetSourceAttributesCb = pfnGetSourceAttributesCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerKernelSetCacheConfigRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnKernelSetCacheConfigCb_t pfnSetCacheConfigCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Kernel.pfnSetCacheConfigCb = pfnSetCacheConfigCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerKernelGetPropertiesRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnKernelGetPropertiesCb_t pfnGetPropertiesCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Kernel.pfnGetPropertiesCb = pfnGetPropertiesCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerKernelGetNameRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnKernelGetNameCb_t pfnGetNameCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Kernel.pfnGetNameCb = pfnGetNameCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerCommandListAppendLaunchKernelRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnCommandListAppendLaunchKernelCb_t pfnAppendLaunchKernelCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.CommandList.pfnAppendLaunchKernelCb = pfnAppendLaunchKernelCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerCommandListAppendLaunchCooperativeKernelRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnCommandListAppendLaunchCooperativeKernelCb_t pfnAppendLaunchCooperativeKernelCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.CommandList.pfnAppendLaunchCooperativeKernelCb = pfnAppendLaunchCooperativeKernelCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerCommandListAppendLaunchKernelIndirectRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnCommandListAppendLaunchKernelIndirectCb_t pfnAppendLaunchKernelIndirectCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.CommandList.pfnAppendLaunchKernelIndirectCb = pfnAppendLaunchKernelIndirectCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerCommandListAppendLaunchMultipleKernelsIndirectRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnCommandListAppendLaunchMultipleKernelsIndirectCb_t pfnAppendLaunchMultipleKernelsIndirectCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.CommandList.pfnAppendLaunchMultipleKernelsIndirectCb = pfnAppendLaunchMultipleKernelsIndirectCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerContextMakeMemoryResidentRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnContextMakeMemoryResidentCb_t pfnMakeMemoryResidentCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Context.pfnMakeMemoryResidentCb = pfnMakeMemoryResidentCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerContextEvictMemoryRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnContextEvictMemoryCb_t pfnEvictMemoryCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Context.pfnEvictMemoryCb = pfnEvictMemoryCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerContextMakeImageResidentRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnContextMakeImageResidentCb_t pfnMakeImageResidentCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Context.pfnMakeImageResidentCb = pfnMakeImageResidentCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerContextEvictImageRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnContextEvictImageCb_t pfnEvictImageCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Context.pfnEvictImageCb = pfnEvictImageCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerSamplerCreateRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnSamplerCreateCb_t pfnCreateCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Sampler.pfnCreateCb = pfnCreateCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerSamplerDestroyRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnSamplerDestroyCb_t pfnDestroyCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Sampler.pfnDestroyCb = pfnDestroyCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerVirtualMemReserveRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnVirtualMemReserveCb_t pfnReserveCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.VirtualMem.pfnReserveCb = pfnReserveCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerVirtualMemFreeRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnVirtualMemFreeCb_t pfnFreeCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.VirtualMem.pfnFreeCb = pfnFreeCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerVirtualMemQueryPageSizeRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnVirtualMemQueryPageSizeCb_t pfnQueryPageSizeCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.VirtualMem.pfnQueryPageSizeCb = pfnQueryPageSizeCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerPhysicalMemCreateRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnPhysicalMemCreateCb_t pfnCreateCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.PhysicalMem.pfnCreateCb = pfnCreateCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerPhysicalMemDestroyRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnPhysicalMemDestroyCb_t pfnDestroyCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.PhysicalMem.pfnDestroyCb = pfnDestroyCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerVirtualMemMapRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnVirtualMemMapCb_t pfnMapCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.VirtualMem.pfnMapCb = pfnMapCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerVirtualMemUnmapRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnVirtualMemUnmapCb_t pfnUnmapCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.VirtualMem.pfnUnmapCb = pfnUnmapCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerVirtualMemSetAccessAttributeRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnVirtualMemSetAccessAttributeCb_t pfnSetAccessAttributeCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.VirtualMem.pfnSetAccessAttributeCb = pfnSetAccessAttributeCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerVirtualMemGetAccessAttributeRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnVirtualMemGetAccessAttributeCb_t pfnGetAccessAttributeCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.VirtualMem.pfnGetAccessAttributeCb = pfnGetAccessAttributeCb;

    return result;
}


ZE_DLLEXPORT ze_result_t ZE_APICALL
zelTracerKernelSetGlobalOffsetExpRegisterCallback(
    zel_tracer_handle_t hTracer,
    zel_tracer_reg_t callback_type,
    ze_pfnKernelSetGlobalOffsetExpCb_t pfnSetGlobalOffsetExpCb
    ) {

    ze_result_t result;
    auto& cbs = tracing_layer::APITracer::fromHandle(hTracer)->getProEpilogues(callback_type, result);
    if (result == ZE_RESULT_SUCCESS)
        cbs.Kernel.pfnSetGlobalOffsetExpCb = pfnSetGlobalOffsetExpCb;

    return result;
}



} //extern C