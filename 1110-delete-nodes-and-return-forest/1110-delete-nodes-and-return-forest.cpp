class Solution {
public:
    TreeNode* deleteNodeHelper(TreeNode* root, unordered_set<int> &st, vector<TreeNode*> &result){
        // check root exisitence
        if(!root){
            return nullptr;
        }

        // we go to root left and right most
        root->left = deleteNodeHelper(root->left,st,result);
        root->right = deleteNodeHelper(root->right,st,result);

        if(st.find(root->val)!=st.end()){
            // this is the node we have to delete
            // first pushing value and left and right in result
            if(root->left)  result.push_back(root->left);
            if(root->right)  result.push_back(root->right);

            return nullptr; // this works as delteing node
        }
        else{
            // not the node to delte 
            return root;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;

        // set for storing values of vector to_deltete
        unordered_set<int> st;
        for(auto i:to_delete){
            st.insert(i);
        }

        // function that delte the roots we want to delete and than return the ans
        deleteNodeHelper(root,st,result);

        // we will check that do we also need to delete the root also
        if(st.find(root->val)==st.end()){
            result.push_back(root);
        }
        return result;
    }
};