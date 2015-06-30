//
//  AMAnimalProvider.h
//  AMStaticLib
//
//  Created by appsynth on 6/26/15.
//  Copyright (c) 2015 Appsynth. All rights reserved.
//

#import <Foundation/Foundation.h>


@class Animal;


@interface AMAnimalProvider : NSObject

+ (Animal *) buildAnimalFromCustomClass:(Class) customClass;

@end
