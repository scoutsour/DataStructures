#include <iostream>
#include <vector>
#include<algorithm>
#include<iostream>
#include<math.h>
#include<cmath>
#include<stdio.h>


//HUGE TAKEAWAY, merge sorts digit by digit (preserves) order if its the same number all the way until max digit
//Easiest way to compare digits is to divide / 10^idx bit- 1 ->will get you the first digit of num after you cut it 

using namespace std;
// ---------------------------------------------------------------
// Task 1: Define a CountSort Class 
// ---------------------------------------------------------------
// Below is a class for counting sort. 
// 
// It has a private vector "list" that holds the list to sort.
// All member functions should operate on "list". 
// 
// It has several public member functions. 
// 1. SetList: assign a vector (to sort) to "list". 
// 2. GetList: return the current "list"
// 3. ListMax: return the maximum value in "list"
// 4. SortList: sort "list" based on the counting sort algorithm.  
class CountSort {
public:
    void SetList(vector<int> InputList);
    vector<int> GetList();
    int ListMax();
    void SortList();
    bool contains(int num, vector<int> list);
private:
    vector<int> list;
};



void CountSort::SetList(vector<int> InputList)
{
    this->list = InputList;
}

vector<int> CountSort::GetList()
{
    return this->list;
}

int CountSort::ListMax()
{
    int returning = 0;
    for (int i = 0; i < list.size(); ++i)
    {
        if (list.at(i) > returning)
        {
            returning = list.at(i);
        }
    }
    return returning;

}


bool CountSort::contains(int num, vector<int> InputList)
{
    for (int i = 0; i < InputList.size(); ++i)
    {
        if (InputList.at(i) == num)
        {
            return true;
        }
    }
    return false;
}


void CountSort::SortList()
{

    int LargestNum = ListMax();
    LargestNum += 1;
    int* arraySum = new int[LargestNum]; // the +1 could be wrong or it could be a max # issue

    // initialize to 0
    for (int i = 0; i < LargestNum; ++i)
    {
        arraySum[i] = 0;
    }

    // counter list
    for (int i = 0; i < list.size(); i++)
    {
        ++arraySum[list.at(i)]; //  counts for duplicates ++
    }

    // sum of counter list
    for (int i = 1; i < LargestNum; i++)
    {
        arraySum[i] += arraySum[i - 1];
    }

    // final = ordered list with -1 in between 
    int* FINAL = new int[LargestNum];
    for (int i = 0; i < LargestNum; ++i)
    {
        FINAL[i] = -1;
    }

    // fills the retunring list
    for (int i = 0; i < list.size(); ++i)
    {
        for (int j = 0; j < LargestNum; ++j)
        {
            if (list[i] == j)
            {
                FINAL[j] = list[i];
            }
        }
    }



    vector<int> nick;
    for (int i = 0; i < LargestNum; ++i)
    {
        if (FINAL[i] != -1)
        {
            nick.push_back(FINAL[i]);
        }
    }

    list = nick;


}



// ..............................................................
// ---------------------------------------------------------------
// ---------------------------------------------------------------
// Task 2: Define a RadixSort Class 
// ---------------------------------------------------------------
// Below is a class for RadixSort.
// 
// It has a private vector "list" that holds the list to sort.
// All member functions should operate on "list". 
// 
// It has several public member functions. 
// 1. SetList: assign a vector (to sort) to "list". 
// 2. GetList: return the current "list"
// 3. GetNumBit: return the maximum number of bits of any element in "list"
//    Example: if "list"={35,27,9}, then return 2
//    Example: if "list"={352,22027,19}, then return 5 
// 4. GetList_ByBit (int IdxBit): return the "IdxBit"_th LSB's in "list" 
//    Example: if "list"={35,27,9} & IdxBit=1, then return a list {5,7,9}
//    Example: if "list"={35,27,9} & IdxBit=2, then return a list {3,2,0}
//    The returned list should be stored in an integer vector (not string or other)
// 5. SortList_byBit (int IdxBit): sort "list" based on the IdxBit_th LSB in "list"
//    Need to call counting sort to do the sorting. 
//    If there is a tie between two elements, preserve their order 
//    Example: if "list"={42,22,7} & IdxBit=1, then return 42,22,7 
//    Example: if "list"={42,22,7} & IdxBit=2, then return 7,22,42 
class RadixSort {
public:
    void SetList(vector<int> InputList);
    vector<int> GetList();
    int GetNumBit();
    vector<int> GetList_byBit(int IdxBit);
    void SortList_byBit(int IdxBit);
    bool isSorted(vector<int> a);
private:
    vector<int> list;
};


