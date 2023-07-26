//
// Created by Kenneth on 2020/08/07.
//

#ifndef PROJ_ANDROID_INTERSTITIALCALLBACK_H
#define PROJ_ANDROID_INTERSTITIALCALLBACK_H

#include "platform/android/jni/JniHelper.h"

class InterstitialCallback{
public:
    void (*onLoadCallback) (char *) = nullptr;
    void (*onShowCallback) (char *) = nullptr;
    void (*onFailCallback) (char *, char *) = nullptr;
    void (*onCloseCallback) (char *) = nullptr;

    void setOnLoadCallback(void (*_onLoadCallback) (char *));
    void setOnShowCallback(void (*_onShowCallback) (char *));
    void setOnFailCallback(void (*_onFailCallback) (char *, char *));
    void setOnCloseCallback(void (*_onCloseCallback) (char *));
};

extern "C"{
    JNIEXPORT void JNICALL Java_ad_helper_openbidding_interstitial_Cocos2dxInterstitial_onLoadAdCb(JNIEnv *, jobject, jstring);
    JNIEXPORT void JNICALL Java_ad_helper_openbidding_interstitial_Cocos2dxInterstitial_onShowAdCb(JNIEnv *, jobject, jstring);
    JNIEXPORT void JNICALL Java_ad_helper_openbidding_interstitial_Cocos2dxInterstitial_onLoadFailAdCb(JNIEnv *, jobject, jstring, jstring);
    JNIEXPORT void JNICALL Java_ad_helper_openbidding_interstitial_Cocos2dxInterstitial_onCloseAdCb(JNIEnv *, jobject, jstring);
}
#endif //PROJ_ANDROID_INTERSTITIALCALLBACK_H
