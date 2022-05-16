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
#import "BIDMADAdmobAppOpenAd.h"

@protocol BIDMADAppOpenAdDelegate;
@protocol OpenBiddingAppOpenAdDelegateProtocol;
@protocol OpenBiddingAppOpenAdProtocol;

@interface BIDMADAppOpenAd : NSObject

@property (nonatomic, strong) id<BIDMADAppOpenAdDelegate> _Nullable delegate;
@property (strong, nonatomic) NSDictionary*               _Nullable ads_dic;
@property (nonatomic)         NSString*                   _Nullable zoneID;
@property (nonatomic, strong) NSString* 	              _Nullable userId;
@property (nonatomic, strong) NSString*                   _Nullable CUID;
@property (nonatomic) BOOL                          isLabelService;
@property (nonatomic) BOOL                          isLabelServiceAdmin;
@property (nonatomic) BOOL                          testMode;
@property (nonatomic) BOOL                          isComplete;
@property (nonatomic) BOOL                          isLoaded;
@property (nonatomic, strong) id<OpenBiddingAppOpenAdProtocol> _Nullable instanceOBH;

- (id _Nonnull)init;
- (instancetype _Nonnull)initWithZoneID:(NSString * _Nonnull)zoneID
                   instanceOBH:(id _Nullable)instanceOBH
                     sessionID:(NSString * _Nonnull)sessionID
                       adsDict:(NSDictionary * _Nullable)adsDict
                   revInfoECPM:(NSDictionary * _Nullable)revInfoECPM
                      areaInfo:(NSDictionary * _Nullable)areaInfo
                    changeInfo:(NSDictionary * _Nullable)changeInfo
                          date:(NSDictionary * _Nullable)date
                isLabelService:(NSNumber * _Nullable)isLabelService
           isLabelServiceAdmin:(NSNumber * _Nullable)isLabelServiceAdmin
                      mediType:(NSString * _Nullable)mediationType
                    realZoneID:(NSString * _Nonnull)realZoneID;
- (void)showAppOpenAd;
- (void)requestAppOpenAd;
- (void)selectAds:(NSDictionary * _Nullable)lv_dic;
- (void)registerForAppOpenAdForZoneID:(NSString * _Nonnull)zoneId;
- (void)deregisterForAppOpenAd;
- (void)UIApplicationDidBecomeActiveAction;
- (NSError * _Nullable)sortBasedOnFloorPriceAndSelectFirstAd;
- (NSError * _Nullable)withoutSortingJustSelectFirstAd;

- (void)onAppOpenAdLoad:(BIDMADAppOpenAd * _Nonnull)core  current:(NSDictionary* _Nullable) currentDic;
- (void)onAppOpenAdError;
- (void)onAppOpenAdShow:(BIDMADAppOpenAd * _Nonnull)core  current:(NSDictionary* _Nullable) currentDic;
- (void)onAppOpenAdClick:(BIDMADAppOpenAd * _Nonnull)core current:(NSDictionary* _Nullable) currentDic;
- (void)onAppOpenAdClose:(BIDMADAppOpenAd * _Nonnull)core current:(NSDictionary* _Nullable) currentDic;

@end

@protocol BIDMADAppOpenAdDelegate <NSObject>
@optional

- (void)BIDMADAppOpenAdAllFail:(BIDMADAppOpenAd * _Nonnull)core;
- (void)BIDMADAppOpenAdLoad:(BIDMADAppOpenAd * _Nonnull)core;
- (void)BIDMADAppOpenAdClose:(BIDMADAppOpenAd * _Nonnull)core;
- (void)BIDMADAppOpenAdShow:(BIDMADAppOpenAd * _Nonnull)core;
- (void)BIDMADAppOpenAdClick:(BIDMADAppOpenAd * _Nonnull)core;

@end

@protocol OpenBiddingAppOpenAdDelegateProtocol <NSObject>

- (void)OpenBiddingAppOpenAdAllFail:(id _Nonnull)core;
- (void)OpenBiddingAppOpenAdLoad:(id _Nonnull)core;
- (void)OpenBiddingAppOpenAdClose:(id _Nonnull)core;
- (void)OpenBiddingAppOpenAdShow:(id _Nonnull)core;
- (void)OpenBiddingAppOpenAdClick:(id _Nonnull)core;

@end

@protocol OpenBiddingAppOpenAdProtocol <NSObject>

@property (nonatomic, strong) id<OpenBiddingAppOpenAdDelegateProtocol> _Nullable delegate;
@property (strong, nonatomic) NSDictionary*                    _Nullable ads_dic;
@property (nonatomic)         NSString*                        _Nullable zoneID;
@property (nonatomic, strong) NSString*                        _Nullable userId;
@property (nonatomic, strong) NSString*                        _Nullable CUID;
@property (nonatomic)         BOOL                                       testMode;
@property (nonatomic)         BOOL                                       isComplete;
@property (nonatomic)         BOOL                                       isLoaded;
@property (nonatomic)         BOOL                                       isBidmadLoaded;

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

@end
