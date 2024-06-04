class Solution {
public:
    bool vowel(char c){
        c = tolower(c);
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
            return true;
        return false;
    }
    string reverseVowels(string s) {
        int low = 0;
        int high = s.length()-1;

        while(low<=high){
            if(vowel(s[low]) && vowel(s[high])){
                swap(s[low],s[high]);
                low++;
                high--;
            }
            else if(!vowel(s[low])){
                low++;
            }
            else{
                high--;
            }
        }
        return s;
    }
};