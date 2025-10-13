// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetMesh());
	CameraBoom->TargetArmLength = 600.f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom,USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	HealthWidgetComp = CreateDefaultSubobject<UWidgetComponent>(TEXT("HealthBar"));
	HealthWidgetComp->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform);
	
	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	
}




void APlayerCharacter::LeftMouseButtonPressed(int SkillIndex,float MageStaminaCost,float FighterStaminaCost)
{
	if(SetAttackChoise == 1) 
	{
		if(SkillIndex == 0) 
		{
			SpawnSkillLoc = GetMesh()->GetSocketLocation("hand_l");
			SpawnSkillRot = FollowCamera->GetComponentRotation();
		}
		else if(SkillIndex == 1)
		{
			SpawnSkillLoc = GetMesh()->GetSocketLocation("R_Hand_Weapon");
			SpawnSkillRot = FollowCamera->GetComponentRotation();
		}
		else if(SkillIndex == 3)
		{
			SpawnSkillLoc = (GetActorForwardVector()* 1600.f) + GetActorLocation();
			SpawnSkillRot = FRotator::ZeroRotator;
		}
		else if(SkillIndex == 4)
		{
			SpawnSkillLoc = GetActorLocation();
			SpawnSkillRot = FRotator::ZeroRotator;
		}
		else if(SkillIndex == 5)
		{
			SpawnSkillLoc = GetActorLocation();
			SpawnSkillRot = FRotator::ZeroRotator;
		}
		else if(SkillIndex == 6)
		{
			SpawnSkillLoc = GetActorLocation();
			SpawnSkillRot = FRotator::ZeroRotator;
		}
		else if(SkillIndex == 7)
		{
			SpawnSkillLoc = (GetActorForwardVector()* 80.f) + GetActorLocation();
			SpawnSkillRot = FollowCamera->GetComponentRotation();
		}
		SpawnPrimaryOnServer(MageSkills[SkillIndex],SpawnSkillLoc,SpawnSkillRot,SkillIndex,MageStaminaCost,FighterStaminaCost);
	}
	else if(SetAttackChoise == 0 ) 
	{
		if(SkillIndex == 0)
		{
			SpawnSkillLoc = (GetActorForwardVector()*60.f) + GetActorLocation();
			SpawnSkillRot = GetActorRotation();
		}
		else if(SkillIndex == 1)
		{
			SpawnSkillLoc = (GetActorForwardVector()*60.f) + GetActorLocation();
			SpawnSkillRot = GetActorRotation();
		}
		else if(SkillIndex == 2)
		{
			SpawnSkillLoc = (GetActorForwardVector()*250.f) + GetActorLocation();
			SpawnSkillRot = GetActorRotation();
		}
		else if(SkillIndex == 3)
		{
			SpawnSkillLoc = GetActorLocation();
			SpawnSkillRot = GetActorRotation();
		}
		else if(SkillIndex == 4)
		{
			SpawnSkillLoc = GetActorLocation();
			SpawnSkillRot = GetActorRotation();
		}
		else if(SkillIndex == 5)
		{
			SpawnSkillLoc = (GetActorForwardVector()*1300.f) + GetActorLocation();
			SpawnSkillRot = GetActorRotation();
		}
		else if(SkillIndex == 6)
		{
			SpawnSkillLoc = GetMesh()->GetSocketLocation("TrailWeaponEnd");
			SpawnSkillRot = GetActorRotation();
		}
		else if(SkillIndex == 7)
		{
			SpawnSkillLoc = GetMesh()->GetSocketLocation("TrailWeaponEnd");
			SpawnSkillRot = GetActorRotation();
		}
		SpawnPrimaryOnServer(FighterSkills[SkillIndex],SpawnSkillLoc,SpawnSkillRot,SkillIndex,MageStaminaCost,FighterStaminaCost);
	}
}

void APlayerCharacter::SpawnPrimaryOnServer_Implementation(TSubclassOf<AActor> ActorRef, FVector SpawnLoc,
	FRotator SpawnRot,int SkillIndex,float MageStaminaCost,float FighterStaminaCost)
{
	SpawnPrimaryOnClient(ActorRef,SpawnLoc,SpawnRot,SkillIndex,MageStaminaCost,FighterStaminaCost);
}


