//
//  OpenBiddingBanner.h
//  OpenBiddingMobileAds
//
//  Created by 김선정 on 2015. 7. 13..
//  Copyright (c) 2015년 ADOP Co., Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <BidmadSDK/BIDMADUtil.h>
#import "OpenBiddingAdmob.h"
#import <BidmadSDK/BidmadSDK.h>

@class OpenBiddingBanner;

@protocol BIDMADOpenBiddingBannerDelegate;

@protocol BIDMADOpenBiddingBannerInnerDelegate <NSObject>

@required

- (void)onBannerAllFail:(OpenBiddingBanner *)core;
- (void)onBannerError:(OpenBiddingBanner *)core code:(NSString *)error failType:(NSString*)failType current:(NSDictionary*)currentDic passbackStr:(NSString*) passBackStr passback:(NSDictionary*) passbackDic;
- (void)onBannerClosed:(OpenBiddingBanner *)core current:(NSDictionary*) currentDic;
- (void)onBannerLoad:(OpenBiddingBanner *)core current:(NSDictionary*) currentDic;
- (void)onBannerClick:(OpenBiddingBanner*) core current:(NSDictionary*) currentDic;

@end

@interface OpenBiddingBanner : UIView<BIDMADOpenBiddingBannerInnerDelegate, BIDMADBannerDelegate>

@property (strong, nonatomic) NSDictionary* ads_dic;
@property (nonatomic) bannerSizeType bannerType;
@property (strong, nonatomic) id<BIDMADOpenBiddingBannerDelegate> delegate;

@property (strong, nonatomic) NSDictionary* ecmp_rev_info;
@property (strong, nonatomic) NSDictionary* area_info;

@property (strong, nonatomic) NSDictionary* change_info;
@property (strong, nonatomic) NSDictionary* date;

@property (nonatomic) NSString* realZoneId;

@property (nonatomic) NSString* zoneID;

@property (nonatomic, assign) int refreshInterval;

@property (nonatomic, strong) NSString* currentAdNetwork;

@property (nonatomic, strong) NSString * _Nullable CUID;

/// Banner Size Parameter is no longer supported, Please use initWithParentViewController:(UIViewController *):(CGPoint)
- (id)initWithParentViewController:(UIViewController *)parentVC adsPosition:(CGPoint)pointn bannerSize:(bannerSizeType) bannerTypeParam __deprecated;
/// Banner Size Parameter is no longer supported, Please use initWithParentViewController:(UIViewController *):(UIView *)
- (id)initWithParentViewController:(UIViewController *)parentVC rootView:(UIView *)view    bannerSize:(bannerSizeType) bannerTypeParam __deprecated;
// INITIALIZE ADS
- (id)initWithParentViewController:(UIViewController *)parentVC adsPosition:(CGPoint)point;
- (id)initWithParentViewController:(UIViewController *)parentVC rootView:(UIView *)view;
- (id)initWithParentViewController:(UIViewController *)parentVC yPoint:(int)yPoint;
/// REQUEST ADS
- (void)requestBannerView;
/// DELETE ADS
- (void)removeAds;
- (void)selectAds:(NSDictionary *)lv_dic isAdsExist:(BOOL)isAds;
- (void)runAds;
- (void)setParentController:(UIViewController *)parentVC;
- (void)hideView;
- (void)showView;

@end

@protocol BIDMADOpenBiddingBannerDelegate <NSObject>

@optional

- (void)BIDMADOpenBiddingBannerAllFail:(OpenBiddingBanner *)core;
- (void)BIDMADOpenBiddingBannerClosed:(OpenBiddingBanner *)core;
- (void)BIDMADOpenBiddingBannerLoad:(OpenBiddingBanner *)core;
- (void)BIDMADOpenBiddingBannerClick:(OpenBiddingBanner*) core;

@end
