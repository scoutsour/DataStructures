//
// In HW4, we implement a hash table class that 
// addresses collision using separate chaining. 
// 
// We will use the modular hash function, whose 
// base equals to the hash table size (input as `size').
// 
// The table will store student nodes. 
// The student class is defined for you. Do not change it (unless there are typos to fix).
// The table class is partly defined. Do not change the private members.  
// 
// Your task is to complete five public member functions, including 
// 1. Add_Head()
// 2. Add_Order()
// 3. Remove()
// 4. Search()
// 5. Print()
// 
// Detailed instructions are given below. 
// 

//HELPFULL 
#include <iostream>
#include <vector>
using namespace std;
enum major { CS, CE, NA };
class Student {
public:
    int SID;
    major MAJ;
    Student* next;
    Student();
};
Student::Student() {
    SID = -1;
    MAJ = NA;
    next = NULL;
};
class HashTable {
private:
    Student** table;
    int size;
public:
    HashTable(int table_size);
    void Add_Head(Student x);
    void Add_Order(Student x);
    void Remove(int key);
    major Search(int key);
    void Print();
    int Hash(int key);
};
HashTable::HashTable(int table_size) {
    size = table_size;
    table = new Student * [size];
    for (int i = 0; i < size; i++) {
        table[i] = NULL;
    }
}

int HashTable::Hash(int key) {
    return key % size;
};
// ---------------------
// Add_Head(Student x)
// ---------------------
// This function add a new student x to the head of the list at table[x.SID]. 
// For example, suppose the hash function is key%3 
// and if the current hash table is 
// table[0] -> 3 -> 9 
// table[1] -> 1 -> 4
// table[2] -> 2 -> 5
// if we add a new student with SID=6, the new table should be 
// table[0] -> 6 -> 3 -> 9 
// table[1] -> 1 -> 4
// table[2] -> 2 -> 5
void HashTable::Add_Head(Student x)
{
  // Student* temp = new Student(x); // telling a pointer to point to x WHY COPY
   Student* temp = &x;

   int keyAfterHash = Hash(x.SID); // here to help find the current head 
    
   Student* currentHead = table[keyAfterHash];   // assigning a currHead to link the new one to

   temp->next = currentHead; // adding x to head

   table[keyAfterHash] = temp; // putting my new head back in the matrix



}


