// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "MagePrimarySkill.generated.h"

UCLASS()
class MULTIGAME_API AMagePrimarySkill : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AMagePrimarySkill();
	
protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly)
	USphereComponent* SphereComponent;
	
	UPROPERTY(EditDefaultsOnly)
	UProjectileMovementComponent* ProjectileMovementComponent;
	
	UPROPERTY(EditDefaultsOnly)
	UParticleSystemComponent* SkillVfx;

	UPROPERTY(EditDefaultsOnly)
	UParticleSystem* HitParticle;

	FTimerHandle MyTimerHandle;
	void DestroyTime();

};
