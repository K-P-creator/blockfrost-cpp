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
		EXPECT_TRUE(first["tx_hash"].is_string());
		EXPECT_TRUE(first.contains("tx_size"));
		EXPECT_TRUE(first["tx_size"].is_number_integer());
		EXPECT_TRUE(first.contains("total_output"));
		EXPECT_TRUE(first["total_output"].is_string());
		EXPECT_TRUE(first.contains("fee"));
		EXPECT_TRUE(first["fee"].is_string());
		EXPECT_TRUE(first.contains("time"));
		EXPECT_TRUE(first["time"].is_number_integer());
	}
}

TEST(MempoolTest, ReturnsMempoolTransaction) {
	BlockFrostClient client(API_KEY);
	auto response = client.mempool_transaction(MEMPOOL_TX_HASH);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("tx_hash"));
	EXPECT_TRUE(response["tx_hash"].is_string());
	EXPECT_TRUE(response.contains("tx_size"));
	EXPECT_TRUE(response["tx_size"].is_number_integer());
	EXPECT_TRUE(response.contains("total_output"));
	EXPECT_TRUE(response["total_output"].is_string());
	EXPECT_TRUE(response.contains("fee"));
	EXPECT_TRUE(response["fee"].is_string());
	EXPECT_TRUE(response.contains("time"));
	EXPECT_TRUE(response["time"].is_number_integer());
}

TEST(MempoolTest, ReturnsMempoolAddress) {
	BlockFrostClient client(API_KEY);
	auto response = client.mempool_address(BECH32_ADDR, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("tx_hash"));
		EXPECT_TRUE(first["tx_hash"].is_string());
		EXPECT_TRUE(first.contains("tx_size"));
		EXPECT_TRUE(first["tx_size"].is_number_integer());
		EXPECT_TRUE(first.contains("total_output"));
		EXPECT_TRUE(first["total_output"].is_string());
		EXPECT_TRUE(first.contains("fee"));
		EXPECT_TRUE(first["fee"].is_string());
		EXPECT_TRUE(first.contains("time"));
		EXPECT_TRUE(first["time"].is_number_integer());
	}
}
