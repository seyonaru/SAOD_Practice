#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
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

//ShellSort

void ShellSort(int A[], int N, const vector<int>& h) {
    int C = 0;
    int M = 0;
    int m = h.size();
    for (int t = m - 1; t >= 0; t--) {
        int k = h[t];
        for (int i = k; i < N; i++) {
            M++;
            int temp = A[i];
            bool check = false;
            int j = i - k;
            while ((j >= 0) && (temp < A[j])) {
                check = true;
                C++;
                M++;
                A[j + k] = A[j];
                j -= k;
            }
            if (check == false) C++;
            M++;
            A[j + k] = temp;
        }
    }

    cout << "C: " << C << ", M: " << M << ", C + M = " << C + M;
}

void TablePrint(const int wight) {
    cout << right << setw(3 * wight) << "ShellSort Method" << endl;

    cout << left << setw(wight - 8) << "N"
        << setw(wight) << "h1 ... hm (D.Knut)"
        << setw(wight) << "Insert M + C (fact.)"
        << setw(wight) << "Shell M + C (fact.)" << endl;
    cout << string(4 * wight, '-') << endl;

    cout << left << setw(wight - 8) << "100"
        << setw(wight) << "1,3,7,15,31"
        << setw(wight) << "5367"
        << setw(wight) << "1795" << endl;

    cout << left << setw(wight - 8) << "200"
        << setw(wight) << "1,3,7,15,31,63"
        << setw(wight) << "18911"
        << setw(wight) << "4320" << endl;

    cout << left << setw(wight - 8) << "300"
        << setw(wight) << "1,3,7,15,31,63,127"
        << setw(wight) << "43711"
        << setw(wight) << "7200" << endl;

    cout << left << setw(wight - 8) << "400"
        << setw(wight) << "1,3,7,15,31,63,127"
        << setw(wight) << "77158"
        << setw(wight) << "10262" << endl;

    cout << left << setw(wight - 8) << "500"
        << setw(wight) << "1,3,7,15,31,63,127"
        << setw(wight) << "127848"
        << setw(wight) << "13012" << endl;
}

void TablePrint2(const int wight) {
    cout << right << setw(2 * wight) << "C + M (fact.)" << endl;

    cout << left << setw(wight - 8) << "N"
        << setw(wight) << "Select"
        << setw(wight) << "Bubble"
        << setw(wight) << "Shaker"
        << setw(wight) << "Insert" << endl;
    cout << string(4 * wight, '-') << endl;

    cout << left << setw(wight - 8) << "100"
        << setw(wight) << "5247"
        << setw(wight) << "11455"
        << setw(wight) << "9995"
        << setw(wight) << "5367" << endl;

    cout << left << setw(wight - 8) << "200"
        << setw(wight) << "21597"
        << setw(wight) << "49428"
        << setw(wight) << "44872"
        << setw(wight) << "18911" << endl;

    cout << left << setw(wight - 8) << "300"
        << setw(wight) << "44547"
        << setw(wight) << "107471"
        << setw(wight) << "99876"
        << setw(wight) << "43711" << endl;

    cout << left << setw(wight - 8) << "400"
        << setw(wight) << "80697"
        << setw(wight) << "205226"
        << setw(wight) << "177708"
        << setw(wight) << "77158" << endl;

    cout << left << setw(wight - 8) << "500"
        << setw(wight) << "125847"
        << setw(wight) << "305559"
        << setw(wight) << "258822"
        << setw(wight) << "127848" << endl;
}

int main() {
    srand(0);
    const int n = 500;
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
    /*
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
    */

    //ShellSort 
    int m = floor(log2(n)) - 1;
    vector<int> h(m);
    cout << m;
    for (int i = 0; i < m; i++) {
        if (i == 0) h[i] = 1;
        else h[i] = 2 * h[i - 1] + 1;
    }
    cout << endl;
    for (int i : h) cout << i << "\t";
    
    ShellSort(A2, n, h);
    cout << "\nSorted descending massive: ";
    PrintMas(A2, n);
    int sum1 = CheckSum(A2, n);
    int run1 = RunNumber(A2, n);
    cout << "Sum: " << sum1 << ", Run: " << run1 << "\n";
    ShellSort(A, n, h);
    cout << "\nSorted ascending massive: ";
    PrintMas(A, n);
    int sum4 = CheckSum(A, n);
    int run4 = RunNumber(A, n);
    cout << "Sum: " << sum4 << ", Run: " << run4 << "\n";
    ShellSort(A3, n, h);
    cout << "\nSorted random massive: ";
    PrintMas(A3, n);
    int sum5 = CheckSum(A3, n);
    int run5 = RunNumber(A3, n);
    cout << "Sum: " << sum5 << ", Run: " << run5 << "\n";
    
    const int wight = 15;
    TablePrint(wight);
}  