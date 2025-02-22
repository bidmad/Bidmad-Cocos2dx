//
//  CommonBridgeObjC.h
//
//  Created by Kenneth on 2021/04/24.
//

#ifndef CommonBridgeObjC_h
#define CommonBridgeObjC_h

#include "CommonBridgeCpp.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <BidmadSDK/Cocos2dxCommon.h>
#import <OpenBiddingHelper/BidmadAdFreeInformation.h>

@interface CommonBridgeObjC : NSObject <BIDMADCocos2dxCommonDelegate>

+ (CommonBridgeObjC*)sharedInstance;
- (void)setDebugMode:(BOOL)isDebug;
- (void)setAdvertiserTrackingEnabled:(BOOL)enable;
- (BOOL)getAdvertiserTrackingEnabled;
- (void)reqAdTrackingAuthorization;
- (void)setGoogleTestId:(NSString*)testDeviceId;
- (void)setGdprConsent:(bool)consent useArea:(bool)useArea;
- (int)getGdprConsentWithUseArea:(bool)useArea;
- (const char *)getPRIVACYURL;
- (void)initializeSdkWithAppDomain:(NSString *)appDomain;
- (void)initializeSdkWithCallbackForAppDomain:(NSString *)appDomain;
- (bool)isAdFree;

// callback setting
- (void)setInitializeCallback:(void (*)(bool))_onInitializedCallback;
- (void)setAdFreeEventCallback:(void (*)(bool))_onAdFreeCallback;

@end


#endif /* CommonBridgeObjC_h */
