#include "../../include/BlockFrostClient.hpp"

json BlockFrostClient::epochs_latest() {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/epochs/latest" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "epochs_latest");
	return json::parse(response.text);
}

json BlockFrostClient::epochs_latest_parameters() {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/epochs/latest/parameters" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "epochs_latest_parameters");
	return json::parse(response.text);
}

json BlockFrostClient::epoch(int epoch_number) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/epochs/" + std::to_string(epoch_number) },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "epoch");
	return json::parse(response.text);
}

json BlockFrostClient::epoch_next(int epoch_number, int count, int page) {
	validate_parameters(count, page, "asc");
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/epochs/" + std::to_string(epoch_number) + "/next" },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "epoch_next");
	return json::parse(response.text);
}

json BlockFrostClient::epoch_previous(int epoch_number, int count, int page) {
	validate_parameters(count, page, "asc");
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/epochs/" + std::to_string(epoch_number) + "/previous" },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "epoch_previous");
	return json::parse(response.text);
}

json BlockFrostClient::epoch_stakes(int epoch_number, int count, int page) {
	validate_parameters(count, page, "asc");
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/epochs/" + std::to_string(epoch_number) + "/stakes" },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "epoch_stakes");
	return json::parse(response.text);
}

json BlockFrostClient::epoch_stakes_pool(int epoch_number, const std::string& pool_id, int count, int page) {
	validate_parameters(count, page, "asc");
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/epochs/" + std::to_string(epoch_number) + "/stakes/" + pool_id },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "epoch_stakes_pool");
	return json::parse(response.text);
}

json BlockFrostClient::epoch_blocks(int epoch_number, int count, int page, const std::string& order) {
	validate_parameters(count, page, order);
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/epochs/" + std::to_string(epoch_number) + "/blocks" },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "epoch_blocks");
	return json::parse(response.text);
}

json BlockFrostClient::epoch_blocks_pool(int epoch_number, const std::string& pool_id, int count, int page, const std::string& order) {
	validate_parameters(count, page, order);
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/epochs/" + std::to_string(epoch_number) + "/blocks/" + pool_id },
		cpr::Parameters{ {"count", std::to_string(count)},
						 {"page", std::to_string(page)},
						 {"order", order} },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "epoch_blocks_pool");
	return json::parse(response.text);
}

json BlockFrostClient::epoch_parameters(int epoch_number) {
	auto response = cpr::Get(
		cpr::Url{ m_baseUrl + "/epochs/" + std::to_string(epoch_number) + "/parameters" },
		cpr::Header{ {"project_id", m_apiKey} }
	);
	// Check if request succeeded
	check_status(response, "epoch_parameters");
	return json::parse(response.text);
}