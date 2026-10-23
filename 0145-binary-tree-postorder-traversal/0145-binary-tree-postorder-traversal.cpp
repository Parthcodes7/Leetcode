class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if (!root) return postorder;

        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != nullptr || !st.empty()) {
            if (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            } 
            else {
                TreeNode* temp = st.top()->right;
                
                if (temp == nullptr) {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->val);

                    while (!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                        st.pop();
                        postorder.push_back(temp->val);
                    }
                } 
                else {
                    curr = temp;
                }
            }
        }

        return postorder;
    }
};