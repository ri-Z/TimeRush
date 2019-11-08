// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TimeRush/MyGameStateBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyGameStateBase() {}
// Cross Module References
	TIMERUSH_API UClass* Z_Construct_UClass_AMyGameStateBase_NoRegister();
	TIMERUSH_API UClass* Z_Construct_UClass_AMyGameStateBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameStateBase();
	UPackage* Z_Construct_UPackage__Script_TimeRush();
// End Cross Module References
	void AMyGameStateBase::StaticRegisterNativesAMyGameStateBase()
	{
	}
	UClass* Z_Construct_UClass_AMyGameStateBase_NoRegister()
	{
		return AMyGameStateBase::StaticClass();
	}
	struct Z_Construct_UClass_AMyGameStateBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMyGameStateBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameStateBase,
		(UObject* (*)())Z_Construct_UPackage__Script_TimeRush,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyGameStateBase_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "MyGameStateBase.h" },
		{ "ModuleRelativePath", "MyGameStateBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMyGameStateBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyGameStateBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMyGameStateBase_Statics::ClassParams = {
		&AMyGameStateBase::StaticClass,
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
		0x009002A0u,
		METADATA_PARAMS(Z_Construct_UClass_AMyGameStateBase_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AMyGameStateBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMyGameStateBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMyGameStateBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMyGameStateBase, 1379546025);
	template<> TIMERUSH_API UClass* StaticClass<AMyGameStateBase>()
	{
		return AMyGameStateBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMyGameStateBase(Z_Construct_UClass_AMyGameStateBase, &AMyGameStateBase::StaticClass, TEXT("/Script/TimeRush"), TEXT("AMyGameStateBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyGameStateBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
