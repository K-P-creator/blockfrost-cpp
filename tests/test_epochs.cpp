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
	EXPECT_TRUE(response["epoch"].is_number_integer());
	EXPECT_TRUE(response.contains("start_time"));
	EXPECT_TRUE(response["start_time"].is_number_integer());
	EXPECT_TRUE(response.contains("end_time"));
	EXPECT_TRUE(response["end_time"].is_number_integer());
	EXPECT_TRUE(response.contains("first_block_time"));
	EXPECT_TRUE(response["first_block_time"].is_number_integer());
	EXPECT_TRUE(response.contains("last_block_time"));
	EXPECT_TRUE(response["last_block_time"].is_number_integer());
	EXPECT_TRUE(response.contains("block_count"));
	EXPECT_TRUE(response["block_count"].is_number_integer());
	EXPECT_TRUE(response.contains("tx_count"));
	EXPECT_TRUE(response["tx_count"].is_number_integer());
	EXPECT_TRUE(response.contains("output"));
	EXPECT_TRUE(response["output"].is_string());
	EXPECT_TRUE(response.contains("fees"));
	EXPECT_TRUE(response["fees"].is_string());
	EXPECT_TRUE(response.contains("active_stake"));
	EXPECT_TRUE(response["active_stake"].is_string());
}

TEST(EpochsTest, ReturnsEpochsLatestParameters) {
	BlockFrostClient client(API_KEY);
	
	// Call health to ensure API is ready
	client.health();
	
	auto response = client.epochs_latest_parameters();
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("epoch"));
	EXPECT_TRUE(response["epoch"].is_number_integer());
	EXPECT_TRUE(response.contains("min_fee_a"));
	EXPECT_TRUE(response["min_fee_a"].is_number_integer());
	EXPECT_TRUE(response.contains("min_fee_b"));
	EXPECT_TRUE(response["min_fee_b"].is_number_integer());
	EXPECT_TRUE(response.contains("max_block_size"));
	EXPECT_TRUE(response["max_block_size"].is_number_integer());
	EXPECT_TRUE(response.contains("max_tx_size"));
	EXPECT_TRUE(response["max_tx_size"].is_number_integer());
	EXPECT_TRUE(response.contains("max_bh_size"));
	EXPECT_TRUE(response["max_bh_size"].is_number_integer());
	EXPECT_TRUE(response.contains("key_deposit"));
	EXPECT_TRUE(response["key_deposit"].is_string());
	EXPECT_TRUE(response.contains("pool_deposit"));
	EXPECT_TRUE(response["pool_deposit"].is_string());
	EXPECT_TRUE(response.contains("e_max"));
	EXPECT_TRUE(response["e_max"].is_number_integer());
	EXPECT_TRUE(response.contains("n_opt"));
	EXPECT_TRUE(response["n_opt"].is_number_integer());
	EXPECT_TRUE(response.contains("a0"));
	EXPECT_TRUE(response["a0"].is_number());
	EXPECT_TRUE(response.contains("rho"));
	EXPECT_TRUE(response["rho"].is_number());
	EXPECT_TRUE(response.contains("tau"));
	EXPECT_TRUE(response["tau"].is_number());
	EXPECT_TRUE(response.contains("decentralisation_param"));
	EXPECT_TRUE(response["decentralisation_param"].is_number());
	EXPECT_TRUE(response.contains("extra_entropy"));
	EXPECT_TRUE(response["extra_entropy"].is_string());
	EXPECT_TRUE(response.contains("protocol_major_ver"));
	EXPECT_TRUE(response["protocol_major_ver"].is_number_integer());
	EXPECT_TRUE(response.contains("protocol_minor_ver"));
	EXPECT_TRUE(response["protocol_minor_ver"].is_number_integer());
	EXPECT_TRUE(response.contains("min_utxo"));
	EXPECT_TRUE(response["min_utxo"].is_string());
	EXPECT_TRUE(response.contains("min_pool_cost"));
	EXPECT_TRUE(response["min_pool_cost"].is_string());
	EXPECT_TRUE(response.contains("nonce"));
	EXPECT_TRUE(response["nonce"].is_string());
	EXPECT_TRUE(response.contains("price_mem"));
	EXPECT_TRUE(response["price_mem"].is_number());
	EXPECT_TRUE(response.contains("price_step"));
	EXPECT_TRUE(response["price_step"].is_number());
	EXPECT_TRUE(response.contains("max_tx_ex_mem"));
	EXPECT_TRUE(response["max_tx_ex_mem"].is_string());
	EXPECT_TRUE(response.contains("max_tx_ex_steps"));
	EXPECT_TRUE(response["max_tx_ex_steps"].is_string());
	EXPECT_TRUE(response.contains("max_block_ex_mem"));
	EXPECT_TRUE(response["max_block_ex_mem"].is_string());
	EXPECT_TRUE(response.contains("max_block_ex_steps"));
	EXPECT_TRUE(response["max_block_ex_steps"].is_string());
	EXPECT_TRUE(response.contains("max_val_size"));
	EXPECT_TRUE(response["max_val_size"].is_string());
	EXPECT_TRUE(response.contains("collateral_percent"));
	EXPECT_TRUE(response["collateral_percent"].is_number_integer());
	EXPECT_TRUE(response.contains("max_collateral_inputs"));
	EXPECT_TRUE(response["max_collateral_inputs"].is_number_integer());
	EXPECT_TRUE(response.contains("coins_per_utxo_size"));
	EXPECT_TRUE(response["coins_per_utxo_size"].is_string());
	EXPECT_TRUE(response.contains("coins_per_utxo_word"));
	EXPECT_TRUE(response["coins_per_utxo_word"].is_string());
	EXPECT_TRUE(response.contains("cost_models"));
	EXPECT_TRUE(response["cost_models"].is_object());
}