void APlayerCharacter::SpawnPrimaryOnClient_Implementation(TSubclassOf<AActor> ActorRef, FVector SpawnLoc,
	FRotator SpawnRot,int SkillIndex,float MageStaminaCost,float FighterStaminaCost)
{
	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	if(SetAttackChoise == 1)
	{
		
		AActor* SpawnlananAc =	GetWorld()->SpawnActor<AActor>(MageSkills[SkillIndex],SpawnLoc,SpawnRot,Params);
	}
	else if(SetAttackChoise == 0)
	{
		
		AActor* SpawnlananAc =	GetWorld()->SpawnActor<AActor>(FighterSkills[SkillIndex],SpawnLoc,SpawnRot,Params);
		if(SkillIndex == 7)
		{
			SpawnlananAc->AttachToComponent(GetMesh(),FAttachmentTransformRules::SnapToTargetIncludingScale,"HeavySword");
		}
	}
}


void APlayerCharacter::PlaySkillMontageServer_Implementation(int AnimIndex, float SetMageSkillDelay,float SetFighterSkillDelay,float MageStaminaCost,float FighterStaminaCost)
{
	if(SetAttackChoise == 1)
	{
		PlaySkillMontageMulti(AnimIndex,SetMageSkillDelay,0.f,MageStaminaCost,0.f);
	}
	else if(SetAttackChoise == 0)
	{
		PlaySkillMontageMulti(AnimIndex,0.f,SetFighterSkillDelay,0.f,FighterStaminaCost);
	}
	
}

void APlayerCharacter::PlaySkillMontageMulti_Implementation(int AnimIndex, float SetMageSkillDelay,float SetFighterSkillDelay,float MageStaminaCost,float FighterStaminaCost)
{
	if(SetAttackChoise == 1 )
	{
		SkillDelay = SetMageSkillDelay;
		CurrentStamina-= MageStaminaCost;
		StaminaUpdateServer(CurrentStamina,MaxStamina);
		if(AnimIndex != 7)
		{
			M_AttackMage[AnimIndex]->RateScale = 1.2f;
		}
		else if(AnimIndex == 7)
		{
			M_AttackMage[AnimIndex]->RateScale = 0.8f;
		}
		
		PlayAnimMontage(M_AttackMage[AnimIndex]);
	}
	else if(SetAttackChoise == 0 )
	{
		SkillDelay = SetFighterSkillDelay;
		CurrentStamina-= FighterStaminaCost;
		StaminaUpdateServer(CurrentStamina,MaxStamina);
		if(AnimIndex != 7)
		{
			M_AttackFighter[AnimIndex]->RateScale = 1.2f;
		}
		else if(AnimIndex == 7)
		{
			M_AttackFighter[AnimIndex]->RateScale = 0.6f;
		}
		PlayAnimMontage(M_AttackFighter[AnimIndex]);
	}
}

void APlayerCharacter::MageTpServer_Implementation(FVector SpawnLoc, FRotator SpawnRot)
{
	MageTpMulticast(SpawnLoc,SpawnRot);
}

void APlayerCharacter::MageTpMulticast_Implementation(FVector SpawnLoc, FRotator SpawnRot)
{
	CurrentStamina -= 100.f;
	StaminaUpdateServer(CurrentStamina,MaxStamina);
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),ParticleSystems[0],SpawnLoc,SpawnRot,FVector(2.2f));
	SetActorLocation(SpawnLoc);
	SetActorRotation(SpawnRot);
}

void APlayerCharacter::CastMageTp(FVector SpawnLoc, FRotator SpawnRot)
{
	MageTpServer(SpawnLoc,SpawnRot);
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	WidgetRef =	Cast<UPlayerHpUI>(HealthWidgetComp->GetUserWidgetObject());
	if(WidgetRef)
	{
		WidgetRef->SetStartHp(CurrentHp,MaxHp,CurrentStamina,MaxStamina);
	}
	SkillChoicer = 0;
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(CurrentStamina < MaxStamina)
	{
		CurrentStamina += 14 * DeltaTime;
		StaminaUpdateServer(CurrentStamina,MaxStamina);
	}

}



