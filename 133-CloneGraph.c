/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        unordered_map<Node*, Node*> copyMap;
        queue<Node*> nodeQ;
        nodeQ.push(node);
        copyMap[node]=new Node(node->val);
        while(!nodeQ.empty()){
            auto qout=nodeQ.front();
            nodeQ.pop();
            for(auto it: qout->neighbors){
                if(!copyMap[it]){
                    copyMap[it]=new Node(it->val);
                    nodeQ.push(it);
                }
                copyMap[qout]->neighbors.push_back(copyMap[it]);
            }
        }
        return copyMap[node];
    }
};
