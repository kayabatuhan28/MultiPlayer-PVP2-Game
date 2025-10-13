// Fill out your copyright notice in the Description page of Project Settings.


#include "GreatSwordRMBAttack.h"

// Sets default values
AGreatSwordRMBAttack::AGreatSwordRMBAttack()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("HitArea"));
	BoxComponent->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void AGreatSwordRMBAttack::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGreatSwordRMBAttack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

