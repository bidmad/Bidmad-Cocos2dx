//
//  OpenBiddingFlutterBanner.h
//  BidmadSDK
//
//  Created by ADOP_Mac on 2021/03/25.
//
#import <UIKit/UIKit.h>
#import <BidmadSDK/BIDMADSetting.h>
#import "OpenBiddingBanner.h"

#if __has_include(<Flutter/Flutter.h>) || __has_include("Flutter.h")
@import Flutter;

@interface OpenBiddingFlutterBanner : NSObject<BIDMADBannerDelegate, FlutterPlatformView>
#else
@interface OpenBiddingFlutterBanner : NSObject<BIDMADBannerDelegate>
#endif

@property (strong, nonatomic) id flutterChannel;
//- (id)initBanner:(NSObject<FlutterPluginRegistrar>*)registrar channelName:(NSString*)chanNm frame:(CGRect)frame;
- (id)initBanner:(id)registrar channelName:(NSString*)chanNm frame:(CGRect)frame;
- (UIView*)view;

@end
