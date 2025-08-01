#include "../include/BlockFrostClient.hpp"
#include "test_constants.h"
#include <gtest/gtest.h>

TEST(PoolsTest, ReturnsPools) {
	BlockFrostClient client(API_KEY);
	auto response = client.pools(10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("pool_id"));
		EXPECT_TRUE(first["pool_id"].is_string());
		EXPECT_TRUE(first.contains("hex"));
		EXPECT_TRUE(first["hex"].is_string());
		EXPECT_TRUE(first.contains("vrf_key"));
		EXPECT_TRUE(first["vrf_key"].is_string());
		EXPECT_TRUE(first.contains("blocks_minted"));
		EXPECT_TRUE(first["blocks_minted"].is_number_integer());
		EXPECT_TRUE(first.contains("live_stake"));
		EXPECT_TRUE(first["live_stake"].is_string());
		EXPECT_TRUE(first.contains("live_size"));
		EXPECT_TRUE(first["live_size"].is_number());
		EXPECT_TRUE(first.contains("live_saturation"));
		EXPECT_TRUE(first["live_saturation"].is_number());
		EXPECT_TRUE(first.contains("live_delegators"));
		EXPECT_TRUE(first["live_delegators"].is_number_integer());
		EXPECT_TRUE(first.contains("active_stake"));
		EXPECT_TRUE(first["active_stake"].is_string());
		EXPECT_TRUE(first.contains("active_size"));
		EXPECT_TRUE(first["active_size"].is_number());
		EXPECT_TRUE(first.contains("declared_pledge"));
		EXPECT_TRUE(first["declared_pledge"].is_string());
		EXPECT_TRUE(first.contains("live_pledge"));
		EXPECT_TRUE(first["live_pledge"].is_string());
		EXPECT_TRUE(first.contains("margin_cost"));
		EXPECT_TRUE(first["margin_cost"].is_number());
		EXPECT_TRUE(first.contains("fixed_cost"));
		EXPECT_TRUE(first["fixed_cost"].is_string());
		EXPECT_TRUE(first.contains("reward_account"));
		EXPECT_TRUE(first["reward_account"].is_string());
		EXPECT_TRUE(first.contains("owners"));
		EXPECT_TRUE(first["owners"].is_array());
		EXPECT_TRUE(first.contains("registration"));
		EXPECT_TRUE(first["registration"].is_array());
		EXPECT_TRUE(first.contains("retirement"));
		EXPECT_TRUE(first["retirement"].is_array());
	}
}

TEST(PoolsTest, ReturnsPoolsExtended) {
	BlockFrostClient client(API_KEY);
	auto response = client.pools_extended(10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("pool_id"));
		EXPECT_TRUE(first["pool_id"].is_string());
		EXPECT_TRUE(first.contains("hex"));
		EXPECT_TRUE(first["hex"].is_string());
		EXPECT_TRUE(first.contains("vrf_key"));
		EXPECT_TRUE(first["vrf_key"].is_string());
		EXPECT_TRUE(first.contains("blocks_minted"));
		EXPECT_TRUE(first["blocks_minted"].is_number_integer());
		EXPECT_TRUE(first.contains("live_stake"));
		EXPECT_TRUE(first["live_stake"].is_string());
		EXPECT_TRUE(first.contains("live_size"));
		EXPECT_TRUE(first["live_size"].is_number());
		EXPECT_TRUE(first.contains("live_saturation"));
		EXPECT_TRUE(first["live_saturation"].is_number());
		EXPECT_TRUE(first.contains("live_delegators"));
		EXPECT_TRUE(first["live_delegators"].is_number_integer());
		EXPECT_TRUE(first.contains("active_stake"));
		EXPECT_TRUE(first["active_stake"].is_string());
		EXPECT_TRUE(first.contains("active_size"));
		EXPECT_TRUE(first["active_size"].is_number());
		EXPECT_TRUE(first.contains("declared_pledge"));
		EXPECT_TRUE(first["declared_pledge"].is_string());
		EXPECT_TRUE(first.contains("live_pledge"));
		EXPECT_TRUE(first["live_pledge"].is_string());
		EXPECT_TRUE(first.contains("margin_cost"));
		EXPECT_TRUE(first["margin_cost"].is_number());
		EXPECT_TRUE(first.contains("fixed_cost"));
		EXPECT_TRUE(first["fixed_cost"].is_string());
		EXPECT_TRUE(first.contains("reward_account"));
		EXPECT_TRUE(first["reward_account"].is_string());
		EXPECT_TRUE(first.contains("owners"));
		EXPECT_TRUE(first["owners"].is_array());
		EXPECT_TRUE(first.contains("registration"));
		EXPECT_TRUE(first["registration"].is_array());
		EXPECT_TRUE(first.contains("retirement"));
		EXPECT_TRUE(first["retirement"].is_array());
		EXPECT_TRUE(first.contains("url"));
		EXPECT_TRUE(first.contains("hash"));
		EXPECT_TRUE(first.contains("ticker"));
		EXPECT_TRUE(first.contains("name"));
		EXPECT_TRUE(first.contains("description"));
		EXPECT_TRUE(first.contains("homepage"));
	}
}

