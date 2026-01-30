#include "WorldManager.h"
#include "Kismet/GameplayStatics.h"
#include "../Player/MyPlayerCharacter.h"
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

		// Mostrar mensaje en pantalla al cambio de día a noche y viceversa.
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

	// Si es de noche y no es un mapa seguro, moriste de wan.
    if (bIsNight && !bIsSafeMap)
    {
        AMyPlayerCharacter* Player =
            Cast<AMyPlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

        if (Player)
        {
            Player->Destroy();
        }
    }
}

