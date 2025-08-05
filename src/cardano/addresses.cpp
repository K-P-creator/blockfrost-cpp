#include "../../include/BlockFrostClient.hpp"


json BlockFrostClient::address(const std::string& address) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/addresses/" + address },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "address");
	return json::parse(response.text);
}

json BlockFrostClient::address_extended(const std::string& address)
{
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/addresses/" + address + "/extended" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "address_extended");
	return json::parse(response.text);
}

json BlockFrostClient::address_total(const std::string& address) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/addresses/" + address + "/total" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "address_total");
	return json::parse(response.text);
}

json BlockFrostClient::address_utxos(const std::string& address) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/addresses/" + address + "/utxos" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "address_utxos");
	return json::parse(response.text);
}

json BlockFrostClient::address_utxos_asset(const std::string& address, const std::string& asset) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/addresses/" + address + "/utxos/" + asset },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "address_utxos_asset");
	return json::parse(response.text);
}

json BlockFrostClient::address_transactions(const std::string& address) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/addresses/" + address + "/transactions" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "address_transactions");
	return json::parse(response.text);
}
