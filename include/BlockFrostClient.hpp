#pragma once

#include <string>
#include <iostream>
#include "external/json.hpp"
#include <cpr/cpr.h>
#include "helpers.hpp"


enum class Network {mainnet, preprod, preview};

using json = nlohmann::json;

class BlockFrostClient {
    public:
    // Construct a new client with a user provided API key
    // Default to using the test network if no network is selected
    explicit BlockFrostClient(const std::string& apiKey, Network n = Network::preprod);



	// --- HEALTH ---
	
    // Return backend status as a boolean. (AKA if API key is valid)
    bool health();

    // Returns the UNIX time in a json
    json clock();



	// --- METRICS ---
	
    // History of your Blockfrost usage metrics in the past 30 days
    json metrics();

    // History of your Blockfrost usage metrics per endpoint in the past 30 days
    json metrics_endpoints();



	// --- ACCOUNTS ---
	
    // Obtain information about a specific stake account
	// Parameters: stake address as string
    json accounts(const std::string&);    

    // Obtain information about the reward history of a specific account
    // Parameters: Stake address as a string (Path Parameter)
	// count - integer - min:1 max:100 default:100 - The number of results displayed on one page.
    // page - integer min:1 max:21474836 default:1 - The page number for listing the results.
    // order - string enum - default:asc - The ordering of items from the point of view of the blockchain, not the page listing itself.By default, we return oldest first, newest last
	// asc - ascending order, desc - descending order
	enum class order { asc, desc };
	json account_rewards(const std::string&, int count = 100, int page = 1, const std::string = "asc");

    // Obtain information about the history of a specific account.
	// Parameters: Stake address as a string (Path Parameter)
	// count - integer - min:1 max:100 default:100 - The number of results displayed on one page.
	// page - integer min:1 max:21474836 default:1 - The page number for listing the results.
	// order - string enum - default:asc - The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last
	json account_history(const std::string& stakeAdr, int count = 100, int page = 1, const std::string order = "asc");

    // Obtain information about the delegation of a specific account
	// Parameters: Stake address as a string (Path Parameter)
	// count - integer - min:1 max:100 default:100 - The number of results displayed on one page.
	// page - integer min:1 max:21474836 default:1 - The page number for listing the results.
	// order - string enum - default:asc - The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last
	json account_delegations(const std::string& stakeAdr, int count = 100, int page = 1, const std::string order = "asc");

    // Obtain information about the registrations and deregistrations of a specific account
	// Parameters: Stake address as a string (Path Parameter)
	// count - integer - min:1 max:100 default:100 - The number of results displayed on one page.
	// page - integer min:1 max:21474836 default:1 - The page number for listing the results.
	// order - string enum - default:asc - The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last
	json account_registrations(const std::string& stakeAdr, int count = 100, int page = 1, const std::string order = "asc");

    // Obtain information about the withdrawals of a specific account
	// Parameters: Stake address as a string (Path Parameter)
	// count - integer - min:1 max:100 default:100 - The number of results displayed on one page.
	// page - integer min:1 max:21474836 default:1 - The page number for listing the results.
	// order - string enum - default:asc - The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last
	json account_withdrawals(const std::string& stakeAdr, int count = 100, int page = 1, const std::string order = "asc");

    // Obtain information about the MIRs of a specific account.
	// Parameters: Stake address as a string (Path Parameter)
	// count - integer - min:1 max:100 default:100 - The number of results displayed on one page.
	// page - integer min:1 max:21474836 default:1 - The page number for listing the results.
	// order - string enum - default:asc - The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last
	json account_mirs(const std::string& stakeAdr, int count = 100, int page = 1, const std::string order = "asc");

	// Obtain information about the addresses of a specific account
	// Parameters: Stake address as a string (Path Parameter)
	// count - integer - min:1 max:100 default:100 - The number of results displayed on one page.
	// page - integer min:1 max:21474836 default:1 - The page number for listing the results.
	// order - string enum - default:asc - The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last
	json account_addresses(const std::string& stakeAdr, int count = 100, int page = 1, const std::string order = "asc");

