#include "../include/BlockFrostClient.hpp"
#include "test_constants.h"
#include <gtest/gtest.h>

TEST(NetworkTest, ReturnsNetwork) {
	BlockFrostClient client(API_KEY);
	auto response = client.network();
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("supply"));
	EXPECT_TRUE(response.contains("stake"));
}

TEST(NetworkTest, ReturnsNetworkEras) {
	BlockFrostClient client(API_KEY);
	auto response = client.network_eras();
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("start"));
		EXPECT_TRUE(first.contains("end"));
		EXPECT_TRUE(first.contains("parameters"));
	}
}
