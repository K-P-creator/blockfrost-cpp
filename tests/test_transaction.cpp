#include "../include/BlockFrostClient.hpp"
#include "test_constants.h"
#include <gtest/gtest.h>

TEST(TransactionTest, ReturnsTransaction) {
	BlockFrostClient client(API_KEY);
	auto response = client.transaction(TX_HASH);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("hash"));
	EXPECT_TRUE(response["hash"].is_string());
	EXPECT_TRUE(response.contains("block"));
	EXPECT_TRUE(response["block"].is_string());
	EXPECT_TRUE(response.contains("block_height"));
	EXPECT_TRUE(response["block_height"].is_number_integer());
	EXPECT_TRUE(response.contains("block_time"));
	EXPECT_TRUE(response["block_time"].is_number_integer());
	EXPECT_TRUE(response.contains("slot"));
	EXPECT_TRUE(response["slot"].is_number_integer());
	EXPECT_TRUE(response.contains("index"));
	EXPECT_TRUE(response["index"].is_number_integer());
	EXPECT_TRUE(response.contains("output_amount"));
	EXPECT_TRUE(response["output_amount"].is_array());
	EXPECT_TRUE(response.contains("fees"));
	EXPECT_TRUE(response["fees"].is_string());
	EXPECT_TRUE(response.contains("deposit"));
	EXPECT_TRUE(response["deposit"].is_string());
	EXPECT_TRUE(response.contains("size"));
	EXPECT_TRUE(response["size"].is_number_integer());
	EXPECT_TRUE(response.contains("invalid_before"));
	EXPECT_TRUE(response.contains("invalid_hereafter"));
	EXPECT_TRUE(response.contains("utxo_count"));
	EXPECT_TRUE(response["utxo_count"].is_number_integer());
	EXPECT_TRUE(response.contains("withdrawal_count"));
	EXPECT_TRUE(response["withdrawal_count"].is_number_integer());
	EXPECT_TRUE(response.contains("mir_cert_count"));
	EXPECT_TRUE(response["mir_cert_count"].is_number_integer());
	EXPECT_TRUE(response.contains("delegation_count"));
	EXPECT_TRUE(response["delegation_count"].is_number_integer());
	EXPECT_TRUE(response.contains("stake_cert_count"));
	EXPECT_TRUE(response["stake_cert_count"].is_number_integer());
	EXPECT_TRUE(response.contains("pool_update_count"));
	EXPECT_TRUE(response["pool_update_count"].is_number_integer());
	EXPECT_TRUE(response.contains("pool_retire_count"));
	EXPECT_TRUE(response["pool_retire_count"].is_number_integer());
	EXPECT_TRUE(response.contains("asset_mint_or_burn_count"));
	EXPECT_TRUE(response["asset_mint_or_burn_count"].is_number_integer());
	EXPECT_TRUE(response.contains("redeemer_count"));
	EXPECT_TRUE(response["redeemer_count"].is_number_integer());
	EXPECT_TRUE(response.contains("valid_contract"));
	EXPECT_TRUE(response["valid_contract"].is_boolean());
}

TEST(TransactionTest, ReturnsTransactionUtxos) {
	BlockFrostClient client(API_KEY);
	auto response = client.transaction_utxos(TX_HASH);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("hash"));
	EXPECT_TRUE(response["hash"].is_string());
	EXPECT_TRUE(response.contains("inputs"));
	EXPECT_TRUE(response["inputs"].is_array());
	EXPECT_TRUE(response.contains("outputs"));
	EXPECT_TRUE(response["outputs"].is_array());
}

TEST(TransactionTest, ReturnsTransactionStakes) {
	BlockFrostClient client(API_KEY);
	auto response = client.transaction_stakes(TX_HASH);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("cert_index"));
		EXPECT_TRUE(first["cert_index"].is_number_integer());
		EXPECT_TRUE(first.contains("address"));
		EXPECT_TRUE(first["address"].is_string());
		EXPECT_TRUE(first.contains("registration"));
		EXPECT_TRUE(first["registration"].is_boolean());
	}
}

TEST(TransactionTest, ReturnsTransactionDelegations) {
	BlockFrostClient client(API_KEY);
	auto response = client.transaction_delegations(TX_HASH);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("index"));
		EXPECT_TRUE(first["index"].is_number_integer());
		EXPECT_TRUE(first.contains("cert_index"));
		EXPECT_TRUE(first["cert_index"].is_number_integer());
		EXPECT_TRUE(first.contains("address"));
		EXPECT_TRUE(first["address"].is_string());
		EXPECT_TRUE(first.contains("pool_id"));
		EXPECT_TRUE(first["pool_id"].is_string());
		EXPECT_TRUE(first.contains("active_epoch"));
		EXPECT_TRUE(first["active_epoch"].is_number_integer());
	}
}

TEST(TransactionTest, ReturnsTransactionWithdrawals) {
	BlockFrostClient client(API_KEY);
	auto response = client.transaction_withdrawals(TX_HASH);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("address"));
		EXPECT_TRUE(first["address"].is_string());
		EXPECT_TRUE(first.contains("amount"));
		EXPECT_TRUE(first["amount"].is_string());
		EXPECT_TRUE(first.contains("tx_hash"));
		EXPECT_TRUE(first["tx_hash"].is_string());
	}
}

