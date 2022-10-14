// set standard header

#ifndef SET
#define SET

#include "xtree.h"
#include "xstddef.h"

// CLASS TEMPLATE TsetTraits
template< typename Kty, // key/value type
          typename Pr > // comparator predicate type
class TsetTraits // traits required to make Tree behave like a set
{
public:
   using key_type = Kty;
   using value_type = Kty;
   using key_compare = Pr;
   using value_compare = key_compare;
};

// CLASS TEMPLATE set
template< typename Kty, typename Pr = less< Kty > >
class set : public Tree< TsetTraits< Kty, Pr > >
{  // ordered red-black tree of key values, unique keys
public:
   using key_compare = Pr;

   set()
      : Tree< TsetTraits< Kty, Pr > >( key_compare() )
   {
   }
};

#endif // SET