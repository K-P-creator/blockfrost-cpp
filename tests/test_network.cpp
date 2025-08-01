#include "../include/BlockFrostClient.hpp"
#include "test_constants.h"
#include <gtest/gtest.h>

TEST(NetworkTest, ReturnsNetwork) {
	BlockFrostClient client(API_KEY);
	auto response = client.network();
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("supply"));
	EXPECT_TRUE(response["supply"].is_object());
	EXPECT_TRUE(response.contains("stake"));
	EXPECT_TRUE(response["stake"].is_object());
}

TEST(NetworkTest, ReturnsNetworkEras) {
	BlockFrostClient client(API_KEY);
	auto response = client.network_eras();
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("name"));
		EXPECT_TRUE(first["name"].is_string());
		EXPECT_TRUE(first.contains("epoch_start"));
		EXPECT_TRUE(first["epoch_start"].is_number_integer());
		EXPECT_TRUE(first.contains("epoch_end"));
		EXPECT_TRUE(first["epoch_end"].is_number_integer());
		EXPECT_TRUE(first.contains("block_start"));
		EXPECT_TRUE(first["block_start"].is_number_integer());
		EXPECT_TRUE(first.contains("block_end"));
		EXPECT_TRUE(first["block_end"].is_number_integer());
		EXPECT_TRUE(first.contains("block_time"));
		EXPECT_TRUE(first["block_time"].is_number_integer());
		EXPECT_TRUE(first.contains("slot_length"));
		EXPECT_TRUE(first["slot_length"].is_number_integer());
		EXPECT_TRUE(first.contains("slots_per_epoch"));
		EXPECT_TRUE(first["slots_per_epoch"].is_number_integer());
		EXPECT_TRUE(first.contains("max_supply"));
		EXPECT_TRUE(first["max_supply"].is_string());
	}
}
