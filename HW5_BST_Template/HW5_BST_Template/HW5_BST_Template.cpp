// In this assignment, we implement a binary search tree.
// The node class and its member functions have been defined for you. 
// The tree class has been defined for you, too. 
// Your task is to complete the member functions of the tree class. 
// You can also add other member functions to the tree class. 
// 
// After implementation, please also try to design your own 
// testing cases to test the program. The examples given in the 
// instruction document only aim to provide a concrete idea on 
// how the outputs should look like, and may not be sufficient 
// to reveal all possible (logical) flaws in the program. 
// 
// There are generally two steps to design testing cases. 
// 
// Step 1 is to identify possible scenarios. 
// For example, after implementing a remove function, you may 
// want to test (1) remove a leaf node, (2) remove the root node, 
// (3) remove a node not in the tree, (4) remove a node 
// in the left subtree, (5) remove a node in the right subtree. 
// You may also want to test the scenario when we continously 
// remove a set of nodes. 
// 
// Step 2 is to design input and expected output for each scenario. 
// For example, to test removing a root node, you may want to first 
// draw the input tree, manually perform removal based on your design 
// (assume it is correctly implemented) and manually figure out what 
// the resulted tree should look like. Then, run your program and see 
// if it gives the same result. 
// Not that even if your program has no problem being complied, it may 
// give a different result which implies logical flaws in the design. 
// 
#include <iostream>
#include <vector>
using namespace std;
class Node {
private:
    Node* parent;
    Node* left;
    Node* right;
    int height;
    int SID;
public:
    Node();
    void SetParent(Node* ptr);
    void SetLeft(Node* ptr);
    void SetRight(Node* ptr);
    void SetSID(int data);
    Node* GetParent();
    Node* GetLeft();
    Node* GetRight();
    int GetSID();
   // int GetHeight(Node* ptr); //what should be here
};
Node::Node() {
    parent = NULL;
    left = NULL;
    right = NULL;
    SID = -1;
};
void Node::SetParent(Node* ptr) {
    parent = ptr;
};
void Node::SetLeft(Node* ptr) {
    left = ptr;
};
void Node::SetRight(Node* ptr) {
    right = ptr;
};
void Node::SetSID(int data) {
    SID = data;
};
Node* Node::GetParent() {
    return parent;
};
Node* Node::GetLeft() {
    return left;
};
Node* Node::GetRight() {
    return right;
};
int Node::GetSID() {
    return SID;
};
// 
// Below is the binary search tree class. 
// The tree should contain both NIL nodes (SID==-1) 
// and non-NIL nodes (SID > 0). 
// 
// Currently, the class has ten public member functions. 
// Four are implemented for you. Please implement the rest. 
// 
// To facilitate implementation, you can add member functions.
// For example, you probably want to add a Search function. 
// Tip1: you may want to test the added functions before using 
// them to implement the target functions. 
// Tip2: properly design the input and output of additional 
// functions so it can be efficiently used by target functions. 
//  
// 
// All member functions are explained below. 
// 
// 1. BinarySearchTree
// This function initializes the tree. 
// It is defined for you. 
// 
// 2. SetRoot
// This function set the root pointer.
// It is defined for you. 
// 
// 3. GetRoot
// This function returns the root pointer.
// It is defined for you. 
// 
// 4. PreTraverse
// This function performs pre-order traverse of the tree. 
// It is defined for you.
// It will be used to examine other functions. 
// 
// 5. Size()
// This function returns the number of non-NIL nodes in the tree. 
// Please complete it. 
// 
// 6. Add(Node *ptr)
// This function adds a node at address "ptr" to the tree. 
// Please complete it. 
// There are reference in the lecture slides. 
// 
// 7. FindMax(Node *ptr)
// This function returns the address of the maximum node 
// (i.e., node with the larget SID) in the tree rooted at ptr. 
// Please complete it. 
// 
// 8. FindMin(Node *ptr)
// This function returns the address of the minimum node 
// (i.e., node with the smallest SID) in the tree rooted at ptr. 
// Please complete it. 
// 
// 9. Remove1(int key)
// This function removes the node whose SID==key from the tree. 
// If this node is not in the tree, do nothing. 
// This function implements Algorithm 1 (recursively fill holes) 
// in the lecture slides. 
// ** When filling a hole, please always try to find the max node 
// in the left sub-tree first; if the left sub-tree does not exist, 
// then find the min node in the right sub-tree. **
// ** Same requirement for Remove2 when the hole has two child nodes. **
// 
// 10. Remove2(int key)
// This function removes the node whose SID==key from the tree. 
// If this node is not in the tree, do nothing. 
// This function implements Algorithm 2 (replace single-child node 
// with its only sub-tree) in the lecture slides. 
//
// 
class BinarySearchTree {
private:
    Node* root;
public:
    BinarySearchTree();
    void SetRoot(Node* ptr);
    Node* GetRoot();
    void PreTraverse(Node* ptr);
    int sizeHelper(Node* ptr);
    int Size();
    void Add(Node* ptr);
    Node* FindMax(Node* ptr);
    Node* FindMin(Node* ptr);
    Node* Search(Node* root, int key);
    void Remove1(int key);
    void Remove2(int key);
};
BinarySearchTree::BinarySearchTree() {
    root = NULL;
};
void BinarySearchTree::SetRoot(Node* ptr) {
    root = ptr;
};
Node* BinarySearchTree::GetRoot() {
    return root;
};
void BinarySearchTree::PreTraverse(Node* ptr) {
    if (ptr->GetSID() == -1) {
        return;
    }
    else {
        cout << ptr->GetSID() << endl;
        PreTraverse(ptr->GetLeft());
        PreTraverse(ptr->GetRight());
    }
}
Node* BinarySearchTree::Search(Node* root, int key)
{

    // if its negative one return the root;
    if (root->GetSID() == -1 || key == root->GetSID())
    {
        return root;
    }
    else if (key > root->GetSID())
    {
        Search(root->GetRight(), key);
    }
    else if (key < root->GetSID())
    {
        Search(root->GetLeft(), key);
    }
}
;
void BinarySearchTree::Add(Node* ptr)
{
    if (root == NULL) // no root
    {
        root = new Node;
        root = ptr;
        SetRoot(root);
        root->SetLeft(new Node);
        root->SetRight(new Node);
        root->GetLeft()->SetParent(ptr);
        root->GetRight()->SetParent(ptr);
        return;

    }

    Node* temp = Search(root, ptr->GetSID());
    if (temp->GetSID() != -1) // already in the tree
    {
        return;
    }
    temp = temp->GetParent();

    if (ptr->GetSID() > temp->GetSID())
    {

        temp->SetRight(ptr);
        ptr->SetParent(temp); // setting links back and forth
    }
    else
    {
        temp->SetLeft(ptr);
        ptr->SetParent(temp);
    }
    ptr->SetLeft(new Node);
    ptr->SetRight(new Node);
    ptr->GetLeft()->SetParent(ptr);
    ptr->GetRight()->SetParent(ptr);
}
;
Node* BinarySearchTree::FindMax(Node* ptr) // using recursion
{
    Node* returning = new Node(); //might need to do a new node
    returning = ptr;

    while (returning->GetRight()->GetSID() != -1) // difference between a while and recursion
    {
        returning = returning->GetRight();
    }

    return returning;
}
Node* BinarySearchTree::FindMin(Node* ptr)
{
    Node* returning = new Node(); //might need to do a new node
    returning = ptr;

    while (returning->GetLeft()->GetSID() != -1) // difference between a while and recursion
    {
        returning = returning->GetLeft();
    }

    return returning;
}
;

