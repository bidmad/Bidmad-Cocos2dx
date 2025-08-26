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
#import <BidmadSDK/BidmadSDK.h>
#import <BidmadSDK/BidmadSDK-Swift.h>
#import <OpenBiddingHelper/OpenBiddingHelper.h>
#import <OpenBiddingHelper/OpenBiddingHelper-Swift.h>
#import <OpenBiddingHelper/BidmadRewardAdForGame.h>

static NSMutableDictionary* BidmadCocos2dxRewardDic;

@interface RewardBridgeObjC : NSObject <BIDMADOpenBiddingRewardVideoDelegate>{
    RewardBridgeCpp* mController;
}

@property (nonatomic, strong) NSString * _Nonnull mZoneId;

+ (void)initialSetupWithZoneId:(NSString *)zoneId controller:(RewardBridgeCpp *)controller;
+ (id)getInstance:(NSString*) zoneId;
- (void)loadRewardVideo;
- (void)showRewardVideo;
- (BOOL)isLoaded;
- (void)setAutoReload:(bool)isAutoReload;

@end


#endif /* RewardBridgeObjC_h */
