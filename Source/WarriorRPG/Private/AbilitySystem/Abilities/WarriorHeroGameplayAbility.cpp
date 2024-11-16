// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilitySystem/Abilities/WarriorHeroGameplayAbility.h"
#include "Characters/WarriorHeroCharacter.h"
#include "Controllers/WarriorHeroController.h"
#include "Components/Combat/HeroCombatComponent.h"

AWarriorHeroCharacter *UWarriorHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
    if (!CatchedWarriorHeroCharacter.IsValid())
    {
        CatchedWarriorHeroCharacter = Cast<AWarriorHeroCharacter>(CurrentActorInfo->AvatarActor);
    }
    return CatchedWarriorHeroCharacter.IsValid() ? CatchedWarriorHeroCharacter.Get() : nullptr;
}

AWarriorHeroController *UWarriorHeroGameplayAbility::GetHeroControllerFromActorInfo()
{
    if (!CatchedWarriorHeroController.IsValid())
    {
        CatchedWarriorHeroController = Cast<AWarriorHeroController>(CurrentActorInfo->PlayerController);
    }
    return CatchedWarriorHeroController.IsValid() ? CatchedWarriorHeroController.Get() : nullptr;
}

UHeroCombatComponent *UWarriorHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
    return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}