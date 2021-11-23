//
//  RewardBridgeObjC.h
//
//  Created by Kenneth on 2021/04/24.
//

#ifndef RewardBridgeObjC_h
#define RewardBridgeObjC_h

#include "RewardBridgeCpp.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <OpenBiddingHelper/OpenBiddingRewardVideo.h>
#import <OpenBiddingHelper/OpenBiddingCocos2dxReward.h>

static NSMutableDictionary* BidmadCocos2dxRewardDic;

@interface RewardBridgeObjC : NSObject <BIDMADOpenBiddingRewardVideoDelegate>{
    NSString* mZoneId;
    OpenBiddingCocos2dxReward* mRewardVideo;
    RewardBridgeCpp* mController;
}
- (id)initWithZoneId:(NSString *)zoneId controller:(RewardBridgeCpp*) controller;
+ (id)getInstance:(NSString*) zoneId;
- (void)loadRewardVideo;
- (void)showRewardVideo;
- (BOOL)isLoaded;
- (void)setAutoReload:(bool)isAutoReload;

@end


#endif /* RewardBridgeObjC_h */
