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
		EXPECT_TRUE(first["script_hash"].is_string());
		EXPECT_TRUE(first.contains("type"));
		EXPECT_TRUE(first["type"].is_string());
		EXPECT_TRUE(first.contains("serialised_size"));
		EXPECT_TRUE(first["serialised_size"].is_number_integer());
	}
}

TEST(ScriptsTest, ReturnsScript) {
	BlockFrostClient client(API_KEY);
	auto response = client.script(SCRIPT_HASH);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("script_hash"));
	EXPECT_TRUE(response["script_hash"].is_string());
	EXPECT_TRUE(response.contains("type"));
	EXPECT_TRUE(response["type"].is_string());
	EXPECT_TRUE(response.contains("serialised_size"));
	EXPECT_TRUE(response["serialised_size"].is_number_integer());
}

TEST(ScriptsTest, ReturnsScriptJson) {
	BlockFrostClient client(API_KEY);
	auto response = client.script_json(SCRIPT_HASH);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("script_hash"));
	EXPECT_TRUE(response["script_hash"].is_string());
	EXPECT_TRUE(response.contains("type"));
	EXPECT_TRUE(response["type"].is_string());
	EXPECT_TRUE(response.contains("json"));
	EXPECT_TRUE(response["json"].is_object());
}

TEST(ScriptsTest, ReturnsScriptCbor) {
	BlockFrostClient client(API_KEY);
	auto response = client.script_cbor(SCRIPT_HASH);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("script_hash"));
	EXPECT_TRUE(response["script_hash"].is_string());
	EXPECT_TRUE(response.contains("type"));
	EXPECT_TRUE(response["type"].is_string());
	EXPECT_TRUE(response.contains("cbor"));
	EXPECT_TRUE(response["cbor"].is_string());
}

TEST(ScriptsTest, ReturnsScriptRedeemers) {
	BlockFrostClient client(API_KEY);
	auto response = client.script_redeemers(SCRIPT_HASH);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("tx_hash"));
		EXPECT_TRUE(first["tx_hash"].is_string());
		EXPECT_TRUE(first.contains("tx_index"));
		EXPECT_TRUE(first["tx_index"].is_number_integer());
		EXPECT_TRUE(first.contains("purpose"));
		EXPECT_TRUE(first["purpose"].is_string());
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

TEST(ScriptsTest, ReturnsScriptDatum) {
	BlockFrostClient client(API_KEY);
	auto response = client.script_datum(DATUM_HASH);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("datum_hash"));
	EXPECT_TRUE(response["datum_hash"].is_string());
	EXPECT_TRUE(response.contains("json_value"));
	EXPECT_TRUE(response["json_value"].is_object());
}

TEST(ScriptsTest, ReturnsScriptDatumCbor) {
	BlockFrostClient client(API_KEY);
	auto response = client.script_datum_cbor(DATUM_HASH);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("datum_hash"));
	EXPECT_TRUE(response["datum_hash"].is_string());
	EXPECT_TRUE(response.contains("cbor"));
	EXPECT_TRUE(response["cbor"].is_string());
}