TEST(TransactionTest, ReturnsTransactionMirs) {
	BlockFrostClient client(API_KEY);
	auto response = client.transaction_mirs(TX_HASH);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("pot"));
		EXPECT_TRUE(first["pot"].is_string());
		EXPECT_TRUE(first.contains("cert_index"));
		EXPECT_TRUE(first["cert_index"].is_number_integer());
		EXPECT_TRUE(first.contains("address"));
		EXPECT_TRUE(first["address"].is_string());
		EXPECT_TRUE(first.contains("amount"));
		EXPECT_TRUE(first["amount"].is_string());
		EXPECT_TRUE(first.contains("tx_hash"));
		EXPECT_TRUE(first["tx_hash"].is_string());
	}
}

TEST(TransactionTest, ReturnsTransactionPoolUpdates) {
	BlockFrostClient client(API_KEY);
	auto response = client.transaction_pool_updates(TX_HASH);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("cert_index"));
		EXPECT_TRUE(first["cert_index"].is_number_integer());
		EXPECT_TRUE(first.contains("pool_id"));
		EXPECT_TRUE(first["pool_id"].is_string());
		EXPECT_TRUE(first.contains("vrf_key"));
		EXPECT_TRUE(first["vrf_key"].is_string());
		EXPECT_TRUE(first.contains("pledge"));
		EXPECT_TRUE(first["pledge"].is_string());
		EXPECT_TRUE(first.contains("margin_cost"));
		EXPECT_TRUE(first["margin_cost"].is_number());
		EXPECT_TRUE(first.contains("fixed_cost"));
		EXPECT_TRUE(first["fixed_cost"].is_string());
		EXPECT_TRUE(first.contains("reward_account"));
		EXPECT_TRUE(first["reward_account"].is_string());
		EXPECT_TRUE(first.contains("owners"));
		EXPECT_TRUE(first["owners"].is_array());
		EXPECT_TRUE(first.contains("relays"));
		EXPECT_TRUE(first["relays"].is_array());
		EXPECT_TRUE(first.contains("pool_metadata_hash"));
		EXPECT_TRUE(first.contains("pool_metadata_url"));
		EXPECT_TRUE(first.contains("pool_metadata_json"));
	}
}

TEST(TransactionTest, ReturnsTransactionPoolRetires) {
	BlockFrostClient client(API_KEY);
	auto response = client.transaction_pool_retires(TX_HASH);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("cert_index"));
		EXPECT_TRUE(first["cert_index"].is_number_integer());
		EXPECT_TRUE(first.contains("pool_id"));
		EXPECT_TRUE(first["pool_id"].is_string());
		EXPECT_TRUE(first.contains("retiring_epoch"));
		EXPECT_TRUE(first["retiring_epoch"].is_number_integer());
	}
}

TEST(TransactionTest, ReturnsTransactionMetadata) {
	BlockFrostClient client(API_KEY);
	auto response = client.transaction_metadata(TX_HASH);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("label"));
		EXPECT_TRUE(first["label"].is_string());
		EXPECT_TRUE(first.contains("json_metadata"));
		EXPECT_TRUE(first["json_metadata"].is_object());
	}
}

TEST(TransactionTest, ReturnsTransactionMetadataCbor) {
	BlockFrostClient client(API_KEY);
	auto response = client.transaction_metadata_cbor(TX_HASH);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("label"));
		EXPECT_TRUE(first["label"].is_string());
		EXPECT_TRUE(first.contains("cbor_metadata"));
		EXPECT_TRUE(first["cbor_metadata"].is_string());
	}
}

TEST(TransactionTest, ReturnsTransactionRedeemers) {
	BlockFrostClient client(API_KEY);
	auto response = client.transaction_redeemers(TX_HASH);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("tx_index"));
		EXPECT_TRUE(first["tx_index"].is_number_integer());
		EXPECT_TRUE(first.contains("purpose"));
		EXPECT_TRUE(first["purpose"].is_string());
		EXPECT_TRUE(first.contains("script_hash"));
		EXPECT_TRUE(first["script_hash"].is_string());
		EXPECT_TRUE(first.contains("datum_hash"));
		EXPECT_TRUE(first["datum_hash"].is_string());
		EXPECT_TRUE(first.contains("datum_value"));
		EXPECT_TRUE(first.contains("unit_mem"));
		EXPECT_TRUE(first["unit_mem"].is_string());
		EXPECT_TRUE(first.contains("unit_steps"));
		EXPECT_TRUE(first["unit_steps"].is_string());
		EXPECT_TRUE(first.contains("fee"));
		EXPECT_TRUE(first["fee"].is_string());
	}
}

TEST(TransactionTest, ReturnsTransactionRequiredSigners) {
	BlockFrostClient client(API_KEY);
	auto response = client.transaction_required_signers(TX_HASH);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("hash"));
		EXPECT_TRUE(first["hash"].is_string());
	}
}

TEST(TransactionTest, ReturnsTransactionCbor) {
	BlockFrostClient client(API_KEY);
	auto response = client.transaction_cbor(TX_HASH);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("hash"));
	EXPECT_TRUE(response["hash"].is_string());
	EXPECT_TRUE(response.contains("cbor"));
	EXPECT_TRUE(response["cbor"].is_string());
}
