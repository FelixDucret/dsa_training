#include <gtest/gtest.h>
#include "Hash_table.hpp"


TEST(HashTable_tests, insert_get)
{
    HashTable ht = HashTable(2);

    ht.insert(1, 4);

    EXPECT_EQ(ht.get(1), 4);
    EXPECT_EQ(ht.get(0), -1);
}

TEST(HashTable_tests, remove)
{
    HashTable ht = HashTable(2);

    ht.insert(1, 4);
    ht.insert(0, 7);

    EXPECT_EQ(ht.get(1), 4);

    EXPECT_EQ(ht.remove(1), true);

    EXPECT_EQ(ht.get(1), -1);

    EXPECT_EQ(ht.remove(1), false);

    EXPECT_EQ(ht.get(0), 7);

}

TEST(HashTable_tests, getSize)
{
    HashTable ht = HashTable(2);
    EXPECT_EQ(ht.getSize(), 0);

    ht.insert(1, 1);

    EXPECT_EQ(ht.getSize(), 1);

    ht.insert(0, 2);

    EXPECT_EQ(ht.getSize(), 2);

    ht.remove(0);

    EXPECT_EQ(ht.getSize(), 1);

}

TEST(HashTable, case_1)
{
    HashTable ht = HashTable(4);
    ht.insert(1, 2);
    EXPECT_EQ(ht.get(1), 2);

    ht.insert(1, 3);
    EXPECT_EQ(ht.get(1), 3);

    EXPECT_EQ(ht.remove(1), true);

    EXPECT_EQ(ht.get(1), -1);
}

TEST(HashTable, getCapacity)
{
    HashTable ht = HashTable(2);
    EXPECT_EQ(ht.getCapacity(), 2);

    ht.insert(0, 1);
    EXPECT_EQ(ht.getCapacity(), 4);

    ht.remove(0);
    EXPECT_EQ(ht.getCapacity(), 4);

}

TEST(HashTable, resize)
{
    HashTable ht = HashTable(1);
    ht.resize();
    EXPECT_EQ(ht.getCapacity(), 2);

    ht.insert(3, 4);
    ht.insert(1, 2);
    
    EXPECT_EQ(ht.get(1), 2);
    EXPECT_EQ(ht.get(3), 4);


}

TEST(HashTable, case_2)
{
    HashTable ht = HashTable(2);
    EXPECT_EQ(ht.getCapacity(), 2);

    ht.insert(6, 7);
    EXPECT_EQ(ht.getCapacity(), 4);

    ht.insert(1, 2);
    EXPECT_EQ(ht.getCapacity(), 8);

    ht.insert(3, 4);
    EXPECT_EQ(ht.getCapacity(), 8);

    EXPECT_EQ(ht.getSize(), 3);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}