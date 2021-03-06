//
//  DJILBAirLink.h
//  DJISDK
//
//  Copyright © 2015, DJI. All rights reserved.
//

#import <DJISDK/DJISDK.h>

NS_ASSUME_NONNULL_BEGIN

@class DJILBAirLink;
@class DJISignalInformation;

/**
 *  Define the air link max supported channel count
 */
#define DJI_LBAIRLINK_SUPPORTED_CHANNEL_COUNT (8)

/*********************************************************************************/
#pragma mark - Data Struct
/*********************************************************************************/

/**
 *  Downlink channel selection mode (manual or automatic) for wireless link.
 */
typedef NS_ENUM (uint8_t, DJILBAirLinkChannelSelectionMode) {
    /**
     *  Air link will automatically select the best physical channel based on the signal environment.
     */
    DJILBAirLinkChannelSelectionModeAuto,
    /**
     *  Manually select the physical channel.
     */
    DJILBAirLinkChannelSelectionModeManual,
    /**
     *  Unknown physical channel selection mode.
     */
    DJILBAirLinkChannelSelectionModeUnknown,
};

/**
 *  OSD data units.
 */
typedef NS_ENUM (uint8_t, DJILBAirLinkOSDUnits) {
    /**
     *  Imperial
     */
    DJILBAirLinkOSDUnitsImperial,
    /**
     *  Metric
     */
    DJILBAirLinkOSDUnitsMetric,
    /**
     *  Unknown
     */
    DJILBAirLinkOSDUnitsUnknown,
};

/**
 *  Remote Controller port to output secondary video to (in addition to USB video sent to the Mobile Device).
 */
typedef NS_ENUM (uint8_t, DJILBAirLinkSecondaryVideoOutputPort) {
    /**
     *  HDMI port
     */
    DJILBAirLinkSecondaryVideoOutputPortHDMI,
    /**
     *  SDI port
     */
    DJILBAirLinkSecondaryVideoOutputPortSDI,
    /**
     *  Unknown
     */
    DJILBAirLinkSecondaryVideoOutputPortUnknown,
};

/**
 *  Define the combination of video sources to form the secondary output video.
 */
typedef NS_ENUM (uint8_t, DJILBAirLinkPIPDisplayMode) {
    /**
     *  Displays the FPV Camera (HDMI or AV input to the air link Module).
     */
    DJILBAirLinkPIPDisplayModeLB,
    /**
     *  Displays the video from the HD Gimbal (Gimbal input to the air link Module).
     */
    DJILBAirLinkPIPDisplayModeExt,
    /**
     *  Displays the video from HD Gimbal camera as the main subject, and the HDMI or AV video from FPV camera in a mini window (Picture in Picture, or PIP).
     */
    DJILBAirLinkPIPDisplayModePIPLB,
    /**
     *  Displays the HDMI or AV output of the FPV camera as the main subject, and the video from the HD Gimbal in a mini window (Picture in Picture, or PIP).
     */
    DJILBAirLinkPIPDisplayModePIPExt,
    /**
     *  Unknown output mode.
     */
    DJILBAirLinkPIPDisplayModeUnknown,
};

/**
 *  Secondary output video resolution and frame rate.
 */
typedef NS_ENUM (uint8_t, DJILBAirLinkSecondaryVideoFormat) {
    /**
     *  1080I
     */
    DJILBAirLinkSecondaryVideoFormat1080I60FPS,
    DJILBAirLinkSecondaryVideoFormat1080I50FPS,
    /**
     *  1080P
     */
    DJILBAirLinkSecondaryVideoFormat1080P60FPS,
    DJILBAirLinkSecondaryVideoFormat1080P50FPS,
    DJILBAirLinkSecondaryVideoFormat1080P30FPS,
    DJILBAirLinkSecondaryVideoFormat1080P25FPS,
    DJILBAirLinkSecondaryVideoFormat1080P24FPS,
    /**
     *  720P
     */
    DJILBAirLinkSecondaryVideoFormat720P60FPS,
    DJILBAirLinkSecondaryVideoFormat720P50FPS,
    DJILBAirLinkSecondaryVideoFormat720P30FPS,
    DJILBAirLinkSecondaryVideoFormat720P25FPS,
    /**
     *  Unknown
     */
    DJILBAirLinkSecondaryVideoFormatUnknown,
};

