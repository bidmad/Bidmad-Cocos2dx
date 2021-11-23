//
// Created by Kenneth on 2020/08/07.
//

#include "GoogleGDPRController.h"

#define LOG_TAG "bidmad"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define coco2dxClass "com.adop.sdk.userinfo.consent.GoogleGDPRConsent"

GoogleGDPRController* GoogleGDPRController::controller = nullptr;
GoogleGDPRCallback* GoogleGDPRController::callback = nullptr;

GoogleGDPRController* GoogleGDPRController::getInstance() {
    if(controller == nullptr){
      controller = new GoogleGDPRController();
      controller->setListener();
      callback = new GoogleGDPRCallback();
    }

    return controller;
}

void GoogleGDPRController::getGoogleGDPRConsentInstance() {
    if (JniHelper::getStaticMethodInfo(
            jniM,
            coco2dxClass,
            "getInstance",
            "(Landroid/app/Activity;)Lcom/adop/sdk/userinfo/consent/GoogleGDPRConsent;"
    )) {
        jObj = jniM.env->CallStaticObjectMethod(jniM.classID, jniM.methodID, JniHelper::getActivity());
        jCls = jniM.env->GetObjectClass(jObj);
    }
}

void GoogleGDPRController::setDebug(char* testDeviceId, bool isEEA) {
    getGoogleGDPRConsentInstance();

    jstring _testDeviceId = jniM.env->NewStringUTF(testDeviceId);
    jmethodID midGet = jniM.env->GetMethodID(jCls, "setDebug", "(Ljava/lang/String;Z)V");
    jniM.env->CallVoidMethod(jObj, midGet, _testDeviceId, isEEA);

    jniM.env->DeleteLocalRef(_testDeviceId);

    deleteLocalRefMember();
}

bool GoogleGDPRController::isConsentFormAvailable() {
    bool result = false;
    getGoogleGDPRConsentInstance();

    jmethodID midGet = jniM.env->GetMethodID(jCls, "isConsentFormAvailable", "()Z");
    result = jniM.env->CallBooleanMethod(jObj, midGet);

    deleteLocalRefMember();

    return result;
}

int GoogleGDPRController::getConsentStatus() {
    int result = 0;
    getGoogleGDPRConsentInstance();

    jmethodID midGet = jniM.env->GetMethodID(jCls, "getConsentStatus", "()I");
    result = jniM.env->CallIntMethod(jObj, midGet);

    deleteLocalRefMember();

    return result;
}

void GoogleGDPRController::reset() {
    getGoogleGDPRConsentInstance();

    jmethodID midGet = jniM.env->GetMethodID(jCls, "reset", "()V");
    jniM.env->CallVoidMethod(jObj, midGet);

    deleteLocalRefMember();
}

void GoogleGDPRController::requestConsentInfoUpdate() {
    getGoogleGDPRConsentInstance();

    jmethodID midGet = jniM.env->GetMethodID(jCls, "requestConsentInfoUpdate", "()V");
    jniM.env->CallVoidMethod(jObj, midGet);

    deleteLocalRefMember();
}

void GoogleGDPRController::loadForm() {
    getGoogleGDPRConsentInstance();

    jmethodID midGet = jniM.env->GetMethodID(jCls, "loadForm", "()V");
    jniM.env->CallVoidMethod(jObj, midGet);

    deleteLocalRefMember();
}

void GoogleGDPRController::showForm() {
    getGoogleGDPRConsentInstance();

    jmethodID midGet = jniM.env->GetMethodID(jCls, "showForm", "()V");
    jniM.env->CallVoidMethod(jObj, midGet);

    deleteLocalRefMember();
}

void GoogleGDPRController::setListener() {
    getGoogleGDPRConsentInstance();

    jmethodID midGet = jniM.env->GetMethodID(jCls, "setListenerForCpp", "()V");
    jniM.env->CallVoidMethod(jObj, midGet);

    deleteLocalRefMember();
}

void GoogleGDPRController::deleteLocalRefMember(){
    jniM.env->DeleteLocalRef(jObj);
    jniM.env->DeleteLocalRef(jCls);
    jniM.env->DeleteLocalRef(jniM.classID);
}

void GoogleGDPRController::setOnConsentInfoUpdateSuccessCallback(void (*_onConsentInfoUpdateSuccessCallback) ()){
    callback->setOnConsentInfoUpdateSuccessCallback(_onConsentInfoUpdateSuccessCallback);
}

void GoogleGDPRController::setOnConsentInfoUpdateFailureCallback(void (*_onConsentInfoUpdateFailureCallback) (char *)){
    callback->setOnConsentInfoUpdateFailureCallback(_onConsentInfoUpdateFailureCallback);
}

void GoogleGDPRController::setOnConsentFormLoadSuccessCallback(void (*_onConsentFormLoadSuccessCallback) ()){
    callback->setOnConsentFormLoadSuccessCallback(_onConsentFormLoadSuccessCallback);
}

void GoogleGDPRController::setOnConsentFormLoadFailureCallback(void (*_onConsentFormLoadFailureCallback) (char *)){
    callback->setOnConsentFormLoadFailureCallback(_onConsentFormLoadFailureCallback);
}

void GoogleGDPRController::setOnConsentFormDismissedCallback(void (*_onConsentFormDismissedCallback) (char *)){
    callback->setOnConsentFormDismissedCallback(_onConsentFormDismissedCallback);
}

void GoogleGDPRController::callCallback(char* callbackType, char* msg){
    GoogleGDPRController* controller = getInstance();

    if(controller == nullptr){
        LOGD("callCallback controller nullptr");
        return;
    } else if(controller->callback == nullptr){
        LOGD("callCallback controller->callback nullptr");
        return;
    }

    GoogleGDPRCallback* callback = controller->callback;

    LOGD("callCallback callbackType : %s", callbackType);
    if( (strcmp(callbackType, "onConsentInfoUpdateSuccess") == 0) && (callback->onConsentInfoUpdateSuccessCallback != nullptr) ){
        callback->onConsentInfoUpdateSuccessCallback();
    }else if( (strcmp(callbackType, "onConsentInfoUpdateFailure") == 0) && (callback->onConsentInfoUpdateFailureCallback != nullptr) ){
        callback->onConsentInfoUpdateFailureCallback(msg);
    }else if( (strcmp(callbackType, "onConsentFormLoadSuccess") == 0) && (callback->onConsentFormLoadSuccessCallback != nullptr) ){
        callback->onConsentFormLoadSuccessCallback();
    }else if( (strcmp(callbackType, "onConsentFormLoadFailure") == 0) && (callback->onConsentFormLoadFailureCallback != nullptr) ){
        callback->onConsentFormLoadFailureCallback(msg);
    }else if( (strcmp(callbackType, "onConsentFormDismissed") == 0) && (callback->onConsentFormDismissedCallback != nullptr) ){
        callback->onConsentFormDismissedCallback(msg);
    }
}