// This is the template for HW3. 
// We will implement a singly linked list (SLL) class and sort it. 
// The node class is defined for you. 
// The singly linked list (SLL) class is partly defined. 
// Do not change the existing definitions. 
// 
// You have two major tasks: 
// 1. Complete five member functions of the SLL class. 
// 2. Complete merge sort based on the SLL data structure. 
// Detailed instructions are given below. 
// 
// Tip: to facilitate debugging, you may first implement a simple 
// add function (e.g., only add to head). This allows you to quickly 
// construct a list and test/debug other functions.
//
// 
#include <iostream>
using namespace std;

//NOTE -> is used because it is a pointer
// -----------------------
// -----------------------
// Node Class Definition 
// -----------------------
// -----------------------

// Question- can we add public members?
class Node {
private:
    int data;
    Node* link_next;
public:
    void SetData(int x);
    int GetData();
    void SetLink_Next(Node* ptr);
    Node* GetLink_Next();
    Node();
};
Node::Node() {
    data = 0;
    link_next = NULL;
}
void Node::SetData(int x) {
    data = x;
}
int Node::GetData() {
    return data;
}
void Node::SetLink_Next(Node* ptr) {
    link_next = ptr;
}
Node* Node::GetLink_Next() {
    return link_next;
}
// -------------------------------------
// -------------------------------------
// Singly Linked List Class Definition 
// -------------------------------------
// -------------------------------------
// The following is a partly defined singly linked class.  
// Its only private member is a head pointer -- you cannot add others. 
// It has multiple public member functions. 
// Four member functions are given to you. 
// Your job is to complete the following five member functions: 
// 
// *************
// 1. GetSize()
// *************
// This function returns the number of nodes in the list. 
// Below is an example. 
// 
// Example: 
// If list = 5, 7, 1, 3, 
// then GetSize() returns 4. 
//  
// 
// *************************
// 2. LinearSearch(int key)
// *************************
// This function performs linear search on the list with the given key.
// If key is not found or the list is empty, return -1. 
// If key is found, return location of the node holding that key. 
// Location will start from 0 and ends at n-1. 
// Below is an example. 
// 
// Example: 
// If list = 5, 7, 1, 3, then  
// LinearSearch(5) returns 0. 
// LinearSearch(1) returns 2. 
// LinearSearch(10) returns -1. 
// 
// 
// *************************
// 3. Add(int val, int idx)
// *************************
// This function adds a node with data "val" at location "idx". 
// Here, "idx" starts from 0 (head node) and ends at n-1 (tail node). 
// If the input "idx" is bigger than n-1, then add node to the tail. 
// Below are three examples. 
// 
// Example 1: 
// If list = 5, 7, 1, 2. 
// If we run Add(3,2), 
// then new list = 5, 7, 3, 1, 2. 
// 
// Example 2: 
// If list = 5, 7, 1, 2. 
// If we run Add(3,0), 
// then new list = 3, 5, 7, 1, 2. 
// 
// Example 3:  
// If list = 5, 7, 1, 2. 
// If we run Add(3,7) 
// then new list = 5, 7, 1, 2, 3. 
// (Here, "7" is bigger than n-1, so add "3" to the tail.)  
// 
// 
// *******************
// 4. Remove(int idx)
// *******************
// This function removes the node at location "idx". 
// Here, "idx" starts from 0 (head node) and ends at n-1 (tail node). 
// If the input "idx" is bigger than n-1, then remove the tail. 
// Below are three examples. 
// 
// Example 1: 
// If list = 5, 7, 1, 2. 
// If we run Remove(0), 
// then new list = 7, 1, 2. 
// 
// Example 2: 
// If list = 5, 7, 1, 2. 
// If we run Remove(2), 
// then new list = 5, 7, 2. 
// 
// Example 3: 
// If list = 5, 7, 1, 2. 
// If we run Remove(7), 
// then new list = 5, 7, 1. 
// (Here, "7" is bigger than n-1, so remove the tail. ) 
//
//
// *************
// 5. Reverse()
// *************
// This function reverses the current list. 
// If the list is empty or contains only one node, do nothing. 
// Below are three examples. 
// 
// Example 1: 
// If list is empty. 
// If we run Reverse(), 
// then new list is empty. 
// 
// Example 2: 
// If list = 5. 
// If we run Reverse(), 
// then new list = 5. 
// 
// Example 3: 
// If list = 5, 7, 1, 2. 
// If we run Reverse(), 
// then new list = 2, 1, 7, 5. 
//
// 
class SList {
private:
    Node* head;
public:
    // The following four functions are given to you. 
    // The SetHead and GetHead functions are only useful for merge sort.
    SList();
    void Print();
    void SetHead(Node* ptr);
    Node* GetHead();
    // You need to complete the following five functions.     
    int GetSize();
    int LinearSearch(int key);
    void Add(int val, int idx);
    void Remove(int idx);
    void Reverse();
};

SList::SList() {
    head = NULL;
}
void SList::Print() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->GetData() << endl;
        temp = temp->GetLink_Next();
    }
}
Node* SList::GetHead() {
    return head;
}
void SList::SetHead(Node* ptr) {
    head = ptr;
}

