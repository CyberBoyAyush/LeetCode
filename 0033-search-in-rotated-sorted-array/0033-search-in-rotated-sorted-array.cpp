int getPivot(vector<int>& arr, int n){
    int s = 0;
    int e = n-1;
    int mid = s+ (e-s)/2;

    while(s<e){
        if(arr[mid]>=arr[0]){
            s = mid + 1;
        }
        else{
            e = mid;
        }
        mid = s+ (e-s)/2;
    }
    return s;
 }
 int binarySearch(vector<int>& arr,int s, int e,int key){
    int start = s;
    int end = e;
    // int mid = (start+end)/2;
    int mid = start + (end-start)/2;
    
    while(start<=end){
        if(arr[mid] == key){
            return mid;
        }

        // if key is greater then mid go to right side
        if(key>arr[mid]){
            start = mid+1;
        }
        // if key is greater then mid go to left side
        else{
            end = mid -1;
        }
        // now from above our start or mid is updated we also have to update mid
        // mid = (start+end)/2;
        mid = start + (end-start)/2;
    }
    return -1;
}

class Solution { public: int search(vector<int>& arr, int k) { 
    int pivot = getPivot(arr, arr.size());
    if(arr[pivot]<=k && arr[arr.size()-1]>=k){ //BS on line 2
        return binarySearch(arr,pivot,arr.size()-1,k);
    }
    else{// BS on line 1
        return binarySearch(arr,0,pivot-1,k);
    } 
} 
};

