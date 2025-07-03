#include <gtest/gtest.h>
#include "1472.hpp"


TEST(BrowserHistory_tests, without_visit_deletion)
{
    BrowserHistory* bh = new BrowserHistory("google.com");

    bh->visit("youtube.com");

    EXPECT_EQ(bh->back(1), "google.com");

    EXPECT_EQ(bh->forward(1), "youtube.com");

    EXPECT_EQ(bh->back(5), "google.com");

}

TEST(BrowserHistory_tests, visit_deletion)
{
    BrowserHistory* bh = new BrowserHistory("google.com");

    bh->visit("youtube.com");

    EXPECT_EQ(bh->back(1), "google.com");

    EXPECT_EQ(bh->forward(1), "youtube.com");

    bh->visit("stackoverflow.com");

    EXPECT_EQ(bh->back(5), "google.com");

    bh->visit("leetcode.com");

    EXPECT_EQ(bh->forward(1), "leetcode.com");

}


TEST(BrowserHistory_tests, test_case_1)
{
    BrowserHistory* bh = new BrowserHistory("leetcode.com");

    bh->visit("google.com");

    bh->visit("facebook.com");

    bh->visit("youtube.com");

    EXPECT_EQ(bh->back(1), "facebook.com");

    EXPECT_EQ(bh->back(1), "google.com");
    
    EXPECT_EQ(bh->forward(1), "facebook.com");

    bh->visit("linkedin.com");

    EXPECT_EQ(bh->forward(2), "linkedin.com");

    EXPECT_EQ(bh->back(2), "google.com");

    EXPECT_EQ(bh->back(7), "leetcode.com");
}


int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}