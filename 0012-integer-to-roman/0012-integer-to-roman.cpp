class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> storeIntRoman = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

        string res;

        for(int i = 0; i<storeIntRoman.size();i++){
            if(num==0) break;

            int times = num / storeIntRoman[i].first;

            while(times--){
                res += storeIntRoman[i].second;
            }

            num = num % storeIntRoman[i].first;
        }

        return res;
    };

};