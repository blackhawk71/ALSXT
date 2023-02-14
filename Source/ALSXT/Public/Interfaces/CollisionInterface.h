#pragma once

#include "Utility/ALSXTStructs.h"
#include "CollisionInterface.generated.h"

UINTERFACE(Blueprintable)
class UCollisionInterface : public UInterface {
	GENERATED_BODY()
};

class ALSXT_API ICollisionInterface {
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Collision Interface")
	void GetMass(float& Mass);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Collision Interface")
	void GetVelocity(float& Velocity);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Collision Interface")
	void OnAttackCollision(FAttackDoubleHitResult Hit);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Collision Interface")
	void OnImpactCollision(FDoubleHitResult Hit);

};