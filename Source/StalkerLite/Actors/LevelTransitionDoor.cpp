#include "LevelTransitionDoor.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SceneComponent.h"
#include "../Core/MyGameInstance.h"

ALevelTransitionDoor::ALevelTransitionDoor()
{
    PrimaryActorTick.bCanEverTick = false;

    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

    ExitPoint = CreateDefaultSubobject<USceneComponent>(TEXT("ExitPoint"));
    ExitPoint->SetupAttachment(RootComponent);
    ExitPoint->SetRelativeLocation(FVector(100.f, 0.f, 0.f));
}

void ALevelTransitionDoor::Use()
{
    if (TargetLevel.IsNone()) return;


    UGameplayStatics::OpenLevel(this, TargetLevel);
}
