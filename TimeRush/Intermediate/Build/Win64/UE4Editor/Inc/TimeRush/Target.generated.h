// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TIMERUSH_Target_generated_h
#error "Target.generated.h already included, missing '#pragma once' in Target.h"
#endif
#define TIMERUSH_Target_generated_h

#define TimeRush_Source_TimeRush_Target_h_15_RPC_WRAPPERS
#define TimeRush_Source_TimeRush_Target_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define TimeRush_Source_TimeRush_Target_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATarget(); \
	friend struct Z_Construct_UClass_ATarget_Statics; \
public: \
	DECLARE_CLASS(ATarget, AStaticMeshActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/TimeRush"), NO_API) \
	DECLARE_SERIALIZER(ATarget)


#define TimeRush_Source_TimeRush_Target_h_15_INCLASS \
private: \
	static void StaticRegisterNativesATarget(); \
	friend struct Z_Construct_UClass_ATarget_Statics; \
public: \
	DECLARE_CLASS(ATarget, AStaticMeshActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/TimeRush"), NO_API) \
	DECLARE_SERIALIZER(ATarget)


#define TimeRush_Source_TimeRush_Target_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATarget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATarget) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATarget); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATarget); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATarget(ATarget&&); \
	NO_API ATarget(const ATarget&); \
public:


#define TimeRush_Source_TimeRush_Target_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATarget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATarget(ATarget&&); \
	NO_API ATarget(const ATarget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATarget); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATarget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATarget)


#define TimeRush_Source_TimeRush_Target_h_15_PRIVATE_PROPERTY_OFFSET
#define TimeRush_Source_TimeRush_Target_h_12_PROLOG
#define TimeRush_Source_TimeRush_Target_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TimeRush_Source_TimeRush_Target_h_15_PRIVATE_PROPERTY_OFFSET \
	TimeRush_Source_TimeRush_Target_h_15_RPC_WRAPPERS \
	TimeRush_Source_TimeRush_Target_h_15_INCLASS \
	TimeRush_Source_TimeRush_Target_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TimeRush_Source_TimeRush_Target_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TimeRush_Source_TimeRush_Target_h_15_PRIVATE_PROPERTY_OFFSET \
	TimeRush_Source_TimeRush_Target_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	TimeRush_Source_TimeRush_Target_h_15_INCLASS_NO_PURE_DECLS \
	TimeRush_Source_TimeRush_Target_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TIMERUSH_API UClass* StaticClass<class ATarget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TimeRush_Source_TimeRush_Target_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
