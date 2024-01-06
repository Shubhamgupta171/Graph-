//Inorder traversal of a BST gives us a sorted order of the items in it.
//So a simple inorder breaking off at the kth item would give us our answer !

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        
        while(root != NULL || !s.empty()){
            while(root != NULL){
                s.push(root);
                root = root->left;
            }    
            
            root = s.top(); s.pop();
            
            if(--k == 0) return root->val;
            
            root = root->right;
        }
        
        return -1;
    }
};
