/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2021. All rights reserved.
 ******************************************************************************************/

#pragma once

/*
in order recurse: a b c d e f
- before zig:
     d
  -------
  b     e
-----
a   c
- after zig:
     b
  -------
  a     d
      -----
      c   e

*/

template <typename T> BinNodePosi<T> BinNode<T>::zig() { //˳ʱ����ת
   BinNodePosi<T> lChild = lc;
   // change current node's parent , point it to current node's left child
   lChild->parent = this->parent;
   if ( lChild->parent )
     ( ( this == lChild->parent->rc ) // ���ڵ��Ƿ�Ϊ�Һ���?
       ? lChild->parent->rc : lChild->parent->lc ) = lChild; // ����֮ǰ�����Һ��ӵ�״̬.

   // change left child's right child to current node's left child.
   lc = lChild->rc; if ( lc ) lc->parent = this;

   // change lChild's right child to current node.
   lChild->rc = this; this->parent = lChild;

   // update heights ()
   // get left child or right child, update height base on it.
   height = 1 + max ( stature ( lc ), stature ( rc ) );

   // 
   lChild->height = 1 + max ( stature ( lChild->lc ), stature ( lChild->rc ) );
   for ( BinNodePosi<T> x = lChild->parent; x; x = x->parent )
      if ( HeightUpdated( *x ) )
         break;
      else
         x->height = 1 + max ( stature ( x->lc ), stature ( x->rc ) );
   return lChild;
}
