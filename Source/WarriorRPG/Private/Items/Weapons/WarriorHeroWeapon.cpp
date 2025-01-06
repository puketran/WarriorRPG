// Fill out your copyright notice in the Description page of Project Settings.

#include "Items/Weapons/WarriorHeroWeapon.h"

void AWarriorHeroWeapon::AssignGrantedAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle> &InGrantedAbilitySpecHandles)
{
    GrantedAbilitySpecHandles = InGrantedAbilitySpecHandles;
}

TArray<FGameplayAbilitySpecHandle> AWarriorHeroWeapon::GetGrantedAbilitySpecHandles() const
{
    return GrantedAbilitySpecHandles;
}