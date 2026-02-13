#include "Zone1Spawner.h"

AZone1Spawner::AZone1Spawner()
{
    PrimaryActorTick.bCanEverTick = true;
    LootTier = 1;
    SpawnRadius = 5000.0f;
    bAllowMigration = true;
}

int32 AZone1Spawner::CalculatePopulationDensity()
{
    // Base population for a residential tile
    int32 BasePop = 5;

    // Multiply population by the Loot Tier (POI Interest)
    // Tier 1 (House) = 5, Tier 3 (Pharmacy) = 15
    int32 FinalPop = BasePop * LootTier;

    return FinalPop;
}

// Logic to simulate 'Drift' 
// If noise levels are high in a neighboring tile, this tile 'exports' its population there.
void SimulateMigration(float NeighboringHeat)
{
    if (NeighboringHeat > 5.0f)
    {
        // Internal logic would move AI agents toward the high-heat tile
    }
}