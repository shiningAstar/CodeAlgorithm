#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

/* 二分搜索树 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/*******************************/

//递推实现插入二叉树
bool insertBST1(TreeNode *root, TreeNode *node)
{
    if(root == NULL || node == NULL)
        return false;

    TreeNode *p = root;

    while(p)
    {
        if(node->val < p->val)
        {
            if(p->left)
                p = p->left;
            else
            {
                p->left = node;
                break;
            }
        }
        else if(node->val > p->val)
         {
             if(p->right)
                p = p->right;
             else
             {
                 p->right = node;
                 break;
             }
         }
        else
            return false;
    }
    return true;
}

/*******************************/
//递归实现插入二叉树
bool insertBST2(TreeNode *root, TreeNode *node)
{
    if(root == NULL)
        return true;
    if(node->val < root->val)
    {
        if(insertBST2(root->left, node))
        {
            root->left = node;
            return true;
        }
        else
            return false;
    }
    else if(node->val > root->val)
    {
        if(insertBST2(root->right, node))
        {
            root->right = node;
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

/*******************************/


/*******************************/

//递推实现查找二叉树
bool searchBST1(TreeNode *root, int val)
{
    if(root == NULL)
        return false;

    TreeNode *p = root;

    while(p)
    {
        if(val < p->val)
            p = p->left;
        else if(val > p->val)
            p = p->right;
        else
            break;
    }
    if(p)
        return true;
    else
        return false;
}

/*******************************/
//递归实现查找二叉树
bool searchBST2(TreeNode *root, int val)
{
    if(root == NULL)
        return false;
    if(val < root->val)
        return searchBST2(root->left, val);
    else if(val > root->val)
        return searchBST2(root->right, val);
    else
        return true;
}

/*******************************/


/*******************************/
//递推实现深度优先遍历，先序
void dfsBST11(TreeNode *root)
{
    stack<TreeNode *> nodes;
    TreeNode *node;

    nodes.push(root);

    while(!nodes.empty())
    {
        node = nodes.top();
        //遍历node
        cout<<node->val;
        nodes.pop();
        if(node->left)
            nodes.push(node->left);
        if(node->right)
            nodes.push(node->right);
    }
}

/*******************************/



/*******************************/
//递归实现深度优先遍历，先序
void dfsBST12(TreeNode *root)
{
    //遍历node
    cout<<root->val;
    if(root->left)
        dfsBST12(root->left);
    if(root->right)
        dfsBST12(root->right);
}

/*******************************/


/*******************************/
//递推实现深度优先遍历，中序
void dfsBST21(TreeNode *root)
{
    stack<TreeNode *> nodes;
    TreeNode *node;

    node = root;

    while(!nodes.empty() || node)
    {
        if(node == NULL)
        {
            node = nodes.top();
            //遍历node
            cout<<node->val;
            nodes.pop();
            node = node->right;
        }
        else
        {
            nodes.push(node);
            node = node->left;
        }
    }
}

/*******************************/



/*******************************/
//递归实现深度优先遍历，中序
void dfsBST22(TreeNode *root)
{
    if(root->left)
        dfsBST22(root->left);
    //遍历node
    cout<<root->val;
    if(root->right)
        dfsBST22(root->right);
}

/*******************************/



/*******************************/
//递推实现深度优先遍历，后序
void dfsBST31(TreeNode *root)
{
    stack<TreeNode *> nodes;
    TreeNode *node, *last;

    node = root;

    while(!nodes.empty() || node)
    {
        if(node == NULL)
        {
            node = nodes.top();
            if(node->right && node->right != last)
            {
                //左子树遍历完，遍历右子树
                node = node->right;
            }
            else
            {
                //右子树遍历完，遍历node
                cout<<node->val;
                nodes.pop();
                last = node;
                node = NULL;
            }
        }
        else
        {
            //遍历node为根的树，node入栈，遍历左子树
            nodes.push(node);
            node = node->left;
        }
    }
}

/*******************************/



/*******************************/
//递归实现深度优先遍历，后序
void dfsBST32(TreeNode *root)
{
    if(root->left)
        dfsBST32(root->left);
    if(root->right)
        dfsBST32(root->right);
    //遍历node
    cout<<root->val;
}

/*******************************/


/*******************************/
//递推实现广度优先遍历
void bfsBST(TreeNode *root)
{
    if(root == NULL)
        return;
    queue<TreeNode *> que;

    que.push(root);

    while(!que.empty())
    {
        TreeNode *node = que.top();
        que.pop();
        //遍历node
        //cout<<node->val;
        if(node->left)
            que.push(node->left);
        if(node->right)
            que.push(node->right);
    }

}

/*******************************/


/*******************************/
//递归实现查找最小值节点
TreeNode *minBST(TreeNode *root)
{
    if(root == NULL)
        return NULL;

    if(root->left == NULL)
        return root;

    return minBST(root->left);

}

/*******************************/

/*******************************/
//递归实现删除最小值节点，返回删除后子树的根
TreeNode *deleteMinBST(TreeNode *root, TreeNode &*min)
{
    if(root == NULL)
        return NULL;

    if(root->left)
    {
        root->left = deleteMinBST(root->left, min);
        return root;
    }
    else  //root->left == NULL
    {
        TreeNode *rightnode = root->right;
        //删除
        //delete root;
        //返回节点可用作替换，仅在结构中去除
        min = root;
        return rightnode;
    }
}

/*******************************/

/*******************************/
//递归实现查找最大值节点
TreeNode *maxBST(TreeNode *root)
{
    if(root == NULL)
        return NULL;

    if(root->right == NULL)
        return root;

    return maxBST(root->right);

}

/*******************************/

/*******************************/
//递归实现删除最大值节点，返回删除后子树的根
TreeNode *deleteMaxBST(TreeNode *root, TreeNode &*max)
{
    if(root == NULL)
        return NULL;

    if(root->right)
    {
        root->right = deleteMinBST(root->right, max);
        return root;
    }
    else  //root->right == NULL
    {
        TreeNode *leftnode = root->left;
        //删除
        //delete root;
        //返回节点可用作替换，仅在结构中去除
        max = root;
        return leftnode;
    }
}

/*******************************/

/*******************************/
//递归实现删除节点，返回删除后子树的根
TreeNode *deleteBST(TreeNode *root, int key)
{
    if(root == NULL)
        return NULL;

    if(key < root->val)
    {
        root->left = deleteBST(root->left);
        return root;
    }
    else  (key > root->val)
    {
        root->right = deleteBST(root->right);
        return root;
    }
    else   //key == root->val
    {
        if(root->left == NULL)  //包括  && root->right == NULL
        {
            int rightnode = root->right;
            //删除，不删结构中去除不影响结构正确
            //delete root;
            return rightnode;
        }
        else if(root->right == NULL)
        {
            TreeNode *leftnode = root->left;
            //删除，不删结构中去除不影响结构正确
            //delete root;
            return leftnode;
        }
        else  //root->left != NULL && root->right != NULL
        {
            TreeNode *min;
            root->right = deleteMinBST(root->right, min);  //最小值节点用在替换删除节点
            min->left = root->left;
            min->right = root->right;
            //删除，不删结构中去除不影响结构正确
            //delete root;
            return min;
        }
    }
}

/*******************************/

/*******************************/
//递推实现查找node前驱节点
TreeNode *predecessorBST(TreeNode *root, TreeNode *node)
{
    if(root == NULL)
        return NULL;

    if(node->left)
        return maxBST(node->left);

    //node没有左子树，前驱节点是以node为最小值最大子树根节点的父节点
    TreeNode *pred = NULL, *p = root;
    while(p)
    {
        if(node->val > p->val)
        {
            pred = p;
            p = p->right;
        }
        else if(node->val < p->val)
        {
            TreeNode *minr = p;
            while(p)
            {
                if(p->left == node)
                    return pred;   //node不是根节点最小值返回找到pred，node为根最小值返回NULL
                p = p->left;
            }
            p = minr;
            pred = p;
            p = p->left;
        }
        else
            return pred;
    }
    //树中不存在node
    return NULL;


}

/*******************************/

/*******************************/
//递推实现查找node后继节点
TreeNode *successorBST(TreeNode *root, TreeNode *node)
{
    if(root == NULL)
        return NULL;

    if(node->right)
        return maxBST(node->left);

    //node没有右子树，后继节点是以node为最大值最大子树根节点的父节点
    TreeNode *succ = NULL, *p = root;
    while(p)
    {
        if(node->val < p->val)
        {
            succ = p;
            p = p->left;
        }
        else if(node->val > p->val)
        {
            TreeNode *maxr = p;
            while(p)
            {
                if(p->right == node)
                    return succ;   //node不是根节点最大值返回找到succ，node为根最大值返回NULL
                p = p->right;
            }
            p = maxr;
            succ = p;
            p = p->right;
        }
        else
        {
            return succ;
        }
    }
    //树中不存在node
    return NULL;

}



#endif // BST_H_INCLUDED
