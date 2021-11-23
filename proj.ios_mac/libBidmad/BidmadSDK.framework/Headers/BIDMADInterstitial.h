//
//  BIDMADInterstitial.h
//  BIDMADSDK
//
//  Created by 김선정 on 2015. 7. 15..
//  Copyright (c) 2015년 ADOP Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BIDMADUtil.h"
#import "BIDMADSetting.h"
#import "BIDMADAdmanager.h"
#import "BIDMADAdmob.h"
#import "BIDMADAtomInterstitial.h"

#if __has_include(<BidmadAdapterFC/BidmadAdapterFC.h>) || __has_include("BidmadAdapterFC.h")
#import <BidmadAdapterFC/BidmadAdapterFC.h>
#endif

#if __has_include(<BidmadAdapterFNC/BidmadAdapterFNC.h>) || __has_include("BidmadAdapterFNC.h")
#import <BidmadAdapterFNC/BidmadAdapterFNC.h>
#endif

@protocol BIDMADInterstitialDelegate <NSObject>

@optional

- (void)BIDMADInterstitialAllFail:(BIDMADInterstitial *)core;

/// PREPARED INTERSTITIAL VIEW
- (void)BIDMADInterstitialLoad:(BIDMADInterstitial *)core;

/// ERROR
- (void)BIDMADInterstitialError:(BIDMADInterstitial *)core code:(NSString *)error;

/// CLOSE INTERSTITIAL VIEW
- (void)BIDMADInterstitialClose:(BIDMADInterstitial *)core;

/// SHOW INTERSTITIAL VIEW
- (void)BIDMADInterstitialShow:(BIDMADInterstitial *)core;

@end

@protocol BIDMADInterstitialInnerDelegate <NSObject>
@required

- (void)onInterstitialLoad;
- (void)onInterstitialError:(NSString *)error failType:(NSString *)failType;
- (void)onInterstitialShow;
- (void)onInterstitialClick;
- (void)onInterstitialClose;

@end


@interface BIDMADInterstitial : NSObject <BIDMADInterstitialInnerDelegate>

@property (nonatomic, strong) id<BIDMADInterstitialDelegate> delegate;

@property (nonatomic, strong) id<BIDMADInterstitialInnerDelegate> innerDelegate;

@property (nonatomic, strong) UIViewController* parentViewController;

@property (strong, nonatomic) NSDictionary*             ads_dic;
@property (nonatomic) BOOL                     isDirectLoad;

@property (strong, nonatomic) NSDictionary*                      ecpm_rev_info;
@property (strong, nonatomic) NSDictionary*                      area_info;

@property (strong, nonatomic) NSDictionary*                    change_info;
@property (strong, nonatomic) NSDictionary*                    date;

@property (nonatomic) NSString * zoneID;

@property (nonatomic) bool justLoading;

@property (nonatomic) int mediationNumber;

@property (nonatomic) BOOL                       isLabelService;
@property (nonatomic) BOOL                       isLabelServiceAdmin;

@property (nonatomic) NSString *                 realZoneId;

@property (nonatomic) BOOL                       isLoaded;

@property (nonatomic, strong) NSString * _Nullable CUID;

///inititalize
- (id)init;

/// Init Method for OBH
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
                    realZoneID:(NSString * _Nonnull)realZoneID;

/// This method sorts the dictionary of compass ads data from the highest floor price to the least.
/// It returns the NSError if necessary properties are not available nor nil.
/// If success, it lastly calls selectAds with the first ad with the highest floor price.
- (NSError * _Nullable)sortBasedOnFloorPriceAndSelectFirstAd;

- (NSError * _Nullable)withoutSortingJustSelectFirstAd;

///InterstitialView Load
- (void)loadInterstitialView;

///InterstitialView Show
- (void)showInterstitialView;

///InterstitialView Direct Show
- (void)directShowInterstitialView;

- (void)selectAds:(NSDictionary *)lv_dic;

- (void)removeInterstitialADS;

- (void)sendLog:(NSDictionary *)info :(NSString *)advertisementType :(NSString *)logType :(NSString *)recvSessionId :(NSString * _Nullable)cuid;

@end




