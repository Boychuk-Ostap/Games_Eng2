// Lab 04 - Prime Path Coverage
// Name  : Ostap Boychuk
// StudentID: c00301627
//
// The unit under test is scanRegion( ) in src/region_scan.cpp. 
//
//
// Replace each FAIL( ) with real assertions. Add more TEST cases as you need
// them. A test "reaches" a node or edge by calling scanRegion( ) with a grid
// that forces execution down that part of the graph.

#include <gtest/gtest.h>
#include "../src/region_scan.hpp"

// The following is an example test code provided as a starter code. 
// You can use the similar test format, and choosing the right assert from GoogleTest.
// Ideally, you should be able to write test cases for all FEASIBLE prime paths
// Just like we discussed in the lecture, Prime Path Coverage Subsumes Edge-Pair coverage, which in-turn subsumes Edge coverage.
// So in this lab, if all prime paths are covered (tests written for each), we automatically complete all the edges and the pairs.
// p01 - 4-5-4, p02 5-4-5, p03 1-2-3-4-5, p19 5-4-6-2-7-8-10-11-12 
// nodes 8 and 11: sum > 10 and sum % 3 == 0
TEST(ScanRegion, WorkedExample_PositiveMultipleOfThree) {
    Grid g = {{11, 11, 11}};
    EXPECT_EQ(scanRegion(g), 33);
}

// TODO(Task 2 - node coverage): add tests so that, between them, every node
// of the graph is executed at least once. One more grid alongside the worked
// example is enough. Think about which grid drives the false arm of the
// sum > 10 decision and the default arm of the switch.
// p01, p03, p22 5-4-6-2-7-9-10-12-13
//nodes 9 and 12: sum <= 10 and sum % 3 != 0
TEST(ScanRegion, NodeCoverage_SecondTest) {
    Grid g = { {1} };
    EXPECT_EQ(scanRegion(g), -1);
}

// TODO(Task 3 - edge coverage): add the tests that cover the edges node
// coverage leaves out. The edge from the outer loop test straight to the code
// after the loops needs a grid the outer loop never enters.
//p13 1-2-7-9-10-11-13
//edge (2,7): other loop never enters
TEST(ScanRegion, EdgeCoverage_EmptyRegion) {
    Grid g = {};
    EXPECT_EQ(scanRegion(g), 0);
}

// TODO(Task 4 - prime path tour): using the prime path list in the overview,
// add tests whose executions tour the feasible prime paths. Label each test
// with the prime path numbers it covers. Three of the listed prime paths are
// infeasible; you do not write tests for those, but you must explain in your
// report why they cannot be toured.
//p20 5-4-6-2--7-8-10-12-13
TEST(ScanRegion, PrimePath_SumAtMost10_NotMultipleOf3) {
    Grid g = { {11} };
    EXPECT_EQ(scanRegion(g), 11);
 }

// p04 1-2-3-4-6, p05 2-3-4-6-2, p17 3-4-6-2-7-9-10-11-13
TEST(ScanRegion, PrimePath_EmptyRow) {
    Grid g = { {} };
    EXPECT_EQ(scanRegion(g), 0);
}
// p04, p05, p06 3-4-6-2-3, p07 4-6-2-3-4, p10 6-2-3-4-6, p17
TEST(ScanRegion, PrimePath_TwoEmptyRows) {
    Grid g = { {}, {} };
    EXPECT_EQ(scanRegion(g), 0);
}
// p07, p08 5-4-6-2-3, p09 6-2-3-4-5, p22
TEST(ScanRegion, PrimePath_TwoRows) {
    Grid g = { {1}, {1} };
    EXPECT_EQ(scanRegion(g), -2);
}
// p15 3-4-6-2-7-8-10-11-13
TEST(ScanRegion, PrimePath_LastRowEmpty_SumAbove10_MultipleOf3) {
    Grid g = { {11, 11, 11}, {} };
    EXPECT_EQ(scanRegion(g), 33);
}
// p16 3-4-6-2-7-8-10-12-13
TEST(ScanRegion, PrimePath_LastRowEmpty_SumAbove10_NotMultipleOf3) {
    Grid g = { {11}, {} };
    EXPECT_EQ(scanRegion(g), 11);
}
// p18 3-4-6-2-7-9-10-12-13
TEST(ScanRegion, PrimePath_LastRowEmpty_SumAtMost10_NotMultipleOf3) {
    Grid g = { {1}, {} };
    EXPECT_EQ(scanRegion(g), -1);
}
// p21 5-4-6-2-7-9-10-11-13
TEST(ScanRegion, PrimePath_SumAtMost10_MultipleOf3) {
    Grid g = { {3} };
    EXPECT_EQ(scanRegion(g), 0);
}