// Fill out your copyright notice in the Description page of Project Settings.


#include "MageGroundStaffImpact.h"

#include "Particles/ParticleSystemComponent.h"

// Sets default values
AMageGroundStaffImpact::AMageGroundStaffImpact()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("HitArea"));
	SphereComponent->SetupAttachment(GetRootComponent());

	ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSys"));
	ParticleSystemComponent->SetupAttachment(SphereComponent->GetAttachmentRoot());

}

// Called when the game starts or when spawned
void AMageGroundStaffImpact::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMageGroundStaffImpact::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

