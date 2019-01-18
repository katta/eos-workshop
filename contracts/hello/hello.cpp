#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>

using namespace eosio;

class hello : public contract {
  public:
      using contract::contract;
  
      /*
       * Action definition that prints a name with a greeting.
       */
      [[eosio::action]] // attribute used by ABI generator
      void hi( name user ) {

         // require_auth( user );
         print( "Hello, ", name{user});
      }
};

// macro handles the dispatching of actions
EOSIO_DISPATCH( hello, (hi)) 
