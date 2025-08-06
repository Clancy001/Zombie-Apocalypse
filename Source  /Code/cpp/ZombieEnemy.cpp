#include "ZombieEnemy.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ZombieApocalypseCharacter.h"
#include "Kismet/GameplayStatics.h"

AZombieEnemy::AZombieEnemy()
{
    PrimaryActorTick.bCanEverTick = true;
    OnActorBeginOverlap.AddDynamic(this, &AZombieEnemy::OnOverlap);
}

void AZombieEnemy::BeginPlay()
{
    Super::BeginPlay();
}

void AZombieEnemy::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Follow the player
    ACharacter* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
    if (Player)
    {
        FVector Direction = (Player->GetActorLocation() - GetActorLocation()).GetSafeNormal();
        AddMovementInput(Direction, 1.0f);
    }
}

void AZombieEnemy::TakeDamage(float Amount)
{
    Health -= Amount;
    if (Health <= 0)
    {
        Destroy();
    }
}

void AZombieEnemy::OnOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
    if (OtherActor && OtherActor->IsA(AZombieApocalypseCharacter::StaticClass()))
    {
        AZombieApocalypseCharacter* Player = Cast<AZombieApocalypseCharacter>(OtherActor);
        if (Player)
        {
            // Reduce player's health
            // Example: Player->TakeDamage(Damage);
        }
    }
}
