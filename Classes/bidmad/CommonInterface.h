#include "cocos2d.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "ios/CommonBridgeCpp.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "android/CommonController.h"
#endif

USING_NS_CC;

class CommonInterface{

public:
    static char* pluginVersion;
    static void setDebugMode(bool);
    static void setAdvertiserTrackingEnabled(bool);
    static bool getAdvertiserTrackingEnabled();
    static void reqAdTrackingAuthorization(void (*_onAdTrackingAuthorizationResponse) (int));
    static void setGoogleTestId(char *);
    static void setGdprConsent(bool, bool); // Parameters: Consent, UseArea
    static int getGdprConsent(bool);       // Parameter: UseArea
    static const char* getPRIVACYURL();
    static void setCUID(char *);
    static void initializeSdk(char *);
};
