#include<iostream>
#include <vector>

using namespace std;
struct Matrix {
    long long mat[2][2];

    Matrix() {
        for(int i=0; i<2; ++i)
            for(int j=0; j<2; ++j)
                mat[i][j] = 0;
    }

    void print(const string& name) const {
        cout << name << ":" << endl;
        cout << "[" << mat[0][0] << ", " << mat[0][1] << "]" << endl;
        cout << "[" << mat[1][0] << ", " << mat[1][1] << "]" << endl;
    }
};
//2.1
Matrix product(Matrix M, Matrix N) {
    Matrix res;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            res.mat[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                res.mat[i][j] += M.mat[i][k] * N.mat[k][j];
            }
        }
    }
    return res;
}


Matrix subtract(Matrix M, Matrix N) {
    Matrix res;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            res.mat[i][j] = M.mat[i][j] - N.mat[i][j];
    return res;
}


Matrix scalarMul(long long k, Matrix M) {
    Matrix res;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            res.mat[i][j] = k * M.mat[i][j];
    return res;
}


void compute_An_Bn(int n, Matrix A, Matrix B) {

    Matrix An;
    An.mat[0][0] = 1; An.mat[1][1] = 1; 
    
    Matrix Bn; 

    for (int i = 0; i < n; i++) {
        
        Matrix nextAn = subtract(product(An, A), scalarMul(13, product(Bn, B)));
        Matrix nextBn = subtract(product(Bn, A), product(An, B));
        
        An = nextAn;
        Bn = nextBn;
    }

    An.print("An");
    Bn.print("Bn");
}
int main(){
	///2.2
	Matrix A, B;
    A.mat[0][0] = 3; A.mat[0][1] = -4;
    A.mat[1][0] = 2; A.mat[1][1] = -1;

    B.mat[0][0] = 2; B.mat[0][1] = -3;
    B.mat[1][0] = 1; B.mat[1][1] = 4;

    int n;
    cout << " Nhap vao so n: ";
    cin >> n;

    if (n < 0) {
        cout << "n phai lon hon 0." << endl;
    } else {
    cout<<" Mang An va Bn lan luot la:"<<endl;
        compute_An_Bn(n, A, B);
    }

    return 0;
}