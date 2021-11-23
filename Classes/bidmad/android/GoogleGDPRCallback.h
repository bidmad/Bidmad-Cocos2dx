#ifndef PROJ_ANDROID_GOOGLEGDPRCALLBACK_H
#define PROJ_ANDROID_GOOGLEGDPRCALLBACK_H

#include "platform/android/jni/JniHelper.h"

class GoogleGDPRCallback{
public:
    void (*onConsentInfoUpdateSuccessCallback) () = nullptr;
    void (*onConsentInfoUpdateFailureCallback) (char *) = nullptr;
    void (*onConsentFormLoadSuccessCallback) () = nullptr;
    void (*onConsentFormLoadFailureCallback) (char *) = nullptr;
    void (*onConsentFormDismissedCallback) (char *) = nullptr;

    void setOnConsentInfoUpdateSuccessCallback(void (*_onConsentInfoUpdateSuccessCallback) ());
    void setOnConsentInfoUpdateFailureCallback(void (*_onConsentInfoUpdateFailureCallback) (char *));
    void setOnConsentFormLoadSuccessCallback(void (*_onConsentFormLoadSuccessCallback) ());
    void setOnConsentFormLoadFailureCallback(void (*_onConsentFormLoadFailureCallback) (char *));
    void setOnConsentFormDismissedCallback(void (*_onConsentFormDismissedCallback) (char *));
};

extern "C"{
    JNIEXPORT void JNICALL Java_com_adop_sdk_userinfo_consent_GoogleGDPRConsent_onConsentInfoUpdateSuccessCb(JNIEnv *, jobject);
    JNIEXPORT void JNICALL Java_com_adop_sdk_userinfo_consent_GoogleGDPRConsent_onConsentInfoUpdateFailureCb(JNIEnv *, jobject, jstring);
    JNIEXPORT void JNICALL Java_com_adop_sdk_userinfo_consent_GoogleGDPRConsent_onConsentFormLoadSuccessCb(JNIEnv *, jobject);
    JNIEXPORT void JNICALL Java_com_adop_sdk_userinfo_consent_GoogleGDPRConsent_onConsentFormLoadFailureCb(JNIEnv *, jobject, jstring);
    JNIEXPORT void JNICALL Java_com_adop_sdk_userinfo_consent_GoogleGDPRConsent_onConsentFormDismissedCb(JNIEnv *, jobject, jstring);
}
#endif //PROJ_ANDROID_GOOGLEGDPRCALLBACK_H
