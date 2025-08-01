
# C++ SDK for Cardano

## About

The goal of this project is to create a C++ SDK for BlockFrost/Cardano.
I will use libcpr for HTML requests to blockfrost. I will use nlohmann/json for JSON parsing
When you use the tests or the demo you will need to add your API key to src/main.cpp and/or tests/test_constants.h

### Dependencies

- **libcpr**: HTTP requests to BlockFrost API
  - GitHub: https://github.com/libcpr/cpr
- **nlohmann/json**: JSON parsing and manipulation
  - GitHub: https://github.com/nlohmann/json

## Building the Project

This project is built with MSVC (Microsoft Visual Studio Compiler). Follow these steps to build the demo and tests:

### Prerequisites

- Visual Studio 2022 with C++ development tools
- CMake 3.20 or later

### Build Steps

1. **Open the Developer Command Prompt**
   ```cmd
   "x64 Native Tools Command Prompt for VS 2022"
   ```

2. **Navigate to your project directory**
   ```cmd
   cd C:\Path\To\YourProject
   ```

3. **Clean previous build (optional)**
   ```cmd
   rd /s /q build
   ```

4. **Configure CMake to generate MSVC project files**
   ```cmd
   cmake -S . -B build -G "Visual Studio 17 2022" -A x64
   ```

5. **Build the main project and all tests**
  Remember to add your API key before building!
   ```cmd
   cmake --build build --config Debug --target run_all_tests
   ```

## Running Tests

### Method 1: Direct Execution
```cmd
cd build/bin/tests/Debug
test_blockfrost.exe


cd build
ctest -C Debug --output-on-failure
```

## Project Structure

```
blockfrost-cpp/
├── CMakeLists.txt
├── include/
│   ├── BlockFrostClient.hpp
│   ├── BlockFrostExceptions.hpp
│   ├── external/
│   │   └── json.hpp
│   └── helpers.hpp
├── src/
│   ├── BlockFrostClient.cpp
│   ├── main.cpp
│   ├── health.cpp
│   ├── metrics.cpp
│   └── cardano/
│       ├── accounts.cpp
│       ├── addresses.cpp
│       ├── assets.cpp
│       ├── blocks.cpp
│       ├── epochs.cpp
│       ├── governance.cpp
│       ├── ledger.cpp
│       ├── mempool.cpp
│       ├── metadata.cpp
│       ├── network.cpp
│       ├── pools.cpp
│       ├── scripts.cpp
│       ├── transaction.cpp
│       └── utilities.cpp
└── tests/
    ├── test_constants.h
    ├── test_accounts.cpp
    ├── test_addresses.cpp
    ├── test_assets.cpp
    ├── test_blocks.cpp
    ├── test_epochs.cpp
    ├── test_governance.cpp
    ├── test_health.cpp
    ├── test_ledger.cpp
    ├── test_mempool.cpp
    ├── test_metadata.cpp
    ├── test_metrics.cpp
    ├── test_network.cpp
    ├── test_pools.cpp
    ├── test_scripts.cpp
    ├── test_transaction.cpp
    └── test_utilities.cpp
```

## Features

The SDK provides comprehensive coverage of the BlockFrost API, including:

- **Health & Metrics**: API health checks and performance metrics
- **Accounts**: Stake account information and history
- **Addresses**: Address details and UTXO information
- **Assets**: Native and custom asset management
- **Blocks**: Block information and transactions
- **Epochs**: Epoch data and parameters
- **Governance**: DRep and proposal management
- **Ledger**: Genesis information
- **Mempool**: Transaction pool management
- **Metadata**: Transaction metadata handling
- **Network**: Network information and eras
- **Pools**: Stake pool operations
- **Scripts**: Plutus script management
- **Transactions**: Transaction details and UTXOs
- **Utilities**: Address derivation and transaction evaluation

## License

This project is open source. Please check the license file for more details.
