#include "BaseGameMode.h"
#include "../Player/MyPlayerCharacter.h"

ABaseGameMode::ABaseGameMode()
{
    DefaultPawnClass = AMyPlayerCharacter::StaticClass();
}
