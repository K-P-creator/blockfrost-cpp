#include "../include/BlockFrostClient.hpp"
#include "test_constants.h"
#include <gtest/gtest.h>

TEST(LedgerTest, ReturnsGenesis) {
	BlockFrostClient client(API_KEY);
	auto response = client.genesis();
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("active_slots_coefficient"));
	EXPECT_TRUE(response.contains("update_quorum"));
	EXPECT_TRUE(response.contains("max_lovelace_supply"));
	EXPECT_TRUE(response.contains("network_magic"));
	EXPECT_TRUE(response.contains("epoch_length"));
	EXPECT_TRUE(response.contains("system_start"));
	EXPECT_TRUE(response.contains("slots_per_kes_period"));
	EXPECT_TRUE(response.contains("slot_length"));
	EXPECT_TRUE(response.contains("max_kes_evolutions"));
	EXPECT_TRUE(response.contains("security_param"));
}
