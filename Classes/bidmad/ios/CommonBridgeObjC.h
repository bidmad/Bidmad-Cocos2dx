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

@interface CommonBridgeObjC : NSObject <BIDMADCocos2dxCommonDelegate>

+ (CommonBridgeObjC*)sharedInstance;
- (void)setDebugMode:(BOOL)isDebug;
- (void)setAdvertiserTrackingEnabled:(BOOL)enable;
- (BOOL)getAdvertiserTrackingEnabled;
- (void)reqAdTrackingAuthorization;
- (void)setGoogleTestId:(NSString*)testDeviceId;
@end


#endif /* CommonBridgeObjC_h */
