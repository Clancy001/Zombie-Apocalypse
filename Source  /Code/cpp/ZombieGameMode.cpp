#include "ZombieGameMode.h"
#include "ZombieEnemy.h"
#include "Kismet/GameplayStatics.h"

AZombieGameMode::AZombieGameMode()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AZombieGameMode::BeginPlay()
{
    Super::BeginPlay();
    SpawnEnemyWave();
}

void AZombieGameMode::SpawnEnemyWave()
{
    for (int i = 0; i < EnemiesPerWave * WaveCount; i++)
    {
        FVector SpawnLocation = FVector(FMath::RandRange(-1000, 1000), FMath::RandRange(-1000, 1000), 100);
        GetWorld()->SpawnActor<AZombieEnemy>(ZombieClass, SpawnLocation, FRotator::ZeroRotator);
    }

    WaveCount++;
    GetWorld()->GetTimerManager().SetTimer(WaveTimer, this, &AZombieGameMode::SpawnEnemyWave, 30.0f, false);
}

void AZombieGameMode::EnemyKilled()
{
    // Increase score or trigger new logic here
}
