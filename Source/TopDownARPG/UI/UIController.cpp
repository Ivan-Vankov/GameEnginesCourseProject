// Fill out your copyright notice in the Description page of Project Settings.


#include "UIController.h"
#include "Engine/PostProcessVolume.h"
#include "Materials/Material.h"

// Sets default values
AUIController::AUIController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!IsValid(PostProcessVolume))
	{
		//UE_LOG(LogTopDownARPG, Error, TEXT("AUIController::AUIController() !IsValid(PostProcessVolume)"));
		return;
	}

	if (!IsValid(VCRMaterial))
	{
		//UE_LOG(LogTopDownARPG, Error, TEXT("AUIController::AUIController() !IsValid(&VCRMaterial)"));
		return;
	}

	PostProcessVolume->AddOrUpdateBlendable(VCRMaterial, 0);
}

// Called when the game starts or when spawned
void AUIController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

