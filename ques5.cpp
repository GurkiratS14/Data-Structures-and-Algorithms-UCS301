#include <iostream>
using namespace std;



class DiagonalMatrix {
    int *arr;
    int n;
public:
    DiagonalMatrix(int size) {
        n = size;
        arr = new int[n]; // only diagonal elements
        for(int i=0; i<n; i++) arr[i] = 0;
    }
    void set(int i, int j, int val) {
        if(i == j) arr[i-1] = val;
    }
    int get(int i, int j) {
        if(i == j) return arr[i-1];
        return 0;
    }
    void display() {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

class TriDiagonalMatrix {
    int *arr;
    int n;
public:
    TriDiagonalMatrix(int size) {
        n = size;
        arr = new int[3*n - 2]; // store elements from 3 diagonals
        for(int i=0;i<3*n-2;i++) arr[i]=0;
    }
    int index(int i, int j) {
        if(i-j==1) return i-2;       // lower diagonal
        else if(i==j) return n-1+i-1;// main diagonal
        else if(i-j==-1) return 2*n-1+i-1; // upper diagonal
        return -1;
    }
    void set(int i, int j, int val) {
        int idx = index(i,j);
        if(idx!=-1) arr[idx]=val;
    }
    int get(int i, int j) {
        int idx = index(i,j);
        if(idx!=-1) return arr[idx];
        return 0;
    }
    void display() {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                cout<<get(i,j)<<" ";
            }
            cout<<endl;
        }
    }
};

class LowerTriangularMatrix {
    int *arr;
    int n;
public:
    LowerTriangularMatrix(int size) {
        n = size;
        arr = new int[n*(n+1)/2];
        for(int i=0;i<n*(n+1)/2;i++) arr[i]=0;
    }
    int index(int i, int j) {
        if(i>=j) return (i*(i-1))/2 + (j-1);
        return -1;
    }
    void set(int i,int j,int val) {
        int idx=index(i,j);
        if(idx!=-1) arr[idx]=val;
    }
    int get(int i,int j) {
        int idx=index(i,j);
        if(idx!=-1) return arr[idx];
        return 0;
    }
    void display() {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                cout<<get(i,j)<<" ";
            }
            cout<<endl;
        }
    }
};

class UpperTriangularMatrix {
    int *arr;
    int n;
public:
    UpperTriangularMatrix(int size) {
        n = size;
        arr = new int[n*(n+1)/2];
        for(int i=0;i<n*(n+1)/2;i++) arr[i]=0;
    }
    int index(int i,int j) {
        if(i<=j) return (j*(j-1))/2 + (i-1);
        return -1;
    }
    void set(int i,int j,int val) {
        int idx=index(i,j);
        if(idx!=-1) arr[idx]=val;
    }
    int get(int i,int j) {
        int idx=index(i,j);
        if(idx!=-1) return arr[idx];
        return 0;
    }
    void display() {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                cout<<get(i,j)<<" ";
            }
            cout<<endl;
        }
    }
};

class SymmetricMatrix {
    int *arr;
    int n;
public:
    SymmetricMatrix(int size) {
        n=size;
        arr=new int[n*(n+1)/2];
        for(int i=0;i<n*(n+1)/2;i++) arr[i]=0;
    }
    int index(int i,int j) {
        if(i>=j) return (i*(i-1))/2 + (j-1);
        else return (j*(j-1))/2 + (i-1);
    }
    void set(int i,int j,int val) {
        arr[index(i,j)] = val;
    }
    int get(int i,int j) {
        return arr[index(i,j)];
    }
    void display() {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                cout<<get(i,j)<<" ";
            }
            cout<<endl;
        }
    }
};

int main() {
    int n;
    cout<<"Enter size of matrix: ";
    cin>>n;

    cout<<"\n--- Diagonal Matrix ---\n";
    DiagonalMatrix d(n);
    d.set(1,1,5); d.set(2,2,8); d.set(3,3,9);
    d.display();

    cout<<"\n--- Tri-diagonal Matrix ---\n";
    TriDiagonalMatrix t(n);
    t.set(1,1,1); t.set(1,2,2);
    t.set(2,1,3); t.set(2,2,4); t.set(2,3,5);
    t.set(3,2,6); t.set(3,3,7);
    t.display();

    cout<<"\n--- Lower Triangular Matrix ---\n";
    LowerTriangularMatrix l(n);
    l.set(2,1,10); l.set(3,1,20); l.set(3,2,30);
    l.display();

    cout<<"\n--- Upper Triangular Matrix ---\n";
    UpperTriangularMatrix u(n);
    u.set(1,2,11); u.set(1,3,22); u.set(2,3,33);
    u.display();

    cout<<"\n--- Symmetric Matrix ---\n";
    SymmetricMatrix s(n);
    s.set(1,2,100); s.set(2,3,200); s.set(1,3,300);
    s.display();

    return 0;
}
