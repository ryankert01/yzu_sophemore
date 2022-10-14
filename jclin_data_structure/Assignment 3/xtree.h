// xtree internal header
#define swap(x, y) (x ^= y), (y ^= x), (x ^= y)
#define dir(gu) ((gu->parent == myHead) ? myHead->parent : (gu->parent->left == gu) ? gu->parent->left : gu->parent->right)
#define sib(u) ((u->parent == myHead) ? myHead : (u->parent->left == u) ? u->parent->right : u->parent->left)
#define Red 0
#define Black 1
#ifndef XTREE
#define XTREE

template< typename Ty >
struct TreeNode
{
   using NodePtr = TreeNode *;
   using value_type = Ty;

   NodePtr    left;   // left subtree, or smallest element if head
   NodePtr    parent; // parent, or root of tree if head
   NodePtr    right;  // right subtree, or largest element if head
   char       color;  // 0: Red, 1: Black; Black if head
   char       isNil;  // 1 only if head (also nil) node
   value_type myval;  // the stored value, unused if head
};

// CLASS TEMPLATE TreeVal
template< typename Ty >
class TreeVal
{
public:
   using NodePtr = TreeNode< Ty > *;

   using value_type = Ty;
   using size_type  = size_t;

   TreeVal()
      : myHead( new TreeNode< value_type > ),
        mySize( 0 )
   {
      myHead->left = myHead;
      myHead->parent = myHead;
      myHead->right = myHead;
      myHead->color = 1;
      myHead->isNil = 1;
   }

   ~TreeVal()
   {
      clear( myHead->parent );
      delete myHead;
   }

   // Removes all elements from the set object (which are destroyed)
   void clear( TreeNode< value_type > *node )
   {
      if( !node->isNil ) // node is not an external node
      {
         clear( node->left );
         clear( node->right );
         delete node;
      }
   }

   // rebalance for insertion; u points to the inserted node
   void reBalance(TreeNode< value_type >* u)
   {  // u->parent cannot be the root
       TreeNode< value_type >* pu = u->parent;
       TreeNode< value_type >* gu = pu->parent;
       TreeNode< value_type >* uncle = sib(pu);

       if (uncle->color == Red) { // if uncle is Red
           uncle->color = Black;
           pu->color = Black;
           if (gu->parent != myHead) {
               gu->color = Red;
               if (gu->parent->color == Red)
                   reBalance(gu);
           }

       }
       else {
           if (gu->left == pu) {
               if (pu->left == u) { //LL
                   pu->color = Black, gu->color = Red;
                   LLRotation(pu);
               }
               else { // LR
                   u->color = Black, gu->color = Red;
                   LRRotation(u);
               }
           }
           else {
               if (pu->left == u) { // RL
                   u->color = Black, gu->color = Red;
                   RLRotation(u);
               }
               else { // RR
                   pu->color = Black, gu->color = Red;
                   RRRotation(pu);
               }

           }
       }

   }

   // rotate right at gu, where pu = gu->left and u = pu->left
   void LLRotation( TreeNode< value_type > *pu )
   {
      TreeNode< value_type > *gu = pu->parent;
      pu->parent = gu->parent;
      dir(gu) = pu;

      if(pu->right != myHead)
          pu->right->parent = gu;
      
      gu->left = pu->right;

      gu->parent = pu;
      pu->right = gu;
   }

   // LR rotation; pu = gu->left and u = pu->right
   void LRRotation( TreeNode< value_type > *u )
   {
      TreeNode< value_type > *pu = u->parent;
      TreeNode< value_type > *gu = pu->parent;

      RRRotation(u);
      LLRotation(u);

   }

   // RL rotation; pu = gu->right and u = pu->left
   void RLRotation( TreeNode< value_type > *u )
   {
      TreeNode< value_type > *pu = u->parent;
      TreeNode< value_type > *gu = pu->parent;

      LLRotation(u);
      RRRotation(u);

   }

   // rotate left at gu, where pu = gu->right and u = pu->right
   void RRRotation( TreeNode< value_type > *pu )
   {
      TreeNode< value_type > *gu = pu->parent;
      pu->parent = gu->parent;
      dir(gu) = pu;
      
      if(pu->left != myHead) 
          pu->left->parent = gu;
      gu->right = pu->left;

      gu->parent = pu;
      pu->left = gu;
   }

