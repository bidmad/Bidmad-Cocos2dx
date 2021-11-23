//
//  GoogleGDPRBridgeCpp.hpp
//  BidmadCocos2dxSample-mobile
//
//  Created by ADOP_Mac on 2021/11/19.
//

#ifndef GoogleGDPRBridgeCpp_h
#define GoogleGDPRBridgeCpp_h

#include "cocos2d.h"

class GoogleGDPRBridgeCpp {
private:
    void (*onConsentInfoUpdateSuccessCallback) () = nullptr;
    void (*onConsentInfoUpdateFailureCallback) (char *) = nullptr;
    void (*onConsentFormLoadSuccessCallback) () = nullptr;
    void (*onConsentFormLoadFailureCallback) (char *) = nullptr;
    void (*onConsentFormDismissedCallback) (char *) = nullptr;
public:
    GoogleGDPRBridgeCpp();
    void setDebug(char*, bool);
    void requestConsentInfoUpdate();
    bool isConsentFormAvailable();
    void loadForm();
    int getConsentStatus();
    void reset();
    void setDelegate();
    void showForm();
    void setOnConsentInfoUpdateSuccessCallback(void (*_onConsentInfoUpdateSuccessCallback) ());
    void setOnConsentInfoUpdateFailureCallback(void (*_onConsentInfoUpdateFailureCallback) (char *));
    void setOnConsentFormLoadSuccessCallback(void (*_onConsentFormLoadSuccessCallback) ());
    void setOnConsentFormLoadFailureCallback(void (*_onConsentFormLoadFailureCallback) (char *));
    void setOnConsentFormDismissedCallback(void (*_onConsentFormDismissedCallback) (char *));
    void callCallback(char* callbackType, char* errorReason);
};

#endif
