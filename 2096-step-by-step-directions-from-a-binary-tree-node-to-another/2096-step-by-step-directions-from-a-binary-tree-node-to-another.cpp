class Solution {
public:
    //func to find the lowest common ancestor
    TreeNode* LCA(TreeNode* root, int start, int dest){
        if(!root)   return NULL;

        if(root->val == start || root->val == dest){
            return root;
        }

        // we go left and right
        TreeNode* l = LCA(root->left,start,dest);
        TreeNode* r = LCA(root->right,start,dest);

        if(l && r){
            // we found both either in left or right
            return root;
        }

        return l ? l : r; // we found only one l or r
    }

    bool findPath(TreeNode* LCA,int target,string &path){
        // if LCA is null
        if(!LCA)    return 0; // target not found

        // lca is target
        if(LCA->val==target)    return 1;

        // we go left part to search
        path.push_back('L');
        if(findPath(LCA->left,target,path)){
            return true; //left me path target milgya
        }
        // nhi mila toh L joh puhs kiya tha usko hatado
        path.pop_back();

        // we go right part to search
        path.push_back('R');
        if(findPath(LCA->right,target,path)){
            return true; //right me path target milgya
        }
        // nhi mila toh L joh puhs kiya tha usko hatado
        path.pop_back();
        

        // ab upar wala kuch nhi hua to we cant find target
        return 0;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCANode = LCA(root,startValue,destValue);

        // strings that stores the path on either side
        string LCAToStart = "";
        string LCAToDest = "";

        findPath(LCANode, startValue, LCAToStart);
        findPath(LCANode, destValue, LCAToDest);

        string res = "";
        // we have to write UU on the place of LCAToStart string as it is in reverse
        for(auto s:LCAToStart){
            res.push_back('U');
        }

        // add the LCAtoDest string in it becuase it is correct
        res += LCAToDest;

        return res;
    }
};