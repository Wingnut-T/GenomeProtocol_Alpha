#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InfectedBase.generated.h"

/**
 * Base class for all Infected (Shamblers, Runners).
 * Implements the sensory detection logic for Sound and Sight.
 */
UCLASS()
class GENOMEPROTOCOL_API AInfectedBase : public ACharacter
{
    GENERATED_BODY()

public:
    AInfectedBase();

    // The AI's 'Hearing' sensitivity. Lower is more sensitive.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genome | AI")
    float HearingThreshold = 0.5f;

    // The current state of the AI (Idle, Investigate, Aggro)
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Genome | AI")
    FString CurrentState = "Idle";

    // Function to process 'Heat' samples from the environment
    UFUNCTION(BlueprintCallable, Category = "Genome | AI")
    void SenseEnvironment(float LocalHeatValue, float ElectricalHumValue);

protected:
    // Called when the AI detects a sound above its threshold
    void OnSoundDetected(FVector Location);
};