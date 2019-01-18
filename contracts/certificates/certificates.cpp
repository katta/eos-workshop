#include <eosiolib/eosio.hpp>

using namespace eosio;

class [[eosio::contract]] certificates : public contract {

  public:
    using contract::contract;

    [[eosio::action]]
    void create(
      uint64_t id,
      std::string name,
      std::string major
    ) {
     
      require_auth(_self);
      datastore ds(_self, _self.value);
      ds.emplace(_self, [&](auto& row) {
        row.id = id;
        row.name = name;
        row.major = major;
        row.timestamp = now();
      });
    }

    [[eosio::action]]
    void deleteall() {
      require_auth(_self);
      datastore ds(_self, _self.value);
      for(auto itr = ds.begin(); itr != ds.end();) {
        itr = ds.erase(itr);
      }
    }

  private:
    struct [[eosio::table]] certificate {
      uint64_t		 id;
      std::string  name;
      std::string  major;
      uint64_t     timestamp;

      uint64_t primary_key() const { return id; }
    };

    typedef eosio::multi_index<"certificate"_n, certificate> datastore;

};

EOSIO_DISPATCH(certificates, ( create )( deleteall ))
