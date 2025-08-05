#include "../include/BlockFrostClient.hpp"
#include "test_constants.h"
#include <gtest/gtest.h>

TEST(TransactionTest, ReturnsTransaction) {
	BlockFrostClient client(API_KEY);
	auto response = client.transaction(TX_HASH);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("hash"));
	EXPECT_TRUE(response.contains("block"));
	EXPECT_TRUE(response.contains("block_height"));
	EXPECT_TRUE(response.contains("block_time"));
	EXPECT_TRUE(response.contains("slot"));
	EXPECT_TRUE(response.contains("index"));
	EXPECT_TRUE(response.contains("output_amount"));
	EXPECT_TRUE(response.contains("fees"));
	EXPECT_TRUE(response.contains("deposit"));
	EXPECT_TRUE(response.contains("size"));
	EXPECT_TRUE(response.contains("invalid_before"));
	EXPECT_TRUE(response.contains("invalid_hereafter"));
	EXPECT_TRUE(response.contains("utxo_count"));
	EXPECT_TRUE(response.contains("withdrawal_count"));
	EXPECT_TRUE(response.contains("mir_cert_count"));
	EXPECT_TRUE(response.contains("delegation_count"));
	EXPECT_TRUE(response.contains("stake_cert_count"));
	EXPECT_TRUE(response.contains("pool_update_count"));
	EXPECT_TRUE(response.contains("pool_retire_count"));
	EXPECT_TRUE(response.contains("asset_mint_or_burn_count"));
	EXPECT_TRUE(response.contains("redeemer_count"));
}

TEST(TransactionTest, ReturnsTransactionUtxos) {
	BlockFrostClient client(API_KEY);
	auto response = client.transaction_utxos(TX_HASH);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("hash"));
	EXPECT_TRUE(response.contains("inputs"));
	EXPECT_TRUE(response.contains("outputs"));
}

TEST(TransactionTest, ReturnsTransactionStakes) {
	BlockFrostClient client(API_KEY);
	auto response = client.transaction_stakes(TX_HASH);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("cert_index"));
		EXPECT_TRUE(first.contains("address"));
		EXPECT_TRUE(first.contains("registration"));
	}
}

TEST(TransactionTest, ReturnsTransactionDelegations) {
	BlockFrostClient client(API_KEY);
	auto response = client.transaction_delegations(TX_HASH);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("index"));
		EXPECT_TRUE(first.contains("cert_index"));
		EXPECT_TRUE(first.contains("address"));
		EXPECT_TRUE(first.contains("pool_id"));
		EXPECT_TRUE(first.contains("active_epoch"));
	}
}

TEST(TransactionTest, ReturnsTransactionWithdrawals) {
	BlockFrostClient client(API_KEY);
	auto response = client.transaction_withdrawals(TX_HASH);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("address"));
		EXPECT_TRUE(first.contains("amount"));
		EXPECT_TRUE(first.contains("tx_hash"));
		EXPECT_TRUE(first.contains("cert_index"));
	}
}

TEST(TransactionTest, ReturnsTransactionMirs) {
	BlockFrostClient client(API_KEY);
	auto response = client.transaction_mirs(TX_HASH);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("pot"));
		EXPECT_TRUE(first.contains("cert_index"));
		EXPECT_TRUE(first.contains("address"));
		EXPECT_TRUE(first.contains("amount"));
		EXPECT_TRUE(first.contains("tx_hash"));
	}
}

TEST(TransactionTest, ReturnsTransactionPoolUpdates) {
	BlockFrostClient client(API_KEY);
	auto response = client.transaction_pool_updates(TX_HASH);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("cert_index"));
		EXPECT_TRUE(first.contains("pool_id"));
		EXPECT_TRUE(first.contains("vrf_key"));
		EXPECT_TRUE(first.contains("pledge"));
		EXPECT_TRUE(first.contains("margin_cost"));
		EXPECT_TRUE(first.contains("fixed_cost"));
		EXPECT_TRUE(first.contains("reward_account"));
		EXPECT_TRUE(first.contains("owners"));
		EXPECT_TRUE(first.contains("relays"));
		EXPECT_TRUE(first.contains("metadata"));
	}
}

TEST(TransactionTest, ReturnsTransactionPoolRetires) {
	BlockFrostClient client(API_KEY);
	auto response = client.transaction_pool_retires(TX_HASH);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("cert_index"));
		EXPECT_TRUE(first.contains("pool_id"));
		EXPECT_TRUE(first.contains("retiring_epoch"));
	}
}

TEST(TransactionTest, ReturnsTransactionMetadata) {
	BlockFrostClient client(API_KEY);
	auto response = client.transaction_metadata(TX_HASH);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("label"));
		EXPECT_TRUE(first.contains("json_metadata"));
	}
}

TEST(TransactionTest, ReturnsTransactionMetadataCbor) {
	BlockFrostClient client(API_KEY);
	auto response = client.transaction_metadata_cbor(TX_HASH);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("label"));
		EXPECT_TRUE(first.contains("cbor_metadata"));
	}
}

TEST(TransactionTest, ReturnsTransactionRedeemers) {
	BlockFrostClient client(API_KEY);
	auto response = client.transaction_redeemers(TX_HASH);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("tx_index"));
		EXPECT_TRUE(first.contains("purpose"));
		EXPECT_TRUE(first.contains("script_hash"));
		EXPECT_TRUE(first.contains("datum_hash"));
		EXPECT_TRUE(first.contains("redeemer_data_hash"));
		EXPECT_TRUE(first.contains("unit_mem"));
		EXPECT_TRUE(first.contains("unit_steps"));
		EXPECT_TRUE(first.contains("fee"));
	}
}

TEST(TransactionTest, ReturnsTransactionRequiredSigners) {
	BlockFrostClient client(API_KEY);
	auto response = client.transaction_required_signers(TX_HASH);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("hash"));
	}
}

TEST(TransactionTest, ReturnsTransactionCbor) {
	BlockFrostClient client(API_KEY);
	auto response = client.transaction_cbor(TX_HASH);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("cbor"));
}
