class Solution {
private:

int firstOccurence(vector<int>& arr, int size,int key){
    int start = 0;
    int end = size - 1;
    int mid = start + (end-start)/2;
    int ans = -1;
    while(start<=end){
        if(key==arr[mid]){
            ans = mid;
            end = mid-1;
        }
        else if(key>arr[mid]){
            start = mid + 1;
        }
        else if(key<arr[mid]){
            end = mid - 1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}
int lastOccurence(vector<int>& arr, int size,int key){
    int start = 0;
    int end = size - 1;
    int mid = start + (end-start)/2;
    int ans = -1;
    while(start<=end){
        if(key==arr[mid]){
            ans = mid;
            start = mid+1;
        }
        else if(key>arr[mid]){
            start = mid + 1;
        }
        else if(key<arr[mid]){
            end = mid - 1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}

public:
    vector<int> searchRange(vector<int>& nums, int target) {
         pair <int,int> p;
        int n = nums.size();
        int first = firstOccurence(nums,n,target);
        int last = lastOccurence(nums,n,target);

    return {first, last};
    }
};