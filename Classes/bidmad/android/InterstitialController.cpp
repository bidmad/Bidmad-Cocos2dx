//
// Created by Kenneth on 2020/08/07.
//

#include "InterstitialController.h"
#include <map>

#define LOG_TAG "bidmad"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define coco2dxClass "ad.helper.openbidding.interstitial.Cocos2dxInterstitial"

static std::map<std::string, InterstitialController*> icm;

InterstitialController::InterstitialController(char* zoneId) {
    mZoneId = zoneId;
    callback = new InterstitialCallback();

    std::string _zoneId = zoneId; //char을 key로 사용 시 못찾는 현상이 있음.
    icm.insert(std::pair<std::string, InterstitialController*>(_zoneId, this));
}

void InterstitialController::getInstance() {
    if (JniHelper::getStaticMethodInfo(
            jniM,
            coco2dxClass,
            "getInstance",
            "(Ljava/lang/String;)Lad/helper/openbidding/interstitial/Cocos2dxInterstitial;"
    )) {
        jstring _zoneId = jniM.env->NewStringUTF(mZoneId);
        jObj = jniM.env->CallStaticObjectMethod(jniM.classID, jniM.methodID, _zoneId);
        jCls = jniM.env->GetObjectClass(jObj);
        jniM.env->DeleteLocalRef(_zoneId);
    }
}

void InterstitialController::setActivity() {
    getInstance();

    jmethodID midGet = jniM.env->GetMethodID(jCls, "setActivity", "(Landroid/app/Activity;)V");
    jniM.env->CallVoidMethod(jObj, midGet, JniHelper::getActivity());

    deleteLocalRefMember();
}

void InterstitialController::makeInterstitial() {
    getInstance();

    jmethodID midGet = jniM.env->GetMethodID(jCls, "makeInterstitial", "()V");
    jniM.env->CallVoidMethod(jObj, midGet);

    deleteLocalRefMember();
}

void InterstitialController::setAdInfo(char *zoneId) {
    getInstance();

    jstring _zoneId = jniM.env->NewStringUTF(zoneId);
    jmethodID midGet = jniM.env->GetMethodID(jCls, "setAdInfo", "(Ljava/lang/String;)V");
    jniM.env->CallVoidMethod(jObj, midGet, _zoneId);

    jniM.env->DeleteLocalRef(_zoneId);
    deleteLocalRefMember();
}

void InterstitialController::setCUID(char *cuid) {
    getInstance();

    jstring _cuid = jniM.env->NewStringUTF(cuid);
    jmethodID midGet = jniM.env->GetMethodID(jCls, "setCUID", "(Ljava/lang/String;)V");
    jniM.env->CallVoidMethod(jObj, midGet, _cuid);

    jniM.env->DeleteLocalRef(_cuid);
    deleteLocalRefMember();
}

void InterstitialController::load() {
    getInstance();

    jmethodID midGet = jniM.env->GetMethodID(jCls, "load", "()V");
    jniM.env->CallVoidMethod(jObj, midGet);

    deleteLocalRefMember();
}

void InterstitialController::show() {
    getInstance();

    jmethodID midGet = jniM.env->GetMethodID(jCls, "show", "()V");
    jniM.env->CallVoidMethod(jObj, midGet);

    deleteLocalRefMember();
}

bool InterstitialController::isLoaded() {
    bool result = false;

    getInstance();

    jmethodID midGet = jniM.env->GetMethodID(jCls, "isLoaded", "()Z");
    result = jniM.env->CallBooleanMethod(jObj, midGet);

    deleteLocalRefMember();

    return result;
}

void InterstitialController::setAutoReload(bool isAutoReload) {
    getInstance();

    jmethodID midGet = jniM.env->GetMethodID(jCls, "setAutoReload", "(Z)V");
    jniM.env->CallVoidMethod(jObj, midGet, isAutoReload);

    deleteLocalRefMember();
}

void InterstitialController::deleteLocalRefMember(){
    jniM.env->DeleteLocalRef(jObj);
    jniM.env->DeleteLocalRef(jCls);
    jniM.env->DeleteLocalRef(jniM.classID);
}

void InterstitialController::setOnLoadCallback(void (*_onLoadCallback) (char *)){
    callback->setOnLoadCallback(_onLoadCallback);
}
void InterstitialController::setOnShowCallback(void (*_onShowCallback) (char *)){
    callback->setOnShowCallback(_onShowCallback);
}
void InterstitialController::setOnFailCallback(void (*_onFailCallback) (char *)){
    callback->setOnLoadCallback(_onFailCallback);
}
void InterstitialController::setOnCloseCallback(void (*_onCloseCallback)(char *)){
    callback->setOnCloseCallback(_onCloseCallback);
}

void InterstitialController::callCallback(char* callbackType, char* zoneId){
    std::string _zoneId = zoneId;
    InterstitialController* controller = icm.find(_zoneId)->second;

    if(controller == nullptr){
        LOGD("callCallback controller nullptr : %s", zoneId);
        return;
    } else if(controller->callback == nullptr){
        LOGD("callCallback controller->callback nullptr : %s", zoneId);
        return;
    }

    InterstitialCallback* callback = controller->callback;

    LOGD("callCallback callbackType : %s", callbackType);
    LOGD("callCallback zoneId : %s", zoneId);
    if( (strcmp(callbackType, "onLoad") == 0) && (callback->onLoadCallback != nullptr) ){
        callback->onLoadCallback(zoneId);
    }else if( (strcmp(callbackType, "onShow") == 0) && (callback->onShowCallback != nullptr) ){
        callback->onShowCallback(zoneId);
    }else if( (strcmp(callbackType, "onFail") == 0) && (callback->onFailCallback != nullptr) ){
        callback->onFailCallback(zoneId);
    }else if( (strcmp(callbackType, "onClose") == 0) && (callback->onCloseCallback != nullptr) ){
        callback->onCloseCallback(zoneId);
    }
}
