//
//  BidmadCommonCpp.mm
//  BidmadiOS
//
//  Created by Kenneth on 2021/04/24.
//

#include "CommonBridgeCpp.h"
#include "CommonBridgeObjC.h"

static void (*onAdTrackingAuthorizationResponse)(int);

void CommonBridgeCpp::setDebugMode(bool isDebug) {
    [[CommonBridgeObjC sharedInstance] setDebugMode:isDebug];
}

void CommonBridgeCpp::setAdvertiserTrackingEnabled(bool isDebug) {
    [[CommonBridgeObjC sharedInstance] setAdvertiserTrackingEnabled:isDebug];
}

bool CommonBridgeCpp::getAdvertiserTrackingEnabled() {
    return [[CommonBridgeObjC sharedInstance] getAdvertiserTrackingEnabled];
}

void CommonBridgeCpp::reqAdTrackingAuthorization(void (*_onAdTrackingAuthorizationResponse) (int)) {
    onAdTrackingAuthorizationResponse = _onAdTrackingAuthorizationResponse;
    
    [[CommonBridgeObjC sharedInstance] reqAdTrackingAuthorization];
}

void CommonBridgeCpp::onATTCallback(int response){
    onAdTrackingAuthorizationResponse(response);
}

void CommonBridgeCpp::setGoogleTestId(char * testDeviceId) {
    NSString* _testDeviceId = [NSString stringWithUTF8String: testDeviceId];
    [[CommonBridgeObjC sharedInstance] setGoogleTestId:_testDeviceId];
}

void CommonBridgeCpp::setGdprConsent(bool consent, bool useArea) {
    [[CommonBridgeObjC sharedInstance] setGdprConsent:consent useArea:useArea];
}

int CommonBridgeCpp::getGdprConsent(bool useArea) {
    return [[CommonBridgeObjC sharedInstance] getGdprConsentWithUseArea:useArea];
}

const char* CommonBridgeCpp::getPRIVACYURL() {
    return [[CommonBridgeObjC sharedInstance] getPRIVACYURL];
}

void CommonBridgeCpp::setCUID(char *cuid) {
    [BIDMADSetting.sharedInstance setCuid:[NSString stringWithUTF8String:(const char *)cuid]];
}

void CommonBridgeCpp::initializeSdk(char *appKey) {
    [[CommonBridgeObjC sharedInstance] initializeSdkWithAppKey:[NSString stringWithUTF8String:(const char *)appKey]];
    return;
}

void CommonBridgeCpp::initializeSdkWithCallback(char *appKey) {
    [CommonBridgeObjC.sharedInstance initializeSdkWithCallbackForAppKey:[NSString stringWithUTF8String:(const char *)appKey]];
}

bool CommonBridgeCpp::isAdFree() {
    return [[CommonBridgeObjC sharedInstance] isAdFree];
}

void CommonBridgeCpp::setInitializeCallback(void (*_onInitializedCallback) (bool)) {
    [[CommonBridgeObjC sharedInstance] setInitializeCallback:_onInitializedCallback];
    return;
}

void CommonBridgeCpp::setAdFreeEventCallback(void (*_onAdFreeCallback) (bool)) {
    [[CommonBridgeObjC sharedInstance] setAdFreeEventCallback:_onAdFreeCallback];
    return;
}
