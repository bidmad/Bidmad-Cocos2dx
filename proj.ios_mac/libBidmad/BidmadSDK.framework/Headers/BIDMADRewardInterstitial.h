//
//  BIDMADRewardedInterstitial.h
//  BidmadSDK
//
//  Created by ADOP_Mac on 2021/05/20.
//  Copyright © 2021 ADOP Co., Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol BIDMADRewardInterstitialDelegate;
@protocol BIDMADRewardInterstitialInnerDelegate;

#pragma mark BIDMADRewardInterstitial Interface

    @interface BIDMADRewardInterstitial : NSObject<BIDMADRewardInterstitialInnerDelegate>
        
    @property (nonatomic, strong) id<BIDMADRewardInterstitialDelegate> delegate;
    @property (nonatomic, strong) NSDictionary *ads_dic;
    @property (nonatomic, strong) UIViewController *parentViewController;
    @property (nonatomic) NSString *zoneID;
    @property (nonatomic) BOOL isLoaded;
    @property (nonatomic, strong) NSString * _Nullable CUID;
    @property (nonatomic, strong) NSString * _Nullable currentAdNetwork;

    - (void) requestRewardInterstitial;
    - (void) showRewardInterstitialView;
    - (void)removeRewardInterstitialAds;

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

    @end

#pragma mark BIDMADRewardInterstitial Delegate

    @protocol BIDMADRewardInterstitialDelegate <NSObject>
    @optional

    - (void)BIDMADRewardInterstitialAllFail:(BIDMADRewardInterstitial *)core;
    - (void)BIDMADRewardInterstitialLoad:(BIDMADRewardInterstitial *)core;
    - (void)BIDMADRewardInterstitialClose:(BIDMADRewardInterstitial *)core;
    - (void)BIDMADRewardInterstitialShow:(BIDMADRewardInterstitial *)core;
    - (void)BIDMADRewardInterstitialClick:(BIDMADRewardInterstitial *)core;
    - (void)BIDMADRewardInterstitialSuccess:(BIDMADRewardInterstitial *)core;
    - (void)BIDMADRewardInterstitialSkipped:(BIDMADRewardInterstitial *) core;

    @end

#pragma mark BIDMADRewardInterstitial Inner-Delegate

    @protocol BIDMADRewardInterstitialInnerDelegate <NSObject>
    @required

        - (void)onRewardInterstitialLoad:(BIDMADRewardInterstitial *)core current:(NSDictionary*) currentDic;
        - (void)onRewardInterstitialError:(NSString *)error failType:(NSString *)failType;
        - (void)onRewardInterstitialShow:(BIDMADRewardInterstitial *)core current:(NSDictionary*) currentDic;
        - (void)onRewardInterstitialClick:(BIDMADRewardInterstitial *)core current:(NSDictionary*) currentDic;
        - (void)onRewardInterstitialSuccess:(BIDMADRewardInterstitial *)core current:(NSDictionary*) currentDic;
        - (void)onRewardInterstitialSkipped:(BIDMADRewardInterstitial *) core current:(NSDictionary*) currentDic;
        - (void)onRewardInterstitialClose:(BIDMADRewardInterstitial *)core current:(NSDictionary*) currentDic;

    @end
