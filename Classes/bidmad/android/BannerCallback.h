#ifndef PROJ_ANDROID_BANNERCALLBACK_H
#define PROJ_ANDROID_BANNERCALLBACK_H

#include "platform/android/jni/JniHelper.h"

class BannerCallback{
public:
    void (*onLoadCallback) (char *) = nullptr;
    void (*onFailCallback) (char *, char*) = nullptr;

    void setOnLoadCallback(void (*_onLoadCallback) (char *));
    void setOnFailCallback(void (*_onFailCallback) (char *, char*));
};

extern "C"{
    JNIEXPORT void JNICALL Java_ad_helper_openbidding_adview_Cocos2dxAdView_onLoadAdCb(JNIEnv *, jobject, jstring);
    JNIEXPORT void JNICALL Java_ad_helper_openbidding_adview_Cocos2dxAdView_onLoadFailAdCb(JNIEnv *, jobject, jstring, jstring);
}
#endif //PROJ_ANDROID_BANNERCALLBACK_H
