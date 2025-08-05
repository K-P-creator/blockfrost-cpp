#include "../include/BlockFrostClient.hpp"
#include "test_constants.h"
#include <gtest/gtest.h>

TEST(MempoolTest, ReturnsMempool) {
	BlockFrostClient client(API_KEY);
	auto response = client.mempool(10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("tx_hash"));
	}
}

TEST(MempoolTest, ReturnsMempoolTransaction) {
	BlockFrostClient client(API_KEY);
	auto response = client.mempool_transaction(TX_HASH);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("tx_hash"));
	EXPECT_TRUE(response.contains("tx_size"));
	EXPECT_TRUE(response.contains("total_output"));
	EXPECT_TRUE(response.contains("fee"));
	EXPECT_TRUE(response.contains("time"));
}

TEST(MempoolTest, ReturnsMempoolAddress) {
	BlockFrostClient client(API_KEY);
	auto response = client.mempool_address(BECH32_ADDR, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("tx_hash"));
		EXPECT_TRUE(first.contains("tx_size"));
		EXPECT_TRUE(first.contains("total_output"));
		EXPECT_TRUE(first.contains("fee"));
		EXPECT_TRUE(first.contains("time"));
	}
}
