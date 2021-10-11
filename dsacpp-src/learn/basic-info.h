// kinda pseudocode

/*
 * vector's metadata: size, capacity, data
 * vector's functions: Create, Read, Update, Delete
 *   Create: allocate.
 *   Read: Get from Rank, Find some value, terverse
 *   Update: insert, expand, shrink, sort, unsort
 *   Delete: delete by rank;
 */
template <typename T> class Vector {
 protected:
  int _capacity;
  int _size;
  T* data;
 public:
  Vector(int size, int capacity , T v = 0) {
    data = new T[capacity];
    for (int i = 0 ; i <= size; data[i++] = v);
  }

  void bubble() {};
  void fancyBubbleSort() {};
  void normalBubbleSort() {};

  void merge() {};
};
/*
 * normal code, and just for whole vector. it's bad.
 */
template <typename T> void Vector<T>::normalBubbleSort() {
  for(int j = 0 ; j <= _size; j++) {
    for(int i = 0; i <= _size; i++) {
      if (data[i] > data[i+1]){
        int tmp = data[i];
        data[i] = data[i+1];
        data[i+1] = tmp;
      }
    }
  }
}
/*
 * fancy code from , treat bubble as a single action, and if do not need bubble again, means all sorted.
 */
template <typename T> boolean Vector<T>::bubble() {
  boolean sorted = true;
  for (int i = 0 ; i <= _size; i++) {
    // if need sort , then means it's not sorted yet.
    sorted = false;
    swap(data[i] , data[i++]);
  }
}

template <typename T> void Vector<T>::fancyBubbleSort() {
  while (!bubble());
}

/*
 * have three part,
 *  A first : | lo --------- mi ---------- hi |
 *  B second: | lo --------- mi)
 *  C third : (mi ---------- hi |
 * what we need to do is take data[mi - lo], and data[hi - mi], merge them.
 * since B & C is sorted, our purpose is to merge B & C , then copy it to A. so we need to figure out several things:
 * 1. traverse B, if B is not traversed yet, and bigger then C(or C is all traversed), then put it into A.
 * 2. traverse C, if C is not traversed ye, and is bigger then B(or B is all traversed), then put it into A.
 */
template <typename T> void Vector<T>::merge(int lo, int hi, int mi) {
  // let A's location to be lo.
  T* A = data + lo;

  // copy mi - lo data to B.
  int left_side = mi - lo;
  T* B = new T[left_side];
  for (int i = 0; i < left_side; B[i] = A[i++]);

  int right_side = hi - mi;
  T* C = A[data + mi];

  // i for traverse A, j for B, k for C;
  for(int i,j,k = 0; j < left_side || k < right_side;) {
    // DO 1. merge B to A
    if (j < left_side && (!(k < right_side) || B[j] <= C[k] )){
      A[i++] = B[j++];
    }
    // DO 2. merge C to A
    if (k < right_side && (!(j<left_side) || C[k] <= B[j])){
      A[i++] = C[k++];
    }
  }

  delete [] B;
}

/*
 * List's metadata:
 *  List(data, headListNode, tailNode, size)
 *  ListNode(prev, next).
 * List's function: Create, Read, Update, Delete
 *   Create: allocate.
 *   Read: Get from Rank, Find some value, terverse
 *   Update: insert, sort, unsort
 *   Delete: delete by rank;
 */

template <typename T> struct ListNode;
template <typename T> using ListNodePosi() = ListNode();

template <typename T> struct ListNode {
  ListNode() {}
ListNode(T data, ListNodePosi<T> prev = null, ListNodePosi<T> next = null)
  : data(data), prev(prev), next(next) {}
  ListNodePosi<T> next;
  ListNodePosi<T> prev;
  T data;

  ListNodePosi<T> insertAsNext();
  ListNodePosi<T> insertAsPrev();
};

template <typename T> ListNodePosi<T> ListNode<T>::insertAsPrev(T const& data) {
  ListNodePosi<T> newNode = new ListNode(data, prev, this);
  prev.next = nowNode;
  prev = newNode;
  return newNode;
}

template <typename T> ListNodePosi<T> ListNode<T>::insertAsNext(T const& data) {
  ListNodePosi<T> newNode = new ListNode(data, this, next);
  next = newNode;
  next.prev = newNode;
  return newNode;
}

class List () {
 public:
  ListNode head, tail;
  int _size;
  insertAfterNode();
  insertBeforeNode();
}

/*
 * can implement by vector.
 */

template <typename T> class Stack: public Vector<T>{
  void push(T &const data){ insert(size(), data)};
  T pop() {
    return remove( size() - 1);
  };
  T& top() {
    return (*this)[size() - 1];
  };
};

/*
 * can implement by vector as well.
 */
