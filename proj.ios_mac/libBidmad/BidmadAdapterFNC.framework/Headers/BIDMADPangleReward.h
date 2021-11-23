//
//  BIDMADPangleReward.h
//  BidmadSDK
//
//  Created by ADOP_Mac on 2021/06/25.
//  Copyright © 2021 ADOP Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <BUFoundation/BUFoundation.h>
#import <BUAdSDK/BUAdSDK.h>
#import <BUVAAuxiliary/BUVAAuxiliary.h>

@interface BIDMADPangleReward : NSObject<BURewardedVideoAdDelegate>

@property (weak,nonatomic) id __nullable bidmadControllerForCallbacks;

- (id __nonnull)initWithAppID:(NSString * _Nonnull)appID
                                pubID:(NSString * _Nullable)pubID
                               rootVC:(UIViewController * _Nonnull)rootVC
                           parentView:(UIView * _Nullable)parentView
                              isChild:(NSNumber * _Nullable)isChild
                        isGDPRConsent:(NSNumber * _Nullable)isGDPRConsent
                        isCCPAConsent:(NSNumber * _Nullable)isCCPAConsent;
- (void)load;
- (void)setIsRewardedAd:(BOOL)isRewardedAd;
- (void)setIsDebug:(BOOL)isDebug;
- (void)setBidmadController:(id __nonnull)bidmadController;
- (void)show;
- (void)hide;
- (void)remove;

@end
