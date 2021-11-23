//
//  GoogleGDPRBridgeObjC.h
//  BidmadCocos2dxSample-mobile
//
//  Created by ADOP_Mac on 2021/11/19.
//

#include "GoogleGDPRBridgeCpp.h"
#import <Foundation/Foundation.h>
#import <BidmadSDK/Cocos2dxGDPRforGoogle.h>

NS_ASSUME_NONNULL_BEGIN

@interface GoogleGDPRBridgeObjC : NSObject {
    GoogleGDPRBridgeCpp* mController;
}

+ (id _Nonnull)sharedInstance;
- (id _Nonnull)init;
- (void)setCallbackController:(GoogleGDPRBridgeCpp *)controller;
- (void)setDebug:(char* _Nonnull)testDeviceId isEEA:(bool)isEEA;
- (void)requestConsentInfoUpdate;
- (bool)isConsentFormAvailable;
- (void)loadForm;
- (int)getConsentStatus;
- (void)reset;
- (void)showForm;

@end

NS_ASSUME_NONNULL_END
