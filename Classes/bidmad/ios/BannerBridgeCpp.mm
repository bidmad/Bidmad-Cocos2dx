//
//  BannerBridgeCpp.m
//  BidmadCocos2dxSample-mobile
//
//  Created by ADOP_Mac on 2021/06/29.
//

#include "BannerBridgeCpp.h"
#include "BannerBridgeObjC.h"

BannerBridgeCpp::BannerBridgeCpp(char* zoneId){
    NSLog(@"BidmadSDK, Banner Instance Creation");
    
    mZoneId = zoneId;
    NSString* _zoneId = [NSString stringWithUTF8String: zoneId];
    [[BannerBridgeObjC alloc] initWithZoneId:_zoneId controller:this];
}

void BannerBridgeCpp::load(int y) {
    NSLog(@"BidmadSDK, load");
    
    NSString* _zoneId = [NSString stringWithUTF8String: mZoneId];
    BannerBridgeObjC* bidmadObject = [BannerBridgeObjC getInstance:_zoneId];
    [bidmadObject load:y];
}

void BannerBridgeCpp::load(int x, int y) {
    NSLog(@"BidmadSDK, load");
    
    NSString* _zoneId = [NSString stringWithUTF8String: mZoneId];
    BannerBridgeObjC* bidmadObject = [BannerBridgeObjC getInstance:_zoneId];
    [bidmadObject load:x :y];
}

void BannerBridgeCpp::setInterval(int interval) {
    NSLog(@"BidmadSDK, setInterval");
    
    NSString* _zoneId = [NSString stringWithUTF8String: mZoneId];
    BannerBridgeObjC* bidmadObject = [BannerBridgeObjC getInstance:_zoneId];
    [bidmadObject setInterval: interval];
}

void BannerBridgeCpp::removeBanner() {
    NSLog(@"BidmadSDK, removeBanner");
    
    NSString* _zoneId = [NSString stringWithUTF8String: mZoneId];
    BannerBridgeObjC* bidmadObject = [BannerBridgeObjC getInstance:_zoneId];
    [bidmadObject removeBanner];
}

void BannerBridgeCpp::hideBannerView() {
    NSLog(@"BidmadSDK, hideBannerView");
    
    NSString* _zoneId = [NSString stringWithUTF8String: mZoneId];
    BannerBridgeObjC* bidmadObject = [BannerBridgeObjC getInstance:_zoneId];
    [bidmadObject hideBannerView];
}

void BannerBridgeCpp::showBannerView() {
    NSLog(@"BidmadSDK, showBannerView");
    
    NSString* _zoneId = [NSString stringWithUTF8String: mZoneId];
    BannerBridgeObjC* bidmadObject = [BannerBridgeObjC getInstance:_zoneId];
    [bidmadObject showBannerView];
}

void BannerBridgeCpp::setCUID(char* cuid) {
    NSString *_cuid = [NSString stringWithUTF8String:cuid];
    NSString* _zoneId = [NSString stringWithUTF8String: mZoneId];
    
    BannerBridgeObjC* bidmadObject = [BannerBridgeObjC getInstance:_zoneId];
    [bidmadObject setCUID:_cuid];
}

void BannerBridgeCpp::setOnLoadCallback(void (*_onLoadCallback)( char *)){
    NSLog(@"BidmadSDK, setOnLoadCallback");
    
    onLoadCallback = _onLoadCallback;
}

void BannerBridgeCpp::setOnFailCallback(void (*_onFailCallback)( char *)){
    NSLog(@"BidmadSDK, setOnFailCallback");
    
    onFailCallback = _onFailCallback;
}

void BannerBridgeCpp::callCallback(char* callbackType, char* zoneId){
    CCLOG("BidmadSDK callCallback : %s  ", callbackType);
    CCLOG("BidmadSDK zoneId : %s  ", zoneId);
    
    if( (strcmp(callbackType, "onLoad") == 0) && (onLoadCallback != nullptr) ){
        onLoadCallback(zoneId);
    }else if( (strcmp(callbackType, "onFail") == 0) && (onFailCallback != nullptr) ){
        onFailCallback(zoneId);
    }
}
