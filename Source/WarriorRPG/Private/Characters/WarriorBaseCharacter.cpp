// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/WarriorBaseCharacter.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/WarriorAttributeSet.h"
#include "WarriorDebugHelper.h"

// Sets default values
AWarriorBaseCharacter::AWarriorBaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;
	GetMesh()->bReceivesDecals = false;

	WarriorAbilitySystemComponent = CreateDefaultSubobject<UWarriorAbilitySystemComponent>(TEXT("WarriorAbilitySystemComponent"));
	WarriorAttributeSet = CreateDefaultSubobject<UWarriorAttributeSet>(TEXT("WarriorAttributeSet"));

	// if (WarriorAbilitySystemComponent)
	// 	// Debug::Print("WarriorAbilitySystemComponent!", FColor::Green, 3);
	// 	UE_LOG(LogTemp, Warning, TEXT("WarriorAbilitySystemComponent!"));

	// if (WarriorAttributeSet)
	// 	// Debug::Print("WarriorAttributeSet!", FColor::Green, 3);
	// 	UE_LOG(LogTemp, Warning, TEXT("WarriorAttributeSet!"));
}

void AWarriorBaseCharacter::PossessedBy(AController *NewController)
{
	Super::PossessedBy(NewController);

	if (WarriorAbilitySystemComponent)
	{
		WarriorAbilitySystemComponent->InitAbilityActorInfo(this, this);

		ensureMsgf(!CharacterStartUpData.IsNull(), TEXT("Forgot to assign start up data to %s"), *GetName());
	}
}

UAbilitySystemComponent *AWarriorBaseCharacter::GetAbilitySystemComponent() const
{
	return GetWarriorAbilitySystemComponent();
}
