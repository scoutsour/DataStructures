#include <iostream>
#include <vector>
using namespace std;
// ---------------------------------------------------------------
// Task 1: Define a BasicSort Class 
// ---------------------------------------------------------------
// Below is a class for basic sorting algorithms. 
// 
// It has a private vector "list" that holds the list to sort.
// All member functions should operate on "list". 
// 
// It has several public member functions. 
// 1. SetList: assign a vector (to sort) to "list". 
// 2. GetList: return the current "list"
// 3. BubbleSort: sort "list" using bubble sort 
// 4. SelectionSort: sort "list" using selection sort 
// 
// An important feautre of both sorting algorithms is 
// the input argument "NumRound". If NumRound=-1, then 
// we should run the sorting algorithm until the list 
// is fully sorted. If NumRound = x, then we should stop 
// when either the list is partially sorted for x rounds 
// or when the list becomes fully sorted before x rounds. 
//
// Example 1: list={7,5,3,2}
// BubbleSort(1), list={2,7,5,3}
// BubbleSort(2), list={2,3,7,5}
// BubbleSort(3), list={2,3,5,7}
// BubbleSort(4), list={2,3,5,7}, if the list is fully sorted 
//                                before x rounds are executed, 
//                                then stop when the list is fully sorted
// Example 2: list={7,5,3,2}
// SelectionSort(1), list={2,5,3,7}
// SelectionSort(2), list={2,3,5,7}
// SelectionSort(3), list={2,3,5,7}, similarly, stop when the list is fully sorted 
//
// Your job is to complete the following functions 
// -- SetList
// -- GetList
// -- BubbleSort
// -- SelectionSort 
class BasicSort {
public:
    void SetList(vector<int> InputList);
    vector<int> GetList();
    void BubbleSort(int NumRound); // numRound part not implemented
    void SelectionSort(int NumRound); //not implemented
    bool isSorted();
private:
    vector<int> list;
};
// ..............................................................
// ---------------------------------------------------------------
int main()
{
    // The main function is given to you. 
    // We first input the testing mode, NumRound and an arbitrary number of non-repeated integers into a vector.
        // The input of this list will terminate when we give an non-integer input  e.g., letter 'a'.
        // Then, we pass this vector to the BasicSort object. 
        // Then, we test your implemented member functions. 
        vector<int> InputList;
    vector<int> TestList;
    int temp, mode, NumRound;
    BasicSort x;
    // take inputs
    cin >> mode >> NumRound;
    while (cin >> temp) {
        InputList.push_back(temp);
    }
    // pass inputs to class objects 
    x.SetList(InputList);

    // start testing functions 
    switch (mode) {
    case 1: // check if input is corret 
        TestList = x.GetList();
        for (int i = 0; i < TestList.size(); i++) {
            cout << TestList.at(i) << endl;
        }
        break;
    case 2: // check if BubbleSort is correct when NumRound=-1
        x.BubbleSort(NumRound);
        TestList = x.GetList();
        for (int i = 0; i < TestList.size(); i++) {
            cout << TestList.at(i) << endl;
        }
        break;
    case 3: // check if BubbleSort is correct when NumRound 
        x.BubbleSort(NumRound);
        TestList = x.GetList();
        for (int i = 0; i < TestList.size(); i++) {
            cout << TestList.at(i) << endl;
        }
        break;
    case 4: // check if SelectionSort is correct when NumRound=-1
        x.SelectionSort(NumRound);
        TestList = x.GetList();
        for (int i = 0; i < TestList.size(); i++) {
            cout << TestList.at(i) << endl;
        }
        break; 
    case 5: // check if SelectionSort is correct when NumRound
        x.SelectionSort(NumRound);
        TestList = x.GetList();
        for (int i = 0; i < TestList.size(); i++) {
            cout << TestList.at(i) << endl;
        }
        break;
    }
    return 0;
}

void BasicSort::SetList(vector<int> InputList)
{
    this->list =InputList;
}

vector<int> BasicSort::GetList()
{
    return this->list;
}

bool BasicSort::isSorted()
{
    for (int i = 0; i < this->list.size() - 1; ++i)
    {
        if (this->list.at(i) > this->list.at(i + 1))
        {
            return false;
        }
    }
    return true;
}

void BasicSort::BubbleSort(int NumRound) 
{
    int roundsCompleted = 0;
    
    if (NumRound == -1)
    {
        while (isSorted() == false)
        {
            for (int i = 0; i < list.size() - 1; i++)
            {
                if (list.at(i) > list.at(i + 1))
                {
                    int temp = list.at(i);
                    list.at(i) = list.at(i + 1);
                    list.at(i + 1) = temp;
                }
            }
        }


    }

    else
    {
        while(isSorted() == false && roundsCompleted != NumRound)
         {
            for (int i = 0; i < list.size() - 1; i++)
            {
                if (list.at(i) > list.at(i + 1))
                {
                    int temp = list.at(i);
                    list.at(i) = list.at(i + 1);
                    list.at(i + 1) = temp;
                }
            }
   

                   roundsCompleted++;
         }
    }
    
}

void BasicSort::SelectionSort(int NumRound)
{
    int roundsCompleted = 0;
    if (NumRound == -1)
    {
        for (int i = 0; i < this->list.size()-1; i++)
        {
            int minPos = i;// dont want this one messig me up
            for (int j = i + 1; j < this->list.size(); j++)
            {
                if (this->list.at(j) < this->list.at(minPos))
                {
                    minPos = j;
                }
            }

            if (minPos != i)
            {
                int temp = this->list.at(i);
                this->list.at(i) = this->list.at(minPos);
                this->list.at(minPos) = temp;
            }


        }
    }
    else
    {
        for (int i = 0; i < this->list.size() - 1; i++)
        {


            int minPos = i;// dont want this one messig me up
            for (int j = i + 1; j < this->list.size(); j++)
            {
                if (this->list.at(j) < this->list.at(minPos))
                {
                    minPos = j;
                }
            }

            if (minPos != i && roundsCompleted < NumRound) // so close
            {
                int temp = this->list.at(i);
                this->list.at(i) = this->list.at(minPos);
                this->list.at(minPos) = temp;
                roundsCompleted++;
            }




        }
    }



  
}

