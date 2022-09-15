#include <iostream>
using std::cout;
using std::endl;

#include <unordered_set>
#include "unordered_set.h"

template< typename T >
bool duplicate( T *values, size_t i )
{
   for( size_t j = 0; j < i; j++ )
      if( values[ j ] == values[ i ] )
         return true;
   return false;
}

template< typename T >
void testUnorderedSet();

template< typename T >
void testUnorderedSet1( size_t numData );

template< typename T >
void testUnorderedSet2();

template< typename T >
bool equal( unordered_set< T > &left, std::unordered_set< T > &right );

int main()
{
   testUnorderedSet< char >();

   testUnorderedSet< short >();

   testUnorderedSet< long >();

   testUnorderedSet< long long >();

   system( "pause" );
}

template< typename T >
void testUnorderedSet()
{
   size_t numDatas[] = { 8, 64, 512, 1024 };
   size_t numCases = ( sizeof( T ) == 1 ) ? 2 : 4;
   for( unsigned int i = 0; i < numCases; i++ )
   {
      srand( i );
      testUnorderedSet1< T >( numDatas[ i ] );
   }

   cout << endl;

   for( unsigned int seed = 51; seed <= 60; seed++ )
   {
      srand( seed );
      testUnorderedSet1< T >( rand() );
   }

   cout << endl;

   for( unsigned int seed = 1; seed <= 10; seed++ )
   {
      srand( seed );
      testUnorderedSet2< T >();
   }

   cout << endl;
}

template< typename T >
void testUnorderedSet1( size_t numData )
{
   unordered_set< T > data1;
   std::unordered_set< T > data2;

   size_t numErrors = numData + 1;
   if( equal( data1, data2 ) )
      numErrors--;

   T *values = new T[ numData ];
   for( size_t i = 0; i < numData; i++ )
   {
      do values[ i ] = static_cast< T >( rand() % ( 5 * numData ) );
      while( duplicate< T >( values, i ) );
   }

   for( size_t i = 0; i < numData; i++ )
   {
      data1.insert( values[ i ] );
      data2.insert( values[ i ] );

      if( equal( data1, data2 ) )
         numErrors--;
   }

   cout << "There are " << numErrors << " errors.\n";
}

template< typename T >
void testUnorderedSet2()
{
   unordered_set< T > data1;
   std::unordered_set< T > data2;

   T maxValue = 99;
   size_t numErrors = 500;
   T value;
   for( size_t i = 0; i < 500; i++ )
   {
      value = 1 + rand() % maxValue;
      switch( rand() % 2 )
      {
      case 0:
         data1.insert( value );
         data2.insert( value );
         break;
      case 1:
         if( data1.size() > 0 )
         {
            data1.erase( value );
            data2.erase( value );
         }
         break;
      default:
         break;
      }

      if( equal( data1, data2 ) )
         numErrors--;
   }

   cout << "There are " << numErrors << " errors.\n";
}

// Determines if two unordered_sets are equal.
template< typename T >
bool equal( unordered_set< T > &left, std::unordered_set< T > &right )
{
   if( left.size() != right.size() )
      return false;

   if( left.bucket_count() != right.bucket_count() )
      return false;

#if _ITERATOR_DEBUG_LEVEL == 2 // Solution Configuration is Debug
   size_t offset1 = 2;
   size_t offset2 = 5;
   size_t offset3 = 4;
#else                        // Solution Configuration is Release
   size_t offset1 = 1;
   size_t offset2 = 3;
   size_t offset3 = 3;
#endif

   typedef typename std::list< T >::_Unchecked_iterator RightIt;
   RightIt rightListHead = *( reinterpret_cast< RightIt * >( &right ) + offset1 );
   RightIt *rightVecFirst = *( reinterpret_cast< RightIt ** >( &right ) + offset2 );

   typedef typename list< T >::iterator ListIt;
   ListIt *leftVecFirst = *( reinterpret_cast< ListIt ** >( &left ) + offset3 );
   for( size_t bucketNo = 0; bucketNo < right.bucket_count(); bucketNo++ )
   {
      if( left.bucket_size( bucketNo ) != right.bucket_size( bucketNo ) )
         return false;

      ListIt leftBucketFirst = leftVecFirst[ 2 * bucketNo ];
      ListIt leftBucketLast = leftVecFirst[ 2 * bucketNo + 1 ];
      RightIt rightBucketFirst = rightVecFirst[ 2 * bucketNo ]; // an iterator pointing to the first element in right._List for bucket bucketNo
      RightIt rightBucketLast = rightVecFirst[ 2 * bucketNo + 1 ];

      if( rightBucketFirst != rightListHead )
      {
         if( rightBucketFirst != rightBucketLast )
         {
            ListIt leftIt = leftBucketFirst;
            RightIt rightIt = rightBucketFirst;
            while( rightIt != rightBucketLast )
            {
               if( *leftIt != *rightIt )
                  return false;

               ++leftIt;
               ++rightIt;
            }
         }

         if( *leftBucketLast != *rightBucketLast )
            return false;
      }
   }

   ListIt leftIt = *leftVecFirst; 
   RightIt rightIt = *rightVecFirst;
   while( rightIt != rightListHead ) // compare the whole list in left with the whole list in right
   {
      if( *leftIt != *rightIt )
         return false;
      ++leftIt;
      ++rightIt;
   }

   return true;
}