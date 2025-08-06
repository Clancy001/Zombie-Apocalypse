#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ZombieGameMode.generated.h"

UCLASS()
class ZOMBIEAPOCALYPSE_API AZombieGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    AZombieGameMode();

protected:
    virtual void BeginPlay() override;
    void SpawnEnemyWave();

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<class AZombieEnemy> ZombieClass;

    int32 WaveCount = 1;
    int32 EnemiesPerWave = 5;
    FTimerHandle WaveTimer;

public:
    void EnemyKilled();
};
