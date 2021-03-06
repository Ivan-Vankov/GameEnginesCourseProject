#pragma once

#include "CoreMinimal.h"
#include "Abilities/Ability.h"
#include "BoltAbility.generated.h"

UCLASS()
class TOPDOWNARPG_API UBoltAbility : public UAbility
{
	GENERATED_BODY()

public:
	virtual void Activate(AActor* Source) override;

private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AProjectile> ProjectileClass;
};