TEST(PoolsTest, ReturnsPoolsRetired) {
	BlockFrostClient client(API_KEY);
	auto response = client.pools_retired(10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("pool_id"));
		EXPECT_TRUE(first["pool_id"].is_string());
		EXPECT_TRUE(first.contains("hex"));
		EXPECT_TRUE(first["hex"].is_string());
		EXPECT_TRUE(first.contains("vrf_key"));
		EXPECT_TRUE(first["vrf_key"].is_string());
		EXPECT_TRUE(first.contains("blocks_minted"));
		EXPECT_TRUE(first["blocks_minted"].is_number_integer());
		EXPECT_TRUE(first.contains("live_stake"));
		EXPECT_TRUE(first["live_stake"].is_string());
		EXPECT_TRUE(first.contains("live_size"));
		EXPECT_TRUE(first["live_size"].is_number());
		EXPECT_TRUE(first.contains("live_saturation"));
		EXPECT_TRUE(first["live_saturation"].is_number());
		EXPECT_TRUE(first.contains("live_delegators"));
		EXPECT_TRUE(first["live_delegators"].is_number_integer());
		EXPECT_TRUE(first.contains("active_stake"));
		EXPECT_TRUE(first["active_stake"].is_string());
		EXPECT_TRUE(first.contains("active_size"));
		EXPECT_TRUE(first["active_size"].is_number());
		EXPECT_TRUE(first.contains("declared_pledge"));
		EXPECT_TRUE(first["declared_pledge"].is_string());
		EXPECT_TRUE(first.contains("live_pledge"));
		EXPECT_TRUE(first["live_pledge"].is_string());
		EXPECT_TRUE(first.contains("margin_cost"));
		EXPECT_TRUE(first["margin_cost"].is_number());
		EXPECT_TRUE(first.contains("fixed_cost"));
		EXPECT_TRUE(first["fixed_cost"].is_string());
		EXPECT_TRUE(first.contains("reward_account"));
		EXPECT_TRUE(first["reward_account"].is_string());
		EXPECT_TRUE(first.contains("owners"));
		EXPECT_TRUE(first["owners"].is_array());
		EXPECT_TRUE(first.contains("registration"));
		EXPECT_TRUE(first["registration"].is_array());
		EXPECT_TRUE(first.contains("retirement"));
		EXPECT_TRUE(first["retirement"].is_array());
	}
}

