//
//  OpenBiddingFlutterInterstitial.h
//  BidmadSDK
//
//  Created by ADOP_Mac on 2021/03/26.
//

#import <Foundation/Foundation.h>
#import "OpenBiddingInterstitial.h"
#import <BidmadSDK/BIDMADSetting.h>

#if __has_include(<Flutter/Flutter.h>) || __has_include("Flutter.h")
@import Flutter;
#endif

@interface OpenBiddingFlutterInterstitial : NSObject<BIDMADInterstitialDelegate>

@property (strong, nonatomic) id flutterChannel;
//- (id)initInterstitial:(NSObject<FlutterPluginRegistrar>*)registrar channelName:(NSString*)chanNm;
- (id)initInterstitial:(id)registrar channelName:(NSString*)chanNm;

@end
