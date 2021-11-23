#include "cocos2d.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "ios/GoogleGDPRBridgeCpp.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "android/GoogleGDPRController.h"
#endif

USING_NS_CC;

class GoogleGDPRInterface {
private:
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    GoogleGDPRBridgeCpp* gdpr;
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    GoogleGDPRController* gdpr;
#endif
public:
    GoogleGDPRInterface();
    void setDebug(char*, bool);
    bool isConsentFormAvailable();
    int getConsentStatus();
    void reset();
    void requestConsentInfoUpdate();
    void loadForm();
    void showForm();
    void setOnConsentInfoUpdateSuccessCallback(void (*_onConsentInfoUpdateSuccessCallback) ());
    void setOnConsentInfoUpdateFailureCallback(void (*_onConsentInfoUpdateFailureCallback) (char *));
    void setOnConsentFormLoadSuccessCallback(void (*_onConsentFormLoadSuccessCallback)());
    void setOnConsentFormLoadFailureCallback(void (*_onConsentFormLoadFailureCallback) (char *));
    void setOnConsentFormDismissedCallback(void (*_onConsentFormDismissedCallback) (char *));
};
