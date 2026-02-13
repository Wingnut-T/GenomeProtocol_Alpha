#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Zone1Spawner.generated.h"

UCLASS()
class GENOMEPROTOCOL_API AZone1Spawner : public AActor
{
    GENERATED_BODY()

public:
    AZone1Spawner();

    // The current 'Loot Tier' of this tile. 
    // Tier 1 (House) = 5-10 Shamblers. Tier 3 (Pharmacy) = 25+ Shamblers.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genome | Spawning")
    int32 LootTier = 1;

    // The maximum radius for the initial spawn group.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genome | Spawning")
    float SpawnRadius = 5000.0f;

    // Function to calculate how many infected to spawn based on POI interest
    UFUNCTION(BlueprintCallable, Category = "Genome | Spawning")
    int32 CalculatePopulationDensity();

    // Logic for 'Horde Migration' - pulling infected from neighboring tiles
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genome | Spawning")
    bool bAllowMigration = true;
};