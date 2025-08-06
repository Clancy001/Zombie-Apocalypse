#include "ZombieSpawner.h"
#include "ZombieEnemy.h"
#include "Kismet/GameplayStatics.h"

AZombieSpawner::AZombieSpawner()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AZombieSpawner::BeginPlay()
{
    Super::BeginPlay();
    SpawnWave();
}

void AZombieSpawner::SpawnWave()
{
    for (int32 i = 0; i < EnemiesToSpawn; i++)
    {
        FVector SpawnLocation = GetActorLocation() + FVector(FMath::RandRange(-500, 500), FMath::RandRange(-500, 500), 0);
        GetWorld()->SpawnActor<AZombieEnemy>(ZombieClass, SpawnLocation, FRotator::ZeroRotator);
    }
}
