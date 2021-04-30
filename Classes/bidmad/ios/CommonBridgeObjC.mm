//
//  CommonBridgeObjc.mm
//  BidmadiOS
//
//  Created by Kenneth on 2021/04/24.
//

#define DEFINE_SHARED_INSTANCE_USING_BLOCK(block) \
static dispatch_once_t pred = 0; \
__strong static id _sharedObject = nil; \
dispatch_once(&pred, ^{ \
_sharedObject = block(); \
}); \
return _sharedObject; \

#include "CommonBridgeObjC.h"

@implementation CommonBridgeObjC

-(id)init
{
    [[Cocos2dxCommon sharedInstance] setDelegate:self];
    return self;
}

+ (CommonBridgeObjC*)sharedInstance
{
    DEFINE_SHARED_INSTANCE_USING_BLOCK(^{
        return [[self alloc]init];
    });
}
- (void)setDebugMode:(BOOL)isDebug
{
    [[Cocos2dxCommon sharedInstance] setDebugMode:isDebug];
    NSLog(@"isDebug : %d",[[BIDMADSetting sharedInstance] isDebug]);
}

- (void)setAdvertiserTrackingEnabled:(BOOL)enable
{
    [[Cocos2dxCommon sharedInstance] setAdvertiserTrackingEnabled:enable];
}
    
- (BOOL)getAdvertiserTrackingEnabled
{
    return [[Cocos2dxCommon sharedInstance] getAdvertiserTrackingEnabled];
}

- (void)reqAdTrackingAuthorization
{
    [[Cocos2dxCommon sharedInstance] reqAdTrackingAuthorization];
}

- (void)setGoogleTestId:(NSString*)testDeviceId
{
    [[Cocos2dxCommon sharedInstance] setGoogleTestId:testDeviceId];
}

- (void)BIDMADAdTrackingAuthorizationResponse:(int)response
{
    CommonBridgeCpp::onATTCallback(response);
}

@end
