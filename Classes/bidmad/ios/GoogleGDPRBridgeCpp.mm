//
//  GoogleGDPRBridgeCpp.cpp
//  BidmadCocos2dxSample-mobile
//
//  Created by ADOP_Mac on 2021/11/19.
//

#include "GoogleGDPRBridgeCpp.h"
#include "GoogleGDPRBridgeObjC.h"

GoogleGDPRBridgeCpp::GoogleGDPRBridgeCpp() {
    [[GoogleGDPRBridgeObjC sharedInstance] setCallbackController: this];
}

void GoogleGDPRBridgeCpp::setDebug(char* testDeviceId, bool isEEA) {
    [[GoogleGDPRBridgeObjC sharedInstance] setDebug:testDeviceId isEEA:isEEA];
}

void GoogleGDPRBridgeCpp::requestConsentInfoUpdate() {
    [[GoogleGDPRBridgeObjC sharedInstance] requestConsentInfoUpdate];
}

bool GoogleGDPRBridgeCpp::isConsentFormAvailable() {
    return [[GoogleGDPRBridgeObjC sharedInstance] isConsentFormAvailable];
}

void GoogleGDPRBridgeCpp::loadForm() {
    [[GoogleGDPRBridgeObjC sharedInstance] loadForm];
}

int GoogleGDPRBridgeCpp::getConsentStatus() {
    return [[GoogleGDPRBridgeObjC sharedInstance] getConsentStatus];
}

void GoogleGDPRBridgeCpp::reset() {
    [[GoogleGDPRBridgeObjC sharedInstance] reset];
}

void GoogleGDPRBridgeCpp::showForm() {
    [[GoogleGDPRBridgeObjC sharedInstance] showForm];
}

void GoogleGDPRBridgeCpp::setOnConsentInfoUpdateSuccessCallback(void (*_onConsentInfoUpdateSuccessCallback) ()) {
    onConsentInfoUpdateSuccessCallback = _onConsentInfoUpdateSuccessCallback;
}

void GoogleGDPRBridgeCpp::setOnConsentInfoUpdateFailureCallback(void (*_onConsentInfoUpdateFailureCallback) (char *)) {
    onConsentInfoUpdateFailureCallback = _onConsentInfoUpdateFailureCallback;
}

void GoogleGDPRBridgeCpp::setOnConsentFormLoadSuccessCallback(void (*_onConsentFormLoadSuccessCallback) ()) {
    onConsentFormLoadSuccessCallback = _onConsentFormLoadSuccessCallback;
}

void GoogleGDPRBridgeCpp::setOnConsentFormLoadFailureCallback(void (*_onConsentFormLoadFailureCallback) (char *)) {
    onConsentFormLoadFailureCallback = _onConsentFormLoadFailureCallback;
}

void GoogleGDPRBridgeCpp::setOnConsentFormDismissedCallback(void (*_onConsentFormDismissedCallback) (char *)) {
    onConsentFormDismissedCallback = _onConsentFormDismissedCallback;
}

void GoogleGDPRBridgeCpp::callCallback(char* callbackType, char* errorReason) {
    if((strcmp(callbackType, "onConsentInfoUpdateSuccessCallback") == 0) &&
       (onConsentInfoUpdateSuccessCallback != nullptr)) {
        onConsentInfoUpdateSuccessCallback();
    }else if((strcmp(callbackType, "onConsentInfoUpdateFailureCallback") == 0) &&
             (onConsentInfoUpdateFailureCallback != nullptr)) {
        onConsentInfoUpdateFailureCallback(errorReason);
    }else if((strcmp(callbackType, "onConsentFormLoadSuccessCallback") == 0) &&
             (onConsentFormLoadSuccessCallback != nullptr)) {
        onConsentFormLoadSuccessCallback();
    }else if((strcmp(callbackType, "onConsentFormLoadFailureCallback") == 0) &&
             (onConsentFormLoadFailureCallback != nullptr)) {
        onConsentFormLoadFailureCallback(errorReason);
    }else if((strcmp(callbackType, "onConsentFormDismissedCallback") == 0) &&
             (onConsentFormDismissedCallback != nullptr)) {
        onConsentFormDismissedCallback(errorReason);
    }
}

