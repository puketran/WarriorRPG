// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"
#include "WarriorHeroGameplayAbility.generated.h"

class AWarriorHeroCharacter;
class AWarriorHeroController;
class UHeroCombatComponent;
/**
 *
 */
UCLASS()
class WARRIORRPG_API UWarriorHeroGameplayAbility : public UWarriorGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	AWarriorHeroCharacter *GetHeroCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	AWarriorHeroController *GetHeroControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	UHeroCombatComponent *GetHeroCombatComponentFromActorInfo();

private:
	TWeakObjectPtr<AWarriorHeroCharacter> CatchedWarriorHeroCharacter;

	TWeakObjectPtr<AWarriorHeroController> CatchedWarriorHeroController;
	TWeakObjectPtr<UHeroCombatComponent> CatchedHeroCombatComponent;
};