major HashTable::Search(int key)
{
    major result = NA;
    Student* temp;


    int use = key % size;

    temp = table[use];
    while (temp != NULL)
    {
        if (key == temp->SID)
        {
            result = temp->MAJ;
            break;
        }
        temp = temp->next;
    }

    return result;


}
// ---------------------
// Add_Order(Student x)
// ---------------------
// This function add a new student x to the list at table[x.SID] 
// such that the list remains sorted in an ascending order.  
// For example, suppose the hash function is key%3 
// and if the current hash table is 
// table[0] -> 3 -> 9 
// table[1] -> 1 -> 4
// table[2] -> 2 -> 5
// if we add a new student with SID=6, the new table should be 
// table[0] -> 3 -> 6 -> 9
// table[1] -> 1 -> 3
// table[2] -> 2 -> 5
void HashTable::Add_Order(Student x) // pointers do have access to the object that they are pointing at
{
   
    Student* X = new Student(x);  // how does this copy constructor work || but I a

    // Note that -> for pointer and . for accessing members

    int key = Hash(x.SID);
    int indexOfInserting = 0;

    Student* temp = table[key];

  
    if (temp == NULL) // case nothing is there
    {
        table[key] = X;
        return;
    }


    if (X->SID < temp->SID) // case one element is there
    {
        X->next = temp;
        table[key] = X;
        return;
    }

    
    while (temp != NULL)
    {
        if (X->SID < temp->SID)
        {
            break;
        }
        indexOfInserting++;
        temp = temp->next;
    }

    // put it back to start
    temp = table[key];

    //otherwise i am gonna use the insert at a given index
    // X is what I am inserting and temp is my head
    int count = 0;

    while (temp != NULL)
    {
        if (count == (indexOfInserting - 1))
        {
            X->next = temp->next;
            temp->next = X;
            break;
        }
        temp = temp->next;
        count++;
    }


}
// ......
// ......
// ......
// ---------------------
// Remove(int key)
// ---------------------
// This function removes a student x from the table if x.SID == key.
// If the student is not in the table, do nothing. 
// For example, if the current hash table is 
// table[0] -> 6 -> 3 
// table[1] -> 4 -> 1
// table[2] -> 5 -> 2
// if we run Remove(4), the new table will be 
// table[0] -> 6 -> 3 
// table[1] -> 1
// table[2] -> 5 -> 2
// if we further run Remove(7), the new table will remain the same, i.e.,  
// table[0] -> 6 -> 3 
// table[1] -> 1
// table[2] -> 5 -> 2
void HashTable::Remove(int key) // assuming elements are not repeating
{
    int newKey = Hash(key);
    bool found = false;

    Student* temp = table[newKey];

    while (temp != NULL)
    {
        if (temp->SID == key)
        {
            found = true;
        }
        temp = temp->next;
    }
    temp = table[newKey]; // reinitialized to start the loop again

    if (found == true)
    {
        if (temp->SID == key)
        {
            table[newKey] = temp->next;
        }
        else
        {
            while (temp != NULL)
            {
                if (temp->next->SID == key)
                {
                    temp->next = temp->next->next; // just skips over
                    break;
                }
                temp = temp->next;
            }
        }
    }
  




}
;
// ......
// ......
// ---------------------
// Search(int key)
// ---------------------
// This function returns the major of student x in the table if x.SID == key. 
// If the student is not in the table, return NA. 
// For example, if the current hash table is 
// table[0] -> 6 -> 3 
// table[1] -> 4 -> 1
// table[2] -> 5 -> 2
// if we run Search(4), student 4's major should be returned. 
// if we run Search(7), 'NA' should be returned. 
// ......
// ......
// ......
// ---------------------
// Print()
// ---------------------
// This function prints all SIDs in the table row by row and head-to-tail per row. 
// For example, if the current hash table is 
// table[0] -> 6 -> 3 
// table[1] -> 4 -> 1
// table[2] -> 5 -> 2
// if we run Print(), we should see "6 3 4 1 5 2" (vertically)  
// For Gradescope to grade correctly, please strictly follow the given output format.
void HashTable::Print() {
    Student* temp; // used to store the node we want to print 
    // now implement your print function 
    // ......
    // ......
    // ......
    // whenever you get a node to print, assign its address to temp 
    // and print its SID using "cout << temp->SID << endl;"
    // do not add any other cout otherwise gradescope will fail to grade it  correctly

    for (int i = 0; i < size; ++i)
    {
        temp = table[i];
        while (temp != NULL)
        {
            cout << temp->SID << endl;
            temp = temp->next;
        }
    }
};
int main()
{
    int mode, size, key, sid, maj;
    vector<Student> input;
    Student temp;
    // Input test mode, table size, search key. 
    cin >> mode >> size >> key;
    // Store input nodes in a vector for now.
    // However, we should not vectors to stored 
    // collided students in the hash table. 
    // We should use linked list instead. 
    while (cin >> sid >> maj) {
        temp.SID = sid;
        temp.MAJ = static_cast<major>(maj);
        input.push_back(temp);
    };
    // Now construct and test the hash table.
    HashTable x(size);
    switch (mode) {
    case 1: // check the Add_Head and Print functions
        for (int i = 0; i < input.size(); i++) {
            x.Add_Head(input.at(i));
        }
        x.Print();
        break;
    case 2: // check the Add_Order function 
        for (int i = 0; i < input.size(); i++) {
            x.Add_Order(input.at(i));
        }
        x.Print();
        break;
    case 3: // check the Search function (based on Add_Order)
        for (int i = 0; i < input.size(); i++) {
            x.Add_Order(input.at(i));
        }
        switch (x.Search(key)) {
        case 0:
            cout << "CS" << endl;
            break;
        case 1:
            cout << "CE" << endl;
            break;
        case 2:
            cout << "NA" << endl;
            break;
        }
        break;// not sure if this is the broken break 
    case 4: // check the Remove function (based on Add_Order)
        for (int i = 0; i < input.size(); i++) {
            x.Add_Order(input.at(i));
        }
        x.Remove(key);
        x.Print();
        break;
    }
    return 0;
    
}