//
//  NLForwarding.h
//  CreateMLInternal
//
//  Copyright © 2019 Apple. All rights reserved.
//

#ifdef CREATEML_INTERNAL
#ifdef __OBJC2__

#import <Foundation/Foundation.h>
#import <NaturalLanguage/NLGazetteer.h>
#import <NaturalLanguage/NLEmbedding.h>

NS_ASSUME_NONNULL_BEGIN


API_AVAILABLE(macos(10.15))
@interface __NLEmbedding : NSObject

+ (BOOL)writeEmbeddingMLModelForDictionary:(NSDictionary<NSString *, NSArray<NSNumber *> *> *)dictionary
                                  language:(NLLanguage)language
                                  revision:(NSUInteger)revision
                                     toURL:(NSURL *)url
                                   options:(NSDictionary *)options
                                     error:(NSError **)error;

@end

API_AVAILABLE(macos(10.15))
@interface __NLGazetteer : NSObject

+ (BOOL)writeGazetteerMLModelForDictionary:(NSDictionary<NSString *, NSArray<NSString *> *> *)dictionary
                                  language:(NLLanguage)language
                                     toURL:(NSURL *)url
                                   options:(NSDictionary *)options
                                     error:(NSError **)error;

@end

NS_ASSUME_NONNULL_END

#endif // __OBJC__
#endif // CREATEML_INTERNAL
