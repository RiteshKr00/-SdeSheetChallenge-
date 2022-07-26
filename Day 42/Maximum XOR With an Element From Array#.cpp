void mergeSort(vector<int>&arr,int low,int mid,int high){
    int n1=mid-low+1,n2=high-mid;
    vector<int>a(n1,0);
    vector<int>b(n2,0);
    for(int i=0;i<n1;i++)a[i]=arr[low+i];
    for(int i=0;i<n2;i++)b[i]=arr[mid+1+i];
    int i=0,j=0,k=low;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            i++;k++;
        }
        else{
            arr[k]=b[j];
            j++;k++;
        }
    }
    while(i<n1){
        arr[k]=a[i];
        i++;k++;
    }
    while(j<n2){
        arr[k]=b[j];
        j++;k++;
    }
}
void merge(vector<int>&arr,int start,int end){
    if(start<end){
        int mid=start+(end-start)/2;
        merge(arr,start,mid);
        merge(arr,mid+1,end);
        mergeSort(arr,start,mid,end);
    }
}
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
    vector<int>ans;
    //sort(arr.begin(),arr.end());
    merge(arr,0,arr.size()-1);
    for(auto q:queries){
        int maxi=-1e9;
        if(arr[0]>q[1])ans.push_back(-1);
        else{
            for(int i=0;i<arr.size();i++){
                if(arr[i]<=q[1]){
                    maxi=max(maxi,arr[i]^q[0]);
                }
            }
            ans.push_back(maxi);
        }
    }
    return ans;
}

//can also be Solved using trie
#include<bits/stdc++.h>

class TrieNode{
    
    public:
        
        int data;
        TrieNode* children[2];
    
    
    TrieNode(int d){
        
        this->data = d;
        
      children[0] = NULL;
      children[1] = NULL;
      
    }
    
};

class Trie{
    
    public:
    
    TrieNode* root;
    
    Trie(){
        root = new TrieNode(5);
    }
    
    
    void insertUtil(TrieNode* root , int &num){
       TrieNode* curr = root;
        
        for(int i=31 ; i>=0 ; i--){   // insert
            
            int bit = (num >> i) & 1;   
            
            if( curr->children[bit] == NULL){
                    curr->children[bit] = new TrieNode(bit);
            }
            
            curr = curr->children[bit];
        }   
        
    }
    
    
    void insert(int &num){
        insertUtil(root ,  num);
    }
    
    
    
    int MaxXorAns(TrieNode* root , int x ){
            int ans = 0;
            
             TrieNode* curr = root;
        
            for(int i=31;i>=0;i--){
                
                int bit = (x >> i) & 1;
                int opp = !bit;
                
                if( curr->children[opp] ){         
                    ans = ans + (1<<i);   // 1<<i  = 2^i  
                    curr = curr->children[opp];
                }
            
                else{
                    curr = curr->children[bit];
                }
           
            }  //  for loop
            
            return ans;
            
    }
    
    
    int maxXor(int x ){
        return MaxXorAns(root , x ); 
    }
    
    
   
};   // class  Trie



vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	
    Trie* t = new Trie();
    
    int n = arr.size();
    int m = queries.size();
    
     // 1st Step : 
    
        sort(arr.begin() , arr.end());
    
    
    // 2nd step 
    
    vector< pair< int , pair<int,int> > > ofpair;    //  ai  ,  xi,querIdx  
    
    
    for(int i=0;i<m;i++){
        ofpair.push_back( { queries[i][1]  , { queries[i][0],i } }  );
        
    }
    
    sort(ofpair.begin() , ofpair.end() );
    
    
    // 3rd  Step : 

        vector<int> vecAns(m);  
        int k=0;
    
    for(int i=0;i<m;i++){
        
        int ai = ofpair[i].first;
        int xi = ofpair[i].second.first;
        int Storeindex = ofpair[i].second.second;

//         cout<<ai <<"  : "<<xi<<","<<Storeindex<<endl;
        
        while(k<n && arr[k] <= ai){
               t->insert(arr[k]);
                k++;
        }
        
        
        if(k==0){
            vecAns[Storeindex] = -1;
        }
        
        else{
              vecAns[Storeindex] = t->maxXor(xi);
        }
        
        
   }
    
    
    return vecAns;
    
}
Alternate
#include<bits/stdc++.h>
struct Node{
    Node *links[2];
    
    bool containsKey(int bit){
        return (links[bit] != NULL);
    }
    
    Node *get(int bit){
        return links[bit];
    }
    
    void put(int bit, Node *node){
        links[bit] = node;
    }
};
class Trie{
    private:
        Node *root;
     public:
        Trie(){
            root = new Node();
        }
        void insert(int num){
            Node *node = root;
            for(int i = 31; i >= 0; i--){
                int bit = (num >> i) & 1;
                if(!node->containsKey(bit)){
                    node->put(bit, new Node());
                }
                node = node->get(bit);
            }
        }
        int getMax(int num){
            Node * node = root;
            int maxVal = 0;
            for(int i = 31; i >= 0; i--){
                int bit = (num >> i) & 1;
                if(node->containsKey(!bit)){
                    maxVal = maxVal | (1 << i);
                    node = node->get(!bit);
                }
                else
                    node = node->get(bit);
            }
            return maxVal;
        }
};
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	Trie trie;
    vector<int> ans(queries.size(), 0);
    vector<pair<int, pair<int, int>>> offlineQueries;
    sort(arr.begin(), arr.end());
    int idx = 0;
    for(auto it: queries){
        offlineQueries.push_back({it[1], {it[0], idx++}});
    }
    sort(offlineQueries.begin(), offlineQueries.end());
    int i = 0;
    for(auto &it: offlineQueries){
        int ai = it.first;
        int xi = it.second.first;
        int index = it.second.second;
        while(i < arr.size() && arr[i] <= ai){
            trie.insert(arr[i]);
            i++;
        }
        if(i != 0)
            ans[index] = trie.getMax(xi);
        else
            ans[index] = -1;
    }
    return ans;
}