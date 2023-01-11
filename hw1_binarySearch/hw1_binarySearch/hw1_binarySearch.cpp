#include <iostream>
using namespace std;
class Student {
public:
    void SetSID(int a);
    int GetSID();
    void binaryHelper(int low, int high, int mid, int key, Student* ptr, int var[]);
private:
    int SID;
};
// -------------------------------------------
// Please define the function of SetID() here;
// It should assign an input integer a to SID 
// ...........................................
// -------------------------------------------
void Student::SetSID(int a) {
    SID = a;
};
// -------------------------------------------
// Please define the function of GetID() here;
// It should return the value of SID
// ...........................................
// -------------------------------------------
int Student::GetSID() {
    return SID;
}
void Student::binaryHelper(int low, int high, int mid, int key, Student* ptr, int var[]) // var should be one
{
    mid = (high + low) / 2;
    var[1]++;
    
    if (ptr[mid].GetSID() == key)
    {
        var[0] = mid;
    }
    else if (ptr[mid].GetSID() > key)
    {
        binaryHelper(low, mid - 1, mid, key, ptr, var);
    }
    else if (ptr[mid].GetSID() < key)
    {
        binaryHelper(mid + 1, high, mid, key, ptr, var);
    }
 
}
int* BinarySearch(Student* ptr, int arr_size, int key) {
    // --------------------------------------------------------------------
    // Please implement binary search here
    // Input: an array of student objects, the array size and a search key
    // Output: an array of two integers (declared for you below)
    //         The 1st element is the search result: index of 
    //         the key in the array if it is found or -1 
    //         The 2nd element is the number of search iterations 
    //         it takes for your algorithm to return the result   
    // --------------------------------------------------------------------
    int high = arr_size - 1;
    int placeHolder = 0;

    static int val[2]; // to prevent the content of array from being lost 
    // ... 

    val[0] = -1;
    val[1] = 0; // might be one
    Student Nick;
        Nick.binaryHelper(0, high, placeHolder, key, ptr, val);
    return val;
}
int CheckOrder(Student* ptr, int arr_size) {
    // ----------------------------------------------------
    // Please implement a function that checks whether 
    // the SID of students are sorted in ascending order.
    // Return 1 if sorted, and return 0 if not. 
    //  
    // For example, suppose we have three students objects 
    // in the input array, and the SID's of ptr[0], ptr[1], 
    // ptr[3] are 1, 3, 5, then it is sorted. Return 1. 
    // 
    // If the SID's of ptr[0], ptr[1], ptr[3] are 3, 1, 5, 
    // then it is not sorted. Return 0. 
    // ----------------------------------------------------
    int isSorted = 1;
    for (int i = 0; i < arr_size-1; ++i)
    {
        if (ptr[i].GetSID() > ptr[i + 1].GetSID())
        {
            isSorted = 0;
        }
    }
    
    return isSorted;

}
int main()
{
    // The main function is given to you. 
    // It first declares an array of seven student objects.  
    // It then takes a key and seven SID's as input and 
    // assigns the ID's to the seven students. 
    // 
    // Then, it checks if the input SID's are sorted in 
    // ascending order. 
    // If so, it will perform binary search.  
    Student x[7];
    int temp, key, mode, * value;
    cin >> mode >> key;
    for (int i = 0; i < 7; i++) {

        cin >> temp;
        x[i].SetSID(temp);
    }
    switch (mode) {

    case 1: // check correction of the CheckOrder function

        cout << CheckOrder(x, 7) << endl;
        break;
    case 2: // check correction of the returned index of the search 
        if (CheckOrder(x, 7)) {
            value = BinarySearch(x, 7, key);
            cout << value[0] << endl;
        }
        else {
            cout << -2 << endl;
        }
        break;
    case 3: // check correction of the number of search iterations 
        if (CheckOrder(x, 7)) {
            value = BinarySearch(x, 7, key);
            cout << value[1] << endl;
        }
        else {
            cout << -2 << endl;
        }
        break;
    }
    return 0;
}