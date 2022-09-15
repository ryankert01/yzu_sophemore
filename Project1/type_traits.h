#ifndef TYPE_TRAITS
#define TYPE_TRAITS

// FNV-1a UTILITIES
#if defined(_WIN64)
constexpr size_t FNVOffsetBasis = 14695981039346656037ULL;
constexpr size_t FNVPrime = 1099511628211ULL;
#else // defined(_WIN64)
constexpr size_t FNVOffsetBasis = 2166136261U; // 10000001 00011100 10011101 11000101
constexpr size_t FNVPrime = 16777619U;         // 00000001 00000000 00000001 10010011
#endif // defined(_WIN64)

// STRUCT TEMPLATE hash
template< typename kty >
struct hash
{
   // Computes hash value which will be used to compute bucket number
   size_t operator()( const kty &keyval ) const
   {
      size_t val = FNVOffsetBasis;
      const unsigned char* const first = &reinterpret_cast< const unsigned char & >( keyval );
      const size_t count = sizeof( kty );
      for( size_t idx = 0; idx < count; ++idx )
      {
         val ^= static_cast< size_t >( first[ idx ] );
         val *= FNVPrime;
      }
      return val;
   }
};

#endif // TYPE_TRAITS