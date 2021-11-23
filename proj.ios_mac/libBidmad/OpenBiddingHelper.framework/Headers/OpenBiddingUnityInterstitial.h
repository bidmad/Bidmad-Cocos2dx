//
//  UnityInterstitial.h
//  BidmadSDK
//
//  Created by Kenneth on 2021/01/15.
//  Copyright © 2021 ADOP Co., Ltd. All rights reserved.
//

#ifndef OpenBiddingUnityInterstitial_h
#define OpenBiddingUnityInterstitial_h

#import <Foundation/Foundation.h>
#import <BidmadSDK/BIDMADSetting.h>
#import "OpenBiddingInterstitial.h"

static NSMutableDictionary* BidmadOpenBiddingInterstitialDic;

@interface OpenBiddingUnityInterstitial : NSObject <BIDMADOpenBiddingInterstitialDelegate>{
    NSString* mZoneId;
    id<BIDMADOpenBiddingInterstitialDelegate> delegate;
    @public OpenBiddingInterstitial* bidmadInterstitial;
    UIViewController* mParentVC;
}

- (id)initWithZoneId:(NSString *)zoneId parentVC:(UIViewController *)parentVC;
+ (id)getInstance:(NSString *)zoneId;
- (void)setZoneID:(NSString *)zoneId;
- (void)setDelegate:(id) param;
- (void)load;
- (void)show;
- (bool)isLoaded;
- (void)setAutoReload:(bool)isAutoReload;
- (void)setCUID:(NSString *)cuid;

@end

#endif /* OpenBiddingUnityInterstitial_h */
