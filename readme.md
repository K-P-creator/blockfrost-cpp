
# C++ SDK for Cardano

## About

The goal of this project is to create a fully featured SDK for blockfrost written in C++. I wanted to pick a project that would be useful to the open source community around cardano/blockfrost, and rather than create the 100th wallet app I decided to make a C++ SDK. The idea came to me as I scrolled through the long list of available SDK's and saw there was no option for C++ (my prefferred language). As an undergrad student entering my junior year in the fall, I thought this would be a perfect project for my skill level. This taught me a ton about what makes up the cardano ecosystem. I also got to learn about HTML requests, unit testing, CMAKE and JSONs. There are a few tests that are a work in progress, and will be fixed soon, but currently I am out of time. When you run the tests make sure you use a preprod API key as that is what all of my sample data is on at the moment. The current main is a demo that allows you to see exactly what is outputting from each of the API calls. While I don't know how many people will find this useful, I will certainly be using it next year when I compete in this challenge, and perhaps others will find it useful if they wish to create a cardano app with C++.

In the coming weeks I will finish out all the tests, as well as make this project FetchContent() freindly so that other C++ devs can use it in their projects.

### Dependencies

- **libcpr**: HTTP requests to BlockFrost API
  - GitHub: https://github.com/libcpr/cpr
- **nlohmann/json**: JSON parsing and manipulation
  - GitHub: https://github.com/nlohmann/json
- **gtest**: C++ test framework by Google
  - GitHub: https://github.com/google/googletest

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

   ```cmd
   cmake --build build --config Debug --target run_all_tests
   ```

## Running Tests

### Navigate to directory

```cmd
cd build/bin/tests/Debug
```

### Run Tests

```cmd
test_blockfrost.exe
```

## Running main

### Build the main

In the base directory use

```cmd
cmake --build build --config Debug
```

```cmd
cd build/debug
```

```cmd
blockfrost_demo.exe
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

## TODO

Implement utilities tests
Fix tests for governance metadata (there seems to be metadata for my drep on cadanoscan.io but blockfrost returns a 404)
Fix mempool transaction test (needs different tx data?)
Fix ReturnPoolVotes test
Fix ReturnScriptDatum tests

## License

This project is open source. Please check the license file for more details.
