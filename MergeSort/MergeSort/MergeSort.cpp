#include <iostream>
#include <vector>
using namespace std;
// ---------------------------------------------------------------
// Task 1: Define a MergeSort Class 
// ---------------------------------------------------------------
// Below is a class for merge sort. 
// 
// It has a private vector "list" that holds the list to sort.
// All member functions should operate on "list". 
// 
// It has several public member functions. 
// 1. SetList: assign a vector (to sort) to "list". 
// 2. GetList: return the current "list"
// 3. SortList: sort "list" based on the merge sort algorithm.  
//
// Parts of the SortList function are given to you. 
// You need to complete this function based on the given parts 
// (but feel free to add additional functions as you like).
//  
// A key feature in the given SortList function is to call 
// a recursive function "RecursiveSort", which recursively 
// splits the input list, sorts each split, and merges the splits 
// Note "RecursiveSort" takes input by value and returns a sorted input. 
// 
// Your job is to complete the following functions:
// -- SetList()
// -- GetList()
// -- SortList()
// -- RecursiveSort()
class MergeSort {
public:
    void SetList(vector<int> InputList);
    vector<int> GetList();
    void SortList();
private:
    vector<int> list;
    vector<int> RecursiveSort(vector<int> &x);
};
void MergeSort::SetList(vector<int> InputList)
{
    list = std::move(InputList);
}
vector<int> MergeSort::GetList()
{
    return list;
}
// Below is a template for the MergeSort function.  
// Note it is not recursive. Only "RecursiveSort" is recursive. 
void MergeSort::SortList() {
    // Step 1. Split "list" into list_l and list_r 
    // list_l = left sublist
    // list_r = right sublist 
    // ...... 
    // Step 2. Call RecursiveSort to sort each sublist 
    vector<int> list_l;
    vector<int> list_r;
    list_l = RecursiveSort(list_l);
    list_r = RecursiveSort(list_r);
    list = RecursiveSort(list);
    // Step 3. Merge list_l and list_r back to "list"  
    // list = [list_l, list_r] 
}
vector<int> MergeSort::RecursiveSort(vector<int> &x)
{
    if (x.size() < 2) // assume that one of the methods we call has a left of 0 and a right of 1, we will start it the next time at mid+1 2 > 1 and will cause errors
    {
        return x;
    }

    else
    {
        int mid = (x.size()) / 2;
        vector<int> leftArr;
        vector<int> rightArr;
        copy(x.begin(), x.end() - mid, back_inserter(leftArr)); //should one be inclusive or exlusive
        copy(x.end() - mid, x.end(), back_inserter(rightArr));

        leftArr = RecursiveSort(leftArr);
        rightArr = RecursiveSort(rightArr);

        int l = 0, r = 0;
        vector<int> sorted;

 
        while (l < leftArr.size() && r < rightArr.size()) {
            if (leftArr[l] <= rightArr[r]) {
                sorted.push_back(leftArr[l++]);
            }
            else {
                sorted.push_back(rightArr[r++]);

            }
        }


        while (l < leftArr.size()) {
            sorted.push_back(leftArr[l++]);

        }


        while (r < rightArr.size()) {
            sorted.push_back(rightArr[r++]);
        }

        
        return sorted;
    }
}
;
// ---------------------------------------------------------------
int main()
{
    // The main function is given to you. 
    // We first input an arbitrary number of non-repeated integers into a vector. 
    // The input of this list will terminate when we give an non-integer input 
        // Then, we pass this vector to the MergeSort object. 
        // Then, we run your implemented functions. 
        vector<int> InputList;
    vector<int> TestList;
    int temp, mode;
    MergeSort x;
    // takie inputs
    cin >> mode;
    while (cin >> temp) {
        InputList.push_back(temp);
    }
    x.SetList(InputList);
    // start testing functions 
    switch (mode) {
    case 1: // check if input is correct 
        TestList = x.GetList();
        for (int i = 0; i < TestList.size(); i++) {
            cout << TestList.at(i) << endl;
        }
        break;
    case 2: // check if SortList is correct 
        x.SortList();
        TestList = x.GetList();
        for (int i = 0; i < TestList.size(); i++) {
            cout << TestList.at(i) << endl;
        }
        break;
    }
    return 0;
}
