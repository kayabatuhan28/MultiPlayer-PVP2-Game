// Fill out your copyright notice in the Description page of Project Settings.


#include "GreatSwordPrimary.h"

// Sets default values
AGreatSwordPrimary::AGreatSwordPrimary()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("HitArea"));
	BoxComponent->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void AGreatSwordPrimary::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGreatSwordPrimary::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGreatSwordPrimary::DestroyTime()
{
	K2_DestroyActor();
}

