#include "../../include/BlockFrostClient.hpp"

json BlockFrostClient::assets(int count, int page, const std::string order){
	validate_parameters(count, page, order);
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/assets" },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "assets");
	return json::parse(response.text);
}

json BlockFrostClient::asset(const std::string& asset) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/assets/" + asset },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "asset");
	return json::parse(response.text);
}

json BlockFrostClient::asset_history(const std::string& asset) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/assets/" + asset + "/history" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "asset_history");
	return json::parse(response.text);
}

json BlockFrostClient::asset_transactions(const std::string& asset, int count, int page, const std::string order) {
	validate_parameters(count, page, order);
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/assets/" + asset + "/transactions" },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "asset_transactions");
	return json::parse(response.text);
}

json BlockFrostClient::asset_addresses(const std::string& asset, int count, int page, const std::string order) {
	validate_parameters(count, page, order);
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/assets/" + asset + "/addresses" },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "asset_addresses");
	return json::parse(response.text);
}

json BlockFrostClient::assets_policy(const std::string& policy_id, int count, int page, const std::string order) {
	validate_parameters(count, page, order);
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/assets/policy/" + policy_id },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "assets_policy");
	return json::parse(response.text);
}