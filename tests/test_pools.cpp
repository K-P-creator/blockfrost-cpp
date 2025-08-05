#include "../include/BlockFrostClient.hpp"
#include "test_constants.h"
#include <gtest/gtest.h>

TEST(PoolsTest, ReturnsPools) {
	BlockFrostClient client(API_KEY);
	auto response = client.pools(10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		EXPECT_TRUE(response[0].is_string());
	}
}

TEST(PoolsTest, ReturnsPoolsExtended) {
	BlockFrostClient client(API_KEY);
	auto response = client.pools_extended(10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("pool_id"));
		EXPECT_TRUE(first.contains("hex"));
		EXPECT_TRUE(first.contains("active_stake"));
		EXPECT_TRUE(first.contains("blocks_minted"));
		EXPECT_TRUE(first.contains("live_stake"));
	}
}

TEST(PoolsTest, ReturnsPoolsRetired) {
	BlockFrostClient client(API_KEY);
	auto response = client.pools_retired(10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("pool_id"));
		EXPECT_TRUE(first.contains("epoch"));
	}
}

TEST(PoolsTest, ReturnsPoolsRetiring) {
	BlockFrostClient client(API_KEY);
	auto response = client.pools_retiring(10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("pool_id"));
		EXPECT_TRUE(first["epoch"].is_string());
	}
}

TEST(PoolsTest, ReturnsPool) {
	BlockFrostClient client(API_KEY);
	auto response = client.pool(POOL_ID);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("pool_id"));
	EXPECT_TRUE(response.contains("hex"));
	EXPECT_TRUE(response.contains("vrf_key"));
	EXPECT_TRUE(response.contains("active_stake"));
	EXPECT_TRUE(response.contains("live_stake"));
}

TEST(PoolsTest, ReturnsPoolHistory) {
	BlockFrostClient client(API_KEY);
	auto response = client.pool_history(POOL_ID);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("epoch"));
		EXPECT_TRUE(first.contains("blocks"));
		EXPECT_TRUE(first["blocks"].is_number_integer());
		EXPECT_TRUE(first["active_stake"].is_string());
		EXPECT_TRUE(first["active_size"].is_number());
		EXPECT_TRUE(first["delegators_count"].is_number_integer());
		EXPECT_TRUE(first["rewards"].is_string());
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
		EXPECT_TRUE(first.contains("live_stake"));
	}
}

TEST(PoolsTest, ReturnsPoolBlocks) {
	BlockFrostClient client(API_KEY);
	auto response = client.pool_blocks(POOL_ID, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		EXPECT_TRUE(response[0].is_string());
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
