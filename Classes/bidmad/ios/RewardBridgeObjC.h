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
#import <BidmadSDK/Cocos2dxReward.h>

static NSMutableDictionary* BidmadCocos2dxRewardDic;

@interface RewardBridgeObjC : NSObject <BIDMADRewardVideoDelegate>{
    NSString* mZoneId;
    Cocos2dxReward* mRewardVideo;
    RewardBridgeCpp* mController;
}
- (id)initWithZoneId:(NSString *)zoneId controller:(RewardBridgeCpp*) controller;
+ (id)getInstance:(NSString*) zoneId;
- (void)loadRewardVideo;
- (void)showRewardVideo;
- (BOOL)isLoaded;

@end


#endif /* RewardBridgeObjC_h */
