// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "MageSkill6Index.generated.h"

UCLASS()
class MULTIGAME_API AMageSkill6Index : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMageSkill6Index();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	USphereComponent* SphereComponent;

	

};
