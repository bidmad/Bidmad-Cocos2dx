//
//  BIDMADRewardVideo.h
//  BidmadSDK
//
//  Created by 김선정 on 2018. 10. 29..
//  Copyright © 2018년 ADOP Co., Ltd. All rights reserved.
//

@class OpenBiddingRewardVideo;

#import <Foundation/Foundation.h>
#import <BidmadSDK/BIDMADUtil.h>
#import <BidmadSDK/BIDMADSetting.h>
#import "OpenBiddingAdmob.h"
#import "OpenBiddingInterstitial.h"
#import <BidmadSDK/BIDMADRewardVideo.h>

@protocol BIDMADOpenBiddingRewardVideoDelegate;

@protocol BIDMADOpenBiddingRewardVideoInnerDelegate <NSObject>
@required

- (void)onVideoLoad:(OpenBiddingRewardVideo *)core       current:(NSDictionary*) currentDic;
- (void)onVideoError:(OpenBiddingRewardVideo *)core code:(NSString *)error failType:(NSString*) failType current:(NSDictionary*)currentDic passbackStr:(NSString*) passBackStr passback:(NSDictionary*) passbackDic;
- (void)onVideoShow:(OpenBiddingRewardVideo *)core       current:(NSDictionary*) currentDic;
- (void)onVideoClick:(OpenBiddingRewardVideo *)core      current:(NSDictionary*) currentDic;
- (void)onVideoSuccess:(OpenBiddingRewardVideo *)core    current:(NSDictionary*) currentDic;
- (void)onVideoSkipped:(OpenBiddingRewardVideo *) core   current:(NSDictionary*) currentDic;

@end

@interface OpenBiddingRewardVideo : NSObject <BIDMADOpenBiddingRewardVideoInnerDelegate, BIDMADRewardVideoDelegate>

@property (nonatomic, strong) id<BIDMADOpenBiddingRewardVideoDelegate> delegate;

@property (nonatomic, strong) id<BIDMADOpenBiddingRewardVideoInnerDelegate> innerDelegate;

@property (nonatomic, strong) UIViewController*             parentViewController;

@property (strong, nonatomic) NSDictionary*                 ads_dic;

@property (strong, nonatomic) NSDictionary*                      ecmp_rev_info;
@property (strong, nonatomic) NSDictionary*                      area_info;

@property (strong, nonatomic) NSDictionary*                    change_info;
@property (strong, nonatomic) NSDictionary*                    date;

@property (nonatomic) NSString * zoneID;

@property (nonatomic) bool justLoading;

@property (nonatomic, strong) NSString* userId;

@property (nonatomic) BOOL                       testMode;
@property (nonatomic) BOOL                       isComplete;
@property (nonatomic) BOOL                       isLoaded;

@property (nonatomic) NSString *                 realZoneId;

@property (nonatomic, strong) NSString * _Nullable CUID;

///inititalize
- (id)init;

- (void)loadRewardVideo;

- (void)showRewardVideo;

- (void)selectAds:(NSDictionary *)lv_dic;

@end

@protocol BIDMADOpenBiddingRewardVideoDelegate <NSObject>

@optional

- (void)BIDMADOpenBiddingRewardVideoAllFail:(OpenBiddingRewardVideo *)core;

- (void)BIDMADOpenBiddingRewardVideoLoad:(OpenBiddingRewardVideo *)core;

- (void)BIDMADOpenBiddingRewardVideoSuccessLoadLog:(NSDictionary*)currentDic;

- (void)BIDMADOpenBiddingRewardVideoErrorLoadLog:(NSDictionary*)currentDic;

- (void)BIDMADOpenBiddingRewardVideoClose:(OpenBiddingRewardVideo *)core;

- (void)BIDMADOpenBiddingRewardVideoShow:(OpenBiddingRewardVideo *)core;

- (void)BIDMADOpenBiddingRewardVideoComplete:(OpenBiddingRewardVideo *)core;

- (void)BIDMADOpenBiddingRewardVideoClick:(OpenBiddingRewardVideo *)core;

- (void)BIDMADOpenBiddingRewardVideoSucceed:(OpenBiddingRewardVideo *)core;

- (void)BIDMADOpenBiddingRewardSkipped:(OpenBiddingRewardVideo *) core;

@end