/**
 *  PIP (Picture In Picture) position on the screen reltaive to the main subject video.
 *
 */
typedef NS_ENUM (uint8_t, DJILBAirLinkPIPPosition) {
    /**
     *  PIP is in the screen's top left.
     */
    DJILBAirLinkPIPPositionTopLeft,
    /**
     *  PIP is in the screen's top right.
     */
    DJILBAirLinkPIPPositionTopRight,
    /**
     *  PIP is in the screen's bottom left.
     */
    DJILBAirLinkPIPPositionBottomLeft,
    /**
     *  PIP is in the screen's bottom right.
     */
    DJILBAirLinkPIPPositionBottomRight,
    /**
     *  Unknown PIP position.
     */
    DJILBAirLinkPIPPositionUnknown,
};

/**
 *  FPV Video can prioritize either quality or latency.
 */
typedef NS_ENUM (uint8_t, DJILBAirLinkFPVVideoQualityLatency) {
    /**
     *  High quality priority.
     */
    DJILBAirLinkFPVVideoQualityLatencyHighQuality,
    /**
     *  Low latency priority.
     */
    DJILBAirLinkFPVVideoQualityLatencyLowLatency,
    /**
     *  Unknown transmission mode.
     */
    DJILBAirLinkFPVVideoQualityLatencyUnknown,
};

/**
 *  Wireless downlink data rate. Lower rates are used for longer ranges, but will have lower video quality.
 *
 */
typedef NS_ENUM (uint8_t, DJILBAirLinkDataRate) {
    /**
     *  4 Mbps (Potential range up to 3 km)
     */
    DJILBAirLinkDataRate4Mbps,
    /**
     *  6 Mbps (Potential range up to 2 km)
     */
    DJILBAirLinkDataRate6Mbps,
    /**
     *  8 Mbps (Potential range up to 1.5 km)
     */
    DJILBAirLinkDataRate8Mbps,
    /**
     *  10 Mbps (Potential range up to 0.7 km)
     */
    DJILBAirLinkDataRate10Mbps,
    /**
     *  Unknown
     */
    DJILBAirLinkDataRateUnknown
};

/**
 *  RSSI (Received Signal Strength Indicator) in dBm
 *
 */
typedef struct
{
    /**
     *  RSSI with range [-100, -60] dBm
     *
     */
    int8_t rssi[DJI_LBAIRLINK_SUPPORTED_CHANNEL_COUNT];
} DJILBAirLinkAllChannelSignalStrengths;

/*********************************************************************************/
#pragma mark - DJILBAirLinkDelegate
/*********************************************************************************/

/**
 *  This protocol provides delegate methods to receive updated signal information for channels and updated video data from Lightbridge 2.
 */
@protocol DJILBAirLinkDelegate <NSObject>

@optional

/**
 *  Signal quality and strength information for current uplink channel on each Remote Controller antenna.
 *
 *  @param lbAirLink   DJILBAirLink Instance.
 *  @param antennas    DJISignalInformation object. The power property is valid only when the connecting product is Lightbridge 2.
 *                     For other products, the value of power is always 0.
 */
- (void)lbAirLink:(DJILBAirLink *_Nonnull)lbAirLink didUpdateRemoteControllerSignalInformation:(NSArray *_Nonnull)antennas;

/**
 *  Signal quality and strength information for current downlink channel on each air link module antenna.
 *
 *  @param lbAirLink    DJILBAirLink Instance.
 *  @param antennas     DJISignalInformation object.
 */
- (void)lbAirLink:(DJILBAirLink *_Nonnull)lbAirLink didUpdateLBAirLinkModuleSignalInformation:(NSArray *_Nonnull)antennas;

/**
 *  Signal strength for all available downlink channels.
 *
 *  @param lbAirLink        DJILBAirLink Instance.
 *  @param signalStrength   The strength of the signal.
 */
- (void)lbAirLink:(DJILBAirLink *_Nonnull)lbAirLink didUpdateAllChannelSignalStrengths:(DJILBAirLinkAllChannelSignalStrengths)signalStrength;

/**
 *  Callback for when the FPV video bandwidth percentage has changed. Each Remote Controller can create a secondary video from the FPV and HD Gimbal video downlink information. For the slave Remote Controllers it's important to know if the percentage bandwidth has changed so the right PIP display mode (DJIPIPDisplayMode) can be selected. For example, if the FPV video bandwidth goes to 100%, then DJIALPIPModeLB should be used.
 *
 *  @param lbAirLink        DJILBAirLink instance.
 *  @param bandwidthPercent Output bandwidth percentage.
 */
