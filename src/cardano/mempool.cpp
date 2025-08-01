#include "../../include/BlockFrostClient.hpp"

json BlockFrostClient::mempool(int count, int page, std::string order) {
	validate_parameters(count, page, order);
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/mempool" },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "mempool");
	return json::parse(response.text);
}

json BlockFrostClient::mempool_transaction(const std::string& tx_hash) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/mempool/" + tx_hash },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "mempool_transaction");
	return json::parse(response.text);
}

json BlockFrostClient::mempool_address(const std::string& address, int count, int page, const std::string order) {
	validate_parameters(count, page, order);
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/mempool/addresses/" + address },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "mempool_address");
	return json::parse(response.text);
}
