/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> traversal;
        
        if (root != nullptr)
        {
            traversal.push_back(root->val);

            vector<Node*> children = root->children;
            for (int i = 0; i<children.size(); ++i)
            {
                vector<int> traversalTmp = preorder(children[i]);
                traversal.insert(traversal.end(),
                traversalTmp.begin(),
                traversalTmp.end());
            }
        }
        
        return traversal;
    }
};
