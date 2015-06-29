//
//  AMADInterstitial.h
//  AMInterstitialTestApp
//
//  Created by appsynth on 6/10/15.
//  Copyright (c) 2015 Appsynth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@class AMADInterstitial;


/************************************
    Protocol
 *************************************/


@protocol AMADInterstitialDelegate <NSObject>

@optional
- (void) amInterstitialDidReceiveAd: (AMADInterstitial *) ad;       // Fetch ads succesfully

- (void) amInterstitialDidDismissScreen:(AMADInterstitial *) ad;    // Did dissmiss the ads

- (void) amInterstitialWillPresentScreen:(AMADInterstitial *) ad;

- (void) amInterstitialWillDismissScreen:(AMADInterstitial *) ad;



//- (void)interstitial:(GADInterstitial *)ad didFailToReceiveAdWithError:(GADRequestError *)error {
@end


/************************************
    Class
 *************************************/


@interface AMADInterstitial : NSObject


#pragma mark - AppMojo

// AppMojo Unique identifer
@property (nonatomic, strong) IBInspectable NSString *iphoneAdPlacementID;
@property (nonatomic, strong) IBInspectable NSString *ipadAdPlacementID;

@property (nonatomic, assign) id<AMADInterstitialDelegate> delegate;


#pragma mark - AdMob


// Note that Test ads are only shown on specific devices that you specify, so all of your users will still receive production ads.
@property (nonatomic, strong) NSMutableArray *testDevices;

// Ads ID to be presented on AppMojo Banner View
@property (nonatomic, strong) NSArray *adUnitIDArray;

/* 
 Returns YES if the AMInterstitial is ready to be displayed.
 The delegate's amInterstitialDidReceiveAd: will be called after this property switches from NO to YES.
 */
@property(nonatomic, readonly, assign) BOOL isReady;

/*
 Returns YES if this object has already been presented.
 Interstitial objects can only be used once even with different requests.
 */
@property(nonatomic, readonly, assign) BOOL hasBeenUsed;

// Auto Dismissing
//@property(nonatomic, assign) BOOL isAutoDismiss;
//@property(nonatomic, assign) NSInteger dismissTimeout;

// Designated initializer
- (instancetype) initWithAdsIDArray: (NSArray *) aAdsIDArray;
- (void) initializeForStoryboardWithIDArray: (NSArray *) aAdsIDArray;

// To test on simulator
- (void) enableTestOnSimilator;

// Start loading Interstitial
- (void) loadInterstitial;

// Reload Interstitial. This can be called only we do initWithAdsIDArray already
- (void) reloadInterstitial;

// Present Interstitial ad. Note that this must be called after Interstital has been load with the method "loadInterstitial"
- (void) presentFromRootViewController:(UIViewController *) rootViewController;

// Present Interstitial ad, and then dismiss the Interstital Ads after a dismiss interval passes
- (void) presentFromRootViewController: (UIViewController *) rootViewController dismissInterval: (NSInteger) aDismissInterval;

@end

