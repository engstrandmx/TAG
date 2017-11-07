// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TAG_TAGGameMode_generated_h
#error "TAGGameMode.generated.h already included, missing '#pragma once' in TAGGameMode.h"
#endif
#define TAG_TAGGameMode_generated_h

#define TAG_Source_TAG_TAGGameMode_h_20_RPC_WRAPPERS
#define TAG_Source_TAG_TAGGameMode_h_20_RPC_WRAPPERS_NO_PURE_DECLS
#define TAG_Source_TAG_TAGGameMode_h_20_EVENT_PARMS
#define TAG_Source_TAG_TAGGameMode_h_20_CALLBACK_WRAPPERS
#define TAG_Source_TAG_TAGGameMode_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATAGGameMode(); \
	friend TAG_API class UClass* Z_Construct_UClass_ATAGGameMode(); \
public: \
	DECLARE_CLASS(ATAGGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), 0, TEXT("/Script/TAG"), TAG_API) \
	DECLARE_SERIALIZER(ATAGGameMode) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TAG_Source_TAG_TAGGameMode_h_20_INCLASS \
private: \
	static void StaticRegisterNativesATAGGameMode(); \
	friend TAG_API class UClass* Z_Construct_UClass_ATAGGameMode(); \
public: \
	DECLARE_CLASS(ATAGGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), 0, TEXT("/Script/TAG"), TAG_API) \
	DECLARE_SERIALIZER(ATAGGameMode) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TAG_Source_TAG_TAGGameMode_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	TAG_API ATAGGameMode(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATAGGameMode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(TAG_API, ATAGGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATAGGameMode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	TAG_API ATAGGameMode(ATAGGameMode&&); \
	TAG_API ATAGGameMode(const ATAGGameMode&); \
public:


#define TAG_Source_TAG_TAGGameMode_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	TAG_API ATAGGameMode(ATAGGameMode&&); \
	TAG_API ATAGGameMode(const ATAGGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(TAG_API, ATAGGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATAGGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATAGGameMode)


#define TAG_Source_TAG_TAGGameMode_h_20_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__PlayerControllers() { return STRUCT_OFFSET(ATAGGameMode, PlayerControllers); } \
	FORCEINLINE static uint32 __PPO__bSpawnTypeFlipped() { return STRUCT_OFFSET(ATAGGameMode, bSpawnTypeFlipped); } \
	FORCEINLINE static uint32 __PPO__bSpawnSpectator() { return STRUCT_OFFSET(ATAGGameMode, bSpawnSpectator); }


#define TAG_Source_TAG_TAGGameMode_h_17_PROLOG \
	TAG_Source_TAG_TAGGameMode_h_20_EVENT_PARMS


#define TAG_Source_TAG_TAGGameMode_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TAG_Source_TAG_TAGGameMode_h_20_PRIVATE_PROPERTY_OFFSET \
	TAG_Source_TAG_TAGGameMode_h_20_RPC_WRAPPERS \
	TAG_Source_TAG_TAGGameMode_h_20_CALLBACK_WRAPPERS \
	TAG_Source_TAG_TAGGameMode_h_20_INCLASS \
	TAG_Source_TAG_TAGGameMode_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TAG_Source_TAG_TAGGameMode_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TAG_Source_TAG_TAGGameMode_h_20_PRIVATE_PROPERTY_OFFSET \
	TAG_Source_TAG_TAGGameMode_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	TAG_Source_TAG_TAGGameMode_h_20_CALLBACK_WRAPPERS \
	TAG_Source_TAG_TAGGameMode_h_20_INCLASS_NO_PURE_DECLS \
	TAG_Source_TAG_TAGGameMode_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TAG_Source_TAG_TAGGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
