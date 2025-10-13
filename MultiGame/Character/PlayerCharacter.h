// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "MultiGame/Widgets/PlayerHpUI.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class MULTIGAME_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()
	

public:
	
	APlayerCharacter();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void Tick(float DeltaSeconds) override;

	//0-> GreatSword   1->Mage
	UPROPERTY(BlueprintReadWrite,Replicated)
	int SetAttackChoise;
	
	UPROPERTY(VisibleAnywhere)
	UWidgetComponent* HealthWidgetComp;
	UPROPERTY(BlueprintReadWrite)
	UPlayerHpUI* WidgetRef;
	
	UPROPERTY(BlueprintReadWrite,Replicated)
	bool WeaponEquip;
	UPROPERTY(BlueprintReadWrite,Replicated)
	bool IsAttacking;
	UPROPERTY(BlueprintReadWrite,Replicated)
	bool WPressed;
	UPROPERTY(BlueprintReadWrite,Replicated)
	bool SPressed;
	UPROPERTY(BlueprintReadWrite,Replicated)
	bool APressed;
	UPROPERTY(BlueprintReadWrite,Replicated)
	bool DPressed;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Replicated,Category = "EvadeFighter")
	TArray<UAnimMontage*> M_EvadeAnimFighter;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Replicated,Category = "EvadeMage")
	TArray<UAnimMontage*> M_EvadeAnimMage;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Replicated,Category = "AttackFighter")
	TArray<UAnimMontage*> M_AttackFighter;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Replicated,Category = "AttackMage")
	TArray<UAnimMontage*> M_AttackMage;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Replicated,Category = "EquipFighter")
	TArray<UAnimMontage*> M_EquipWeaponFighter;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Replicated,Category = "EquipMage")
	TArray<UAnimMontage*> M_EquipWeaponMage;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Replicated,Category = "MageHit")
	TArray<UAnimMontage*> M_HitMageAnim;
	
	UPROPERTY(BlueprintReadWrite)
	float CurrentHp = 20.f;
	UPROPERTY(BlueprintReadWrite)
	float MaxHp = 300.f;
	UPROPERTY(BlueprintReadWrite)
	float CurrentStamina = 200.f;
	UPROPERTY(BlueprintReadWrite)
	float MaxStamina = 200.f;

	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category = Camera)
	UCameraComponent* FollowCamera;

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<AActor>> MageSkills;
	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<AActor>> FighterSkills;
	
	UPROPERTY(BlueprintReadWrite,Replicated)
	float SkillDelay;
	UFUNCTION(BlueprintCallable)
	void LeftMouseButtonPressed(int SkillIndex,float MageStaminaCost,float FighterStaminaCost);
	UFUNCTION(Reliable,Server)
	void SpawnPrimaryOnServer(TSubclassOf<AActor>ActorRef,FVector SpawnLoc,FRotator SpawnRot,int SkillIndex,float MageStaminaCost,float FighterStaminaCost);
	UFUNCTION(Unreliable,NetMulticast)
	void SpawnPrimaryOnClient(TSubclassOf<AActor>ActorRef,FVector SpawnLoc,FRotator SpawnRot,int SkillIndex,float MageStaminaCost,float FighterStaminaCost);
	UFUNCTION(Reliable,Server,BlueprintCallable)
	void PlaySkillMontageServer(int AnimIndex,float SetMageSkillDelay,float SetFighterSkillDelay,float MageStaminaCost,float FighterStaminaCost);
	UFUNCTION(Unreliable,NetMulticast)
	void PlaySkillMontageMulti(int AnimIndex,float SetMageSkillDelay,float SetFighterSkillDelay,float MageStaminaCost,float FighterStaminaCost);
	UPROPERTY(BlueprintReadWrite)
	int SkillChoicer;

	UFUNCTION(BlueprintCallable)
	void CastMageTp(FVector SpawnLoc,FRotator SpawnRot);
	UFUNCTION(Reliable,Server)
	void MageTpServer(FVector SpawnLoc,FRotator SpawnRot);
	UFUNCTION(Unreliable,NetMulticast)
	void MageTpMulticast(FVector SpawnLoc,FRotator SpawnRot);
	UPROPERTY(EditDefaultsOnly,Category = Vfx)
	TArray<UParticleSystem*> ParticleSystems;
	
	
	
protected:
	virtual void BeginPlay() override;
	
	
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	
	UFUNCTION(Reliable,NetMulticast)
	void Equip();
	UFUNCTION(Reliable,Server)
	void EquipToServer();

	UFUNCTION(Reliable,NetMulticast)
	void EvadeMulti();
	UFUNCTION(Reliable,Server)
	void EvadeServer();
	
private:
	UPROPERTY(VisibleAnywhere, Category = Camera)
	USpringArmComponent* CameraBoom;

	

public:
	//Update Widget Functions
	//--------------------------------------------------------------------------------------------------------------------------------------

	UPROPERTY(BlueprintReadWrite)
	FVector SpawnSkillLoc;
	UPROPERTY(BlueprintReadWrite)
	FRotator SpawnSkillRot;
	
	UFUNCTION(Reliable,NetMulticast)
	void StaminaUpdateMulti(float StaminaParam,float MaxStaminaParam);
	UFUNCTION(Reliable,Server,BlueprintCallable)
	void StaminaUpdateServer(float StaminaParam,float MaxStaminaParam);

	UFUNCTION(Reliable,NetMulticast)
	void SetNewMageData();
	UFUNCTION(Reliable,Server,BlueprintCallable)
	void SetNewMageDataServer();

	//Evades
	UFUNCTION(Reliable,NetMulticast)
	void WPressedFNC();
	UFUNCTION(Reliable,Server)
	void WPressedServer();
	UFUNCTION(Reliable,NetMulticast)
	void WUnPressedFNC();
	UFUNCTION(Reliable,Server)
	void WUnPressedFNCServer();
	
	UFUNCTION(Reliable,NetMulticast)
	void SPressedFNC();
	UFUNCTION(Reliable,Server)
	void SPressedFNCServer();
	UFUNCTION(Reliable,NetMulticast)
	void SUnPressedFNC();
	UFUNCTION(Reliable,Server)
	void SUnPressedFNCServer();
	
	UFUNCTION(Reliable,NetMulticast)
	void APressedFNC();
	UFUNCTION(Reliable,Server)
	void APressedFNCServer();
	UFUNCTION(Reliable,NetMulticast)
	void AUnPressedFNC();
	UFUNCTION(Reliable,Server)
	void AUnPressedFNCServer();

	UFUNCTION(Reliable,NetMulticast)
	void DPressedFNC();
	UFUNCTION(Reliable,Server)
	void DPressedFNCServer();
	UFUNCTION(Reliable,NetMulticast)
	void DUnPressedFNC();
	UFUNCTION(Reliable,Server)
	void DUnPressedFNCServer();
	

};







