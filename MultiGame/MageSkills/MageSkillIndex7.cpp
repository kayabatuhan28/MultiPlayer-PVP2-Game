// Fill out your copyright notice in the Description page of Project Settings.


#include "MageSkillIndex7.h"

#include "Particles/ParticleSystemComponent.h"

// Sets default values
AMageSkillIndex7::AMageSkillIndex7()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("HitArea"));
	BoxComponent->SetupAttachment(GetRootComponent());

	ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("SkillVfx"));
	ParticleSystemComponent->SetupAttachment(BoxComponent->GetAttachmentRoot());

}

// Called when the game starts or when spawned
void AMageSkillIndex7::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMageSkillIndex7::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

