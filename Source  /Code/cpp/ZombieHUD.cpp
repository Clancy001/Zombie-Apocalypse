#include "ZombieHUD.h"
#include "Engine/Canvas.h"
#include "UObject/ConstructorHelpers.h"

void AZombieHUD::DrawHUD()
{
    Super::DrawHUD();

    if (CrosshairTex)
    {
        FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);
        FVector2D CrosshairDrawPosition(Center.X - 8.0f, Center.Y - 8.0f);

        FCanvasTileItem TileItem(CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
        TileItem.BlendMode = SE_BLEND_Translucent;
        Canvas->DrawItem(TileItem);
    }
}
