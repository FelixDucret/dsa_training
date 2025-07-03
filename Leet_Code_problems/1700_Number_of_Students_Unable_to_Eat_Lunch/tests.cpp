#include <gtest/gtest.h>
#include "1700.hpp"


TEST(StudentCount_tests, base_case)
{
    vector<int> students = {1, 0};
    vector<int> sandwiches1 = {1, 0};
    vector<int> sandwiches2 = {1, 1};
    EXPECT_EQ(countStudents(students, sandwiches1), 0);
    EXPECT_EQ(countStudents(students, sandwiches2), 1);
}

TEST(StudentCount_tests, test_case_1)
{
    vector<int> students = {1, 1, 0, 0};
    vector<int> sandwiches = {0, 1, 0, 1};
    EXPECT_EQ(countStudents(students, sandwiches), 0);
}

TEST(StudentCount_tests, test_case_2)
{
    vector<int> students = {1, 1, 1, 0, 0, 1};
    vector<int> sandwiches = {1, 0, 0, 0, 1, 1};
    EXPECT_EQ(countStudents(students, sandwiches), 3);
}


int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
};