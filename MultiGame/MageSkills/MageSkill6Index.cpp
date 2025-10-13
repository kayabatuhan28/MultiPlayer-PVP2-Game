// Fill out your copyright notice in the Description page of Project Settings.


#include "MageSkill6Index.h"

// Sets default values
AMageSkill6Index::AMageSkill6Index()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("HitArea"));
	SphereComponent->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void AMageSkill6Index::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMageSkill6Index::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

