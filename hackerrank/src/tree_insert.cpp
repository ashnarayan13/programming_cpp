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
  	
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
    }

/*
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

    Node * insert(Node * root, int data) {
        if(root == NULL)
        {
            root = new Node(data);
            return root;
        }
        Node* dummy = root;
        while(root != NULL)
        {
            if(root->data > data)
            {
                // Go left
                if(root->left)
                {
                    root = root->left;
                }
                else
                {
                    root->left = new Node(data);
                    break;
                }
            }
            else
            {
                // Go right
                if(root->right)
                {
                    root = root->right;
                }
                else
                {
                    root->right = new Node(data);
                    break;
                }
            }
        }
        return dummy;
    }

    Node * rec(Node * cur, int data)
    {
        if(cur == NULL)
        {
            cur = new Node(data);
        }
        else if(cur->data > data)
        {
            cur->left = rec(cur->left, data);
        }
        else
        {
            cur->right = rec(cur->right, data);
        }
        return cur;
        
    }

    Node * insertRec(Node * root, int data)
    {
        if(root==NULL)
        {
            root = new Node(data);
            return root;
        }
        else
        {
            Node* dummy = root;
            rec(dummy, data);
            return root;
        }
        
    }

};

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        //root = myTree.insert(root, data);
        root = myTree.insertRec(root, data);
    }
  	
    myTree.preOrder(root);
  
    return 0;
}
