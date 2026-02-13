#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TactileUI.generated.h"

/**
 * Interface for in-game hardware displays.
 * Used for the Handheld Diagnostic Tool and the Lab Terminal Monitor.
 */
UCLASS()
class GENOMEPROTOCOL_API UTactileUI : public UUserWidget
{
    GENERATED_BODY()

public:
    // --- DIAGNOSTIC DATA ---

    // Formatted string for Voltage (e.g., "12.02V")
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genome | UI")
    FText DisplayVoltage;

    // Formatted string for Sync Progress (e.g., "SYNC: 45%")
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genome | UI")
    FText DisplaySyncPercent;

    // Status Indicator: Green (Stable), Yellow (Warning), Red (Corruption)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genome | UI")
    FLinearColor StatusColor;

    // --- REFRESH LOGIC ---

    // Updates the display with raw data from the Lab Terminal or Power Node
    UFUNCTION(BlueprintCallable, Category = "Genome | UI")
    void UpdateDisplay(float RawVoltage, float RawProgress);
};