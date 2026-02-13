#pragma once

#include "CoreMinimal.h"
#include "PowerNode.h"
#include "LabTerminal.generated.h"

/**
 * The primary objective node. Requires high power and generates 
 * significant acoustic 'Heat' during the Sync process.
 */
UCLASS(BlueprintType)
class GENOMEPROTOCOL_API ALabTerminal : public AActor
{
    GENERATED_BODY()

public:
    ALabTerminal();

    // --- SYNC STATUS ---

    // Current progress (0.0 to 1.0)
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Genome | Terminal")
    float SyncProgress = 0.0f;

    // Minimum voltage required from the PowerNode to prevent data corruption
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genome | Terminal")
    float RequiredVoltage = 12.0f;

    // --- ENVIRONMENTAL IMPACT ---

    // Heat multiplier while syncing. Fans spin at 100% duty cycle.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genome | Terminal")
    float SyncAcousticMultiplier = 4.5f;

    // --- FUNCTIONS ---

    // Starts the 5-minute 'Commitment' window
    UFUNCTION(BlueprintCallable, Category = "Genome | Terminal")
    void BeginDataSync();

    // Logic to handle power fluctuations (brownouts)
    UFUNCTION(BlueprintCallable, Category = "Genome | Terminal")
    void HandlePowerFluctuation(float IncomingVoltage);
};