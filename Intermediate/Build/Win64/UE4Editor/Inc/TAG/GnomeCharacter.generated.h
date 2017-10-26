// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVector;
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef TAG_GnomeCharacter_generated_h
#error "GnomeCharacter.generated.h already included, missing '#pragma once' in GnomeCharacter.h"
#endif
#define TAG_GnomeCharacter_generated_h

#define TAG_Source_TAG_GnomeCharacter_h_16_RPC_WRAPPERS \
	virtual void SimulateDeathFX_Implementation(FVector ForceVector); \
 \
	DECLARE_FUNCTION(execSimulateDeathFX) \
	{ \
		P_GET_STRUCT(FVector,Z_Param_ForceVector); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SimulateDeathFX_Implementation(Z_Param_ForceVector); \
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


#define TAG_Source_TAG_GnomeCharacter_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSimulateDeathFX) \
	{ \
		P_GET_STRUCT(FVector,Z_Param_ForceVector); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SimulateDeathFX_Implementation(Z_Param_ForceVector); \
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


#define TAG_Source_TAG_GnomeCharacter_h_16_EVENT_PARMS \
	struct GnomeCharacter_eventSimulateDeathFX_Parms \
	{ \
		FVector ForceVector; \
	};


#define TAG_Source_TAG_GnomeCharacter_h_16_CALLBACK_WRAPPERS
#define TAG_Source_TAG_GnomeCharacter_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGnomeCharacter(); \
	friend TAG_API class UClass* Z_Construct_UClass_AGnomeCharacter(); \
public: \
	DECLARE_CLASS(AGnomeCharacter, ATAGCharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/TAG"), NO_API) \
	DECLARE_SERIALIZER(AGnomeCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TAG_Source_TAG_GnomeCharacter_h_16_INCLASS \
private: \
	static void StaticRegisterNativesAGnomeCharacter(); \
	friend TAG_API class UClass* Z_Construct_UClass_AGnomeCharacter(); \
public: \
	DECLARE_CLASS(AGnomeCharacter, ATAGCharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/TAG"), NO_API) \
	DECLARE_SERIALIZER(AGnomeCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TAG_Source_TAG_GnomeCharacter_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGnomeCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGnomeCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGnomeCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGnomeCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGnomeCharacter(AGnomeCharacter&&); \
	NO_API AGnomeCharacter(const AGnomeCharacter&); \
public:


#define TAG_Source_TAG_GnomeCharacter_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGnomeCharacter(AGnomeCharacter&&); \
	NO_API AGnomeCharacter(const AGnomeCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGnomeCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGnomeCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGnomeCharacter)


#define TAG_Source_TAG_GnomeCharacter_h_16_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__LaunchForce() { return STRUCT_OFFSET(AGnomeCharacter, LaunchForce); } \
	FORCEINLINE static uint32 __PPO__GoldMesh() { return STRUCT_OFFSET(AGnomeCharacter, GoldMesh); } \
	FORCEINLINE static uint32 __PPO__DeathEmitter() { return STRUCT_OFFSET(AGnomeCharacter, DeathEmitter); } \
	FORCEINLINE static uint32 __PPO__MountDistance() { return STRUCT_OFFSET(AGnomeCharacter, MountDistance); } \
	FORCEINLINE static uint32 __PPO__CarryMovementSpeed() { return STRUCT_OFFSET(AGnomeCharacter, CarryMovementSpeed); } \
	FORCEINLINE static uint32 __PPO__PickupTime() { return STRUCT_OFFSET(AGnomeCharacter, PickupTime); } \
	FORCEINLINE static uint32 __PPO__MaxHealth() { return STRUCT_OFFSET(AGnomeCharacter, MaxHealth); }


#define TAG_Source_TAG_GnomeCharacter_h_13_PROLOG \
	TAG_Source_TAG_GnomeCharacter_h_16_EVENT_PARMS


#define TAG_Source_TAG_GnomeCharacter_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TAG_Source_TAG_GnomeCharacter_h_16_PRIVATE_PROPERTY_OFFSET \
	TAG_Source_TAG_GnomeCharacter_h_16_RPC_WRAPPERS \
	TAG_Source_TAG_GnomeCharacter_h_16_CALLBACK_WRAPPERS \
	TAG_Source_TAG_GnomeCharacter_h_16_INCLASS \
	TAG_Source_TAG_GnomeCharacter_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TAG_Source_TAG_GnomeCharacter_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TAG_Source_TAG_GnomeCharacter_h_16_PRIVATE_PROPERTY_OFFSET \
	TAG_Source_TAG_GnomeCharacter_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	TAG_Source_TAG_GnomeCharacter_h_16_CALLBACK_WRAPPERS \
	TAG_Source_TAG_GnomeCharacter_h_16_INCLASS_NO_PURE_DECLS \
	TAG_Source_TAG_GnomeCharacter_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TAG_Source_TAG_GnomeCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
