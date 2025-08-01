#include "../../include/BlockFrostClient.hpp"

json BlockFrostClient::blocks_latest() {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/blocks/latest" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "blocks_latest");
	return json::parse(response.text);
}

json BlockFrostClient::blocks_latest_transactions(int count, int page, const std::string& order) {
	validate_parameters(count, page, order);
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/blocks/latest/txs" },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "blocks_latest_transactions");
	return json::parse(response.text);
}

json BlockFrostClient::blocks_latest_transactions_cbor(int count, int page, const std::string& order) {
	validate_parameters(count, page, order);
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/blocks/latest/txs/cbor" },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "blocks_latest_transactions_cbor");
	return json::parse(response.text);
}

json BlockFrostClient::block(const std::string& hash_or_number) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/blocks/" + hash_or_number },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "block");
	return json::parse(response.text);
}

json BlockFrostClient::block_next(const std::string& hash_or_number, int count, int page) {
	validate_parameters(count, page, "asc");
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/blocks/" + hash_or_number + "/next" },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "block_next");
	return json::parse(response.text);
}

json BlockFrostClient::block_previous(const std::string& hash_or_number, int count, int page) {
	validate_parameters(count, page, "asc");
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/blocks/" + hash_or_number + "/previous" },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "block_previous");
	return json::parse(response.text);
}

json BlockFrostClient::block_slot(int slot_number) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/blocks/slot/" + std::to_string(slot_number) },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "block_slot");
	return json::parse(response.text);
}

json BlockFrostClient::block_epoch_slot(int epoch_number, int slot_number) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/blocks/epoch/" + std::to_string(epoch_number) + "/slot/" + std::to_string(slot_number) },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "block_epoch_slot");
	return json::parse(response.text);
}

json BlockFrostClient::block_transactions(const std::string& hash_or_number, int count, int page, const std::string& order) {
	validate_parameters(count, page, order);
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/blocks/" + hash_or_number + "/txs" },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "block_transactions");
	return json::parse(response.text);
}

json BlockFrostClient::block_transactions_cbor(const std::string& hash_or_number, int count, int page, const std::string& order) {
	validate_parameters(count, page, order);
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/blocks/" + hash_or_number + "/txs/cbor" },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "block_transactions_cbor");
	return json::parse(response.text);
}

json BlockFrostClient::block_addresses(const std::string& hash_or_number, int count, int page) {
	validate_parameters(count, page, "asc");
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/blocks/" + hash_or_number + "/addresses" },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "block_addresses");
	return json::parse(response.text);
}