//
//  BannerBridgeCpp.m
//  BidmadCocos2dxSample-mobile
//
//  Created by ADOP_Mac on 2021/06/29.
//

#include "BannerBridgeCpp.h"
#include "BannerBridgeObjC.h"

BannerBridgeCpp::BannerBridgeCpp(char* zoneId){
    mZoneId = zoneId;
    NSString* _zoneId = [NSString stringWithUTF8String: zoneId];
    [BannerBridgeObjC initialSetupWithZoneId:_zoneId controller:this];
}

void BannerBridgeCpp::load(int y) {
    NSString* _zoneId = [NSString stringWithUTF8String: mZoneId];
    BannerBridgeObjC* bidmadObject = [BannerBridgeObjC getInstance:_zoneId];
    [bidmadObject load:y];
}

void BannerBridgeCpp::load(int x, int y) {
    NSString* _zoneId = [NSString stringWithUTF8String: mZoneId];
    BannerBridgeObjC* bidmadObject = [BannerBridgeObjC getInstance:_zoneId];
    [bidmadObject load:x :y];
}

void BannerBridgeCpp::loadWithPosition(int adPosition) {
    NSString *_zoneId = [NSString stringWithUTF8String:mZoneId];
    BannerBridgeObjC *bidmadObject = [BannerBridgeObjC getInstance:_zoneId];
    [bidmadObject loadWithAdPosition:adPosition];
}

void BannerBridgeCpp::setInterval(int interval) {
    NSString* _zoneId = [NSString stringWithUTF8String: mZoneId];
    BannerBridgeObjC* bidmadObject = [BannerBridgeObjC getInstance:_zoneId];
    [bidmadObject setInterval: interval];
}

void BannerBridgeCpp::removeBanner() {
    NSString* _zoneId = [NSString stringWithUTF8String: mZoneId];
    BannerBridgeObjC* bidmadObject = [BannerBridgeObjC getInstance:_zoneId];
    [bidmadObject removeBanner];
}

void BannerBridgeCpp::hideBannerView() {
    NSString* _zoneId = [NSString stringWithUTF8String: mZoneId];
    BannerBridgeObjC* bidmadObject = [BannerBridgeObjC getInstance:_zoneId];
    [bidmadObject hideBannerView];
}

void BannerBridgeCpp::showBannerView() {
    NSString* _zoneId = [NSString stringWithUTF8String: mZoneId];
    BannerBridgeObjC* bidmadObject = [BannerBridgeObjC getInstance:_zoneId];
    [bidmadObject showBannerView];
}

void BannerBridgeCpp::setOnLoadCallback(void (*_onLoadCallback)(char *)){
    onLoadCallback = _onLoadCallback;
}

void BannerBridgeCpp::setOnFailCallback(void (*_onFailCallback)(char *, char *)) {
    onFailCallback = _onFailCallback;
}

void BannerBridgeCpp::callCallback(char* callbackType, char* zoneId, char* errorReason){
    CCLOG("BidmadSDK callCallback : %s  ", callbackType);
    CCLOG("BidmadSDK zoneId : %s  ", zoneId);
    
    if( (strcmp(callbackType, "onLoad") == 0) && (onLoadCallback != nullptr) ){
        onLoadCallback(zoneId);
    }else if( (strcmp(callbackType, "onFail") == 0) && (onFailCallback != nullptr) ){
        onFailCallback(zoneId, errorReason);
    }
}
