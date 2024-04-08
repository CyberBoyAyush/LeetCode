class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        vector<int>ans;

    map<int,int>store;

    for(int i=0; i<v.size(); i++){

        store[v[i]]++;

    }

    for(auto x:store){

        if(x.second>v.size()/3)

         ans.push_back(x.first) ;

    }

    return ans;
    }
};