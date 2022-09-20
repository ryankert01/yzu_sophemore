// algorithm standard header

#ifndef ALGORITHM
#define ALGORITHM

namespace MyNamespace
{
   template <typename RanIt, typename Ty, typename Pr>
   inline void pushHeapByIndex(RanIt first, ptrdiff_t hole, ptrdiff_t top, Ty &val, Pr pred)
   {
      if (hole == top)
         return;
      RanIt it = first + (hole - 1) / 2;
      if (pred(val, *it))
      {
         *(first + hole) = *it;
         *it = val;
         pushHeapByIndex(first, (hole - 1) / 2, top, val, pred);
      }
   }

   // push *(last - 1) onto heap at [first, last - 1), using pred
   template <typename RanIt, typename Pr>
   inline void push_heap(RanIt first, RanIt last, Pr pred)
   {
      ptrdiff_t count = last - first;
      if (count >= 2)
      {
         --last;
         typename RanIt::value_type val = *last;
         --count;
         pushHeapByIndex(first, count, 0, val, pred);
      }
   }

   template <typename RanIt, typename Ty, typename Pr>
   inline void popHeapHoleByIndex(RanIt first, ptrdiff_t hole, ptrdiff_t bottom, Ty &val, Pr pred, bool k = true)
   {
       ptrdiff_t idx = hole * 2 + 1;
       ptrdiff_t decidedNode;

       if (idx + 1 < bottom) {
           decidedNode = pred(*(first + idx), *(first + idx + 1)) ? idx + 1 : idx;
       }
       else if (idx < bottom) {
           decidedNode = idx;
       }
       else {
           return;
       }
       if (pred(*(first + hole), *(first + decidedNode))) {
           Ty temp = val;
           *(first + hole) = *(first + decidedNode);
           *(first + decidedNode) = temp;
           popHeapHoleByIndex(first, decidedNode, bottom, *(first + decidedNode), pred);
       }

       
       /*
       if (idx + 1 < bottom && pred(*(first + hole), *(first + idx + 1))) {
           Ty temp = *(first + hole);
           *(first + hole) = *(first + idx + 1);
           *(first + idx + 1) = temp;
           popHeapHoleByIndex(first, idx + 1, bottom, *(first + idx + 1), pred,0);
           for (ptrdiff_t i = 0; i < bottom; i++)
               cout << *(first + i) << " ";
           cout << endl;
       }
       if (idx < bottom && pred(*(first + hole), *(first + idx))) {
           Ty temp = *(first + hole);
           *(first + hole) = *(first + idx);
           *(first + idx) = temp;
           popHeapHoleByIndex(first, idx, bottom, *(first + idx), pred, 0);
           for (ptrdiff_t i = 0; i < bottom; i++)
               cout << *(first + i) << " ";
           cout << endl;
       }
       // debug
       if (k) { 
           for (ptrdiff_t i = 0; i < bottom; i++) 
               cout << *(first + i) << " "; 
           cout << endl; 
       }*/
   }

   // pop *first to *(last - 1) and reheap, using pred
   template <typename RanIt, typename Pr>
   inline void pop_heap(RanIt first, RanIt last, Pr pred)
   {
      if (last - first >= 2)
      {
         --last;
         typename RanIt::value_type val = *last;
         popHeapHoleByIndex(first, 0, last - first, val, pred);
      }
   }

   // make [first, last) into a heap, using pred
   template <typename RanIt, typename Pr>
   inline void make_heap(RanIt first, RanIt last, Pr pred)
   {
      ptrdiff_t bottom = last - first;
      ptrdiff_t hole = bottom / 2;
      while (hole > 0)
      {
         // reheap top half, bottom to top
         --hole;
         typename RanIt::value_type val = *(first + hole);
         popHeapHoleByIndex(first, hole, bottom, val, pred);
      }
   }
}

#endif // ALGORITHM