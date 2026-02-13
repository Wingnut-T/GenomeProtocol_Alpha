#include "GenomeCharacter.h"

// Constructor: Set default values when the character is spawned
AGenomeCharacter::AGenomeCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
    
    // Initializing our "Admin" defaults
    BloodVolume = 5.0f;
    CurrentHeartrate = 72.0f;
    PanicLevel = 0.0f;
}

// Called when the game starts
void AGenomeCharacter::BeginPlay()
{
    Super::BeginPlay();
}

// THE ACOUSTIC ENGINE LOGIC
// This function determines the "Radius" of the Heat Sphere around the player.
float AGenomeCharacter::CalculateAcousticHeat()
{
    // Base heat is 1.0 (dead silence)
    float BaseHeat = 1.0f;

    // 1. Heartrate Factor: As heartrate rises (Panic), the "thump" carries further.
    // Every 10 BPM over 70 adds to the radius.
    float HeartrateFactor = (CurrentHeartrate - 70.0f) * 0.05f;

    // 2. Panic Factor: Panic makes the character clumsy (heavy breathing, gear rattling).
    float PanicFactor = PanicLevel * 2.5f;

    // Final Heat Radius calculation
    // This value will be passed to the AI to see if they are within "hearing" distance.
    float FinalHeatRadius = BaseHeat + HeartrateFactor + PanicFactor;

    return FinalHeatRadius;
}