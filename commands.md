# Setting up your environment

https://developers.eos.io/eosio-home/docs/setting-up-your-environment

# Start the wallet

```bash
keosd 
```

# Start the node

```bash
nodeos -e -p eosio \
--plugin eosio::producer_plugin \
--plugin eosio::chain_api_plugin \
--plugin eosio::http_plugin \
--plugin eosio::history_plugin \
--plugin eosio::history_api_plugin \
--data-dir CONTRACTS_DIR/eosio/data \
--config-dir CONTRACTS_DIR/eosio/config \
--access-control-allow-origin='*' \
--contracts-console \
--http-validate-host=false \
--verbose-http-errors \
--filter-on='*'
```

# Check if the wallet is running

```bash
cleos wallet list
```

# Check if the node is running

```bash
curl http://localhost:8888/v1/chain/get_info

OR

cleos get info
```

# Install Contract Development Toolkit (CDT)

```bash
https://developers.eos.io/eosio-home/docs/installing-the-contract-development-toolkit
```

# Wallet Operations

```bash

### Create a wallet
cleos wallet create --to-console
cleos wallet list

### Open a wallet
cleos wallet open 

### Unlock a wallet
cleos wallet unlock -n default

```

# Keys

```bash
### Creates a key-pair
cleos wallet create_key

### Import keys
cleos wallet import

#### eosio - development key
5KQwrPbwdL6PhXujxW37FSSQZ1JiwsST4cqQzDeyXtP79zkvFD3

```


# Account Operations
```bash
### Creating account
# cleos create account <creator account> <account name> <owner key>

cleos create account eosio alice <PUBLIC KEY>
cleos create account bob


cleos get account bob
```


# Contract operations

```bash
### Compile the contract
eosio-cpp -o hello.wasm hello.cpp --abigen

### Create account for the contract
cleos create account eosio hello YOUR_PUBLIC_KEY -p eosio@active

### Publishing the contract to EOS
cleos set contract hello CONTRACTS_DIR/hello -p hello@active
```

# Actions

```bash
cleos push action hello hi '["iitmumbai"]' -p bob@active
cleos push action hello hi '["iitmumbai"]' -p alice@active
```


# Certificate Contract
___


