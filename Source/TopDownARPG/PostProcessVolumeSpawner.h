// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PostProcessVolumeSpawner.generated.h"

UCLASS(Blueprintable)
class TOPDOWNARPG_API APostProcessVolumeSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APostProcessVolumeSpawner();

    UFUNCTION(BlueprintCallable)
    class APostProcessVolume* SpawnPostProcessVolume();

private:
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<class APostProcessVolume> PostProcessVolumeClass;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
