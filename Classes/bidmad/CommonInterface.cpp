//
// Created by Kenneth on 2020/08/07.
//

#include "CommonInterface.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#define LOG_TAG "bidmad"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#endif

char* CommonInterface::pluginVersion = "1.9.0";

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

void CommonInterface::initializeSdk() {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    CommonBridgeCpp::initializeSdk();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    CommonController::initializeSdk();
#endif
    return;
}
