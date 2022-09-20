// testing priority queues

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

//#include "deque.h"

#include <queue>
using std::deque;

#include "priority_queue.h"

template< typename T >
void testPriorityQueue();

template< typename T, typename T1, typename T2, typename T3 = less< T >,
                                             typename T4 = std::less< T > >
void testContructor();

template< typename T, typename T1, typename T2, typename T3 = less< T >,
                                             typename T4 = std::less< T > >
void testPush();

template< typename T, typename T1, typename T2, typename T3 = less< T >,
                                             typename T4 = std::less< T > >
void testPop();

template< typename T, typename T1, typename T2, typename T3 = less< T >,
                                             typename T4 = std::less< T > >
void testPushPop();

template< typename T1, typename T2 >
bool equal( T1 &v1, T2 &v2 );

int main()
{
   testPriorityQueue< char >();
   testPriorityQueue< short >();
   testPriorityQueue< long >();
   testPriorityQueue< long long >();

   system( "pause" );
}

template< typename T >
void testPriorityQueue()
{
   testContructor< T, vector< T >, std::vector< T > >();
   testContructor< T, vector< T >, std::vector< T >, greater< T >, std::greater< T > >();

   testPush< T, vector< T >, std::vector< T > >();
   testPush< T, vector< T >, std::vector< T >, greater< T >, std::greater< T > >();

   testPop< T, vector< T >, std::vector< T > >();
   testPop< T, vector< T >, std::vector< T >, greater< T >, std::greater< T > >();

   testPushPop< T, vector< T >, std::vector< T > >();
   testPushPop< T, vector< T >, std::vector< T >, greater< T >, std::greater< T > >();

   testContructor< T, deque< T >, std::deque< T > >();
   testContructor< T, deque< T >, std::deque< T >, greater< T >, std::greater< T > >();

   testPush< T, deque< T >, std::deque< T > >();
   testPush< T, deque< T >, std::deque< T >, greater< T >, std::greater< T > >();

   testPop< T, deque< T >, std::deque< T > >();
   testPop< T, deque< T >, std::deque< T >, greater< T >, std::greater< T > >();

   testPushPop< T, deque< T >, std::deque< T > >();
   testPushPop< T, deque< T >, std::deque< T >, greater< T >, std::greater< T > >();

   cout << endl;
}

template< typename T, typename T1, typename T2, typename T3, typename T4 >
void testContructor()
{
   int num = 100;
   int numErrors = num;
   T myints[ 100 ];
   T1 v1;
   T2 v2;

   for( int i = 0; i < num; i++ )
   {
      int size = rand() % 100;
      for( int j = 0; j < size; j++ )
         myints[ j ] = 1 + rand() % 99;

      priority_queue< T, T1, T3 > pq1( myints, myints + size );
      v1 = *( reinterpret_cast< T1 * >( &pq1 ) );

      std::priority_queue< T, T2, T4 > pq2( myints, myints + size );
      v2 = *( reinterpret_cast< T2 * >( &pq2 ) );

      if( equal( v1, v2 ) )
         numErrors--;
   }

   cout << "There are " << numErrors << " errors.\n";
}

template< typename T, typename T1, typename T2, typename T3, typename T4 >
void testPush()
{
   int num = 100;
   int numErrors = num;
   T myints[ 100 ];
   T1 v1;
   T2 v2;

   for( int i = 0; i < num; i++ )
   {
      int size = rand() % 100;
      for( int j = 0; j < size; j++ )
         myints[ j ] = 1 + rand() % 99;

      priority_queue< T, T1, T3 > pq1( myints, myints + size );
      v1 = *( reinterpret_cast< T1 * >( &pq1 ) );

      std::priority_queue< T, T2, T4 > pq2( myints, myints + size );
      v2 = *( reinterpret_cast< T2 * >( &pq2 ) );

      T value = 1 + rand() % 99;
      pq1.push( value );
      pq2.push( value );

      if( equal( v1, v2 ) )
         numErrors--;
   }

   cout << "There are " << numErrors << " errors.\n";
}

template< typename T, typename T1, typename T2, typename T3, typename T4 >
void testPop()
{
   int num = 100;
   int numErrors = num;
   T myints[ 100 ];
   T1 v1;
   T2 v2;

   for( int i = 0; i < num; i++ )
   {
      int size = rand() % 100;
      for( int j = 0; j < size; j++ )
         myints[ j ] = 1 + rand() % 99;

      priority_queue< T, T1, T3 > pq1( myints, myints + size );
      v1 = *( reinterpret_cast< T1 * >( &pq1 ) );

      std::priority_queue< T, T2, T4 > pq2( myints, myints + size );
      v2 = *( reinterpret_cast< T2 * >( &pq2 ) );

      if( pq1.size() > 0 )
      {
         pq1.pop();
         pq2.pop();
      }

      if( equal( v1, v2 ) )
         numErrors--;
   }

   cout << "There are " << numErrors << " errors.\n";
}

template< typename T, typename T1, typename T2, typename T3, typename T4 >
void testPushPop()
{
   int num = 100;
   int numErrors = num;
   priority_queue< T, T1, T3 > pq1;
   std::priority_queue< T, T2, T4 > pq2;
   T1 v1;
   T2 v2;
   T value;

   for( int i = 0; i < num; i++ )
   {
      switch( rand() % 2 )
      {
         case 0:
            value = 1 + rand() % 99;
            pq1.push( value );
            pq2.push( value );
            break;
         case 1:
            if( pq1.size() > 0 )
            {
               pq1.pop();
               pq2.pop();
            }
      }

      v1 = *( reinterpret_cast< T1 * >( &pq1 ) );
      v2 = *( reinterpret_cast< T2 * >( &pq2 ) );
      if( equal( v1, v2 ) )
         numErrors--;
   }

   cout << "There are " << numErrors << " errors.\n";
}

template< typename T1, typename T2 >
bool equal( T1 &v1, T2 &v2 )
{
   if( v1.size() != v2.size() )
      return false;

   for( unsigned int i = 0; i < v1.size(); i++ )
      if( v1[ i ] != v2[ i ] )
         return false;

   return true;
}