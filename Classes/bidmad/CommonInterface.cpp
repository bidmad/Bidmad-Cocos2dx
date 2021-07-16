//
// Created by Kenneth on 2020/08/07.
//

#include "CommonInterface.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#define LOG_TAG "bidmad"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#endif

char* CommonInterface::pluginVersion = "1.2.1";

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