TEST(EpochsTest, ReturnsEpoch) {
	BlockFrostClient client(API_KEY);
	
	// Call health to ensure API is ready
	client.health();
	
	auto response = client.epoch(EPOCH_NUMBER);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("epoch"));
	EXPECT_TRUE(response["epoch"].is_number_integer());
	EXPECT_TRUE(response.contains("start_time"));
	EXPECT_TRUE(response["start_time"].is_number_integer());
	EXPECT_TRUE(response.contains("end_time"));
	EXPECT_TRUE(response["end_time"].is_number_integer());
	EXPECT_TRUE(response.contains("first_block_time"));
	EXPECT_TRUE(response["first_block_time"].is_number_integer());
	EXPECT_TRUE(response.contains("last_block_time"));
	EXPECT_TRUE(response["last_block_time"].is_number_integer());
	EXPECT_TRUE(response.contains("block_count"));
	EXPECT_TRUE(response["block_count"].is_number_integer());
	EXPECT_TRUE(response.contains("tx_count"));
	EXPECT_TRUE(response["tx_count"].is_number_integer());
	EXPECT_TRUE(response.contains("output"));
	EXPECT_TRUE(response["output"].is_string());
	EXPECT_TRUE(response.contains("fees"));
	EXPECT_TRUE(response["fees"].is_string());
	EXPECT_TRUE(response.contains("active_stake"));
	EXPECT_TRUE(response["active_stake"].is_string());
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
		EXPECT_TRUE(first["epoch"].is_number_integer());
		EXPECT_TRUE(first.contains("start_time"));
		EXPECT_TRUE(first["start_time"].is_number_integer());
		EXPECT_TRUE(first.contains("end_time"));
		EXPECT_TRUE(first["end_time"].is_number_integer());
		EXPECT_TRUE(first.contains("first_block_time"));
		EXPECT_TRUE(first["first_block_time"].is_number_integer());
		EXPECT_TRUE(first.contains("last_block_time"));
		EXPECT_TRUE(first["last_block_time"].is_number_integer());
		EXPECT_TRUE(first.contains("block_count"));
		EXPECT_TRUE(first["block_count"].is_number_integer());
		EXPECT_TRUE(first.contains("tx_count"));
		EXPECT_TRUE(first["tx_count"].is_number_integer());
		EXPECT_TRUE(first.contains("output"));
		EXPECT_TRUE(first["output"].is_string());
		EXPECT_TRUE(first.contains("fees"));
		EXPECT_TRUE(first["fees"].is_string());
		EXPECT_TRUE(first.contains("active_stake"));
		EXPECT_TRUE(first["active_stake"].is_string());
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
		EXPECT_TRUE(first["epoch"].is_number_integer());
		EXPECT_TRUE(first.contains("start_time"));
		EXPECT_TRUE(first["start_time"].is_number_integer());
		EXPECT_TRUE(first.contains("end_time"));
		EXPECT_TRUE(first["end_time"].is_number_integer());
		EXPECT_TRUE(first.contains("first_block_time"));
		EXPECT_TRUE(first["first_block_time"].is_number_integer());
		EXPECT_TRUE(first.contains("last_block_time"));
		EXPECT_TRUE(first["last_block_time"].is_number_integer());
		EXPECT_TRUE(first.contains("block_count"));
		EXPECT_TRUE(first["block_count"].is_number_integer());
		EXPECT_TRUE(first.contains("tx_count"));
		EXPECT_TRUE(first["tx_count"].is_number_integer());
		EXPECT_TRUE(first.contains("output"));
		EXPECT_TRUE(first["output"].is_string());
		EXPECT_TRUE(first.contains("fees"));
		EXPECT_TRUE(first["fees"].is_string());
		EXPECT_TRUE(first.contains("active_stake"));
		EXPECT_TRUE(first["active_stake"].is_string());
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
		EXPECT_TRUE(first["stake_address"].is_string());
		EXPECT_TRUE(first.contains("pool_id"));
		EXPECT_TRUE(first["pool_id"].is_string());
		EXPECT_TRUE(first.contains("amount"));
		EXPECT_TRUE(first["amount"].is_string());
	}
}

