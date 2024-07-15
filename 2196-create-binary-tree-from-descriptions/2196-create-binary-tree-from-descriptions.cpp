class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mpp; // storing address
        unordered_set<int> childSet; // stores the child values (Helps in retriving root)

        for(vector<int> &vec:descriptions){
            int parent = vec[0];
            int child = vec[1];
            int isLeft = vec[2];

            // finding parent in map
            if(mpp.find(parent) == mpp.end()){
                // parent not found in map
                mpp[parent] = new TreeNode(parent); // creation of parent node
            }

            // finding child in map
            if(mpp.find(child) == mpp.end()){
                // child not found in map
                mpp[child] = new TreeNode(child); // creation of child node
            }

            // now the orientation of node
            if(isLeft == 1){
                // left node hai
                mpp[parent]->left = mpp[child];
            }
            else{
                // right node hai
                mpp[parent]->right = mpp[child];
            }

            // pushing the value of child in multiset as it will never be our root
            childSet.insert(child);
        }

        // finding the root
        for(vector<int> &vec:descriptions){
            int parent = vec[0];
            // finding the parent in multiset
            if(childSet.find(parent) == childSet.end()){
                return mpp[parent]; // the parent node is our root
            }
        }
        return NULL; // it will never happen
    }
};