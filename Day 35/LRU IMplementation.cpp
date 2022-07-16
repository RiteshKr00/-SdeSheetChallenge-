#include<bits/stdc++.h>
/*learn about list splice function
-->used to transfer  elements from one list to another.
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
