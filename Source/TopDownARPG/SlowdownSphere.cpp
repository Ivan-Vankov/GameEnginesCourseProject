// Fill out your copyright notice in the Description page of Project Settings.


#include "SlowdownSphere.h"
#include "Projectiles/Projectile.h"
#include "TopDownARPGCharacter.h"
#include "Components/SphereComponent.h"
#include "TopDownARPG.h"
#include "GameFramework/MovementComponent.h"

ASlowdownSphere::ASlowdownSphere()
{
 	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	//SetLifeSpan(5);

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	SphereComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	SphereComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_PhysicsBody, ECollisionResponse::ECR_Overlap);
	SphereComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Destructible, ECollisionResponse::ECR_Overlap);

	RootComponent = SphereComponent;

	SphereComponent->OnComponentBeginOverlap.AddUniqueDynamic(this, &ASlowdownSphere::OnBeginOverlap);
	SphereComponent->OnComponentEndOverlap.AddUniqueDynamic(this, &ASlowdownSphere::OnEndOverlap);
}

// Called when the game starts or when spawned
void ASlowdownSphere::BeginPlay()
{
	Super::BeginPlay();
}

void ASlowdownSphere::OnBeginOverlap(UPrimitiveComponent * OverlappedComp, AActor * Other, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{

	UE_LOG(LogTopDownARPG, Log, TEXT("In ASlowdownSphere::OnBeginOverlap"));
	if (IsValid(Other)) {
		Other->CustomTimeDilation /= SlowdownAmount;
	}

	//ATopDownARPGCharacter* Character = Cast<ATopDownARPGCharacter>(Other);
	//if (IsValid(Character))
	//{
	//	UE_LOG(LogTopDownARPG, Log, TEXT("Entered Slowdown Sphere"));
	//	Character->CustomTimeDilation /= SlowdownAmount;
	//	UE_LOG(LogTopDownARPG, Log, TEXT("CustomTimeDilation is %f"), Character->CustomTimeDilation);
	//	//DoSlowdown(Character);
	//	//Character->SetTimeDilation(0.5);
	//	return;
	//}

	//AProjectile* Projectile = Cast<AProjectile>(Other);
	//if (IsValid(Projectile))
	//{
	//	UE_LOG(LogTopDownARPG, Log, TEXT("Entered Slowdown Sphere"));
	//	Character->CustomTimeDilation /= SlowdownAmount;
	//	//Projectile->SetTimeDilation(0.5);
	//	return;
	//}
}

void ASlowdownSphere::OnEndOverlap(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	if (IsValid(OtherActor)) {
		OtherActor->CustomTimeDilation = 1;
	}
	//ATopDownARPGCharacter* Character = Cast<ATopDownARPGCharacter>(OtherActor);
	//if (IsValid(Character))
	//{
	//	UE_LOG(LogTopDownARPG, Log, TEXT("Exited Slowdown Sphere"));
	//	//Character->SetTimeDilation(1);
	//	return;
	//}

	//AProjectile* Projectile = Cast<AProjectile>(OtherActor);
	//if (IsValid(Projectile))
	//{
	//	UE_LOG(LogTopDownARPG, Log, TEXT("Exited Slowdown Sphere"));
	//	//Projectile->SetTimeDilation(1);
	//	return;
	//}
}

//void ASlowdownSphere::DoSlowdown(AActor * actor)
//{
//	UMovementComponent * MovementComponent = Cast<UMovementComponent>(
//		actor->GetComponentByClass(UMovementComponent::StaticClass()));
//
//	if (IsValid(MovementComponent)) {
//		MovementComponent->Velocity *= 0.5;
//	}
//}

void ASlowdownSphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

