// Fill out your copyright notice in the Description page of Project Settings.


#include "GreatSwordIndex7Skill.h"

#include "Particles/ParticleSystemComponent.h"

// Sets default values
AGreatSwordIndex7Skill::AGreatSwordIndex7Skill()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("HitArea"));
	BoxComponent->SetupAttachment(GetRootComponent());

	ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("SkillVfx"));
	ParticleSystemComponent->SetupAttachment(BoxComponent->GetAttachmentRoot());

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComponent->SetupAttachment(BoxComponent->GetAttachmentRoot());
	

}

// Called when the game starts or when spawned
void AGreatSwordIndex7Skill::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGreatSwordIndex7Skill::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

