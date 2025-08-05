#include "../include/BlockFrostClient.hpp"
#include "test_constants.h"
#include <gtest/gtest.h>

TEST(GovernanceTest, ReturnsGovernanceDreps) {
	BlockFrostClient client(API_KEY);
	auto response = client.governance_dreps(10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("drep_id"));
		EXPECT_TRUE(first.contains("hex"));
	}
}

TEST(GovernanceTest, ReturnsGovernanceDrep) {
	BlockFrostClient client(API_KEY);
	auto response = client.governance_drep(DREP_ID);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("drep_id"));
	EXPECT_TRUE(response.contains("hex"));
	EXPECT_TRUE(response.contains("amount"));
}

TEST(GovernanceTest, ReturnsGovernanceDrepDelegators) {
	BlockFrostClient client(API_KEY);
	auto response = client.governance_drep_delegators(DREP_ID, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("address"));
		EXPECT_TRUE(first.contains("amount"));
	}
}

TEST(GovernanceTest, ReturnsGovernanceDrepMetadata) {
	BlockFrostClient client(API_KEY);
	auto response = client.governance_drep_metadata(DREP_ID);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("drep_id"));
	EXPECT_TRUE(response.contains("drep_metadata_hash"));
	EXPECT_TRUE(response.contains("url"));
	EXPECT_TRUE(response.contains("metadata_hash"));
	EXPECT_TRUE(response.contains("metadata"));
}

TEST(GovernanceTest, ReturnsGovernanceDrepUpdates) {
	BlockFrostClient client(API_KEY);
	auto response = client.governance_drep_updates(DREP_ID, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("tx_hash"));
		EXPECT_TRUE(first.contains("cert_index"));
		EXPECT_TRUE(first.contains("action"));
	}
}

TEST(GovernanceTest, ReturnsGovernanceDrepVotes) {
	BlockFrostClient client(API_KEY);
	auto response = client.governance_drep_votes(DREP_ID, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("tx_hash"));
		EXPECT_TRUE(first.contains("cert_index"));
		EXPECT_TRUE(first.contains("gov_action_type"));
		EXPECT_TRUE(first.contains("gov_action_index"));
		EXPECT_TRUE(first.contains("vote"));
	}
}

TEST(GovernanceTest, ReturnsGovernanceProposals) {
	BlockFrostClient client(API_KEY);
	auto response = client.governance_proposals(10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("tx_hash"));
		EXPECT_TRUE(first.contains("cert_index"));
		EXPECT_TRUE(first.contains("governance_type"));
	}
}

TEST(GovernanceTest, ReturnsGovernanceProposal) {
	BlockFrostClient client(API_KEY);
	auto response = client.governance_proposal(TX_HASH, 0);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("tx_hash"));
	EXPECT_TRUE(response.contains("cert_index"));
	EXPECT_TRUE(response.contains("deposit"));
}

TEST(GovernanceTest, ReturnsGovernanceProposalParameters) {
	BlockFrostClient client(API_KEY);
	auto response = client.governance_proposal_parameters(TX_HASH, 0);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("tx_hash"));
	EXPECT_TRUE(response.contains("cert_index"));
	EXPECT_TRUE(response.contains("parameters"));
}

TEST(GovernanceTest, ReturnsGovernanceProposalWithdrawals) {
	BlockFrostClient client(API_KEY);
	auto response = client.governance_proposal_withdrawals(TX_HASH, 0);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("stake_address"));
		EXPECT_TRUE(first.contains("amount"));
	}
}

TEST(GovernanceTest, ReturnsGovernanceProposalVotes) {
	BlockFrostClient client(API_KEY);
	auto response = client.governance_proposal_votes(TX_HASH, 0, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto first = response[0];
		EXPECT_TRUE(first.contains("tx_hash"));
		EXPECT_TRUE(first.contains("cert_index"));
		EXPECT_TRUE(first.contains("voter_role"));
		EXPECT_TRUE(first.contains("vote"));
		EXPECT_TRUE(first.contains("voter"));
	}

}

TEST(GovernanceTest, ReturnsGovernanceProposalMetadata) {
	BlockFrostClient client(API_KEY);
	auto response = client.governance_proposal_metadata(TX_HASH, 0);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("tx_hash"));
	EXPECT_TRUE(response.contains("cert_index"));
	EXPECT_TRUE(response.contains("url"));
	EXPECT_TRUE(response.contains("hash"));
}
