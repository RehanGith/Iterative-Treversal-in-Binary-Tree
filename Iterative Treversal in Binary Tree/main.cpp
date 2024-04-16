#include <iostream>
#include <stack>
using namespace std;
class Tree {
	int data;
public:
	Tree* left;
	Tree* right;
	Tree(int d = 0, Tree* l = nullptr, Tree* r = nullptr) : data(d), left(l), right(r) {
	}
	void set_data();
	int get_data() const;
	void set_left_right(Tree* l, Tree* r) {
		left = l; right = r;
	}

};
void Tree::set_data() {
	cout << "Enter data: ";
	cin >> data;
}
int Tree::get_data() const {
	return data;
}
void iterative_inorder(Tree* temp) {
	if (temp == nullptr)
		return;
	stack <Tree*> t;
	do{
		if (temp != nullptr) {
			t.push(temp);
			temp = temp->left;
		}
		else {
			temp = t.top();
			t.pop();
			cout << temp->get_data() << endl;
			temp = temp->right;
		}
	} while (!t.empty() || temp != nullptr);
}
void iterative_preorder(Tree* temp) {
	if (temp == nullptr)
		return;
	stack <Tree*> t;
	do {
		if (temp != nullptr) {
			cout << temp->get_data() << endl;
			t.push(temp);
			temp = temp->left;
		}
		else {
			temp = t.top();
			t.pop();
			temp = temp->right;
		}
	} while (!t.empty() || temp != nullptr);
}
void iterative_postorder(Tree* temp) {
	if (temp == nullptr)
		return;
	stack <Tree*> t;
	Tree* nnode = nullptr;
	do {
		if (temp != nullptr) {
			t.push(temp);
			temp = temp->left;
		}
		else {
			if(nnode)
				cout << nnode->get_data() << endl;
			nnode = temp = t.top();
			t.pop();
			temp = temp->right;
		}
	} while (!t.empty() || temp != nullptr);
	cout << nnode->get_data() << endl;
}
int main() {
	Tree* nl = new Tree(11);
	Tree* nr = new Tree(5);
	Tree* n = new Tree(7, nl, nr);
	Tree* nl_left = new Tree(13);
	Tree* nr_left = new Tree(8);
	Tree* nr_right = new Tree(2);
	nl->set_left_right(nl_left, nullptr);
	nr->set_left_right(nr_left, nr_right);

	iterative_postorder(n);
	delete n, nl, nr, nl_left, nr_left, nr_right;

	return 0;
}