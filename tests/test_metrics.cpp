#include "../include/BlockFrostClient.hpp"
#include "test_constants.h"
#include <gtest/gtest.h>

TEST(MetricsTest, ReturnsMetrics) {
	BlockFrostClient client(API_KEY);
	auto response = client.metrics();

	// Call health to ensure metrics is not empty
	client.health();

	ASSERT_TRUE(response.is_array());
	ASSERT_FALSE(response.empty());
	
	const auto& first = response.at(0);
	EXPECT_TRUE(first.contains("calls"));
	EXPECT_TRUE(first["calls"].is_number_integer());

	EXPECT_TRUE(first.contains("time"));
	EXPECT_TRUE(first["time"].is_number_integer());
}

TEST(MetricsTest, ReturnsMetricsEndopoints) {
	BlockFrostClient client(API_KEY);
	auto response = client.metrics_endpoints();

	ASSERT_TRUE(response.is_array());
	EXPECT_FALSE(response.empty());
	
	const auto& first = response.at(0);
	EXPECT_TRUE(first.contains("calls"));
	EXPECT_TRUE(first["calls"].is_number_integer());

	EXPECT_TRUE(first.contains("time"));
	EXPECT_TRUE(first["time"].is_number_integer());

	EXPECT_TRUE(first.contains("endpoint"));
	EXPECT_TRUE(first["endpoint"].is_string());
}