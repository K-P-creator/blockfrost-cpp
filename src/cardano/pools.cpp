#include "../../include/BlockFrostClient.hpp"

json BlockFrostClient::pools(int count, int page, const std::string order) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/pools" },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "pools");
	return json::parse(response.text);
}

json BlockFrostClient::pools_extended(int count, int page, const std::string order) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/pools/extended" },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "pools_extended");
	return json::parse(response.text);
}

json BlockFrostClient::pools_retired(int count, int page, const std::string order) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/pools/retired" },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "pools_retired");
	return json::parse(response.text);
}

json BlockFrostClient::pools_retiring(int count, int page, const std::string order) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/pools/retiring" },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "pools_retiring");
	return json::parse(response.text);
}

json BlockFrostClient::pool(const std::string& pool_id) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/pools/" + pool_id },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "pool");
	return json::parse(response.text);
}

json BlockFrostClient::pool_history(const std::string& pool_id) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/pools/" + pool_id + "/history" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "pool_history");
	return json::parse(response.text);
}

json BlockFrostClient::pool_metadata(const std::string& pool_id) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/pools/" + pool_id + "/metadata" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "pool_metadata");
	return json::parse(response.text);
}

json BlockFrostClient::pool_relays(const std::string& pool_id) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/pools/" + pool_id + "/relays" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "pool_relays");
	return json::parse(response.text);
}

json BlockFrostClient::pool_delegators(const std::string& pool_id, int count, int page, const std::string order) {
	validate_parameters(count, page, order);
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/pools/" + pool_id + "/delegators" },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "pool_delegators");
	return json::parse(response.text);
}

json BlockFrostClient::pool_blocks(const std::string& pool_id, int count, int page, const std::string order) {
	validate_parameters(count, page, order);
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/pools/" + pool_id + "/blocks" },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "pool_blocks");
	return json::parse(response.text);
}

json BlockFrostClient::pool_updates(const std::string& pool_id, int count, int page, const std::string order) {
	validate_parameters(count, page, order);
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/pools/" + pool_id + "/updates" },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "pool_updates");
	return json::parse(response.text);
}

json BlockFrostClient::pool_votes(const std::string& pool_id, int count, int page, const std::string order) {
	validate_parameters(count, page, order);
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/pools/" + pool_id + "/votes" },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "pool_votes");
	return json::parse(response.text);
}