int SList::GetSize()
{
    int returning =0;
    Node* temp = head;
    while (temp != NULL) // why can I not use a dot?
    {
        ++returning;
        temp = temp->GetLink_Next();
    }
    return returning;
}
int SList::LinearSearch(int key)
{
    bool found = false;
    int index = 0;
    Node* temp;
    temp = head;
    while (temp != NULL) // why can I not use a dot?
    {
        if (temp->GetData() == key)
        {
            found = true;
            break; //not sure if this exits entire loop
        }
        temp = temp->GetLink_Next();
        index++;
    }
    if (!found)
    {
        index = -1;
    }

    return index;

}
void SList::Add(int val, int idx)
{
    
    Node* inserting = new Node();
    inserting->SetData(val); // is it because objects
    int count = 0;
    int size = GetSize(); // for some reason get size was not working

    if (idx == 0)
    {
        inserting->SetLink_Next(head);
        head = inserting; // note need to update head
        return;
    }



   if (idx > size - 1)
    {
        while (head != NULL)
        {
            head = head->GetLink_Next();
        }
        head->SetLink_Next(inserting);
        return;
    }


   while (head != NULL)
    {
        if (count == (idx - 1))
        {
            inserting->SetLink_Next(head->GetLink_Next()); // getlinkNext is the issue
            head->SetLink_Next(inserting);
            break;
        }
        head = head->GetLink_Next();
        count++;
    }
    
}
void SList::Remove(int idx)
{
    Node* temp = this->head;
    int size = GetSize();


    if (idx == 0)
    {
        Node* helper = temp->GetLink_Next();
        temp->SetLink_Next(NULL);
        SetHead(helper);
        return;
    }


    if (idx > size - 1)
    {
        int count = 0;
        while (count < (size -2))
        {
            temp = temp->GetLink_Next();
            count++;
        }
        temp->SetLink_Next(NULL);
        return;
    }

    int count = 0;
    while (temp != NULL)
    {
        
        if (count == (idx - 1)) // note temp so you dont mess up the list (how come my temp changes the actual list)
        {
            Node* temp2 = temp->GetLink_Next();
            Node* temp3 = temp2->GetLink_Next();
            temp->SetLink_Next(temp3);
            temp2->SetLink_Next(NULL);
        }
        temp = temp->GetLink_Next();
     
        count++;
    }

}
void SList::Reverse()
{
    Node* current = head;
    Node* prev = NULL, * next = NULL;

    while (current != NULL) {
        next = current->GetLink_Next();
        current->SetLink_Next(prev);
        prev = current;
        current = next;
    }
    head = prev; // this is why i dont have to set the list after I am done

}

//
// -----------
// Merge Sort  
// -----------
// The following is an incomplete merge sort function. 
// Its input is the head pointer of a singly linked list. 
// Its output is the head pointer of the sorted list. 
// We will test this function in the following way: 
// First, use your SList class to generate a singly linked list. 
// Then, retrive its head pointer and pass it to the merge sort function.
// Finally, get a new head pointer of the sorted list, pass it back to the list class and print it.
// You can see the testing code in the main function (mode = 7)
// .........
// Your task is to design and implement this merge sort function 
// based on the singly linked list data structure. 
// No array or vector can be used. 
// Tip: it should be recursive. 
// 

Node* findMid(Node* head)
{
 
    SList Helper = SList();
    Helper.SetHead(head);

    Node* Returning = new Node();
    int count = 0;
    int size = Helper.GetSize() -1;
    Node* temp = head;
    int mid = size / 2;

    while (temp != NULL)
    {
        if (count == mid)
        {
            Returning = temp;
            break;
        }
        temp = temp->GetLink_Next();
        count++;
    }

    return Returning;
}

Node* Merge(Node* Left, Node* Right)
{
    Node* returning = new Node(); // do i need to initalize
    Node* temp = returning;


    if (Left == NULL)
    {
        return Right;
    }

    if (Right == NULL)
    {
        return Left;
    }

   
    while (Left != NULL && Right != NULL)
    {
        if (Left->GetData() < Right->GetData())
        {
            temp->SetLink_Next(Left);
            temp = Left;
            Left = Left->GetLink_Next();
        }
        else
        {
            temp->SetLink_Next(Right);
            temp = Right;
            Right = Right->GetLink_Next();
        }
    }


    while (Left != NULL)
    {
        temp->SetLink_Next(Left);
        temp = Left;
        Left = Left->GetLink_Next();
    }

    while(Right != NULL)
    {
        temp->SetLink_Next(Right);
        temp = Right;
        Right = Right->GetLink_Next();
    }

    return returning->GetLink_Next();
}

Node* MergeSort(Node* ptr) { // not sure that this is correct first statements || turttle and hare alg
    if (ptr == NULL || ptr->GetLink_Next() == NULL)
    {
        return ptr;
    }

    Node* mid = findMid(ptr);

    Node* left = ptr;
    Node* right = mid->GetLink_Next();
    mid->SetLink_Next(NULL);

    left = MergeSort(left);
    right = MergeSort(right);

    Node* returning = Merge(left, right);

    return returning;
   
   
}
int main()
{
    // 
    // The main function is given to you. 
    // It first constructs a singly linked list. 
    // It then tests your implemented member functions 
    // and the merge sort function. 
    // 
    SList x;
    int mode, value, idx, key, temp;
    cin >> mode >> value >> idx >> key;
    for (int i = 0; i < 4; i++) {
        cin >> temp;
        x.Add(temp, 0);
    }
    switch (mode) {
    case 1: // check your add function with idx = 0
        x.Print();
        break;
    case 2: // check your GetSize function
        cout << x.GetSize();
        break;
    case 3: // check your LinearSearch function
        cout << x.LinearSearch(key);
        break;
    case 4: // check your add function with arbirary idx 
        x.Add(value, idx);
        x.Print();
        break;
    case 5: // check your remove function
        x.Remove(idx);
        x.Print();
        break;
    case 6: // check your reverse function 
        x.Reverse();
        x.Print();
        break;
    case 7: // check your merge sort function
        x.SetHead(MergeSort(x.GetHead()));
        x.Print();
        break;
    }
    return 0;
}