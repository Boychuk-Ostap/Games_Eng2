// Lab 02 - Testing a three-branch classifier
// Name  :
// Student ID:
//
// Task: fill in three tests inside runTests(), one per branch.
//
// Build:  g++ -std=c++17 -Wall -Wextra lab02_classify.cpp -o lab02
// Run  :  ./lab02

#include <iostream>
#include <string>



int classify(int x) {
    if (x < 0)  return -1;
    if (x == 0) return  0;
    return 1;
}

static int passes = 0;
static int fails = 0;
int X;

static void checkEqual(int actual, int expected, const std::string& label) {
    if (actual == expected) {
        ++passes;
        std::cout << "[PASS] " << label << "  (got " << actual << ")\n";
    }
    else {
        ++fails;
        std::cout << "[FAIL] " << label
            << "  (got " << actual << ", expected " << expected << ")\n";
    }
}

static void runTests() {
    // TODO(1): call classify() with a negative value and check the return equals -1
    X = -1;
    checkEqual(classify(X), X, "Negative branch");
    // TODO(2): call classify() with zero and check the return equals 0
    X = 0;
    checkEqual(classify(X), X, "Zero branch");
    // TODO(3): call classify() with a positive value and check the return equals 1
    X = 1;
    checkEqual(classify(X), X, "Positive branch");
    // For instance : checkEqual(classify(X), X, "negative branch");
}

int main() {
    runTests();
    std::cout << "\nSummary: " << passes << " passed, " << fails << " failed.\n";
    return fails == 0 ? 0 : 1;
}
