//
//  AMBannerView.h
//  AMBannerViewTestApp
//
//  Created by Appsynth on 6/5/15.
//  Copyright (c) 2015 Appsynth. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "AMAdSize.h"


/************************************
    Protocol
 *************************************/

@protocol AMADBannerViewDelegate <NSObject>
@optional
- (void) amAdViewDidReceiveAd: (id) aInfo;

@end


/************************************
    Class
 *************************************/


@interface AMADBannerView : UIView

// AppMojo Unique identifer
@property (nonatomic, strong) IBInspectable NSString *iphoneAdPlacementID;
@property (nonatomic, strong) IBInspectable NSString *ipadAdPlacementID;

// Ads ID to be presented on AppMojo Banner View
@property (nonatomic, strong) NSArray *adUnitIDArray;

// The root view controller to be presented on
@property (nonatomic, weak) UIViewController *rootViewController;

// Note that Test ads are only shown on specific devices that you specify, so all of your users will still receive production ads.
@property (nonatomic, strong) NSMutableArray *testDevices;

// Origin of banner referred to its superview
@property (nonatomic, assign) CGPoint origin;

@property (nonatomic, assign) id<AMADBannerViewDelegate> delegate;


// Obsoleted, use initWithAMAdBannerSize: and initWithCustomAMAdSize:origin: instead.
//- (instancetype) initWithAMAdSize: (AMAdSize) aAmAdSize;
//- (instancetype) initWithAMAdSize: (AMAdSize) aAmAdSize origin: (CGPoint) aOrigin;
- (instancetype) initWithAMAdBannerSize: (AMAdBannerSize) aAmAdSize;
- (instancetype) initWithAMAdBannerSize: (AMAdBannerSize) aAmAdSize origin: (CGPoint) aOrigin;

- (instancetype) initWithCustomAMAdSize: (AMAdSize *) aAmAdSize;
- (instancetype) initWithCustomAMAdSize: (AMAdSize *) aAmAdSize origin: (CGPoint) aOrigin;

// Load and present banner
- (void) loadBanner;

// To test on simulator
- (void) enableTestOnSimilator;

@property(nonatomic, assign, getter=isAutoloadEnabled) BOOL autoloadEnabled;

@end



