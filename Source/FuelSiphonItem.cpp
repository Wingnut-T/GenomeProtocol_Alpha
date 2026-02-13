#include "FuelSiphonItem.h"

bool UFuelSiphonItem::ProcessTransfer(float DeltaTime, float& SourceAmount, float& TargetCurrent, float TargetMax)
{
    // 1. VALIDATION CHECKS (The Handshake)
    if (SourceAmount <= 0.0f) 
    {
        // Source is empty (404 Not Found)
        return false; 
    }

    if (TargetCurrent >= TargetMax) 
    {
        // Target is full (Buffer Overflow)
        return false; 
    }

    // 2. CALCULATE TRANSFER AMOUNT
    // How much fuel moves in this specific frame?
    float AmountToMove = FlowRate * DeltaTime;

    // 3. CLAMPING LOGIC
    // Don't take more than exists, don't fill more than space allows.
    if (AmountToMove > SourceAmount) AmountToMove = SourceAmount;
    if ((TargetCurrent + AmountToMove) > TargetMax) AmountToMove = TargetMax - TargetCurrent;

    // 4. EXECUTE TRANSFER
    SourceAmount -= AmountToMove;
    TargetCurrent += AmountToMove;

    // Return true to keep the 'Siphon Loop' running
    return true; 
}