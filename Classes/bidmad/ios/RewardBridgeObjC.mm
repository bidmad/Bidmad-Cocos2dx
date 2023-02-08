//
//  RewardBridgeObjc.mm
//  BidmadiOS
//
//  Created by Kenneth on 2021/04/24.
//

#include "RewardBridgeObjC.h"
#import "BidmadCocos2DXSharedState.h"
#import <ADOPUtility/NSArray+HigherOrderFunctionsForADOP.h>

@interface RewardSharedState : NSObject <BIDMADOpenBiddingRewardVideoDelegate>

+ (RewardSharedState *)shared;
@property (nonatomic, strong) NSMutableArray<RewardBridgeObjC *> *rewards;

@end

@implementation RewardSharedState

+ (RewardSharedState *)shared {
    static dispatch_once_t pred = 0;
    __strong static RewardSharedState * _sharedObject = nil;
    dispatch_once(&pred, ^{
        _sharedObject = ^{
            RewardSharedState *instance = [[RewardSharedState alloc] init];
            instance.rewards = [[NSMutableArray alloc] init];
            [BidmadRewardAdForGame setDelegate:instance];
            return instance;
        }();
    });
    return _sharedObject;
}

- (void)onLoadAd:(OpenBiddingRewardVideo *)bidmadAd {
    [self callbackForTarget:bidmadAd action:^(RewardBridgeObjC *reward) {
        [reward onLoadAd:bidmadAd];
    }];
}

- (void)onShowAd:(OpenBiddingRewardVideo *)bidmadAd {
    [self callbackForTarget:bidmadAd action:^(RewardBridgeObjC *reward) {
        [reward onShowAd:bidmadAd];
    }];
}

- (void)onCompleteAd:(OpenBiddingRewardVideo *)bidmadAd {
    [self callbackForTarget:bidmadAd action:^(RewardBridgeObjC *reward) {
        [reward onCompleteAd:bidmadAd];
    }];
}

- (void)onSkipAd:(OpenBiddingRewardVideo *)bidmadAd {
    [self callbackForTarget:bidmadAd action:^(RewardBridgeObjC *reward) {
        [reward onSkipAd:bidmadAd];
    }];
}

- (void)onLoadFailAd:(OpenBiddingRewardVideo *)bidmadAd error:(NSError *)error {
    [self callbackForTarget:bidmadAd action:^(RewardBridgeObjC *reward) {
        [reward onLoadFailAd:bidmadAd error:error];
    }];
}

- (void)onClickAd:(OpenBiddingRewardVideo *)bidmadAd {
    [self callbackForTarget:bidmadAd action:^(RewardBridgeObjC *reward) {
        [reward onClickAd:bidmadAd];
    }];
}

- (void)onCloseAd:(OpenBiddingRewardVideo *)bidmadAd {
    [self callbackForTarget:bidmadAd action:^(RewardBridgeObjC *reward) {
        [reward onCloseAd:bidmadAd];
    }];
}

- (void)callbackForTarget:(OpenBiddingRewardVideo *)bidmadAd action:(void(^)(RewardBridgeObjC *))action {
    RewardBridgeObjC *callbackTarget =
        [[self.rewards filterForADOP:^BOOL(RewardBridgeObjC *reward) {
            return [reward.mZoneId isEqualToString:bidmadAd.zoneID];
        }] firstObject];
    
    if (callbackTarget != nil) {
        action(callbackTarget);
    }
}

@end

@implementation RewardBridgeObjC

- (id)initWithZoneId:(NSString *)zoneId controller:(RewardBridgeCpp*) controller;
{
    self = [super init];
    
    if (self) {
        _mZoneId = zoneId;
        mController = controller;
        
        [BidmadRewardAdForGame initialSetupForZoneID:self.mZoneId];
        
        RewardBridgeObjC *removeTarget =
            [[RewardSharedState.shared.rewards filterForADOP:^BOOL(RewardBridgeObjC *reward) {
                return [reward.mZoneId isEqualToString:zoneId];
            }] firstObject];
        
        if (removeTarget != nil) {
            [RewardSharedState.shared.rewards removeObject:removeTarget];
        }
        
        [RewardSharedState.shared.rewards addObject:self];
    }
    
    return self;
}

+ (void)initialSetupWithZoneId:(NSString *)zoneId controller:(RewardBridgeCpp *)controller {
    if (BidmadCocos2dxRewardDic == nil) {
        BidmadCocos2dxRewardDic = [[NSMutableDictionary alloc] init];
    }
    
    RewardBridgeObjC *bridge = [BidmadCocos2dxRewardDic objectForKey:zoneId];
    if (bridge == nil) {
        bridge = [[RewardBridgeObjC alloc] initWithZoneId:zoneId controller:controller];
        [BidmadCocos2dxRewardDic setObject:bridge forKey:zoneId];
    }
    
    bridge->mController = controller;
}

+ (id)getInstance:(NSString *)zoneId
{
    return [BidmadCocos2dxRewardDic objectForKey:zoneId];
}

- (void) loadRewardVideo {
    [BidmadRewardAdForGame loadWithZoneID:self.mZoneId];
}

- (void) showRewardVideo {
    [BidmadRewardAdForGame showWithZoneID:self.mZoneId viewController:[BidmadCocos2DXSharedState.shared cocosViewController]];
}

- (BOOL) isLoaded {
    return [BidmadRewardAdForGame isLoadedWithZoneID:self.mZoneId];
}

- (void)setAutoReload:(bool)isAutoReload {
    [BidmadRewardAdForGame setAutoReload:isAutoReload];
}

- (void)onLoadAd:(OpenBiddingRewardVideo *)bidmadAd {
    char* zoneId = (char *)[bidmadAd.zoneID UTF8String];
    char* type = (char *)[@"onLoad" UTF8String];
    mController->callCallback(type, zoneId, nullptr);
}

- (void)onShowAd:(OpenBiddingRewardVideo *)bidmadAd {
    char* zoneId = (char *)[bidmadAd.zoneID UTF8String];
    char* type = (char *)[@"onShow" UTF8String];
    mController->callCallback(type, zoneId, nullptr);
}

- (void)onCompleteAd:(OpenBiddingRewardVideo *)bidmadAd {
    char* zoneId = (char *)[bidmadAd.zoneID UTF8String];
    char* type = (char *)[@"onComplete" UTF8String];
    mController->callCallback(type, zoneId, nullptr);
}

- (void)onSkipAd:(OpenBiddingRewardVideo *)bidmadAd {
    char* zoneId = (char *)[bidmadAd.zoneID UTF8String];
    char* type = (char *)[@"onSkip" UTF8String];
    mController->callCallback(type, zoneId, nullptr);
}

- (void)onLoadFailAd:(OpenBiddingRewardVideo *)bidmadAd error:(NSError *)error {
    char* zoneId = (char *)[bidmadAd.zoneID UTF8String];
    char* type = (char *)[@"onFail" UTF8String];
    mController->callCallback(type, zoneId, (char *)[error.localizedDescription UTF8String]);
}

- (void)onClickAd:(OpenBiddingRewardVideo *)bidmadAd {
    // Cocos2DX Interface does not support click callbacks.
}

- (void)onCloseAd:(OpenBiddingRewardVideo *)bidmadAd {
    char* zoneId = (char *)[bidmadAd.zoneID UTF8String];
    char* type = (char *)[@"onClose" UTF8String];
    mController->callCallback(type, zoneId, nullptr);
}

@end
