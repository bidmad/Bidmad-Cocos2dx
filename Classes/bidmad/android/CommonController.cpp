//
// Created by Kenneth on 2020/08/07.
//

#include "CommonController.h"
#include <cstring>

#define LOG_TAG "bidmad"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define coco2dxClass "com.adop.sdk.Common"
#define cocos2dxBidmadCommonClass "ad.helper.openbidding.BidmadCommon"
#define coco2dxAdOptionClass "com.adop.sdk.AdOption"
#define coco2dxConsentClass "com.adop.sdk.userinfo.consent.Consent"
#define coco2dxAdFreeInformationClass "ad.helper.openbidding.AdFreeInformation"

void (*CommonController::onAdFree)(bool) = nullptr;
void (*CommonController::onInitialized) (bool) = nullptr;

void CommonController::setDebugging(bool isDebug) {
    JniMethodInfo jniM;
    if (JniHelper::getStaticMethodInfo(
            jniM,
            coco2dxClass,
            "setDebugging",
            "(Z)V"
    )) {
        jniM.env->CallStaticVoidMethod(jniM.classID, jniM.methodID, isDebug);

        jniM.env->DeleteLocalRef(jniM.classID);
    }
}

void CommonController::setGgTestDeviceid(char* testDeviceId) {
    JniMethodInfo jniM;
    if (JniHelper::getStaticMethodInfo(
            jniM,
            coco2dxClass,
            "setGgTestDeviceid",
            "(Ljava/lang/String;)V"
    )) {
        jstring _testDeviceId = jniM.env->NewStringUTF(testDeviceId);
        jniM.env->CallStaticVoidMethod(jniM.classID, jniM.methodID, _testDeviceId);

        jniM.env->DeleteLocalRef(_testDeviceId);
        jniM.env->DeleteLocalRef(jniM.classID);
    }
}

void CommonController::setGdprConsent(bool consent, bool useArea) {
    JniMethodInfo jniM;
    jobject jObj;
    if (JniHelper::getMethodInfo(
        jniM,
        coco2dxConsentClass,
        "<init>",
        "(Landroid/content/Context;Z)V"
    )) {
        jObj = jniM.env->NewObject(jniM.classID, jniM.methodID, JniHelper::getActivity(), useArea);

        jmethodID midGet = jniM.env->GetMethodID(jniM.classID, "setGdprConsent", "(Z)V");
        jniM.env->CallVoidMethod(jObj, midGet, consent);

        jniM.env->DeleteLocalRef(jObj);
        jniM.env->DeleteLocalRef(jniM.classID);
    }
}

int CommonController::getGdprConsent(bool useArea) {
    /*
     * Return GDPR Status(int)
     * YES(1)
     * NO(0)
     * UNKWON(-1)
     * UNUSE(-2)
     */
    JniMethodInfo jniM;
    jobject jObj;
    int result = useArea ? -1 : -2;

    if (JniHelper::getMethodInfo(
            jniM,
            coco2dxConsentClass,
            "<init>",
            "(Landroid/content/Context;Z)V"
    )) {
        jObj = jniM.env->NewObject(jniM.classID, jniM.methodID, JniHelper::getActivity(), useArea);

        jmethodID midGet = jniM.env->GetMethodID(jniM.classID, "getGdprConsentForOtherPlatform", "()I");

        result = jniM.env->CallIntMethod(jObj, midGet);
        jniM.env->DeleteLocalRef(jniM.classID);
    }

    return result;
}

const char* CommonController::getPRIVACYURL() {
    JniMethodInfo jniM;
    jobject jObj;
    const char* result = "";
    if (JniHelper::getMethodInfo(
        jniM,
        coco2dxConsentClass,
        "<init>",
        "(Landroid/content/Context;)V"
    )) {
        jObj = jniM.env->NewObject(jniM.classID, jniM.methodID, JniHelper::getActivity());

        jmethodID midGet = jniM.env->GetMethodID(jniM.classID, "getPRIVACYURL", "()Ljava/lang/String;");

        jstring url = (jstring) jniM.env->CallObjectMethod(jObj, midGet);

        result = jniM.env->GetStringUTFChars(url, NULL);
        jniM.env->ReleaseStringUTFChars(url, result);

        jniM.env->DeleteLocalRef(url);
        jniM.env->DeleteLocalRef(jniM.classID);
    }

    return result;
}

void CommonController::setCUID(char * id){
    JniMethodInfo jniM;
    jobject jObj;
        if (JniHelper::getStaticMethodInfo(
                jniM,
                coco2dxAdOptionClass,
                "getInstance",
                "()Lcom/adop/sdk/AdOption;"
        )) {
            jstring _cuid = jniM.env->NewStringUTF(id);
            jObj = jniM.env->CallStaticObjectMethod(jniM.classID, jniM.methodID);

            jmethodID midGet = jniM.env->GetMethodID(jniM.classID, "setCuid", "(Ljava/lang/String;)V");
            jniM.env->CallVoidMethod(jObj, midGet, _cuid);

            jniM.env->DeleteLocalRef(jObj);
            jniM.env->DeleteLocalRef(_cuid);
            jniM.env->DeleteLocalRef(jniM.classID);
        }
}

