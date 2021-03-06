//
// Created by Kenneth on 2020/08/10.
//

#include "BannerCallback.h"
#include "BannerController.h"
#include <map>

#define LOG_TAG "bidmad"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)

void BannerCallback::setOnLoadCallback(void (*_onLoadCallback) (char *)) {
    onLoadCallback = _onLoadCallback;
}

void BannerCallback::setOnFailCallback(void (*_onFailCallback) (char *)) {
    onFailCallback = _onFailCallback;
}

extern "C"{
    JNIEXPORT void JNICALL Java_ad_helper_openbidding_adview_Cocos2dxAdView_onLoadAdCb(JNIEnv *env, jobject obj, jstring str){
        LOGD("Java_ad_helper_openbidding_adview_Cocos2dxAdView_onLoadAdCb");

        const char *zoneId = env->GetStringUTFChars(str, NULL);

        BannerController::callCallback("onLoad", (char *)zoneId);

        env->ReleaseStringUTFChars(str, zoneId);
    }

    JNIEXPORT void JNICALL Java_ad_helper_openbidding_adview_Cocos2dxAdView_onFailedAdCb(JNIEnv *env, jobject obj, jstring str){
        LOGD("Java_ad_helper_openbidding_adview_Cocos2dxAdView_onFailedAdCb");

        const char *zoneId = env->GetStringUTFChars(str, NULL);

        BannerController::callCallback("onFail", (char *)zoneId);

        env->ReleaseStringUTFChars(str, zoneId);
    }
}