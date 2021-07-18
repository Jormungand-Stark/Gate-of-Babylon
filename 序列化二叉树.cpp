/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "[]";
        string res("[");
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode* node = que.front();
            que.pop();
            if(node){
                res.append(to_string(node->val) + ",");
                que.push(node->left);
                que.push(node->right);
            }
            else res.append("~,");
        }
        res.erase(res.size()-1);
        res.append("]");
        //cout << res << endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="[]") return nullptr;
        vector<TreeNode*> nodes;
        int i = 1;//剥离'['
        while(i < data.size()){
            string stmp = "";
            while(data[i]!=',' && data[i]!=']'){
                stmp += data[i];
                i++;
            }
            
            if(stmp == "~"){
                nodes.push_back(nullptr);
            }
            else{
                int temp = stoi(stmp);
                TreeNode* node = new TreeNode(temp);//string转int
                nodes.push_back(node);
            }
            i++;
        }
        
        int pos = 1;//数组构成二叉树映射关系
        for(int j = 0; j < nodes.size(); j++){
            if(!nodes[j]) continue;
            nodes[j]->left = nodes[pos++];
            nodes[j]->right = nodes[pos++];
        }
        return nodes[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
