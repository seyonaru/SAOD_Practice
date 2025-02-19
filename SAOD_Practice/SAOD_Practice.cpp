#include <iostream>
#include <ctime>
#include <cstdlib>

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
    for (i = 0; i < N - 2; i++) {
        for (j = N; j > i; j--) {
            C++;
            if (A[j] < A[j - 1]) {
                M += 3;
                swap(A[j], A[j - 1]);
            }
        }
    }
    cout << "\nC: " << C << ", M: " << M << "\n";
}

int main() {
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
    int sum2 = CheckSum(A, n);
    int run2 = RunNumber(A, n);
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
    //cout << "\nSorted ascending masseive: ";
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
    BubbleSort(A2, n);
    cout << "\nSorted descending massive with optimisation: ";
    PrintMas(A2, n);
    BubbleSort(A, n);
    cout << "\nSorted ascending massive with optimisation: ";
    PrintMas(A, n);
    BubbleSort(A3, n);
    cout << "\nSorted random massive with optimisation: ";
    PrintMas(A3, n);
}  