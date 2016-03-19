#!/bin/sh
#
# Copyright (c) 2015-present, DJI, Inc. All rights reserved.
#
# This script installs the docsets in the current folder into the user's ~/Library

(
cd "$(dirname "$0")"
DESTINATION="$HOME/Library/Developer/Shared/Documentation/DocSets/"
echo "This script will install the docsets in the current folder into $DESTINATION"
\ls -d *.docset | xargs -I {} cp -R {} $DESTINATION
echo "Installation complete. Please restart Xcode."
break;

)


- (void)viewDidLoad {
    [super viewDidLoad];

    // disable the connect button by default
    [self.connectButton setEnabled:NO];

    //Register App with key
    NSString* appKey = @"Please enter your App Key here";
    [DJISDKManager registerApp:appKey withDelegate:self];

    self.sdkVersionLabel.text = [@"DJI SDK Version: " stringByAppendingString:[DJISDKManager getSDKVersion]];
}- (void)viewDidLoad {
    [super viewDidLoad];

    // disable the connect button by default
    [self.connectButton setEnabled:NO];

    //Register App with key
    NSString* appKey = @"Please enter your App Key here";
    [DJISDKManager registerApp:appKey withDelegate:self];

    self.sdkVersionLabel.text = [@"DJI SDK Version: " stringByAppendingString:[DJISDKManager getSDKVersion]];
}
