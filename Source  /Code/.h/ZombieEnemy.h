#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ZombieEnemy.generated.h"

UCLASS()
class ZOMBIEAPOCALYPSE_API AZombieEnemy : public ACharacter
{
    GENERATED_BODY()

public:
    AZombieEnemy();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, Category = "Combat")
    float Damage = 10.0f;

    UPROPERTY(EditAnywhere, Category = "Stats")
    float Health = 50.0f;

    UFUNCTION()
    void OnOverlap(AActor* OverlappedActor, AActor* OtherActor);

public:
    virtual void Tick(float DeltaTime) override;
    void TakeDamage(float Amount);
};
