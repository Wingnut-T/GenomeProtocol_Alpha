#pragma once

#include "CoreMinimal.h"
#include "InventoryItem.h"
#include "MedicalItem.generated.h"

/**
 * Specialized items for treating biological trauma.
 * Inherits from InventoryItem to include 'The Snap' durability logic.
 */
UCLASS(BlueprintType)
class GENOMEPROTOCOL_API UMedicalItem : public UInventoryItem
{
    GENERATED_BODY()

public:
    // How much blood loss (L/s) this item stops
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genome | Medical")
    float BleedReduction = 0.5f;

    // How much it reduces the overall Injury Modifier
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genome | Medical")
    float PainStabilization = 0.1f;

    // Time in seconds it takes to apply the item (Tactile risk)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genome | Medical")
    float ApplicationTime = 4.0f;

    // Whether this item requires a high Networking/Technical skill to use correctly 
    // (e.g., automated med-kits or advanced trauma gear)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genome | Medical")
    bool bRequiresAdvancedSkill = false;
};