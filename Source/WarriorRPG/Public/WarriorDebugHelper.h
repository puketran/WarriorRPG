#pragma once

namespace Debug
{
    static void Print(const FString &Message, const FColor &Color = FColor::MakeRandomColor(), int InKey = -1)
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(InKey, 5.f, Color, Message);
        }
    }
}