#include <bits/stdc++.h>
struct TrieNode
{
    TrieNode *child[26];
    bool isend=false;
    int countword=0;
    int countpre=0;
    bool containskey(int ch)
    {
        if(child[ch]==NULL) return false;
        else return true;
    }
    void setend()
    {
        isend=true;
    }
    bool getend()
    {
        return isend;
    } 
    void incend(){
        countword++;
    }
    void incpre(){
        countpre++;
    }
    int getcountword(){
       return countword;
    }
    int getcountpre(){
        return countpre;
    }
    void reducepre(){
        countpre--;
    }
    void deleteend(){
        countword--;
    }
    TrieNode* get(int ind)
    {
        return child[ind];
    }
};
class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    void insert(string &word){
        int n = word.length();
        TrieNode* head = root;
        for(int i=0;i<n;i++)
        {
            int ind = word[i]-'a';
            if(!(head->containskey(ind)))
            {
                TrieNode *temp = new TrieNode;
                head->child[ind]=temp;
            }
               head=head->child[ind];
            head->incpre();
        }
        head->incend();
        head->setend();
    }
    int countWordsEqualTo(string &word){
        int n = word.length();
        TrieNode* head = root;
        for(int i=0;i<n;i++)
        {
            int ind = word[i]-'a';
            if(head->containskey(ind))
                 head=head->child[ind];
            else return 0;
        }
        return head->getcountword();
    }

    int countWordsStartingWith(string &word){
       int n = word.length();
        TrieNode* head = root;
        for(int i=0;i<n;i++)
        {
            int ind = word[i]-'a';
            if(head->containskey(ind))
                 head=head->child[ind];
            else return 0;
        }
        return head->getcountpre();
    }

    void erase(string &word){
       int n = word.length();
        TrieNode* head = root;
        for(int i=0;i<n;i++)
        {
            int ind = word[i]-'a';
            if(head->containskey(ind))
            {
               head=head->child[ind];
                head->reducepre();
            }  
            else return;
        }
        head->deleteend();
    }
};