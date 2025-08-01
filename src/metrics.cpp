#include "../include/BlockFrostClient.hpp"

json BlockFrostClient::metrics()
{
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/metrics" },
		cpr::Header{ {"project_id", m_apiKey} }
	);

	// Check if request succeeded
	check_status(response, "metrics");

	return json::parse(response.text);
}

json BlockFrostClient::metrics_endpoints()
{
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/metrics/endpoints" },
		cpr::Header{ {"project_id", m_apiKey} }
	);

	// Check if request succeeded
	check_status(response, "metrics_endpoints");

	return json::parse(response.text);
}