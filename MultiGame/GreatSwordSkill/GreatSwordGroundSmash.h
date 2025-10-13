// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "GreatSwordGroundSmash.generated.h"

UCLASS()
class MULTIGAME_API AGreatSwordGroundSmash : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AGreatSwordGroundSmash();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	USphereComponent* SphereComponent;

	

};
