#ifndef __TREE_H_
#define __TREE_H_
#include <iostream>
//#include "iterators.h"

enum Mode { PREORDER, INORDER, POSTORDER };

//-----------------------------------
// class BinaryTree (Binary Trees)
// process nodes in Pre/In/Post order
//-----------------------------------
template <typename T, typename Key>
class BinaryTree {
	Mode _mode;

protected:
	//--------------------------------------------------------
	// inner class Node
	// a single Node from a binary tree
	//--------------------------------------------------------
	class Node {
	protected:
		Node* _left;
		Node* _right;
		T _value;
		Node* _parent;
	public:
		Node(const T& value)
			: _value(value), _left(nullptr), _right(nullptr), _parent(nullptr) {}
		Node(const T& value,  Node* left,  Node* right, Node* parent)
			: _value(value), _left(left), _right(right), _parent(parent) {}
		T& value() { return this->_value; }
		void value(const T& value) { _value = value; }
		Node* left() const { return _left; }
		void left(Node* node) { _left = node; node->_parent = this; }
		Node* right() const { return _right; }
		void right(Node* node) { _right = node;  node->_parent = this;}
		Node* parent() const { return _parent; }
		void parent(Node* node) { _parent = node; }
	}; //end of Node class

	using GetKey = Key(*)(const T&);
	using ValueProc = void(*)(T&);

	GetKey _getKey;
	ValueProc _delete;

	Node* root;
	virtual void process(Node& node, ValueProc process) const { process(node.value()); }

public:
	//class Iterator : public BidirectionalIterator<Node, T> {
		// HOMEWORK
	//};

	BinaryTree(GetKey getKey, ValueProc del)
		: root(nullptr), _mode(INORDER), _getKey(getKey), _delete(del) {}
	BinaryTree() : BinaryTree([](const T& value) { return static_cast<Key>(value); }, 
		                      [](T& value) {}) {}

	virtual ~BinaryTree() { if (root != nullptr) clear(root); }

	BinaryTree(const BinaryTree&) = delete;
	BinaryTree(BinaryTree&&) = delete;
	BinaryTree& operator=(const BinaryTree&) = delete;
	BinaryTree& operator=(BinaryTree&&) = delete;

	void mode(Mode mode) { _mode = mode; }
	Mode mode() const { return _mode; }

	int isEmpty() const { return root == nullptr; }
	void clear() { clear(root); root = nullptr; }
	void process(ValueProc) const;
	void process() const { process([](T& value) { std::cout << value << " "; }); };

	virtual void add(const T&) = 0;
	virtual bool check(const Key&) const = 0;
	virtual T search(const Key&) const = 0;
	virtual void remove(const Key&) = 0;

private:
	void preOrder(ValueProc process) const { preOrder(root, process); }
	void inOrder(ValueProc process) const { inOrder(root, process); }
	void postOrder(ValueProc process) const { postOrder(root, process); }
	void clear(Node*);
	void preOrder(Node*, ValueProc) const;
	void inOrder(Node*, ValueProc) const;
	void postOrder(Node*, ValueProc) const;

public:
	//Iterator begin() {} HOMEWORK
	//Iterator end() {} HOMEWORK
	int leaves() const {return leaves(root); }
	int leaves(Node*) const;
	int height() const { return height(root); }
	int height(Node*) const;
	int onlyLeftSons() const { return onlyLeftSons(root); }
	int onlyLeftSons(Node*) const;
	void reflect() { reflect(root); }
	void reflect(Node*);
};

//----------------------------------------------------------
// class BinaryTree implementation
//----------------------------------------------------------
template <typename T, typename Key>
void BinaryTree<T, Key>::clear(Node* current) {
	if (current != nullptr) { // Release memory associated with children
		clear(current->left());
		clear(current->right());
		_delete(current->value());
		delete current;
	}
}

// preOrder processing of tree rooted at current
template <typename T, typename Key>
void BinaryTree<T, Key>::preOrder(Node* current, ValueProc proc) const {
	// visit Node,	 left child, right child
	if (current != nullptr) { // process current Node
		process(*current, proc);
		// then visit children
		preOrder(current->left(), proc);
		preOrder(current->right(), proc);
	}
}
// inOrder processing of tree rooted at current
template <typename T, typename Key>
void BinaryTree<T, Key>::inOrder(Node* current, ValueProc proc) const {
	// visit left child, Node, right child
	if (current != nullptr) {
		inOrder(current->left(), proc);
		process(*current, proc);
		inOrder(current->right(), proc);
	}
}
// postOrder processing of tree rooted at current
template <typename T, typename Key>
void BinaryTree<T, Key>::postOrder(Node* current, ValueProc proc) const {
	// visit left child, right child, node
	if (current != nullptr) {
		postOrder(current->left(), proc);
		postOrder(current->right(), proc);
		process(*current, proc);
	}
}

template <typename T, typename Key>
void BinaryTree<T, Key>::process(ValueProc process) const {
	switch (_mode) {
	case PREORDER:
		preOrder(process);
		break;
	case INORDER:
		inOrder(process);
		break;
	case POSTORDER:
		postOrder(process);
		break;
	}
}


//returns number of leaves in tree
template <typename T, typename Key>
int BinaryTree<T, Key>::leaves(Node* node)  const
{
	if (node == nullptr)
		return 0;
	if (node->right== nullptr && node->left == nullptr)
		return 1;
	if (node->right != nullptr)
		return 0 + leaves(node->right);
	if (node->left != nullptr)
		return 0 + leaves(node->left);
}

//returns the hight of the tree
template <typename T, typename Key>
int BinaryTree<T, Key>::height(Node* node) const {
	if (node == nullptr)
		return 0;
	else
	{
		/* compute the depth of each subtree */
		int lDepth = height(node->left);
		int rDepth = height(node->right);

		/* use the larger one */
		if (lDepth > rDepth)
			return(lDepth + 1);
		else return(rDepth + 1);
	}
	return 0;
}

template <typename T, typename Key>
int BinaryTree<T, Key>::onlyLeftSons(Node* node)  const {
	if (node == nullptr)
		return 0;
	if (node->right == nullptr && node->left == nullptr)
		return 0;
	if (node->right != nullptr)
		return 0 + leaves(node->right);
	if (node->left != nullptr)
		return 1 + leaves(node->left);

}

template <typename T, typename Key>
void BinaryTree<T, Key>::reflect(Node *node) {
	if (node == nullptr)
		return;
	reflect(node->right);
	Node temp(node->value);
	temp.left = node->left;
	node->left = node->right;
	node->right = temp.left;
	reflect(node->left);
	temp.left = node->left;
	node->left = node->right;
	node->right = temp.left;	
}

#endif // __TREE_H_
