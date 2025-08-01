#include "../include/BlockFrostClient.hpp"
#include "test_constants.h"
#include <gtest/gtest.h>

TEST(BlocksTest, ReturnsBlocksLatest) {
	BlockFrostClient client(API_KEY);
	auto response = client.blocks_latest();
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("hash"));
	EXPECT_TRUE(response["hash"].is_string());
	EXPECT_TRUE(response.contains("epoch"));
	EXPECT_TRUE(response["epoch"].is_number_integer());
	EXPECT_TRUE(response.contains("slot"));
	EXPECT_TRUE(response["slot"].is_number_integer());
	EXPECT_TRUE(response.contains("height"));
	EXPECT_TRUE(response["height"].is_number_integer());
}

TEST(BlocksTest, ReturnsBlocksLatestTransactions) {
	BlockFrostClient client(API_KEY);
	auto response = client.blocks_latest_transactions(10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("hash"));
		EXPECT_TRUE(first["hash"].is_string());
		EXPECT_TRUE(first.contains("block"));
		EXPECT_TRUE(first["block"].is_string());
		EXPECT_TRUE(first.contains("block_height"));
		EXPECT_TRUE(first["block_height"].is_number_integer());
	}
}

TEST(BlocksTest, ReturnsBlocksLatestTransactionsCbor) {
	BlockFrostClient client(API_KEY);
	auto response = client.blocks_latest_transactions_cbor(10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("hash"));
		EXPECT_TRUE(first["hash"].is_string());
		EXPECT_TRUE(first.contains("block"));
		EXPECT_TRUE(first["block"].is_string());
		EXPECT_TRUE(first.contains("block_height"));
		EXPECT_TRUE(first["block_height"].is_number_integer());
		EXPECT_TRUE(first.contains("cbor_hex"));
		EXPECT_TRUE(first["cbor_hex"].is_string());
	}
}

TEST(BlocksTest, ReturnsBlock) {
	BlockFrostClient client(API_KEY);
	auto response = client.block(BLOCK_HASH_OR_NUMBER);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("hash"));
	EXPECT_TRUE(response["hash"].is_string());
	EXPECT_TRUE(response.contains("epoch"));
	EXPECT_TRUE(response["epoch"].is_number_integer());
	EXPECT_TRUE(response.contains("slot"));
	EXPECT_TRUE(response["slot"].is_number_integer());
	EXPECT_TRUE(response.contains("height"));
	EXPECT_TRUE(response["height"].is_number_integer());
}

TEST(BlocksTest, ReturnsBlockNext) {
	BlockFrostClient client(API_KEY);
	auto response = client.block_next(BLOCK_HASH_OR_NUMBER, 10, 1);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("hash"));
		EXPECT_TRUE(first["hash"].is_string());
		EXPECT_TRUE(first.contains("epoch"));
		EXPECT_TRUE(first["epoch"].is_number_integer());
		EXPECT_TRUE(first.contains("slot"));
		EXPECT_TRUE(first["slot"].is_number_integer());
		EXPECT_TRUE(first.contains("height"));
		EXPECT_TRUE(first["height"].is_number_integer());
	}
}

TEST(BlocksTest, ReturnsBlockPrevious) {
	BlockFrostClient client(API_KEY);
	auto response = client.block_previous(BLOCK_HASH_OR_NUMBER, 10, 1);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("hash"));
		EXPECT_TRUE(first["hash"].is_string());
		EXPECT_TRUE(first.contains("epoch"));
		EXPECT_TRUE(first["epoch"].is_number_integer());
		EXPECT_TRUE(first.contains("slot"));
		EXPECT_TRUE(first["slot"].is_number_integer());
		EXPECT_TRUE(first.contains("height"));
		EXPECT_TRUE(first["height"].is_number_integer());
	}
}

TEST(BlocksTest, ReturnsBlockSlot) {
	BlockFrostClient client(API_KEY);
	auto response = client.block_slot(BLOCK_SLOT);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("hash"));
	EXPECT_TRUE(response["hash"].is_string());
	EXPECT_TRUE(response.contains("epoch"));
	EXPECT_TRUE(response["epoch"].is_number_integer());
	EXPECT_TRUE(response.contains("slot"));
	EXPECT_TRUE(response["slot"].is_number_integer());
	EXPECT_TRUE(response.contains("height"));
	EXPECT_TRUE(response["height"].is_number_integer());
}

TEST(BlocksTest, ReturnsBlockEpochSlot) {
	BlockFrostClient client(API_KEY);
	auto response = client.block_epoch_slot(EPOCH_NUMBER, EPOCH_SLOT);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("hash"));
	EXPECT_TRUE(response["hash"].is_string());
	EXPECT_TRUE(response.contains("epoch"));
	EXPECT_TRUE(response["epoch"].is_number_integer());
	EXPECT_TRUE(response.contains("slot"));
	EXPECT_TRUE(response["slot"].is_number_integer());
	EXPECT_TRUE(response.contains("height"));
	EXPECT_TRUE(response["height"].is_number_integer());
}

TEST(BlocksTest, ReturnsBlockTransactions) {
	BlockFrostClient client(API_KEY);
	auto response = client.block_transactions(BLOCK_HASH_OR_NUMBER, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("hash"));
		EXPECT_TRUE(first["hash"].is_string());
		EXPECT_TRUE(first.contains("block"));
		EXPECT_TRUE(first["block"].is_string());
		EXPECT_TRUE(first.contains("block_height"));
		EXPECT_TRUE(first["block_height"].is_number_integer());
	}
}

TEST(BlocksTest, ReturnsBlockTransactionsCbor) {
	BlockFrostClient client(API_KEY);
	auto response = client.block_transactions_cbor(BLOCK_HASH_OR_NUMBER, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("hash"));
		EXPECT_TRUE(first["hash"].is_string());
		EXPECT_TRUE(first.contains("block"));
		EXPECT_TRUE(first["block"].is_string());
		EXPECT_TRUE(first.contains("block_height"));
		EXPECT_TRUE(first["block_height"].is_number_integer());
		EXPECT_TRUE(first.contains("cbor_hex"));
		EXPECT_TRUE(first["cbor_hex"].is_string());
	}
}

TEST(BlocksTest, ReturnsBlockAddresses) {
	BlockFrostClient client(API_KEY);
	auto response = client.block_addresses(BLOCK_HASH_OR_NUMBER, 10, 1);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("address"));
		EXPECT_TRUE(first["address"].is_string());
		EXPECT_TRUE(first.contains("transactions"));
		EXPECT_TRUE(first["transactions"].is_array());
	}
}
