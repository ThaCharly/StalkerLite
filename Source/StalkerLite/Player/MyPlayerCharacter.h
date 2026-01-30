#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"
#include "../Actors/LevelTransitionDoor.h"
#include "DrawDebugHelpers.h"
#include "MyPlayerCharacter.generated.h"



UCLASS()
class STALKERLITE_API AMyPlayerCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AMyPlayerCharacter();

    void MoveForward(float Value);
    void MoveRight(float Value);
    void Interact();



protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
    UPROPERTY(VisibleAnywhere)
    class UCameraComponent* Camera;
};
