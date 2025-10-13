// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHpUI.h"


void UPlayerHpUI::NativePreConstruct()
{
	Super::NativePreConstruct();
	PlayerName->SetText(FText::FromString("BaseCharacter"));
}

void UPlayerHpUI::UpdateHp(float Health, float MaxHealth)
{
	HealthBar->SetPercent(Health / MaxHealth);
	CurrentHealthLabel->SetText(FText::AsNumber(Health));
}

void UPlayerHpUI::SetStartHp(float Health, float MaxHealth, float Stamina, float StaminaMax)
{
	HealthBar->SetPercent(Health / MaxHealth);
	StaminaBar->SetPercent(Stamina/StaminaMax);
	CurrentHealthLabel->SetText(FText::AsNumber(Health));
}

void UPlayerHpUI::UpdateStamina(float CurrentStamina, float MaxStamina)
{
	StaminaBar->SetPercent(CurrentStamina/MaxStamina);
}

void UPlayerHpUI::SetMageDataUI(float Hp, float MaxHp, float CurrentStamina, float MaxStamina, FString string)
{
	HealthBar->SetPercent(Hp / MaxHp);
	CurrentHealthLabel->SetText(FText::AsNumber(Hp));
	PlayerName->SetText(FText::FromString(string));
	StaminaBar->SetPercent(CurrentStamina/MaxStamina);
}


