#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <vector>

#include <set>
#include "set.h"

template< typename T, typename T1 = less< T >, typename T2 = std::less< T > >
void testSet1();

template< typename T, typename T1 = less< T >, typename T2 = std::less< T > >
void testSet2();

// returns true if and only if set1 == set2
template< typename T, typename T1, typename T2 >
bool equal(set< T, T1 >& set1, std::set< T, T2 >& set2);

// returns true if and only if 
// the subtree rooted at node1 is equal to the subtree rooted at node2
template< typename Kty >
bool equal(size_t* node1, size_t* head1,
    size_t* node2, size_t* head2);

size_t* minimum(size_t* node, size_t* head1);
size_t* maximum(size_t* node, size_t* head);

// call preorder1 and inorder1
template< typename T, typename T1 >
void twoTraversals1(set< T, T1 >& set1);

// preorder traversal on our set
template< typename Kty >
void preorder1(size_t* node, size_t* head);

// inorder traversal on our set
template< typename Kty >
void inorder1(size_t* node, size_t* head);

// call preorder2 and inorder2
template< typename T, typename T2 >
void twoTraversals2(std::set< T, T2 >& set2);

// preorder traversal on STL set
template< typename Kty >
void preorder2(size_t* node, size_t* head);

// inorder traversal on STL set
template< typename Kty >
void inorder2(size_t* node, size_t* head);

int main()
{
    for (unsigned int seed = 11; seed <= 20; seed++)
    {
        srand(seed);
        testSet1< short >();
    }
    cout << endl;

    for (unsigned int seed = 11; seed <= 20; seed++)
    {
        srand(seed);
        testSet2< short >();
    }
    cout << endl;

    for (unsigned int seed = 11; seed <= 20; seed++)
    {
        srand(seed);
        testSet1< short, greater< short >, std::greater< short > >();
    }
    cout << endl;

    for (unsigned int seed = 11; seed <= 20; seed++)
    {
        srand(seed);
        testSet2< short, greater< short >, std::greater< short > >();
    }
    cout << endl;

    for (unsigned int seed = 11; seed <= 20; seed++)
    {
        srand(seed);
        testSet1< long >();
    }
    cout << endl;

    for (unsigned int seed = 11; seed <= 20; seed++)
    {
        srand(seed);
        testSet2< long >();
    }
    cout << endl;

    for (unsigned int seed = 11; seed <= 20; seed++)
    {
        srand(seed);
        testSet1< long, greater< long >, std::greater< long > >();
    }
    cout << endl;

    for (unsigned int seed = 11; seed <= 20; seed++)
    {
        srand(seed);
        testSet2< long, greater< long >, std::greater< long > >();
    }
    cout << endl;

    for (unsigned int seed = 11; seed <= 20; seed++)
    {
        srand(seed);
        testSet1< long long >();
    }
    cout << endl;

    for (unsigned int seed = 11; seed <= 20; seed++)
    {
        srand(seed);
        testSet2< long long >();
    }
    cout << endl;

    for (unsigned int seed = 11; seed <= 20; seed++)
    {
        srand(seed);
        testSet1< long long, greater< long long >, std::greater< long long > >();
    }
    cout << endl;

    for (unsigned int seed = 11; seed <= 20; seed++)
    {
        srand(seed);
        testSet2< long long, greater< long long >, std::greater< long long > >();
    }
    cout << endl;

    system("pause");
}

template< typename T, typename T1, typename T2 >
void testSet1()
{
    int numKeys = 1000;
    T key;

    set< T, T1 > set1;
    std::set< T, T2 > set2;

    int numErrors = numKeys + 1;
    if (equal(set1, set2))
        numErrors--;

    for (int i = 0; i < numKeys; i++)
    {
        switch (rand() % 3)
        {
        case 0:
            key = 1 + rand() % (5 * numKeys);
            set1.insert(key);
            set2.insert(key);

            //         twoTraversals1< T, T1 >( set1 );
            //         twoTraversals2< T, T2 >( set2 );
            break;
        case 1:
            if (set2.size() > 0)
            {
                key = 1 + rand() % (5 * numKeys);
                set1.erase(key);
                set2.erase(key);

                //            twoTraversals1< T, T1 >( set1 );
                //            twoTraversals2< T, T2 >( set2 );
            }
        }

        if (equal(set1, set2))
            numErrors--;
    }

    cout << "There are " << numErrors << " errors.\n";
}

