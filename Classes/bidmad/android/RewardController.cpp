//
// Created by Kenneth on 2020/08/07.
//

#include "RewardController.h"
#include <map>
#include <string.h>

#define LOG_TAG "bidmad"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define coco2dxClass "ad.helper.openbidding.reward.Cocos2dxReward"

static std::map<std::string, RewardController*> rcm;

RewardController::RewardController(char* zoneId) {
    mZoneId = zoneId;
    callback = new RewardCallback();

    std::string _zoneId(zoneId); //char을 key로 사용 시 못찾는 현상이 있음.
    rcm.insert(std::pair<std::string, RewardController*>(_zoneId, this));
}

void RewardController::getInstance() {
    if (JniHelper::getStaticMethodInfo(
            jniM,
            coco2dxClass,
            "getInstance",
            "(Ljava/lang/String;)Lad/helper/openbidding/reward/Cocos2dxReward;"
    )) {
        jstring _zoneId = jniM.env->NewStringUTF(mZoneId);
        jObj = jniM.env->CallStaticObjectMethod(jniM.classID, jniM.methodID, _zoneId);
        jCls = jniM.env->GetObjectClass(jObj);
        jniM.env->DeleteLocalRef(_zoneId);
    }
}

void RewardController::setActivity() {
    getInstance();

    jmethodID midGet = jniM.env->GetMethodID(jCls, "setActivity", "(Landroid/app/Activity;)V");
    jniM.env->CallVoidMethod(jObj, midGet, JniHelper::getActivity());

    deleteLocalRefMember();
}

void RewardController::makeReward() {
    getInstance();

    jmethodID midGet = jniM.env->GetMethodID(jCls, "makeReward", "()V");
    jniM.env->CallVoidMethod(jObj, midGet);

    deleteLocalRefMember();
}

void RewardController::load() {
    getInstance();

    jmethodID midGet = jniM.env->GetMethodID(jCls, "load", "()V");
    jniM.env->CallVoidMethod(jObj, midGet);

    deleteLocalRefMember();
}

void RewardController::show() {
    getInstance();

    jmethodID midGet = jniM.env->GetMethodID(jCls, "show", "()V");
    jniM.env->CallVoidMethod(jObj, midGet);

    deleteLocalRefMember();
}

bool RewardController::isLoaded() {
    bool result = false;

    getInstance();

    jmethodID midGet = jniM.env->GetMethodID(jCls, "isLoaded", "()Z");
    result = jniM.env->CallBooleanMethod(jObj, midGet);

    deleteLocalRefMember();

    return result;
}

void RewardController::setAutoReload(bool isAutoReload) {
    getInstance();

    jmethodID midGet = jniM.env->GetMethodID(jCls, "setAutoReload", "(Z)V");
    jniM.env->CallVoidMethod(jObj, midGet, isAutoReload);

    deleteLocalRefMember();
}

void RewardController::deleteLocalRefMember(){
    jniM.env->DeleteLocalRef(jObj);
    jniM.env->DeleteLocalRef(jCls);
    jniM.env->DeleteLocalRef(jniM.classID);
}

void RewardController::setOnLoadCallback(void (*_onLoadCallback) (char *)){
    callback->setOnLoadCallback(_onLoadCallback);
}
void RewardController::setOnShowCallback(void (*_onShowCallback) (char *)){
    callback->setOnShowCallback(_onShowCallback);
}
void RewardController::setOnFailCallback(void (*_onFailCallback) (char *)){
    callback->setOnLoadCallback(_onFailCallback);
}
void RewardController::setOnCompleteCallback(void (*_onCompleteCallback) (char *)){
    callback->setOnCompleteCallback(_onCompleteCallback);
}
void RewardController::setOnSkipCallback(void (*_onSkipCallback) (char *)){
    callback->setOnSkipCallback(_onSkipCallback);
}
void RewardController::setOnCloseCallback(void (*_onCloseCallback)(char *)){
    callback->setOnCloseCallback(_onCloseCallback);
}

void RewardController::callCallback(char* callbackType, char* zoneId, char* errorInfo){
    std::string _zoneId(zoneId);
    RewardController* controller = rcm.find(_zoneId)->second;

    if(controller == nullptr){
        LOGD("callCallback controller nullptr : %s", zoneId);
        return;
    } else if(controller->callback == nullptr){
        LOGD("callCallback controller->callback nullptr : %s", zoneId);
        return;
    }

    RewardCallback* callback = controller->callback;

    LOGD("callCallback callbackType : %s", callbackType);
    LOGD("callCallback zoneId : %s", zoneId);
    if( (strcmp(callbackType, "onLoad") == 0) && (callback->onLoadCallback != nullptr) ){
        callback->onLoadCallback(zoneId);
    }else if( (strcmp(callbackType, "onShow") == 0) && (callback->onShowCallback != nullptr) ){
        callback->onShowCallback(zoneId);
    }else if( (strcmp(callbackType, "onFail") == 0) && (callback->onFailCallback != nullptr) ){
        callback->onFailCallback(zoneId, errorInfo);
    }else if( (strcmp(callbackType, "onComplete") == 0) && (callback->onCompleteCallback != nullptr) ){
        callback->onCompleteCallback(zoneId);
    }else if( (strcmp(callbackType, "onSkip") == 0) && (callback->onSkipCallback != nullptr) ){
        callback->onSkipCallback(zoneId);
    }else if( (strcmp(callbackType, "onClose") == 0) && (callback->onCloseCallback != nullptr) ){
        callback->onCloseCallback(zoneId);
    }
}
