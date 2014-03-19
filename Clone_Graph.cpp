// Clone an undirected graph. Each node in the graph contains a label and 
// a list of its neighbors.


/**
 * Definition for undirected graph.
 *  struct UndirectedGraphNode {
 *      int label;
 *      vector<UndirectedGraphNode *> neighbors;
 *      UndirectedGraphNode(int x) : label(x) {};
 *  };
 */

class Solution {
public:
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode *graph) {
        if (graph == NULL) 
            return NULL;

        // link graph node and its copy, and mark visited/copied graph nodes
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
        UndirectedGraphNode *graphCopy = new UndirectedGraphNode(graph->label);
        map[graph] = graphCopy;  

        queue<UndirectedGraphNode*> q;
        q.push(graph);

        while (!q.empty()) {
            UndirectedGraphNode *cur = q.front();
            q.pop();

            for (int i = 0; i < cur->neighbors.size(); i++) {
                UndirectedGraphNode *neighbor = cur->neighbors[i];

                // not visited yet, create node, then form the link
                if (map.find(neighbor) == map.end()) {  
                    UndirectedGraphNode *temp = new UndirectedGraphNode(neighbor->label);
                    map[cur]->neighbors.push_back(temp);
                    map[neighbor] = temp;
                    q.push(neighbor);
                } else {  // already visited, create link directly
                    map[cur]->neighbors.push_back(map[neighbor]);
                }
            }
        }
        return graphCopy;
    }
};