TEST(EpochsTest, ReturnsEpochStakesPool) {
	BlockFrostClient client(API_KEY);
	
	// Call health to ensure API is ready
	client.health();
	
	auto response = client.epoch_stakes_pool(EPOCH_NUMBER, POOL_ID, 10, 1);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("stake_address"));
		EXPECT_TRUE(first["stake_address"].is_string());
		EXPECT_TRUE(first.contains("pool_id"));
		EXPECT_TRUE(first["pool_id"].is_string());
		EXPECT_TRUE(first.contains("amount"));
		EXPECT_TRUE(first["amount"].is_string());
	}
}

TEST(EpochsTest, ReturnsEpochBlocks) {
	BlockFrostClient client(API_KEY);
	
	// Call health to ensure API is ready
	client.health();
	
	auto response = client.epoch_blocks(EPOCH_NUMBER, 10, 1, "asc");
	
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

TEST(EpochsTest, ReturnsEpochBlocksPool) {
	BlockFrostClient client(API_KEY);
	auto response = client.epoch_blocks_pool(EPOCH_NUMBER, POOL_ID, 10, 1, "asc");
	
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

TEST(EpochsTest, ReturnsEpochParameters) {
	BlockFrostClient client(API_KEY);
	auto response = client.epoch_parameters(EPOCH_NUMBER);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("epoch"));
	EXPECT_TRUE(response["epoch"].is_number_integer());
	EXPECT_TRUE(response.contains("min_fee_a"));
	EXPECT_TRUE(response["min_fee_a"].is_number_integer());
	EXPECT_TRUE(response.contains("min_fee_b"));
	EXPECT_TRUE(response["min_fee_b"].is_number_integer());
	EXPECT_TRUE(response.contains("max_block_size"));
	EXPECT_TRUE(response["max_block_size"].is_number_integer());
	EXPECT_TRUE(response.contains("max_tx_size"));
	EXPECT_TRUE(response["max_tx_size"].is_number_integer());
	EXPECT_TRUE(response.contains("max_bh_size"));
	EXPECT_TRUE(response["max_bh_size"].is_number_integer());
	EXPECT_TRUE(response.contains("key_deposit"));
	EXPECT_TRUE(response["key_deposit"].is_string());
	EXPECT_TRUE(response.contains("pool_deposit"));
	EXPECT_TRUE(response["pool_deposit"].is_string());
	EXPECT_TRUE(response.contains("e_max"));
	EXPECT_TRUE(response["e_max"].is_number_integer());
	EXPECT_TRUE(response.contains("n_opt"));
	EXPECT_TRUE(response["n_opt"].is_number_integer());
	EXPECT_TRUE(response.contains("a0"));
	EXPECT_TRUE(response["a0"].is_number());
	EXPECT_TRUE(response.contains("rho"));
	EXPECT_TRUE(response["rho"].is_number());
	EXPECT_TRUE(response.contains("tau"));
	EXPECT_TRUE(response["tau"].is_number());
	EXPECT_TRUE(response.contains("decentralisation_param"));
	EXPECT_TRUE(response["decentralisation_param"].is_number());
	EXPECT_TRUE(response.contains("extra_entropy"));
	EXPECT_TRUE(response["extra_entropy"].is_string());
	EXPECT_TRUE(response.contains("protocol_major_ver"));
	EXPECT_TRUE(response["protocol_major_ver"].is_number_integer());
	EXPECT_TRUE(response.contains("protocol_minor_ver"));
	EXPECT_TRUE(response["protocol_minor_ver"].is_number_integer());
	EXPECT_TRUE(response.contains("min_utxo"));
	EXPECT_TRUE(response["min_utxo"].is_string());
	EXPECT_TRUE(response.contains("min_pool_cost"));
	EXPECT_TRUE(response["min_pool_cost"].is_string());
	EXPECT_TRUE(response.contains("nonce"));
	EXPECT_TRUE(response["nonce"].is_string());
	EXPECT_TRUE(response.contains("price_mem"));
	EXPECT_TRUE(response["price_mem"].is_number());
	EXPECT_TRUE(response.contains("price_step"));
	EXPECT_TRUE(response["price_step"].is_number());
	EXPECT_TRUE(response.contains("max_tx_ex_mem"));
	EXPECT_TRUE(response["max_tx_ex_mem"].is_string());
	EXPECT_TRUE(response.contains("max_tx_ex_steps"));
	EXPECT_TRUE(response["max_tx_ex_steps"].is_string());
	EXPECT_TRUE(response.contains("max_block_ex_mem"));
	EXPECT_TRUE(response["max_block_ex_mem"].is_string());
	EXPECT_TRUE(response.contains("max_block_ex_steps"));
	EXPECT_TRUE(response["max_block_ex_steps"].is_string());
	EXPECT_TRUE(response.contains("max_val_size"));
	EXPECT_TRUE(response["max_val_size"].is_string());
	EXPECT_TRUE(response.contains("collateral_percent"));
	EXPECT_TRUE(response["collateral_percent"].is_number_integer());
	EXPECT_TRUE(response.contains("max_collateral_inputs"));
	EXPECT_TRUE(response["max_collateral_inputs"].is_number_integer());
	EXPECT_TRUE(response.contains("coins_per_utxo_size"));
	EXPECT_TRUE(response["coins_per_utxo_size"].is_string());
	EXPECT_TRUE(response.contains("coins_per_utxo_word"));
	EXPECT_TRUE(response["coins_per_utxo_word"].is_string());
	EXPECT_TRUE(response.contains("cost_models"));
	EXPECT_TRUE(response["cost_models"].is_object());
}
