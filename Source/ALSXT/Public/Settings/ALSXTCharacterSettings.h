// MIT

#pragma once

#include "CoreMinimal.h"
#include "Settings/AlsCharacterSettings.h"
#include "Settings/ALSXTVaultingSettings.h"
#include "Settings/ALSXTSlidingSettings.h"
#include "Settings/ALSXTFPEyeFocusSettings.h"
#include "ALSXTCharacterSettings.generated.h"

/**
 * 
 */
UCLASS()
class ALSXT_API UALSXTCharacterSettings : public UAlsCharacterSettings
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FALSXTGeneralVaultingSettings Vaulting;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FALSXTGeneralSlidingSettings Sliding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FALSXTFPEyeFocusSettings FirstPersonEyeFocus;

	UALSXTCharacterSettings();
	
};
