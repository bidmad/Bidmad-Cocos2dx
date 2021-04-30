//
// Created by Kenneth on 2020/08/07.
//

#include "RewardController.h"
#include <map>
#include <string.h>

#define LOG_TAG "bidmad"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define coco2dxClass "com.adop.sdk.reward.Cocos2dxReward"

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
            "(Ljava/lang/String;)Lcom/adop/sdk/reward/Cocos2dxReward;"
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

void RewardController::setAdInfo(char *zoneId) {
    getInstance();

    jstring _zoneId = jniM.env->NewStringUTF(zoneId);
    jmethodID midGet = jniM.env->GetMethodID(jCls, "setAdInfo", "(Ljava/lang/String;)V");
    jniM.env->CallVoidMethod(jObj, midGet, _zoneId);

    jniM.env->DeleteLocalRef(_zoneId);
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

void RewardController::callCallback(char* callbackType, char* zoneId){
    std::string _zoneId(zoneId);
    RewardController* controller = rcm.find(_zoneId)->second;
    RewardCallback* callback = controller->callback;

    LOGD("callCallback callbackType : %s", callbackType);
    LOGD("callCallback zoneId : %s", zoneId);
    if( (strcmp(callbackType, "onLoad") == 0) && (callback->onLoadCallback != nullptr) ){
        callback->onLoadCallback(zoneId);
    }else if( (strcmp(callbackType, "onShow") == 0) && (callback->onShowCallback != nullptr) ){
        callback->onShowCallback(zoneId);
        controller->load();
    }else if( (strcmp(callbackType, "onFail") == 0) && (callback->onFailCallback != nullptr) ){
        callback->onFailCallback(zoneId);
    }else if( (strcmp(callbackType, "onComplete") == 0) && (callback->onCompleteCallback != nullptr) ){
        callback->onCompleteCallback(zoneId);
    }else if( (strcmp(callbackType, "onSkip") == 0) && (callback->onSkipCallback != nullptr) ){
        callback->onSkipCallback(zoneId);
    }else if( (strcmp(callbackType, "onClose") == 0) && (callback->onCloseCallback != nullptr) ){
        callback->onCloseCallback(zoneId);
    }
}
