#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class ZOMBIEAPOCALYPSE_API AProjectile : public AActor
{
    GENERATED_BODY()
	
public:	
    AProjectile();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere)
    class UProjectileMovementComponent* ProjectileMovement;

    UPROPERTY(VisibleAnywhere)
    class USphereComponent* CollisionComponent;

    UPROPERTY(VisibleAnywhere)
    class UStaticMeshComponent* Mesh;

    UFUNCTION()
    void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
               UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:	
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditDefaultsOnly)
    float Damage = 20.0f;
};
