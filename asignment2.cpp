
//MAXIMUM DEPTH OF A TREE 
class Solution {
public:
    int call(TreeNode* root, int c){
        //static int c=0;
        if (root==nullptr) return c;
        if(root!=nullptr) c++;
        int a =call(root->left,c);
        int b =call(root->right,c);
        c= max(a,b);
        return c;


    }
    int maxDepth(TreeNode* root) {
        int count =call(root,0);
        return count;
    }
};

//find the bottom tree value
class Solution {
public:
    
    TreeNode* lot(TreeNode* a){
        queue<TreeNode*> q;
        TreeNode* temp;
        TreeNode* temp2;
        q.push(a);
        q.push(NULL);
        
        while(!q.empty()){
            temp=q.front();
            if(temp==nullptr){
                q.pop(); 
                if(!q.empty()){
                    temp=q.front(); 
                    temp2=temp;
                }
                else break;
            q.pop();
            q.push(nullptr);    
            }
            else{
                if(temp->left)  q.push(temp->left);
                if(temp->right) q.push(temp->right);
                //if(temp->left!=NULL || temp->right!=NULL) q.push(nullptr);
            }
        
        }
        return temp2;
    }
    

    int findBottomLeftValue(TreeNode* root) {
        root=lot(root);
        return root->val;
    }
};
// Search in a BST
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode*temp;
        temp =root;
        while(temp !=nullptr){
            if(temp->val==val) break;
            if(temp->val >val) temp=temp->left;
            else temp=temp->right;
           
        }
        return temp;
    }
};

//Inorder Traversal
class Solution {
public:


    vector<int> push (vector<int> &v, TreeNode* root){
        //TreeNode* temp =root;
        if(!root) return v;
        if (root->left != nullptr) v= push(v,root->left);
        v.push_back(root->val);
        if(root->right != nullptr) v =push(v,root->right);
        return v;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        push(v,root);
        return v;
    }
};
