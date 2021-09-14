/*
 * vector's metadata: size, capacity, data
 * vector's functions: Create, Read, Update, Delete
 *   Create: allocate.
 *   Read: Get from Rank, Find some value, terverse
 *   Update: insert, expand, shrink, sort, unsort
 *   Delete: delete by rank;
 */
class Vector() {
 public:
  int _capacity;
  int _size;
  int data;
};

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
