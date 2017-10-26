// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TAG_Trigger_generated_h
#error "Trigger.generated.h already included, missing '#pragma once' in Trigger.h"
#endif
#define TAG_Trigger_generated_h

#define TAG_Source_TAG_Trigger_h_12_RPC_WRAPPERS
#define TAG_Source_TAG_Trigger_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define TAG_Source_TAG_Trigger_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATrigger(); \
	friend TAG_API class UClass* Z_Construct_UClass_ATrigger(); \
public: \
	DECLARE_CLASS(ATrigger, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/TAG"), NO_API) \
	DECLARE_SERIALIZER(ATrigger) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TAG_Source_TAG_Trigger_h_12_INCLASS \
private: \
	static void StaticRegisterNativesATrigger(); \
	friend TAG_API class UClass* Z_Construct_UClass_ATrigger(); \
public: \
	DECLARE_CLASS(ATrigger, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/TAG"), NO_API) \
	DECLARE_SERIALIZER(ATrigger) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TAG_Source_TAG_Trigger_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATrigger(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATrigger) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATrigger); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATrigger); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATrigger(ATrigger&&); \
	NO_API ATrigger(const ATrigger&); \
public:


#define TAG_Source_TAG_Trigger_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATrigger(ATrigger&&); \
	NO_API ATrigger(const ATrigger&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATrigger); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATrigger); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATrigger)


#define TAG_Source_TAG_Trigger_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__bTriggerOnce() { return STRUCT_OFFSET(ATrigger, bTriggerOnce); }


#define TAG_Source_TAG_Trigger_h_9_PROLOG
#define TAG_Source_TAG_Trigger_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TAG_Source_TAG_Trigger_h_12_PRIVATE_PROPERTY_OFFSET \
	TAG_Source_TAG_Trigger_h_12_RPC_WRAPPERS \
	TAG_Source_TAG_Trigger_h_12_INCLASS \
	TAG_Source_TAG_Trigger_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TAG_Source_TAG_Trigger_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TAG_Source_TAG_Trigger_h_12_PRIVATE_PROPERTY_OFFSET \
	TAG_Source_TAG_Trigger_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	TAG_Source_TAG_Trigger_h_12_INCLASS_NO_PURE_DECLS \
	TAG_Source_TAG_Trigger_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TAG_Source_TAG_Trigger_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
