//
//  BannerBridgeCpp.m
//  BidmadCocos2dxSample-mobile
//
//  Created by ADOP_Mac on 2021/06/29.
//

#include "BannerBridgeObjC.h"
//#include <FBAudienceNetwork/FBAudienceNetwork.h>

@implementation BannerBridgeObjC

- (id)initWithZoneId:(NSString *)zoneId controller:(BannerBridgeCpp *)controller
{
    NSLog(@"BidmadSDK initWithZoneId");
    
    if(BidmadCocos2dxBannerDic == nil){
        BidmadCocos2dxBannerDic = [[NSMutableDictionary alloc] init];
    }
    
    mZoneId = zoneId;
    mController = controller;
    
    mBanner = [[OpenBiddingCocos2dxBanner alloc] initWithZoneID:zoneId];
    [mBanner setDelegate:self];
    
    [BidmadCocos2dxBannerDic setObject:self forKey:zoneId];
    
    return self;
}

+ (id)getInstance:(NSString *)zoneId
{
    NSLog(@"BidmadSDK, getInstance");
    return [BidmadCocos2dxBannerDic objectForKey:zoneId];
}

- (void)load:(int)y {
    NSLog(@"BidmadSDK, load");
    
    [mBanner load:y];
}

- (void)load:(int)x :(int)y {
    NSLog(@"BidmadSDK, load");
    [mBanner load:x :y];
}

- (void)setInterval:(int)interval {
    NSLog(@"BidmadSDK, setInterval");
    [mBanner setInterval:interval];
}

- (void)removeBanner {
    NSLog(@"BidmadSDK, removeBanner");
    [mBanner removeBanner];
}

- (void)hideBannerView {
    NSLog(@"BidmadSDK, hideBannerView");
    [mBanner hideBannerView];
}

- (void)showBannerView {
    NSLog(@"BidmadSDK, showBannerView");
    [mBanner showBannerView];
}

- (void)setCUID:(NSString *)cuid {
    [mBanner setCUID:cuid];
}

- (void)BIDMADOpenBiddingBannerAllFail:(OpenBiddingBanner *)core {
    char* zoneId = (char *)[core.zoneID UTF8String];
    char* type = (char *)[@"onFail" UTF8String];
    mController->callCallback(type, zoneId);
}

- (void)BIDMADOpenBiddingBannerClosed:(BIDMADBanner *)core {}

- (void)BIDMADOpenBiddingBannerLoad:(BIDMADBanner *)core {
    char* zoneId = (char *)[core.zoneID UTF8String];
    char* type = (char *)[@"onLoad" UTF8String];
    mController->callCallback(type, zoneId);
}

- (void)BIDMADOpenBiddingBannerClick:(BIDMADBanner*) core {}

@end
