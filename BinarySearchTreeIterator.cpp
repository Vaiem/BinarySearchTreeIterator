/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    TreeNode* currentNode = nullptr;
public:
    BSTIterator(TreeNode* root) {
       recTree(root);
    }
    
    int next() {
        if(currentNode != nullptr)
        {   
            int item = currentNode->val;
            currentNode = currentNode->right;
            return item;
        }
        return INT_MIN;
    }
    
    bool hasNext() {
        if(currentNode != nullptr)
        {
            return true;
        }
        return false;
    }

    void recTree(TreeNode* root)
    {
        if(root == nullptr)
        {
          return;
        }

        recTree(root->right);
        root->right = currentNode;
        currentNode = root;

        recTree(root->left);

    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */