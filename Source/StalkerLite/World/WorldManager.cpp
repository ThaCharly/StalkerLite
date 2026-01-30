#include "WorldManager.h"
#include "Engine/Engine.h"


AWorldManager::AWorldManager()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AWorldManager::BeginPlay()
{
    Super::BeginPlay();
}

void AWorldManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    CurrentTime += DeltaTime;

    if (CurrentTime >= DayDuration)
    {
        CurrentTime = 0.f;
        bIsNight = !bIsNight;

        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(
                -1,
                2.f,
                bIsNight ? FColor::Blue : FColor::Yellow,
                bIsNight ? TEXT("NOCHE") : TEXT("DIA")
            );
        }

    }
}

