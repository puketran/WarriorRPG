// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilitySystem/WarriorAbilitySystemComponent.h"

void UWarriorAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag &InInputTag)
{
    if (!InInputTag.IsValid())
    {
        return;
    }
    UE_LOG(LogTemp, Log, TEXT("Input_AbilityInputPressed: %s"), *InInputTag.ToString());

    for (const FGameplayAbilitySpec &AbilitySpec : GetActivatableAbilities())
    {
        if (!AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag))
            continue;
        TryActivateAbility(AbilitySpec.Handle);
    }
}

void UWarriorAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag &InInputTag)
{
}