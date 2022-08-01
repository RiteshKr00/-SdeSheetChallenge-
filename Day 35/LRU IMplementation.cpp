#include<bits/stdc++.h>
/*learn about list splice function
-->used to transfer  elements from one list to another.
1.Transfer all the elements of list x into another list at some position.
2.Transfer only the element pointed by i from list x into the list at some position.
3.Transfers the range [first, last) from list x into another list at some position.
Time Complexity: O(n)
Auxiliary Space: O(1) of splice function
# syntax list1--->list 2
list1_name.splice (iterator position, list2)
                or 
list1_name.splice (iterator position, list2, iterator i)
                or 
list1_name.splice (iterator position, list2, iterator first, iterator last)
*/
class LRUCache
{
public:
    int size;
    list<pair<int,int>>l;
    map<int,list<pair<int,int>>::iterator>mp;
    LRUCache(int capacity)
    {
        // Write your code here
        size=capacity;
    }

    int get(int key)
    {
        // Write your code here
        if(mp.find(key)==mp.end())
            return -1;
        //move recently accesed to start of list;
        l.splice(l.begin(),l,mp[key]);        
        
        return mp[key]->second;
    }

    void put(int key, int value)
    {
        // Write your code here
        
        if(mp.find(key)!=mp.end()){
            l.splice(l.begin(),l,mp[key]);   
            mp[key]->second=value;
            return;
        }
        if(size==l.size()){
            auto last=l.back().first;
            l.pop_back();
            mp.erase(last);            
        }
        l.push_front({key,value});
            mp[key]=l.begin();     
    }
};

///M2
// To insert and remove elements within a collection - that's natural to a LinkedList.

// However, deletion in a Singly LinkedList costs O(2*n) time , Doubly LinkedList costs O(n) time. In order to reduce time to O(1), we have to figure out a node bounded to a key in O(1) - that can be achived by a mapping from key to node.

// We always put the most recent one at the head of the Doubly LinkedList, then the least recent ones should be at the end.

// For Doubly LinkedList, we add head and tail to avoid tedious null checks.


class LRUCache {
    private DNode head, tail;
    private Map<Integer, DNode> nodeMap; // map k to node
    private int capacity;
    
    public LRUCache(int capacity) {
        head = new DNode(-1, -1);
        tail = new DNode(-1, -1);
        
        head.next= tail;
        tail.prev = head;
        this.capacity = capacity;
        
        nodeMap = new HashMap<>();
    }
    
    public int get(int key) {
        if (nodeMap.containsKey(key)) {
            moveToFront(nodeMap.get(key));
            return nodeMap.get(key).v;
        } else
            return -1;
    }
    
    public void put(int key, int value) {
        if (nodeMap.containsKey(key)) {
            DNode nodeToPut = nodeMap.get(key);
            nodeToPut.v = value;
            
            moveToFront(nodeToPut);
        } else {
            if (nodeMap.size() == capacity)
                evict();
            DNode nodeToPut = new DNode(key, value);
            nodeMap.put(key, nodeToPut);
            
            insertToFront(nodeToPut);
        }
    }
    
    private void moveToFront(DNode toMove) {
        delete(toMove);
        insertToFront(toMove);
    }
    
    private void delete(DNode toDelete) {
        DNode toDeletePrev = toDelete.prev; 
        DNode toDeleteNext = toDelete.next; 
        toDeletePrev.next = toDeleteNext;
        toDeleteNext.prev = toDeletePrev;
    }
    
    private void insertToFront(DNode toInsert) {
        DNode headNext = head.next;
        head.next = toInsert;
        toInsert.next = headNext;
        headNext.prev = toInsert;
        toInsert.prev = head;
    }
    
    void evict() {                   
        DNode toEvict = tail.prev;
        
        toEvict.prev.next = tail;
        tail.prev = toEvict.prev;
        
        nodeMap.remove(toEvict.k);
    }
    
    class DNode {
        int k, v;
        DNode next;
        DNode prev;
        public DNode(int k, int v) {
            this.k = k;
            this.v = v;
            next = null;
            prev = null;
        }
    }
}
