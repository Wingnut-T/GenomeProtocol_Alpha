#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InventoryItem.generated.h"

/**
 * Base class for all scavengeable tools and items.
 * Implements 'The Snap' - 100% functionality until 0 durability.
 */
UCLASS(BlueprintType)
class GENOMEPROTOCOL_API UInventoryItem : public UObject
{
    GENERATED_BODY()

public:
    // Item Identifier
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genome | Item")
    FString ItemName;

    // Current durability uses remaining
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Genome | Item")
    int32 CurrentDurability = 50;

    // The logic for using a tool (Hammering, Screwing, Siphoning)
    UFUNCTION(BlueprintCallable, Category = "Genome | Item")
    bool UseItem()
    {
        if (CurrentDurability > 0)
        {
            CurrentDurability--;
            
            // Logic: Tools work perfectly until they hit 0.
            if (CurrentDurability == 0)
            {
                // In Alpha, this will trigger the 'Snap' SFX.
                return false; 
            }
            return true;
        }
        return false; // Item is already broken/spent
    }
};