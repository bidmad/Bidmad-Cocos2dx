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

@interface CommonBridgeObjC () <BidmadAdFreeInformationDelegate>

@end

@implementation CommonBridgeObjC {
    void (*onAdFreeCallback)(bool);
    void (*onInitializedCallback)(bool);
}

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

- (void)setGdprConsent:(bool)consent useArea:(bool)useArea
{
    [[Cocos2dxCommon sharedInstance] setGdprConsent:consent useArea:useArea];
}

- (int)getGdprConsentWithUseArea:(bool)useArea {
    return [[Cocos2dxCommon sharedInstance] getGdprConsentWithUseArea:useArea];
}

- (const char*)getPRIVACYURL {
    return [[Cocos2dxCommon sharedInstance] getPRIVACYURL];
}

- (void)initializeSdkWithAppKey:(NSString *)appKey {
    [BIDMADSetting.sharedInstance initializeSdkWithKey:appKey];
}

- (void)initializeSdkWithCallbackForAppKey:(NSString *)appKey {
    [BIDMADSetting.sharedInstance initializeSdkWithKey:appKey completionHandler:^(BOOL initStatus) {
        if (onInitializedCallback != nil) {
            if (initStatus == YES) {
                onInitializedCallback(true);
            } else {
                onInitializedCallback(false);
            }
        }
    }];
}

- (bool)isAdFree {
    if ([BidmadAdFreeInformation status] == BidmadAdFreeInformationStatusBlocked) {
        return true; // Free of ads
    } else {
        return false; // ads must be displayed
    }
}

- (void)setInitializeCallback:(void (*)(bool))_onInitializedCallback {
    onInitializedCallback = _onInitializedCallback;
}

- (void)setAdFreeEventCallback:(void (*)(bool))_onAdFreeCallback {
    onAdFreeCallback = _onAdFreeCallback;
    [BidmadAdFreeInformation setDelegate:self];
}

- (void)didAdFreeInformationStatusChange:(BidmadAdFreeInformationStatus)status {
    if (status == BidmadAdFreeInformationStatusBlocked) {
        if (onAdFreeCallback != nil) {
            onAdFreeCallback(true); // Free of ads
        }
    } else {
        if (onAdFreeCallback != nil) {
            onAdFreeCallback(false); // ads must be displayed
        }
    }
}

@end
