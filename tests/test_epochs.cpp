#include "../include/BlockFrostClient.hpp"
#include "test_constants.h"
#include <gtest/gtest.h>

TEST(EpochsTest, ReturnsEpochsLatest) {
	BlockFrostClient client(API_KEY);
	
	// Call health to ensure API is ready
	client.health();
	
	auto response = client.epochs_latest();
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("epoch"));
	EXPECT_TRUE(response.contains("start_time"));
	EXPECT_TRUE(response.contains("end_time"));
	EXPECT_TRUE(response.contains("first_block_time"));
	EXPECT_TRUE(response.contains("last_block_time"));
	EXPECT_TRUE(response.contains("block_count"));
	EXPECT_TRUE(response.contains("tx_count"));
	EXPECT_TRUE(response.contains("output"));
	EXPECT_TRUE(response.contains("fees"));
	EXPECT_TRUE(response.contains("active_stake"));
}

TEST(EpochsTest, ReturnsEpochsLatestParameters) {
	BlockFrostClient client(API_KEY);
	
	// Call health to ensure API is ready
	client.health();
	
	auto response = client.epochs_latest_parameters();
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("epoch"));
	EXPECT_TRUE(response.contains("min_fee_a"));
	EXPECT_TRUE(response.contains("min_fee_b"));
	EXPECT_TRUE(response.contains("max_block_size"));
	EXPECT_TRUE(response.contains("max_tx_size"));
	EXPECT_TRUE(response.contains("max_block_header_size"));
	EXPECT_TRUE(response.contains("key_deposit"));
	EXPECT_TRUE(response.contains("pool_deposit"));
	EXPECT_TRUE(response.contains("e_max"));
	EXPECT_TRUE(response.contains("n_opt"));
	EXPECT_TRUE(response.contains("a0"));
	EXPECT_TRUE(response.contains("rho"));
	EXPECT_TRUE(response.contains("tau"));
	EXPECT_TRUE(response.contains("decentralisation_param"));
	EXPECT_TRUE(response.contains("extra_entropy"));
	EXPECT_TRUE(response.contains("protocol_major_ver"));
	EXPECT_TRUE(response.contains("protocol_minor_ver"));
	EXPECT_TRUE(response.contains("min_utxo"));
	EXPECT_TRUE(response.contains("min_pool_cost"));
	EXPECT_TRUE(response.contains("nonce"));
	EXPECT_TRUE(response.contains("price_mem"));
	EXPECT_TRUE(response.contains("price_step"));
	EXPECT_TRUE(response.contains("max_tx_ex_mem"));
	EXPECT_TRUE(response.contains("max_tx_ex_steps"));
	EXPECT_TRUE(response.contains("max_block_ex_mem"));
	EXPECT_TRUE(response.contains("max_block_ex_steps"));
	EXPECT_TRUE(response.contains("max_val_size"));
	EXPECT_TRUE(response.contains("collateral_percent"));
	EXPECT_TRUE(response.contains("max_collateral_inputs"));
	EXPECT_TRUE(response.contains("coins_per_utxo_size"));
	EXPECT_TRUE(response.contains("coins_per_utxo_word"));
	EXPECT_TRUE(response.contains("cost_models"));
}

TEST(EpochsTest, ReturnsEpoch) {
	BlockFrostClient client(API_KEY);
	
	// Call health to ensure API is ready
	client.health();
	
	auto response = client.epoch(EPOCH_NUMBER);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("epoch"));
	EXPECT_TRUE(response.contains("start_time"));
	EXPECT_TRUE(response.contains("end_time"));
	EXPECT_TRUE(response.contains("first_block_time"));
	EXPECT_TRUE(response.contains("last_block_time"));
	EXPECT_TRUE(response.contains("block_count"));
	EXPECT_TRUE(response.contains("tx_count"));
	EXPECT_TRUE(response.contains("output"));
	EXPECT_TRUE(response.contains("fees"));
	EXPECT_TRUE(response.contains("active_stake"));
}

TEST(EpochsTest, ReturnsEpochNext) {
	BlockFrostClient client(API_KEY);
	
	// Call health to ensure API is ready
	client.health();
	
	auto response = client.epoch_next(EPOCH_NUMBER, 10, 1);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("epoch"));
		EXPECT_TRUE(first.contains("start_time"));
		EXPECT_TRUE(first.contains("end_time"));
		EXPECT_TRUE(first.contains("first_block_time"));
		EXPECT_TRUE(first.contains("last_block_time"));
		EXPECT_TRUE(first.contains("block_count"));
		EXPECT_TRUE(first.contains("tx_count"));
		EXPECT_TRUE(first.contains("output"));
		EXPECT_TRUE(first.contains("fees"));
		EXPECT_TRUE(first.contains("active_stake"));
	}
}

