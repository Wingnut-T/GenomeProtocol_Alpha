#pragma once

#include "CoreMinimal.h"
#include "InventoryItem.h"
#include "PowerNode.generated.h"

/**
 * Base class for all electrical components (Batteries, Solar, Generators, Lab Gear).
 * Manages the flow of Voltage and Amperage in the local grid.
 */
UCLASS(BlueprintType)
class GENOMEPROTOCOL_API UPowerNode : public UInventoryItem
{
    GENERATED_BODY()

public:
    // --- ELECTRICAL SPECS ---

    // Operating Voltage (e.g., 12.0V). 
    // If this drops below a threshold, connected 'Load' gear flickers or corrupts data.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genome | Power")
    float OperatingVoltage = 12.0f;

    // The rate of energy consumption (A). 
    // Higher Amperage draw drains batteries faster and increases 'Electrical Hum' noise.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genome | Power")
    float AmperageDraw = 0.5f;

    // Efficiency Rating (0.0 to 1.0). 
    // Low-tier scavenged gear wastes power as heat/noise.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genome | Power")
    float Efficiency = 0.85f;

    // --- INFRASTRUCTURE LOGIC ---

    // Does this node provide power (Solar/Battery) or consume it (Lab Terminal/Lights)?
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genome | Power")
    bool bIsPowerSource = false;

    // Signal Leakage: The electrical hum radius (Heat) generated while active.
    UFUNCTION(BlueprintCallable, Category = "Genome | Power")
    float GetElectricalHumRadius();
};