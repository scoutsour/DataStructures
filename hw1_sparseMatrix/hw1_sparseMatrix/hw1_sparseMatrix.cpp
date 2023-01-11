#include <iostream>
using namespace std;
class matrix {
public:
    void SetEntry(int i, int j, int v);
    int GetEntry(int i, int j); // this is already defined for you. 
    int CountNonZero();
    void GetSparseRep();
    int* SparseRow, * SparseCol, * SparseVal;
private:
    int m[3][5];
};
void matrix::SetEntry(int i, int j, int v) {

    // ------------------------------------------------------
    // assign value v to the row i and column j of matrix "m" 
    // ------------------------------------------------------
    m[i][j] = v;

}
int matrix::GetEntry(int i, int j) {
    // this function returns matrix entry at row i and column j 
    return m[i][j];
}
int matrix::CountNonZero() {
    // ------------------------------------------------------
    // return the number of non-zero elements in matrix "m" 
    // ------------------------------------------------------
    int returning = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (m[i][j] != 0)
            {
                returning = ++returning; // for loop to check how many zero elements there are
            }
        }
    }

    return returning;

}
void matrix::GetSparseRep() {

    // ------------------------------------------------------
    // generate a sparse representation of matrix "m"
    // ------------------------------------------------------
    // assign results to (SparseRow, SparseCol, SparseVal)
    // use SparseRow to hold row indcies
    // use SparseCol to hold column indcies
    // use SparseVal to hold entry values
    // 
    // For example, if the first non-zero element we find is m[a][b], 
    // then SparseRow[0]=a, SparseCol[0]=b, SparseVale[0]=m[a][b]. 
    // If the second non-zero element we find is m[c][d], then 
    // SparseRow[1]=a, SparseCol[1]=b, SparseVale[1]=m[a][b]
    // 
    // parts of the code is given to you, please build on them
    // you can add lines both inside and outside the loop.
    // --------------------------------------------------------
    this->SparseRow = new int[3];
    this->SparseCol = new int[3];
    this->SparseVal = new int[3];
    int counter = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (m[i][j] != 0) {
                

                this->SparseRow[counter] = i;
                this->SparseCol[counter] = j;
                this->SparseVal[counter] = m[i][j]; // returned the sparse representation for task 3
            

                ++counter;
               
            }
        }
    }
}



int main()
{
    // The main function is given to you. 
    // It first declares a matrix object "x", 
    // then inputs the matrix values, 
    // then generates the sparse representation 
    // of the matrix and finally outputs it. 
    // You do not need to modify this function. 
    // And please do not modify it or Gradescope 
    // may not recognize the format of your intput/output.
    matrix x;

    int temp, mode;
    cin >> mode; // this controls what to test 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> temp;
            x.SetEntry(i, j, temp);
        }
    }
    switch (mode) {

    case 1: // test if inputs are correctly assigned 

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 5; j++) {
                cout << x.GetEntry(i, j) << endl;
            }
        }
        break;

    case 2: // test if CountNonZero() is correct 
        cout << x.CountNonZero() << endl;
        break;
    case 3: // test if GetSparseRep() is correct 
        x.GetSparseRep();
        for (int i = 0; i < x.CountNonZero(); i++) {
            cout << x.SparseRow[i] << ' ' << x.SparseCol[i] << ' ' <<
                x.SparseVal[i] << endl;
        }
        break;
    }
    return 0;
}