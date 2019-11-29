// Fill out your copyright notice in the Description page of Project Settings.

#include "AreaSlowdownAbility.h"
#include "SlowdownSphere.h"
#include "TopDownARPG.h"
#include "Engine/World.h"

void UAreaSlowdownAbility::Activate(AActor* Source)
{
	Super::Activate(Source);

	UE_LOG(LogTopDownARPG, Error, TEXT("In UAreaSlowdownAbility::Activate"));

	UWorld* World = GetWorld();
	if (IsValid(World) == false)
	{
		UE_LOG(LogTopDownARPG, Error, TEXT("UAreaSlowdownAbility::Activate IsValid(World) == false"));
	}

	FActorSpawnParameters SpawnParameters;
	SpawnParameters.Owner = Source;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	UE_LOG(LogTopDownARPG, Error, TEXT("UAreaSlowdownAbility::Activate Spawning Slowdown Sphere"));
	FVector SpawnLocation = Source->GetActorLocation() + Source->GetActorForwardVector() * 500.0f;

	AActor* SlowdownSphere = World->SpawnActor<AActor>(
		SlowdownSphereClass, 
		SpawnLocation, 
		Source->GetActorRotation(), 
		SpawnParameters);

	if (IsValid(SlowdownSphere) == false)
	{
		UE_LOG(LogTopDownARPG, Error, TEXT("UAreaSlowdownAbility::Activate IsValid(Projectile) == false"));
		return;
	}
}