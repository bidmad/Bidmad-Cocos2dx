#include "cocos2d.h"
#include "GoogleGDPRCallback.h"

USING_NS_CC;

class GoogleGDPRController{
private:
    jobject jObj;
    JniMethodInfo jniM;
    jclass jCls;

    static GoogleGDPRController* controller;

    void deleteLocalRefMember();
    void getGoogleGDPRConsentInstance();
    void setListener();
public:
    static GoogleGDPRCallback* callback;

    static GoogleGDPRController* getInstance();
    void setDebug(char*, bool);
    bool isConsentFormAvailable();
    int getConsentStatus();
    void reset();
    void requestConsentInfoUpdate();
    void loadForm();
    void showForm();

    void setOnConsentInfoUpdateSuccessCallback(void (*_onConsentInfoUpdateSuccessCallback) ());
    void setOnConsentInfoUpdateFailureCallback(void (*_onConsentInfoUpdateFailureCallback) (char *));
    void setOnConsentFormLoadSuccessCallback(void (*_onConsentFormLoadSuccessCallback) ());
    void setOnConsentFormLoadFailureCallback(void (*_onConsentFormLoadFailureCallback) (char *));
    void setOnConsentFormDismissedCallback(void (*_onConsentFormDismissedCallback) (char *));
    static void callCallback(char*, char*);
};