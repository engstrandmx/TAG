// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef TAG_WaterField_generated_h
#error "WaterField.generated.h already included, missing '#pragma once' in WaterField.h"
#endif
#define TAG_WaterField_generated_h

#define TAG_Source_TAG_WaterField_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execBeginOverlap) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->BeginOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define TAG_Source_TAG_WaterField_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execBeginOverlap) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->BeginOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define TAG_Source_TAG_WaterField_h_12_EVENT_PARMS \
	struct WaterField_eventOnActorEnter_Parms \
	{ \
		AActor* EnteringActor; \
	};


#define TAG_Source_TAG_WaterField_h_12_CALLBACK_WRAPPERS
#define TAG_Source_TAG_WaterField_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAWaterField(); \
	friend TAG_API class UClass* Z_Construct_UClass_AWaterField(); \
public: \
	DECLARE_CLASS(AWaterField, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/TAG"), NO_API) \
	DECLARE_SERIALIZER(AWaterField) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TAG_Source_TAG_WaterField_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAWaterField(); \
	friend TAG_API class UClass* Z_Construct_UClass_AWaterField(); \
public: \
	DECLARE_CLASS(AWaterField, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/TAG"), NO_API) \
	DECLARE_SERIALIZER(AWaterField) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TAG_Source_TAG_WaterField_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AWaterField(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AWaterField) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWaterField); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWaterField); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AWaterField(AWaterField&&); \
	NO_API AWaterField(const AWaterField&); \
public:


#define TAG_Source_TAG_WaterField_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AWaterField(AWaterField&&); \
	NO_API AWaterField(const AWaterField&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWaterField); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWaterField); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AWaterField)


#define TAG_Source_TAG_WaterField_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__WaveSimMult() { return STRUCT_OFFSET(AWaterField, WaveSimMult); } \
	FORCEINLINE static uint32 __PPO__WaveMagnitude() { return STRUCT_OFFSET(AWaterField, WaveMagnitude); }


#define TAG_Source_TAG_WaterField_h_9_PROLOG \
	TAG_Source_TAG_WaterField_h_12_EVENT_PARMS


#define TAG_Source_TAG_WaterField_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TAG_Source_TAG_WaterField_h_12_PRIVATE_PROPERTY_OFFSET \
	TAG_Source_TAG_WaterField_h_12_RPC_WRAPPERS \
	TAG_Source_TAG_WaterField_h_12_CALLBACK_WRAPPERS \
	TAG_Source_TAG_WaterField_h_12_INCLASS \
	TAG_Source_TAG_WaterField_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TAG_Source_TAG_WaterField_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TAG_Source_TAG_WaterField_h_12_PRIVATE_PROPERTY_OFFSET \
	TAG_Source_TAG_WaterField_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	TAG_Source_TAG_WaterField_h_12_CALLBACK_WRAPPERS \
	TAG_Source_TAG_WaterField_h_12_INCLASS_NO_PURE_DECLS \
	TAG_Source_TAG_WaterField_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TAG_Source_TAG_WaterField_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
