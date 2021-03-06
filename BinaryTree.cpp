#include <iostream>
#include <stack>
#include <fstream>
#include <string>
#include <iomanip>

typedef char itemType;

struct BTNode {
	itemType item;
	BTNode * left;
	BTNode * right;
	BTNode() {
		left = nullptr;
		right = nullptr;
	}
};

using namespace std;

BTNode* makeArithmeticExpressionTree(string postfix);
void postOrderPrint(BTNode* root);

int main(){// I didn't check if postfix expression are right or if there is something weird
		   // Also i didn't delete the binary tree because he doesn't say so
	ifstream infile;
	infile.open("data.txt");
	string postfix;
	while (getline(infile, postfix)) {
		cout << left << setw(29) << "postfix = " << postfix << endl;
		BTNode * root = makeArithmeticExpressionTree(postfix);
		cout << "Arithmetic Expression Tree = ";
		postOrderPrint(root);
		cout << endl;
	}
	return 0;
}
BTNode* makeArithmeticExpressionTree(string postfix) {
	BTNode * root;
	stack<BTNode*> s;
	for (unsigned i = 0; i < postfix.length(); i++) {
		char ch = postfix[i];
		if (ch == ' ')
			continue;
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			BTNode * rightChild = s.top();
			s.pop();
			BTNode * leftChild = s.top();
			s.pop();
			BTNode * node = new BTNode;
			node->left = leftChild;
			node->right = rightChild;
			node->item = ch;
			s.push(node);
		}
		else {
			BTNode * ptr = new BTNode;
			ptr->item = ch;
			s.push(ptr);
		}
	}
	root = s.top();
	s.pop();
	return root;
}
void postOrderPrint(BTNode* root) {
	if (!root)
		return;
	postOrderPrint(root->left);
	postOrderPrint(root->right);
	cout << root->item << " ";
}