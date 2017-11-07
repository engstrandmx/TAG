// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TAG_TrollCharacter_generated_h
#error "TrollCharacter.generated.h already included, missing '#pragma once' in TrollCharacter.h"
#endif
#define TAG_TrollCharacter_generated_h

#define TAG_Source_TAG_TrollCharacter_h_16_RPC_WRAPPERS \
	virtual void SimulateInteractFX_Implementation(); \
	virtual bool ServerDealDamage_Validate(); \
	virtual void ServerDealDamage_Implementation(); \
	virtual bool ServerInteract_Validate(); \
	virtual void ServerInteract_Implementation(); \
	virtual bool ServerStopInteract_Validate(); \
	virtual void ServerStopInteract_Implementation(); \
 \
	DECLARE_FUNCTION(execSimulateInteractFX) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SimulateInteractFX_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnRep_IsPunching) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnRep_IsPunching(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDealDamage) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->DealDamage(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerDealDamage) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerDealDamage_Validate()) \
		{ \
			RPC_ValidateFailed(TEXT("ServerDealDamage_Validate")); \
			return; \
		} \
		this->ServerDealDamage_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerInteract) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerInteract_Validate()) \
		{ \
			RPC_ValidateFailed(TEXT("ServerInteract_Validate")); \
			return; \
		} \
		this->ServerInteract_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerStopInteract) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerStopInteract_Validate()) \
		{ \
			RPC_ValidateFailed(TEXT("ServerStopInteract_Validate")); \
			return; \
		} \
		this->ServerStopInteract_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDelayedInteract) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->DelayedInteract(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIsPunching) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->GetIsPunching(); \
		P_NATIVE_END; \
	}


#define TAG_Source_TAG_TrollCharacter_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSimulateInteractFX) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SimulateInteractFX_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnRep_IsPunching) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnRep_IsPunching(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDealDamage) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->DealDamage(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerDealDamage) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerDealDamage_Validate()) \
		{ \
			RPC_ValidateFailed(TEXT("ServerDealDamage_Validate")); \
			return; \
		} \
		this->ServerDealDamage_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerInteract) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerInteract_Validate()) \
		{ \
			RPC_ValidateFailed(TEXT("ServerInteract_Validate")); \
			return; \
		} \
		this->ServerInteract_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerStopInteract) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerStopInteract_Validate()) \
		{ \
			RPC_ValidateFailed(TEXT("ServerStopInteract_Validate")); \
			return; \
		} \
		this->ServerStopInteract_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDelayedInteract) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->DelayedInteract(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIsPunching) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->GetIsPunching(); \
		P_NATIVE_END; \
	}


#define TAG_Source_TAG_TrollCharacter_h_16_EVENT_PARMS
#define TAG_Source_TAG_TrollCharacter_h_16_CALLBACK_WRAPPERS
#define TAG_Source_TAG_TrollCharacter_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATrollCharacter(); \
	friend TAG_API class UClass* Z_Construct_UClass_ATrollCharacter(); \
public: \
	DECLARE_CLASS(ATrollCharacter, ATAGCharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/TAG"), NO_API) \
	DECLARE_SERIALIZER(ATrollCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TAG_Source_TAG_TrollCharacter_h_16_INCLASS \
private: \
	static void StaticRegisterNativesATrollCharacter(); \
	friend TAG_API class UClass* Z_Construct_UClass_ATrollCharacter(); \
public: \
	DECLARE_CLASS(ATrollCharacter, ATAGCharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/TAG"), NO_API) \
	DECLARE_SERIALIZER(ATrollCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TAG_Source_TAG_TrollCharacter_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATrollCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATrollCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATrollCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATrollCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATrollCharacter(ATrollCharacter&&); \
	NO_API ATrollCharacter(const ATrollCharacter&); \
public:


#define TAG_Source_TAG_TrollCharacter_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATrollCharacter(ATrollCharacter&&); \
	NO_API ATrollCharacter(const ATrollCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATrollCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATrollCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATrollCharacter)


#define TAG_Source_TAG_TrollCharacter_h_16_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SpawnedPawn() { return STRUCT_OFFSET(ATrollCharacter, SpawnedPawn); } \
	FORCEINLINE static uint32 __PPO__DismountOffset() { return STRUCT_OFFSET(ATrollCharacter, DismountOffset); } \
	FORCEINLINE static uint32 __PPO__InteractShape() { return STRUCT_OFFSET(ATrollCharacter, InteractShape); } \
	FORCEINLINE static uint32 __PPO__Damage() { return STRUCT_OFFSET(ATrollCharacter, Damage); } \
	FORCEINLINE static uint32 __PPO__DamageRadius() { return STRUCT_OFFSET(ATrollCharacter, DamageRadius); } \
	FORCEINLINE static uint32 __PPO__CurrentHealth() { return STRUCT_OFFSET(ATrollCharacter, CurrentHealth); } \
	FORCEINLINE static uint32 __PPO__MaxHealth() { return STRUCT_OFFSET(ATrollCharacter, MaxHealth); } \
	FORCEINLINE static uint32 __PPO__DamageParticles() { return STRUCT_OFFSET(ATrollCharacter, DamageParticles); }


#define TAG_Source_TAG_TrollCharacter_h_13_PROLOG \
	TAG_Source_TAG_TrollCharacter_h_16_EVENT_PARMS


#define TAG_Source_TAG_TrollCharacter_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TAG_Source_TAG_TrollCharacter_h_16_PRIVATE_PROPERTY_OFFSET \
	TAG_Source_TAG_TrollCharacter_h_16_RPC_WRAPPERS \
	TAG_Source_TAG_TrollCharacter_h_16_CALLBACK_WRAPPERS \
	TAG_Source_TAG_TrollCharacter_h_16_INCLASS \
	TAG_Source_TAG_TrollCharacter_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TAG_Source_TAG_TrollCharacter_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TAG_Source_TAG_TrollCharacter_h_16_PRIVATE_PROPERTY_OFFSET \
	TAG_Source_TAG_TrollCharacter_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	TAG_Source_TAG_TrollCharacter_h_16_CALLBACK_WRAPPERS \
	TAG_Source_TAG_TrollCharacter_h_16_INCLASS_NO_PURE_DECLS \
	TAG_Source_TAG_TrollCharacter_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TAG_Source_TAG_TrollCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
