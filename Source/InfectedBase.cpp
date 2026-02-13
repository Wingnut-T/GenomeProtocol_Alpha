#include "InfectedBase.h"

AInfectedBase::AInfectedBase()
{
    PrimaryActorTick.bCanEverTick = true;
    HearingThreshold = 0.5f;
    CurrentState = "Idle";
}

void AInfectedBase::SenseEnvironment(float LocalHeatValue, float ElectricalHumValue)
{
    // Combine acoustic and electrical signals into a 'Total Signal'
    float TotalSignal = LocalHeatValue + (ElectricalHumValue * 0.5f);

    // If the signal is significantly higher than the threshold, move to Investigate
    if (TotalSignal > (HearingThreshold * 2.5f))
    {
        CurrentState = "Investigate";
        // Logic to move AI to the location of the sound source would go here
    }
    // If signal is lower but still present, maintain Idle but stay alert
    else if (TotalSignal > HearingThreshold)
    {
        CurrentState = "Alert";
    }
    else
    {
        CurrentState = "Idle";
    }
}

void AInfectedBase::OnSoundDetected(FVector Location)
{
    // Placeholder for AI pathfinding to a specific coordinate
    if (CurrentState == "Investigate")
    {
        // MoveToLocation(Location);
    }
}