template< typename T, typename T1, typename T2 >
void testSet2()
{
    int numKeys = 1000;
    std::vector< T > keys;
    T key;

    set< T, T1 > set1;
    std::set< T, T2 > set2;

    int numErrors = numKeys + 1;
    if (equal(set1, set2))
        numErrors--;

    for (int i = 0; i < numKeys; i++)
    {
        switch (rand() % 3)
        {
        case 0:
        case 1:
            key = 1 + rand() % (5 * numKeys);
            keys.push_back(key);

            set1.insert(key);
            set2.insert(key);

            //         twoTraversals1< T, T1 >( set1 );
            //         twoTraversals2< T, T2 >( set2 );
            break;
        case 2:
            if (set2.size() > 0)
            {
                size_t pos = rand() % keys.size();
                key = keys[pos];
                keys.erase(keys.begin() + pos);

                set1.erase(key);
                set2.erase(key);

                //            twoTraversals1< T, T1 >( set1 );
                //            twoTraversals2< T, T2 >( set2 );
            }
        }

        if (equal(set1, set2))
            numErrors--;
    }

    cout << "There are " << numErrors << " errors.\n";
}

unsigned long long int twoTo32 = static_cast<unsigned long long int>(ULONG_MAX) + 1;

#if _ITERATOR_DEBUG_LEVEL == 2 // Solution Configuration is Debug
size_t offset1 = 1;
size_t offset2 = 2;
#else                        // Solution Configuration is Release
size_t offset1 = 0;
size_t offset2 = 1;
#endif

// returns true if and only if set1 == set2
template< typename T, typename T1, typename T2 >
bool equal(set< T, T1 >& set1, std::set< T, T2 >& set2)
{
    size_t size1 = *(reinterpret_cast<size_t*>(&set1) + 2);
    size_t size2 = *(reinterpret_cast<size_t*>(&set2) + offset2);

    if (size1 != size2)
        return false;

    size_t* head1 = *(reinterpret_cast<size_t**>(&set1) + 1);
    size_t* head2 = *(reinterpret_cast<size_t**>(&set2) + offset1);

    char color1 = static_cast<char>(*(head1 + 3) % 256);
    char color2 = static_cast<char>(*(head2 + 3) % 256);

    if (color1 != color2)
        return false;

    char isNil1 = static_cast<char>(*(head1 + 3) / 256 % 256);
    char isNil2 = static_cast<char>(*(head2 + 3) / 256 % 256);

    if (isNil1 != isNil2)
        return false;

    if (size1 == 0)
        return true;

    size_t* root1 = *(reinterpret_cast<size_t**>(head1) + 1);
    size_t* root2 = *(reinterpret_cast<size_t**>(head2) + 1);

    if (*(reinterpret_cast<size_t**>(head1)) != minimum(root1, head1))
        return false;

    if (*(reinterpret_cast<size_t**>(head1) + 2) != maximum(root1, head1))
        return false;

    return equal< T >(root1, head1, root2, head2);
}

size_t* minimum(size_t* node, size_t* head)
{
    size_t* leftChild = *(reinterpret_cast<size_t**>(node));
    while (leftChild != head)
    {
        node = leftChild;
        leftChild = *(reinterpret_cast<size_t**>(node));
    }
    return node;
}

size_t* maximum(size_t* node, size_t* head)
{
    size_t* rightChild = *(reinterpret_cast<size_t**>(node) + 2);
    while (rightChild != head)
    {
        node = rightChild;
        rightChild = *(reinterpret_cast<size_t**>(node) + 2);
    }
    return node;
}

