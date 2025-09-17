#include <iostream>
using namespace std;

class Sparse {
    int r[20], c[20], v[20];
    int t; // number of non-zero
public:
    Sparse(int arr[][3], int n) {
        t = n;
        for (int i=0; i<n; i++) {
            r[i] = arr[i][0];
            c[i] = arr[i][1];
            v[i] = arr[i][2];
        }
    }

    void display() {
        cout << "Row Col Val" << endl;
        for (int i=0; i<t; i++) {
            cout << r[i] << " " << c[i] << " " << v[i] << endl;
        }
    }

    Sparse transpose() {
        int B[20][3];
        for (int i=0; i<t; i++) {
            B[i][0] = c[i];
            B[i][1] = r[i];
            B[i][2] = v[i];
        }
        return Sparse(B, t);
    }

    Sparse add(Sparse &S) {
        int A[40][3];
        int i=0,j=0,k=0;
        while (i<t && j<S.t) {
            if (r[i]<S.r[j] || (r[i]==S.r[j] && c[i]<S.c[j])) {
                A[k][0]=r[i]; A[k][1]=c[i]; A[k][2]=v[i]; i++; k++;
            }
            else if (S.r[j]<r[i] || (S.r[j]==r[i] && S.c[j]<c[i])) {
                A[k][0]=S.r[j]; A[k][1]=S.c[j]; A[k][2]=S.v[j]; j++; k++;
            }
            else {
                A[k][0]=r[i]; A[k][1]=c[i]; A[k][2]=v[i]+S.v[j]; i++; j++; k++;
            }
        }
        while (i<t) { A[k][0]=r[i]; A[k][1]=c[i]; A[k][2]=v[i]; i++; k++; }
        while (j<S.t) { A[k][0]=S.r[j]; A[k][1]=S.c[j]; A[k][2]=S.v[j]; j++; k++; }
        return Sparse(A,k);
    }

    Sparse multiply(Sparse &S) {
        int A[40][3]; int k=0;
        for (int i=0; i<t; i++) {
            for (int j=0; j<S.t; j++) {
                if (c[i]==S.r[j]) {
                    int row=r[i], col=S.c[j], val=v[i]*S.v[j];
                    int found=0;
                    for (int m=0; m<k; m++) {
                        if (A[m][0]==row && A[m][1]==col) {
                            A[m][2]+=val; found=1; break;
                        }
                    }
                    if (!found) { A[k][0]=row; A[k][1]=col; A[k][2]=val; k++; }
                }
            }
        }
        return Sparse(A,k);
    }
};

int main() {
    int Adata[][3] = {{0,0,5},{0,2,8},{1,1,3},{2,0,6}};
    int Bdata[][3] = {{0,1,4},{1,2,7},{2,0,2},{2,2,1}};
    Sparse A(Adata,4), B(Bdata,4);

    cout << "Matrix A:" << endl; A.display();
    cout << "Matrix B:" << endl; B.display();

    Sparse T = A.transpose();
    cout << "Transpose of A:" << endl; T.display();

    Sparse C = A.add(B);
    cout << "A + B:" << endl; C.display();

    Sparse M = A.multiply(B);
    cout << "A x B:" << endl; M.display();

    return 0;
}