	// Obtain information about assets associated with addresses of a specific account
	// Parameters: Stake address as a string (Path Parameter)
	// count - integer - min:1 max:100 default:100 - The number of results displayed on one page.
	// page - integer min:1 max:21474836 default:1 - The page number for listing the results.
	// order - string enum - default:asc - The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last
	json account_addresses_assets(const std::string& stakeAdr, int count = 100, int page = 1, const std::string order = "asc");

	// Obtain summed details about all addresses associated with a given account
	// Parameters: Stake address as a string (Path Parameter)
	// count - integer - min:1 max:100 default:100 - The number of results displayed on one page.
	// page - integer min:1 max:21474836 default:1 - The page number for listing the results.
	// order - string enum - default:asc - The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last
	json account_addresses_total(const std::string& stakeAdr, int count = 100, int page = 1, const std::string order = "asc");

	// UTXOs associated with the account.
	// // Parameters: Stake address as a string (Path Parameter)
	// count - integer - min:1 max:100 default:100 - The number of results displayed on one page.
	// page - integer min:1 max:21474836 default:1 - The page number for listing the results.
	// order - string enum - default:asc - The ordering of items from the point of view of the blockchain, not the page listing itself. By default, we return oldest first, newest last
	json account_utxos(const std::string& stakeAdr, int count = 100, int page = 1, const std::string order = "asc");



	// --- ADDRESSES ---
		
	// Obtain information about a specific address
	// Parameters: Bech32 address - string
	json address(const std::string& address);

	// Obtain extended information about a specific address
	// Parameters: Bech32 address - string
	json address_extended(const std::string& address);

	// Obtain details about an address
	// Parameters: Bech32 address - string
	json address_total(const std::string& address);

	// UTXOs of the address
	// Parameters: Bech32 address - string
	json address_utxos(const std::string& address);

	// UTXOs of the address
	// Parameters: Bech32 address - string
	// asset - Concatenation of the policy_id and hex-encoded asset_name - string
	json address_utxos_asset(const std::string& address, const std::string& asset);

	// Transactions on the address
	// Parameters: Bech32 address - string
	json address_transactions(const std::string& address);



	// --- ASSETS ---
	
	// List of all assets
	// Parameters: count, page, order
	json assets(int count = 100, int page = 1, const std::string order = "asc");

	// Get information about a specific asset
	// Parameters: asset - Concatenation of policy_id and hex-encoded asset_name
	json asset(const std::string& asset);

	// History of a specific asset
	// Parameters: asset - Concatenation of policy_id and hex-encoded asset_name
	json asset_history(const std::string& asset);

	// List of a specific asset transactions
	// Parameters: asset - string, count, page, order
	json asset_transactions(const std::string& asset, int count = 100, int page = 1, const std::string order = "asc");

	// List of a addresses containing a specific asset
	// Parameters: asset - string, count, page, order
	json asset_addresses(const std::string& asset, int count = 100, int page = 1, const std::string order = "asc");

	// List of asset minted under a specific policy
	// Parameters: policy_id - hex string, count, page, order
	json assets_policy(const std::string& policy_id, int count = 100, int page = 1, const std::string order = "asc");



	// --- BLOCKS ---
	
	// Return the latest block available to the backend (tip of the blockchain)
	json blocks_latest();

	// Return transactions within the latest block
	json blocks_latest_transactions(int count = 100, int page = 1, const std::string& order = "asc");

	// Return transactions within the latest block with CBOR data
	json blocks_latest_transactions_cbor(int count = 100, int page = 1, const std::string& order = "asc");

	// Return the content of a specific block by hash or block number
	json block(const std::string& hash_or_number);

	// Return the list of blocks following a specific block
	json block_next(const std::string& hash_or_number, int count = 100, int page = 1);

	// Return the list of blocks preceding a specific block
	json block_previous(const std::string& hash_or_number, int count = 100, int page = 1);

	// Return the content of the block for a given slot number
	json block_slot(int slot_number);

	// Return the content of the block for a specific epoch and slot number
	json block_epoch_slot(int epoch_number, int slot_number);

	// Return the transactions within a block
	json block_transactions(const std::string& hash_or_number, int count = 100, int page = 1, const std::string& order = "asc");

	// Return the transactions within the block, including CBOR representations
	json block_transactions_cbor(const std::string& hash_or_number, int count = 100, int page = 1, const std::string& order = "asc");

	// Return the list of addresses affected in a specific block
	json block_addresses(const std::string& hash_or_number, int count = 100, int page = 1);



	// --- EPOCHS ---
	
	// Return the information about the latest, therefore current, epoch
	json epochs_latest();

	// Return the protocol parameters for the latest epoch
	json epochs_latest_parameters();

	// Return the content of a specific epoch by epoch number
	json epoch(int epoch_number);

	// Return the list of epochs following a specific epoch
	json epoch_next(int epoch_number, int count = 100, int page = 1);

	// Return the list of epochs preceding a specific epoch
	json epoch_previous(int epoch_number, int count = 100, int page = 1);

	// Return the active stake distribution for the specified epoch
	json epoch_stakes(int epoch_number, int count = 100, int page = 1);

	// Return the active stake for the specified epoch specified by stake pool
	json epoch_stakes_pool(int epoch_number, const std::string& pool_id, int count = 100, int page = 1);

	// Return the blocks minted for the specified epoch
	json epoch_blocks(int epoch_number, int count = 100, int page = 1, const std::string& order = "asc");

	// Return the blocks minted for the specified epoch by stake pool
	json epoch_blocks_pool(int epoch_number, const std::string& pool_id, int count = 100, int page = 1, const std::string& order = "asc");

	// Return the protocol parameters for the specified epoch
	json epoch_parameters(int epoch_number);


	
	// --- GOVERNANCE ---
	
	// Return the information about Delegate Representatives (DReps)
	json governance_dreps(int count = 100, int page = 1, std::string order = "asc");

	// DRep information
	json governance_drep(const std::string& drep_id);

	// List of Drep delegators
	json governance_drep_delegators(const std::string& drep_id, int count = 100, int page = 1, std::string order = "asc");

	// DRep metadata information
	json governance_drep_metadata(const std::string& drep_id);

	// List of certificate updates to the DRep
	json governance_drep_updates(const std::string& drep_id, int count = 100, int page = 1, std::string order = "asc");

	// History of Drep votes
	json governance_drep_votes(const std::string& drep_id, int count = 100, int page = 1, std::string order = "asc");

	// Return the information about Proposals
	json governance_proposals(int count = 100, int page = 1, std::string order = "asc");

	// Proposal information
	json governance_proposal(const std::string& tx_hash, int cert_index);

	// Parameters proposal details
	json governance_proposal_parameters(const std::string& tx_hash, int cert_index);

	// Parameters withdrawals details
	json governance_proposal_withdrawals(const std::string& tx_hash, int cert_index);

	// History of Proposal votes
	json governance_proposal_votes(const std::string& tx_hash, int cert_index, int count = 100, int page = 1, std::string order = "asc");

	// Proposal metadata information
	json governance_proposal_metadata(const std::string& tx_hash, int cert_index);



	// --- LEDGER ---
	
	// Return the information about blockchain genesis
	json genesis();



	// --- MEMPOOL ---

	// Return transactions that are currently stored in Blockfrost mempool, waiting to be included in a newly minted block. Shows only transactions submitted via Blockfrost.io.
	json mempool(int count = 100, int page = 1, std::string order = "asc");

	// Return content of the requested transaction
	json mempool_transaction(const std::string& hash);

	// List of mempool transactions where at least one of the transaction inputs or outputs belongs to the address. Shows only transactions submitted via Blockfrost.io
	json mempool_address(const std::string& address, int count = 100, int page = 1, std::string order = "asc");



	// --- METADATA ---

	// List of all used transaction metadata labels
	json metadata_txs_labels(int count = 100, int page = 1, std::string order = "asc");

	// Transaction metadata per label.
	json metadata_txs_label(const std::string& label, int count = 100, int page = 1, std::string order = "asc");

	// Transaction metadata per label
	json metadata_txs_label_cbor(const std::string& label, int count = 100, int page = 1, std::string order = "asc");



	// --- NETWORK ---

	// Return detailed network information
	json network();

	// Returns start and end of each era along with parameters that can vary between hard forks
	json network_eras();

	
	
	// --- POOLS ---