TEST(EpochsTest, ReturnsEpochPrevious) {
	BlockFrostClient client(API_KEY);
	
	// Call health to ensure API is ready
	client.health();
	
	auto response = client.epoch_previous(EPOCH_NUMBER, 10, 1);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("epoch"));
		EXPECT_TRUE(first.contains("start_time"));
		EXPECT_TRUE(first.contains("end_time"));
		EXPECT_TRUE(first.contains("first_block_time"));
		EXPECT_TRUE(first.contains("last_block_time"));
		EXPECT_TRUE(first.contains("block_count"));
		EXPECT_TRUE(first.contains("tx_count"));
		EXPECT_TRUE(first.contains("output"));
		EXPECT_TRUE(first.contains("fees"));
		EXPECT_TRUE(first.contains("active_stake"));
	}
}

TEST(EpochsTest, ReturnsEpochStakes) {
	BlockFrostClient client(API_KEY);
	
	// Call health to ensure API is ready
	client.health();
	
	auto response = client.epoch_stakes(EPOCH_NUMBER, 10, 1);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("stake_address"));
		EXPECT_TRUE(first.contains("pool_id"));
		EXPECT_TRUE(first.contains("amount"));
	}
}

TEST(EpochsTest, ReturnsEpochStakesPool) {
	BlockFrostClient client(API_KEY);
	
	// Call health to ensure API is ready
	client.health();
	
	auto response = client.epoch_stakes_pool(EPOCH_NUMBER, POOL_ID, 10, 1);
	
	ASSERT_TRUE(response.is_array());
}

TEST(EpochsTest, ReturnsEpochBlocks) {
	BlockFrostClient client(API_KEY);
	
	// Call health to ensure API is ready
	client.health();
	
	auto response = client.epoch_blocks(EPOCH_NUMBER, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
}

TEST(EpochsTest, ReturnsEpochBlocksPool) {
	BlockFrostClient client(API_KEY);
	auto response = client.epoch_blocks_pool(EPOCH_NUMBER, POOL_ID, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("hash"));
		EXPECT_TRUE(first.contains("epoch"));
		EXPECT_TRUE(first.contains("slot"));
		EXPECT_TRUE(first.contains("height"));
	}
}

TEST(EpochsTest, ReturnsEpochParameters) {
	BlockFrostClient client(API_KEY);
	auto response = client.epoch_parameters(EPOCH_NUMBER);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("epoch"));
	EXPECT_TRUE(response.contains("min_fee_a"));
	EXPECT_TRUE(response.contains("min_fee_b"));
	EXPECT_TRUE(response.contains("max_block_size"));
	EXPECT_TRUE(response.contains("max_tx_size"));
	EXPECT_TRUE(response.contains("max_block_header_size"));
	EXPECT_TRUE(response.contains("key_deposit"));
	EXPECT_TRUE(response.contains("pool_deposit"));
	EXPECT_TRUE(response.contains("e_max"));
	EXPECT_TRUE(response.contains("n_opt"));
	EXPECT_TRUE(response.contains("a0"));
	EXPECT_TRUE(response.contains("rho"));
	EXPECT_TRUE(response.contains("tau"));
	EXPECT_TRUE(response.contains("decentralisation_param"));
	EXPECT_TRUE(response.contains("extra_entropy"));
	EXPECT_TRUE(response.contains("protocol_major_ver"));
	EXPECT_TRUE(response.contains("protocol_minor_ver"));
	EXPECT_TRUE(response.contains("min_utxo"));
	EXPECT_TRUE(response.contains("min_pool_cost"));
	EXPECT_TRUE(response.contains("nonce"));
	EXPECT_TRUE(response.contains("price_mem"));
	EXPECT_TRUE(response.contains("price_step"));
	EXPECT_TRUE(response.contains("max_tx_ex_mem"));
	EXPECT_TRUE(response.contains("max_tx_ex_steps"));
	EXPECT_TRUE(response.contains("max_block_ex_mem"));
	EXPECT_TRUE(response.contains("max_block_ex_steps"));
	EXPECT_TRUE(response.contains("max_val_size"));
	EXPECT_TRUE(response.contains("collateral_percent"));
	EXPECT_TRUE(response.contains("max_collateral_inputs"));
	EXPECT_TRUE(response.contains("coins_per_utxo_size"));
	EXPECT_TRUE(response.contains("coins_per_utxo_word"));
	EXPECT_TRUE(response.contains("cost_models"));
}
