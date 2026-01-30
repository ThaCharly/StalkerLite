#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldManager.generated.h"

UCLASS()
class STALKERLITE_API AWorldManager : public AActor
{
    GENERATED_BODY()

public:
    AWorldManager();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

	// El tiempo y sus propiedades son manejadas acá:

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Time")
    float DayDuration = 30.f; // 0.5 minutos por día

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Time")
    float CurrentTime = 0.f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Time")
    bool bIsNight = false;

	// Propiedades del mapa acá:

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "World")
    bool bIsSafeMap = false;


};
