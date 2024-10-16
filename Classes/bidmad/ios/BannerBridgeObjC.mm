//
//  BannerBridgeCpp.m
//  BidmadCocos2dxSample-mobile
//
//  Created by ADOP_Mac on 2021/06/29.
//

#include "BannerBridgeObjC.h"
#import "BidmadCocos2DXSharedState.h"

@interface BannerSharedState : NSObject <BIDMADOpenBiddingBannerDelegate>

+ (BannerSharedState *)shared;
@property (nonatomic, strong) NSMutableArray<BannerBridgeObjC *> *banners;

@end

@implementation BannerSharedState

+ (BannerSharedState *)shared {
    static dispatch_once_t pred = 0;
    __strong static BannerSharedState * _sharedObject = nil;
    dispatch_once(&pred, ^{
        _sharedObject = ^{
            BannerSharedState *instance = [[BannerSharedState alloc] init];
            instance.banners = [[NSMutableArray alloc] init];
            [BidmadBannerAdForGame setDelegate:instance];
            return instance;
        }();
    });
    return _sharedObject;
}

- (void)onLoadAd:(OpenBiddingBanner *)bidmadAd {
    [self callbackForTarget:bidmadAd action:^(BannerBridgeObjC *banner) {
        [banner onLoadAd:bidmadAd];
    }];
}

- (void)onLoadFailAd:(OpenBiddingBanner *)bidmadAd error:(NSError *)error {
    [self callbackForTarget:bidmadAd action:^(BannerBridgeObjC *banner) {
        [banner onLoadFailAd:bidmadAd error:error];
    }];
}

- (void)onClickAd:(OpenBiddingBanner *)bidmadAd {
    [self callbackForTarget:bidmadAd action:^(BannerBridgeObjC *banner) {
        [banner onClickAd:bidmadAd];
    }];
}

- (void)callbackForTarget:(OpenBiddingBanner *)bidmadAd action:(void(^)(BannerBridgeObjC *))action {
    BannerBridgeObjC *callbackTarget =
        [[self.banners filterForADOP:^BOOL(BannerBridgeObjC *banner) {
            return [banner.mZoneId isEqualToString:bidmadAd.zoneID];
        }] firstObject];
    
    if (callbackTarget != nil) {
        action(callbackTarget);
    }
}

@end

@implementation BannerBridgeObjC

- (id)initWithZoneId:(NSString *)zoneId controller:(BannerBridgeCpp *)controller {
    self = [super init];
    
    if (self) {
        _mZoneId = zoneId;
        mController = controller;
        
        [BidmadCocos2dxBannerDic setObject:self forKey:zoneId];
        
        BannerBridgeObjC *removeTarget =
            [[BannerSharedState.shared.banners filterForADOP:^BOOL(BannerBridgeObjC *banner) {
                return [banner.mZoneId isEqualToString:zoneId];
            }] firstObject];
        
        if (removeTarget != nil) {
            [BannerSharedState.shared.banners removeObject:removeTarget];
        }
        
        [BannerSharedState.shared.banners addObject:self];
    }
    
    return self;
}

+ (void)initialSetupWithZoneId:(NSString *)zoneId controller:(BannerBridgeCpp *)controller {
    if (BidmadCocos2dxBannerDic == nil) {
        BidmadCocos2dxBannerDic = [[NSMutableDictionary alloc] init];
    }
    
    BannerBridgeObjC *bridge = [BidmadCocos2dxBannerDic objectForKey:zoneId];
    if (bridge == nil) {
        bridge = [[BannerBridgeObjC alloc] initWithZoneId:zoneId controller:controller];
        [BidmadCocos2dxBannerDic setObject:bridge forKey:zoneId];
    }
    
    bridge->mController = controller;
}

+ (id)getInstance:(NSString *)zoneId {
    return [BidmadCocos2dxBannerDic objectForKey:zoneId];
}

- (void)callLoad {
    [BidmadBannerAdForGame setRefreshInterval:mRefreshInterval withZoneID:self.mZoneId];
    [BidmadBannerAdForGame loadWithZoneID:self.mZoneId];
}

- (void)load:(int)y {
    [BidmadBannerAdForGame initialSetupForZoneID:self.mZoneId viewController:[BidmadCocos2DXSharedState.shared cocosViewController] yCoordinate:(CGFloat)y];
    [self callLoad];
}

- (void)load:(int)x :(int)y {
    [BidmadBannerAdForGame initialSetupForZoneID:self.mZoneId viewController:[BidmadCocos2DXSharedState.shared cocosViewController] xCoordinate:(CGFloat)x yCoordinate:(CGFloat)y];
    [self callLoad];
}

- (void)loadWithAdPosition:(int)position {
    [BidmadBannerAdForGame initialSetupForZoneID:self.mZoneId viewController:[BidmadCocos2DXSharedState.shared cocosViewController] adPosition:(BIDMADAdPosition)position];
    [self callLoad];
}

- (void)setInterval:(int)interval {
    mRefreshInterval = (NSInteger)interval;
}

- (void)removeBanner {
    [BidmadBannerAdForGame removeWithZoneID:self.mZoneId];
}

- (void)hideBannerView {
    [BidmadBannerAdForGame hideWithZoneID:self.mZoneId];
}

- (void)showBannerView {
    [BidmadBannerAdForGame showWithZoneID:self.mZoneId];
}

- (void)onLoadAd:(OpenBiddingBanner *)bidmadAd {
    char* zoneId = (char *)[bidmadAd.zoneID UTF8String];
    char* type = (char *)[@"onLoad" UTF8String];
    mController->callCallback(type, zoneId, nullptr);
}

- (void)onLoadFailAd:(OpenBiddingBanner *)bidmadAd error:(NSError *)error {
    char* zoneId = (char *)[bidmadAd.zoneID UTF8String];
    char* type = (char *)[@"onFail" UTF8String];
    mController->callCallback(type, zoneId, (char *)[error.localizedDescription UTF8String]);
}

- (void)onClickAd:(OpenBiddingBanner *)bidmadAd {
    // Cocos2DX Interface does not support click callback
}

@end
