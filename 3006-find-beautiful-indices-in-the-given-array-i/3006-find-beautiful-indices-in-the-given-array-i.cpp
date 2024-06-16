class Solution {
public:
void computeLPS(string pat, vector<int> &LPS, int M){
        int len = 0;
        LPS[0] = 0;
        
        int i = 1;
        
        while(i<M){
            if(pat[i] == pat[len]){
                len++;
                LPS[i] = len;
                i++;
            }
            
            else{
                if(len!=0){
                    len = LPS[len-1];
                }
                else{
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }
        vector <int> KMP(string pat, string txt)
        {
            int N = txt.length();
            int M = pat.length();
            
            vector<int> result;
            
            vector<int> LPS(M,0);
            computeLPS(pat,LPS,M); // yeh boii LPS bana do
            
            int i = 0;
            int j = 0;
            while(i<N){
                if(pat[j] == txt[i]){ // match horela hai
                    i++;
                    j++;
                }
                
                if(j==M){ // string match hogya yehhhh
                    result.push_back(i-j);
                    j = LPS[j-1];
                }
                
                else if(pat[j] != txt[i]){
                    if(j!=0){
                        j = LPS[j-1]; // j pointer ko pichle wale lps pe khiskha do
                    }
                    else{
                        i++; //upar wale step se bhi kuch nahi hua
                    }
                }
            }
            return result;
        }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.length();
        
        vector<int> i_indices = KMP(a, s);
        vector<int> j_indices = KMP(b, s);
        /*
            Just simply find the indices where a is present in s
            Just simply find the indices where b is present in s
        */
    
        vector<int> result;
        
        for(int &i : i_indices) {
            /*
                For every index i where 'a' was found in 's'
                I will see if we find any index j in the range i-k and i+k
            */
            
            int left_limit  = max(0, i - k);   //To avoid out of bound -> I used max(0, i-k)
            int right_limit = min(n-1, i + k); //To avoid out of bound -> I used min(n-1, i+k)
            
            auto it = lower_bound(begin(j_indices), end(j_indices), left_limit);
            
            if(it != j_indices.end() && *it <= right_limit) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};