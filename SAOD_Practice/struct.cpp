#include "struct.hpp"


void InsertSortStruct(S s[], int size) {
    S temp;

    for (int i = 1; i < size; i++) {
        temp = s[i];
        int j = i - 1; 

        while (j >= 0 && compare(temp, s[j])) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = temp;
    }
}

bool compare(const S& s1, const S& s2) {
    if (s1.surname != s2.surname) {
        return s1.surname < s2.surname;
    }
    return s1.name < s2.name;
}

void InsertSortStruct(S s[], int size, int key, bool asc) {
    S temp;

    for (int i = 1; i < size; i++) {
        temp = s[i];
        int j = i - 1;

        while (j >= 0 && compare(temp, s[j], key, asc)) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = temp;
    }
}
bool compare(const S& s1, const S& s2, int key, bool asc) {
    string f1, f2;
    switch (key) {
    case 1:
        f1 = s1.surname;
        f2 = s2.surname;
        break;
    case 2:
        f1 = s1.name;
        f2 = s2.name;
        break;
    case 3:
        f1 = s1.secondName;
        f2 = s2.secondName;
        break;
    case 4:
        f1 = s1.number;
        f2 = s2.number;
        break;
    default: 
        return false;
    }
    return asc ? (f1 < f2) : (f1 > f2);
}

int BinarySearchStruct(S s[], int size, int key, const string& ToFind) {
    int L = 0;
    int R = size - 1;
    switch (key)
    {
    case 1:
        while (L <= R) {
            int middle = L + (R - L) / 2;
            if (s[middle].surname == ToFind) {
                return middle;
            }
            if (s[middle].surname > ToFind) {
                R = middle - 1;
            }
            else {
                L = middle + 1;
            }
        }
        break;
    case 2:
        while (L <= R) {
            int middle = L + (R - L) / 2;
            if (s[middle].name == ToFind) {
                return middle;
            }
            if (s[middle].name > ToFind) {
                R = middle - 1;
            }
            else {
                L = middle + 1;
            }
        }
        break;
    case 3:
        while (L <= R) {
            int middle = L + (R - L) / 2;
            if (s[middle].secondName == ToFind) {
                return middle;
            }
            if (s[middle].secondName > ToFind) {
                R = middle - 1;
            }
            else {
                L = middle + 1;
            }
        }
        break;
    case 4:
        while (L <= R) {
            int middle = L + (R - L) / 2;
            if (s[middle].number == ToFind) {
                return middle;
            }
            if (s[middle].number > ToFind) {
                R = middle - 1;
            }
            else {
                L = middle + 1;
            }
        }
        break;
    default:
        break;
    }
    return - 1;   
}
//indexation
vector<int> IndexCreate(const vector<Contact>&con, bool flag) {
    vector<int> ind(con.size());
    iota(ind.begin(), ind.end(), 0);
    sort(ind.begin(), ind.end(), [&](int a, int b) {
        return flag ? con[a].name < con[b].name : con[a].phone < con[b].phone;
        });
    return ind;
}

void Print(const vector<Contact>& con, const vector<int>& ind) {
    for (int i : ind) {
        Contact a = con[i];
        cout << a.print();
    }
}