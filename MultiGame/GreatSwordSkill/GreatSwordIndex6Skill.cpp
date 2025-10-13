// Fill out your copyright notice in the Description page of Project Settings.


#include "GreatSwordIndex6Skill.h"

// Sets default values
AGreatSwordIndex6Skill::AGreatSwordIndex6Skill()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("HitArea"));
	BoxComponent->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void AGreatSwordIndex6Skill::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGreatSwordIndex6Skill::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

