// Fill out your copyright notice in the Description page of Project Settings.

#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent *InASCToGive, int32 ApplyLevel)
{
    check(InASCToGive);

    GrantAbilities(ActivateOnGivenAbilities, InASCToGive, ApplyLevel);
    GrantAbilities(ReactiveAbilities, InASCToGive, ApplyLevel);
    UE_LOG(LogTemp, Warning, TEXT("UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent"));
}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<UWarriorGameplayAbility>> &InAbilitiesToGive, UWarriorAbilitySystemComponent *InASCToGive, int32 ApplyLevel)
{
    if (InAbilitiesToGive.IsEmpty())
    {
        return;
    }

    for (const TSubclassOf<UWarriorGameplayAbility> &Ability : InAbilitiesToGive)
    {
        if (Ability)
        {
            FGameplayAbilitySpec AbilitySpec(Ability);
            AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
            AbilitySpec.Level = ApplyLevel;
            InASCToGive->GiveAbility(AbilitySpec);
            UE_LOG(LogTemp, Warning, TEXT("UDataAsset_StartUpDataBase::GrantAbilities"));
        }
    }
}