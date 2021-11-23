//
//  BIDMADAdx.h
//  BidmadSDK
//
//  Created by 김선정 on 2017. 6. 19..
//  Copyright © 2017년 ADOP Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "OpenBiddingBanner.h"
#import "OpenBiddingInterstitial.h"
#import "OpenBiddingRewardVideo.h"
#import "OpenBiddingRewardInterstitial.h"

#import <BidmadSDK/BIDMADUtil.h>
#if __has_include(<GoogleMobileAds/GoogleMobileAds.h>)
#import <GoogleMobileAds/GoogleMobileAds.h>
#import <BidmadSDK/BidmadSDK.h>
#define GOOGLESDK_EXIST
#endif

@class OpenBiddingBanner;
@class OpenBiddingInterstitial;
@class OpenBiddingRewardVideo;
@class OpenBiddingRewardInterstitial;

#ifdef GOOGLESDK_EXIST
@interface OpenBiddingAdmob : NSObject<GADBannerViewDelegate, GADFullScreenContentDelegate>

#else
@interface OpenBiddingAdmob : NSObject
#endif

@property (weak,nonatomic) OpenBiddingBanner* banner;
@property (weak,nonatomic) OpenBiddingInterstitial* interstitial;
@property (strong,nonatomic) OpenBiddingRewardVideo* rewardVideo;

- (id)initWithAdBanner:(NSDictionary *)dic OpenBiddingBanner:(OpenBiddingBanner *)banner;
- (id)initWithAdBanner:(NSDictionary *)dict BidmadBanner:(BIDMADBanner *)banner;

- (id)initWithInterstitial:(NSDictionary *)dic OpenBiddingInterstitial:(OpenBiddingInterstitial *)interstitial;
- (id)initWithInterstitial:(NSDictionary *)dict BidmadInterstitial:(BIDMADInterstitial *)interstitial;

- (id)initWithRewardVideo:(NSDictionary *)dic OpenBiddingReward:(OpenBiddingRewardVideo *)rewardVideo userId:(NSString *) userId;
- (id)initWithRewardVideo:(NSDictionary *)dict BidmadReward:(BIDMADRewardVideo *)rewardVideo userID:(NSString *)userID;

- (id)initWithRewardInterstitial:(NSDictionary *)dic openBiddingRewardInterstitial:(OpenBiddingRewardInterstitial *)rewardInterstitialArg;
- (id)initWithRewardInterstitial:(NSDictionary *)dict BidmadRewardInterstitial:(BIDMADRewardInterstitial *)rewardInterstitial;

- (void)loadAdmobRewardInterstitial:(UIViewController *)pvc;
- (void)showAdmobRewardInterstitial;
- (void)removeRewardInterstitialAds;

- (void)showAdmobBanner:(UIViewController *)pvc bannerContainer:(UIView*)bannerContainer;
- (void)showAdmobInterstitial:(UIViewController *)pvc;
- (void)showAdmobRewardVideo: (UIViewController *)pvc;

- (void)removeBannerAds;
- (void)removeInterstitialAds;
- (void)gogoInterstitial;
- (void)gogoRewardVideo;

- (void)setTestDevice:(NSString *) deviceId;

@end
