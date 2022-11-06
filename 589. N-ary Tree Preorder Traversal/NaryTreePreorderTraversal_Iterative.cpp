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
#include <stack>
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> traversal;
        
        if (root != nullptr)
        {
        	stack<Node*> nodesStack;
            nodesStack.push(root);
            Node* father;
            do {
                father = nodesStack.top();
                traversal.push_back(father->val);
                nodesStack.pop();
                
                for (int i = father->children.size()-1; i>=0; --i)
                {
                    nodesStack.push(father->children[i]);
                }
            } while (!nodesStack.empty()); 
        }
        
        return traversal;
    }
};
