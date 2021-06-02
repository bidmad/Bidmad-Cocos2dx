#ifndef PROJ_ANDROID_BANNERCALLBACK_H
#define PROJ_ANDROID_BANNERCALLBACK_H

#include "platform/android/jni/JniHelper.h"

class BannerCallback{
public:
    void (*onLoadCallback) (char *) = nullptr;
    void (*onFailCallback) (char *) = nullptr;

    void setOnLoadCallback(void (*_onLoadCallback) (char *));
    void setOnFailCallback(void (*_onFailCallback) (char *));
};

extern "C"{
    JNIEXPORT void JNICALL Java_com_adop_sdk_adview_Cocos2dxAdView_onLoadAdCb(JNIEnv *, jobject, jstring);
    JNIEXPORT void JNICALL Java_com_adop_sdk_adview_Cocos2dxAdView_onFailedAdCb(JNIEnv *, jobject, jstring);
}
#endif //PROJ_ANDROID_BANNERCALLBACK_H
