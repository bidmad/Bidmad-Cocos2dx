//
// Created by Kenneth on 2020/08/10.
//

#include "GoogleGDPRCallback.h"
#include "GoogleGDPRController.h"
#include <map>

#define LOG_TAG "bidmad"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)

void GoogleGDPRCallback::setOnConsentInfoUpdateSuccessCallback(void (*_onConsentInfoUpdateSuccessCallback) ()) {
    onConsentInfoUpdateSuccessCallback = _onConsentInfoUpdateSuccessCallback;
}

void GoogleGDPRCallback::setOnConsentInfoUpdateFailureCallback(void (*_onConsentInfoUpdateFailureCallback) (char *)) {
    onConsentInfoUpdateFailureCallback = _onConsentInfoUpdateFailureCallback;
}

void GoogleGDPRCallback::setOnConsentFormLoadSuccessCallback(void (*_onConsentFormLoadSuccessCallback) ()) {
    onConsentFormLoadSuccessCallback = _onConsentFormLoadSuccessCallback;
}

void GoogleGDPRCallback::setOnConsentFormLoadFailureCallback(void (*_onConsentFormLoadFailureCallback) (char *)) {
    onConsentFormLoadFailureCallback = _onConsentFormLoadFailureCallback;
}

void GoogleGDPRCallback::setOnConsentFormDismissedCallback(void (*_onConsentFormDismissedCallback) (char *)) {
    onConsentFormDismissedCallback = _onConsentFormDismissedCallback;
}

extern "C"{
    JNIEXPORT void JNICALL Java_com_adop_sdk_userinfo_consent_GoogleGDPRConsent_onConsentInfoUpdateSuccessCb(JNIEnv *env, jobject obj){
        LOGD("Java_com_adop_sdk_userinfo_consent_GoogleGDPRConcent_onConsentInfoUpdateSuccessCb");

        const char *msg = "";
        GoogleGDPRController::callCallback("onConsentInfoUpdateSuccess", nullptr);
    }
    JNIEXPORT void JNICALL Java_com_adop_sdk_userinfo_consent_GoogleGDPRConsent_onConsentInfoUpdateFailureCb(JNIEnv *env, jobject obj, jstring str){
        LOGD("Java_com_adop_sdk_userinfo_consent_GoogleGDPRConcent_onConsentInfoUpdateFailureCb");

        const char *msg = env->GetStringUTFChars(str, NULL);
        GoogleGDPRController::callCallback("onConsentInfoUpdateFailure", (char *)msg);
        env->ReleaseStringUTFChars(str, msg);
    }
    JNIEXPORT void JNICALL Java_com_adop_sdk_userinfo_consent_GoogleGDPRConsent_onConsentFormLoadSuccessCb(JNIEnv *env, jobject obj){
        LOGD("Java_com_adop_sdk_userinfo_consent_GoogleGDPRConcent_onConsentFormLoadSuccessCb");

        const char *msg = "";
        GoogleGDPRController::callCallback("onConsentFormLoadSuccess", nullptr);
    }
    JNIEXPORT void JNICALL Java_com_adop_sdk_userinfo_consent_GoogleGDPRConsent_onConsentFormLoadFailureCb(JNIEnv *env, jobject obj, jstring str){
        LOGD("Java_com_adop_sdk_userinfo_consent_GoogleGDPRConcent_onConsentFormLoadFailureCb");

        const char *msg = env->GetStringUTFChars(str, NULL);
        GoogleGDPRController::callCallback("onConsentFormLoadFailure", (char *)msg);
        env->ReleaseStringUTFChars(str, msg);
    }
    JNIEXPORT void JNICALL Java_com_adop_sdk_userinfo_consent_GoogleGDPRConsent_onConsentFormDismissedCb(JNIEnv *env, jobject obj, jstring str){
        LOGD("Java_com_adop_sdk_userinfo_consent_GoogleGDPRConcent_onConsentFormDismissedCb");

        const char *msg = env->GetStringUTFChars(str, NULL);
        GoogleGDPRController::callCallback("onConsentFormDismissed", (char *)msg);
        env->ReleaseStringUTFChars(str, msg);
    }
}