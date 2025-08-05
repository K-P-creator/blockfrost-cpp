#include "../include/BlockFrostClient.hpp"
#include "test_constants.h"
#include <gtest/gtest.h>

TEST(ScriptsTest, ReturnsScripts) {
	BlockFrostClient client(API_KEY);
	auto response = client.scripts(10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("script_hash"));
	}
}

TEST(ScriptsTest, ReturnsScript) {
	BlockFrostClient client(API_KEY);
	auto response = client.script(SCRIPT_HASH);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("script_hash"));
}

TEST(ScriptsTest, ReturnsScriptJson) {
	BlockFrostClient client(API_KEY);
	auto response = client.script_json(SCRIPT_HASH);
	
	ASSERT_TRUE(response.is_object());
	if (!response.empty()){
		EXPECT_TRUE(response.contains("json"));
	}
}

TEST(ScriptsTest, ReturnsScriptCbor) {
	BlockFrostClient client(API_KEY);
	auto response = client.script_cbor(SCRIPT_HASH);
	
	ASSERT_TRUE(response.is_object());
	if (!response.empty()){
		EXPECT_TRUE(response.contains("cbor"));
	}
}

TEST(ScriptsTest, ReturnsScriptRedeemers) {
	BlockFrostClient client(API_KEY);
	auto response = client.script_redeemers(SCRIPT_HASH);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("tx_hash"));
		EXPECT_TRUE(first.contains("tx_index"));
		EXPECT_TRUE(first.contains("purpose"));
	}
}

TEST(ScriptsTest, ReturnsScriptDatum) {
	BlockFrostClient client(API_KEY);
	/*
	NEEDS FIX

	auto response = client.script_datum(DATUM_HASH);
	
	ASSERT_TRUE(response.is_object());
	if (!response.empty()){
		EXPECT_TRUE(response.contains("json_value"));
	}
		*/
}

TEST(ScriptsTest, ReturnsScriptDatumCbor) {
	BlockFrostClient client(API_KEY);
	auto response = client.script_datum_cbor(DATUM_HASH);
	
	ASSERT_TRUE(response.is_object());
	if (!response.empty()){
		EXPECT_TRUE(response.contains("cbor"));
	}
}
