//
//  BIDMADInterstitial.h
//  BIDMADSDK
//
//  Created by 김선정 on 2015. 7. 15..
//  Copyright (c) 2015년 ADOP Co., Ltd. All rights reserved.
//

@class OpenBiddingInterstitial;

#import <Foundation/Foundation.h>
#import <BidmadSDK/BIDMADUtil.h>
#import <BidmadSDK/BIDMADSetting.h>
#import "OpenBiddingAdmob.h"


@protocol BIDMADOpenBiddingInterstitialDelegate <NSObject>

@optional

- (void)BIDMADOpenBiddingInterstitialAllFail:(OpenBiddingInterstitial *)core;

/// PREPARED INTERSTITIAL VIEW
- (void)BIDMADOpenBiddingInterstitialLoad:(OpenBiddingInterstitial *)core;

/// CLOSE INTERSTITIAL VIEW
- (void)BIDMADOpenBiddingInterstitialClose:(OpenBiddingInterstitial *)core;

/// SHOW INTERSTITIAL VIEW
- (void)BIDMADOpenBiddingInterstitialShow:(OpenBiddingInterstitial *)core;

@end

@protocol BIDMADOpenBiddingInterstitialInnerDelegate <NSObject>
@required

- (void)onInterstitialLoad:(OpenBiddingInterstitial *)core       current:(NSDictionary*) currentDic;
- (void)onInterstitialError:(OpenBiddingInterstitial *)core code:(NSString *)error failType:(NSString*)failType current:(NSDictionary*)currentDic passbackStr:(NSString*) passBackStr passback:(NSDictionary*) passbackDic;
- (void)onInterstitialShow:(OpenBiddingInterstitial *)core       current:(NSDictionary*) currentDic;
- (void)onInterstitialClick:(OpenBiddingInterstitial *)core      current:(NSDictionary*) currentDic;
- (void)onInterstitialClose:(OpenBiddingInterstitial *)core      current:(NSDictionary*) currentDic;

@end


@interface OpenBiddingInterstitial : NSObject <BIDMADOpenBiddingInterstitialInnerDelegate, BIDMADInterstitialDelegate>

@property (nonatomic, strong) id<BIDMADOpenBiddingInterstitialDelegate> delegate;

@property (nonatomic, strong) id<BIDMADOpenBiddingInterstitialInnerDelegate> innerDelegate;

@property (nonatomic, strong) UIViewController* parentViewController;

@property (strong, nonatomic) NSDictionary*             ads_dic;

@property (strong, nonatomic) NSDictionary*                      ecmp_rev_info;
@property (strong, nonatomic) NSDictionary*                      area_info;

@property (strong, nonatomic) NSDictionary*                    change_info;
@property (strong, nonatomic) NSDictionary*                    date;

@property (nonatomic) NSString * zoneID;

@property (nonatomic) bool justLoading;

@property (nonatomic) NSString *                 realZoneId;

@property (nonatomic) BOOL                       isLoaded;

@property (nonatomic, strong) NSString * _Nullable CUID;

///inititalize
- (id)init;

///InterstitialView Load
- (void)loadInterstitialView;

///InterstitialView Show
- (void)showInterstitialView;

/// 삭제할것
- (void)selectAds:(NSDictionary *)lv_dic;

- (void)removeInterstitialADS;

@end




