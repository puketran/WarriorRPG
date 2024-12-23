// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "Components/Combat/PawnCombatComponent.h"

void UWarriorGameplayAbility::OnGiveAbility(const FGameplayAbilityActorInfo *ActorInfo, const FGameplayAbilitySpec &Spec)
{
    Super::OnGiveAbility(ActorInfo, Spec);
    UE_LOG(LogTemp, Warning, TEXT("UWarriorGameplayAbility::OnGiveAbility2222"));

    if (AbilityActivationPolicy == EWarriorAbilityActivationPolicy::OnGiven)
    {
        UE_LOG(LogTemp, Warning, TEXT("AbilityActivationPolicy OnGiven"));
        if (ActorInfo && !Spec.IsActive())
        {
            UE_LOG(LogTemp, Warning, TEXT("TryActivateAbility"));
            ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle);
        }
        else if (!ActorInfo)
        {
            UE_LOG(LogTemp, Warning, TEXT("AbilityActivationPolicy OnGiven ActorInfo is nullptr"));
        }
        else if (Spec.IsActive())
        {
            UE_LOG(LogTemp, Warning, TEXT("AbilityActivationPolicy OnGiven Spec is not active"));
        }
    }
}

void UWarriorGameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo *ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
    Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
    UE_LOG(LogTemp, Warning, TEXT("UWarriorGameplayAbility::EndAbility"));

    if (AbilityActivationPolicy == EWarriorAbilityActivationPolicy::OnGiven)
    {
        if (ActorInfo)
        {
            ActorInfo->AbilitySystemComponent->ClearAbility(Handle);
        }
    }
}

UPawnCombatComponent *UWarriorGameplayAbility::GetPawnCombatComponentFromActorInfo() const
{
    return GetAvatarActorFromActorInfo()->FindComponentByClass<UPawnCombatComponent>();
}

UWarriorAbilitySystemComponent *UWarriorGameplayAbility::GetWarriorAbilitySystemComponentFromActorInfo() const
{
    return Cast<UWarriorAbilitySystemComponent>(CurrentActorInfo->AbilitySystemComponent);
}