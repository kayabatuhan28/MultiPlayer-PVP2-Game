// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacter.h"
#include "Animation/AnimInstance.h"
#include "MageAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class MULTIGAME_API UMageAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
	UPROPERTY(BlueprintReadOnly,Category = Character)
	bool WeaponEquipped;

	UPROPERTY(BlueprintReadOnly)
	float Direction;

	bool DoOnceVariable;

	FTimerHandle ResetDoOnceTimer;
	void ResetDoOnce();

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<AActor>> SkillsActor;

	UFUNCTION(BlueprintCallable)
	void CastPrimaryAttack();

private:
	UPROPERTY(BlueprintReadOnly,Category = Character, meta=(AllowPrivateAccess = "true"))
	APlayerCharacter* PlayerCharacter;
	
	UPROPERTY(BlueprintReadOnly,Category = Character, meta=(AllowPrivateAccess = "true"))
	float Speed;

	UPROPERTY(BlueprintReadOnly,Category = Character, meta=(AllowPrivateAccess = "true"))
	bool bIsInAir;

	UPROPERTY(BlueprintReadOnly,Category = Character, meta=(AllowPrivateAccess = "true"))
	bool bIsAccelerating;
	
};
