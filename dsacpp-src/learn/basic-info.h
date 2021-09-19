/*
 * vector's metadata: size, capacity, data
 * vector's functions: Create, Read, Update, Delete
 *   Create: allocate.
 *   Read: Get from Rank, Find some value, terverse
 *   Update: insert, expand, shrink, sort, unsort
 *   Delete: delete by rank;
 */
template <typename T>
class Vector {
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
template <typename T> void Vector<T>::bubbleSort() {
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

struct ListNode ();
struct ListNodePosi() = ListNode();
struct ListNode () {
 public:
  next ListNode;
  prev ListNode;
  int data;

  insertAsNext();
  insertAsPrev();
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
class Stack() {
  pop();
  push();

  trim();
}

/*
 * can implement by vector as well.
 */
class Queue(){
  enqueue();
  dequeue();
}

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
struct BinNode {}

class BinTree() {}

struct GraphNode {}

class Graph() {}
