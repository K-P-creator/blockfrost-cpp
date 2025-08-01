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
		EXPECT_TRUE(first["drep_id"].is_string());
		EXPECT_TRUE(first.contains("drep_metadata_hash"));
		EXPECT_TRUE(first.contains("voting_power"));
		EXPECT_TRUE(first["voting_power"].is_string());
	}
}

TEST(GovernanceTest, ReturnsGovernanceDrep) {
	BlockFrostClient client(API_KEY);
	auto response = client.governance_drep(DREP_ID);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("drep_id"));
	EXPECT_TRUE(response["drep_id"].is_string());
	EXPECT_TRUE(response.contains("drep_metadata_hash"));
	EXPECT_TRUE(response.contains("voting_power"));
	EXPECT_TRUE(response["voting_power"].is_string());
}

TEST(GovernanceTest, ReturnsGovernanceDrepDelegators) {
	BlockFrostClient client(API_KEY);
	auto response = client.governance_drep_delegators(DREP_ID, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("stake_address"));
		EXPECT_TRUE(first["stake_address"].is_string());
		EXPECT_TRUE(first.contains("amount"));
		EXPECT_TRUE(first["amount"].is_string());
	}
}

TEST(GovernanceTest, ReturnsGovernanceDrepMetadata) {
	BlockFrostClient client(API_KEY);
	auto response = client.governance_drep_metadata(DREP_ID);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("drep_id"));
	EXPECT_TRUE(response["drep_id"].is_string());
	EXPECT_TRUE(response.contains("drep_metadata_hash"));
	EXPECT_TRUE(response.contains("url"));
	EXPECT_TRUE(response.contains("metadata_hash"));
	EXPECT_TRUE(response.contains("metadata"));
	EXPECT_TRUE(response["metadata"].is_object());
}

TEST(GovernanceTest, ReturnsGovernanceDrepUpdates) {
	BlockFrostClient client(API_KEY);
	auto response = client.governance_drep_updates(DREP_ID, 10, 1, "asc");
	
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

TEST(GovernanceTest, ReturnsGovernanceDrepVotes) {
	BlockFrostClient client(API_KEY);
	auto response = client.governance_drep_votes(DREP_ID, 10, 1, "asc");
	
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

TEST(GovernanceTest, ReturnsGovernanceProposals) {
	BlockFrostClient client(API_KEY);
	auto response = client.governance_proposals(10, 1, "asc");
	
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
		EXPECT_TRUE(first.contains("deposit_amount"));
		EXPECT_TRUE(first["deposit_amount"].is_string());
		EXPECT_TRUE(first.contains("return_address"));
		EXPECT_TRUE(first["return_address"].is_string());
		EXPECT_TRUE(first.contains("expiration_epoch"));
		EXPECT_TRUE(first["expiration_epoch"].is_number_integer());
	}
}

TEST(GovernanceTest, ReturnsGovernanceProposal) {
	BlockFrostClient client(API_KEY);
	auto response = client.governance_proposal(TX_HASH, 0);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("tx_hash"));
	EXPECT_TRUE(response["tx_hash"].is_string());
	EXPECT_TRUE(response.contains("cert_index"));
	EXPECT_TRUE(response["cert_index"].is_number_integer());
	EXPECT_TRUE(response.contains("gov_action_type"));
	EXPECT_TRUE(response["gov_action_type"].is_string());
	EXPECT_TRUE(response.contains("gov_action_index"));
	EXPECT_TRUE(response["gov_action_index"].is_number_integer());
	EXPECT_TRUE(response.contains("deposit_amount"));
	EXPECT_TRUE(response["deposit_amount"].is_string());
	EXPECT_TRUE(response.contains("return_address"));
	EXPECT_TRUE(response["return_address"].is_string());
	EXPECT_TRUE(response.contains("expiration_epoch"));
	EXPECT_TRUE(response["expiration_epoch"].is_number_integer());
}

TEST(GovernanceTest, ReturnsGovernanceProposalParameters) {
	BlockFrostClient client(API_KEY);
	auto response = client.governance_proposal_parameters(TX_HASH, 0);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("tx_hash"));
	EXPECT_TRUE(response["tx_hash"].is_string());
	EXPECT_TRUE(response.contains("cert_index"));
	EXPECT_TRUE(response["cert_index"].is_number_integer());
	EXPECT_TRUE(response.contains("gov_action_type"));
	EXPECT_TRUE(response["gov_action_type"].is_string());
	EXPECT_TRUE(response.contains("gov_action_index"));
	EXPECT_TRUE(response["gov_action_index"].is_number_integer());
	EXPECT_TRUE(response.contains("deposit_amount"));
	EXPECT_TRUE(response["deposit_amount"].is_string());
	EXPECT_TRUE(response.contains("return_address"));
	EXPECT_TRUE(response["return_address"].is_string());
	EXPECT_TRUE(response.contains("expiration_epoch"));
	EXPECT_TRUE(response["expiration_epoch"].is_number_integer());
}

TEST(GovernanceTest, ReturnsGovernanceProposalWithdrawals) {
	BlockFrostClient client(API_KEY);
	auto response = client.governance_proposal_withdrawals(TX_HASH, 0);
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("stake_address"));
		EXPECT_TRUE(first["stake_address"].is_string());
		EXPECT_TRUE(first.contains("amount"));
		EXPECT_TRUE(first["amount"].is_string());
	}
}

TEST(GovernanceTest, ReturnsGovernanceProposalVotes) {
	BlockFrostClient client(API_KEY);
	auto response = client.governance_proposal_votes(TX_HASH, 0, 10, 1, "asc");
	
	ASSERT_TRUE(response.is_array());
	if (!response.empty()) {
		auto& first = response[0];
		EXPECT_TRUE(first.contains("stake_address"));
		EXPECT_TRUE(first["stake_address"].is_string());
		EXPECT_TRUE(first.contains("vote"));
		EXPECT_TRUE(first["vote"].is_string());
		EXPECT_TRUE(first.contains("voting_power"));
		EXPECT_TRUE(first["voting_power"].is_string());
	}
}

TEST(GovernanceTest, ReturnsGovernanceProposalMetadata) {
	BlockFrostClient client(API_KEY);
	auto response = client.governance_proposal_metadata(TX_HASH, 0);
	
	ASSERT_TRUE(response.is_object());
	EXPECT_TRUE(response.contains("tx_hash"));
	EXPECT_TRUE(response["tx_hash"].is_string());
	EXPECT_TRUE(response.contains("cert_index"));
	EXPECT_TRUE(response["cert_index"].is_number_integer());
	EXPECT_TRUE(response.contains("gov_action_type"));
	EXPECT_TRUE(response["gov_action_type"].is_string());
	EXPECT_TRUE(response.contains("gov_action_index"));
	EXPECT_TRUE(response["gov_action_index"].is_number_integer());
	EXPECT_TRUE(response.contains("deposit_amount"));
	EXPECT_TRUE(response["deposit_amount"].is_string());
	EXPECT_TRUE(response.contains("return_address"));
	EXPECT_TRUE(response["return_address"].is_string());
	EXPECT_TRUE(response.contains("expiration_epoch"));
	EXPECT_TRUE(response["expiration_epoch"].is_number_integer());
	EXPECT_TRUE(response.contains("url"));
	EXPECT_TRUE(response.contains("metadata_hash"));
	EXPECT_TRUE(response.contains("metadata"));
	EXPECT_TRUE(response["metadata"].is_object());
}