int BinarySearchTree::Size()
{
    Node* temp = new Node();
    temp = GetRoot();

    // take care of null case later
    // if not call on root itself



    int returning = 0;
    returning += sizeHelper(temp);
    return returning;
}
;
int BinarySearchTree::sizeHelper(Node* ptr)
{
    int Returning = 0; // its a huge takeaway that returning is different variable each call
    if (ptr->GetSID() == -1)
    {
        return Returning; // or returning
    }
    else
    {
        ++Returning;
        Returning += sizeHelper(ptr->GetLeft());
        Returning += sizeHelper(ptr->GetRight());
    }

    return Returning;
}
;

void BinarySearchTree::Remove1(int key) // ignoring exception cases
{
    Node* OG = new Node();
    OG = Search(GetRoot(), key);
    Node* max = new Node();
    max = FindMax(OG->GetLeft());

    while (max->GetLeft()->GetSID() != -1)
    {
        OG->SetSID(max->GetSID());
        OG = max; // not sure
        max = FindMax(OG->GetLeft());
    }

    OG->SetSID(max->GetSID());
    max->SetSID(-1);


}
void BinarySearchTree::Remove2(int key) // got help from tanner with this method
{
    Node* temp = Search(GetRoot(), key);

    if (temp->GetSID() == -1)
    {
        return;

    }

    if (temp->GetLeft()->GetSID() == -1 && temp->GetRight()->GetSID() == -1)
    {
        temp->SetLeft(nullptr);
        temp->SetRight(nullptr);
        temp->SetSID(-1);
        return;
    }
    else if (temp->GetLeft()->GetSID() != -1 && temp->GetRight()->GetSID() != -1)
    {
        Node* Successor = FindMin(temp->GetRight());
        int sucVal = Successor->GetSID();
        Remove2(Successor->GetSID());
        temp->SetSID(sucVal);
    }

    else
    {
        Node* Child = (temp->GetLeft() ? temp->GetLeft() : temp->GetRight());

        if (temp == temp->GetParent()->GetLeft())
        {
            temp->GetParent()->SetLeft(Child);
        }
        else
        {
            temp->GetParent()->SetRight(Child);
        }
    }
}
;
int main()
{
    int mode, key;
    cin >> mode >> key;
    BinarySearchTree x;
    int temp_SID;
    Node* temp_node;
    // now we construct the tree using "Add"
    while (cin >> temp_SID) {
        temp_node = new Node;
        temp_node->SetSID(temp_SID);
        x.Add(temp_node);
    }
    switch (mode) {
    case 1: // check the "Size" function 
        cout << x.Size();
        break;
    case 2: // check the "Add" function 
        x.PreTraverse(x.GetRoot());
        break;
    case 3: // check the "FindMax" function, assuming tree is not empty  
        cout << x.FindMax(x.GetRoot())->GetSID();
        break;
    case 4: // check the "FindMin" function, assuming tree is not empty
        cout << x.FindMin(x.GetRoot())->GetSID();
        break;
    case 5: // check the "Remove1" function 
        x.Remove1(key);
        x.PreTraverse(x.GetRoot());
        break;
    case 6: // check the "Remove2" function 
      x.Remove2(key);
      x.PreTraverse(x.GetRoot());
        break;
    }
    return 0;
}
