//
// Created by Kenneth on 2020/08/07.
//

#include "RewardInterface.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#define LOG_TAG "bidmad"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#endif

RewardInterface::RewardInterface(char* zoneId){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    reward = new RewardBridgeCpp(zoneId);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    reward = new RewardController(zoneId);
    reward->setActivity();
    reward->makeReward();
#endif
}

void RewardInterface::load(){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    reward->loadRewardVideo();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    reward->load();
#endif
}

void RewardInterface::show(){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    reward->showRewardVideo();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    reward->show();
#endif
}


bool RewardInterface::isLoaded(){
    bool result = false;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    result = reward->isLoaded();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    result = reward->isLoaded();
#endif
    return result;
}

void RewardInterface::setAutoReload(bool isAutoReload) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    reward->setAutoReload(isAutoReload);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    reward->setAutoReload(isAutoReload);
#endif
}

void RewardInterface::setOnLoadCallback(void (*_onLoadCallback) (char *)){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    reward->setOnLoadCallback(_onLoadCallback);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    reward->callback->setOnLoadCallback(_onLoadCallback);
#endif
}

void RewardInterface::setOnShowCallback(void (*_onShowCallback) (char *)){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    reward->setOnShowCallback(_onShowCallback);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    reward->callback->setOnShowCallback(_onShowCallback);
#endif
}

void RewardInterface::setOnFailCallback(void (*_onFailCallback) (char *, char *)){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    reward->setOnFailCallback(_onFailCallback);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    reward->callback->setOnFailCallback(_onFailCallback);
#endif
}

void RewardInterface::setOnCompleteCallback(void (*_onCompleteCallback) (char *)){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    reward->setOnCompleteCallback(_onCompleteCallback);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    reward->callback->setOnCompleteCallback(_onCompleteCallback);
#endif
}

void RewardInterface::setOnSkipCallback(void (*_onSkipCallback) (char *)){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    reward->setOnSkipCallback(_onSkipCallback);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    reward->callback->setOnSkipCallback(_onSkipCallback);
#endif
}

void RewardInterface::setOnCloseCallback(void (*_onCloseCallback)(char *)){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    reward->setOnCloseCallback(_onCloseCallback);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    reward->callback->setOnCloseCallback(_onCloseCallback);
#endif
}
