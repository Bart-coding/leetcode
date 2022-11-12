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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> treeTraversal;
        
        if (root != nullptr)
        {
            queue<TreeNode*> nodesQueue;
            nodesQueue.push(root);
            vector<int> firstLevel{root->val};
            treeTraversal.push_back(firstLevel);
            TreeNode* father;
            
            do {
                vector<int> nextLevel;
                int prevoiusLevelNodes = nodesQueue.size();
                for (int i = 0; i<prevoiusLevelNodes; ++i)
                {
                    father = nodesQueue.front();
                    nodesQueue.pop();
                    if (father->left != nullptr)
                    {
                        nodesQueue.push(father->left);
                        nextLevel.push_back(father->left->val);
                    }
                    if (father->right != nullptr)
                    {
                        nodesQueue.push(father->right);
                        nextLevel.push_back(father->right->val);
                    }
                }
                if (!nextLevel.empty())
                    treeTraversal.push_back(nextLevel);
                           
            } while(!nodesQueue.empty());
        }
        
        return treeTraversal;
    }
};