	// List of registered stake pools
	json pools(int count = 100, int page = 1, const std::string order = "asc");
	
	// List of registered stake pools with additional information
	json pools_extended(int count = 100, int page = 1, const std::string order = "asc");
	
	// List of already retired pools
	json pools_retired(int count = 100, int page = 1, const std::string order = "asc");
	
	// List of stake pools retiring in the upcoming epochs
	json pools_retiring(int count = 100, int page = 1, const std::string order = "asc");
	
	// Pool information
	json pool(const std::string& pool_id);
	
	// History of stake pool parameters over epochs
	json pool_history(const std::string& pool_id);
	
	// Stake pool registration metadata
	json pool_metadata(const std::string& pool_id);
	
	// Relays of a stake pool
	json pool_relays(const std::string& pool_id);
	
	// List of current stake pools delegators
	json pool_delegators(const std::string& pool_id, int count = 100, int page = 1, const std::string order = "asc");
	
	// List of stake pools blocks
	json pool_blocks(const std::string& pool_id, int count = 100, int page = 1, const std::string order = "asc");
	
	// List of certificate updates to the stake pool
	json pool_updates(const std::string& pool_id, int count = 100, int page = 1, const std::string order = "asc");
	
	// History of stake pools votes
	json pool_votes(const std::string& pool_id, int count = 100, int page = 1, const std::string order = "asc");

	

	// --- SCRIPTS ---

	// List of scripts.
	json scripts(int count = 100, int page = 1, const std::string& order = "asc");
	
	// Information about a specific script
	json script(const std::string& script_hash);
	
	// JSON representation of a timelock script
	json script_json(const std::string& script_hash);
	
	// CBOR representation of a plutus script
	json script_cbor(const std::string& script_hash);
	
	// List of redeemers of a specific script
	json script_redeemers(const std::string& script_hash);
	
	// Query JSON value of a datum by its hash
	json script_datum(const std::string& datum_hash);
	
	// Query CBOR serialised datum by its hash
	json script_datum_cbor(const std::string& datum_hash);

	

	// --- TRANSACTIONS ---

	// Return content of the requested transaction
	json transaction(const std::string& hash);

	// Return the inputs and UTXOs of the specific transaction
	json transaction_utxos(const std::string& hash);

	// Obtain information about (de)registration of stake addresses within a transaction
	json transaction_stakes(const std::string& hash);
	
	// Obtain information about delegation certificates of a specific transaction
	json transaction_delegations(const std::string& hash);
	
	// Obtain information about withdrawals of a specific transaction
	json transaction_withdrawals(const std::string& hash);
	
	// Obtain information about Move Instantaneous Rewards (MIRs) of a specific transaction
	json transaction_mirs(const std::string& hash);
	
	// Obtain information about stake pool registration and update certificates of a specific transaction
	json transaction_pool_updates(const std::string& hash);
	
	// Obtain information about stake pool retirements within a specific transaction
	json transaction_pool_retires(const std::string& hash);
	
	// Obtain the transaction metadata
	json transaction_metadata(const std::string& hash);
	
	// Obtain the transaction metadata in CBOR
	json transaction_metadata_cbor(const std::string& hash);
	
	// Obtain the transaction redeemers
	json transaction_redeemers(const std::string& hash);
	
	// Obtain the extra transaction witnesses
	json transaction_required_signers(const std::string& hash);
	
	// Obtain the CBOR serialized transaction
	json transaction_cbor(const std::string& hash);
	
	// Submit an already serialized transaction to the network
	std::string transaction_submit(const std::vector<uint8_t>& cbor_bytes);



	// --- UTILITIES ---

	// Derive Shelley address from an xpub
	json utils_address_from_xpub(const std::string& xpub, int role, int index);
	
	// Submit an already serialized transaction to evaluate how much execution units it requires
	json utils_evaluate_tx(const std::vector<uint8_t>& cbor_bytes);
	
	// Submit a JSON payload with transaction CBOR and additional UTXO set to evaluate how much execution units it requires
	json utils_evaluate_utxos(const std::vector<uint8_t>& cbor_bytes);
	

private:
    std::string m_apiKey;
    std::string m_baseUrl;
};
