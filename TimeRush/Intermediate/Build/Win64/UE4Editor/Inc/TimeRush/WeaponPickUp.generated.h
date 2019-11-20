// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TIMERUSH_WeaponPickUp_generated_h
#error "WeaponPickUp.generated.h already included, missing '#pragma once' in WeaponPickUp.h"
#endif
#define TIMERUSH_WeaponPickUp_generated_h

#define TimeRush_Source_TimeRush_WeaponPickUp_h_12_RPC_WRAPPERS
#define TimeRush_Source_TimeRush_WeaponPickUp_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define TimeRush_Source_TimeRush_WeaponPickUp_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAWeaponPickUp(); \
	friend struct Z_Construct_UClass_AWeaponPickUp_Statics; \
public: \
	DECLARE_CLASS(AWeaponPickUp, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/TimeRush"), NO_API) \
	DECLARE_SERIALIZER(AWeaponPickUp)


#define TimeRush_Source_TimeRush_WeaponPickUp_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAWeaponPickUp(); \
	friend struct Z_Construct_UClass_AWeaponPickUp_Statics; \
public: \
	DECLARE_CLASS(AWeaponPickUp, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/TimeRush"), NO_API) \
	DECLARE_SERIALIZER(AWeaponPickUp)


#define TimeRush_Source_TimeRush_WeaponPickUp_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AWeaponPickUp(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AWeaponPickUp) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWeaponPickUp); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWeaponPickUp); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AWeaponPickUp(AWeaponPickUp&&); \
	NO_API AWeaponPickUp(const AWeaponPickUp&); \
public:


#define TimeRush_Source_TimeRush_WeaponPickUp_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AWeaponPickUp(AWeaponPickUp&&); \
	NO_API AWeaponPickUp(const AWeaponPickUp&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWeaponPickUp); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWeaponPickUp); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AWeaponPickUp)


#define TimeRush_Source_TimeRush_WeaponPickUp_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__MeshComponent() { return STRUCT_OFFSET(AWeaponPickUp, MeshComponent); } \
	FORCEINLINE static uint32 __PPO__SphereComponent() { return STRUCT_OFFSET(AWeaponPickUp, SphereComponent); } \
	FORCEINLINE static uint32 __PPO__CollectEffect() { return STRUCT_OFFSET(AWeaponPickUp, CollectEffect); }


#define TimeRush_Source_TimeRush_WeaponPickUp_h_9_PROLOG
#define TimeRush_Source_TimeRush_WeaponPickUp_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TimeRush_Source_TimeRush_WeaponPickUp_h_12_PRIVATE_PROPERTY_OFFSET \
	TimeRush_Source_TimeRush_WeaponPickUp_h_12_RPC_WRAPPERS \
	TimeRush_Source_TimeRush_WeaponPickUp_h_12_INCLASS \
	TimeRush_Source_TimeRush_WeaponPickUp_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TimeRush_Source_TimeRush_WeaponPickUp_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TimeRush_Source_TimeRush_WeaponPickUp_h_12_PRIVATE_PROPERTY_OFFSET \
	TimeRush_Source_TimeRush_WeaponPickUp_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	TimeRush_Source_TimeRush_WeaponPickUp_h_12_INCLASS_NO_PURE_DECLS \
	TimeRush_Source_TimeRush_WeaponPickUp_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TIMERUSH_API UClass* StaticClass<class AWeaponPickUp>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TimeRush_Source_TimeRush_WeaponPickUp_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
