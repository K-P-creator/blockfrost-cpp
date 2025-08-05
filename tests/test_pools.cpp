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
		EXPECT_TRUE(first.contains("epoch"));
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
	}
}

TEST(PoolsTest, ReturnsPoolMetadata) {
	BlockFrostClient client(API_KEY);
	auto response = client.pool_metadata(POOL_ID);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("pool_id"));
	EXPECT_TRUE(response.contains("hex"));
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
		EXPECT_TRUE(first.contains("cert_index"));
		EXPECT_TRUE(first.contains("action"));
	}
}

TEST(PoolsTest, ReturnsPoolVotes) {
	BlockFrostClient client(API_KEY);
	/*
	NEEDS FIX

	auto response = client.pool_votes(BECH32_ADDR, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("tx_hash"));
		EXPECT_TRUE(first.contains("cert_index"));
		EXPECT_TRUE(first.contains("vote"));
	}
		*/
}
