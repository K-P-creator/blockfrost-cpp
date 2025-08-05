#include "../include/BlockFrostClient.hpp"
#include "test_constants.h"
#include <gtest/gtest.h>

TEST(AccountsTest, ReturnsAccount) {
	BlockFrostClient client(API_KEY);
	auto response = client.accounts(STAKE_ADDR);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("stake_address"));
	EXPECT_TRUE(response.contains("active"));
	EXPECT_TRUE(response.contains("active_epoch"));
	EXPECT_TRUE(response.contains("controlled_amount"));
	EXPECT_TRUE(response.contains("rewards_sum"));
	EXPECT_TRUE(response.contains("withdrawals_sum"));
	EXPECT_TRUE(response.contains("reserves_sum"));
	EXPECT_TRUE(response.contains("treasury_sum"));
	EXPECT_TRUE(response.contains("withdrawable_amount"));
	EXPECT_TRUE(response.contains("pool_id"));
}

TEST(AccountsTest, ReturnsAccountRewards) {
	BlockFrostClient client(API_KEY);
	auto response = client.account_rewards(STAKE_ADDR, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("epoch"));
		EXPECT_TRUE(first.contains("amount"));
		EXPECT_TRUE(first.contains("pool_id"));
		EXPECT_TRUE(first.contains("type"));
	}
}

TEST(AccountsTest, ReturnsAccountHistory) {
	BlockFrostClient client(API_KEY);
	auto response = client.account_history(STAKE_ADDR, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("active_epoch"));
		EXPECT_TRUE(first.contains("amount"));
		EXPECT_TRUE(first.contains("pool_id"));
	}
}

TEST(AccountsTest, ReturnsAccountDelegations) {
	BlockFrostClient client(API_KEY);
	auto response = client.account_delegations(STAKE_ADDR, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("active_epoch"));
		EXPECT_TRUE(first.contains("tx_hash"));
		EXPECT_TRUE(first.contains("amount"));
		EXPECT_TRUE(first.contains("pool_id"));
	}
}

TEST(AccountsTest, ReturnsAccountRegistrations) {
	BlockFrostClient client(API_KEY);
	auto response = client.account_registrations(STAKE_ADDR, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("tx_hash"));
		EXPECT_TRUE(first.contains("action"));
	}
}

TEST(AccountsTest, ReturnsAccountWithdrawals) {
	BlockFrostClient client(API_KEY);
	auto response = client.account_withdrawals(STAKE_ADDR, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("tx_hash"));
		EXPECT_TRUE(first.contains("amount"));
	}
}

TEST(AccountsTest, ReturnsAccountMirs) {
	BlockFrostClient client(API_KEY);
	auto response = client.account_mirs(STAKE_ADDR, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("tx_hash"));
		EXPECT_TRUE(first.contains("amount"));
	}
}

TEST(AccountsTest, ReturnsAccountAddresses) {
	BlockFrostClient client(API_KEY);
	auto response = client.account_addresses(STAKE_ADDR, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("address"));
	}
}

TEST(AccountsTest, ReturnsAccountAddressesAssets) {
	BlockFrostClient client(API_KEY);
	auto response = client.account_addresses_assets(STAKE_ADDR, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("address"));
		EXPECT_TRUE(first.contains("tx_count"));
	}
}

TEST(AccountsTest, ReturnsAccountAddressesTotal) {
	BlockFrostClient client(API_KEY);
	auto response = client.account_addresses_total(STAKE_ADDR);
	
	ASSERT_TRUE(response.is_object());
	if (!response.empty()){
		EXPECT_TRUE(response.contains("stake_address"));
	}
}

TEST(AccountsTest, ReturnsAccountUtxos) {
	BlockFrostClient client(API_KEY);
	auto response = client.account_utxos(STAKE_ADDR, 10, 1, "asc");
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("address"));
		EXPECT_TRUE(first.contains("tx_hash"));
		EXPECT_TRUE(first.contains("output_index"));
	}
}