#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    void levelOrder(Node * root) {
        queue<Node> q;
        q.push(*root);
        while(!q.empty()){
            Node n = q.front();

            if(n.left){
                q.push(*n.left);
            }
            if(n.right){
                q.push(*n.right);
            }

            cout<<n.data<<" ";
            q.pop();
        }

    }

    void postOrder(Node *root) {
        if(root == NULL)
        {
            return;
        }
        postOrder(root->left);
        postOrder(root->right);
        
        cout<<root->data<<" ";
    }

    void inOrder(Node *root) {
        if(root == NULL)
        {
            return;
        }

        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }

    void preOrder(Node *root) {
        if(root == NULL)
        {
            return;
        }

        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void leftView(Node* root)
    {
        if(root == NULL)
        {
            return;
        }
        cout<<root->data;
        leftView(root->left);
    }

    void rightView(Node* root)
    {
        if(root == NULL)
        {
            return;
        }
        cout<<root->data;
        rightView(root->right);
    }

    void topView(Node * root) {
        if(root != NULL)
        {
            leftView(root);
            cout<<root->data;
            rightView(root);
        }
        
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	//myTree.postOrder(root);
	myTree.inOrder(root);
	//myTree.preOrder(root);
    //myTree.levelOrder(root);
    //myTree.topView(root);
    return 0;
}
