class Solution {
public:
    string removeOccurrences(string s, string part) {
        // while(s.find(part)!=string::npos){
        //     s.erase(s.find(part),part.length());
        // }
        // return s;

        // stack
        int partLen = part.length();
        string stack; // Using a string as a stack
        
        for (char c : s) {
            stack.push_back(c); // Push character onto stack
            
            // Check if the top of the stack contains the substring `part`
            if (stack.size() >= partLen && stack.substr(stack.size() - partLen) == part) {
                stack.erase(stack.size() - partLen, partLen); // Remove the substring `part`
            }
        }
        
        return stack; // The stack now contains the result string
    }
};