#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ZombieHUD.generated.h"

UCLASS()
class ZOMBIEAPOCALYPSE_API AZombieHUD : public AHUD
{
    GENERATED_BODY()

public:
    virtual void DrawHUD() override;

protected:
    UPROPERTY(EditDefaultsOnly, Category = "UI")
    UTexture2D* CrosshairTex;
};
