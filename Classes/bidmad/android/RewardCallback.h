//
// Created by Kenneth on 2020/08/07.
//

#ifndef PROJ_ANDROID_REWARDCALLBACK_H
#define PROJ_ANDROID_REWARDCALLBACK_H

#include "platform/android/jni/JniHelper.h"

class RewardCallback{
public:
    void (*onLoadCallback) (char *) = nullptr;
    void (*onShowCallback) (char *) = nullptr;
    void (*onFailCallback) (char *, char *) = nullptr;
    void (*onCompleteCallback) (char *) = nullptr;
    void (*onSkipCallback) (char *) = nullptr;
    void (*onCloseCallback) (char *) = nullptr;

    void setOnLoadCallback(void (*_onLoadCallback) (char *));
    void setOnShowCallback(void (*_onShowCallback) (char *));
    void setOnFailCallback(void (*_onFailCallback) (char *, char *));
    void setOnCompleteCallback(void (*_onCompleteCallback) (char *));
    void setOnSkipCallback(void (*_onSkipCallback) (char *));
    void setOnCloseCallback(void (*_onCloseCallback) (char *));
};

extern "C"{
    JNIEXPORT void JNICALL Java_ad_helper_openbidding_reward_Cocos2dxReward_onLoadAdCb(JNIEnv *, jobject, jstring);
    JNIEXPORT void JNICALL Java_ad_helper_openbidding_reward_Cocos2dxReward_onShowAdCb(JNIEnv *, jobject, jstring);
    JNIEXPORT void JNICALL Java_ad_helper_openbidding_reward_Cocos2dxReward_onLoadFailAdCb(JNIEnv *, jobject, jstring, jstring);
    JNIEXPORT void JNICALL Java_ad_helper_openbidding_reward_Cocos2dxReward_onCompleteAdCb(JNIEnv *, jobject, jstring);
    JNIEXPORT void JNICALL Java_ad_helper_openbidding_reward_Cocos2dxReward_onCloseAdCb(JNIEnv *, jobject, jstring);
    JNIEXPORT void JNICALL Java_ad_helper_openbidding_reward_Cocos2dxReward_onSkipAdCb(JNIEnv *, jobject, jstring);
}
#endif //PROJ_ANDROID_REWARDCALLBACK_H
