// unordered_set standard header

#ifndef UNORDERED_SET
#define UNORDERED_SET

#include "type_traits.h"
#include "xhash.h"

// CLASS TEMPLATE UsetTraits
template< typename Kty, // key type (same as value type)
          typename Tr > // comparator predicate type
class UsetTraits : public Tr // traits required to make Hash behave like a set
{
public:
   using key_type = Kty;
   using value_type = Kty;
   using key_compare = Tr;

   explicit UsetTraits( const Tr& traits )
      : Tr( traits )
   {
   }
};

// CLASS TEMPLATE unordered_set
template< typename Kty, typename Hasher = hash< Kty > >
class unordered_set : public Hash< UsetTraits< Kty, Hasher > >
{
   // hash table of key-values, unique keys
private:
   using Mybase = Hash< UsetTraits< Kty, Hasher > >;
   using KeyCompare = typename Mybase::KeyCompare;

public:
   unordered_set()
      : Mybase( KeyCompare() ) // Hasher()
   {
   }
};

#endif // UNORDERED_SET