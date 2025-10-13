// Fill out your copyright notice in the Description page of Project Settings.


#include "MageAnimInstance.h"
#include "PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UMageAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	PlayerCharacter = Cast<APlayerCharacter>(TryGetPawnOwner());
}

void UMageAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if(PlayerCharacter == nullptr)
	{
		PlayerCharacter = Cast<APlayerCharacter>(TryGetPawnOwner());
	}
	if(PlayerCharacter == nullptr) return;

	FVector Velocity = PlayerCharacter->GetVelocity();
	Velocity.Z = 0.f;
	Speed = Velocity.Size();

	Direction = CalculateDirection(TryGetPawnOwner()->GetVelocity(),TryGetPawnOwner()->GetActorRotation());
	bIsInAir = PlayerCharacter->GetCharacterMovement()->IsFalling();
	bIsAccelerating = PlayerCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f ? true : false;
	WeaponEquipped = PlayerCharacter->WeaponEquip;
	
}

void UMageAnimInstance::ResetDoOnce()
{
	DoOnceVariable = false;
}

void UMageAnimInstance::CastPrimaryAttack()
{
	FVector SpawnLoc = PlayerCharacter->GetMesh()->GetSocketLocation("hand_r");
	FRotator SpawnRot = PlayerCharacter->FollowCamera->GetComponentRotation();
	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn; 
	AActor* SpawnlananAc =	GetWorld()->SpawnActor<AActor>(SkillsActor[0],SpawnLoc,SpawnRot,Params);
	GetWorld()->GetTimerManager().SetTimer(ResetDoOnceTimer,this,&UMageAnimInstance::ResetDoOnce,0.5f,false);
}
