#include "../../include/BlockFrostClient.hpp"

json BlockFrostClient::network() {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/network" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "network");
	return json::parse(response.text);
}

json BlockFrostClient::network_eras() {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/network/eras" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "network_eras");
	return json::parse(response.text);
}
