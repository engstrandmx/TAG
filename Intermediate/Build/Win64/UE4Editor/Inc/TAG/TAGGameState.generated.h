// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TAG_TAGGameState_generated_h
#error "TAGGameState.generated.h already included, missing '#pragma once' in TAGGameState.h"
#endif
#define TAG_TAGGameState_generated_h

#define TAG_Source_TAG_TAGGameState_h_16_RPC_WRAPPERS \
	virtual bool ServerResetTime_Validate(); \
	virtual void ServerResetTime_Implementation(); \
 \
	DECLARE_FUNCTION(execServerResetTime) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerResetTime_Validate()) \
		{ \
			RPC_ValidateFailed(TEXT("ServerResetTime_Validate")); \
			return; \
		} \
		this->ServerResetTime_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTimeElapsed) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetTimeElapsed(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetScore) \
	{ \
		P_GET_UBOOL(Z_Param_SideA); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=this->GetScore(Z_Param_SideA); \
		P_NATIVE_END; \
	}


#define TAG_Source_TAG_TAGGameState_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execServerResetTime) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerResetTime_Validate()) \
		{ \
			RPC_ValidateFailed(TEXT("ServerResetTime_Validate")); \
			return; \
		} \
		this->ServerResetTime_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTimeElapsed) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetTimeElapsed(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetScore) \
	{ \
		P_GET_UBOOL(Z_Param_SideA); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=this->GetScore(Z_Param_SideA); \
		P_NATIVE_END; \
	}


#define TAG_Source_TAG_TAGGameState_h_16_EVENT_PARMS
#define TAG_Source_TAG_TAGGameState_h_16_CALLBACK_WRAPPERS
#define TAG_Source_TAG_TAGGameState_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATAGGameState(); \
	friend TAG_API class UClass* Z_Construct_UClass_ATAGGameState(); \
public: \
	DECLARE_CLASS(ATAGGameState, AGameStateBase, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/TAG"), NO_API) \
	DECLARE_SERIALIZER(ATAGGameState) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TAG_Source_TAG_TAGGameState_h_16_INCLASS \
private: \
	static void StaticRegisterNativesATAGGameState(); \
	friend TAG_API class UClass* Z_Construct_UClass_ATAGGameState(); \
public: \
	DECLARE_CLASS(ATAGGameState, AGameStateBase, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/TAG"), NO_API) \
	DECLARE_SERIALIZER(ATAGGameState) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TAG_Source_TAG_TAGGameState_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATAGGameState(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATAGGameState) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATAGGameState); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATAGGameState); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATAGGameState(ATAGGameState&&); \
	NO_API ATAGGameState(const ATAGGameState&); \
public:


#define TAG_Source_TAG_TAGGameState_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATAGGameState(ATAGGameState&&); \
	NO_API ATAGGameState(const ATAGGameState&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATAGGameState); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATAGGameState); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATAGGameState)


#define TAG_Source_TAG_TAGGameState_h_16_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__TimeElapsed() { return STRUCT_OFFSET(ATAGGameState, TimeElapsed); } \
	FORCEINLINE static uint32 __PPO__RoundTime() { return STRUCT_OFFSET(ATAGGameState, RoundTime); } \
	FORCEINLINE static uint32 __PPO__GoldGatheredA() { return STRUCT_OFFSET(ATAGGameState, GoldGatheredA); } \
	FORCEINLINE static uint32 __PPO__GoldGatheredB() { return STRUCT_OFFSET(ATAGGameState, GoldGatheredB); }


#define TAG_Source_TAG_TAGGameState_h_13_PROLOG \
	TAG_Source_TAG_TAGGameState_h_16_EVENT_PARMS


#define TAG_Source_TAG_TAGGameState_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TAG_Source_TAG_TAGGameState_h_16_PRIVATE_PROPERTY_OFFSET \
	TAG_Source_TAG_TAGGameState_h_16_RPC_WRAPPERS \
	TAG_Source_TAG_TAGGameState_h_16_CALLBACK_WRAPPERS \
	TAG_Source_TAG_TAGGameState_h_16_INCLASS \
	TAG_Source_TAG_TAGGameState_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TAG_Source_TAG_TAGGameState_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TAG_Source_TAG_TAGGameState_h_16_PRIVATE_PROPERTY_OFFSET \
	TAG_Source_TAG_TAGGameState_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	TAG_Source_TAG_TAGGameState_h_16_CALLBACK_WRAPPERS \
	TAG_Source_TAG_TAGGameState_h_16_INCLASS_NO_PURE_DECLS \
	TAG_Source_TAG_TAGGameState_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TAG_Source_TAG_TAGGameState_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
