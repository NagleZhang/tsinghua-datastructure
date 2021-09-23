// kinda pseudocode

#include "basic-info.h"

typedef BinTree<char> PFCTree;

typedef Vector<PFCTree> PFCForest;

/*
  |    |    |     |    |    |     |    |    |
 ---  ---  ---   ---  ---  ---   ---  ---  ---  ...
 | |  | |  | |   | |  | |  | |   | |  | |  | |

 */
PFCForest* initForest() {
  PFCForest forest = new PFCForest;

  for (int i = 0; i < N_CHAR ; i++) { // N_CHAR is from 0x20 - 0x80
    forest -> insert(i, new PFCTree());
    (*forest) [i] -> insertAsRoot( 0x20 + i );
  }

  return forest;
}

/*
                      ^
  ----- ---- ----  ---  ---  ----  ---- ---     ...
  |    |    |     |    |    |     |    |    |
 ---  ---  ---   ---  ---  ---   ---  ---  ---  ...
 | |  | |  | |   | |  | |  | |   | |  | |  | |
 */

PFCTree* generageTree() {
  srand((unsigned int) time(NULL));

  while(1 < forest -> size()) {
    PFCTree * s = new PFCTree;
    s -> insertAsRoot('^');
    int r1 = rand() % forest -> size();
    s -> attachAsLC (s->root() , (*forest)[r1]);
    forest -> remove( r1 );
    int r2 = rand() % forest -> size() ;
    s -> attachAsRC (s -> root() , (*forest) [r2]);
    forest -> remove( r2 );
    forest -> insert(forest -> size(), s);
  }

  return (*forest)[0]
}

int main(int argc, char* argv[]) {

  PFCForest * forest = initForest();
}