void CommonController::initializeSdk(char * appKey){
    JniMethodInfo jniM;
    if (JniHelper::getStaticMethodInfo(
            jniM,
            cocos2dxBidmadCommonClass,
            "initializeSdk",
            "(Landroid/app/Activity;Ljava/lang/String;)V"
    )) {

        jstring _appkey = jniM.env->NewStringUTF(appKey);
        jniM.env->CallStaticVoidMethod(jniM.classID, jniM.methodID, JniHelper::getActivity(), _appkey);

        jniM.env->DeleteLocalRef(_appkey);
        jniM.env->DeleteLocalRef(jniM.classID);
    }

}

void CommonController::initializeSdkWithCallback(char * appKey, void (*_onInitialized) (bool)){
    JniMethodInfo jniM;
    if (JniHelper::getStaticMethodInfo(
            jniM,
            cocos2dxBidmadCommonClass,
            "initializeSdkWithCbListener",
            "(Landroid/app/Activity;Ljava/lang/String;)V"
    )) {
        LOGD("CommonController::initializeSdkWithCbListener");

        onInitialized = _onInitialized;

        jstring _appkey = jniM.env->NewStringUTF(appKey);
        jniM.env->CallStaticVoidMethod(jniM.classID, jniM.methodID, JniHelper::getActivity(), _appkey);

        jniM.env->DeleteLocalRef(_appkey);
        jniM.env->DeleteLocalRef(jniM.classID);
    }

}

void CommonController::setAdFreeEventCallback(void (*_onAdFree) (bool)){
    JniMethodInfo jniM;
    jobject jObj;
    if (JniHelper::getStaticMethodInfo(
            jniM,
            coco2dxAdFreeInformationClass,
            "getInstance",
            "(Landroid/content/Context;)Lad/helper/openbidding/AdFreeInformation;"
    )) {
        LOGD("CommonController::setAdFreeEventCallback");
        onAdFree = _onAdFree;

        jObj = jniM.env->CallStaticObjectMethod(jniM.classID, jniM.methodID, JniHelper::getActivity());
        jmethodID  midGet = jniM.env->GetMethodID(jniM.classID, "setOnAdFreeCbListener", "()V");

        jniM.env->CallVoidMethod(jObj, midGet);

        jniM.env->DeleteLocalRef(jObj);
        jniM.env->DeleteLocalRef(jniM.classID);
    }
}

bool CommonController::isAdFree(){
    JniMethodInfo jniM;
    jobject jObj;
    if (JniHelper::getStaticMethodInfo(
            jniM,
            coco2dxAdFreeInformationClass,
            "getInstance",
            "(Landroid/content/Context;)Lad/helper/openbidding/AdFreeInformation;"
    )) {
        //getAdFreeStatus
        jObj = jniM.env->CallStaticObjectMethod(jniM.classID, jniM.methodID, JniHelper::getActivity());
        jmethodID  midGet = jniM.env->GetMethodID(jniM.classID, "getAdFreeStatus", "()I");

        int result = jniM.env->CallIntMethod(jObj, midGet);

        jniM.env->DeleteLocalRef(jObj);
        jniM.env->DeleteLocalRef(jniM.classID);

        return (result==0)? true : false;
    }
    return false;
}

extern "C"{
    JNIEXPORT void JNICALL Java_ad_helper_openbidding_BidmadCommon_onInitializedCb(JNIEnv *env, jobject obj, jstring isComplete){ //jboolean 과 java boolean 호환이 되지 않는 이슈로 jstring 으로 사용
        if(nullptr != CommonController::onInitialized) {

            const char *isCompletedStr = env->GetStringUTFChars(isComplete, NULL);
            if(std::strncmp(isCompletedStr, "true", 4) == 0) {
                CommonController::onInitialized(true);
            }else {
                CommonController::onInitialized(false);
            }
            env->ReleaseStringUTFChars(isComplete, isCompletedStr);
        }
    }
    
    JNIEXPORT void JNICALL Java_ad_helper_openbidding_AdFreeInformation_onAdFreeCb(JNIEnv *env, jobject obj, jstring isAdFree){
        if(nullptr != CommonController::onAdFree) {
            
            const char *isAdFreeStr = env->GetStringUTFChars(isAdFree, NULL);
            
            if(std::strncmp(isAdFreeStr, "true", 4) == 0) {
                CommonController::onAdFree(true);
            }else {
                CommonController::onAdFree(false);
            }
            
            env->ReleaseStringUTFChars(isAdFree, isAdFreeStr);
        }
    }
}