- (void)lbAirLink:(DJILBAirLink *_Nonnull)lbAirLink didFPVBandwidthPercentChanged:(float)bandwidthPercent;

/**
 *  Tells the delegate that a updated Video data is received.
 *
 *  @param lbAirLink    DJILBAirLink Instance.
 *  @param data         The received video data.
 */
- (void)lbAirLink:(DJILBAirLink *_Nonnull)lbAirLink didReceiveVideoData:(NSData *)data;

@end


/*********************************************************************************/
#pragma mark - DJILBAirLink
/*********************************************************************************/

/**
 *  This class contains methods to change settings of the Lightbridge Air Link.
 */
@interface DJILBAirLink : NSObject

@property(nonatomic, weak) id<DJILBAirLinkDelegate> delegate;

/**
 *  Sets downlink channel selection mode (automatic or manual).
 *
 *  @param mode       Channel selection mode for LBAirLink.
 *  @param completion Completion block.
 */
- (void)setChannelSelectionMode:(DJILBAirLinkChannelSelectionMode)mode withCompletion:(DJICompletionBlock)completion;

/**
 *  Gets downlink channel selection mode.
 *
 *  @param completion Completion block.
 */
- (void)getChannelSelectionModeWithCompletion:(void (^_Nullable)(DJILBAirLinkChannelSelectionMode mode, NSError *_Nullable error))completion;

/**
 *  Sets fixed downlink channel. Channel selection mode should be set to DJILBAirLinkChannelSelectionModeManual.
 *  Channel can be between 1 and DJILBAirLinkSupportedChannelMax.
 *
 *  @param channel    Specific channel for the air link.
 *  @param completion Completion block.

 */
- (void)setChannel:(int)channel withCompletion:(DJICompletionBlock)completion;

/**
 *  Gets current downlink channel of air link.
 *
 *  @param completion Completion block.
 */
- (void)getChannelWithCompletion:(void (^_Nullable)(int channel, NSError *_Nullable error))completion;

/**
 *  Sets the downlink data rate (throughput). Higher data rates increase the quality of video transmission, but can only be used at shorter ranges.
 *
 *  @param rate  Fixed rate (throughput).
 *  @param completion Completion block.
 */
- (void)setDataRate:(DJILBAirLinkDataRate)rate withCompletion:(DJICompletionBlock)completion;

/**
 *  Gets the current downlink data rate (throughput).
 *
 *  @param completion Completion block.
 */
- (void)getDataRateWithCompletion:(void (^_Nullable)(DJILBAirLinkDataRate rate, NSError *_Nullable error))completion;

/**
 *  Sets FPV video quality vs latency preference. This mode only effects the FPV camera and not the camera on the HD Gimbal.
 *
 *  @param qualityLatency Quality vs Latency tradeoff for the FPV video
 *  @param completion     Completion block.
 */
- (void)setFPVQualityLatency:(DJILBAirLinkFPVVideoQualityLatency)qualityLatency withCompletion:(DJICompletionBlock)completion;

/**
 *  Gets FPV video quality vs latency preference. This mode only effects the FPV camera and not the camera on the HD Gimbal.
 *
 *  @param completion Completion block.
 */
- (void)getFPVQualityLatencyWithCompletion:(void (^_Nullable)(DJILBAirLinkFPVVideoQualityLatency qualityLatency, NSError *_Nullable error))completion;

/**
 *  Sets the percentage downlink video bandwidth dedicated to the FPV camera. The remaining percentage is dedicated to the camera on the HD Gimbal. Setting 100% dedicates all the video bandwidth to FPV.
 *
 *  @param percent    Percentage downlink bandwidth for FPV camera.
 *  @param completion Completion block.
 */
- (void)setFPVVideoBandwidthPercent:(float)percent withCompletion:(DJICompletionBlock)completion;

/**
 *  Gets the percentage downlink video bandwidth dedicated to the FPV camera. The remaining percentage is dedicated to the camera on the HD Gimbal. Setting 100% dedicates all the video bandwidth to FPV.
 *
 */
- (void)getFPVVideoBandwidthPercentWithCompletion:(void (^_Nullable)(float percent, NSError *_Nullable error))completion;