template <typename T> class Queue: public Vector<T> {
  void enqueue( T const & data){
    insert(size(), data);
  };
  T* dequeue(){
    remove(first());
  };
};

/*
 * BinTree's metadata:
 *  BinNode/BinNodePosition : leftChild, rightChild, data, Parent, height
 *  BinTree: root, _size
 * BinTree's function: Create, Read, Update, Delete
 *  Create: allocate
 *  Read: 
 *  Update: 
 *  Delete: 
 */
template <typename T> struct BinNode{};

#define BinNodePosi(T) BinNode<T>*;

/*
 * as a node , this data should be able to:
 *  1. terverse
 *  2. find parent, left child , right child
 *  3. get current height.
 *  4. insert & remove node.
 */

template <typename T> struct BinNode {
  T data;
  BinNode(T) parent;
  BinNode(T) leftChild;
  BinNode(T) rightChild;
  int hight;

  BinNode(): parent(null), leftChild(null), rightChild(null),hight(0) { }
  BinNode(T e, BinNodePosi(T) parent, BinNodePosi(T) leftChild, BinNodePosi(T) rightChild , int height ) {
    data = e;
    parent = parent;
    leftChild = leftChild;
    rightChild = rightChild;
    hight = hight;
  }

  void zig();
  void zag();
};

/*
 * as a tree manager, this structure should be able to:
 *  1. get root node.
 *  2. CRUD tree, tree need to know where to insert & where to delete the node.
 */
class BinTree() {
 protected:
  int _size;
  BinNodePosi(T) root;

  updateHeight(BinNodePosi(T) x);
  // because Binary Node's child are not fixed. so it's hard to maintain it's height.
  // alternatively , just update all the height above. because binary tree's above is fixed.
  updateHeightAbove() {}
 public:
  BinTree(): _size(0), root(NULL) {}
  ~BinTree() {
    if (0 < _size) { remove(root);}
  }
  int size() {return _size;}

  template <typename T, typename VT> void trav_recur_preorder(BinNodePosi(T) node, VT& visit) {
    if (!x) return;
    visit(x -> data);
    trav_preorder(node -> lc, visit);
    trav_preorder(node -> rc, visit);
  }

  template <typename T, typename VT> void trav_recur_inorder(BinNodePosi(T) node, VT& visit) {
    if (!x) return;
    trav_preorder(node -> lc, visit);
    visit(x -> data);
    trav_preorder(node -> rc, visit);
  }

  template <typename T, typename VT> void trav_recur_postorder(BinNodePosi(T) node, VT& visit) {
    if (!x) return;
    trav_preorder(node -> lc, visit);
    trav_preorder(node -> rc, visit);
    visit(x -> data);
  }

  template <typename T, typename VT> static void visitAloneLeftBranch(BinNodePosi(T) leftNode, VT& visit, Stack<BinNodePosi(T)> & stack) {
    while(leftNode -> lc) {
      visit(x -> data);
      stack.push(x->rc);
      leftNode = leftNode -> lc;
    }
  }

  // because recursive version take to much space, so ,it's better change it to iteration version.
  template <typename T, typename VT> void trev_iter_preorder(BinNodePosi(T) node, VT& visit) {
    Stack<BinNodePosi(T)> stack;
    while( true ) {
      visitAloneLeftBranch(node, VT, stack);
      if (stack.empty()) {
        break;
      }
      node = stack.pop();
    }
  }

  template <typename T> void goAloneLeftBranch(BinNodePosi(T) inNode, Stack<BinNodePosi(T)> & stack) {
    while(x) {
      stack.push(x);
      x = x -> leftNode;
    }
  }

  template <typename T, typename VT> void trev_iter_inorder(BinNodePosi(T) node, VT& visit) {
    Stack<BinNodePosi(T)> stack;
    while (true) {
      goAloneLeftBranch(node, stack);
      if (stack.empty()){
        break;
      }
      node = stack.pop();
      visit(node -> data);
      node = node -> rightNode;
    }
  }

  template <typename T, typename VT> static void gotoHVFL(Stack<BinNodePosi(T)> & stack) {
    while(BinNodePosi(T) x = stack.top()) {
      if ( HasLChild( *x ) ) {
        if ( HasRChild( *x ) stack.push( x -> rightNode ));
        stack.push( x -> leftChild );
      } else {
        stack.push( x -> rightNode );
      }
    }
    stack.pop();
  }

  template <typename T, typename VT> void trev_iter_postorder(BinNodePosi(T) node, VT& visit) {
    Stack<BinNodePosi(T)> stack;
    if (x) stack.push( x );
    while( !stack.empty() ) {
      if ( stack.top() != x-> parent ){
        gotoHVFL( stack );
      }
    }

    x = s.pop();
    visit( x-> data );
  }

