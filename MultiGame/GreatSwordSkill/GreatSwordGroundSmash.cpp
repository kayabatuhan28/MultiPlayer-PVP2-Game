// Fill out your copyright notice in the Description page of Project Settings.


#include "GreatSwordGroundSmash.h"

// Sets default values
AGreatSwordGroundSmash::AGreatSwordGroundSmash()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("HitArea"));
	SphereComponent->SetupAttachment(GetRootComponent());

}


void AGreatSwordGroundSmash::BeginPlay()
{
	Super::BeginPlay();
	
}


void AGreatSwordGroundSmash::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

