//
//  AppDelegate.h
//  OpenGLDemo
//
//  Created by colin on 15/5/4.
//  Copyright (c) 2015年 colin. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "OpenGLView.h"

@interface AppDelegate : UIResponder <UIApplicationDelegate>{
    OpenGLView* _glView;
}


@property (nonatomic,retain)IBOutlet OpenGLView *glView;
@property (strong, nonatomic)IBOutlet UIWindow *window;


@end

