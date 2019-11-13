// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TIMERUSH_MyCharacter_generated_h
#error "MyCharacter.generated.h already included, missing '#pragma once' in MyCharacter.h"
#endif
#define TIMERUSH_MyCharacter_generated_h

#define TimeRush_Source_TimeRush_MyCharacter_h_12_RPC_WRAPPERS
#define TimeRush_Source_TimeRush_MyCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define TimeRush_Source_TimeRush_MyCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyCharacter(); \
	friend struct Z_Construct_UClass_AMyCharacter_Statics; \
public: \
	DECLARE_CLASS(AMyCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/TimeRush"), NO_API) \
	DECLARE_SERIALIZER(AMyCharacter)


#define TimeRush_Source_TimeRush_MyCharacter_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAMyCharacter(); \
	friend struct Z_Construct_UClass_AMyCharacter_Statics; \
public: \
	DECLARE_CLASS(AMyCharacter, ACharacter, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/TimeRush"), NO_API) \
	DECLARE_SERIALIZER(AMyCharacter)


#define TimeRush_Source_TimeRush_MyCharacter_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyCharacter(AMyCharacter&&); \
	NO_API AMyCharacter(const AMyCharacter&); \
public:


#define TimeRush_Source_TimeRush_MyCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyCharacter(AMyCharacter&&); \
	NO_API AMyCharacter(const AMyCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyCharacter)


#define TimeRush_Source_TimeRush_MyCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraComponent() { return STRUCT_OFFSET(AMyCharacter, CameraComponent); }


#define TimeRush_Source_TimeRush_MyCharacter_h_9_PROLOG
#define TimeRush_Source_TimeRush_MyCharacter_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TimeRush_Source_TimeRush_MyCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	TimeRush_Source_TimeRush_MyCharacter_h_12_RPC_WRAPPERS \
	TimeRush_Source_TimeRush_MyCharacter_h_12_INCLASS \
	TimeRush_Source_TimeRush_MyCharacter_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TimeRush_Source_TimeRush_MyCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TimeRush_Source_TimeRush_MyCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	TimeRush_Source_TimeRush_MyCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	TimeRush_Source_TimeRush_MyCharacter_h_12_INCLASS_NO_PURE_DECLS \
	TimeRush_Source_TimeRush_MyCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TIMERUSH_API UClass* StaticClass<class AMyCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TimeRush_Source_TimeRush_MyCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
