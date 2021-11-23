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
#import "BIDMADAdmob.h"
#import "BIDMADAdmanager.h"
#import "BIDMADInterstitial.h"

#if __has_include(<BidmadAdapterFC/BidmadAdapterFC.h>) || __has_include("BidmadAdapterFC.h")
#import <BidmadAdapterFC/BidmadAdapterFC.h>
#endif

#if __has_include(<BidmadAdapterFNC/BidmadAdapterFNC.h>) || __has_include("BidmadAdapterFNC.h")
#import <BidmadAdapterFNC/BidmadAdapterFNC.h>
#endif

@class BIDMADInterstitial;

@protocol BIDMADRewardVideoDelegate;

@protocol BIDMADRewardVideoInnerDelegate <NSObject>
@required

- (void)onVideoLoad;
- (void)onVideoError:(NSString *)error failType:(NSString *)failType;
- (void)onVideoShow;
- (void)onVideoClick;
- (void)onVideoSuccess;
- (void)onVideoSkipped;
- (void)onVideoClose;

@end

@interface BIDMADRewardVideo : NSObject <BIDMADRewardVideoInnerDelegate>

@property (nonatomic, strong) id<BIDMADRewardVideoDelegate> delegate;

@property (nonatomic, strong) id<BIDMADRewardVideoInnerDelegate> innerDelegate;

@property (nonatomic, strong) UIViewController*             parentViewController;

@property (strong, nonatomic) NSDictionary*                 ads_dic;

@property (strong, nonatomic) NSDictionary*                      ecpm_rev_info;
@property (strong, nonatomic) NSDictionary*                      area_info;

@property (strong, nonatomic) NSDictionary*                    change_info;
@property (strong, nonatomic) NSDictionary*                    date;
@property (strong, nonatomic) NSString*                        mediationType;

@property (nonatomic) int mediationNumber;

@property (nonatomic) BOOL isDirectLoad;

@property (nonatomic) NSString * zoneID;

@property (nonatomic) bool justLoading;

@property (nonatomic, strong) NSString* userId;

@property (nonatomic) BOOL                       isLabelService;
@property (nonatomic) BOOL                       isLabelServiceAdmin;
@property (nonatomic) BOOL                       testMode;
@property (nonatomic) BOOL                       isComplete;
@property (nonatomic) BOOL                       isLoaded;

@property (nonatomic) NSString *                 realZoneId;

@property (nonatomic, strong) NSString * _Nullable CUID;

@property (nonatomic) BOOL isInterstitialBackfill;
@property (nonatomic, strong) BIDMADInterstitial* interstitial;


///inititalize
- (id)init;

/// Init Method specifically for OBH Framework
- (instancetype)initWithZoneID:(NSString * _Nonnull)zoneID
          parentViewController:(UIViewController * _Nonnull)parentVC
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

- (NSError * _Nullable)sortBasedOnFloorPriceAndSelectFirstAd;

- (NSError * _Nullable)withoutSortingJustSelectFirstAd;

///InterstitialView Load
- (void)loadRewardVideo;

///InterstitialView Show
- (void)showRewardVideo;

- (void)directShowRewardView;

- (void)selectAds:(NSDictionary *)lv_dic;

- (void) sendLog :(NSDictionary *) info :(NSString *) advertisementType :(NSString *) logType;

- (void) sendLog :(NSDictionary *) info :(NSString *) advertisementType :(NSString *) logType :(NSString *)recvSessionId;

- (void) releaseBidmadResource;

- (void) removeRewardADS;


@end

@protocol BIDMADRewardVideoDelegate <NSObject>

@optional

- (void)BIDMADRewardVideoAllFail:(BIDMADRewardVideo *)core;

/// PREPARED INTERSTITIAL VIEW
- (void)BIDMADRewardVideoLoad:(BIDMADRewardVideo *)core;

/// For Display
- (void)BIDMADRewardVideoSuccessLoadLog:(NSDictionary*)currentDic;

- (void)BIDMADRewardVideoErrorLoadLog:(NSDictionary*)currentDic;

- (void)BIDMADRewardVideoClose:(BIDMADRewardVideo *)core;

/// SHOW INTERSTITIAL VIEW
- (void)BIDMADRewardVideoShow:(BIDMADRewardVideo *)core;

/// COMPLETE REWARD VIDEO
- (void)BIDMADRewardVideoComplete:(BIDMADRewardVideo *)core;

/// CLICK REWARD VIDEO
- (void)BIDMADRewardVideoClick:(BIDMADRewardVideo *)core;

/// CLICK REWARD VIDEO
- (void)BIDMADRewardVideoSucceed:(BIDMADRewardVideo *)core;

/// SKIP RERWARD VIDEO
- (void)BIDMADRewardSkipped:(BIDMADRewardVideo *) core;

@end



