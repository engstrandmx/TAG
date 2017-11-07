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
#ifdef TAG_Trigger_generated_h
#error "Trigger.generated.h already included, missing '#pragma once' in Trigger.h"
#endif
#define TAG_Trigger_generated_h

#define TAG_Source_TAG_Trigger_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execTriggerEvent) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->TriggerEvent(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEndOverlap) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->EndOverlap(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex); \
		P_NATIVE_END; \
	} \
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


#define TAG_Source_TAG_Trigger_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execTriggerEvent) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->TriggerEvent(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEndOverlap) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->EndOverlap(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex); \
		P_NATIVE_END; \
	} \
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


#define TAG_Source_TAG_Trigger_h_13_EVENT_PARMS
#define TAG_Source_TAG_Trigger_h_13_CALLBACK_WRAPPERS
#define TAG_Source_TAG_Trigger_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATrigger(); \
	friend TAG_API class UClass* Z_Construct_UClass_ATrigger(); \
public: \
	DECLARE_CLASS(ATrigger, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/TAG"), NO_API) \
	DECLARE_SERIALIZER(ATrigger) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TAG_Source_TAG_Trigger_h_13_INCLASS \
private: \
	static void StaticRegisterNativesATrigger(); \
	friend TAG_API class UClass* Z_Construct_UClass_ATrigger(); \
public: \
	DECLARE_CLASS(ATrigger, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/TAG"), NO_API) \
	DECLARE_SERIALIZER(ATrigger) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TAG_Source_TAG_Trigger_h_13_STANDARD_CONSTRUCTORS \
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


#define TAG_Source_TAG_Trigger_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATrigger(ATrigger&&); \
	NO_API ATrigger(const ATrigger&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATrigger); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATrigger); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATrigger)


#define TAG_Source_TAG_Trigger_h_13_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__bTriggerOnce() { return STRUCT_OFFSET(ATrigger, bTriggerOnce); } \
	FORCEINLINE static uint32 __PPO__bIsStandOnTrigger() { return STRUCT_OFFSET(ATrigger, bIsStandOnTrigger); }


#define TAG_Source_TAG_Trigger_h_10_PROLOG \
	TAG_Source_TAG_Trigger_h_13_EVENT_PARMS


#define TAG_Source_TAG_Trigger_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TAG_Source_TAG_Trigger_h_13_PRIVATE_PROPERTY_OFFSET \
	TAG_Source_TAG_Trigger_h_13_RPC_WRAPPERS \
	TAG_Source_TAG_Trigger_h_13_CALLBACK_WRAPPERS \
	TAG_Source_TAG_Trigger_h_13_INCLASS \
	TAG_Source_TAG_Trigger_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TAG_Source_TAG_Trigger_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TAG_Source_TAG_Trigger_h_13_PRIVATE_PROPERTY_OFFSET \
	TAG_Source_TAG_Trigger_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	TAG_Source_TAG_Trigger_h_13_CALLBACK_WRAPPERS \
	TAG_Source_TAG_Trigger_h_13_INCLASS_NO_PURE_DECLS \
	TAG_Source_TAG_Trigger_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TAG_Source_TAG_Trigger_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
