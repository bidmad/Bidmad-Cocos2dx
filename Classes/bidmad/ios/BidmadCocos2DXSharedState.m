//
//  BidmadCocos2DXSharedState.m
//  BidmadCocos2dxSample-mobile
//
//  Created by Seungsub Oh on 2023/01/30.
//

#import "BidmadCocos2DXSharedState.h"
#import <BidmadSDK/BIDMADUtil.h>

@interface BidmadCocos2DXSharedState ()

@property (nonatomic, strong) UIViewController * _Nullable rootViewController;

@end

@implementation BidmadCocos2DXSharedState

+ (BidmadCocos2DXSharedState *)shared {
    static dispatch_once_t pred = 0;
    __strong static BidmadCocos2DXSharedState * _sharedObject = nil;
    dispatch_once(&pred, ^{
        _sharedObject = ^{
            BidmadCocos2DXSharedState *instance = [[BidmadCocos2DXSharedState alloc] init];
            [instance setRootViewController:nil];
            return instance;
        }();
    });
    return _sharedObject;
}

- (UIViewController *)cocosViewController {
    if (self.rootViewController == nil) {
        self.rootViewController = [BIDMADUtil topMostController];
    }
    
    return self.rootViewController;
}

@end
