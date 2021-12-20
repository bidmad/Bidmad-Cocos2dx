//
//  BidmadRewardCpp.mm
//  BidmadiOS
//
//  Created by Kenneth on 2021/04/24.
//

#include "RewardBridgeCpp.h"
#include "RewardBridgeObjC.h"

RewardBridgeCpp::RewardBridgeCpp(char* zoneId){
    mZoneId = zoneId;
    NSString* _zoneId = [NSString stringWithUTF8String: zoneId];
    [[RewardBridgeObjC alloc] initWithZoneId:_zoneId controller:this];
}

void RewardBridgeCpp::loadRewardVideo() {
    NSString* _zoneId = [NSString stringWithUTF8String: mZoneId];
    RewardBridgeObjC* bidmadObject = [RewardBridgeObjC getInstance:_zoneId];
    [bidmadObject loadRewardVideo];
}

void RewardBridgeCpp::showRewardVideo() {
    NSString* _zoneId = [NSString stringWithUTF8String: mZoneId];
    RewardBridgeObjC* bidmadObject = [RewardBridgeObjC getInstance:_zoneId];
    [bidmadObject showRewardVideo];
}

bool RewardBridgeCpp::isLoaded() {
    NSString* _zoneId = [NSString stringWithUTF8String: mZoneId];
    RewardBridgeObjC* bidmadObject = [RewardBridgeObjC getInstance:_zoneId];
    return [bidmadObject isLoaded];
}

void RewardBridgeCpp::setAutoReload(bool isAutoReload) {
    NSString* _zoneId = [NSString stringWithUTF8String: mZoneId];
    RewardBridgeObjC* bidmadObject = [RewardBridgeObjC getInstance:_zoneId];
    [bidmadObject setAutoReload:isAutoReload];
}

void RewardBridgeCpp::setCUID(char* cuid) {
    NSString *_cuid = [NSString stringWithUTF8String:cuid];
    NSString* _zoneId = [NSString stringWithUTF8String: mZoneId];
    RewardBridgeObjC* bidmadObject = [RewardBridgeObjC getInstance:_zoneId];
    [bidmadObject setCUID:_cuid];
}

void RewardBridgeCpp::setOnLoadCallback(void (*_onLoadCallback)( char *)){
    onLoadCallback = _onLoadCallback;
}

void RewardBridgeCpp::setOnShowCallback(void (*_onShowCallback)( char *)){
    onShowCallback = _onShowCallback;
}

void RewardBridgeCpp::setOnFailCallback(void (*_onFailCallback)( char *)){
    onFailCallback = _onFailCallback;
}

void RewardBridgeCpp::setOnCompleteCallback(void (*_onCompleteCallback)( char *)){
    onCompleteCallback = _onCompleteCallback;
}

void RewardBridgeCpp::setOnSkipCallback(void (*_onSkipCallback)( char *)){
    onSkipCallback = _onSkipCallback;
}

void RewardBridgeCpp::setOnCloseCallback(void (*_onCloseCallback)( char *)){
    onCloseCallback = _onCloseCallback;
}

void RewardBridgeCpp::callCallback(char* callbackType, char* zoneId){
    CCLOG("BidmadSDK callCallback : %s  ", callbackType);
    CCLOG("BidmadSDK zoneId : %s  ", zoneId);
    if( (strcmp(callbackType, "onLoad") == 0) && (onLoadCallback != nullptr) ){
        onLoadCallback(zoneId);
    }else if( (strcmp(callbackType, "onShow") == 0) && (onShowCallback != nullptr) ){
        onShowCallback(zoneId);
    }else if( (strcmp(callbackType, "onFail") == 0) && (onFailCallback != nullptr) ){
        onFailCallback(zoneId);
    }else if( (strcmp(callbackType, "onComplete") == 0) && (onCompleteCallback != nullptr) ){
        onCompleteCallback(zoneId);
    }else if( (strcmp(callbackType, "onSkip") == 0) && (onSkipCallback != nullptr) ){
        onSkipCallback(zoneId);
    }else if( (strcmp(callbackType, "onClose") == 0) && (onCloseCallback != nullptr) ){
        onCloseCallback(zoneId);
    }else if( (strcmp(callbackType, "onClick") == 0) && (onClickCallback != nullptr) ){
        onClickCallback(zoneId);
    }
}