TEST(PoolsTest, ReturnsPoolsRetiring) {
	BlockFrostClient client(API_KEY);
	auto response = client.pools_retiring(10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("pool_id"));
		EXPECT_TRUE(first["pool_id"].is_string());
		EXPECT_TRUE(first.contains("hex"));
		EXPECT_TRUE(first["hex"].is_string());
		EXPECT_TRUE(first.contains("vrf_key"));
		EXPECT_TRUE(first["vrf_key"].is_string());
		EXPECT_TRUE(first.contains("blocks_minted"));
		EXPECT_TRUE(first["blocks_minted"].is_number_integer());
		EXPECT_TRUE(first.contains("live_stake"));
		EXPECT_TRUE(first["live_stake"].is_string());
		EXPECT_TRUE(first.contains("live_size"));
		EXPECT_TRUE(first["live_size"].is_number());
		EXPECT_TRUE(first.contains("live_saturation"));
		EXPECT_TRUE(first["live_saturation"].is_number());
		EXPECT_TRUE(first.contains("live_delegators"));
		EXPECT_TRUE(first["live_delegators"].is_number_integer());
		EXPECT_TRUE(first.contains("active_stake"));
		EXPECT_TRUE(first["active_stake"].is_string());
		EXPECT_TRUE(first.contains("active_size"));
		EXPECT_TRUE(first["active_size"].is_number());
		EXPECT_TRUE(first.contains("declared_pledge"));
		EXPECT_TRUE(first["declared_pledge"].is_string());
		EXPECT_TRUE(first.contains("live_pledge"));
		EXPECT_TRUE(first["live_pledge"].is_string());
		EXPECT_TRUE(first.contains("margin_cost"));
		EXPECT_TRUE(first["margin_cost"].is_number());
		EXPECT_TRUE(first.contains("fixed_cost"));
		EXPECT_TRUE(first["fixed_cost"].is_string());
		EXPECT_TRUE(first.contains("reward_account"));
		EXPECT_TRUE(first["reward_account"].is_string());
		EXPECT_TRUE(first.contains("owners"));
		EXPECT_TRUE(first["owners"].is_array());
		EXPECT_TRUE(first.contains("registration"));
		EXPECT_TRUE(first["registration"].is_array());
		EXPECT_TRUE(first.contains("retirement"));
		EXPECT_TRUE(first["retirement"].is_array());
	}
}

TEST(PoolsTest, ReturnsPool) {
	BlockFrostClient client(API_KEY);
	auto response = client.pool(POOL_ID);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("pool_id"));
	EXPECT_TRUE(response["pool_id"].is_string());
	EXPECT_TRUE(response.contains("hex"));
	EXPECT_TRUE(response["hex"].is_string());
	EXPECT_TRUE(response.contains("vrf_key"));
	EXPECT_TRUE(response["vrf_key"].is_string());
	EXPECT_TRUE(response.contains("blocks_minted"));
	EXPECT_TRUE(response["blocks_minted"].is_number_integer());
	EXPECT_TRUE(response.contains("live_stake"));
	EXPECT_TRUE(response["live_stake"].is_string());
	EXPECT_TRUE(response.contains("live_size"));
	EXPECT_TRUE(response["live_size"].is_number());
	EXPECT_TRUE(response.contains("live_saturation"));
	EXPECT_TRUE(response["live_saturation"].is_number());
	EXPECT_TRUE(response.contains("live_delegators"));
	EXPECT_TRUE(response["live_delegators"].is_number_integer());
	EXPECT_TRUE(response.contains("active_stake"));
	EXPECT_TRUE(response["active_stake"].is_string());
	EXPECT_TRUE(response.contains("active_size"));
	EXPECT_TRUE(response["active_size"].is_number());
	EXPECT_TRUE(response.contains("declared_pledge"));
	EXPECT_TRUE(response["declared_pledge"].is_string());
	EXPECT_TRUE(response.contains("live_pledge"));
	EXPECT_TRUE(response["live_pledge"].is_string());
	EXPECT_TRUE(response.contains("margin_cost"));
	EXPECT_TRUE(response["margin_cost"].is_number());
	EXPECT_TRUE(response.contains("fixed_cost"));
	EXPECT_TRUE(response["fixed_cost"].is_string());
	EXPECT_TRUE(response.contains("reward_account"));
	EXPECT_TRUE(response["reward_account"].is_string());
	EXPECT_TRUE(response.contains("owners"));
	EXPECT_TRUE(response["owners"].is_array());
	EXPECT_TRUE(response.contains("registration"));
	EXPECT_TRUE(response["registration"].is_array());
	EXPECT_TRUE(response.contains("retirement"));
	EXPECT_TRUE(response["retirement"].is_array());
}

