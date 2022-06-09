
// T>C-O(Nlogn)
bool areAnagram(string &str1, string &str2){
    // Write your code here.
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());
    return str1==str2;
}
//Hash MAp
// we can use hash map to store the element (increment once and decrement once )
// and if all values  are zero after operation on both
// than its a anagram;
// T.C->O(N) S.C->O(N);
// Note :if element is of one type(limited like lower case or upper case)
//  or adjacent on terms of ascii value then we can use array in palce of map 
//  to reduce compilation time