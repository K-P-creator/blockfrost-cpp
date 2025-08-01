#pragma once

#include <stdexcept>
#include "BlockFrostExceptions.hpp"

inline void validate_parameters(int count, int page, const std::string& order) {
	if (count < 1 || count > 100) {
		throw std::invalid_argument("Count must be between 1 and 100");
	}
	if (page < 1 || page > 2147483647) {
		throw std::invalid_argument("Page must be between 1 and 2147483647");
	}
	if (order != "asc" && order != "desc") {
		throw std::invalid_argument("Order must be either 'asc' or 'desc'");
	}
}

inline void check_status(const cpr::Response& response, const std::string& context = "") {
	switch (response.status_code) {
	case 200:
		return;
	case 400:
		throw BadRequestException("400 Bad Request: " + response.text);
	case 403:
		throw UnauthorizedException("403 Unauthorized: " + response.text);
	case 404:
		throw NotFoundException("404 Not Found: " + response.text);
	case 418:
		throw BannedIpException("418 IP Banned: " + response.text);
	case 429:
		throw RateLimitException("429 Too Many Requests: " + response.text);
	case 500:
		throw InternalServerErrorException("500 Internal Server Error: " + response.text);
	default:
		throw UnknownApiException("Unexpected status (" + std::to_string(response.status_code) + "): " + response.text);
	}
}