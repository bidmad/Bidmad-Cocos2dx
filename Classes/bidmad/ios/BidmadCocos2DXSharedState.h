//
//  BidmadCocos2DXSharedState.h
//  BidmadCocos2dxSample-mobile
//
//  Created by Seungsub Oh on 2023/01/30.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface BidmadCocos2DXSharedState : NSObject

+ (BidmadCocos2DXSharedState *)shared;
@property (readonly) UIViewController * _Nonnull cocosViewController;

@end

NS_ASSUME_NONNULL_END
