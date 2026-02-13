#include "TactileUI.h"

void UTactileUI::UpdateDisplay(float RawVoltage, float RawProgress)
{
    // --- 1. FORMATTING THE TEXT ---
    
    // Convert float to "12.0V" format (1 decimal place)
    FNumberFormattingOptions VoltageFormat;
    VoltageFormat.MinimumFractionalDigits = 1;
    VoltageFormat.MaximumFractionalDigits = 1;
    
    DisplayVoltage = FText::Format(FText::FromString("{0}V"), FText::AsNumber(RawVoltage, &VoltageFormat));

    // Convert 0.45 to "45%"
    DisplaySyncPercent = FText::AsPercent(RawProgress);

    // --- 2. THE STATUS LOGIC (Traffic Light System) ---

    // GREEN: Stable Power (>= 12V)
    if (RawVoltage >= 12.0f)
    {
        StatusColor = FLinearColor::Green;
    }
    // YELLOW: Brownout / Warning (9V - 11.9V)
    // The Sync is stalling, but not corrupting yet.
    else if (RawVoltage >= 9.0f)
    {
        StatusColor = FLinearColor::Yellow;
    }
    // RED: Critical Failure (< 9V)
    // Data corruption is active. Immediate action required.
    else
    {
        StatusColor = FLinearColor::Red;
    }
}