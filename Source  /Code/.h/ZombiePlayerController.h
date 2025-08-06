#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ZombiePlayerController.generated.h"

UCLASS()
class ZOMBIEAPOCALYPSE_API AZombiePlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;
};