/*********************************************************************************/
#pragma mark - Secondary Video Output
/*********************************************************************************/

/**
 *  Return whether secondary video output supported.
 *
 *  @return Secondary video output support result
 */
- (BOOL)isSecondaryVideoOutputSupported;

/**
 *  Enable secondary video output on Remote Controller. The remote controller outputs video to the Mobile Device by default. This will enable a secondary video stream to one of the Remote Controller's physical HDMI and SDI ports (set by setSecondaryVideoPort).
 *
 *  @param enabled    Enables secondary video output.
 *  @param completion Completion block.
 */
- (void)setSecondaryVideoOutputEnabled:(BOOL)enabled withCompletion:(DJICompletionBlock)completion;

/**
 *  Gets whether secondary video output on Remote Controller is enabled. The Remote Controller outputs video to the Mobile Device by default, but a secondary video can be routed to its HDMI or SDI port. Use setSecondaryVideoOuputEnable to enable/disable and setSecondaryVideoOutputPort to choose the port.
 *
 *  @param completion Completion block.
 */
- (void)getSecondaryVideoOutputEnabledWithCompletion:(void (^_Nullable)(BOOL enabled, NSError *_Nullable error))completion;

/**
 *  Sets secondary video output port on Remote Controller. HDMI or SDI are possible. Only one port can be active at once.
 *
 *  @param port       Secondary video output port.
 *  @param completion Completion block.
 */
- (void)setSecondaryVideoOutputPort:(DJILBAirLinkSecondaryVideoOutputPort)port withCompletion:(DJICompletionBlock)completion;

/**
 *  Gets secondary video output port on Remote Controller. HDMI or SDI are possible. Only one port can be active at once.
 *
 *  @param completion Completion block.
 */
- (void)getSecondaryVideoOutputPortWithCompletion:(void (^_Nullable)(DJILBAirLinkSecondaryVideoOutputPort port, NSError *_Nullable error))completion;

/**
 *  Sets the secondary video output Picture in Picture (PIP) display mode. The air link module can connect to both an FPV camera (through the HDMI and AV ports) and a camera mounted on the HD Gimbal (through the Gimbal port). The output video can then be a combination of the two video sources. Either a single video source can be displayed, or one can be displayed within the other (as a Picture in Picture, or PIP). If the mode is set incorrectly, then no output video will be displayed. For example, if only a FPV camera is connected, or the bandwidth for the 'LB' data (FPV) is set to 100 percent, then the only mode that will display data is the DJILBAirLinkPIPModeLB.
 *
 *  @param pipDisplay Picture in Picture display mode.
 *  @param completion Completion block.
 *
 */
- (void)setPIPDisplay:(DJILBAirLinkPIPDisplayMode)pipDisplay withCompletion:(DJICompletionBlock)completion;

/**
 *  Gets the secondary video output Picture in Picture (PIP) display mode. The air link module can connect to both an FPV camera (through the HDMI and AV ports) and a camera mounted on the HD Gimbal (through the Gimbal port). The output video can then be a combination of the two video sources. Either a single video source can be displayed, or one can be displayed within the other (as a Picture in Picture, or PIP).
 *
 *  @param completion Completion block.
 *
 */
- (void)getPIPDisplayWithCompletion:(void (^_Nullable)(DJILBAirLinkPIPDisplayMode pipDisplay, NSError *_Nullable error))completion;

/**
 *  Enables and disables OSD overlay on the secondary video. OSD is flight data like altitude, attitude etc. and can be overlayed on the PIP video.
 *
 *  @param enabled Whether dispaly OSD on screen.
 *  @param completion Completion block.
 *
 */
- (void)setDisplayOSDEnabled:(BOOL)enabled withCompletion:(DJICompletionBlock)completion;

/**
 *  Gets whether OSD is overlayed on the video feed.
 *
 *  @param completion Completion block.
 *
 */
- (void)getDisplayOSDEnabledWithCompletion:(void (^_Nullable)(BOOL enabled, NSError *_Nullable error))completion;

/**
 *  Sets OSD top margin in video pixels.
 *
 *  @param margin     Top margin of OSD, should be in range [0, 50]
 *  @param completion Completion block.
 *
 */
- (void)setOSDTopMargin:(NSUInteger)margin withCompletion:(DJICompletionBlock)completion;

