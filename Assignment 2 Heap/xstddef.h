// xstddef internal header (core)

#ifndef XSTDDEF
#define XSTDDEF

// STRUCT TEMPLATE greater
template< typename Ty = void >
struct greater
{
   const bool operator()( const Ty &left, const Ty &right ) const
   {
      return left > right;
   }
};

// STRUCT TEMPLATE less
template< typename Ty = void >
struct less
{
   const bool operator()( const Ty &left, const Ty &right ) const
   {
      return left < right;
   }
};

#endif // XSTDDEF