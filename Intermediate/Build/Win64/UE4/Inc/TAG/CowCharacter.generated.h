// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TAG_CowCharacter_generated_h
#error "CowCharacter.generated.h already included, missing '#pragma once' in CowCharacter.h"
#endif
#define TAG_CowCharacter_generated_h

#define TAG_Source_TAG_CowCharacter_h_21_RPC_WRAPPERS
#define TAG_Source_TAG_CowCharacter_h_21_RPC_WRAPPERS_NO_PURE_DECLS
#define TAG_Source_TAG_CowCharacter_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACowCharacter(); \
	friend TAG_API class UClass* Z_Construct_UClass_ACowCharacter(); \
public: \
	DECLARE_CLASS(ACowCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/TAG"), NO_API) \
	DECLARE_SERIALIZER(ACowCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TAG_Source_TAG_CowCharacter_h_21_INCLASS \
private: \
	static void StaticRegisterNativesACowCharacter(); \
	friend TAG_API class UClass* Z_Construct_UClass_ACowCharacter(); \
public: \
	DECLARE_CLASS(ACowCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/TAG"), NO_API) \
	DECLARE_SERIALIZER(ACowCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TAG_Source_TAG_CowCharacter_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACowCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACowCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACowCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACowCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACowCharacter(ACowCharacter&&); \
	NO_API ACowCharacter(const ACowCharacter&); \
public:


#define TAG_Source_TAG_CowCharacter_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACowCharacter(ACowCharacter&&); \
	NO_API ACowCharacter(const ACowCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACowCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACowCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACowCharacter)


#define TAG_Source_TAG_CowCharacter_h_21_PRIVATE_PROPERTY_OFFSET
#define TAG_Source_TAG_CowCharacter_h_18_PROLOG
#define TAG_Source_TAG_CowCharacter_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TAG_Source_TAG_CowCharacter_h_21_PRIVATE_PROPERTY_OFFSET \
	TAG_Source_TAG_CowCharacter_h_21_RPC_WRAPPERS \
	TAG_Source_TAG_CowCharacter_h_21_INCLASS \
	TAG_Source_TAG_CowCharacter_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TAG_Source_TAG_CowCharacter_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TAG_Source_TAG_CowCharacter_h_21_PRIVATE_PROPERTY_OFFSET \
	TAG_Source_TAG_CowCharacter_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	TAG_Source_TAG_CowCharacter_h_21_INCLASS_NO_PURE_DECLS \
	TAG_Source_TAG_CowCharacter_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TAG_Source_TAG_CowCharacter_h


#define FOREACH_ENUM_EAISTATE(op) \
	op(EAiState::VE_Wandering) \
	op(EAiState::VE_Fleeing) \
	op(EAiState::VE_Flying) \
	op(EAiState::VE_Floating) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
