// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef TIMERUSH_SniperProjectile_generated_h
#error "SniperProjectile.generated.h already included, missing '#pragma once' in SniperProjectile.h"
#endif
#define TIMERUSH_SniperProjectile_generated_h

#define TimeRush_Source_TimeRush_SniperProjectile_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execApplyGravity) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ApplyGravity(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnProjectileHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnProjectileHit(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define TimeRush_Source_TimeRush_SniperProjectile_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execApplyGravity) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ApplyGravity(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnProjectileHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnProjectileHit(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define TimeRush_Source_TimeRush_SniperProjectile_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASniperProjectile(); \
	friend struct Z_Construct_UClass_ASniperProjectile_Statics; \
public: \
	DECLARE_CLASS(ASniperProjectile, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/TimeRush"), NO_API) \
	DECLARE_SERIALIZER(ASniperProjectile)


#define TimeRush_Source_TimeRush_SniperProjectile_h_13_INCLASS \
private: \
	static void StaticRegisterNativesASniperProjectile(); \
	friend struct Z_Construct_UClass_ASniperProjectile_Statics; \
public: \
	DECLARE_CLASS(ASniperProjectile, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/TimeRush"), NO_API) \
	DECLARE_SERIALIZER(ASniperProjectile)


#define TimeRush_Source_TimeRush_SniperProjectile_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASniperProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASniperProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASniperProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASniperProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASniperProjectile(ASniperProjectile&&); \
	NO_API ASniperProjectile(const ASniperProjectile&); \
public:


#define TimeRush_Source_TimeRush_SniperProjectile_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASniperProjectile(ASniperProjectile&&); \
	NO_API ASniperProjectile(const ASniperProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASniperProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASniperProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASniperProjectile)


#define TimeRush_Source_TimeRush_SniperProjectile_h_13_PRIVATE_PROPERTY_OFFSET
#define TimeRush_Source_TimeRush_SniperProjectile_h_10_PROLOG
#define TimeRush_Source_TimeRush_SniperProjectile_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TimeRush_Source_TimeRush_SniperProjectile_h_13_PRIVATE_PROPERTY_OFFSET \
	TimeRush_Source_TimeRush_SniperProjectile_h_13_RPC_WRAPPERS \
	TimeRush_Source_TimeRush_SniperProjectile_h_13_INCLASS \
	TimeRush_Source_TimeRush_SniperProjectile_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TimeRush_Source_TimeRush_SniperProjectile_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TimeRush_Source_TimeRush_SniperProjectile_h_13_PRIVATE_PROPERTY_OFFSET \
	TimeRush_Source_TimeRush_SniperProjectile_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	TimeRush_Source_TimeRush_SniperProjectile_h_13_INCLASS_NO_PURE_DECLS \
	TimeRush_Source_TimeRush_SniperProjectile_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TIMERUSH_API UClass* StaticClass<class ASniperProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TimeRush_Source_TimeRush_SniperProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