void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump",IE_Pressed,this,&ACharacter::Jump);
	
	PlayerInputComponent->BindAction("EquipWeapon",IE_Pressed,this,&APlayerCharacter::EquipToServer);
	PlayerInputComponent->BindAction("Evade",IE_Pressed,this,&APlayerCharacter::EvadeServer);
	
	
	PlayerInputComponent->BindAction("WPress",IE_Pressed,this,&APlayerCharacter::WPressedServer);
	PlayerInputComponent->BindAction("WPress",IE_Released,this,&APlayerCharacter::WUnPressedFNCServer);
	PlayerInputComponent->BindAction("SPress",IE_Pressed,this,&APlayerCharacter::SPressedFNCServer);
	PlayerInputComponent->BindAction("SPress",IE_Released,this,&APlayerCharacter::SUnPressedFNCServer);
	PlayerInputComponent->BindAction("APress",IE_Pressed,this,&APlayerCharacter::APressedFNCServer);
	PlayerInputComponent->BindAction("APress",IE_Released,this,&APlayerCharacter::AUnPressedFNCServer);
	PlayerInputComponent->BindAction("DPress",IE_Pressed,this,&APlayerCharacter::DPressedFNCServer);
	PlayerInputComponent->BindAction("DPress",IE_Released,this,&APlayerCharacter::DUnPressedFNCServer);

	
	PlayerInputComponent->BindAxis("MoveForward",this,&APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight",this,&APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn",this,&APlayerCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp",this,&APlayerCharacter::LookUp);

	bReplicates = true;
	
}

void APlayerCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APlayerCharacter,WeaponEquip)
	DOREPLIFETIME(APlayerCharacter,IsAttacking)
	DOREPLIFETIME(APlayerCharacter,WPressed)
	DOREPLIFETIME(APlayerCharacter,SPressed)
	DOREPLIFETIME(APlayerCharacter,APressed)
	DOREPLIFETIME(APlayerCharacter,DPressed)
	DOREPLIFETIME(APlayerCharacter,M_EvadeAnimFighter)
	DOREPLIFETIME(APlayerCharacter,M_AttackFighter)
	DOREPLIFETIME(APlayerCharacter,M_EquipWeaponFighter)
	DOREPLIFETIME(APlayerCharacter,M_EvadeAnimMage)
	DOREPLIFETIME(APlayerCharacter,M_AttackMage)
	DOREPLIFETIME(APlayerCharacter,M_EquipWeaponMage)
	DOREPLIFETIME(APlayerCharacter,SetAttackChoise)
	DOREPLIFETIME(APlayerCharacter,SkillDelay)
}

void APlayerCharacter::EquipToServer_Implementation()
{
	Equip();
}

void APlayerCharacter::Equip_Implementation()
{
	if(WeaponEquip == false)
	{
		if(SetAttackChoise == 0)
		{
			PlayAnimMontage(M_EquipWeaponFighter[0]);
		}
		else if(SetAttackChoise == 1)
		{
			PlayAnimMontage(M_EquipWeaponMage[0]);
		}
		WeaponEquip = true;
		GetCharacterMovement()->bUseControllerDesiredRotation = true;
		GetCharacterMovement()->bOrientRotationToMovement = false;
	}
	else
	{
		if(SetAttackChoise == 0)
		{
			PlayAnimMontage(M_EquipWeaponFighter[1]);
		}
		else if(SetAttackChoise == 1)
		{
			PlayAnimMontage(M_EquipWeaponMage[1]);
		}
		WeaponEquip = false;
		GetCharacterMovement()->bUseControllerDesiredRotation = false;
		GetCharacterMovement()->bOrientRotationToMovement = true;
	}
}


void APlayerCharacter::MoveForward(float Value)
{
	if(Controller != nullptr && Value != 0.f)
	{
		const FRotator YawRotation(0.f,Controller->GetControlRotation().Yaw,0.f);
		const FVector Direction( FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X));
		AddMovementInput(Direction,Value);
	}
}

void APlayerCharacter::MoveRight(float Value)
{
	if(Controller != nullptr && Value != 0.f)
	{
		const FRotator YawRotation(0.f,Controller->GetControlRotation().Yaw,0.f);
		const FVector Direction( FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y));
		AddMovementInput(Direction,Value);
	}
}

void APlayerCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void APlayerCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}



