/*
 * Name: Aleksander Eskilson, aeskilson@ku.edu
 * File: BinarySearchTree.cpp
 * Created: 4/22/13
 * Modified: 5/8/13
 * Description: Implementation for BinarySearchTree template class.
 */

//Generic constuctor, root initially null
template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree(): rootPtr(NULL) {
}

//Copy constructor, utilizes copyTree helper method
template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree(const BinarySearchTree<KeyType, ItemType>& tree) {
    rootPtr = copyTree(tree.rootPtr);
}

//Destructor, utilizes destroyTree helper method
template<typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::~BinarySearchTree() {
    destroyTree(rootPtr);
}

//Public Methods
//Boolean check - return whether or not tree contains any number of nodes
template<typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::isEmpty() const {
    return (rootPtr == NULL);
}

//Return height of the tree - utilizes getHeighterHelper method
template<typename KeyType, typename ItemType>
int BinarySearchTree<KeyType, ItemType>::getHeight() const {
    return getHeightHelper(rootPtr);
}

//Return number of nodes - utilizes getNumberOfNodes helper method
template<typename KeyType, typename ItemType>
int BinarySearchTree<KeyType, ItemType>::getNumberOfNodes() const {
    return getNumberOfNodesHelper(rootPtr);
}

//Insert new node with entry newEntry into BST - utilizes inorderInsertion helper method
template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::add(const ItemType& newEntry) {
    BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newEntry);
    rootPtr = inorderInsertion(rootPtr, newNodePtr);
}

/*
 * Remove node that has associated key aKey from BST, throw exception if node does not 
 * exist - utilizes removeValue helper method
 */
template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::remove(const KeyType& aKey) throw(NotFoundException) {
    bool success = false;
    rootPtr = removeValue(rootPtr, aKey, success); 

    if(success == false)
        throw NotFoundException("key not found");

}

/*
 * Return ItemType associated with KeyType aKey, throw exception if node does not exist - utilizes
 * findNode helper method
 */
template<typename KeyType, typename ItemType>
ItemType BinarySearchTree<KeyType, ItemType>::getEntry(const KeyType& aKey) const throw(NotFoundException) {
    BinaryNode<ItemType>* foundPtr = findNode(rootPtr, aKey);
    if(foundPtr == NULL)
        throw NotFoundException("key not found");
    else
        return foundPtr -> getItem();
}

template<typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::contains(const KeyType& aKey) const {
    if(findNode(rootPtr, aKey) != NULL)
        return true;
    else
        return false;
}

