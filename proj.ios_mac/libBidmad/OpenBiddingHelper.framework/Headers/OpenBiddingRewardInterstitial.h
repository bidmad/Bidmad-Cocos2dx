//
//  BIDMADRewardedInterstitial.h
//  BidmadSDK
//
//  Created by ADOP_Mac on 2021/05/20.
//  Copyright © 2021 ADOP Co., Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "OpenBiddingAdmob.h"

@protocol OpenBiddingRewardInterstitialDelegate;
@protocol OpenBiddingRewardInterstitialInnerDelegate;

#pragma mark BIDMADRewardInterstitial Interface

    @interface OpenBiddingRewardInterstitial : NSObject<OpenBiddingRewardInterstitialInnerDelegate, BIDMADRewardInterstitialDelegate>
        
    @property (nonatomic, strong) id<OpenBiddingRewardInterstitialDelegate> delegate;
    @property (nonatomic, strong) NSDictionary *ads_dic;
    @property (nonatomic, strong) UIViewController *parentViewController;
    @property (nonatomic, strong) NSString *userId;
    @property (nonatomic, strong) NSString *sessionId;
    @property (nonatomic) NSString *zoneID;
    @property (nonatomic) BOOL isLoaded;
    @property (nonatomic) BOOL justLoading;
    @property (nonatomic) BOOL preventARCKill;
    @property (nonatomic, strong) NSString * _Nullable CUID;

    - (void) requestRewardInterstitial;
    - (void) showRewardInterstitialView;
    - (void)removeRewardInterstitialAds;

    #pragma mark BIDMADRewardInterstitial Delegate

    - (void)BIDMADRewardInterstitialLoad:(BIDMADRewardInterstitial *)core;
    - (void)BIDMADRewardInterstitialShow:(BIDMADRewardInterstitial *)core;
    - (void)BIDMADRewardInterstitialAllFail:(BIDMADRewardInterstitial *)core;
    - (void)BIDMADRewardInterstitialClick:(BIDMADRewardInterstitial *)core;
    - (void)BIDMADRewardInterstitialSuccess:(BIDMADRewardInterstitial *)core;
    - (void)BIDMADRewardInterstitialClose:(BIDMADRewardInterstitial *)core;
    - (void)BIDMADRewardInterstitialSkipped:(BIDMADRewardInterstitial *)core;
    - (void)BIDMADRewardInterstitialComplete:(BIDMADRewardInterstitial *)core;

    @end

#pragma mark OpenBiddingRewardInterstitialDelegate

    @protocol OpenBiddingRewardInterstitialDelegate <NSObject>
    @optional

    - (void)OpenBiddingRewardInterstitialAllFail:(OpenBiddingRewardInterstitial *)core;
    - (void)OpenBiddingRewardInterstitialLoad:(OpenBiddingRewardInterstitial *)core;
    - (void)OpenBiddingRewardInterstitialClose:(OpenBiddingRewardInterstitial *)core;
    - (void)OpenBiddingRewardInterstitialShow:(OpenBiddingRewardInterstitial *)core;
    - (void)OpenBiddingRewardInterstitialComplete:(OpenBiddingRewardInterstitial *)core;
    - (void)OpenBiddingRewardInterstitialClick:(OpenBiddingRewardInterstitial *)core;
    - (void)OpenBiddingRewardInterstitialSuccess:(OpenBiddingRewardInterstitial *)core;
    - (void)OpenBiddingRewardInterstitialSkipped:(OpenBiddingRewardInterstitial *) core;

    @end

#pragma mark OpenBiddingRewardInterstitialInnerDelegate

    @protocol OpenBiddingRewardInterstitialInnerDelegate <NSObject>
    @required

        - (void)onRewardInterstitialLoad:(OpenBiddingRewardInterstitial *)core current:(NSDictionary*) currentDic;
        - (void)onRewardInterstitialError:(OpenBiddingRewardInterstitial *)core code:(NSString *)error failType:(NSString*) failType current:(NSDictionary*)currentDic passbackStr:(NSString*) passBackStr passback:(NSDictionary*) passbackDic;
        - (void)onRewardInterstitialShow:(OpenBiddingRewardInterstitial *)core current:(NSDictionary*) currentDic;
        - (void)onRewardInterstitialClick:(OpenBiddingRewardInterstitial *)core current:(NSDictionary*) currentDic;
        - (void)onRewardInterstitialSuccess:(OpenBiddingRewardInterstitial *)core current:(NSDictionary*) currentDic;
        - (void)onRewardInterstitialSkipped:(OpenBiddingRewardInterstitial *) core current:(NSDictionary*) currentDic;
        - (void)onRewardInterstitialClose:(OpenBiddingRewardInterstitial *)core current:(NSDictionary*) currentDic;

    @end
