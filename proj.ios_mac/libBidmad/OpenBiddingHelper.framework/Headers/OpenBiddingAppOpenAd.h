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
#import <BidmadSDK/BIDMADAppOpenAd.h>
#import "OpenBiddingAdmobAppOpenAd.h"

@protocol OpenBiddingAppOpenAdDelegate;

@interface OpenBiddingAppOpenAd : NSObject<BIDMADAppOpenAdDelegate>

@property (nonatomic, strong) id<OpenBiddingAppOpenAdDelegate> _Nullable delegate;
@property (strong, nonatomic) NSDictionary*                    _Nullable ads_dic;
@property (nonatomic)         NSString*                        _Nullable zoneID;
@property (nonatomic, strong) NSString*                        _Nullable userId;
@property (nonatomic, strong) NSString*                        _Nullable CUID;
@property (nonatomic, strong) BIDMADAppOpenAd*                 _Nullable bidmadAppOpenAd;
@property (nonatomic)         BOOL                                       testMode;
@property (nonatomic)         BOOL                                       isComplete;
@property (nonatomic)         BOOL                                       isLoaded;
@property (nonatomic)         BOOL                                       isBidmadLoaded;
@property (nonatomic)         BOOL                                       isDisplayingAd;

- (id _Nonnull) init;
- (void) showAppOpenAd;
- (void) requestAppOpenAd;
- (void) selectAds:(NSDictionary * _Nullable)lv_dic;
- (void) sendLog :(NSDictionary * _Nonnull)info : (NSString * _Nonnull)advertisementType : (NSString * _Nonnull)logType :(NSString * _Nonnull)sessionIdArg;
- (void) registerForAppOpenAdForZoneID:(NSString * _Nonnull)zoneId;
- (void) deregisterForAppOpenAd;
- (void) UIApplicationDidBecomeActiveAction;

- (void)BIDMADAppOpenAdAllFail:(BIDMADAppOpenAd * _Nonnull)core;
- (void)BIDMADAppOpenAdLoad:(BIDMADAppOpenAd * _Nonnull)core;
- (void)BIDMADAppOpenAdClose:(BIDMADAppOpenAd * _Nonnull)core;
- (void)BIDMADAppOpenAdShow:(BIDMADAppOpenAd * _Nonnull)core;

- (void)onAppOpenAdLoad:(OpenBiddingAppOpenAd * _Nonnull)core current:(NSDictionary* _Nullable)currentDic;
- (void)onAppOpenAdError;
- (void)onAppOpenAdShow:(OpenBiddingAppOpenAd * _Nonnull)core current:(NSDictionary* _Nullable)currentDic;
- (void)onAppOpenAdClick:(OpenBiddingAppOpenAd * _Nonnull)core current:(NSDictionary* _Nullable)currentDic;
- (void)onAppOpenAdClose:(OpenBiddingAppOpenAd * _Nonnull)core current:(NSDictionary* _Nullable)currentDic;

@end

@protocol OpenBiddingAppOpenAdDelegate <NSObject>
@optional

- (void)OpenBiddingAppOpenAdAllFail:(OpenBiddingAppOpenAd * _Nonnull)core;
- (void)OpenBiddingAppOpenAdLoad:(OpenBiddingAppOpenAd * _Nonnull)core;
- (void)OpenBiddingAppOpenAdClose:(OpenBiddingAppOpenAd * _Nonnull)core;
- (void)OpenBiddingAppOpenAdShow:(OpenBiddingAppOpenAd * _Nonnull)core;
- (void)OpenBiddingAppOpenAdClick:(OpenBiddingAppOpenAd * _Nonnull)core;

@end
