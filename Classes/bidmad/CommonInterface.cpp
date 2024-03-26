//
// Created by Kenneth on 2020/08/07.
//

#include "CommonInterface.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#define LOG_TAG "bidmad"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#endif

char* CommonInterface::pluginVersion = "2.3.0";

void CommonInterface::setDebugMode(bool isDebug){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    CommonBridgeCpp::setDebugMode(isDebug);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    CommonController::setDebugging(isDebug);
#endif
}

void CommonInterface::setAdvertiserTrackingEnabled(bool enable){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    CommonBridgeCpp::setAdvertiserTrackingEnabled(enable);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#endif
}


bool CommonInterface::getAdvertiserTrackingEnabled(){
    bool result = false;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    result = CommonBridgeCpp::getAdvertiserTrackingEnabled();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#endif
    return result;
}

void CommonInterface::reqAdTrackingAuthorization(void (*_onAdTrackingAuthorizationResponse) (int)){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    CommonBridgeCpp::reqAdTrackingAuthorization(_onAdTrackingAuthorizationResponse);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#endif
}
void CommonInterface::setGoogleTestId(char * testDeviceId){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    CommonBridgeCpp::setGoogleTestId(testDeviceId);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    CommonController::setGgTestDeviceid(testDeviceId);
#endif
}

void CommonInterface::setGdprConsent(bool consent, bool useArea) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    CommonBridgeCpp::setGdprConsent(consent, useArea);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    CommonController::setGdprConsent(consent, useArea);
#endif
}

int CommonInterface::getGdprConsent(bool useArea) {
    int result = useArea ? -1 : -2;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    result = CommonBridgeCpp::getGdprConsent(useArea);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    result = CommonController::getGdprConsent(useArea);
#endif
    return result;
}

const char* CommonInterface::getPRIVACYURL() {
    const char* result = "";
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    result = CommonBridgeCpp::getPRIVACYURL();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    result = CommonController::getPRIVACYURL();
#endif
    return result;
}

void CommonInterface::setCUID(char* id){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    CommonBridgeCpp::setCUID(id);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    CommonController::setCUID(id);
#endif
    return;
}

void CommonInterface::initializeSdk(char *appKey) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    CommonBridgeCpp::initializeSdk(appKey);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    CommonController::initializeSdk(appKey);
#endif
    return;
}

void CommonInterface::initializeSdkWithCallback(char *appKey, void (*_onInitialized) (bool)) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    CommonBridgeCpp::setInitializeCallback(_onInitialized);
    CommonBridgeCpp::initializeSdkWithCallback(appKey);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    CommonController::initializeSdkWithCallback(appKey, _onInitialized);
#endif
    return;
}

void CommonInterface::setAdFreeEventCallback(void (*_onAdFree) (bool)) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    CommonBridgeCpp::setAdFreeEventCallback(_onAdFree);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    CommonController::setAdFreeEventCallback(_onAdFree);
#endif
    return;
}

bool CommonInterface::isAdFree() {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    return CommonBridgeCpp::isAdFree();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    return CommonController::isAdFree();
#endif
}
