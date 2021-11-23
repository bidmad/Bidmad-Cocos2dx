//
//  UnityRewardInterstitial.h
//  BidmadSDK
//
//  Created by ADOP_Mac on 2021/07/09.
//  Copyright © 2021 ADOP Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <BidmadSDK/BIDMADSetting.h>
#import "OpenBiddingRewardInterstitial.h"

@interface OpenBiddingUnityRewardInterstitial : NSObject<OpenBiddingRewardInterstitialDelegate>

+ (id)sharedInstance;

- (void)openBiddingNewInstanceRewardInterstitial:(NSString *)zoneId withDelegate:(id<OpenBiddingRewardInterstitialDelegate>)delegate parentVC:(UIViewController *)parentVC;
- (void)openBiddingLoadRewardInterstitial:(NSString *)zoneId;
- (void)openBiddingShowRewardInterstitial:(NSString *)zoneId;
- (bool)openBiddingIsLoadedRewardInterstitial:(NSString *)zoneId;
- (void)setAutoReload:(bool)isAutoReload;
- (void)setCUID:(NSString *)cuid;

@end
