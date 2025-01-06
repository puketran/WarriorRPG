// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NativeGameplayTags.h"

namespace WarriorGameplayTags
{
	/** Input Tags */
	WARRIORRPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move);
	WARRIORRPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look);
	WARRIORRPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_EquipAxe);
	WARRIORRPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_UnequipAxe);

	/** Player tags */
	WARRIORRPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Axe);

	/** Ability tags */
	WARRIORRPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Equip_Axe);
	WARRIORRPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Unequip_Axe);

	WARRIORRPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Equip_Axe);
	WARRIORRPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Unequip_Axe);
}
