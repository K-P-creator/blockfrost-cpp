#include "../../include/BlockFrostClient.hpp"

// Derive Shelley address from an xpub
json BlockFrostClient::utils_address_from_xpub(const std::string& xpub, int role, int index) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/utils/addresses/xpub/" + xpub },
		cpr::Parameters{ {"role", std::to_string(role)},
						 {"index", std::to_string(index)} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "utils_address_from_xpub");
	return json::parse(response.text);
}

// Submit an already serialized transaction to evaluate how much execution units it requires
json BlockFrostClient::utils_evaluate_tx(const std::vector<uint8_t>& cbor_bytes) {
	// Convert vector<uint8_t> to string for the request body
	std::string cbor_string(cbor_bytes.begin(), cbor_bytes.end());
	
	auto response = cpr::Post(
		cpr::Url{ m_baseUrl + "/utils/evaluate/tx" },
		cpr::Body{ cbor_string },
		cpr::Header{ {"project_id", m_apiKey},
					 {"Content-Type", "application/cbor"} }
	);
	// Check if request succeeded
	check_status(response, "utils_evaluate_tx");
	return json::parse(response.text);
}

// Submit a JSON payload with transaction CBOR and additional UTXO set to evaluate how much execution units it requires
json BlockFrostClient::utils_evaluate_utxos(const std::vector<uint8_t>& cbor_bytes) {
	// Convert vector<uint8_t> to string for the request body
	std::string cbor_string(cbor_bytes.begin(), cbor_bytes.end());
	
	auto response = cpr::Post(
		cpr::Url{ m_baseUrl + "/utils/evaluate/utxos" },
		cpr::Body{ cbor_string },
		cpr::Header{ {"project_id", m_apiKey},
					 {"Content-Type", "application/cbor"} }
	);
	// Check if request succeeded
	check_status(response, "utils_evaluate_utxos");
	return json::parse(response.text);
}
