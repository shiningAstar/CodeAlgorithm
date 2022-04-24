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


#endif // BST_H_INCLUDED
