//
//  SelectionManager.h
//  TrenchBroom
//
//  Created by Kristian Duske on 30.01.11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "Math.h"

extern NSString* const SelectionAdded;
extern NSString* const SelectionRemoved;

extern NSString* const SelectionEntities;
extern NSString* const SelectionBrushes;
extern NSString* const SelectionFaces;
extern NSString* const SelectionVertices;

typedef enum {
    SM_UNDEFINED,
    SM_FACES,
    SM_BRUSHES,
    SM_ENTITIES,
    SM_BRUSHES_ENTITIES
} ESelectionMode;

@protocol Face;
@protocol Brush;
@protocol Entity;

@interface SelectionManager : NSObject {
    @private
    NSUndoManager* undoManager;
    NSMutableArray* faces;
    NSMutableArray* partialBrushes;
    NSMutableArray* brushes;
    NSMutableArray* entities;
    id <Entity> brushSelectionEntity;
    BOOL brushSelectionEntityValid;
    ESelectionMode mode;
}

- (id)initWithUndoManager:(NSUndoManager *)theUndoManager;

- (void)addFace:(id <Face>)face record:(BOOL)record;
- (void)addFaces:(NSArray *)theFaces record:(BOOL)record;
- (void)addBrush:(id <Brush>)brush record:(BOOL)record;
- (void)addBrushes:(NSArray *)theBrushes record:(BOOL)record;
- (void)addEntity:(id <Entity>)entity record:(BOOL)record;
- (void)addEntities:(NSArray *)theEntities record:(BOOL)record;

- (ESelectionMode)mode;
- (BOOL)isFaceSelected:(id <Face>)face;
- (BOOL)isBrushSelected:(id <Brush>)brush;
- (BOOL)isEntitySelected:(id <Entity>)entity;
- (BOOL)isBrushPartiallySelected:(id <Brush>)brush;

- (NSArray *)selectedEntities;
- (NSArray *)selectedBrushes;
- (NSArray *)selectedFaces;
- (NSArray *)selectedBrushFaces;
- (NSArray *)partiallySelectedBrushes;
- (BOOL)selectionCenter:(TVector3f *)result;
- (BOOL)selectionBounds:(TBoundingBox *)result;
- (id <Entity>)brushSelectionEntity;

- (BOOL)hasSelection;
- (BOOL)hasSelectedEntities;
- (BOOL)hasSelectedBrushes;
- (BOOL)hasSelectedFaces;

- (void)removeFace:(id <Face>)face record:(BOOL)record;
- (void)removeFaces:(NSArray *)theFaces record:(BOOL)record;
- (void)removeBrush:(id <Brush>)brush record:(BOOL)record;
- (void)removeBrushes:(NSArray *)theBrushes record:(BOOL)record;
- (void)removeEntity:(id <Entity>)entity record:(BOOL)record;
- (void)removeEntities:(NSArray *)theEntities record:(BOOL)record;

- (void)removeAll:(BOOL)record;

@end
