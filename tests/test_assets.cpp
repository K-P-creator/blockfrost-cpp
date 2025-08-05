#include "../include/BlockFrostClient.hpp"
#include "test_constants.h"
#include <gtest/gtest.h>

TEST(AssetsTest, ReturnsAssets) {
	BlockFrostClient client(API_KEY);
	
	client.health();
	
	auto response = client.assets(10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("asset"));
		EXPECT_TRUE(first.contains("quantity"));
	}
}

TEST(AssetsTest, ReturnsAsset) {
	BlockFrostClient client(API_KEY);
	auto response = client.asset(ASSET);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("asset"));
	EXPECT_TRUE(response.contains("policy_id"));
	EXPECT_TRUE(response.contains("asset_name"));
	EXPECT_TRUE(response.contains("fingerprint"));
}

TEST(AssetsTest, ReturnsAssetHistory) {
	BlockFrostClient client(API_KEY);
	auto response = client.asset_history(ASSET);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("tx_hash"));
		EXPECT_TRUE(first.contains("amount"));
		EXPECT_TRUE(first.contains("action"));
	}
}

TEST(AssetsTest, ReturnsAssetTransactions) {
	BlockFrostClient client(API_KEY);
	auto response = client.asset_transactions(ASSET, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("tx_hash"));
		EXPECT_TRUE(first.contains("tx_index"));
		EXPECT_TRUE(first.contains("block_height"));
	}
}

TEST(AssetsTest, ReturnsAssetAddresses) {
	BlockFrostClient client(API_KEY);
	auto response = client.asset_addresses(ASSET, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("address"));
		EXPECT_TRUE(first.contains("quantity"));
	}
}

TEST(AssetsTest, ReturnsAssetsPolicy) {
	BlockFrostClient client(API_KEY);
	
	client.health();
	
	auto response = client.assets_policy(POLICY_ID, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("asset"));
		EXPECT_TRUE(first.contains("quantity"));
	}
}
