//
//  BIDMADPangleBanner.h
//  BidmadSDK
//
//  Created by ADOP_Mac on 2021/06/25.
//  Copyright © 2021 ADOP Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <BUFoundation/BUFoundation.h>
#import <BUAdSDK/BUAdSDK.h>
#import <BUVAAuxiliary/BUVAAuxiliary.h>

/**
 Pangle only supports 300x250(point) and 320x50(point).
 When the 320x100 ad requests come in, pass onBannerError with reason being "Unsupported Ad Banner Size"
 */

@interface BIDMADPangleBanner : NSObject<BUNativeExpressBannerViewDelegate>

@property (weak,nonatomic) id __nullable bidmadControllerForCallbacks;
- (id __nonnull)initWithAppID:(NSString * _Nonnull)appID
                                pubID:(NSString * _Nullable)pubID
                               rootVC:(UIViewController * _Nonnull)rootVC
                           parentView:(UIView * _Nullable)parentView
                              isChild:(NSNumber * _Nullable)isChild
                        isGDPRConsent:(NSNumber * _Nullable)isGDPRConsent
                        isCCPAConsent:(NSNumber * _Nullable)isCCPAConsent;
- (void)load;
- (void)setIsDebug:(BOOL)isDebug;
- (void)setBannerSize:(NSString * _Nonnull)sizeString;
- (void)setBidmadController:(id __nonnull)bidmadController;
- (void)show;
- (void)hide;
- (void)remove;

@end
