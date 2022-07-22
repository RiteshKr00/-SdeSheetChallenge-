#include <bits/stdc++.h> 
void merge(long long *arr,int l, int mid,int r,int &count){
    int t1=mid-l+1;
    int t2=r-mid;
    int k=l;
    vector<long long>temp1(t1),temp2(t2);
    for(int i=0;i<t1;i++){
        temp1[i]=arr[l+i];
    }
    for(int j=0;j<t2;j++){
        temp2[j]=arr[mid+1+j];
        }
    int i=0,j=0;
    while(i<t1&&j<t2){
        if(temp1[i]<=temp2[j]){
            arr[l++]=temp1[i++];
        }else{
//             cout<<(t1-i)<<endl;
            count+=(t1-i);
//             cout<<"-->"<<count<<endl;
            arr[l++]=temp2[j++];            
        }
    }
    while(i<t1){
        arr[l++]=temp1[i++];
    }
    while(j<t2){
        arr[l++]=temp2[j++];
    }
//     delete temp1,temp2;
    
}

void mergesort(long long *arr,int l, int r,int &count){
    if(l<r){
        int mid=l+(r-l)/2;
        mergesort(arr,l,mid,count);
        mergesort(arr,mid+1,r,count);
        merge(arr,l,mid,r,count);
    }
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    int count=0;
    mergesort(arr,0,n-1,count);
    return count;
}