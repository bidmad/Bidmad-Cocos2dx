//
//  BannerBridgeCpp.h
//  BidmadCocos2dxSample-mobile
//
//  Created by ADOP_Mac on 2021/06/29.
//

#ifndef BannerBridgeObjC_h
#define BannerBridgeObjC_h

#include "BannerBridgeCpp.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <BidmadSDK/BidmadSDK.h>
#import <BidmadSDK/BidmadSDK-Swift.h>
#import <OpenBiddingHelper/OpenBiddingHelper.h>
#import <OpenBiddingHelper/OpenBiddingHelper-Swift.h>
#import <OpenBiddingHelper/BidmadBannerAdForGame.h>

static NSMutableDictionary* BidmadCocos2dxBannerDic;

@interface BannerBridgeObjC : NSObject <BIDMADOpenBiddingBannerDelegate>{
    NSInteger mRefreshInterval;
    BannerBridgeCpp *mController;
}

@property (nonatomic, strong) NSString * _Nonnull mZoneId;

+ (void)initialSetupWithZoneId:(NSString *)zoneId controller:(BannerBridgeCpp *)controller;
+ (id)getInstance:(NSString *)zoneId;
- (void)load:(int)y;
- (void)load:(int)x :(int)y;
- (void)loadWithAdPosition:(int)position;
- (void)setInterval:(int)interval;
- (void)removeBanner;
- (void)hideBannerView;
- (void)showBannerView;

@end


#endif /* RewardBridgeObjC_h */
