// intbst.cpp
// Implements class IntBST
// Brian Ozawa Burns, 06/02/2021

#include <string>

#include <iostream>
using std::cout;

// constructor sets up empty tree
template<typename T>
IntBST<T>::IntBST() : root(0) { }

// destructor deletes all nodes
template<typename T>
IntBST<T>::~IntBST() {
    clear(root);
}

// recursive helper for destructor
template<typename T>
void IntBST<T>::clear(Node *n) {
    if (n) {
        clear(n->left);
        clear(n->right);
        delete n;
    }
}

// insert value in tree; return false if duplicate
template<typename T>
bool IntBST<T>::insert(T value) {
    // handle special case of empty tree first
    if (!root) {
        root = new Node(value);
        return true;
    }
    // otherwise use recursive helper
    return insert(value, root);
}

// recursive helper for insert (assumes n is never 0)
template<typename T>
bool IntBST<T>::insert(T value, Node *n) {
    if (value == n->info)
	    return false;
    if (value < n->info) {
        if (n->left)
            return insert(value, n->left);
        else {
            n->left = new Node(value);
            n->left->parent = n;
            return true;
        }
    }
    else {
        if (n->right)
            return insert(value, n->right);
        else {
            n->right = new Node(value);
            n->right->parent = n;
            return true;
        }
    }
}

// print tree data pre-order
template<typename T>
void IntBST<T>::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
template<typename T>
void IntBST<T>::printPreOrder(Node *n) const {
    if (n) {
        cout << n->info << " ";
        printPreOrder(n->left);
        printPreOrder(n->right);
    }
}

// print tree data in-order, with helper
template<typename T>
void IntBST<T>::printInOrder() const {
    printInOrder(root);
}
template<typename T>
void IntBST<T>::printInOrder(Node *n) const {
    if ( !n ){ // root doesn't exist, tree/subtree empty
        return;
    }
    else { // tree not empty, order: left node, root node, right node
        if ( n->left ){
            printInOrder(n->left);
        }
        cout << n->info << " ";
        if ( n->right ){
            printInOrder(n->right);
        }
    }
}

// prints tree data post-order, with helper
template<typename T>
void IntBST<T>::printPostOrder() const {
    printPostOrder(root);
}

template<typename T>
void IntBST<T>::printPostOrder(Node *n) const {
    if ( !n ){ // root doesn't exist, tree/subtree empty
        return;
    }
    else { // tree not empty, order: left node, right node, root node
        if ( n->left ){
            printPostOrder(n->left);
        }
        if ( n->right ){
            printPostOrder(n->right);
        }
        cout << n->info << " ";
    }
}

// return sum of values in tree
template<typename T>
int IntBST<T>::sum() const {
    return sum(root);
}

// recursive helper for sum
template<typename T>
int IntBST<T>::sum(Node *n) const {
    int total = 0;
    if ( !n ){ // root doesn't exist, tree/subtree empty
        return 0;
    }
    else { // tree not empty, return sum of left and right subtree nodes with current node's value
        if ( n->left ){
            total += sum(n->left);
        }
        if ( n->right ){
            total += sum(n->right);
        }
        return total + n->info;
    }
}

// return count of values
template<typename T>
int IntBST<T>::count() const {
    return count(root);
}

