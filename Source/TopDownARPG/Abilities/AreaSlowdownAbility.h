#pragma once

#include "CoreMinimal.h"
#include "Abilities/Ability.h"
#include "AreaSlowdownAbility.generated.h"

UCLASS()
class TOPDOWNARPG_API UAreaSlowdownAbility : public UAbility
{
	GENERATED_BODY()
	
public:
	virtual void Activate(AActor* Source) override;

private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class ASlowdownSphere> SlowdownSphereClass;
};
