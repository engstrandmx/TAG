// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TAG_MultiplayerGameMode_generated_h
#error "MultiplayerGameMode.generated.h already included, missing '#pragma once' in MultiplayerGameMode.h"
#endif
#define TAG_MultiplayerGameMode_generated_h

#define TAG_Source_TAG_MultiplayerGameMode_h_15_RPC_WRAPPERS
#define TAG_Source_TAG_MultiplayerGameMode_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define TAG_Source_TAG_MultiplayerGameMode_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMultiplayerGameMode(); \
	friend TAG_API class UClass* Z_Construct_UClass_AMultiplayerGameMode(); \
public: \
	DECLARE_CLASS(AMultiplayerGameMode, AGameMode, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), 0, TEXT("/Script/TAG"), NO_API) \
	DECLARE_SERIALIZER(AMultiplayerGameMode) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TAG_Source_TAG_MultiplayerGameMode_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAMultiplayerGameMode(); \
	friend TAG_API class UClass* Z_Construct_UClass_AMultiplayerGameMode(); \
public: \
	DECLARE_CLASS(AMultiplayerGameMode, AGameMode, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), 0, TEXT("/Script/TAG"), NO_API) \
	DECLARE_SERIALIZER(AMultiplayerGameMode) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TAG_Source_TAG_MultiplayerGameMode_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMultiplayerGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMultiplayerGameMode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMultiplayerGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMultiplayerGameMode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMultiplayerGameMode(AMultiplayerGameMode&&); \
	NO_API AMultiplayerGameMode(const AMultiplayerGameMode&); \
public:


#define TAG_Source_TAG_MultiplayerGameMode_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMultiplayerGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMultiplayerGameMode(AMultiplayerGameMode&&); \
	NO_API AMultiplayerGameMode(const AMultiplayerGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMultiplayerGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMultiplayerGameMode); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMultiplayerGameMode)


#define TAG_Source_TAG_MultiplayerGameMode_h_15_PRIVATE_PROPERTY_OFFSET
#define TAG_Source_TAG_MultiplayerGameMode_h_12_PROLOG
#define TAG_Source_TAG_MultiplayerGameMode_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TAG_Source_TAG_MultiplayerGameMode_h_15_PRIVATE_PROPERTY_OFFSET \
	TAG_Source_TAG_MultiplayerGameMode_h_15_RPC_WRAPPERS \
	TAG_Source_TAG_MultiplayerGameMode_h_15_INCLASS \
	TAG_Source_TAG_MultiplayerGameMode_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TAG_Source_TAG_MultiplayerGameMode_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TAG_Source_TAG_MultiplayerGameMode_h_15_PRIVATE_PROPERTY_OFFSET \
	TAG_Source_TAG_MultiplayerGameMode_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	TAG_Source_TAG_MultiplayerGameMode_h_15_INCLASS_NO_PURE_DECLS \
	TAG_Source_TAG_MultiplayerGameMode_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TAG_Source_TAG_MultiplayerGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
