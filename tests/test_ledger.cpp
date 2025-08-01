#include "../include/BlockFrostClient.hpp"
#include "test_constants.h"
#include <gtest/gtest.h>

TEST(LedgerTest, ReturnsGenesis) {
	BlockFrostClient client(API_KEY);
	auto response = client.genesis();
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("active_slots_coefficient"));
	EXPECT_TRUE(response["active_slots_coefficient"].is_number());
	EXPECT_TRUE(response.contains("update_quorum"));
	EXPECT_TRUE(response["update_quorum"].is_number_integer());
	EXPECT_TRUE(response.contains("max_lovelace_supply"));
	EXPECT_TRUE(response["max_lovelace_supply"].is_string());
	EXPECT_TRUE(response.contains("network_magic"));
	EXPECT_TRUE(response["network_magic"].is_number_integer());
	EXPECT_TRUE(response.contains("epoch_length"));
	EXPECT_TRUE(response["epoch_length"].is_number_integer());
	EXPECT_TRUE(response.contains("system_start"));
	EXPECT_TRUE(response["system_start"].is_string());
	EXPECT_TRUE(response.contains("slots_per_kes_period"));
	EXPECT_TRUE(response["slots_per_kes_period"].is_number_integer());
	EXPECT_TRUE(response.contains("slot_length"));
	EXPECT_TRUE(response["slot_length"].is_number_integer());
	EXPECT_TRUE(response.contains("max_kes_evolutions"));
	EXPECT_TRUE(response["max_kes_evolutions"].is_number_integer());
	EXPECT_TRUE(response.contains("security_param"));
	EXPECT_TRUE(response["security_param"].is_number_integer());
	EXPECT_TRUE(response.contains("alo_go"));
	EXPECT_TRUE(response["alo_go"].is_object());
	EXPECT_TRUE(response.contains("shelley_creds"));
	EXPECT_TRUE(response["shelley_creds"].is_object());
	EXPECT_TRUE(response.contains("goguen_creds"));
	EXPECT_TRUE(response["goguen_creds"].is_object());
}
