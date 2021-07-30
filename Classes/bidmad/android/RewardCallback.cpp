//
// Created by Kenneth on 2020/08/10.
//

#include "RewardCallback.h"
#include "RewardController.h"
#include <map>

#define LOG_TAG "bidmad"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)

void RewardCallback::setOnLoadCallback(void (*_onLoadCallback) (char *)) {
    onLoadCallback = _onLoadCallback;
}

void RewardCallback::setOnShowCallback(void (*_onShowCallback) (char *)) {
    onShowCallback = _onShowCallback;
}

void RewardCallback::setOnFailCallback(void (*_onFailCallback) (char *)) {
    onFailCallback = _onFailCallback;
}

void RewardCallback::setOnCompleteCallback(void (*_onCompleteCallback) (char *)) {
    onCompleteCallback = _onCompleteCallback;
}

void RewardCallback::setOnSkipCallback(void (*_onSkipCallback) (char *)) {
    onSkipCallback = _onSkipCallback;
}

void RewardCallback::setOnCloseCallback(void (*_onCloseCallback) (char *)) {
    onCloseCallback = _onCloseCallback;
}

extern "C"{
    JNIEXPORT void JNICALL Java_com_adop_sdk_reward_Cocos2dxReward_onLoadAdCb(JNIEnv *env, jobject obj, jstring str){
        LOGD("Java_com_adop_sdk_reward_Cocos2dxReward_onLoadAdCb");

        const char *zoneId = env->GetStringUTFChars(str, NULL);

        RewardController::callCallback("onLoad", (char *)zoneId);

        env->ReleaseStringUTFChars(str, zoneId);
    }

    JNIEXPORT void JNICALL Java_com_adop_sdk_reward_Cocos2dxReward_onShowAdCb(JNIEnv *env, jobject obj, jstring str){
        LOGD("Java_com_adop_sdk_reward_Cocos2dxReward_onShowAdCb");

        const char *zoneId = env->GetStringUTFChars(str, NULL);

        RewardController::callCallback("onShow", (char *)zoneId);

        env->ReleaseStringUTFChars(str, zoneId);
    }

    JNIEXPORT void JNICALL Java_com_adop_sdk_reward_Cocos2dxReward_onFailedAdCb(JNIEnv *env, jobject obj, jstring str){
        LOGD("Java_com_adop_sdk_reward_Cocos2dxReward_onFailedAdCb");

        const char *zoneId = env->GetStringUTFChars(str, NULL);

        RewardController::callCallback("onFail", (char *)zoneId);

        env->ReleaseStringUTFChars(str, zoneId);
    }

    JNIEXPORT void JNICALL Java_com_adop_sdk_reward_Cocos2dxReward_onCompleteAdCb(JNIEnv *env, jobject obj, jstring str){
        LOGD("Java_com_adop_sdk_reward_Cocos2dxReward_onCompleteAdCb");

        const char *zoneId = env->GetStringUTFChars(str, NULL);

        RewardController::callCallback("onComplete", (char *)zoneId);

        env->ReleaseStringUTFChars(str, zoneId);
    }

    JNIEXPORT void JNICALL Java_com_adop_sdk_reward_Cocos2dxReward_onCloseAdCb(JNIEnv *env, jobject obj, jstring str){
        LOGD("Java_com_adop_sdk_reward_Cocos2dxReward_onCloseAdCb");

        const char *zoneId = env->GetStringUTFChars(str, NULL);

        RewardController::callCallback("onClose", (char *)zoneId);

        env->ReleaseStringUTFChars(str, zoneId);
    }

    JNIEXPORT void JNICALL Java_com_adop_sdk_reward_Cocos2dxReward_onSkippedAdCb(JNIEnv *env, jobject obj, jstring str){
        LOGD("Java_com_adop_sdk_reward_Cocos2dxReward_onSkippedAdCb");

        const char *zoneId = env->GetStringUTFChars(str, NULL);

        RewardController::callCallback("onSkip", (char *)zoneId);

        env->ReleaseStringUTFChars(str, zoneId);
    }
}