#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

void FillInc(int A[], int N) {
    for (int i = 0; i < N; i++) {
        A[i] = i + 1;
    }
}
void FillDec(int A[], int N) {
    for (int i = 0; i < N; i++) {
        A[i] = N - i;
    }
}
void FillRand(int A[], int N) {
    for (int i = 0; i < N; i++) {
        A[i] = rand() % 100; 
    }
}
int CheckSum(int A[], int N) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i];
    }
    return sum;
}
int RunNumber(int A[], int N) {
    int runCount = 1;
    int rowCount = 0;
    for (int i = 0; i < N-1; i++) {
        if (A[i] <= A[i + 1]) rowCount++;
        if (A[i] >= A[i + 1] || rowCount == N) {
            rowCount = 0;
            runCount++;
        }
    }
    return runCount;
}
void PrintMas(int A[], int N) {
    cout << "[ ";
    for (int i = 0; i < N; i++){
        cout << A[i] << " ";
    }
    cout << "]";
}
//Метод SelectSort
void SelectSort(int A[], int N) {
    int C = 0;
    int M = 0;
    int minId;
    for (int i = 0; i < N - 1; i++) {
        minId = i;
        for (int j = i + 1; j < N; j++) {
            C++;
            if (A[j] < A[minId]) minId = j;
        }
        M += 3;
        swap(A[minId], A[i]);
    }
    cout << "\nC: " << C << ", M: " << M << ", C + M = " << C + M;
}
void OptimizedSelectSort(int A[], int N) {
    int C = 0;
    int M = 0;
    int minId;
    for (int i = 0; i < N - 1; i++) {
        minId = i;
        for (int j = i + 1; j < N; j++) {
            C++;
            if (A[j] < A[minId]) minId = j;
        }
        if (minId != i) {
            M += 3;
            swap(A[minId], A[i]);
        }
    }
    cout << "\nC: " << C << ", M: " << M << ", C + M = " << C + M;
}

//Метод BubbleSort
void BubbleSort(int A[], int N) {
    int i; // index for iteration
    int j; // index for right element in current pair
    int C = 0;
    int M = 0;
    for (i = 0; i < N - 1; i++) {
        for (j = N-1; j > i; j--) {
            C++;
            if (A[j] < A[j - 1]) {
                M += 3;
                swap(A[j], A[j - 1]);
            }
        }
    }
    cout << "\nC: " << C << ", M: " << M << ", C + M = " << C + M;
}

//ShakerSort
void ShakerSort(int A[], int N) {
    int L = 1;
    int R = N - 1;
    int C = 0;
    int M = 0;
    int k = N;
    while (L < R) {
        for (int j = R; j > L - 1; j--) {
            C++;
            if (A[j] < A[j - 1]) {
                M += 3;
                swap(A[j], A[j - 1]);
                k = j;
            }
        }
        L = k;
        for (int j = L; j < R; j++) {
            C++;
            if (A[j] > A[j + 1]) {
                M += 3;
                swap(A[j], A[j + 1]);
                k = j;
            }
        }
        R = k;
    }
    cout << "\nC: " << C << ", M: " << M << ", C + M = " << C + M << "\n";
}

void InsertSort(int A[], int N) {
    int C = 0;
    int M = 0;
    int temp;
    bool check = false;
    for (int i = 1; i < N; i++) {
        temp = A[i];
        M++;
        int j = i - 1;
        while ((j >= 0) && (temp < A[j])) {
            check = true;
            A[j + 1] = A[j];
            j--;
            C++;
            M++;
        }
        if (check == false) C++;
        M++;
        A[j + 1] = temp;
    }

    cout << "\nC: " << C << ", M: " << M << ", C + M = " << C + M;
}

