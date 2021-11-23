//
//  Cocos2dxGDPRforGoogle.h
//  BidmadSDK
//
//  Created by ADOP_Mac on 2021/04/08.
//  Copyright © 2021 ADOP Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BIDMADGDPRforGoogle.h"

@interface Cocos2dxGDPRforGoogle : NSObject

@property (strong,nonatomic) id<BIDMADGDPRforGoogleProtocol> GDPRforGoogleDelegate;

+ (Cocos2dxGDPRforGoogle *)sharedInstance;
- (id)initGDPRforGoogle;
- (void)setListener;
- (void)setDebug:(char *)testDeviceId isTestEurope:(bool)testEurope;
- (void)requestConsentInfoUpdate;
- (bool)isConsentFormAvailable;
- (void)loadForm;
- (int)getConsentStatus;
- (void)reset;
- (void)showForm;
- (void)setDelegate:(id<BIDMADGDPRforGoogleProtocol>)delegate;

@end
