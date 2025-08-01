#include "../include/BlockFrostClient.hpp"


// Constructor for the client, sets the API key and the network preference
BlockFrostClient::BlockFrostClient(const std::string& apiKey, Network network) : m_apiKey(apiKey){
    switch (network) {
    case Network::mainnet:
        m_baseUrl = "https://cardano-mainnet.blockfrost.io/api/v0";
        break;
    case Network::preprod:
        m_baseUrl = "https://cardano-preprod.blockfrost.io/api/v0";
        break;
    case Network::preview:
        m_baseUrl = "https://cardano-preview.blockfrost.io/api/v0";
        break;
    default:
        throw std::runtime_error("Unknown network");
    }
}






