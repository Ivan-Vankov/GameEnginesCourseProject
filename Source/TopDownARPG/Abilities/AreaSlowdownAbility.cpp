// Fill out your copyright notice in the Description page of Project Settings.

#include "AreaSlowdownAbility.h"
#include "SlowdownSphere.h"
#include "TopDownARPG.h"
#include "Engine/World.h"

void UAreaSlowdownAbility::Activate(AActor* Source)
{
	Super::Activate(Source);

	UWorld* World = GetWorld();
	if (IsValid(World) == false)
	{
		UE_LOG(LogTopDownARPG, Error, TEXT("UAreaSlowdownAbility::Activate IsValid(World) == false"));
	}

	FActorSpawnParameters SpawnParameters;
	SpawnParameters.Owner = Source;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	FVector SpawnLocation = Source->GetActorLocation() + Source->GetActorForwardVector() * 500.0f;
	SpawnLocation.Z -= 200;

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