// recursive helper for count
template<typename T>
int IntBST<T>::count(Node *n) const {
    int numNodes = 0;
    if ( !n ){ // root doesn't exist, tree/subtree empty
        return 0;
    }
    else { // tree not empty, return sum of numNodes in left and right subtrees +1 with current node included
        if ( n->left ){
            numNodes += count(n->left);
        }
        if ( n->right ){
            numNodes += count(n->right);
        }
        return numNodes + 1;
    }

    return 0;
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
template<typename T>
typename IntBST<T>::Node* IntBST<T>::getNodeFor(T value, Node* n) const{
    return NULL; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the tree; false if not
template<typename T>
bool IntBST<T>::contains(T value) const {
    Node *n;
    n = this->root;
    if ( !n ){ // root doesn't exist, tree/subtree empty
        return false;
    }
    while ( n ){
        if ( value < n->info ){ // search left subtree
            n = n->left;
        }
        else if ( value > n->info ){ // search right subtree
            n = n->right;
        }
        else { // n->data is value, return true
            return true;
        }
    }

    return false; 
}

// returns the Node containing the predecessor of the given value
template<typename T>
typename IntBST<T>::Node* IntBST<T>::getPredecessorNode(T value) const{
    Node *n;
    n = root;
    if ( !n ){ // root doesn't exist, tree/subtree empty
        return nullptr;
    }
    if ( contains(value) ){ // checks to make sure value is in fact contained within the BST
        while ( n ){
            if ( value < n->info ){ // search left subtree for value
                n = n->left;
            }
            else if ( value > n->info ){ // search right subtree for value
                n = n->right;
            }
            else{ // value found, now find predecessor
                if ( !n->parent && !n->left ){ // if node has no parent and no left subtree, then there is no predecessor
                    return nullptr;
                }
                else if ( n->parent && !n->left ){ // else if node has no left subtree, but has a parent
                    if ( n->parent->info < n->info ){ // check if parent is predecessor
                        return n->parent;
                    }
                    else if ( n->parent->info > n->info ){ // check if parent's parent is predecessor and so on until null
                        n = n->parent;
                        while ( n->parent->parent ){
                            n = n->parent;
                            if ( n->info < value ){ // return first parent whose info is less than value
                                return n;
                            }
                        }
                        if ( n->parent->info < value ){ // n->parent->parent is null so checking root if predecessor
                            return n->parent;
                        }
                        else { // no parent is predecessor, return nullptr
                            return nullptr;
                        }
                    }
                    else {
                        return nullptr;
                    }
                }
                else if ( n->left ){ // else left subtree exists, predecessor is the rightmost element of left subtree
                    n = n->left;
                    while ( n && n->right ){
                        n = n->right;
                    }
                    return n;
                }
            }
        }
    }
    return nullptr;
}

// returns the predecessor value of the given value or 0 if there is none
template<typename T>
T IntBST<T>::getPredecessor(T value) const{
    Node *n;
    n = root;
    if ( !n ){ // root doesn't exist, tree/subtree empty
        return 0;
    }
    if ( contains(value) ){ // checks to make sure value is in fact contained within the BST
        while ( n ){
            if ( value < n->info ){ // search left subtree for value
                n = n->left;
            }
            else if ( value > n->info ){ // search right subtree for value
                n = n->right;
            }
            else{ // value found, now find predecessor
                if ( !n->parent && !n->left ){ // if node has no parent and no left subtree, then there is no predecessor
                    return 0;
                }
                else if ( n->parent && !n->left ){ // else if node has no left subtree, but has a parent
                    if ( n->parent->info < n->info ){ // check if parent is predecessor
                        return n->parent->info;
                    }
                    else if ( n->parent->info > n->info ){ // check if parent's parent is predecessor and so on until null
                        n = n->parent;
                        while ( n->parent->parent ){
                            n = n->parent;
                            if ( n->info < value ){ // return first parent whose info is less than value
                                return n->info;
                            }
                        }
                        if ( n->parent->info < value ){ // n->parent->parent is null so checking root if predecessor
                            return n->parent->info;
                        }
                        else { // no parent is predecessor, return 0
                            return 0;
                        }
                    }
                    else {
                        return 0;
                    }
                }
                else if ( n->left ){ // else left subtree exists, predecessor is the rightmost element of left subtree
                    n = n->left;
                    while ( n && n->right ){
                        n = n->right;
                    }
                    return n->info;
                }
            }
        }
    }
    return 0;
}

// returns the Node containing the successor of the given value
template<typename T>
typename IntBST<T>::Node* IntBST<T>::getSuccessorNode(T value) const{
    Node *n;
    n = root;
    if ( !n ){ // root doesn't exist, tree/subtree empty
        return nullptr;
    }
    if ( contains(value) ){ // checks to make sure value is in fact contained within the BST
        while ( n ){
            if ( value < n->info ){ // search left subtree for value
                n = n->left;
            }
            else if ( value > n->info ){ // search right subtree for value
                n = n->right;
            }
            else{ // value found, now find successor
                if ( !n->parent && !n->right ){ // if node has no parent and no right subtree, then there is no successor
                    return nullptr;
                }
                else if ( n->parent && !n->right ){ // else if node has no right subtree, but has a parent
                    if ( n->parent->info > n->info ){ // check if parent is successor
                        return n->parent;
                    }
                    else if ( n->parent->info < n->info ){ // check if parent's parent is successor and so on until null
                        n = n->parent;
                        while ( n->parent->parent ){
                            n = n->parent;
                            if ( n->info > value ){ // return first parent whose info is greater than value
                                return n;
                            }
                        }
                        if ( n->parent->info > value ){ // n->parent->parent is null so checking root if successor
                            return n->parent;
                        }
                        else { // no parent is successor, return nullptr
                            return nullptr;
                        }
                    }
                    else {
                        return nullptr;
                    }
                }
                else if ( n->right ){ // else right subtree exists, successor is the leftmost element of right subtree
                    n = n->right;
                    while ( n && n->left ){
                        n = n->left;
                    }
                    return n;
                }
            }
        }
    }
    return nullptr; 
}

// returns the successor value of the given value or 0 if there is none
template<typename T>
T IntBST<T>::getSuccessor(T value) const{
    Node *n;
    n = root;
    if ( !n ){ // root doesn't exist, tree/subtree empty
        return 0;
    }
    if ( contains(value) ){ // checks to make sure value is in fact contained within the BST
        while ( n ){
            if ( value < n->info ){ // search left subtree for value
                n = n->left;
            }
            else if ( value > n->info ){ // search right subtree for value
                n = n->right;
            }
            else{ // value found, now find successor
                if ( !n->parent && !n->right ){ // if node has no parent and no right subtree, then there is no successor
                    return 0;
                }
                else if ( n->parent && !n->right ){ // else if node has no right subtree, but has a parent
                    if ( n->parent->info > n->info ){ // check if parent is successor
                        return n->parent->info;
                    }
                    else if ( n->parent->info < n->info ){ // check if parent's parent is successor and so on until null
                        n = n->parent;
                        while ( n->parent->parent ){
                            n = n->parent;
                            if ( n->info > value ){ // return first parent whose info is greater than value
                                return n->info;
                            }
                        }
                        if ( n->parent->info > value ){ // n->parent->parent is null so checking root if successor
                            return n->parent->info;
                        }
                        else {// no parent is successor, return 0
                            return 0;
                        }
                    }
                    else { 
                        return 0;
                    }
                }
                else if ( n->right ){ // else right subtree exists, successor is the leftmost element of right subtree
                    n = n->right;
                    while ( n && n->left ){
                        n = n->left;
                    }
                    return n->info;
                }
            }
        }
    }
    return 0; 
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
template<typename T>
bool IntBST<T>::remove(T value){
    if ( !root ){ // root doesn't exist, tree/subtree empty
        return false;
    }
    if ( contains(value) ){ // if value is in tree, find it, remove it
        Node *n;
        n = root;
        while ( n ){
            if ( value < n->info ){ // search left subtree for value
                n = n->left;
            }
            else if ( value > n->info ){ // search right subtree for value
                n = n->right;
            }
            else { // value found, remove it and update BST
            /*
                if ( !n->parent && !n->left && !n->right ){ // no parent, no left subtree, no right subtree, deleting root node, set root to null
                    delete n;
                    root = nullptr;
                }
                /////////
                else if ( !n->parent && !n->left ){ // no parent, no left subtree, right node becomes root
                    root = n->right;
                    n->right->parent = nullptr;
                    delete n;
                }
                else if ( !n->parent && !n->right ){ // no parent, no right subtree, left node becomes root
                    root = n->left;
                    n->left->parent = nullptr;
                    delete n;
                }
                //////////
                else if ( n->parent && !n->left && !n->right ){ // no left or right subtree, update parent's left or right node
                    if ( n->info < n->parent->info ){
                        n->parent->left = nullptr;
                        delete n;
                    }
                    else {
                        n->parent->right = nullptr;
                        delete n;
                    }
                }
                else if ( n->parent && !n->left && n->right){ // no left subtree, replace with right node
                    if ( n->info < n->parent->info ){
                        n->parent->left = n->right;
                        n->right->parent = n->parent;
                        delete n;
                    }
                    else {
                        n->parent->right = n->right;
                        n->right->parent = n->parent;
                        delete n;
                    }
                }
                else if ( n->parent && n->left && !n->right ){ // no right subtree, replace with left node
                    if ( n->info < n->parent->info ){
                        n->parent->left = n->left;
                        n->left->parent = n->parent;
                        delete n;
                    }
                    else {
                        n->parent->right = n->left;
                        n->left->parent = n->parent;
                        delete n;
                    }
                }
                else if ( !n->parent ){ // deleting root node, replace root with successor if it exists
                    if ( n->right ){ 
                        Node *succ = getSuccessorNode(value);
                        n->info = succ->info;
                        if ( n->right == succ ){
                            n->right = succ->right;
                        }
                        else {
                            succ->parent->left = nullptr;
                        }
                        delete succ;
                    }
                    else if ( n->left ){
                        Node *pred = getPredecessorNode(value);
                        n->info = pred->info;
                        if ( n->left == pred ){
                            n->left = pred->left;
                        }
                        else {
                            pred->parent->right = nullptr;
                        }
                        delete pred;
                    }
                }
                else { // parent, left, and right all exist, find successor to replace the node
                    Node *succ = getSuccessorNode(value);
                    n->info = succ->info;
                    if ( n->right == succ ){
                        n->right = succ->right;
                    }
                    else {
                        succ->parent->left = nullptr;
                    }
                    delete succ;
                }
            */
                if ( !n->left && !n->right ){ // no left or right subtrees
                    if ( !n->parent ){ // node to delete is the root
                        root = nullptr;
                    }
                    else if ( n->parent->left == n ){
                        n->parent->left = nullptr;
                    }
                    else {
                        n->parent->right = nullptr;
                    }
                    delete n;
                    return true;
                }   
                else if ( n->left && !n->right ){ // no right subtree
                    if ( !n->parent ){ // node to delete is the root
                        root = n->left;
                    }
                    else if ( n->parent->left == n ){
                        n->parent->left = n->left;
                    }
                    else {
                        n->parent->right = n->left;
                    }
                    delete n;
                    return true;
                }
                else if ( !n->left && n->right ){ // no left subtree
                    if ( !n->parent ){ // node to delete is the root
                        root = n->right;
                    }
                    else if ( n->parent->left == n ){
                        n->parent->left = n->right;
                    }
                    else {
                        n->parent->right = n->right;
                    }
                    delete n;
                    return true;
                }
                else { // left and right subtrees both exist
                    Node *succ = getSuccessorNode(value);
                    n->info = succ->info;
                    n = n->right;
                    value = succ->info;
                }
            }
        }
    }
    // else value is not in tree, return false
    return false;
}
