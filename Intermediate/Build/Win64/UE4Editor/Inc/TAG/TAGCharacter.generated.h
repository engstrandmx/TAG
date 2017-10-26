// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AController;
struct FDamageEvent;
class AActor;
#ifdef TAG_TAGCharacter_generated_h
#error "TAGCharacter.generated.h already included, missing '#pragma once' in TAGCharacter.h"
#endif
#define TAG_TAGCharacter_generated_h

#define TAG_Source_TAG_TAGCharacter_h_13_RPC_WRAPPERS \
	virtual void SetMeshVisible_Implementation(bool isTrue); \
	virtual bool ServerResetPlayer_Validate(AController* ); \
	virtual void ServerResetPlayer_Implementation(AController* InController); \
	virtual bool ServerTakeDamage_Validate(float , FDamageEvent const& , AController* , AActor* ); \
	virtual void ServerTakeDamage_Implementation(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser); \
	virtual bool ServerInteract_Validate(); \
	virtual void ServerInteract_Implementation(); \
 \
	DECLARE_FUNCTION(execSetMeshVisible) \
	{ \
		P_GET_UBOOL(Z_Param_isTrue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetMeshVisible_Implementation(Z_Param_isTrue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDelayedRestart) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->DelayedRestart(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerResetPlayer) \
	{ \
		P_GET_OBJECT(AController,Z_Param_InController); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerResetPlayer_Validate(Z_Param_InController)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerResetPlayer_Validate")); \
			return; \
		} \
		this->ServerResetPlayer_Implementation(Z_Param_InController); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnRep_Health) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnRep_Health(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerTakeDamage) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Damage); \
		P_GET_STRUCT(FDamageEvent,Z_Param_DamageEvent); \
		P_GET_OBJECT(AController,Z_Param_EventInstigator); \
		P_GET_OBJECT(AActor,Z_Param_DamageCauser); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerTakeDamage_Validate(Z_Param_Damage,Z_Param_DamageEvent,Z_Param_EventInstigator,Z_Param_DamageCauser)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerTakeDamage_Validate")); \
			return; \
		} \
		this->ServerTakeDamage_Implementation(Z_Param_Damage,Z_Param_DamageEvent,Z_Param_EventInstigator,Z_Param_DamageCauser); \
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
	}


#define TAG_Source_TAG_TAGCharacter_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetMeshVisible) \
	{ \
		P_GET_UBOOL(Z_Param_isTrue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetMeshVisible_Implementation(Z_Param_isTrue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDelayedRestart) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->DelayedRestart(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerResetPlayer) \
	{ \
		P_GET_OBJECT(AController,Z_Param_InController); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerResetPlayer_Validate(Z_Param_InController)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerResetPlayer_Validate")); \
			return; \
		} \
		this->ServerResetPlayer_Implementation(Z_Param_InController); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnRep_Health) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnRep_Health(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerTakeDamage) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Damage); \
		P_GET_STRUCT(FDamageEvent,Z_Param_DamageEvent); \
		P_GET_OBJECT(AController,Z_Param_EventInstigator); \
		P_GET_OBJECT(AActor,Z_Param_DamageCauser); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerTakeDamage_Validate(Z_Param_Damage,Z_Param_DamageEvent,Z_Param_EventInstigator,Z_Param_DamageCauser)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerTakeDamage_Validate")); \
			return; \
		} \
		this->ServerTakeDamage_Implementation(Z_Param_Damage,Z_Param_DamageEvent,Z_Param_EventInstigator,Z_Param_DamageCauser); \
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
	}


#define TAG_Source_TAG_TAGCharacter_h_13_EVENT_PARMS \
	struct TAGCharacter_eventServerResetPlayer_Parms \
	{ \
		AController* InController; \
	}; \
	struct TAGCharacter_eventServerTakeDamage_Parms \
	{ \
		float Damage; \
		FDamageEvent DamageEvent; \
		AController* EventInstigator; \
		AActor* DamageCauser; \
	}; \
	struct TAGCharacter_eventSetMeshVisible_Parms \
	{ \
		bool isTrue; \
	};


#define TAG_Source_TAG_TAGCharacter_h_13_CALLBACK_WRAPPERS
#define TAG_Source_TAG_TAGCharacter_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATAGCharacter(); \
	friend TAG_API class UClass* Z_Construct_UClass_ATAGCharacter(); \
public: \
	DECLARE_CLASS(ATAGCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/TAG"), NO_API) \
	DECLARE_SERIALIZER(ATAGCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TAG_Source_TAG_TAGCharacter_h_13_INCLASS \
private: \
	static void StaticRegisterNativesATAGCharacter(); \
	friend TAG_API class UClass* Z_Construct_UClass_ATAGCharacter(); \
public: \
	DECLARE_CLASS(ATAGCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/TAG"), NO_API) \
	DECLARE_SERIALIZER(ATAGCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TAG_Source_TAG_TAGCharacter_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATAGCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATAGCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATAGCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATAGCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATAGCharacter(ATAGCharacter&&); \
	NO_API ATAGCharacter(const ATAGCharacter&); \
public:


#define TAG_Source_TAG_TAGCharacter_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATAGCharacter(ATAGCharacter&&); \
	NO_API ATAGCharacter(const ATAGCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATAGCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATAGCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATAGCharacter)


#define TAG_Source_TAG_TAGCharacter_h_13_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(ATAGCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(ATAGCharacter, FollowCamera); } \
	FORCEINLINE static uint32 __PPO__bCanMove() { return STRUCT_OFFSET(ATAGCharacter, bCanMove); } \
	FORCEINLINE static uint32 __PPO__Health() { return STRUCT_OFFSET(ATAGCharacter, Health); }


#define TAG_Source_TAG_TAGCharacter_h_10_PROLOG \
	TAG_Source_TAG_TAGCharacter_h_13_EVENT_PARMS


#define TAG_Source_TAG_TAGCharacter_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TAG_Source_TAG_TAGCharacter_h_13_PRIVATE_PROPERTY_OFFSET \
	TAG_Source_TAG_TAGCharacter_h_13_RPC_WRAPPERS \
	TAG_Source_TAG_TAGCharacter_h_13_CALLBACK_WRAPPERS \
	TAG_Source_TAG_TAGCharacter_h_13_INCLASS \
	TAG_Source_TAG_TAGCharacter_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TAG_Source_TAG_TAGCharacter_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TAG_Source_TAG_TAGCharacter_h_13_PRIVATE_PROPERTY_OFFSET \
	TAG_Source_TAG_TAGCharacter_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	TAG_Source_TAG_TAGCharacter_h_13_CALLBACK_WRAPPERS \
	TAG_Source_TAG_TAGCharacter_h_13_INCLASS_NO_PURE_DECLS \
	TAG_Source_TAG_TAGCharacter_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TAG_Source_TAG_TAGCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
