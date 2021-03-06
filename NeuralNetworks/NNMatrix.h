//
//  NNMatrix.h
//  NeuralNetworks
//
//  Created by Pietro Saccardi on 07/05/12.
// 
// Copyright (C) 2013 Pietro Saccardi
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#import <Foundation/Foundation.h>

@interface NNMatrix : NSObject {
    float *matrix;
    float *normOfRows;
}
@property (readonly) NNMatrix *parentMatrix;
@property (readonly) NSUInteger width;
@property (readonly) NSUInteger height;
@property (readonly, getter=hasNormOfRows) BOOL normOfRows;
- (id)initWithWidth:(NSUInteger)w andHeight:(NSUInteger)h;
- (id)initWithImage:(NSImage *)img;
- (void)computeNormOfRows;
- (NSArray *)extractRowsWithThreshold:(float)th delta:(float)d minLength:(NSUInteger)min;
- (void)transpose;
- (NSDictionary *)matricesWithRanges:(NSArray *)ranges;
- (NSMutableSet *)connectedComponentsWithCallback:(BOOL (^)(CGFloat))cb;
@end
