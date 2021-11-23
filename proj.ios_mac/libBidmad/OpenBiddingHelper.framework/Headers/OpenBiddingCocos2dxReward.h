//
//  Cocos2dxReward.h
//  BidmadSdk
//
//  Created by Kenneth on 2021/04/27.
//  Copyright © 2021 ADOP Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <BidmadSDK/BIDMADSetting.h>
#import "OpenBiddingRewardVideo.h"

@interface OpenBiddingCocos2dxReward : NSObject <BIDMADOpenBiddingRewardVideoDelegate>{
    NSString* mZoneId;
    UIViewController *rootVC;
    id<BIDMADOpenBiddingRewardVideoDelegate> delegate;
    @public OpenBiddingRewardVideo* bidmadReward;
}

- (id)initWithZoneId:(NSString *)zoneId viewController:(UIViewController *)rootVC;
- (void)setZoneID:(NSString *)zoneId;
- (void)setDelegate:(id) param;
- (void)load;
- (void)show;
- (bool)isLoaded;
- (void)setAutoReoad:(bool)isAutoReload;

@end

