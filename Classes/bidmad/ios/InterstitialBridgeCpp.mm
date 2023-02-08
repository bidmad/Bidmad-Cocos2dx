//
//  BidmadRewardCpp.mm
//  BidmadiOS
//
//  Created by Kenneth on 2021/04/24.
//

#include "InterstitialBridgeCpp.h"
#include "InterstitialBridgeObjC.h"

InterstitialBridgeCpp::InterstitialBridgeCpp(char* zoneId){
    mZoneId = zoneId;
    NSString* _zoneId = [NSString stringWithUTF8String: zoneId];
    [InterstitialBridgeObjC initialSetupWithZoneId:_zoneId controller:this];
}

void InterstitialBridgeCpp::loadInterstitial() {
    NSString* _zoneId = [NSString stringWithUTF8String: mZoneId];
    InterstitialBridgeObjC* bidmadObject = [InterstitialBridgeObjC getInstance:_zoneId];
    [bidmadObject loadInterstitial];
}

void InterstitialBridgeCpp::showInterstitial() {
    NSString* _zoneId = [NSString stringWithUTF8String: mZoneId];
    InterstitialBridgeObjC* bidmadObject = [InterstitialBridgeObjC getInstance:_zoneId];
    [bidmadObject showInterstitial];
}

bool InterstitialBridgeCpp::isLoaded() {
    NSString* _zoneId = [NSString stringWithUTF8String: mZoneId];
    InterstitialBridgeObjC* bidmadObject = [InterstitialBridgeObjC getInstance:_zoneId];
    return [bidmadObject isLoaded];
}

void InterstitialBridgeCpp::setAutoReload(bool isAutoReload) {
    NSString* _zoneId = [NSString stringWithUTF8String: mZoneId];
    InterstitialBridgeObjC* bidmadObject = [InterstitialBridgeObjC getInstance:_zoneId];
    [bidmadObject setAutoReload:isAutoReload];
}

void InterstitialBridgeCpp::setOnLoadCallback(void (*_onLoadCallback)( char *)){
    onLoadCallback = _onLoadCallback;
}

void InterstitialBridgeCpp::setOnShowCallback(void (*_onShowCallback)( char *)){
    onShowCallback = _onShowCallback;
}

void InterstitialBridgeCpp::setOnFailCallback(void (*_onFailCallback)(char *, char *)) {
    onFailCallback = _onFailCallback;
}

void InterstitialBridgeCpp::setOnCloseCallback(void (*_onCloseCallback)( char *)){
    onCloseCallback = _onCloseCallback;
}

void InterstitialBridgeCpp::callCallback(char* callbackType, char* zoneId, char* errorReason) {
    CCLOG("BidmadSDK callCallback : %s  ", callbackType);
    CCLOG("BidmadSDK zoneId : %s  ", zoneId);
    if( (strcmp(callbackType, "onLoad") == 0) && (onLoadCallback != nullptr) ){
        onLoadCallback(zoneId);
    }else if( (strcmp(callbackType, "onShow") == 0) && (onShowCallback != nullptr) ){
        onShowCallback(zoneId);
    }else if( (strcmp(callbackType, "onFail") == 0) && (onFailCallback != nullptr) ){
        onFailCallback(zoneId, errorReason);
    }else if( (strcmp(callbackType, "onClose") == 0) && (onCloseCallback != nullptr) ){
        onCloseCallback(zoneId);
    }
}
