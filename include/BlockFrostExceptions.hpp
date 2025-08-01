#pragma once
#include <stdexcept>

struct BadRequestException : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

struct UnauthorizedException : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

struct NotFoundException : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

struct RateLimitException : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

struct BannedIpException : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

struct InternalServerErrorException : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

struct UnknownApiException : public std::runtime_error {
    using std::runtime_error::runtime_error;
};