/**
 *  Gets OSD top margin in video pixels.
 *
 *  @param completion Completion block.
 *
 */
- (void)getOSDTopMarginWithCompletion:(void (^_Nullable)(NSUInteger margin, NSError *_Nullable error))completion;

/**
 *  Sets OSD left margin in video pixels.
 *
 *  @param margin     Left margin of OSD, should be in range [0, 50]
 *  @param completion Completion block.
 *
 */
- (void)setOSDLeftMargin:(NSUInteger)margin withCompletion:(DJICompletionBlock)completion;

/**
 *  Gets OSD left margin in video pixels.
 *
 *  @param completion Completion block.
 *
 */
- (void)getOSDLeftMarginWithCompletion:(void (^_Nullable)(NSUInteger margin, NSError *_Nullable error))completion;

/**
 *  Sets OSD bottom margin in video pixels.
 *
 *  @param margin     Bottom margin of OSD, should be in range [0, 50]
 *  @param completion Completion block.
 *
 */
- (void)setOSDBottomMargin:(NSUInteger)margin withCompletion:(DJICompletionBlock)completion;

/**
 *  Gets OSD bottom margin in video pixels.
 *
 *  @param completion Completion block.
 *
 */
- (void)getOSDBottomMarginWithCompletion:(void (^_Nullable)(NSUInteger margin, NSError *_Nullable error))completion;

/**
 *  Sets OSD right margin in video pixels.
 *
 *  @param margin     Right margin of OSD, should be in range [0, 50]
 *  @param completion Completion block.
 *
 */
- (void)setOSDRightMargin:(NSUInteger)margin withCompletion:(DJICompletionBlock)completion;

/**
 *  Gets OSD right margin in video pixels.
 *
 *  @param completion Completion block.
 *
 */
- (void)getOSDRightMarginWithCompletion:(void (^_Nullable)(NSUInteger margin, NSError *_Nullable error))completion;

/**
 *  Sets OSD units to be metric or imperial.
 *
 *  @param units       OSD unit.
 *  @param completion Completion block.
 *
 */
- (void)setOSDUnits:(DJILBAirLinkOSDUnits)units withCompletion:(DJICompletionBlock)completion;

/**
 *  Gets OSD units as either metric or imperial.
 *
 *  @param completion Completion block.
 *
 */
- (void)getOSDUnitsWithCompletion:(void (^_Nullable)(DJILBAirLinkOSDUnits units, NSError *_Nullable error))completion;

/**
 *  Sets Remote Controller HDMI video port output video format.
 *
 *  @param outputFormat Video output format for HDMI port.
 *  @param completion   Completion block.
 *
 */
- (void)setHDMIOutputFormat:(DJILBAirLinkSecondaryVideoFormat)format withCompletion:(DJICompletionBlock)completion;

/**
 *  Gets Remote Controller HDMI video port output video format.
 *
 *  @param completion Completion block.
 *
 */
- (void)getHDMIOutputFormatWithCompletion:(void (^_Nullable)(DJILBAirLinkSecondaryVideoFormat format, NSError *_Nullable error))completion;

/**
 *  Sets Remote Controller SDI video port output video format.
 *
 *  @param outputFormat Video output format for SDI port.
 *  @param completion   Completion block.
 *
 */
- (void)setSDIOutputFormat:(DJILBAirLinkSecondaryVideoFormat)format withCompletion:(DJICompletionBlock)completion;

/**
 *  Gets Remote Controller SDI video port output video format.
 *
 *  @param completion Completion block.
 *
 */
- (void)getSDIOutputFormatWithCompletion:(void (^_Nullable)(DJILBAirLinkSecondaryVideoFormat format, NSError *_Nullable error))completion;

/**
 *  Sets PIP (Picture In Picture) position relative to top left corner of the main subject video feed.
 *
 *
 *  @param position   Position of PIP on the screen.
 *  @param completion Completion block.
 *
 */
- (void)setPIPPosition:(DJILBAirLinkPIPPosition)position withCompletion:(DJICompletionBlock)completion;

/**
 *  Gets PIP (Picture In Picture) position relative to top left corner of the main subject video feed.
 *
 *  @param completion Completion block.
 *
 */
- (void)getPIPPositionWithCompletion:(void (^_Nullable)(DJILBAirLinkPIPPosition position, NSError *_Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
