#include "../include/BlockFrostClient.hpp"
#include "test_constants.h"
#include <gtest/gtest.h>

TEST(AddressesTest, ReturnsAddress) {
	BlockFrostClient client(API_KEY);
	auto response = client.address(BECH32_ADDR);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("address"));
	EXPECT_TRUE(response.contains("amount"));
	EXPECT_TRUE(response.contains("stake_address"));
	EXPECT_TRUE(response.contains("type"));
	EXPECT_TRUE(response.contains("script"));
}

TEST(AddressesTest, ReturnsAddressDetails) {
	BlockFrostClient client(API_KEY);
	auto response = client.address_extended(BECH32_ADDR);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("address"));
	EXPECT_TRUE(response.contains("amount"));
	EXPECT_TRUE(response.contains("stake_address"));
	EXPECT_TRUE(response.contains("type"));
	EXPECT_TRUE(response.contains("script"));
}

TEST(AddressesTest, ReturnsAddressUtxos) {
	BlockFrostClient client(API_KEY);
	auto response = client.address_utxos(BECH32_ADDR);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("tx_hash"));
		EXPECT_TRUE(first.contains("tx_index"));
		EXPECT_TRUE(first.contains("output_index"));
		EXPECT_TRUE(first.contains("amount"));
		EXPECT_TRUE(first.contains("block"));
		EXPECT_TRUE(first.contains("data_hash"));
	}
}

TEST(AddressesTest, ReturnsAddressUtxosAsset) {
	BlockFrostClient client(API_KEY);
	auto response = client.address_utxos_asset(BECH32_ADDR, ASSET);

	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("tx_hash"));
		EXPECT_TRUE(first.contains("tx_index"));
		EXPECT_TRUE(first.contains("output_index"));
		EXPECT_TRUE(first.contains("amount"));
		EXPECT_TRUE(first.contains("block"));
		EXPECT_TRUE(first.contains("data_hash"));
	}
}

TEST(AddressesTest, ReturnsAddressTransactions) {
	BlockFrostClient client(API_KEY);
	auto response = client.address_transactions(BECH32_ADDR);

	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("tx_hash"));
		EXPECT_TRUE(first.contains("tx_index"));
		EXPECT_TRUE(first.contains("block_height"));
		EXPECT_TRUE(first.contains("block_time"));
	}
}