//
//  OpenBiddingAppOpenAd.h
//  OpenBiddingHelper
//
//  Created by 김선정 on 2018. 10. 29..
//  Copyright © 2018년 ADOP Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <BidmadSDK/BIDMADUtil.h>
#import <BidmadSDK/BIDMADSetting.h>
#import "OpenBiddingAdmobAppOpenAd.h"

@protocol OpenBiddingAppOpenAdDelegate;
@protocol OpenBiddingAppOpenAdInnerDelegate;

@interface OpenBiddingAppOpenAd : NSObject<OpenBiddingAppOpenAdInnerDelegate, BIDMADAppOpenAdDelegate>

@property (nonatomic, strong) id<OpenBiddingAppOpenAdDelegate> delegate;
@property (nonatomic, strong) id<OpenBiddingAppOpenAdInnerDelegate> innerDelegate;
@property (strong, nonatomic) NSDictionary*                 ads_dic;
@property (nonatomic) NSString * zoneID;
@property (nonatomic, strong) NSString* userId;
@property (nonatomic) BOOL                       testMode;
@property (nonatomic) BOOL                       isComplete;
@property (nonatomic) BOOL                       isLoaded;

- (id)      init;
- (void)    showAppOpenAd;
- (void) requestAppOpenAd;
- (void)    selectAds:(NSDictionary *)lv_dic;
- (void) sendLog :(NSDictionary *)info : (NSString *)advertisementType : (NSString *)logType :(NSString *)sessionIdArg;
- (void) registerForAppOpenAdForZoneID: (NSString *)zoneId;
- (void) deregisterForAppOpenAd;

- (void)BIDMADAppOpenAdAllFail:(BIDMADAppOpenAd *)core code:(NSString *)error;
- (void)BIDMADAppOpenAdLoad:(BIDMADAppOpenAd *)core;
- (void)BIDMADAppOpenAdClose:(BIDMADAppOpenAd *)core;
- (void)BIDMADAppOpenAdShow:(BIDMADAppOpenAd *)core;

@end

@protocol OpenBiddingAppOpenAdDelegate <NSObject>
@optional

- (void)OpenBiddingAppOpenAdAllFail:(OpenBiddingAppOpenAd *)core code:(NSString *)error;
- (void)OpenBiddingAppOpenAdLoad:(OpenBiddingAppOpenAd *)core;
- (void)OpenBiddingAppOpenAdClose:(OpenBiddingAppOpenAd *)core;
- (void)OpenBiddingAppOpenAdShow:(OpenBiddingAppOpenAd *)core;

@end

@protocol OpenBiddingAppOpenAdInnerDelegate <NSObject>
@required

- (void)onAppOpenAdLoad:(OpenBiddingAppOpenAd *)core       current:(NSDictionary*) currentDic;
- (void)onAppOpenAdError:(OpenBiddingAppOpenAd *)core code:(NSString *)error failType:(NSString*)failType current:(NSDictionary*)currentDic passbackStr:(NSString*) passBackStr passback:(NSDictionary*) passbackDic;
- (void)onAppOpenAdShow:(OpenBiddingAppOpenAd *)core       current:(NSDictionary*) currentDic;
- (void)onAppOpenAdClick:(OpenBiddingAppOpenAd *)core      current:(NSDictionary*) currentDic;
- (void)onAppOpenAdClose:(OpenBiddingAppOpenAd *)core      current:(NSDictionary*) currentDic;

@end