  template <typename T, typename VT> void trev_iter_postorder(BinNodePosi(T) node, VT& visit) {
    Queue<BinNodePosi(T)> queue;
    queue.enqueue(node);
    while(!queue.empty()) {
      BinNodePosi(T) x = queue.dequeue();
      visit(x->data);
      if (HasLChild( *x )) queue.enqueue(x->leftNode);
      if (HasRChild( *x )) queue.enqueue(x->rightNode);
    }
  }

};

typedef enum {undiscovered, discovered, visited} VStatus;
typedef enum {undetermined, tree, cross, forward, backword } EType;
template <typename Tv> struct Vertex {
  Tv data;
  int inDegree, outDegree;
  VStatus status;
  int dTime, fTIme;
  int parent;
  int priority;
};

template <typename Te> struct Edge {
  Te data;
  int weight;
  EType type;
};


<<<<<<< HEAD
// 邻接矩阵实现
/*
 * a graph operation contains several things:
 1. add a row into vector
 2. add a column into vector
 3. add a Veterx
 */
template <typename Tv, typename Te> class GraphMatrix() {
  Vector<Vertex<Tv>> V;
  Vector< Vector< Edge<Te> *> > E;
};


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

// zig & zag for AVL Tree;
template <typename T> void BinNode::zig() {
  // first, change current node's parent point to current node's left child.
  lChild = new BinNodePosi leftChild();
  lChild = this -> lc;
  if (x -> parent) {
    (( this == this -> parent -> rc ) ?
     lChild->parent->lc : lChild->parent->rc ) = lChild;
  }

  // second, change current node's left child , to left child node's right child.
  lc = lChild -> rc; if (lc) lc -> parent = this;

  // third, change new root's(lChild) left child to this.
  lChild -> rc = this; this -> parent = lChild;

  // update current node's height.

}

template <typename T> void BinNode::zag() {
  // first: change current node parent point to right child.

  // second: change right child's right child to to current left child.

  // third: change current node as new root's left child.
}


/* 堆
 * 完全二叉堆就是利用二叉树的逻辑来组织线性的数据。
 * 但是， 二叉堆仅仅需要维护最大即可，可用于优先级队列。这样，在队列中，如何排队，可以借助这种思维方式。
 * 二叉堆当中， 设计到如何构建，蛮力算法会达到 n*log n 的时间复杂度。
 * 所以，弗洛伊德算法，是从抽象的角度来考虑， 通过假设二叉堆已经存在，合并二叉堆的方式，再添加一次下滤的过程，来进行构建。
 * 复杂度可以达到 n。通俗的来讲，就是在向量中，找到中间位置， 然后不断的将前面的向量下滤，从而实现堆构建。
 * 就是二分思想的另外一种运用罢辽。
 */


/*
 * 散列表(密码学是其反向)
 * 简单的理解是, 将散列表一些内容进行 hash 计算. 然后根据 hash 值直接匹配到内容.
 * 上文当中, 缺失的一部分是, 为什么要做 hash, hash 的目的. hash 的意义是, 将原有的大空间, 映射到一个小的空间
 * 当中. 从而提高空间的利用率. 否则, 我们可以直接根据内容定位, 而不需要进行 hash 了.
 * 然而, 既然从大的空间映射到一个小的空间当中, 自然而然必然会产生冲突. 所以, hash 这个东西最大的问题, 就是需要解决冲突.
 * 取余法(表长取做素数,能保持最大公因子为1)/ MAD: (a*key+b) % M
 * 散列方法
 *    数字分析/平方取中(n * n, 再取中间的位数, 这样能够尽量保持 n 的最大利用率 )
 *    折叠法(自左向右|往复折叠, 取总和)
 *    位异或法.
 *    (伪)随机数法, 不可跨平台.
 *    多项式法(针对字符串 hash )
 * 冲突解决
 *   hashing table + 链表(closed addressing), 所有的散列值, 在执行 hash 的时候, 已经注定了要放在内存当中的某个位置.
 *   开放定址: 将申请的内存块的每一个桶, 面向所有的 hash 开放, 这样的话, 每一个 hash 值不一定就存放在绝对的位置. 这样有利于空间的申请效率.
 *       要实现开放定址, 也就意味着, 需要对目前内存空间当中执行查找, 并且找到合适的位置.这个查找的位置,也就是查找链.
 *       而这种策略, 也就带来了一个问题, hash 存放的过程当中, 很大概率会引发大规模的冲突.
 *       所以, 调整每一次试探的步长, 并且从正反,两面进行试探. 为了保证试探能够遍历整个内存的空间,
 *       整个空间的地址需要取为 4k + 3(表长的第二个建议)
 */
