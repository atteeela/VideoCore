/*
 
 Video Core
 Copyright (c) 2014 James G. Hurley
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 
 */

/*!
 *  A simple Objective-C Session API that will create an RTMP session using the 
 *  device's camera(s) and microphone.
 *
 */

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, VCSessionState)
{
    VCSessionStateNone,
    VCSessionStateStarting,
    VCSessionStateStarted,
    VCSessionStateEnded,
    VCSessionStateError
    
};

typedef NS_ENUM(NSInteger, VCCameraState)
{
    VCCameraStateFront,
    VCCameraStateBack
};

@protocol VCSessionDelegate
@required
- (void) connectionStatusChanged: (VCSessionState) sessionState;
@end

@interface VCSimpleSession : NSObject

@property (nonatomic, readonly) VCSessionState rtmpSessionState;
@property (nonatomic, strong, readonly) UIView* previewView;

/*! Setters / Getters for session properties */
@property (nonatomic) CGSize        videoSize;      // Change will not take place until the next RTMP Session
@property (nonatomic) int           bitrate;        // Change will not take place until the next RTMP Session
@property (nonatomic) int           fps;            // Change will not take place until the next RTMP Session
@property (nonatomic) VCCameraState cameraState;
@property (nonatomic) BOOL          torch;
@property (nonatomic) float         videoZoomFactor;

@property (nonatomic) id<VCSessionDelegate> delegate;

// -----------------------------------------------------------------------------
- (instancetype) initWithVideoSize:(CGSize)videoSize
                         frameRate:(int)fps
                           bitrate:(int)bps;

// -----------------------------------------------------------------------------
- (void) startRtmpSessionWithURL:(NSString*) rtmpUrl
                    andStreamKey:(NSString*) streamKey;

- (void) endRtmpSession;

@end
