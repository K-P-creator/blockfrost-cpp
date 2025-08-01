#include "../include/BlockFrostClient.hpp"
#include "test_constants.h"
#include <gtest/gtest.h>

TEST(HealthTest, ReturnsHealthyStatus) {
    BlockFrostClient client(API_KEY);
    bool response = client.health();
    EXPECT_TRUE(response);
}

TEST(HealthTest, ReturnsTime) {
	BlockFrostClient client(API_KEY);
    auto response = client.clock();

	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("server_time"));
}