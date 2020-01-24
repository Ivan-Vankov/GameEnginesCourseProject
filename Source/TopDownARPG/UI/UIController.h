// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UIController.generated.h"

UCLASS()
class TOPDOWNARPG_API AUIController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUIController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class APostProcessVolume* PostProcessVolume;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UMaterial* VCRMaterial;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