bool RadixSort::isSorted(vector<int> a)
{
    for (int i = 0; i < a.size() - 1; ++i)
    {
        if (a.at(i) > a.at(i + 1))
        {
            return false;
        }
    }
    return true;
}

void RadixSort::SetList(vector<int> InputList)
{
    this->list = InputList;
}

vector<int> RadixSort::GetList()
{
    return this->list;
}

int RadixSort::GetNumBit()
{
    int returning = 0;
    int max = 0;

    // finding th largest num
    for (int i = 0; i < list.size(); ++i)
    {

        if (list.at(i) > max)
        {
            max = list.at(i);
        }
    }

    while (max != 0) {
        max = max / 10;
        returning++;
    }
    return returning;


}

vector<int> RadixSort::GetList_byBit(int IdxBit) // didnt want to change the list so it returned one with the elements at a certain index for the sorting part
{
    vector<int> result;
    for (int i = 0; i < list.size(); ++i)
    {
        int temp = list.at(i) / (pow(10, IdxBit - 1)); // gets you to the digit MOST IMPORTANT CODE
        result.push_back(temp % 10); // singles out that digit

    }
    return result;


}

void RadixSort::SortList_byBit(int IdxBit)
{
     vector<int> index_array; // keeps track of index
      for (int i = 0; i < list.size(); ++i)
      {
          index_array.push_back(i);
      }

      vector<int> bit = GetList_byBit(IdxBit);


      //bubble sort to soer digits in (bit)
      while (isSorted(bit) == false) // note the while is the easiest way to go about doing this
      {
          for (int i = 0; i < list.size() - 1; i++)
          {
              if (bit.at(i) > bit.at(i + 1))
              {
                  // arrangin bit
                  int temp = bit.at(i);
                  bit.at(i) = bit.at(i + 1);
                  bit.at(i + 1) = temp;


                  //arrangin indexArr
                  int temp2 = index_array.at(i);
                  index_array.at(i) = index_array.at(i + 1);
                  index_array.at(i + 1) = temp2;
              }
          }
      }

      // loop through the index to put the number

      vector<int> returning;
      for (int i = 0; i < index_array.size(); ++i)
      {
          returning.push_back(list.at(index_array.at(i)));
      }


      SetList(returning);


}

// ..............................................................
// ---------------------------------------------------------------
int main()
{
    // The main function is given to you. 
    // We first input the testing mode, IdxBit and an arbitrary number of non- repeated integers into a vector.
        // The input of this list will terminate when we give an non-integer input    e.g., letter 'a'.
        // Then, we pass this vector to the CountSort and RadixSort objects. 
        // Then, we test your implemented member functions. 
    vector<int> InputList;
    vector<int> TestList;
    int temp, mode, IdxBit;
    CountSort x;
    RadixSort y;
    // takie inputs
    cin >> mode >> IdxBit;
    while (cin >> temp) {
        InputList.push_back(temp);
    }
    // pass inputs to class objects 
    x.SetList(InputList);
    y.SetList(InputList);
    // start testing functions 
    switch (mode) {
    case 1: // check if input of CountSort is corret 
        TestList = x.GetList();
        for (int i = 0; i < TestList.size(); i++) {
            cout << TestList.at(i) << endl;
        }
        break;
    case 2: // check if input of RadixSort is corret 
        TestList = y.GetList();
        for (int i = 0; i < TestList.size(); i++) {
            cout << TestList.at(i) << endl;
        }
        break;
    case 3: // check if ListMax of CountSort is correct 
        cout << x.ListMax() << endl;
        break;
    case 4: // check if SortList of CountSort is correct 
        x.SortList();
        TestList = x.GetList();
        for (int i = 0; i < TestList.size(); i++) {
            cout << TestList.at(i) << endl;
        }
        break;

    case 5: // check if GetNumBit of RadixSort is correct 
        cout << y.GetNumBit() << endl;
        break;
    case 6: // check if GetNumBit of RadixSort is correct 
        TestList = y.GetList_byBit(IdxBit);
        for (int i = 0; i < TestList.size(); i++) {
            cout << TestList.at(i) << endl;
        }
        break;
    case 7: // check if SortList_byBit of RadixSort is correct
        y.SortList_byBit(IdxBit);
        TestList = y.GetList();
        for (int i = 0; i < TestList.size(); i++) {
            cout << TestList.at(i) << endl;
        }
        break;
    }
    return 0;
}
