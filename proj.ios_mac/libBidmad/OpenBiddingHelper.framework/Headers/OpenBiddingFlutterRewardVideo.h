//
//  OpenBiddingFlutterRewardVideo.h
//  BidmadSDK
//
//  Created by ADOP_Mac on 2021/03/26.
//

#import <Foundation/Foundation.h>
#import "OpenBiddingRewardVideo.h"
#import <BidmadSDK/BIDMADSetting.h>

#if __has_include(<Flutter/Flutter.h>) || __has_include("Flutter.h")
@import Flutter;
#endif

@interface OpenBiddingFlutterRewardVideo : NSObject<BIDMADRewardVideoDelegate>

@property (strong, nonatomic) id flutterChannel;
- (id)initRewardVideo:(id)registrar channelName:(NSString*)chanNm;

@end
