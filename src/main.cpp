#include <iostream>
#include "../include/BlockFrostClient.hpp"


int main() {
    const std::string API_KEY = "YOUR_API_KEY";
    const std::string STAKE_ADDR = "stake_test1uq52yy35l6p8qqadg9z2f5wmh84xfkv9kq06udgeg2y6etcd2r2ky";
    const std::string BECH32_ADDR = "addr_test1qrwk4wpsfrnjc6220argh9emc8y6wkdygjvl0q9rcz59ev3g5gfrfl5zwqp66s2y5ngahw02vnvctvql4c63js5f4jhsqqku95";
    const std::string ASSET = "e2bab64ca481afc5a695b7db22fd0a7df4bf930158dfa652fb33799953554d4d495441574152445344656669";
    const std::string POLICY_ID = "e2bab64ca481afc5a695b7db22fd0a7df4bf930158dfa652fb337999";
    const std::string BLOCK_HASH_OR_NUMBER = "74f95e691d434e98a2a6ad5cd009f26ac3bd95c00398f8fe9fffbadcb36b698b";
    const int BLOCK_SLOT = 97873333;
    const int EPOCH_NUMBER = 230;
    const int EPOCH_SLOT = 154933;
    const std::string POOL_ID = "pool1n84mel6x3e8sp0jjgmepme0zmv8gkw8chs98sqwxtruvkhhcsg8";
    const std::string DREP_ID = "drep1ytcw6qzpqqclx2yd0zy64ztvlkkhnf6yrzza8whgnq4vz5gh89626";
    const std::string TX_HASH = "49578eba0c840e822e0688b09112f3f9baaeb51dd0e346c5a4f9d03d2cbc1953";
	const std::string MEMPOOL_TX_HASH = "415ba1afed5d3b059cec494fc53816b1307157d576f6f03bf6c6db9019a3cd14";
    const std::string LABEL = "97";
    const std::string SCRIPT_HASH = "e2bab64ca481afc5a695b7db22fd0a7df4bf930158dfa652fb337999";
    const std::string DATUM_HASH = "d36a2619a672494604e11bb447cbcf5231e9f2ba25c2169177edc941bd50ad6c";

    BlockFrostClient client(API_KEY);

	int success_count = 0;
    int failure_count = 0;
    
    
	std::cout << "\n\nHealth\n\n";

    try {
        std::cout << "health: " << client.health() << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        ++failure_count;
    }
    try {
        std::cout << client.clock().dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

	std::cout << "\n\nMetrics\n\n";

    try {
        std::cout << client.metrics().dump(2) << "\n"; 
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        ++failure_count;
    }
    try { std::cout << client.metrics_endpoints().dump(2) << "\n";
    ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        ++failure_count;
    }
	std::cout << "\n\nAccounts\n\n";

    try { std::cout << client.accounts(STAKE_ADDR).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.account_rewards(STAKE_ADDR, 1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.accout_history(STAKE_ADDR, 1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.account_delegations(STAKE_ADDR, 1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.account_registrations(STAKE_ADDR, 1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.account_withdrawals(STAKE_ADDR, 1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.account_mirs(STAKE_ADDR, 1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.account_addresses(STAKE_ADDR, 1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.account_addresses_assets(STAKE_ADDR, 1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.account_addresses_total(STAKE_ADDR, 1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.account_utxos(STAKE_ADDR, 1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        ++failure_count;
    }
	std::cout << "\n\nAddresses\n\n";

    try { std::cout << client.address(BECH32_ADDR).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\naddress failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.address_extended(BECH32_ADDR).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\naddress_extended failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.address_total(BECH32_ADDR).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\naddress_total failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.address_utxos(BECH32_ADDR).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\naddress_utxos failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.address_uxtos_asset(BECH32_ADDR, ASSET).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\naddress_uxtos_asset failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.address_transactions(BECH32_ADDR).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\naddress_transactions failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }
	std::cout << "\n\nAssets\n\n";

    try { std::cout << client.assets(1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\nassets failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.asset(ASSET).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\nasset failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.asset_history(ASSET).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\nasset_history failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.asset_transactions(ASSET, 1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\nasset_transactions failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.asset_addresses(ASSET, 1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\nasset_addresses failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.assets_policy(POLICY_ID, 1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\nassets_policy failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }
	std::cout << "\n\nBlocks\n\n";

    try { std::cout << client.blocks_latest().dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\nblocks_latest failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.blocks_latest_transactions(1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\nblocks_latest_transactions failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.blocks_latest_transactions_cbor(1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\nblocks_latest_transactions_cbor failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.block(BLOCK_HASH_OR_NUMBER).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\nblock failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.block_next(BLOCK_HASH_OR_NUMBER,1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\nblock_next failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.block_previous(BLOCK_HASH_OR_NUMBER,1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\nblock_previous failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.block_slot(BLOCK_SLOT).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\nblock_slot failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.block_epoch_slot(EPOCH_NUMBER, EPOCH_SLOT).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\nblock_epoch_slot failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.block_transactions(BLOCK_HASH_OR_NUMBER,1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\nblock_transactions failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.block_transactions_cbor(BLOCK_HASH_OR_NUMBER,1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\nblock_transactions_cbor failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.block_addresses(BLOCK_HASH_OR_NUMBER,1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\nblock_addresses failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }
    
	std::cout << "\nEpochs\n\n";

    try { std::cout << client.epochs_latest().dump(5) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\nepochs_latest failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.epochs_latest_parameters().dump(5) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\nepochs_latest_parameters failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.epoch(EPOCH_NUMBER).dump(5) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\nepoch failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.epoch_next(EPOCH_NUMBER,1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\nepoch_next failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.epoch_previous(EPOCH_NUMBER,1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\nepoch_previous failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.epoch_stakes(EPOCH_NUMBER,1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\nepoch_stakes failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.epoch_stakes_pool(EPOCH_NUMBER, POOL_ID,1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\nepoch_stakes_pool failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.epoch_blocks(EPOCH_NUMBER,1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\nepoch_blocks failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.epoch_blocks_pool(EPOCH_NUMBER, POOL_ID,1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\nepoch_blocks_pool failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.epoch_parameters(EPOCH_NUMBER).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "\nepoch_parameters failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    
	std::cout << "\nGovernance\n\n";

    try { std::cout << client.governance_dreps(1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "governance_dreps failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.governance_drep(DREP_ID).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "governance_drep failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.governance_drep_delegators(DREP_ID,1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "governance_drep_delegators failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.governance_drep_metadata(DREP_ID).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "governance_drep_metadata failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.governance_drep_updates(DREP_ID, 1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "governance_drep_updates failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.governance_drep_votes(DREP_ID, 1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "governance_drep_votes failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.governance_proposals().dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "governance_proposals failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.governance_proposal(TX_HASH, 0).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "governance_proposal failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.governance_proposal_parameters(TX_HASH, 0).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "governance_proposal_parameters failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.governance_proposal_withdrawals(TX_HASH, 0).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "governance_proposal_withdrawals failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.governance_proposal_votes(TX_HASH, 0, 1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "governance_proposal_votes failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.governance_proposal_metadata(TX_HASH, 0).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "governance_proposal_metadata failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }
    
	std::cout << "\nLedger\n\n";

    try { std::cout << client.genesis() << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "genesis failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }
    
	std::cout << "\nMempool\n\n";

    try { std::cout << client.mempool().dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "mempool failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.mempool_transaction(MEMPOOL_TX_HASH).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "mempool_transaction failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.mempool_address(BECH32_ADDR).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "mempool_address failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }
    
	std::cout << "\nMetadata\n\n";

    try { std::cout << client.metadata_txs_labels(1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "metadata_txs_labels failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.metadata_txs_label(LABEL,1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "metadata_txs_label failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.metadata_txs_label_cbor(LABEL,1).dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "metadata_txs_label_cbor failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }
    
	std::cout << "\nNetwork\n\n";

    try { std::cout << client.network().dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "network failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }    try { std::cout << client.network_eras().dump(2) << "\n";++success_count;
    }
    catch (const std::exception& e) {
		std::cerr << "network_eras failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }
    
    
    std::cout << "\n\nPools\n\n";

    try {
        std::cout << client.pools(1, 1, "asc").dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << "pools failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    try {
        std::cout << client.pools_extended(1, 1, "asc").dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << "pools_extended failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    try {
        std::cout << client.pools_retired(1, 1, "asc").dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << "pools_retired failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    try {
        std::cout << client.pools_retiring(1, 1, "asc").dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << "pools_retiring failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    try {
        std::cout << client.pool(POOL_ID).dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << "pool failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    try {
        std::cout << client.pool_history(POOL_ID).dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << "pool_history failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    try {
        std::cout << client.pool_metadata(POOL_ID).dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << "pool_metadata failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    try {
        std::cout << client.pool_relays(POOL_ID).dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << "pool_relays failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    try {
        std::cout << client.pool_delegators(POOL_ID, 1, 1, "asc").dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << "pool_delegators failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    try {
        std::cout << client.pool_blocks(POOL_ID, 1, 1, "asc").dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << "pool_blocks failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    try {
        std::cout << client.pool_updates(POOL_ID, 1, 1, "asc").dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << "pool_updates failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    try {
        std::cout << client.pool_votes(POOL_ID, 1, 1, "asc").dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << "pool_votes failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    

    std::cout << "\n\nScripts\n\n";

    try { 
        std::cout << client.scripts(1).dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << "scripts failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    try { 
        std::cout << client.script(SCRIPT_HASH).dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << "script failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    try { 
        std::cout << client.script_json(SCRIPT_HASH).dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << "script_json failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    try { 
        std::cout << client.script_cbor(SCRIPT_HASH).dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << "script_cbor failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    try { 
        std::cout << client.script_redeemers(SCRIPT_HASH).dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << "script_redeemers failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    try { 
        std::cout << client.script_datum(DATUM_HASH).dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << "script_datum failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    try { 
        std::cout << client.script_datum_cbor(DATUM_HASH).dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << "script_datum_cbor failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    std::cout << "\n\nTransactions\n\n";

    try { 
        std::cout << client.transaction(TX_HASH).dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << "transaction failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    try { 
        std::cout << client.transaction_utxos(TX_HASH).dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << "transaction_utxos failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    try { 
        std::cout << client.transaction_stakes(TX_HASH).dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << "transaction_stakes failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    try { 
        std::cout << client.transaction_delegations(TX_HASH).dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << "transaction_delegations failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    try { 
        std::cout << client.transaction_withdrawals(TX_HASH).dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << "transaction_withdrawals failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    try { 
        std::cout << client.transaction_mirs(TX_HASH).dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << "transaction_mirs failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    try { 
        std::cout << client.transaction_pool_updates(TX_HASH).dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << "transaction_pool_updates failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    try { 
        std::cout << client.transaction_pool_retires(TX_HASH).dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << "transaction_pool_retires failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    try { 
        std::cout << client.transaction_metadata(TX_HASH).dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << "transaction_metadata failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    try { 
        std::cout << client.transaction_metadata_cbor(TX_HASH).dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << "transaction_metadata_cbor failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    try { 
        std::cout << client.transaction_redeemers(TX_HASH).dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << "transaction_redeemers failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    try { 
        std::cout << client.transaction_required_signers(TX_HASH).dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << "transaction_required_signers failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    try { 
        std::cout << client.transaction_cbor(TX_HASH).dump(2) << "\n";
        ++success_count;
    }
    catch (const std::exception& e) {
        std::cerr << "transaction_cbor failed\n";
        std::cerr << e.what() << '\n';
        ++failure_count;
    }

    // Note: transaction_submit requires actual CBOR data, so we'll skip it for now
    // as it would require a valid transaction to submit

    std::cout << "\n\nUtilities\n\n";

    // Note: utils_address_from_xpub requires a valid xpub, so we'll skip it for now
    // as it would require a valid extended public key

    // Note: utils_evaluate_tx and utils_evaluate_utxos require actual CBOR data, 
    // so we'll skip them for now as they would require valid transaction data

    
	std::cout << "\n\nSummary\n\n";
	std::cout << "Successful requests: " << success_count << "\n";
	std::cout << "Failed requests: " << failure_count << "\n";
	if (failure_count > 0) {
		std::cout << "Some requests failed. Please check the output for details.\n";
	}
	else {
		std::cout << "All requests were successful!\n";
	}

    return 0;
}
