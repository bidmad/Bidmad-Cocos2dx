//
// Created by Kenneth on 2020/08/10.
//

#include "InterstitialCallback.h"
#include "InterstitialController.h"
#include <map>

#define LOG_TAG "bidmad"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)

void InterstitialCallback::setOnLoadCallback(void (*_onLoadCallback) (char *)) {
    onLoadCallback = _onLoadCallback;
}

void InterstitialCallback::setOnShowCallback(void (*_onShowCallback) (char *)) {
    onShowCallback = _onShowCallback;
}

void InterstitialCallback::setOnFailCallback(void (*_onFailCallback) (char *, char *)) {
    onFailCallback = _onFailCallback;
}

void InterstitialCallback::setOnCloseCallback(void (*_onCloseCallback) (char *)) {
    onCloseCallback = _onCloseCallback;
}

extern "C"{
    JNIEXPORT void JNICALL Java_ad_helper_openbidding_interstitial_Cocos2dxInterstitial_onLoadAdCb(JNIEnv *env, jobject obj, jstring str){
        LOGD("Java_ad_helper_openbidding_interstitial_Cocos2dxInterstitial_onLoadAdCb");

        const char *zoneId = env->GetStringUTFChars(str, NULL);

        InterstitialController::callCallback("onLoad", (char *)zoneId, nullptr);

        env->ReleaseStringUTFChars(str, zoneId);
    }

    JNIEXPORT void JNICALL Java_ad_helper_openbidding_interstitial_Cocos2dxInterstitial_onShowAdCb(JNIEnv *env, jobject obj, jstring str){
        LOGD("Java_ad_helper_openbidding_interstitial_Cocos2dxInterstitial_onShowAdCb");

        const char *zoneId = env->GetStringUTFChars(str, NULL);

        InterstitialController::callCallback("onShow", (char *)zoneId, nullptr);

        env->ReleaseStringUTFChars(str, zoneId);
    }

    JNIEXPORT void JNICALL Java_ad_helper_openbidding_interstitial_Cocos2dxInterstitial_onFailedAdCb(JNIEnv *env, jobject obj, jstring str, jstring error){
        LOGD("Java_ad_helper_openbidding_interstitial_Cocos2dxInterstitial_onFailedAdCb");

        const char *zoneId = env->GetStringUTFChars(str, NULL);
        const char *errorInfo = env->GetStringUTFChars(error, NULL);

        InterstitialController::callCallback("onFail", (char *)zoneId, (char *)errorInfo);

        env->ReleaseStringUTFChars(str, zoneId);
        env->ReleaseStringUTFChars(error, errorInfo);
    }

    JNIEXPORT void JNICALL Java_ad_helper_openbidding_interstitial_Cocos2dxInterstitial_onCloseAdCb(JNIEnv *env, jobject obj, jstring str){
        LOGD("Java_ad_helper_openbidding_interstitial_Cocos2dxInterstitial_onCloseAdCb");

        const char *zoneId = env->GetStringUTFChars(str, NULL);

        InterstitialController::callCallback("onClose", (char *)zoneId, nullptr);

        env->ReleaseStringUTFChars(str, zoneId);
    }
}