void APlayerCharacter::SetNewMageDataServer_Implementation()
{
	SetNewMageData();
}

void APlayerCharacter::SetNewMageData_Implementation()
{
	CurrentHp = 400.f;
	MaxHp = 400.f;
	CurrentStamina = 80.f;
	MaxStamina = 80.f;
	WidgetRef->SetMageDataUI(400.f,400.f,80.f,80.f,"Mage");
}


void APlayerCharacter::EvadeServer_Implementation()
{
	if(CurrentStamina >= 40.f && WeaponEquip == true)
	{
		CurrentStamina -= 40.f;
		StaminaUpdateServer(CurrentStamina,MaxStamina);
		EvadeMulti();
	}
}

void APlayerCharacter::EvadeMulti_Implementation()
{
	if(WPressed == true)
	{
		if(SetAttackChoise == 0)
		{
			PlayAnimMontage(M_EvadeAnimFighter[0]);
		}
		else if(SetAttackChoise == 1)
		{
			PlayAnimMontage(M_EvadeAnimMage[0]);
		}
	}
	else if(SPressed == true)
	{
		if(SetAttackChoise == 0)
		{
			PlayAnimMontage(M_EvadeAnimFighter[1]);
		}
		else if(SetAttackChoise == 1)
		{
			PlayAnimMontage(M_EvadeAnimMage[1]);
		}
	}
	else if(APressed == true)
	{
		if(SetAttackChoise == 0)
		{
			PlayAnimMontage(M_EvadeAnimFighter[2]);
		}
		else if(SetAttackChoise == 1)
		{
			PlayAnimMontage(M_EvadeAnimMage[2]);
		}
	}
	else if(DPressed == true)
	{
		if(SetAttackChoise == 0)
		{
			PlayAnimMontage(M_EvadeAnimFighter[3]);
		}
		else if(SetAttackChoise == 1)
		{
			PlayAnimMontage(M_EvadeAnimMage[3]);
		}
	}
	else
	{
		if(SetAttackChoise == 0)
		{
			PlayAnimMontage(M_EvadeAnimFighter[1]);
		}
		else if(SetAttackChoise == 1)
		{
			PlayAnimMontage(M_EvadeAnimMage[1]);
		}
	}
}

void APlayerCharacter::StaminaUpdateServer_Implementation(float StaminaParam, float MaxStaminaParam)
{
	StaminaUpdateMulti(CurrentStamina,MaxStamina);
}

void APlayerCharacter::StaminaUpdateMulti_Implementation(float StaminaParam, float MaxStaminaParam)
{
	WidgetRef->UpdateStamina(StaminaParam,MaxStaminaParam);
}

void APlayerCharacter::WPressedFNC_Implementation()
{
	WPressed = true;
}

void APlayerCharacter::WPressedServer_Implementation()
{
	WPressedFNC();
}

void APlayerCharacter::WUnPressedFNC_Implementation()
{
	WPressed = false;
}

void APlayerCharacter::WUnPressedFNCServer_Implementation()
{
	WUnPressedFNC();
}

void APlayerCharacter::SPressedFNC_Implementation()
{
	SPressed = true;
}

void APlayerCharacter::SPressedFNCServer_Implementation()
{
	SPressedFNC();
}

void APlayerCharacter::SUnPressedFNC_Implementation()
{
	SPressed = false;
}

void APlayerCharacter::SUnPressedFNCServer_Implementation()
{
	SUnPressedFNC();
}

void APlayerCharacter::APressedFNC_Implementation()
{
	APressed = true;
}

void APlayerCharacter::APressedFNCServer_Implementation()
{
	APressedFNC();
}

void APlayerCharacter::AUnPressedFNC_Implementation()
{
	APressed = false;
}

void APlayerCharacter::AUnPressedFNCServer_Implementation()
{
	AUnPressedFNC();
}

void APlayerCharacter::DPressedFNC_Implementation()
{
	DPressed = true;
}

void APlayerCharacter::DPressedFNCServer_Implementation()
{
	DPressedFNC();
}

void APlayerCharacter::DUnPressedFNC_Implementation()
{
	DPressed = false;
}

void APlayerCharacter::DUnPressedFNCServer_Implementation()
{
	DUnPressedFNC();
}





