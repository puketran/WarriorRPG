// Fill out your copyright notice in the Description page of Project Settings.

#include "DataAssets/Input/DataAsset_InputConfig.h"

UInputAction *UDataAsset_InputConfig::FindNativeInputActionByTag(const FGameplayTag &InInputTag) const
{
    for (const FWarriorInputActionConfig &ActionConfig : NativeInputActions)
    {
        if (ActionConfig.InputTag == InInputTag && ActionConfig.InputAction)
        {
            return ActionConfig.InputAction;
        }
    }
    return nullptr;
}