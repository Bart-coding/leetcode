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
    void insertNextNode (Node* nextNode, vector<int>& traversal) {
        if (nextNode != nullptr)
        {
            traversal.push_back(nextNode->val);

            vector<Node*> children = nextNode->children;
            for (int i = 0; i<children.size(); ++i)
            {
                insertNextNode(children[i], traversal);
            }
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> traversal;
        insertNextNode(root, traversal);
        
        return traversal;
    }
};
