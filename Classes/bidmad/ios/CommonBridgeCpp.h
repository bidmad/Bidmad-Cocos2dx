//
//  CommonBridgeCpp.h
//
//  Created by Kenneth on 2021/04/24.
//

#ifndef CommonBridgeCpp_h
#define CommonBridgeCpp_h

#include "cocos2d.h"

class CommonBridgeCpp{
public:
    static void setDebugMode(bool);
    static void setAdvertiserTrackingEnabled(bool);
    static bool getAdvertiserTrackingEnabled();
    static void reqAdTrackingAuthorization(void (*_onAdTrackingAuthorizationResponse) (int));
    static void onATTCallback(int);
    static void setGoogleTestId(char *);
    static void setGdprConsent(bool, bool);
    static int getGdprConsent(bool);
    static const char* getPRIVACYURL();
    static void setCUID(char *);
    static void initializeSdk(char *);
    static void initializeSdkWithCallback(char *appKey);
    static bool isAdFree();
    
    // callback setting
    static void setInitializeCallback(void (*_onInitializedCallback) (bool));
    static void setAdFreeEventCallback(void (*_onAdFreeCallback) (bool));
};

#endif /* CommonBridgeCpp_h */
