#include "ColorCoding.h"
#include "ReferenceManual.h"
#include <sstream>

namespace TelCoColorCoder {
    std::string GenerateReferenceManual() {
        std::ostringstream manual;
        for (int i = 1; i <= TOTAL_PAIRS; ++i) {
            ColorPair pair = GetColorFromPairNumber(i);
            manual << i << " - " << pair.ToString() << "\n";
        }
        return manual.str();
    }
}
