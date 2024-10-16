//
//  InterstitialBridgeObjc.mm
//  BidmadiOS
//
//  Created by Kenneth on 2021/04/24.
//

#include "InterstitialBridgeObjC.h"
#import "BidmadCocos2DXSharedState.h"

@interface InterstitialSharedState : NSObject <BIDMADOpenBiddingInterstitialDelegate>

+ (InterstitialSharedState *)shared;
@property (nonatomic, strong) NSMutableArray<InterstitialBridgeObjC *> *interstitials;

@end

@implementation InterstitialSharedState

+ (InterstitialSharedState *)shared {
    static dispatch_once_t pred = 0;
    __strong static InterstitialSharedState * _sharedObject = nil;
    dispatch_once(&pred, ^{
        _sharedObject = ^{
            InterstitialSharedState *instance = [[InterstitialSharedState alloc] init];
            instance.interstitials = [[NSMutableArray alloc] init];
            [BidmadInterstitialAdForGame setDelegate:instance];
            return instance;
        }();
    });
    return _sharedObject;
}

- (void)onLoadAd:(OpenBiddingInterstitial *)bidmadAd {
    [self callbackForTarget:bidmadAd action:^(InterstitialBridgeObjC *interstitial) {
        [interstitial onLoadAd:bidmadAd];
    }];
}

- (void)onLoadFailAd:(OpenBiddingInterstitial *)bidmadAd error:(NSError *)error {
    [self callbackForTarget:bidmadAd action:^(InterstitialBridgeObjC *interstitial) {
        [interstitial onLoadFailAd:bidmadAd error:error];
    }];
}

- (void)onShowAd:(OpenBiddingInterstitial *)bidmadAd {
    [self callbackForTarget:bidmadAd action:^(InterstitialBridgeObjC *interstitial) {
        [interstitial onShowAd:bidmadAd];
    }];
}

- (void)onClickAd:(OpenBiddingInterstitial *)bidmadAd {
    [self callbackForTarget:bidmadAd action:^(InterstitialBridgeObjC *interstitial) {
        [interstitial onClickAd:bidmadAd];
    }];
}

- (void)onCloseAd:(OpenBiddingInterstitial *)bidmadAd {
    [self callbackForTarget:bidmadAd action:^(InterstitialBridgeObjC *interstitial) {
        [interstitial onCloseAd:bidmadAd];
    }];
}

- (void)callbackForTarget:(OpenBiddingInterstitial *)bidmadAd action:(void(^)(InterstitialBridgeObjC *))action {
    InterstitialBridgeObjC *callbackTarget =
        [[self.interstitials filterForADOP:^BOOL(InterstitialBridgeObjC *interstitial) {
            return [interstitial.mZoneId isEqualToString:bidmadAd.zoneID];
        }] firstObject];
    
    if (callbackTarget != nil) {
        action(callbackTarget);
    }
}

@end

@implementation InterstitialBridgeObjC

- (id)initWithZoneId:(NSString *)zoneId controller:(InterstitialBridgeCpp*) controller;
{
    self = [super init];
    
    if (self) {
        _mZoneId = zoneId;
        mController = controller;
        
        [BidmadInterstitialAdForGame initialSetupForZoneID:self.mZoneId];
        
        InterstitialBridgeObjC *removeTarget =
            [[InterstitialSharedState.shared.interstitials filterForADOP:^BOOL(InterstitialBridgeObjC *interstitial) {
                return [interstitial.mZoneId isEqualToString:zoneId];
            }] firstObject];
        
        if (removeTarget != nil) {
            [InterstitialSharedState.shared.interstitials removeObject:removeTarget];
        }
        
        [InterstitialSharedState.shared.interstitials addObject:self];
    }
    
    return self;
}

+ (void)initialSetupWithZoneId:(NSString *)zoneId controller:(InterstitialBridgeCpp *)controller {
    if (BidmadCocos2dxInterstitialDic == nil) {
        BidmadCocos2dxInterstitialDic = [[NSMutableDictionary alloc] init];
    }
    
    InterstitialBridgeObjC *bridge = [BidmadCocos2dxInterstitialDic objectForKey:zoneId];
    if (bridge == nil) {
        bridge = [[InterstitialBridgeObjC alloc] initWithZoneId:zoneId controller:controller];
        [BidmadCocos2dxInterstitialDic setObject:bridge forKey:zoneId];
    }
    
    bridge->mController = controller;
}

+ (id)getInstance:(NSString *)zoneId
{
    return [BidmadCocos2dxInterstitialDic objectForKey:zoneId];
}

- (void)loadInterstitial {
    [BidmadInterstitialAdForGame loadWithZoneID:self.mZoneId];
}

- (void)showInterstitial {
    [BidmadInterstitialAdForGame showWithZoneID:self.mZoneId viewController:[BidmadCocos2DXSharedState.shared cocosViewController]];
}

- (BOOL)isLoaded {
    return [BidmadInterstitialAdForGame isLoadedWithZoneID:self.mZoneId];
}

- (void)setAutoReload:(bool)isAutoReload {
    [BidmadInterstitialAdForGame setAutoReload:isAutoReload];
}

- (void)onLoadAd:(OpenBiddingInterstitial *)bidmadAd {
    char* zoneId = (char *)[bidmadAd.zoneID UTF8String];
    char* type = (char *)[@"onLoad" UTF8String];
    mController->callCallback(type, zoneId, nullptr);
}

- (void)onLoadFailAd:(OpenBiddingInterstitial *)bidmadAd error:(NSError *)error {
    char* zoneId = (char *)[bidmadAd.zoneID UTF8String];
    char* type = (char *)[@"onFail" UTF8String];
    mController->callCallback(type, zoneId, (char *)[error.localizedDescription UTF8String]);
}

- (void)onShowAd:(OpenBiddingInterstitial *)bidmadAd {
    char* zoneId = (char *)[bidmadAd.zoneID UTF8String];
    char* type = (char *)[@"onShow" UTF8String];
    mController->callCallback(type, zoneId, nullptr);
}

- (void)onClickAd:(OpenBiddingInterstitial *)bidmadAd {
    // Cocos2DX Interface does not support click callbacks.
}

- (void)onCloseAd:(OpenBiddingInterstitial *)bidmadAd {
    char* zoneId = (char *)[bidmadAd.zoneID UTF8String];
    char* type = (char *)[@"onClose" UTF8String];
    mController->callCallback(type, zoneId, nullptr);
}

@end
