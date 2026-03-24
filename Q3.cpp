#include <iostream>
using namespace std;


void QuanMa(int m, int n, int i, int j) {
    int buocdi[8][2] = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };
    
    cout << "ma tran: " << m << " x " << n << endl;
    cout << "vi tri hien tai: (" << i << ", " << j << ")" << endl;
    cout << "vi tri di den duoc: ";
    
    int count = 0;
    cout << "vi tri di den duoc: ";

    for (int k = 0; k < 8; k++) {
        int ni = i + buocdi[k][0];
        int nj = j + buocdi[k][1];

        if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
            if (count > 0) cout << ", ";
            cout << "(" << ni << ", " << nj << ")";
            count++;
        }
    }

    if (count == 0) {
        cout << "khong hop le";
    }
    cout << "\nTong so nuoc di: " << count << "\n\n";
}

int main() {
    cout << "Q3-b1\n";  
    int m, n, i, j;
    cout << "Nhap kich thuoc ma tran (m n): ";
    cin >> m >> n;
    cout << "Nhap vi tri ma (i j): ";
    cin >> i >> j;
    QuanMa(m, n, i, j);

    return 0;
}

