#include "../../include/BlockFrostClient.hpp"

json BlockFrostClient::governance_dreps(int count, int page, std::string order) {
	validate_parameters(count, page, order);
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/governance/dreps" },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "governance_dreps");
	return json::parse(response.text);
}

json BlockFrostClient::governance_drep(const std::string& drep_id) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/governance/dreps/" + drep_id },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "governance_drep");
	return json::parse(response.text);
}

json BlockFrostClient::governance_drep_delegators(const std::string& drep_id, int count, int page, std::string order) {
	validate_parameters(count, page, order);
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/governance/dreps/" + drep_id + "/delegators" },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "governance_drep_delegations");
	return json::parse(response.text);
}

json BlockFrostClient::governance_drep_metadata(const std::string& drep_id) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/governance/dreps/" + drep_id + "/metadata" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "governance_drep_metadata");
	return json::parse(response.text);
}

json BlockFrostClient::governance_drep_updates(const std::string& drep_id, int count, int page, std::string order) {
	validate_parameters(count, page, order);
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/governance/dreps/" + drep_id + "/updates" },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "governance_drep_updates");
	return json::parse(response.text);
}

json BlockFrostClient::governance_drep_votes(const std::string& drep_id, int count, int page, std::string order) {
	validate_parameters(count, page, order);
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/governance/dreps/" + drep_id + "/votes" },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "governance_drep_votes");
	return json::parse(response.text);
}

json BlockFrostClient::governance_proposals(int count, int page, std::string order) {
	validate_parameters(count, page, order);
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/governance/proposals" },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "governance_proposals");
	return json::parse(response.text);
}

json BlockFrostClient::governance_proposal(const std::string& tx_hash, int cert_index) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/governance/proposals/" + tx_hash + "/" + std::to_string(cert_index) },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "governance_proposal");
	return json::parse(response.text);
}

json BlockFrostClient::governance_proposal_parameters(const std::string& tx_hash, int cert_index) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/governance/proposals/" + tx_hash + "/" + std::to_string(cert_index) + "/parameters" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "governance_proposal_parameters");
	return json::parse(response.text);
}

json BlockFrostClient::governance_proposal_withdrawals(const std::string& tx_hash, int cert_index) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/governance/proposals/" + tx_hash + "/" + std::to_string(cert_index) + "/withdrawals" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "governance_proposal_withdrawals");
	return json::parse(response.text);
}

json BlockFrostClient::governance_proposal_votes(const std::string& tx_hash, int cert_index, int count, int page, std::string order) {
	validate_parameters(count, page, order);
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/governance/proposals/" + tx_hash + "/" + std::to_string(cert_index) + "/votes" },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "governance_proposal_votes");
	return json::parse(response.text);
}

json BlockFrostClient::governance_proposal_metadata(const std::string& tx_hash, int cert_index) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/governance/proposals/" + tx_hash + "/" + std::to_string(cert_index) + "/metadata" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "governance_proposal_metadata");
	return json::parse(response.text);
}
