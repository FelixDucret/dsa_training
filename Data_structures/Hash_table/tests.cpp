#include <gtest/gtest.h>
#include "Hash_table.hpp"


TEST(HashTable_tests, insert_get)
{
    HashTable ht = HashTable(2);

    ht.insert(1, 4);

    EXPECT_EQ(ht.get(1), 4);
    EXPECT_EQ(ht.get(0), -1);
}

// TEST(HashTable, case_1)
// {
//     HashTable ht = HashTable(4);
//     ht.insert(1, 2);
//     EXPECT_EQ(ht.get(1), 2);

//     ht.insert(1, 3);
//     EXPECT_EQ(ht.get(1), 3);

//     EXPECT_EQ(ht.remove(1), true);

//     EXPECT_EQ(ht.get(1), -1);
// }

// TEST(HashTable, case_2)
// {
//     HashTable ht = HashTable(2);
//     EXPECT_EQ(ht.getCapacity(), 2);

//     ht.insert(6, 7);
//     EXPECT_EQ(ht.getCapacity(), 4);

//     ht.insert(1, 2);
//     EXPECT_EQ(ht.getCapacity(), 8);

//     ht.insert(3, 4);
//     EXPECT_EQ(ht.getCapacity(), 8);

//     EXPECT_EQ(ht.getSize(), 3);
// }

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}