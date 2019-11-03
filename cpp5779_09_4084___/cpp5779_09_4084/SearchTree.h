#ifndef __SEARCH_TREE_H_
#define __SEARCH_TREE_H_

#include "Tree.h"

template <typename T, typename Key>
class SearchTree : public BinaryTree<T, Key> {
	using typename BinaryTree<T, Key>::GetKey;
	using typename BinaryTree<T, Key>::Node;
	using BinaryTree<T, Key>::root;
	using BinaryTree<T, Key>::_getKey;
public:
	SearchTree() {}
	SearchTree(GetKey getKey) : BinaryTree<T, Key>(getKey) {}
	SearchTree(const SearchTree&) = delete;
	SearchTree(SearchTree&&) = delete;
	SearchTree& operator=(const SearchTree&) = delete;
	SearchTree& operator=(SearchTree&&) = delete;

	// protocol for search trees
	void add(const T& value) override;
	bool check(const Key& key) const override { return check(root, key); }
	T search(const Key& key) const override { return search(root, key); }
	void remove(const Key& key) override { root = remove(root,search(key)); }
	int level(const Key& key) const { return level(root,key); }

private:
	void add(Node*, const T&);
	bool check(Node* current, const Key& key) const;
	T search(Node* current, const Key& key) const;
	Node* remove(Node* root, T value);
	Node* FindMax(Node * node)const {
		if (node == nullptr)
			return nullptr;

		while (node->right != nullptr)
		{
			node = node->right;
		}
		return node;
	}
	int level(Node*, Key& key) const;
};

template <typename T>
class SearchTreeSimple : public SearchTree<T, T> {
public:
	SearchTreeSimple() {}
	SearchTreeSimple(const SearchTreeSimple&) = delete;
	SearchTreeSimple(SearchTreeSimple&&) = delete;
	SearchTreeSimple& operator=(const SearchTreeSimple&) = delete;
	SearchTreeSimple& operator=(SearchTreeSimple&&) = delete;
};

template <typename T, typename Key>
void SearchTree<T, Key>::add(const T& value) {
	// add value to binary search tree
	if (root == nullptr) {
		root = new Node(value);
	}
	else
		add(root, value);
}

template <typename T, typename Key>
bool SearchTree<T, Key>::check(Node* current, const Key& key) const {
	// see if argument value occurs in tree
	if (current == nullptr)
		return false; // not found
	if (_getKey(current->value()) == key)
		return true;
	if (_getKey(current->value()) < key)
		return check(current->right(), key);
	else
		return check(current->left(), key);
}

template <typename T, typename Key>
T SearchTree<T, Key>::search(Node* current, const Key& key) const {
	// see if argument value occurs in tree
	if (current == nullptr)
		throw "not found:"; // not found
	if (_getKey(current->value()) == key)
		return current->value();
	if (_getKey(current->value()) < key)
		return search(current->right(), key);
	else
		return search(current->left(), key);
}

template <typename T, typename Key>
void SearchTree<T, Key>::add(Node* current, const T& value) {
	if (_getKey(current->value()) < _getKey(value))
		// add to right subtree
		if (current->right() == nullptr)
			current->right(new Node(value));
		else
			add(current->right(), value);
	else
		// add to left subtree
		if (current->left() == nullptr)
			current->left(new Node(value));
		else
			add(current->left(), value);
}

template <typename T, typename Key>
Node* SearchTree<T, Key>::remove(Node* root, T value) {

	if(!check(_getkey(T)))
		throw "not found:"; // not found
	if (root == nullptr) return root;
	else if (value <= root->_value)
		root->left = DeleteNodeInBST(root->_left, value);
	else if (value > root->_value)
		root->right = DeleteNodeInBST(root->_right, value);
	else
	{
		//No child
		if (root->_right == nullptr && root->_left == nullptr)
		{
			delete root;
			root = nullptr;
		}
		//One child 
		else if (root->_right == nullptr)
		{
			Node* temp = root;
			root = root->_left;
			delete temp;
		}
		else if (root->_left == nullptr)
		{
			Node* temp = root;
			root = root->_right;
			delete temp;
		}
		//two child
		else{
			Node* temp = FindMax(root->_left);
			root->_value = temp->_value;
			root->_left = DeleteNodeInBST(root->_left, temp->_value);
		}
	}
	return root;	
}


template <typename T, typename Key>
int SearchTree<T, Key>::level(Node* node, Key& key) const
{
	if (!check(key))
		return -1; // not found
	if (_getKey(node->value()) == key)
		return 0;
	if (_getKey(node->value()) < key)
		return level(node->right(), key)+1;
	else
		return level(node->left(), key)+1;
}

#endif // __SEARCH_TREE_H_
