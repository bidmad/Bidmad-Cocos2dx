#include "BannerController.h"
#include <map>

#define LOG_TAG "bidmad"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define coco2dxClass "ad.helper.openbidding.adview.Cocos2dxAdView"

static std::map<std::string, BannerController*> icm;

BannerController::BannerController(char* zoneId) {
    mZoneId = zoneId;
    callback = new BannerCallback();

    std::string _zoneId = zoneId; //char을 key로 사용 시 못찾는 현상이 있음.
    icm.insert(std::pair<std::string, BannerController*>(_zoneId, this));
}

void BannerController::getInstance() {
    if (JniHelper::getStaticMethodInfo(
            jniM,
            coco2dxClass,
            "getInstance",
            "(Ljava/lang/String;)Lad/helper/openbidding/adview/Cocos2dxAdView;"
    )) {
        jstring _zoneId = jniM.env->NewStringUTF(mZoneId);
        jObj = jniM.env->CallStaticObjectMethod(jniM.classID, jniM.methodID, _zoneId);
        jCls = jniM.env->GetObjectClass(jObj);
        jniM.env->DeleteLocalRef(_zoneId);
    }
}

void BannerController::setActivity() {
    getInstance();

    jmethodID midGet = jniM.env->GetMethodID(jCls, "setActivity", "(Landroid/app/Activity;)V");
    jniM.env->CallVoidMethod(jObj, midGet, JniHelper::getActivity());

    deleteLocalRefMember();
}

void BannerController::makeAdView() {
    getInstance();

    jmethodID midGet = jniM.env->GetMethodID(jCls, "makeAdView", "()V");
    jniM.env->CallVoidMethod(jObj, midGet);

    deleteLocalRefMember();
}

void BannerController::setAdInfo(char *zoneId) {
    getInstance();

    jstring _zoneId = jniM.env->NewStringUTF(zoneId);
    jmethodID midGet = jniM.env->GetMethodID(jCls, "setAdInfo", "(Ljava/lang/String;)V");
    jniM.env->CallVoidMethod(jObj, midGet, _zoneId);

    jniM.env->DeleteLocalRef(_zoneId);
    deleteLocalRefMember();
}

void BannerController::setCUID(char *cuid) {
    getInstance();

    jstring _cuid = jniM.env->NewStringUTF(cuid);
    jmethodID midGet = jniM.env->GetMethodID(jCls, "setCUID", "(Ljava/lang/String;)V");
    jniM.env->CallVoidMethod(jObj, midGet, _cuid);

    jniM.env->DeleteLocalRef(_cuid);
    deleteLocalRefMember();
}

void BannerController::setInterval(int interval) {
    getInstance();

    jmethodID midGet = jniM.env->GetMethodID(jCls, "setInterval", "(I)V");
    jniM.env->CallVoidMethod(jObj, midGet, interval);

    deleteLocalRefMember();
}
    
void BannerController::load(int y) {
    getInstance();

    jmethodID midGet = jniM.env->GetMethodID(jCls, "setBottom", "(I)V");
    jniM.env->CallVoidMethod(jObj, midGet, y);

    midGet = jniM.env->GetMethodID(jCls, "loadWithY", "()V");
    jniM.env->CallVoidMethod(jObj, midGet);

    deleteLocalRefMember();
}

void BannerController::load(int x, int y) {
    getInstance();

    jmethodID midGet = jniM.env->GetMethodID(jCls, "setLeft", "(I)V");
    jniM.env->CallVoidMethod(jObj, midGet, x);

    midGet = jniM.env->GetMethodID(jCls, "setBottom", "(I)V");
    jniM.env->CallVoidMethod(jObj, midGet, y);

    midGet = jniM.env->GetMethodID(jCls, "loadWithXY", "()V");
    jniM.env->CallVoidMethod(jObj, midGet);

    deleteLocalRefMember();
}

void BannerController::removeBanner() {
    getInstance();

    jmethodID midGet = jniM.env->GetMethodID(jCls, "removeBanner", "()V");
    jniM.env->CallVoidMethod(jObj, midGet);

    deleteLocalRefMember();
}

void BannerController::hideBannerView() {
    getInstance();

    jmethodID midGet = jniM.env->GetMethodID(jCls, "hideBannerView", "()V");
    jniM.env->CallVoidMethod(jObj, midGet);

    deleteLocalRefMember();
}

void BannerController::showBannerView() {
    getInstance();

    jmethodID midGet = jniM.env->GetMethodID(jCls, "showBannerView", "()V");
    jniM.env->CallVoidMethod(jObj, midGet);

    deleteLocalRefMember();
}

void BannerController::onPause() {
    getInstance();

    jmethodID midGet = jniM.env->GetMethodID(jCls, "onPause", "()V");
    jniM.env->CallVoidMethod(jObj, midGet);

    deleteLocalRefMember();
}

void BannerController::onResume() {
    getInstance();

    jmethodID midGet = jniM.env->GetMethodID(jCls, "onResume", "()V");
    jniM.env->CallVoidMethod(jObj, midGet);

    deleteLocalRefMember();
}

void BannerController::deleteLocalRefMember(){
    jniM.env->DeleteLocalRef(jObj);
    jniM.env->DeleteLocalRef(jCls);
    jniM.env->DeleteLocalRef(jniM.classID);
}

void BannerController::setOnLoadCallback(void (*_onLoadCallback) (char *)){
    callback->setOnLoadCallback(_onLoadCallback);
}
void BannerController::setOnFailCallback(void (*_onFailCallback) (char *)){
    callback->setOnLoadCallback(_onFailCallback);
}

void BannerController::callCallback(char* callbackType, char* zoneId){
    std::string _zoneId = zoneId;
    BannerController* controller = icm.find(_zoneId)->second;

    if(controller == nullptr){
        LOGD("callCallback controller nullptr : %s", zoneId);
        return;
    } else if(controller->callback == nullptr){
        LOGD("callCallback controller->callback nullptr : %s", zoneId);
        return;
    }

    BannerCallback* callback = controller->callback;

    LOGD("callCallback callbackType : %s", callbackType);
    LOGD("callCallback zoneId : %s", zoneId);
    if( (strcmp(callbackType, "onLoad") == 0) && (callback->onLoadCallback != nullptr) ){
        callback->onLoadCallback(zoneId);
    }else if( (strcmp(callbackType, "onFail") == 0) && (callback->onFailCallback != nullptr) ){
        callback->onFailCallback(zoneId);
    }


}
