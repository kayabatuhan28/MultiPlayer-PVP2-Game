// Fill out your copyright notice in the Description page of Project Settings.


#include "MageLightiningStrike.h"

#include "Particles/ParticleSystemComponent.h"

// Sets default values
AMageLightiningStrike::AMageLightiningStrike()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("HitArea"));
	SphereComponent->SetupAttachment(GetRootComponent());

	SkillVfx = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("SkillVfx"));
	SkillVfx->SetupAttachment(SphereComponent->GetAttachmentRoot());

}

// Called when the game starts or when spawned
void AMageLightiningStrike::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMageLightiningStrike::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

