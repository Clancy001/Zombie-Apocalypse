#include "MainMenuWidget.h"
#include "Kismet/GameplayStatics.h"

void UMainMenuWidget::StartGame()
{
    UGameplayStatics::OpenLevel(this, "GameLevelName"); // Replace with actual level name
}

void UMainMenuWidget::QuitGame()
{
    UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
}
