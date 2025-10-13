// Fill out your copyright notice in the Description page of Project Settings.


#include "GreatSworIndex5Skill.h"

#include "Particles/ParticleSystemComponent.h"

// Sets default values
AGreatSworIndex5Skill::AGreatSworIndex5Skill()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("HitArea"));
	BoxComponent->SetupAttachment(GetRootComponent());

	SkillVfx = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("SkillVfx"));
	SkillVfx->SetupAttachment(BoxComponent->GetAttachmentRoot());

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	StaticMeshComponent->SetupAttachment(BoxComponent->GetAttachmentRoot());

}

// Called when the game starts or when spawned
void AGreatSworIndex5Skill::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void AGreatSworIndex5Skill::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

