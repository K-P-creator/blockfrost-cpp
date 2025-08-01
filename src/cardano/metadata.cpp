#include "../../include/BlockFrostClient.hpp"

json BlockFrostClient::metadata_txs_labels(int count, int page, std::string order) {
	validate_parameters(count, page, order);
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/metadata/txs/labels" },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "metadata_txs_labels");
	return json::parse(response.text);
}

json BlockFrostClient::metadata_txs_label(const std::string& label, int count, int page, std::string order) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/metadata/txs/labels/" + label },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "metadata_txs_label");
	return json::parse(response.text);
}

json BlockFrostClient::metadata_txs_label_cbor(const std::string& label, int count, int page, std::string order) {
	validate_parameters(count, page, order);
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/metadata/txs/labels/" + label + "/cbor" },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "metadata_txs_label_cbor");
	return json::parse(response.text);
}
