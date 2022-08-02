

/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};


Similar to deep copy with Random pointers

use map to store the corresponding new Node
******************************************************************************/

graphNode* dfs(graphNode *node,map<graphNode *,graphNode *>&mp){
    mp[node]=new graphNode(node->data);
    for(auto it:node->neighbours){
        //if clone on node exist then simply push its clone in array
//         othwerwise call dfs because each dfs crate a clone and 
//         store it in map
//         It also acts as visited array because once all are maaped we dont call dfs
        if(mp.find(it)==mp.end()){
            mp[node]->neighbours.push_back(dfs(it,mp));
        }
        else{
            mp[node]->neighbours.push_back(mp[it]);
        }     
    }
    //return equivalent cloned node 
    return mp[node];
}

graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.
    map<graphNode*,graphNode*>mp;    
    
    return dfs(node,mp);
}