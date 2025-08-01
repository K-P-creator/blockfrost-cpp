#include "../include/BlockFrostClient.hpp"
#include "test_constants.h"
#include <gtest/gtest.h>

TEST(MetadataTest, ReturnsMetadataTxsLabels) {
	BlockFrostClient client(API_KEY);
	auto response = client.metadata_txs_labels(10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("label"));
		EXPECT_TRUE(first["label"].is_string());
		EXPECT_TRUE(first.contains("cip10"));
		EXPECT_TRUE(first["cip10"].is_string());
		EXPECT_TRUE(first.contains("count"));
		EXPECT_TRUE(first["count"].is_number_integer());
	}
}

TEST(MetadataTest, ReturnsMetadataTxsLabel) {
	BlockFrostClient client(API_KEY);
	auto response = client.metadata_txs_label(LABEL, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("tx_hash"));
		EXPECT_TRUE(first["tx_hash"].is_string());
		EXPECT_TRUE(first.contains("json_metadata"));
		EXPECT_TRUE(first["json_metadata"].is_object());
	}
}

TEST(MetadataTest, ReturnsMetadataTxsLabelCbor) {
	BlockFrostClient client(API_KEY);
	auto response = client.metadata_txs_label_cbor(LABEL, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("tx_hash"));
		EXPECT_TRUE(first["tx_hash"].is_string());
		EXPECT_TRUE(first.contains("cbor_metadata"));
		EXPECT_TRUE(first["cbor_metadata"].is_string());
	}
}
