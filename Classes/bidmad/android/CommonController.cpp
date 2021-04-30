//
// Created by Kenneth on 2020/08/07.
//

#include "CommonController.h"

#define LOG_TAG "bidmad"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define coco2dxClass "com.adop.sdk.Common"

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