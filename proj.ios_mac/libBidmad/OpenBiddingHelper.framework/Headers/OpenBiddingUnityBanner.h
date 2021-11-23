//
//  UnityBanner.h
//  BidmadSDK
//
//  Created by Kenneth on 2021/01/18.
//  Copyright © 2021 ADOP Co., Ltd. All rights reserved.
//

#ifndef OpenBiddingUnityBanner_h
#define OpenBiddingUnityBanner_h

#import <Foundation/Foundation.h>
#import <BidmadSDK/BIDMADSetting.h>
#import "OpenBiddingBanner.h"

static NSMutableDictionary* BidmadOpenBiddingBannerDic;

@interface OpenBiddingUnityBanner : NSObject <BIDMADOpenBiddingBannerDelegate>{
    NSString* mZoneId;
    id<BIDMADOpenBiddingBannerDelegate> delegate;
    @public OpenBiddingBanner* bidmadBanner;
    UIViewController* mParentVC;
}

- (id)initWithZoneId:(NSString *)zoneId parentVC:(UIViewController *)parentVC adsPosition:(CGPoint)point bannerSize:(bannerSizeType)bannerTypeParam __deprecated;
- (id)initWithZoneId:(NSString *)zoneId parentVC:(UIViewController *)parentVC adsPosition:(CGPoint)point;
- (id)initWithZoneId:(NSString *)zoneId parentVC:(UIViewController *)parentVC adYPoint:(int)yPoint;
+ (id)getInstance:(NSString *)zoneId;
- (void)setZoneID:(NSString *)zoneId;
- (void)setDelegate:(id) param;
- (void)load;
- (void)remove;
- (void)setRefreshInterval:(int)sec;
- (void)hideView;
- (void)showView;
- (void)setCUID:(NSString *)cuid;

@end

#endif /* OpenBiddingUnityBanner_h */