// returns true if and only if 
// the subtree rooted at node1 is equal to the subtree rooted at node2
template< typename Kty >
bool equal(size_t* node1, size_t* head1, size_t* node2, size_t* head2)
{
    // node1 == head1 if and only if node1 is an external node
    // node2 == head2 if and only if node2 is an external node
    if (node1 == head1 && node2 == head2)
        return true;

    if (node1 == head1 && node2 != head2)
        return false;

    if (node1 != head1 && node2 == head2)
        return false;

    char color1 = static_cast<char>(*(node1 + 3) % 256);
    char color2 = static_cast<char>(*(node2 + 3) % 256);
    if (color1 != color2)
        return false;

    char isNil1 = static_cast<char>(*(node1 + 3) / 256 % 256);
    char isNil2 = static_cast<char>(*(node2 + 3) / 256 % 256);
    if (isNil1 != isNil2)
        return false;

    Kty myVal1;
    Kty myVal2;
    if (sizeof(size_t) == 8) // x64 platform
    {
        switch (sizeof(Kty))
        {
        case 1:
            myVal1 = static_cast<Kty>(*(node1 + 3) / 65536 % 256);
            myVal2 = static_cast<Kty>(*(node2 + 3) / 65536 % 256);
            break;
        case 2:
            myVal1 = static_cast<Kty>(*(node1 + 3) / 65536 % 65536);
            myVal2 = static_cast<Kty>(*(node2 + 3) / 65536 % 65536);
            break;
        case 4:
            myVal1 = static_cast<Kty>(*(node1 + 3) / twoTo32);
            myVal2 = static_cast<Kty>(*(node2 + 3) / twoTo32);
            break;
        case 8:
            myVal1 = static_cast<Kty>(*(node1 + 4));
            myVal2 = static_cast<Kty>(*(node2 + 4));
        }
    }
    else // x86 platform
    {
        switch (sizeof(Kty))
        {
        case 1:
            myVal1 = static_cast<Kty>(*(node1 + 3) / 65536 % 256);
            myVal2 = static_cast<Kty>(*(node2 + 3) / 65536 % 256);
            break;
        case 2:
            myVal1 = static_cast<Kty>(*(node1 + 3) / 65536);
            myVal2 = static_cast<Kty>(*(node2 + 3) / 65536);
            break;
        case 4:
            myVal1 = static_cast<Kty>(*(node1 + 4));
            myVal2 = static_cast<Kty>(*(node2 + 4));
            break;
        case 8:
            myVal1 = static_cast<Kty>(*(node1 + 4));
            myVal2 = static_cast<Kty>(*(node2 + 4));
        }
    }

    if (myVal1 != myVal2)
        return false;

    size_t* leftChild1 = *(reinterpret_cast<size_t**>(node1));
    size_t* rightChild1 = *(reinterpret_cast<size_t**>(node1) + 2);
    size_t* leftChild2 = *(reinterpret_cast<size_t**>(node2));
    size_t* rightChild2 = *(reinterpret_cast<size_t**>(node2) + 2);

    return equal< Kty >(leftChild1, head1, leftChild2, head2) &&
        equal< Kty >(rightChild1, head1, rightChild2, head2);
}

template< typename T, typename T1 >
void twoTraversals1(set< T, T1 >& set1)
{
    size_t* head1 = *(reinterpret_cast<size_t**>(&set1) + 1);
    size_t* root1 = *(reinterpret_cast<size_t**>(head1 + 1));

    cout << "our set:\n";
    cout << "Preorder sequence:\n";
    preorder1< T >(root1, head1);

    cout << "\nInorder sequence:\n";
    inorder1< T >(root1, head1);
    cout << endl << endl;
}

// preorder traversal
template< typename Kty >
void preorder1(size_t* node, size_t* head)
{
    if (node != head)
    {
        Kty myVal;
        if (sizeof(size_t) == 8) // x64 platform
        {
            switch (sizeof(Kty))
            {
            case 1:
                myVal = static_cast<Kty>(*(node + 3) / 65536 % 256);
                break;
            case 2:
                myVal = static_cast<Kty>(*(node + 3) / 65536 % 65536);
                break;
            case 4:
                myVal = static_cast<Kty>(*(node + 3) / twoTo32);
                break;
            case 8:
                myVal = static_cast<Kty>(*(node + 4));
            }
        }
        else // x86 platform
        {
            switch (sizeof(Kty))
            {
            case 1:
                myVal = static_cast<Kty>(*(node + 3) / 65536 % 256);
                break;
            case 2:
                myVal = static_cast<Kty>(*(node + 3) / 65536);
                break;
            case 4:
                myVal = static_cast<Kty>(*(node + 4));
                break;
            case 8:
                myVal = static_cast<Kty>(*(node + 4));
            }
        }

        char color = static_cast<char>(*(node + 3) % 256);
        cout << setw(5) << myVal << (color == 0 ? "R" : "B");

        size_t* leftChild = *(reinterpret_cast<size_t**>(node));
        size_t* rightChild = *(reinterpret_cast<size_t**>(node) + 2);
        preorder1< Kty >(leftChild, head);
        preorder1< Kty >(rightChild, head);
    }
}

