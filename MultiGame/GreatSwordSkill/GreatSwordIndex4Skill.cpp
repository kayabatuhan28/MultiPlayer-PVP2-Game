// Fill out your copyright notice in the Description page of Project Settings.


#include "GreatSwordIndex4Skill.h"

#include "Particles/ParticleSystemComponent.h"

// Sets default values
AGreatSwordIndex4Skill::AGreatSwordIndex4Skill()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("HitArea"));
	BoxComponent->SetupAttachment(GetRootComponent());

	ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSys"));
	ParticleSystemComponent->SetupAttachment(BoxComponent->GetAttachmentRoot());

}

// Called when the game starts or when spawned
void AGreatSwordIndex4Skill::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGreatSwordIndex4Skill::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

