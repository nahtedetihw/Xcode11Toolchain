//
//  SNForwarding.h
//  CreateML
//
//  Copyright © 2019 Apple. All rights reserved.
//

#ifdef CREATEML_INTERNAL
#ifdef __OBJC2__

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <SoundAnalysis/SoundAnalysis.h>

NS_ASSUME_NONNULL_BEGIN

@class MLModel, MLMultiArray;

typedef NS_ENUM(NSInteger, __SNFeaturePrintType) {
	__SNFeaturePrintTypeNone = 0,
	__SNFeaturePrintTypeFeatureEmbedding,
	__SNFeaturePrintTypeLogMelSpectogram
};

API_AVAILABLE(macos(10.15))
@protocol __SNCreateFeaturePrintRequest <NSObject>
@property (nonatomic, readwrite) __SNFeaturePrintType featurePrintType;
@property (nonatomic) float overlapFactor;
@end

API_AVAILABLE(macos(10.15))
@interface __SNCreateFeaturePrintRequest : NSObject
+ (id<__SNCreateFeaturePrintRequest>)createRequest;
@end

API_AVAILABLE(macos(10.15))
@protocol __SNFeaturePrint <NSObject>
@property (nonatomic, readonly) __SNFeaturePrintType featurePrintType;
@property (nonatomic, readonly) MLMultiArray *featureVector;
@end

API_AVAILABLE(macos(10.15))
@protocol __SNResultsCollector <SNResultsObserving>
@property (nonatomic, readonly) NSArray *results;
@property (nonatomic, readonly) NSArray<NSError *> *errors;
- (void)clearResults;
- (void)clearErrors;
@end

API_AVAILABLE(macos(10.15))
@interface __SNResultsCollector : NSObject
+ (id<__SNResultsCollector>)resultsCollector;
@end

NS_ASSUME_NONNULL_END

#endif // __OBJC__
#endif // CREATEML_INTERNAL