// inorder traversal
template< typename Kty >
void inorder1(size_t* node, size_t* head)
{
    if (node != head)
    {
        size_t* leftChild = *(reinterpret_cast<size_t**>(node));
        inorder1< Kty >(leftChild, head);

        Kty myVal;
        if (sizeof(size_t) == 8) // x64 platform
        {
            switch (sizeof(Kty))
            {
            case 1:
                myVal = static_cast<Kty>(*(node + 3) / 65536 % 256);
                break;
            case 2:
                myVal = static_cast<Kty>(*(node + 3) / 65536 % 65536);
                break;
            case 4:
                myVal = static_cast<Kty>(*(node + 3) / twoTo32);
                break;
            case 8:
                myVal = static_cast<Kty>(*(node + 4));
            }
        }
        else // x86 platform
        {
            switch (sizeof(Kty))
            {
            case 1:
                myVal = static_cast<Kty>(*(node + 3) / 65536 % 256);
                break;
            case 2:
                myVal = static_cast<Kty>(*(node + 3) / 65536);
                break;
            case 4:
                myVal = static_cast<Kty>(*(node + 4));
                break;
            case 8:
                myVal = static_cast<Kty>(*(node + 4));
            }
        }

        char color = static_cast<char>(*(node + 3) % 256);
        cout << setw(5) << myVal << (color == 0 ? "R" : "B");

        size_t* rightChild = *(reinterpret_cast<size_t**>(node) + 2);
        inorder1< Kty >(rightChild, head);
    }
}

template< typename T, typename T2 >
void twoTraversals2(std::set< T, T2 >& set2)
{
    size_t* head2 = *(reinterpret_cast<size_t**>(&set2) + offset1);
    size_t* root2 = *(reinterpret_cast<size_t**>(head2 + 1));

    cout << "STL set:\n";
    cout << "Preorder sequence:\n";
    preorder2< T >(root2, head2);

    cout << "\nInorder sequence:\n";
    inorder2< T >(root2, head2);
    cout << endl << endl;
}

// preorder traversal
template< typename Kty >
void preorder2(size_t* node, size_t* head)
{
    if (node != head)
    {
        Kty myVal;
        if (sizeof(size_t) == 8) // x64 platform
        {
            switch (sizeof(Kty))
            {
            case 1:
                myVal = static_cast<Kty>(*(node + 3) / 65536 % 256);
                break;
            case 2:
                myVal = static_cast<Kty>(*(node + 3) / 65536 % 65536);
                break;
            case 4:
                myVal = static_cast<Kty>(*(node + 3) / twoTo32);
                break;
            case 8:
                myVal = static_cast<Kty>(*(node + 4));
            }
        }
        else // x86 platform
        {
            switch (sizeof(Kty))
            {
            case 1:
                myVal = static_cast<Kty>(*(node + 3) / 65536 % 256);
                break;
            case 2:
                myVal = static_cast<Kty>(*(node + 3) / 65536);
                break;
            case 4:
                myVal = static_cast<Kty>(*(node + 4));
                break;
            case 8:
                myVal = static_cast<Kty>(*(node + 4));
            }
        }

        char color = static_cast<char>(*(node + 3) % 256);
        cout << setw(5) << myVal << (color == 0 ? "R" : "B");

        size_t* leftChild = *(reinterpret_cast<size_t**>(node));
        size_t* rightChild = *(reinterpret_cast<size_t**>(node) + 2);
        preorder2< Kty >(leftChild, head);
        preorder2< Kty >(rightChild, head);
    }
}

// inorder traversal
template< typename Kty >
void inorder2(size_t* node, size_t* head)
{
    if (node != head)
    {
        size_t* leftChild = *(reinterpret_cast<size_t**>(node));
        inorder2< Kty >(leftChild, head);

        Kty myVal;
        if (sizeof(size_t) == 8) // x64 platform
        {
            switch (sizeof(Kty))
            {
            case 1:
                myVal = static_cast<Kty>(*(node + 3) / 65536 % 256);
                break;
            case 2:
                myVal = static_cast<Kty>(*(node + 3) / 65536 % 65536);
                break;
            case 4:
                myVal = static_cast<Kty>(*(node + 3) / twoTo32);
                break;
            case 8:
                myVal = static_cast<Kty>(*(node + 4));
            }
        }
        else // x86 platform
        {
            switch (sizeof(Kty))
            {
            case 1:
                myVal = static_cast<Kty>(*(node + 3) / 65536 % 256);
                break;
            case 2:
                myVal = static_cast<Kty>(*(node + 3) / 65536);
                break;
            case 4:
                myVal = static_cast<Kty>(*(node + 4));
                break;
            case 8:
                myVal = static_cast<Kty>(*(node + 4));
            }
        }

        char color = static_cast<char>(*(node + 3) % 256);
        cout << setw(5) << myVal << (color == 0 ? "R" : "B");

        size_t* rightChild = *(reinterpret_cast<size_t**>(node) + 2);
        inorder2< Kty >(rightChild, head);
    }
}