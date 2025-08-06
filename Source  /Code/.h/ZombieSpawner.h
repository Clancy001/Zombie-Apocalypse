#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ZombieSpawner.generated.h"

UCLASS()
class ZOMBIEAPOCALYPSE_API AZombieSpawner : public AActor
{
    GENERATED_BODY()

public:
    AZombieSpawner();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<class AZombieEnemy> ZombieClass;

    UPROPERTY(EditAnywhere)
    int32 EnemiesToSpawn = 5;

    void SpawnWave();
};
