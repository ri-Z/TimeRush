// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TimeRush/TimeRushGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTimeRushGameModeBase() {}
// Cross Module References
	TIMERUSH_API UClass* Z_Construct_UClass_ATimeRushGameModeBase_NoRegister();
	TIMERUSH_API UClass* Z_Construct_UClass_ATimeRushGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_TimeRush();
// End Cross Module References
	void ATimeRushGameModeBase::StaticRegisterNativesATimeRushGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_ATimeRushGameModeBase_NoRegister()
	{
		return ATimeRushGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ATimeRushGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATimeRushGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_TimeRush,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATimeRushGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "TimeRushGameModeBase.h" },
		{ "ModuleRelativePath", "TimeRushGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATimeRushGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATimeRushGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATimeRushGameModeBase_Statics::ClassParams = {
		&ATimeRushGameModeBase::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002A8u,
		METADATA_PARAMS(Z_Construct_UClass_ATimeRushGameModeBase_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ATimeRushGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATimeRushGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATimeRushGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATimeRushGameModeBase, 614257287);
	template<> TIMERUSH_API UClass* StaticClass<ATimeRushGameModeBase>()
	{
		return ATimeRushGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATimeRushGameModeBase(Z_Construct_UClass_ATimeRushGameModeBase, &ATimeRushGameModeBase::StaticClass, TEXT("/Script/TimeRush"), TEXT("ATimeRushGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATimeRushGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