void TablePrint(const int wight) {
    cout << right << setw(3*wight) << "C + M (fact.)" << endl;

    cout << left << setw(wight-8) << "N"
        << setw(wight) << "C + M (theor.)"
        << setw(wight) << "Desc."
        << setw(wight) << "Rand."
        << setw(wight) << "Asc." << endl;
    cout << string(4 * wight, '-') << endl;

    cout << left << setw(wight-8) << "100"
        << setw(wight) << "10098"
        << setw(wight) << "10098"
        << setw(wight) << "5367"
        << setw(wight) << "297" << endl;

    cout << left << setw(wight-8) << "200"
        << setw(wight) << "40198"
        << setw(wight) << "40198"
        << setw(wight) << "18911"
        << setw(wight) << "597" << endl;

    cout << left << setw(wight-8) << "300"
        << setw(wight) << "90298"
        << setw(wight) << "90298"
        << setw(wight) << "43711"
        << setw(wight) << "897" << endl;

    cout << left << setw(wight-8) << "400"
        << setw(wight) << "160398"
        << setw(wight) << "160398"
        << setw(wight) << "77158"
        << setw(wight) << "1197" << endl;

    cout << left << setw(wight-8) << "500"
        << setw(wight) << "250498"
        << setw(wight) << "250498"
        << setw(wight) << "127848"
        << setw(wight) << "1497" << endl;
}
int main() {
    const int wight = 15;
    srand(time(0));
    const int n = 100;
    int A[n];
    FillInc(A, n);
    PrintMas(A, n);
    int sum = CheckSum(A, n);
    int run = RunNumber(A, n);
    cout <<"Sum: "<< sum << ", Run: " << run << "\n";
    int A2[n];
    FillDec(A2, n);
    PrintMas(A2, n);
    int sum2 = CheckSum(A2, n);
    int run2 = RunNumber(A2, n);
    cout << "Sum: " << sum2 << ", Run: " << run2 << "\n";
    int A3[n];
    FillRand(A3, n);
    PrintMas(A3, n);
    int sum3 = CheckSum(A3, n);
    int run3 = RunNumber(A3, n);
    cout << "Sum: " << sum3 << ", Run: " << run3 << "\n";

    //SelectSort 
    //SelectSort(A2, n);
    //cout << "\nSorted descending massive: ";
    //PrintMas(A2, n);
    //SelectSort(A, n);
    //cout << "\nSorted ascending massive: ";
    //PrintMas(A, n);
    //SelectSort(A3, n);
    //cout << "\nSorted random massive: ";
    //PrintMas(A3, n);
    //OptimizedSelectSort
    //int B[n];
    //FillInc(B, n);
    //int B2[n];
    //FillDec(B2, n);
    //cout << "\n---\n";
    //int B3[n];
    //FillRand(B3, n);
    //PrintMas(B3, n);
    //int sum32 = CheckSum(B3, n);
    //int run32 = RunNumber(B3, n);
    //cout << "Sum: " << sum32 << ", Run: " << run32 << "\n";
    //OptimizedSelectSort(B2, n);
    //cout << "\nSorted descending massive with optimisation: ";
    //PrintMas(B2, n);
    //OptimizedSelectSort(B, n);
    //cout << "\nSorted ascending massive with optimisation: ";
    //PrintMas(B, n);
    //OptimizedSelectSort(A3, n);
    //cout << "\nSorted random massive with optimisation: ";
    //PrintMas(A3, n);

    //BubbleSort
    //BubbleSort(A2, n);
    //cout << "\nSorted descending massive with optimisation: ";
    //PrintMas(A2, n);
    //BubbleSort(A, n);
    //cout << "\nSorted ascending massive with optimisation: ";
    //PrintMas(A, n);
    //BubbleSort(A3, n);
    //cout << "\nSorted random massive with optimisation: ";
    //PrintMas(A3, n);

    //ShakerSort
    /*
    ShakerSort(A2, n);
    cout << "\nSorted descending massive with optimisation: ";
    PrintMas(A2, n);
    int sum1 = CheckSum(A2, n);
    int run1 = RunNumber(A2, n);
    cout << "Sum: " << sum1 << ", Run: " << run1 << "\n";
    ShakerSort(A, n);
    cout << "\nSorted ascending massive with optimisation: ";
    PrintMas(A, n);
    int sum4 = CheckSum(A, n);
    int run4 = RunNumber(A, n);
    cout << "Sum: " << sum4 << ", Run: " << run4 << "\n";
    ShakerSort(A3, n);
    cout << "\nSorted random massive with optimisation: ";
    PrintMas(A3, n);
    int sum5 = CheckSum(A3, n);
    int run5 = RunNumber(A3, n);
    cout << "Sum: " << sum5 << ", Run: " << run5 << "\n";
    */

    //InsertSort
    InsertSort(A2, n);
    cout << "\nSorted descending massive with optimisation: ";
    PrintMas(A2, n);
    int sum1 = CheckSum(A2, n);
    int run1 = RunNumber(A2, n);
    cout << "Sum: " << sum1 << ", Run: " << run1 << "\n";
    InsertSort(A, n);
    cout << "\nSorted ascending massive with optimisation: ";
    PrintMas(A, n);
    int sum4 = CheckSum(A, n);
    int run4 = RunNumber(A, n);
    cout << "Sum: " << sum4 << ", Run: " << run4 << "\n";
    InsertSort(A3, n);
    cout << "\nSorted random massive with optimisation: ";
    PrintMas(A3, n);
    int sum5 = CheckSum(A3, n);
    int run5 = RunNumber(A3, n);
    cout << "Sum: " << sum5 << ", Run: " << run5 << "\n";

    TablePrint(wight);
}  