// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "PlayerHpUI.generated.h"


UCLASS()
class MULTIGAME_API UPlayerHpUI : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativePreConstruct() override;
	
	UPROPERTY(meta=(BindWidget),BlueprintReadWrite)
	UProgressBar* HealthBar;
	UPROPERTY(meta=(BindWidget),BlueprintReadWrite)
	UProgressBar* StaminaBar;
	UPROPERTY(meta=(BindWidget),BlueprintReadWrite)
	UTextBlock* CurrentHealthLabel;
	UPROPERTY(meta=(BindWidget),BlueprintReadWrite)
	UTextBlock* PlayerName;

	UFUNCTION(BlueprintCallable)
	void UpdateHp(float Health,float MaxHealth);

	UFUNCTION(BlueprintCallable)
	void SetStartHp(float Health,float MaxHealth, float Stamina, float StaminaMax);

	UFUNCTION(BlueprintCallable)
	void UpdateStamina(float CurrentStamina, float MaxStamina);

	UFUNCTION(BlueprintCallable)
	void SetMageDataUI(float Hp,float MaxHp,float CurrentStamina,float MaxStamina, FString string);
	
	
};
