// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TAG_TriggerActorComponent_generated_h
#error "TriggerActorComponent.generated.h already included, missing '#pragma once' in TriggerActorComponent.h"
#endif
#define TAG_TriggerActorComponent_generated_h

#define TAG_Source_TAG_TriggerActorComponent_h_15_DELEGATE \
static inline void FOnTriggerSignature_DelegateWrapper(const FMulticastScriptDelegate& OnTriggerSignature) \
{ \
	OnTriggerSignature.ProcessMulticastDelegate<UObject>(NULL); \
}


#define TAG_Source_TAG_TriggerActorComponent_h_14_RPC_WRAPPERS
#define TAG_Source_TAG_TriggerActorComponent_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define TAG_Source_TAG_TriggerActorComponent_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUTriggerActorComponent(); \
	friend TAG_API class UClass* Z_Construct_UClass_UTriggerActorComponent(); \
public: \
	DECLARE_CLASS(UTriggerActorComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/TAG"), NO_API) \
	DECLARE_SERIALIZER(UTriggerActorComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TAG_Source_TAG_TriggerActorComponent_h_14_INCLASS \
private: \
	static void StaticRegisterNativesUTriggerActorComponent(); \
	friend TAG_API class UClass* Z_Construct_UClass_UTriggerActorComponent(); \
public: \
	DECLARE_CLASS(UTriggerActorComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/TAG"), NO_API) \
	DECLARE_SERIALIZER(UTriggerActorComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TAG_Source_TAG_TriggerActorComponent_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UTriggerActorComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UTriggerActorComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UTriggerActorComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTriggerActorComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UTriggerActorComponent(UTriggerActorComponent&&); \
	NO_API UTriggerActorComponent(const UTriggerActorComponent&); \
public:


#define TAG_Source_TAG_TriggerActorComponent_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UTriggerActorComponent(UTriggerActorComponent&&); \
	NO_API UTriggerActorComponent(const UTriggerActorComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UTriggerActorComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTriggerActorComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UTriggerActorComponent)


#define TAG_Source_TAG_TriggerActorComponent_h_14_PRIVATE_PROPERTY_OFFSET
#define TAG_Source_TAG_TriggerActorComponent_h_10_PROLOG
#define TAG_Source_TAG_TriggerActorComponent_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TAG_Source_TAG_TriggerActorComponent_h_14_PRIVATE_PROPERTY_OFFSET \
	TAG_Source_TAG_TriggerActorComponent_h_14_RPC_WRAPPERS \
	TAG_Source_TAG_TriggerActorComponent_h_14_INCLASS \
	TAG_Source_TAG_TriggerActorComponent_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TAG_Source_TAG_TriggerActorComponent_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TAG_Source_TAG_TriggerActorComponent_h_14_PRIVATE_PROPERTY_OFFSET \
	TAG_Source_TAG_TriggerActorComponent_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	TAG_Source_TAG_TriggerActorComponent_h_14_INCLASS_NO_PURE_DECLS \
	TAG_Source_TAG_TriggerActorComponent_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TAG_Source_TAG_TriggerActorComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
