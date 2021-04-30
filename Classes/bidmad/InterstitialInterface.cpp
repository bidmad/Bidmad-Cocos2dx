//
// Created by Kenneth on 2020/08/07.
//

#include "InterstitialInterface.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#define LOG_TAG "bidmad"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#endif

InterstitialInterface::InterstitialInterface(char* zoneId){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    interstitial = new InterstitialBridgeCpp(zoneId);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    interstitial = new InterstitialController(zoneId);
    interstitial->setActivity();
    interstitial->makeInterstitial();
    interstitial->setAdInfo(zoneId);
#endif
}

void InterstitialInterface::load(){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    interstitial->loadInterstitial();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    interstitial->load();
#endif
}

void InterstitialInterface::show(){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    interstitial->showInterstitial();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    interstitial->show();
#endif
}


bool InterstitialInterface::isLoaded(){
    bool result = false;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    result = interstitial->isLoaded();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    result = interstitial->isLoaded();
#endif
    return result;
}

void InterstitialInterface::setOnLoadCallback(void (*_onLoadCallback) (char *)){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    interstitial->setOnLoadCallback(_onLoadCallback);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    interstitial->callback->setOnLoadCallback(_onLoadCallback);
#endif
}
void InterstitialInterface::setOnShowCallback(void (*_onShowCallback) (char *)){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    interstitial->setOnShowCallback(_onShowCallback);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    interstitial->callback->setOnShowCallback(_onShowCallback);
#endif
}
void InterstitialInterface::setOnFailCallback(void (*_onFailCallback) (char *)){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    interstitial->setOnFailCallback(_onFailCallback);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    interstitial->callback->setOnFailCallback(_onFailCallback);
#endif
}
void InterstitialInterface::setOnCloseCallback(void (*_onCloseCallback)(char *)){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    interstitial->setOnCloseCallback(_onCloseCallback);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    interstitial->callback->setOnCloseCallback(_onCloseCallback);
#endif
}
