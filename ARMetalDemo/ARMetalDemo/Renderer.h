//
//  Renderer.h
//  ARMetalDemo
//
//  Created by vivi wu on 2017/6/16.
//  Copyright © 2017年 vivi wu. All rights reserved.
//

#import <Metal/Metal.h>
#import <ARKit/ARKit.h>

NS_ASSUME_NONNULL_BEGIN

/*
 Protocol abstracting the platform specific view in order to keep the Renderer
 class independent from platform.
 */
@protocol RenderDestinationProvider

@property (nonatomic, readonly, nullable) MTLRenderPassDescriptor *currentRenderPassDescriptor;
@property (nonatomic, readonly, nullable) id<MTLDrawable> currentDrawable;

@property (nonatomic) MTLPixelFormat colorPixelFormat;
@property (nonatomic) MTLPixelFormat depthStencilPixelFormat;
@property (nonatomic) NSUInteger sampleCount;

@end


/*
 The main class performing the rendering of a session.
 */
@interface Renderer : NSObject

- (instancetype)initWithSession:(ARSession *)session metalDevice:(id<MTLDevice>)device renderDestinationProvider:(id<RenderDestinationProvider>)renderDestinationProvider;

- (void)drawRectResized:(CGSize)size;

- (void)update;

@end

NS_ASSUME_NONNULL_END
