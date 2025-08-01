#include "../include/BlockFrostClient.hpp"
#include "test_constants.h"
#include <gtest/gtest.h>


TEST(AddressesTest, ReturnsAddress) {
	BlockFrostClient client(API_KEY);
	auto response = client.address(BECH32_ADDR);

	ASSERT_TRUE(response.is_object());

	if (!response.empty())
	{
		EXPECT_TRUE(response.contains("address"));
		EXPECT_TRUE(response.contains("amount"));
	}
}

TEST(AddressesTest, ReturnsAddressExtended) {
	BlockFrostClient client(API_KEY);
	auto response = client.address_extended(BECH32_ADDR);
	ASSERT_TRUE(response.is_object());
	if (!response.empty())
	{
		EXPECT_TRUE(response.contains("address"));
		EXPECT_TRUE(response.contains("amount"));
	}
}

TEST(AddressesTest, ReturnsAddressTotal) {
	BlockFrostClient client(API_KEY);
	auto response = client.address_total(BECH32_ADDR);
	ASSERT_TRUE(response.is_object());
	if (!response.empty())
	{
		EXPECT_TRUE(response.contains("address"));
		EXPECT_TRUE(response.contains("received_sum"));
	}
}

TEST(AddressesTest, ReturnsAddressUtxos) {
	BlockFrostClient client(API_KEY);
	auto response = client.address_utxos(BECH32_ADDR);
	ASSERT_TRUE(response.is_array());
	if (!response.empty())
	{
		auto& first = response[0];
		EXPECT_TRUE(first.contains("tx_hash"));
		EXPECT_TRUE(first.contains("output_index"));
		EXPECT_TRUE(first.contains("amount"));
	}
}

TEST(AddressesTest, ReturnsAddressUtxosAsset) {
	BlockFrostClient client(API_KEY);
	auto response = client.address_uxtos_asset(BECH32_ADDR, ASSET);
	ASSERT_TRUE(response.is_array());
	if (!response.empty())
	{
		auto& first = response[0];
		EXPECT_TRUE(first.contains("tx_hash"));
		EXPECT_TRUE(first.contains("address"));
		EXPECT_TRUE(first.contains("output_index"));
		EXPECT_TRUE(first.contains("amount"));
	}
}

TEST(AddressesTest, ReturnsAddressTransactions) {
	BlockFrostClient client(API_KEY);
	auto response = client.address_transactions(BECH32_ADDR);
	ASSERT_TRUE(response.is_array());
	if (!response.empty())
	{
		auto& first = response[0];
		EXPECT_TRUE(first.contains("tx_hash"));		
		EXPECT_TRUE(first.contains("block_height"));
		EXPECT_TRUE(first.contains("block_time"));
	}
}