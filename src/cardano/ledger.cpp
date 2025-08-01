#include "../../include/BlockFrostClient.hpp"

json BlockFrostClient::genesis() {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/genesis" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "genesis");
	return json::parse(response.text);
}
