#include "../../include/BlockFrostClient.hpp"

// Return content of the requested transaction
json BlockFrostClient::transaction(const std::string& hash) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/txs/" + hash },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "transaction");
	return json::parse(response.text);
}

// Return the inputs and UTXOs of the specific transaction
json BlockFrostClient::transaction_utxos(const std::string& hash) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/txs/" + hash + "/utxos" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "transaction_utxos");
	return json::parse(response.text);
}

// Obtain information about (de)registration of stake addresses within a transaction
json BlockFrostClient::transaction_stakes(const std::string& hash) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/txs/" + hash + "/stakes" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "transaction_stakes");
	return json::parse(response.text);
}

// Obtain information about delegation certificates of a specific transaction
json BlockFrostClient::transaction_delegations(const std::string& hash) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/txs/" + hash + "/delegations" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "transaction_delegations");
	return json::parse(response.text);
}

// Obtain information about withdrawals of a specific transaction
json BlockFrostClient::transaction_withdrawals(const std::string& hash) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/txs/" + hash + "/withdrawals" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "transaction_withdrawals");
	return json::parse(response.text);
}

// Obtain information about Move Instantaneous Rewards (MIRs) of a specific transaction
json BlockFrostClient::transaction_mirs(const std::string& hash) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/txs/" + hash + "/mirs" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "transaction_mirs");
	return json::parse(response.text);
}

// Obtain information about stake pool registration and update certificates of a specific transaction
json BlockFrostClient::transaction_pool_updates(const std::string& hash) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/txs/" + hash + "/pool_updates" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "transaction_pool_updates");
	return json::parse(response.text);
}

// Obtain information about stake pool retirements within a specific transaction
json BlockFrostClient::transaction_pool_retires(const std::string& hash) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/txs/" + hash + "/pool_retires" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "transaction_pool_retires");
	return json::parse(response.text);
}

// Obtain the transaction metadata
json BlockFrostClient::transaction_metadata(const std::string& hash) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/txs/" + hash + "/metadata" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "transaction_metadata");
	return json::parse(response.text);
}

// Obtain the transaction metadata in CBOR
json BlockFrostClient::transaction_metadata_cbor(const std::string& hash) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/txs/" + hash + "/metadata/cbor" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "transaction_metadata_cbor");
	return json::parse(response.text);
}

// Obtain the transaction redeemers
json BlockFrostClient::transaction_redeemers(const std::string& hash) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/txs/" + hash + "/redeemers" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "transaction_redeemers");
	return json::parse(response.text);
}

// Obtain the extra transaction witnesses
json BlockFrostClient::transaction_required_signers(const std::string& hash) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/txs/" + hash + "/required_signers" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "transaction_required_signers");
	return json::parse(response.text);
}

// Obtain the CBOR serialized transaction
json BlockFrostClient::transaction_cbor(const std::string& hash) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/txs/" + hash + "/cbor" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "transaction_cbor");
	return json::parse(response.text);
}

// Submit an already serialized transaction to the network
std::string BlockFrostClient::transaction_submit(const std::vector<uint8_t>& cbor_bytes) {
	// Convert vector<uint8_t> to string for the request body
	std::string cbor_string(cbor_bytes.begin(), cbor_bytes.end());
	
	auto response = cpr::Post(
		cpr::Url{ m_baseUrl + "/tx/submit" },
		cpr::Body{ cbor_string },
		cpr::Header{ {"project_id", m_apiKey},
					 {"Content-Type", "application/cbor"} }
	);
	// Check if request succeeded
	check_status(response, "transaction_submit");
	return response.text;
}