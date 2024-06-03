// class Solution {
// public:
//     //custom comparator
//     static string str;
//     static bool compare(char char1, char char2) {

//         //this will return true, if position of character1 in str string is
//         //less than the position of character2 in str string

//         //when true is returned, then char1 will be placed before char2 in
//         //output string
//         return (str.find(char1) < str.find(char2));

//     }
//     string customSortString(string order, string s) {

//         str = order;
//         sort(s.begin(), s.end(), compare);
//         return s;
//     }
// };
// string Solution::str;

class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> mpp;

        // put string in map
        for(auto ch:s){
            mpp[ch]++;
    }

        //result string
        string res;

        //now making res string according to order
        for(auto ch : order){
            if(mpp.count(ch)){
                res.append(mpp[ch],ch);
                mpp.erase(ch);
        }
        }

        // now mapping something not in the order
        for(auto &entry:mpp){
            res.append(entry.second, entry.first);
        }
        return res;
    }
};