// Fill out your copyright notice in the Description page of Project Settings.


#include "PostProcessVolumeSpawner.h"
#include "Engine/World.h"
#include "TopDownARPG.h"
#include "Engine/PostProcessVolume.h"

// Sets default values
APostProcessVolumeSpawner::APostProcessVolumeSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

APostProcessVolume* APostProcessVolumeSpawner::SpawnPostProcessVolume()
{
    UWorld* World = GetWorld();
    if (!IsValid(World))
    {
        UE_LOG(LogTopDownARPG, Error, TEXT("APostProcessVolumeSpawner::BeginPlay IsValid(World) == false"));
        return nullptr;
    }

    FActorSpawnParameters SpawnParameters;
    SpawnParameters.Owner = this;
    SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

    FVector SpawnLocation = this->GetActorLocation();

    APostProcessVolume* PostProcessVolume = World->SpawnActor<APostProcessVolume>(
        PostProcessVolumeClass,
        SpawnLocation,
        this->GetActorRotation(),
        SpawnParameters);

    if (!IsValid(PostProcessVolume))
    {
        UE_LOG(LogTopDownARPG, Error, TEXT("APostProcessVolumeSpawner::BeginPlay IsValid(PostProcessVolume) == false"));
        return nullptr;
    }

    return PostProcessVolume;
}

// Called when the game starts or when spawned
void APostProcessVolumeSpawner::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APostProcessVolumeSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

