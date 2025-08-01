#include "../include/BlockFrostClient.hpp"


bool BlockFrostClient::health() {
    auto response = cpr::Get(
        cpr::Url{ m_baseUrl + "/health" },
        cpr::Header{ {"project_id", m_apiKey} }
    );

    // Check if request succeeded
    check_status(response, "health");

    json j = json::parse(response.text);

    bool isHealthy = j["is_healthy"].get<bool>();

    return isHealthy;
}

json BlockFrostClient::clock() {
    auto response = cpr::Get(
        cpr::Url{ m_baseUrl + "/health/clock" },
        cpr::Header{ {"project_id", m_apiKey} }
    );

    // Check if request succeeded
    check_status(response, "clock");

    return json::parse(response.text);
}