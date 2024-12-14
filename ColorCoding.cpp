#include "ColorCoding.h"
#include <stdexcept>
#include <array>

namespace TelCoColorCoder {

    const std::array<std::string, 5> MajorColorNames = { "White", "Red", "Black", "Yellow", "Violet" };
    const std::array<std::string, 5> MinorColorNames = { "Blue", "Orange", "Green", "Brown", "Slate" };

    ColorPair::ColorPair(MajorColor major, MinorColor minor) 
        : majorColor(major), minorColor(minor) {}

    MajorColor ColorPair::getMajor() const { return majorColor; }
    MinorColor ColorPair::getMinor() const { return minorColor; }

    std::string ColorPair::ToString() const {
        return MajorColorNames[majorColor] + " " + MinorColorNames[minorColor];
    }

    ColorPair GetColorFromPairNumber(int pairNumber) {
        if (pairNumber < 1 || pairNumber > TOTAL_PAIRS) {
            throw std::out_of_range("Pair number out of range.");
        }
        int zeroBasedPairNumber = pairNumber - 1;
        MajorColor majorColor = static_cast<MajorColor>(zeroBasedPairNumber / MinorColorNames.size());
        MinorColor minorColor = static_cast<MinorColor>(zeroBasedPairNumber % MinorColorNames.size());
        return ColorPair(majorColor, minorColor);
    }

    int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
        return major * MinorColorNames.size() + minor + 1;
    }
}
