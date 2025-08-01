#include "../../include/BlockFrostClient.hpp"

json BlockFrostClient::accounts(const std::string& stakeAdr)
{
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/accounts/" + stakeAdr },
		cpr::Header{ {"project_id", m_apiKey} }
	);

	// Check if request succeeded
	check_status(response, "accounts");
	return json::parse(response.text);
}

json BlockFrostClient::account_rewards(const std::string& stakeAdr, int count, int page, const std::string order)
{
	// Validate parameters
	validate_parameters(count, page, order);

	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/accounts/" + stakeAdr + "/rewards" },
		cpr::Parameters{ {"stake_address", stakeAdr},
						 {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);

	// Check if request succeeded
	check_status(response, "account_rewards");
	return json::parse(response.text);
}

json BlockFrostClient::accout_history(const std::string& stakeAdr, int count, int page, const std::string order)
{
	// Validate parameters
	validate_parameters(count, page, order);

	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/accounts/" + stakeAdr + "/history" },
		cpr::Parameters{ {"stake_address", stakeAdr},
						 {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);

	// Check if request succeeded
	check_status(response, "account_history");

	return json::parse(response.text);
}

json BlockFrostClient::account_delegations(const std::string& stakeAdr, int count, int page, const std::string order)
{
	// Validate parameters
	validate_parameters(count, page, order);

	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/accounts/" + stakeAdr + "/delegations" },
		cpr::Parameters{ {"stake_address", stakeAdr},
						 {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);

	// Check if request succeeded
	check_status(response, "account_delegations");

	return json::parse(response.text);
}

json BlockFrostClient::account_registrations(const std::string& stakeAdr, int count, int page, const std::string order)
{
	// Validate parameters
	validate_parameters(count, page, order);

	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/accounts/" + stakeAdr + "/registrations" },
		cpr::Parameters{ {"stake_address", stakeAdr},
						 {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);

	// Check if request succeeded
	check_status(response, "account_registrations");

	return json::parse(response.text);
}

json BlockFrostClient::account_withdrawals(const std::string& stakeAdr, int count, int page, const std::string order)
{
	validate_parameters(count, page, order);

	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/accounts/" + stakeAdr + "/withdrawals" },
		cpr::Parameters{ {"stake_address", stakeAdr},
						 {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);

	// Check if request succeeded
	check_status(response, "account_withdrawls");

	return json::parse(response.text);
}

json BlockFrostClient::account_mirs(const std::string& stakeAdr, int count, int page, const std::string order)
{
	validate_parameters(count, page, order);

	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/accounts/" + stakeAdr + "/mirs" },
		cpr::Parameters{ {"stake_address", stakeAdr},
						 {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);

	// Check if request succeeded
	check_status(response, "account_mirs");

	return json::parse(response.text);
}

json BlockFrostClient::account_addresses(const std::string& stakeAdr, int count, int page, const std::string order)
{
	validate_parameters(count, page, order);

	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/accounts/" + stakeAdr + "/addresses" },
		cpr::Parameters{ {"stake_address", stakeAdr},
						 {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);

	// Check if request succeeded
	check_status(response, "account_addresses");

	return json::parse(response.text);
}

json BlockFrostClient::account_addresses_assets(const std::string& stakeAdr, int count, int page, const std::string order)
{
	validate_parameters(count, page, order);

	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/accounts/" + stakeAdr + "/addresses/assets" },
		cpr::Parameters{ {"stake_address", stakeAdr},
						 {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);

	// Check if request succeeded
	check_status(response, "account_addresses_assets");

	return json::parse(response.text);
}

json BlockFrostClient::account_addresses_total(const std::string& stakeAdr, int count, int page, const std::string order)
{
	validate_parameters(count, page, order);

	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/accounts/" + stakeAdr + "/addresses/total" },
		cpr::Parameters{ {"stake_address", stakeAdr},
						 {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);

	// Check if request succeeded
	check_status(response, "account_addresses_total");

	return json::parse(response.text);
}

json BlockFrostClient::account_utxos(const std::string& stakeAdr, int count, int page, const std::string order) {
	validate_parameters(count, page, order);
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/accounts/" + stakeAdr + "/utxos" },
		cpr::Parameters{ {"stake_address", stakeAdr},
						 {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "account_utxos");
	return json::parse(response.text);
}