    // erase p provided that the degree of p is at most one
    // p points to the node to be deleted
    // p == M in "Ch 10 Sec 3.pptx"
   void eraseDegreeOne(TreeNode< value_type >* p)
   {
       TreeNode< value_type >* child;
       if (p->left != myHead)
           child = p->left;
       else if (p->right != myHead)
           child = p->right;
       else
           child = myHead;

       if (p == myHead->parent) // p points to the root; Case 3 in "Ch 10 Sec 3.pptx"
       {
           // set child to be the new root
           child->color = Black;
           child->parent = myHead;
           myHead->parent = child;
       }
       else
       {
           TreeNode< value_type >* pp = p->parent;

           (pp->left == p ? pp->left : pp->right) = child;
           if (child != myHead)
               child->parent = pp;


           if (p->color == 1)
               if (child->color == 0) // Case 2 in "Ch 10 Sec 3.pptx"
                   child->color = 1;
               else                   // Case 4 in "Ch 10 Sec 3.pptx"
                   fixUp(child, p->parent);
       }

       delete p;
       mySize--;
   }
   // rebalance for deletion; Case 4 in "Ch 10 Sec 3.pptx"
   void fixUp(TreeNode< value_type >* N, TreeNode< value_type >* P)
   {
       TreeNode<value_type>* S = (P->left == N) ? P->right : P->left;

       if (S->color == Red) { // 4.1.x
           swap(S->color, P->color);
           if (P->left == N) {
               RRRotation(S);
           }
           else {
               LLRotation(S);
           }
           fixUp(N, P);
       }
       else {
           if (S->right->color == Red && P->left == N) { // 4.2.1
               swap(S->color, P->color);
               S->right->color = Black;
               RRRotation(S);
           }
           else if (S->left->color == Red && P->right == N) { // 4.2.2
               swap(S->color, P->color);
               S->left->color = Black;
               LLRotation(S);
           }
           else if (S->right->color == Black && P->left == N && S->left->color == Red) { // 4.3.1
               swap(S->color, S->left->color);
               LLRotation(S->left);
               fixUp(N, P);
           }
           else if (S->left->color == Black && P->right == N && S->right->color == Red) { // 4.3.2
               swap(S->color, S->right->color);
               RRRotation(S->right);
               fixUp(N, P);
           }
           else if (S->right->color == Black && S->left->color == Black) {
               if (P->color == Red) { // 4.4
                   swap(S->color, P->color);
               }
               else { // 4.5
                   S->color = Red;
                   if (P->parent != myHead)
                       fixUp(P, P->parent);
               }
           }
       }
   }


   NodePtr myHead;   // pointer to head node
   size_type mySize; // number of elements
};

// CLASS TEMPLATE Tree
template< typename Traits >
class Tree // ordered red-black tree for map/multimap/set/multiset
{
public:
   using value_type = typename Traits::value_type;

protected:
   using ScaryVal = TreeVal< value_type >;

public:
   using key_type      = typename Traits::key_type;
   using key_compare   = typename Traits::key_compare;

   using size_type       = size_t;

   Tree( const key_compare &parg )
      : keyCompare( parg ),
        scaryVal()
   {
   }

   ~Tree()
   {
   }

   // Extends the container by inserting a new element,
   // effectively increasing the container size by one.
   void insert( const value_type &val )
   {
      if( scaryVal.mySize == 0 )
      {
         TreeNode< value_type > *root = new TreeNode< value_type >;
         root->myval = val;
         root->left = scaryVal.myHead;
         root->right = scaryVal.myHead;
         root->isNil = 0;
         root->parent = scaryVal.myHead;
         root->color = 1;
         scaryVal.myHead->left = root;
         scaryVal.myHead->parent = root;
         scaryVal.myHead->right = root;
         scaryVal.mySize = 1;
      }
      else
      {                           // scaryVal.myHead->parent points to the root
         TreeNode< value_type > *p = scaryVal.myHead->parent; // p points to the root
         TreeNode< value_type > *pp = scaryVal.myHead;
         while( p != scaryVal.myHead )
         {
            pp = p;
//              keyCompare.operator()( val, p->myval )
            if( keyCompare( val, p->myval ) ) // if( val < p->myval )
               p = p->left;
            else if( keyCompare( p->myval, val ) ) // if( val > p->myval )
               p = p->right;
            else
               return;
         }
         p = new TreeNode<value_type>;
         p->myval = val;
         p->left = scaryVal.myHead;
         p->right = scaryVal.myHead;
         p->parent = pp;
         p->color = Red;
         p->isNil = 0;
         (keyCompare(val, pp->myval) ? pp->left : pp->right) = p;
         if(pp->color == Red) 
             scaryVal.reBalance(p);
         // update max min
         if (keyCompare(val, scaryVal.myHead->left->myval))
             scaryVal.myHead->left = p;
         if (keyCompare(scaryVal.myHead->right->myval, val))
             scaryVal.myHead->right = p;
         scaryVal.mySize++;


      }
   }

   // Removes from the set container a single element whose value is val
   // This effectively reduces the container size by one, which are destroyed.
   // Returns the number of elements erased.
   size_type erase(const key_type& val)
   {
       TreeNode< key_type >* p = scaryVal.myHead->parent; // p points to the root
       while (p != scaryVal.myHead && val != p->myval)
       {
           //           keyCompare.operator()( val, p->myval )
           if (keyCompare(val, p->myval)) // if( val < p->myval )
               p = p->left;
           else
               p = p->right;
       }

       if (p == scaryVal.myHead) // not found
           return 0;
       else // found
       {  // deletes the node pointed by p

           TreeNode<key_type>* leftMax = p->right, * M = p;
           while (leftMax != scaryVal.myHead)
               M = leftMax, leftMax = leftMax->left;
           // update max and min
           if (M == scaryVal.myHead->left)
               scaryVal.myHead->left = (M->right != scaryVal.myHead) ? M->right : M->parent;
           if (M == scaryVal.myHead->right)
               scaryVal.myHead->right = (M->left != scaryVal.myHead) ? M->left : M->parent;
           p->myval = M->myval;
           scaryVal.eraseDegreeOne(M);

           return 1;
       }
   }

private:
   key_compare keyCompare;
   ScaryVal scaryVal;
};

#endif // XTREE