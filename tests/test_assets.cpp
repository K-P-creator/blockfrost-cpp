#include "../include/BlockFrostClient.hpp"
#include "test_constants.h"
#include <gtest/gtest.h>

TEST(AssetsTest, ReturnsAssets) {
	BlockFrostClient client(API_KEY);
	auto response = client.assets(10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("asset"));
		EXPECT_TRUE(first["asset"].is_string());
		EXPECT_TRUE(first.contains("policy_id"));
		EXPECT_TRUE(first["policy_id"].is_string());
		EXPECT_TRUE(first.contains("asset_name"));
		EXPECT_TRUE(first.contains("fingerprint"));
		EXPECT_TRUE(first["fingerprint"].is_string());
	}
}

TEST(AssetsTest, ReturnsAsset) {
	BlockFrostClient client(API_KEY);
	auto response = client.asset(ASSET);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("asset"));
	EXPECT_TRUE(response["asset"].is_string());
	EXPECT_TRUE(response.contains("policy_id"));
	EXPECT_TRUE(response["policy_id"].is_string());
	EXPECT_TRUE(response.contains("asset_name"));
	EXPECT_TRUE(response.contains("fingerprint"));
	EXPECT_TRUE(response["fingerprint"].is_string());
}

TEST(AssetsTest, ReturnsAssetHistory) {
	BlockFrostClient client(API_KEY);
	auto response = client.asset_history(ASSET);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("tx_hash"));
		EXPECT_TRUE(first["tx_hash"].is_string());
		EXPECT_TRUE(first.contains("amount"));
		EXPECT_TRUE(first["amount"].is_string());
		EXPECT_TRUE(first.contains("action"));
		EXPECT_TRUE(first["action"].is_string());
	}
}

TEST(AssetsTest, ReturnsAssetTransactions) {
	BlockFrostClient client(API_KEY);
	auto response = client.asset_transactions(ASSET, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("tx_hash"));
		EXPECT_TRUE(first["tx_hash"].is_string());
		EXPECT_TRUE(first.contains("tx_index"));
		EXPECT_TRUE(first["tx_index"].is_number_integer());
		EXPECT_TRUE(first.contains("block_height"));
		EXPECT_TRUE(first["block_height"].is_number_integer());
	}
}

TEST(AssetsTest, ReturnsAssetAddresses) {
	BlockFrostClient client(API_KEY);
	auto response = client.asset_addresses(ASSET, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("address"));
		EXPECT_TRUE(first["address"].is_string());
		EXPECT_TRUE(first.contains("quantity"));
		EXPECT_TRUE(first["quantity"].is_string());
	}
}

TEST(AssetsTest, ReturnsAssetsPolicy) {
	BlockFrostClient client(API_KEY);
	auto response = client.assets_policy(POLICY_ID, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("asset"));
		EXPECT_TRUE(first["asset"].is_string());
		EXPECT_TRUE(first.contains("policy_id"));
		EXPECT_TRUE(first["policy_id"].is_string());
		EXPECT_TRUE(first.contains("asset_name"));
		EXPECT_TRUE(first.contains("fingerprint"));
		EXPECT_TRUE(first["fingerprint"].is_string());
	}
}