TEST(PoolsTest, ReturnsPoolHistory) {
	BlockFrostClient client(API_KEY);
	auto response = client.pool_history(POOL_ID);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("epoch"));
		EXPECT_TRUE(first["epoch"].is_number_integer());
		EXPECT_TRUE(first.contains("blocks"));
		EXPECT_TRUE(first["blocks"].is_number_integer());
		EXPECT_TRUE(first.contains("active_stake"));
		EXPECT_TRUE(first["active_stake"].is_string());
		EXPECT_TRUE(first.contains("active_size"));
		EXPECT_TRUE(first["active_size"].is_number());
		EXPECT_TRUE(first.contains("delegators_count"));
		EXPECT_TRUE(first["delegators_count"].is_number_integer());
		EXPECT_TRUE(first.contains("rewards"));
		EXPECT_TRUE(first["rewards"].is_string());
		EXPECT_TRUE(first.contains("fees"));
		EXPECT_TRUE(first["fees"].is_string());
	}
}

TEST(PoolsTest, ReturnsPoolMetadata) {
	BlockFrostClient client(API_KEY);
	auto response = client.pool_metadata(POOL_ID);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("pool_id"));
	EXPECT_TRUE(response["pool_id"].is_string());
	EXPECT_TRUE(response.contains("hex"));
	EXPECT_TRUE(response["hex"].is_string());
	EXPECT_TRUE(response.contains("url"));
	EXPECT_TRUE(response.contains("hash"));
	EXPECT_TRUE(response.contains("ticker"));
	EXPECT_TRUE(response.contains("name"));
	EXPECT_TRUE(response.contains("description"));
	EXPECT_TRUE(response.contains("homepage"));
}

TEST(PoolsTest, ReturnsPoolRelays) {
	BlockFrostClient client(API_KEY);
	auto response = client.pool_relays(POOL_ID);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("ipv4"));
		EXPECT_TRUE(first.contains("ipv6"));
		EXPECT_TRUE(first.contains("dns"));
		EXPECT_TRUE(first.contains("dns_srv"));
		EXPECT_TRUE(first.contains("port"));
		EXPECT_TRUE(first["port"].is_number_integer());
	}
}

TEST(PoolsTest, ReturnsPoolDelegators) {
	BlockFrostClient client(API_KEY);
	auto response = client.pool_delegators(POOL_ID, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("address"));
		EXPECT_TRUE(first["address"].is_string());
		EXPECT_TRUE(first.contains("tx_hash"));
		EXPECT_TRUE(first["tx_hash"].is_string());
		EXPECT_TRUE(first.contains("amount"));
		EXPECT_TRUE(first["amount"].is_string());
	}
}

TEST(PoolsTest, ReturnsPoolBlocks) {
	BlockFrostClient client(API_KEY);
	auto response = client.pool_blocks(POOL_ID, 10, 1, "asc");
	
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

TEST(PoolsTest, ReturnsPoolUpdates) {
	BlockFrostClient client(API_KEY);
	auto response = client.pool_updates(POOL_ID, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("tx_hash"));
		EXPECT_TRUE(first["tx_hash"].is_string());
		EXPECT_TRUE(first.contains("cert_index"));
		EXPECT_TRUE(first["cert_index"].is_number_integer());
		EXPECT_TRUE(first.contains("action"));
		EXPECT_TRUE(first["action"].is_string());
	}
}

TEST(PoolsTest, ReturnsPoolVotes) {
	BlockFrostClient client(API_KEY);
	auto response = client.pool_votes(POOL_ID, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("tx_hash"));
		EXPECT_TRUE(first["tx_hash"].is_string());
		EXPECT_TRUE(first.contains("cert_index"));
		EXPECT_TRUE(first["cert_index"].is_number_integer());
		EXPECT_TRUE(first.contains("gov_action_type"));
		EXPECT_TRUE(first["gov_action_type"].is_string());
		EXPECT_TRUE(first.contains("gov_action_index"));
		EXPECT_TRUE(first["gov_action_index"].is_number_integer());
		EXPECT_TRUE(first.contains("vote"));
		EXPECT_TRUE(first["vote"].is_string());
	}
}
