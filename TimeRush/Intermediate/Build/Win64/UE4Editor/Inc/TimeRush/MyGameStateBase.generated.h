// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TIMERUSH_MyGameStateBase_generated_h
#error "MyGameStateBase.generated.h already included, missing '#pragma once' in MyGameStateBase.h"
#endif
#define TIMERUSH_MyGameStateBase_generated_h

#define TimeRush_Source_TimeRush_MyGameStateBase_h_15_RPC_WRAPPERS
#define TimeRush_Source_TimeRush_MyGameStateBase_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define TimeRush_Source_TimeRush_MyGameStateBase_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyGameStateBase(); \
	friend struct Z_Construct_UClass_AMyGameStateBase_Statics; \
public: \
	DECLARE_CLASS(AMyGameStateBase, AGameStateBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/TimeRush"), NO_API) \
	DECLARE_SERIALIZER(AMyGameStateBase)


#define TimeRush_Source_TimeRush_MyGameStateBase_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAMyGameStateBase(); \
	friend struct Z_Construct_UClass_AMyGameStateBase_Statics; \
public: \
	DECLARE_CLASS(AMyGameStateBase, AGameStateBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/TimeRush"), NO_API) \
	DECLARE_SERIALIZER(AMyGameStateBase)


#define TimeRush_Source_TimeRush_MyGameStateBase_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyGameStateBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyGameStateBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyGameStateBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyGameStateBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyGameStateBase(AMyGameStateBase&&); \
	NO_API AMyGameStateBase(const AMyGameStateBase&); \
public:


#define TimeRush_Source_TimeRush_MyGameStateBase_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyGameStateBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyGameStateBase(AMyGameStateBase&&); \
	NO_API AMyGameStateBase(const AMyGameStateBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyGameStateBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyGameStateBase); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyGameStateBase)


#define TimeRush_Source_TimeRush_MyGameStateBase_h_15_PRIVATE_PROPERTY_OFFSET
#define TimeRush_Source_TimeRush_MyGameStateBase_h_12_PROLOG
#define TimeRush_Source_TimeRush_MyGameStateBase_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TimeRush_Source_TimeRush_MyGameStateBase_h_15_PRIVATE_PROPERTY_OFFSET \
	TimeRush_Source_TimeRush_MyGameStateBase_h_15_RPC_WRAPPERS \
	TimeRush_Source_TimeRush_MyGameStateBase_h_15_INCLASS \
	TimeRush_Source_TimeRush_MyGameStateBase_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TimeRush_Source_TimeRush_MyGameStateBase_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TimeRush_Source_TimeRush_MyGameStateBase_h_15_PRIVATE_PROPERTY_OFFSET \
	TimeRush_Source_TimeRush_MyGameStateBase_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	TimeRush_Source_TimeRush_MyGameStateBase_h_15_INCLASS_NO_PURE_DECLS \
	TimeRush_Source_TimeRush_MyGameStateBase_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TIMERUSH_API UClass* StaticClass<class AMyGameStateBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TimeRush_Source_TimeRush_MyGameStateBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
