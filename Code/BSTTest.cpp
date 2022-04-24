#include <vector>
#include <stack>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <math.h>

using namespace std;

#include "TestHelper.h"
#include "../bst.h"

//            5
//        3       7
//     2    4   6  8
//   1               9
int main()
{
    struct TreeNode tree[9];
    for(int i = 0; i < 9; i++)
        tree[i].val = i + 1;
    tree[4].left = &tree[2];
    tree[4].right = &tree[6];
    tree[2].left = &tree[1];
    tree[2].right = &tree[3];
    tree[1].left = &tree[0];
    tree[1].right = NULL;
    tree[0].left = NULL;
    tree[0].right = NULL;
    tree[3].left = NULL;
    tree[3].right = NULL;
    tree[6].left = &tree[5];
    tree[6].right = &tree[7];
    tree[5].left = NULL;
    tree[5].right = NULL;
    tree[7].left = NULL;
    tree[7].right = &tree[8];
    tree[8].left = NULL;
    tree[8].right = NULL;

    dfsBST21(&tree[4]);

    return 0;
}
