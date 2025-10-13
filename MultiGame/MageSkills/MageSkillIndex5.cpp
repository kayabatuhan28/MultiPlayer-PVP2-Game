// Fill out your copyright notice in the Description page of Project Settings.


#include "MageSkillIndex5.h"

#include "Particles/ParticleSystemComponent.h"

// Sets default values
AMageSkillIndex5::AMageSkillIndex5()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("HitArea"));
	SphereComponent->SetupAttachment(GetRootComponent());
	SphereComponent->SetCollisionProfileName("NoCollision");

	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	SkeletalMeshComponent->SetupAttachment(SphereComponent->GetAttachmentRoot());

	ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle"));
	ParticleSystemComponent->SetupAttachment(SphereComponent->GetAttachmentRoot());

}

// Called when the game starts or when spawned
void AMageSkillIndex5::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMageSkillIndex5::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

