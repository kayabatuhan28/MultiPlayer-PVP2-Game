// Fill out your copyright notice in the Description page of Project Settings.


#include "MagePrimarySkill.h"

#include "Particles/ParticleSystemComponent.h"

// Sets default values
AMagePrimarySkill::AMagePrimarySkill()
{
 	
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("HitArea"));
	SphereComponent->SetupAttachment(GetRootComponent());

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComponent"));
	ProjectileMovementComponent->SetUpdatedComponent(SphereComponent);
	ProjectileMovementComponent->InitialSpeed = 3000.f;
	ProjectileMovementComponent->MaxSpeed = 3000.f;
	ProjectileMovementComponent->ProjectileGravityScale = 0.f;

	SkillVfx = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("SkillVfx"));
	SkillVfx->SetupAttachment(SphereComponent->GetAttachmentRoot());
}


void AMagePrimarySkill::BeginPlay()
{
	Super::BeginPlay();
	
}


void AMagePrimarySkill::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMagePrimarySkill::DestroyTime()
{
	K2_DestroyActor();
}

