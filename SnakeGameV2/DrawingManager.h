#pragma once

#include <cstdint>

class DrawingManager
{
public:

    static DrawingManager& Instance()
    {
        static DrawingManager* pInstance = new DrawingManager();
        return *pInstance;
    }

    void ColourSquare(const int16_t x, const int16_t y);

    void DrawFruit(const int16_t x, const int16_t y);

private:
    DrawingManager() {}
};

