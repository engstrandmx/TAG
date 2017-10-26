// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TAG_TAGPlayerController_generated_h
#error "TAGPlayerController.generated.h already included, missing '#pragma once' in TAGPlayerController.h"
#endif
#define TAG_TAGPlayerController_generated_h

#define TAG_Source_TAG_TAGPlayerController_h_27_RPC_WRAPPERS
#define TAG_Source_TAG_TAGPlayerController_h_27_RPC_WRAPPERS_NO_PURE_DECLS
#define TAG_Source_TAG_TAGPlayerController_h_27_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATAGPlayerController(); \
	friend TAG_API class UClass* Z_Construct_UClass_ATAGPlayerController(); \
public: \
	DECLARE_CLASS(ATAGPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), 0, TEXT("/Script/TAG"), NO_API) \
	DECLARE_SERIALIZER(ATAGPlayerController) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TAG_Source_TAG_TAGPlayerController_h_27_INCLASS \
private: \
	static void StaticRegisterNativesATAGPlayerController(); \
	friend TAG_API class UClass* Z_Construct_UClass_ATAGPlayerController(); \
public: \
	DECLARE_CLASS(ATAGPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), 0, TEXT("/Script/TAG"), NO_API) \
	DECLARE_SERIALIZER(ATAGPlayerController) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TAG_Source_TAG_TAGPlayerController_h_27_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATAGPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATAGPlayerController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATAGPlayerController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATAGPlayerController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATAGPlayerController(ATAGPlayerController&&); \
	NO_API ATAGPlayerController(const ATAGPlayerController&); \
public:


#define TAG_Source_TAG_TAGPlayerController_h_27_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATAGPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATAGPlayerController(ATAGPlayerController&&); \
	NO_API ATAGPlayerController(const ATAGPlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATAGPlayerController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATAGPlayerController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATAGPlayerController)


#define TAG_Source_TAG_TAGPlayerController_h_27_PRIVATE_PROPERTY_OFFSET
#define TAG_Source_TAG_TAGPlayerController_h_24_PROLOG
#define TAG_Source_TAG_TAGPlayerController_h_27_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TAG_Source_TAG_TAGPlayerController_h_27_PRIVATE_PROPERTY_OFFSET \
	TAG_Source_TAG_TAGPlayerController_h_27_RPC_WRAPPERS \
	TAG_Source_TAG_TAGPlayerController_h_27_INCLASS \
	TAG_Source_TAG_TAGPlayerController_h_27_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TAG_Source_TAG_TAGPlayerController_h_27_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TAG_Source_TAG_TAGPlayerController_h_27_PRIVATE_PROPERTY_OFFSET \
	TAG_Source_TAG_TAGPlayerController_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	TAG_Source_TAG_TAGPlayerController_h_27_INCLASS_NO_PURE_DECLS \
	TAG_Source_TAG_TAGPlayerController_h_27_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TAG_Source_TAG_TAGPlayerController_h


#define FOREACH_ENUM_EPLAYERTYPE(op) \
	op(EPlayerType::Troll) \
	op(EPlayerType::Gnome) \
	op(EPlayerType::Spectator) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
