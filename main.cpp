#include "ColorCoding.h"
#include "ReferenceManual.h"
#include <iostream>

extern void runTests();

int main() {
    // Run tests
    runTests();

    // Generate and print the reference manual
    std::cout << "Reference Manual:\n";
    std::cout << TelCoColorCoder::GenerateReferenceManual();

    return 0;
}