//Traversal Methods - use associated helper methods
template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::preorderTraverse(void visit(ItemType&)) const {
    preorderHelper(visit, rootPtr);
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::inorderTraverse(void visit(ItemType&)) const {
    inorderHelper(visit, rootPtr);
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::postorderTraverse(void visit(ItemType&)) const {
    postorderHelper(visit, rootPtr);
}

//Protected Utility Methods
//Recurse over BST, for each node found, add 1. Return when branches all terminate to base case, node has no children
template<typename KeyType, typename ItemType>
int BinarySearchTree<KeyType, ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const {
    if(subTreePtr == NULL)
        return 0;
    else
        return 1 + getNumberOfNodesHelper(subTreePtr -> getLeftChildPtr()) + getNumberOfNodesHelper(subTreePtr -> getRightChildPtr());
}

/*
 * Recursivly find node associated with KeyType target. Have helper methods handle special removal cases.
 * Return to remove a pointer to the BST without the removed node. Modify success code throughout.
 */
template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr, const KeyType target, bool& success) {
    //Special case, tree is empty, node never found, return false
    if(subTreePtr == NULL) {
        success = false;
        return NULL;
    }
    //Current node contains target
    else if(subTreePtr -> getItem() == target) {
        //Remove node, return tree without node
        subTreePtr = removeNode(subTreePtr);
        success = true;
        return subTreePtr;
    }
    //Current node greater than target, recurse to nodes left child
    else if(subTreePtr -> getItem() > target) {
        BinaryNode<ItemType>* tempPtr = removeValue(subTreePtr -> getLeftChildPtr(), target, success);
        subTreePtr -> setLeftChildPtr(tempPtr);
        return subTreePtr;
    }
    //Current node less than target, recurse to nodes right child
    else {
        BinaryNode<ItemType>* tempPtr = removeValue(subTreePtr -> getRightChildPtr(), target, success);
        subTreePtr -> setRightChildPtr(tempPtr);
        return subTreePtr;
    }
}

/*
 * Handle special cases
 * 1. Node is leaf
 * 2. Node has only one child
 * 3. Node has two children
 */
template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::removeNode(BinaryNode<ItemType>* nodeToDeletePtr) {
    //Node is leaf - delete it, return null to subTreePtr
    if(nodeToDeletePtr -> isLeaf() == true) {
        delete nodeToDeletePtr;
        nodeToDeletePtr = NULL;
        return nodeToDeletePtr;
    }
    //Node has only one child 
    else if((nodeToDeletePtr -> getLeftChildPtr() == NULL && nodeToDeletePtr -> getRightChildPtr() != NULL) || (nodeToDeletePtr -> getRightChildPtr() == NULL && nodeToDeletePtr -> getLeftChildPtr() != NULL)) {
        BinaryNode<ItemType>* nodeToConnectPtr;
        //Get node's child
        if(nodeToDeletePtr -> getLeftChildPtr() != NULL) 
            nodeToConnectPtr = nodeToDeletePtr -> getLeftChildPtr();
        
        else 
            nodeToConnectPtr = nodeToDeletePtr -> getRightChildPtr();
        
        //Delete node
        delete nodeToDeletePtr;
        nodeToDeletePtr = NULL;
        //Return node's child to parent
        return nodeToConnectPtr;
    }
    //Node has two children
    else {
        ItemType inorderSuccessor;
        //Find Inorder Successor node, return its entry to temporary pointer, delete original Inorder Successor node
        BinaryNode<ItemType>* tempPtr = removeLeftmostNode(nodeToDeletePtr -> getRightChildPtr(), inorderSuccessor);
        nodeToDeletePtr -> setRightChildPtr(tempPtr);
        //Change node's Item to Inorder Successor's Item
        nodeToDeletePtr -> setItem(inorderSuccessor);
    }
}

//Find inorder successor node recursively. Copy its ItemType. Remove its node
template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::removeLeftmostNode(BinaryNode<ItemType>* nodeToDeletePtr, ItemType& inorderSuccessor) {
    //Inorder successor found
    if(nodeToDeletePtr -> getLeftChildPtr() == NULL) {
        inorderSuccessor = nodeToDeletePtr -> getItem();
        return removeNode(nodeToDeletePtr);
    }
    //Inorder not found, recurse
    else {
        nodeToDeletePtr -> setLeftChildPtr(removeLeftmostNode(nodeToDeletePtr -> getLeftChildPtr(), inorderSuccessor));
        return nodeToDeletePtr;

    }
}

//Helper for inorder traverse - visit left subTree, root, right subTree recursively
template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::inorderHelper(void visit(ItemType&), BinaryNode<ItemType>* subTreePtr) const {
    if(subTreePtr != NULL) {
        inorderHelper(visit, subTreePtr -> getLeftChildPtr());
        ItemType theItem = subTreePtr -> getItem();
        visit(theItem);
        inorderHelper(visit, subTreePtr -> getRightChildPtr());
    }
}

//Helper for preorder traverse - visit root, left subTree, right subTree recursively
template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::preorderHelper(void visit(ItemType&), BinaryNode<ItemType>* subTreePtr) const {
    if(subTreePtr != NULL) {
        ItemType theItem = subTreePtr -> getItem();
        visit(theItem);
        preorderHelper(visit, subTreePtr -> getLeftChildPtr());
        preorderHelper(visit, subTreePtr -> getRightChildPtr());
    }
}

//Helper for postorder traverse - visit left subTree, right subTree, root recursively
template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::postorderHelper(void visit(ItemType&), BinaryNode<ItemType>* subTreePtr) const {
    if(subTreePtr != NULL) {
        postorderHelper(visit, subTreePtr -> getLeftChildPtr());
        postorderHelper(visit, subTreePtr -> getRightChildPtr());
        ItemType theItem = subTreePtr -> getItem();
        visit(theItem);
    }
}

//Helper method for add - recursively find correct placement
template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::inorderInsertion(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr) {
    //Tree empty or no child for previously compared node (base case)
    if(subTreePtr == NULL) {
        return newNodePtr;
    }
    //New node greater than current node, recurse right
    else if(newNodePtr -> getItem() > subTreePtr -> getItem()) {
        BinaryNode<ItemType>* tempPtr = inorderInsertion(subTreePtr -> getRightChildPtr(), newNodePtr);
        subTreePtr -> setRightChildPtr(tempPtr);
    }
    //New node less than current node, recurse left
    else {
        BinaryNode<ItemType>* tempPtr = inorderInsertion(subTreePtr -> getLeftChildPtr(), newNodePtr);
        subTreePtr -> setLeftChildPtr(tempPtr);
    }

    return subTreePtr;
}

//Recurse over each branch of tree, add 1 at each found node
template<typename KeyType, typename ItemType>
int BinarySearchTree<KeyType, ItemType>::getHeightHelper(BinaryNode<ItemType>* subTreePtr) const {
    //Base case, nodes children are null
    if(subTreePtr == NULL)
        return 0;
    else
        return 1 + max(getHeightHelper(subTreePtr -> getLeftChildPtr()), getHeightHelper(subTreePtr -> getRightChildPtr()));
}

//Recurse over each branch, delete nodes
template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::destroyTree(BinaryNode<ItemType>* subTreePtr) {
    if(subTreePtr != NULL) {
        destroyTree(subTreePtr -> getLeftChildPtr());
        destroyTree(subTreePtr -> getRightChildPtr());
        delete subTreePtr;
    }
}

//Recursively find node with KeyType target by performing comparisons
template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::findNode(BinaryNode<ItemType>* subTreePtr, const KeyType& target) const {
    //Tree is empty, return null
    if(subTreePtr == NULL)
       return NULL; 
    //Found node
    else if(subTreePtr -> getItem() == target)
        return subTreePtr;
    //Current node greater than target, recurse left
    else if(subTreePtr -> getItem() > target)
        return findNode(subTreePtr -> getLeftChildPtr(), target);
    //Current node less than target, recurse right
    else
        return findNode(subTreePtr -> getRightChildPtr(), target);
}

//Recursively copy each node of the tree
template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::copyTree(const BinaryNode<ItemType>* treePtr) const {
    BinaryNode<ItemType>* newTreePtr = NULL;

    if(treePtr != NULL) {
        //Create new tree node
        newTreePtr = new BinaryNode<ItemType>(treePtr -> getItem(), NULL, NULL);
        //Copy old tree's left and right children
        newTreePtr -> setLeftChildPtr(copyTree(treePtr -> getLeftChildPtr()));
        newTreePtr -> setRightChildPtr(copyTree(treePtr -> getRightChildPtr()));
    }

    return newTreePtr;
}
