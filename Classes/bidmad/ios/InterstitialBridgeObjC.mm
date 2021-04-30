//
//  RewardBridgeObjc.mm
//  BidmadiOS
//
//  Created by Kenneth on 2021/04/24.
//

#include "InterstitialBridgeObjC.h"

@implementation InterstitialBridgeObjC

- (id)initWithZoneId:(NSString *)zoneId controller:(InterstitialBridgeCpp*) controller;
{
    if(BidmadCocos2dxInterstitialDic == nil){
        BidmadCocos2dxInterstitialDic = [[NSMutableDictionary alloc] init];
    }
    
    mZoneId = zoneId;
    mController = controller;
    
    mInterstitialVideo = [[Cocos2dxInterstitial alloc] initWithZoneId:zoneId];
    [mInterstitialVideo setDelegate:self];
    
    [BidmadCocos2dxInterstitialDic setObject:self forKey:zoneId];
    
    return self;
    
}

+ (id)getInstance:(NSString *)zoneId
{
    return [BidmadCocos2dxInterstitialDic objectForKey:zoneId];
}

- (void)loadInterstitial {
    [mInterstitialVideo load];
}

- (void)showInterstitial {
    [mInterstitialVideo show];
}

- (BOOL)isLoaded {
    return [mInterstitialVideo isLoaded];
}

- (void)BIDMADInterstitialLoad:(BIDMADInterstitial *)core {
    char* zoneId = (char *)[core.zoneID UTF8String];
    char* type = (char *)[@"onLoad" UTF8String];
    mController->callCallback(type, zoneId);
}
- (void)BIDMADInterstitialAllFail:(BIDMADInterstitial *)core {
    char* zoneId = (char *)[core.zoneID UTF8String];
    char* type = (char *)[@"onFail" UTF8String];
    mController->callCallback(type, zoneId);
}
- (void)BIDMADInterstitialShow:(BIDMADInterstitial *)core {
    char* zoneId = (char *)[core.zoneID UTF8String];
    char* type = (char *)[@"onShow" UTF8String];
    mController->callCallback(type, zoneId);
}
- (void)BIDMADInterstitialClose:(BIDMADInterstitial *)core {
    char* zoneId = (char *)[core.zoneID UTF8String];
    char* type = (char *)[@"onClose" UTF8String];
    mController->callCallback(type, zoneId);
}

@end
