#import "OpenBiddingFlutterCommon.h"

#if __has_include(<Flutter/Flutter.h>) || __has_include("Flutter.h")
@import Flutter;

@interface OpenBiddingFlutterBannerFactory : NSObject <FlutterPlatformViewFactory>
#else
@interface OpenBiddingFlutterBannerFactory : NSObject
#endif

//- (instancetype)initWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar;
- (instancetype)initWithRegistrar:(id)registrar;
@end
