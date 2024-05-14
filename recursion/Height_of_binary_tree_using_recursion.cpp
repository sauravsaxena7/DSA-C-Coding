#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left;
	Node *right;

	Node(int val){
		data=val;
		left=right=NULL;
	}
};

Node* buildTree(string str){
	// cout<<"saurav suman "<<str<<endl;
	if(str.length()==0 || str[0]=='N')
		return NULL;

	vector<char> ip;

	for(int i=0;i<str.length();i++){
		ip.push_back(str[i]);
	}

	Node *root = new Node(ip[0]-'0');

	queue<Node*> queue;
	queue.push(root);

	int i=1;
	while(!queue.empty() && i<ip.size()){
		Node* currNode = queue.front();
		queue.pop();
		char currVal = ip[i];

		if(currVal!='N'){
			currNode->left = new Node(currVal-'0');
			queue.push(currNode->left);

		}

		i++;
		if(i>=ip.size()){
			break;
		}

		currVal=ip[i];

		if(currVal!='N'){
			currNode->right=new Node(currVal-'0');
			queue.push(currNode->right);
		}
		i++;
	}

	return root;

}

class Solution{
public:
	int height(Node* node){

		if(node==NULL) return 0;

		int leftHeight = height(node->left);
		int rightHeight = height(node->right);


		return 1 + max(leftHeight,rightHeight);
	}
};

int main()
{
	
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string treeString;
		
		getline(cin,treeString);
		//cout<<"lola pola "<<treeString<<endl;
		Node* root = buildTree(treeString);
		Solution obj;
		cout<<obj.height(root)<<endl;
	}

	return 0;
}