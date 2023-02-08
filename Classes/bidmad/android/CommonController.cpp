//
// Created by Kenneth on 2020/08/07.
//

#include "CommonController.h"

#define LOG_TAG "bidmad"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define coco2dxClass "com.adop.sdk.Common"
#define cocos2dxBidmadCommonClass "ad.helper.openbidding.BidmadCommon"
#define coco2dxAdOptionClass "com.adop.sdk.AdOption"
#define coco2dxConsentClass "com.adop.sdk.userinfo.consent.Consent"

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

        jniM.env->DeleteLocalRef(jniM.classID);
    }

}