#include <iostream>
#include <conio.h>
#include <fstream>

//#include "input.csv"
//#include "input_B.csv"

using namespace std;

//const int x=8,y=8;
//const int m=8,n=8;

#define x 8
#define y 8
#define m 8
#define n 8

void input(ifstream& F, int row, int col, int arr[][8]);
void input(ifstream& F, int row, int col, int arr[][8]){
	int j, k;
	for (j=0; j<row; j++){
		for(k=0; k<col; k++){
			F >> arr[j][k];
		}
	}
	F.close();
}

int main(int argc, const char* argv[]){

	int i, j;
	int a[x][y]/*={
		{12,13,2,3,3,2,11,5}, // row 1
		{3,5,2,14,11,5,6,12}, // row 2
		{4,11,3,2,5,7,12,3}, //row 3
		{13,11,12,4,8,11,10,3} //row 4
	}*/,
	b[m][n], c[x][n];

	//open source file A
	ifstream input_A("C:\Users\fsche_000\Downloads\input.csv", ios::in | ios::out);
	if (!input_A.is_open()){
		//input_A.open("input.csv", ios::in | ios::out);
		if (!input_A){
			cerr << "Fail to open" << endl;
			exit(EXIT_FAILURE);
		}	
	}

	// Data entry
	input(input_A,x,y,a);
	
	//open source file B
	ifstream input_B("C:\Users\fsche_000\Downloads\input_B.csv", ios::in | ios::out);
	if (!input_B.is_open()){
		input_B.open("input.csv", ios::in | ios::out);
		if (!input_B){
			cerr << "Fail to open B" << endl;
			exit(EXIT_FAILURE);
		}	
	}

	// Data entry
    	input(input_B,m,n,b);
 
    cout<<"\n\nMatrix A :\n\n";
 
    for(i=0;i<x;i++) {
        for(j=0;j<y;j++){
            cout<<"\t"<<a[i][j];
        }
        cout<<"\n\n";
    }
 
    cout<<"\n\nMatrix B :\n\n";
 
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cout << "\t"<<b[i][j];
        }
        cout << "\n\n";
    }
 
	for(i=0;i<x;i++){
            for(j=0;j<n;j++){
                c[i][j]=0;
                for(int k=0;k<m;k++){
                    c[i][j]=c[i][j]+a[i][k]*b[k][j];
                }
            }
        }
 
        cout<<"\n\nMultiplication of Matrix A and Matrix B :\n\n";
 
        for(i=0;i<x;i++) {
            for(j=0;j<n;j++) {
                cout<<"\t"<<c[i][j];
            }
            cout<<"\n\n";
        }
    
    return 0;
}