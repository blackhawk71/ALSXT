#pragma once

#include "Utility/ALSXTStructs.h"
#include "Engine/DataAsset.h"
#include "Engine/EngineTypes.h"
#include "ALSXTImpactReactionSettings.generated.h"

UCLASS(Blueprintable, BlueprintType)
class ALSXT_API UALSXTImpactReactionSettings : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	TObjectPtr<UAnimMontage> Montage;

	// UnarmedAttack time to blend in amount curve.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	TObjectPtr<UCurveFloat> BlendInCurve;

	// UnarmedAttack time to interpolation, horizontal and vertical correction amounts curve.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	TObjectPtr<UCurveVector> InterpolationAndCorrectionAmountsCurve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	FVector StartRelativeLocation{-65.0f, 0.0f, -100.0f};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings", Meta = (ClampMin = 0))
	FVector2D ReferenceHeight{50.0f, 100.0f};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings", Meta = (ClampMin = 0))
	FVector2D StartTime{0.5f, 0.0f};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings", Meta = (ClampMin = 0))
	FVector2D PlayRate{1.0f, 1.0f};

public:
	float CalculateStartTime(float UnarmedAttackHeight) const;

	float CalculatePlayRate(float UnarmedAttackHeight) const;
};

inline float UALSXTImpactReactionSettings::CalculateStartTime(const float UnarmedAttackHeight) const
{
	return FMath::GetMappedRangeValueClamped(ReferenceHeight, StartTime, UnarmedAttackHeight);
}

inline float UALSXTImpactReactionSettings::CalculatePlayRate(const float UnarmedAttackHeight) const
{
	return FMath::GetMappedRangeValueClamped(ReferenceHeight, PlayRate, UnarmedAttackHeight);
}

USTRUCT(BlueprintType)
struct ALSXT_API FALSXTGeneralImpactReactionSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bAllowImpactReaction{ true };
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bRotateToInputOnStart{ true };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ClampMin = 0))
	float RotationInterpolationSpeed{ 10.0f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ClampMin = -180, ClampMax = 180))
	float RotationOffset{ 45.0f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess))
	TArray<FImpactReactionLocation> ImpactReactionLocations;
};