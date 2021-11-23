//
//  GoogleGDPR.cpp
//  BidmadCocos2dxSample-mobile
//
//  Created by ADOP_Mac on 2021/11/19.
//

#include "GoogleGDPRInterface.h"

GoogleGDPRInterface::GoogleGDPRInterface() {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    gdpr = new GoogleGDPRBridgeCpp();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    gdpr = GoogleGDPRController::getInstance();
#endif
}

void GoogleGDPRInterface::setDebug(char* testDeviceId, bool isTestEurope) {
    CCLOG("BidmadSDK GoogleGDPRInterace - setDebug");
    gdpr->setDebug(testDeviceId, isTestEurope);
}

bool GoogleGDPRInterface::isConsentFormAvailable() {
    CCLOG("BidmadSDK GoogleGDPRInterace - isConsentFormAvailable");
    return gdpr->isConsentFormAvailable();
}

int GoogleGDPRInterface::getConsentStatus() {
    /*
    - ConsentStatus
    UNKNOWN = 0;
    REQUIRED = 1;
    NOT_REQUIRED = 2;
    OBTAINED = 3;
    */
    CCLOG("BidmadSDK GoogleGDPRInterace - getConsentStatus");
    return gdpr->getConsentStatus();
}

void GoogleGDPRInterface::reset() {
    CCLOG("BidmadSDK GoogleGDPRInterace - reset");
    gdpr->reset();
}

void GoogleGDPRInterface::requestConsentInfoUpdate() {
    CCLOG("BidmadSDK GoogleGDPRInterace - requestConsentInfoUpdate");
    gdpr->requestConsentInfoUpdate();
}

void GoogleGDPRInterface::loadForm() {
    CCLOG("BidmadSDK GoogleGDPRInterace - loadForm");
    gdpr->loadForm();
}

void GoogleGDPRInterface::showForm() {
    CCLOG("BidmadSDK GoogleGDPRInterace - showForm");
    gdpr->showForm();
}

void GoogleGDPRInterface::setOnConsentInfoUpdateSuccessCallback(void (*_onConsentInfoUpdateSuccessCallback) ()) {
    gdpr->setOnConsentInfoUpdateSuccessCallback(_onConsentInfoUpdateSuccessCallback);
}

void GoogleGDPRInterface::setOnConsentInfoUpdateFailureCallback(void (*_onConsentInfoUpdateFailureCallback) (char *)) {
    gdpr->setOnConsentInfoUpdateFailureCallback(_onConsentInfoUpdateFailureCallback);
}

void GoogleGDPRInterface::setOnConsentFormLoadSuccessCallback(void (*_onConsentFormLoadSuccessCallback)()) {
    gdpr->setOnConsentFormLoadSuccessCallback(_onConsentFormLoadSuccessCallback);
}
                                                            
void GoogleGDPRInterface::setOnConsentFormLoadFailureCallback(void (*_onConsentFormLoadFailureCallback) (char *)) {
    gdpr->setOnConsentFormLoadFailureCallback(_onConsentFormLoadFailureCallback);
}
                                                            
void GoogleGDPRInterface::setOnConsentFormDismissedCallback(void (*_onConsentFormDismissedCallback) (char *)) {
    gdpr->setOnConsentFormDismissedCallback(_onConsentFormDismissedCallback);
}
