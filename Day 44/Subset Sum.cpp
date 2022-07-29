// T.C->O(2^N)
// Logic: similar to method of finding subset but just modify a little insted of storing
// the whole element in an array just store the sum upto curr index .

// Use Pick dontPick Concept
// pattern 1 and 2 both work
// and at last sort the array storing the sum


void func(int index,int sum,vector<int>arr,vector<int> &sumOfSubsets){
    
    if(index==arr.size()){
        sumOfSubsets.push_back(sum);
        return;
    }
    // picking 
    func(index+1,sum+arr[index],arr,sumOfSubsets);
    
    // not picking 
    func(index+1,sum,arr,sumOfSubsets);
}

vector<int> subsetSum(vector<int> &arr)
{
    // Write your code here
    vector<int>sumOfSubsets;
    func(0,0,arr,sumOfSubsets);
    sort(sumOfSubsets.begin(),sumOfSubsets.end());
    return sumOfSubsets;
}