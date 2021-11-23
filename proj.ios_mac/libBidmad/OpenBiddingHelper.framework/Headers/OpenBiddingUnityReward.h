//
//  UnityReward.h
//  BidmadSDK
//
//  Created by Kenneth on 2021/01/15.
//  Copyright © 2021 ADOP Co., Ltd. All rights reserved.
//

#ifndef OpenBiddingUnityReward_h
#define OpenBiddingUnityReward_h

#import <Foundation/Foundation.h>
#import "OpenBiddingRewardVideo.h"
#import <BidmadSDK/BIDMADSetting.h>

static NSMutableDictionary* BidmadOpenBiddingRewardDic;

@interface OpenBiddingUnityReward : NSObject <BIDMADOpenBiddingRewardVideoDelegate>{
    NSString* mZoneId;
    UIViewController* mParentVC;
    id<BIDMADOpenBiddingRewardVideoDelegate> delegate;
    @public OpenBiddingRewardVideo* bidmadReward;
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

#endif /* OpenBiddingUnityReward_h */
