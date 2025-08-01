#include "../../include/BlockFrostClient.hpp"

json BlockFrostClient::scripts(int count, int page, const std::string& order)
{
	validate_parameters(count, page, order);
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/scripts" },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "scripts");
	return json::parse(response.text);
}

json BlockFrostClient::script(const std::string& script_hash)
{
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/scripts/" + script_hash },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "script");
	return json::parse(response.text);
}

json BlockFrostClient::script_json(const std::string& script_hash)
{
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/scripts/" + script_hash + "/json" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "script_json");
	return json::parse(response.text);
}

json BlockFrostClient::script_cbor(const std::string& script_hash)
{
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/scripts/" + script_hash + "/cbor" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "script_cbor");
	return json::parse(response.text);
}

json BlockFrostClient::script_redeemers(const std::string& script_hash)
{
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/scripts/" + script_hash + "/redeemers" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "script_redeemers");
	return json::parse(response.text);
}

json BlockFrostClient::script_datum(const std::string& datum_hash)
{
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/scripts/datum" + datum_hash},
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "script_datum");
	return json::parse(response.text);
}

json BlockFrostClient::script_datum_cbor(const std::string& datum_hash)
{
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/scripts/datum/" + datum_hash + "/cbor"},
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "script_datum_cbor");
	return json::parse(response.text);
}