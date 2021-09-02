#include <iostream>
using namespace std;


struct TreeNode
{
	std::string data; 
	TreeNode* left;
	TreeNode* right;
};


TreeNode* Minimum(TreeNode* root)
{
	while (root->left != NULL) root = root->left;
	return root;
}



TreeNode* GetNewNode(std::string data)
{
	TreeNode* newNode = new TreeNode(); 
	
	
	newNode->data = data; 
	newNode->left = newNode->right = NULL; 
	return newNode; 
}


struct TreeNode* Delete(struct TreeNode *root, std::string data)
{
	if (root == NULL) return root;
	else if (data < root->data) root->left = Delete(root->left, data);
	else if (data > root->data) root->right = Delete(root->right, data);
	
	else
	{
		
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		}
		
		else if (root->left == NULL)
		{
			struct TreeNode *temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL)
		{
			struct TreeNode *temp = root;
			root = root->left;
			delete temp;
		}
		
		else
		{
			struct TreeNode *temp = Minimum(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	return root;
}

void Ordering(TreeNode *root)
{
	if (root == NULL) return;

	Ordering(root->left); 
	cout << root->data << endl; 
	Ordering(root->right); 
}


TreeNode* Insert(TreeNode* root, std::string data)
{
	if (root == NULL) 
	{
		root = GetNewNode(data); 
	}
	
	
	else if (data <= root->data) 
	{
		root->left = Insert(root->left, data); 
											   
											   
											   
											   
	}
	else
	{
		root->right = Insert(root->right, data);
	}
	return root;
}



bool Search(TreeNode* root, std::string data)
{
	if (root == NULL) return false;
	else if (root->data == data) return true;
	
	else if (data <= root->data) return Search(root->left, data);
	
	else return Search(root->right, data);
}

int main()
{
	
	TreeNode* root; 
	root = NULL; 
	root = Insert(root, "Train1");
	root = Insert(root, "Train2");
	root = Insert(root, "Train3");
	root = Insert(root, "Train4");
	root = Insert(root, "Train5"); 
	root = Insert(root, "Train6");
	std::string letter;
	cout << "Enter Train\n";
	cin >> letter;
	if (Search(root, letter) == true) cout << "Found\n";
	else cout << "Not found\n";
	cout << "Ordered: ";
	Ordering(root);
	cout << "\n";
	cout << "After del: " << endl;
	root = Delete(root, "Train5");
	Ordering(root);
}
