#include "cocos2d.h"
#include "RewardCallback.h"

USING_NS_CC;

class CommonController{
public:
    static void setDebugging(bool);
    static void setCUID(char *);
    static void initializeSdk(char *);
    static void setGgTestDeviceid(char*);
    static void setGdprConsent(bool, bool); // Parameters: Consent, UseArea
    static int getGdprConsent(bool);       // Parameter: UseArea
    static const char* getPRIVACYURL();
    static void initializeSdkWithCallback(char * appKey, void (*_onInitialized) (bool));
    static bool isAdFree();
    static void (*onInitialized) (bool);
    static void (*onAdFree)(bool);

    // callback setting
    static void setAdFreeEventCallback(void (*_onAdFree) (bool));
};

extern "C"{
    JNIEXPORT void JNICALL Java_ad_helper_openbidding_BidmadCommon_onInitializedCb(JNIEnv *env, jobject obj, jstring isComplete);
    JNIEXPORT void JNICALL Java_ad_helper_openbidding_AdFreeInformation_onAdFreeCb(JNIEnv *, jobject obj, jstring isAdFree);
};
