class Solution {
public:
    void reverseString(vector<char>& arr) {
        int s = 0;
        int e = arr.size()-1;
        while(s<e){
        swap(arr[s++],arr[e--]);
    }
    }
};