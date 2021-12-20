//
//  BIDMADRewardVideo.h
//  BidmadSDK
//
//  Created by 김선정 on 2018. 10. 29..
//  Copyright © 2018년 ADOP Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BIDMADUtil.h"
#import "BIDMADSetting.h"
#import "BIDMADAtomReward.h"
#import "BIDMADAdmanager.h"
#import "BIDMADInterstitial.h"
#import "BIDMADAdMobAppOpenAd.h"

@protocol BIDMADAppOpenAdDelegate;
@protocol BIDMADAppOpenAdInnerDelegate;

@interface BIDMADAppOpenAd : NSObject<BIDMADAppOpenAdInnerDelegate>

@property (nonatomic, strong) id<BIDMADAppOpenAdDelegate> delegate;
@property (nonatomic, strong) id<BIDMADAppOpenAdInnerDelegate> innerDelegate;
@property (strong, nonatomic) NSDictionary*                 ads_dic;
@property (nonatomic) NSString * zoneID;
@property (nonatomic, strong) NSString* userId;
@property (nonatomic, strong) NSString * _Nullable CUID;
@property (nonatomic) BOOL                       isLabelService;
@property (nonatomic) BOOL                       isLabelServiceAdmin;
@property (nonatomic) BOOL                       testMode;
@property (nonatomic) BOOL                       isComplete;
@property (nonatomic) BOOL                       isLoaded;

- (id)      init;
- (void)    showAppOpenAd;
- (void) requestAppOpenAd;
- (void)    selectAds:(NSDictionary *)lv_dic;
- (void) registerForAppOpenAdForZoneID: (NSString *)zoneId;
- (void) deregisterForAppOpenAd;
- (void) UIApplicationDidBecomeActiveAction;

@end

@protocol BIDMADAppOpenAdDelegate <NSObject>
@optional

- (void)BIDMADAppOpenAdAllFail:(BIDMADAppOpenAd *)core code:(NSString *)error;
- (void)BIDMADAppOpenAdLoad:(BIDMADAppOpenAd *)core;
- (void)BIDMADAppOpenAdClose:(BIDMADAppOpenAd *)core;
- (void)BIDMADAppOpenAdShow:(BIDMADAppOpenAd *)core;
- (void)BIDMADAppOpenAdClick:(BIDMADAppOpenAd *)core;

@end

@protocol BIDMADAppOpenAdInnerDelegate <NSObject>
@required

- (void)onAppOpenAdLoad:(BIDMADAppOpenAd *)core       current:(NSDictionary*) currentDic;
- (void)onAppOpenAdError:(NSString *)error failType:(NSString*)failType;
- (void)onAppOpenAdShow:(BIDMADAppOpenAd *)core       current:(NSDictionary*) currentDic;
- (void)onAppOpenAdClick:(BIDMADAppOpenAd *)core      current:(NSDictionary*) currentDic;
- (void)onAppOpenAdClose:(BIDMADAppOpenAd *)core      current:(NSDictionary*) currentDic;

@end
