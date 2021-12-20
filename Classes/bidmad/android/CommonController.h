#include "cocos2d.h"
#include "RewardCallback.h"

USING_NS_CC;

class CommonController{
public:
    static void setDebugging(bool);
    static void initializeSdk();
    static void setGgTestDeviceid(char*);
    static void setGdprConsent(bool, bool); // Parameters: Consent, UseArea
    static int getGdprConsent(bool);       // Parameter: UseArea
    static const char* getPRIVACYURL();
};