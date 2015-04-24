#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

const int x=8,y=8;
const int m=8,n=8;

void input(ifstream F, int arr[][]);
void input(ifstream F, int arr[][]){
	int j, k;
	for (j=0;j<15;j++){
		for(k=0;k<15;k++){
			F >> arr[j][k];
		}
	}
	F.close();
}

int main(int argc, const char* argv[]){

    //clrscr();
	int i,j,    
	int a[x][y]/*={
		{12,13,2,3,3,2,11,5}, // row 1
		{3,5,2,14,11,5,6,12}, // row 2
		{4,11,3,2,5,7,12,3}, //row 3
		{13,11,12,4,8,11,10,3} //row 4
	}*/; 
	b[x][y], c[x][y];

	//open source file A
	ifstream input_A("input.csv");
	if (!input_A.is_open()){
		input_A.open("input.csv", ios::in|ios::out);
		if (!input_A){
			cerr << "Fail to open" << input_A << endl;
			exit(EXIT_FAILURE);
		}	
	}

	// Data entry
	input(input_A,a);
	
	//open source file B
	ifstream input_B("input_B.csv"); 
	if (!input_B.is_open()){
		input_B.open("input_B.csv", ios::in|ios::out);
		if (!input_B){
			cerr << "Fail to open" << input_B << endl;
			exit(EXIT_FAILURE);
		}	
	}

	// Data entry
    	input(input_B,b);
 
 /* cout<<"\n\nEnter elements for Matrix A :::\n\n";
 
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            cin>>a[i][j];
        }
        cout<<"\n";
    }*/
 
    cout<<"\n\nMatrix A :\n\n";
 
    for(i=0;i<x;i++) {
        for(j=0;j<y;j++){
            cout<<"\t"<<a[i][j];
        }
        cout<<"\n\n";
    }
 /*
    cout<<"\n-----------------------------------------------------------\n";
 
    cout<<"\nEnter the number of rows and columns for Matrix B:::\n\n";
    cin>>m>>n;
 
    // m denotes number rows in matrix B
    // n denotes number columns in matrix B
 
    cout<<"\n\nEnter elements for Matrix B :::\n\n";
 
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cin>>b[i][j];
        }
        cout<<"\n";
    }
 
 */
    cout<<"\n\nMatrix B :\n\n";
 
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cout<<"\t"<<b[i][j];
        }
        cout<<"\n\n";
    }
 
	for(i=0;i<x;i++){
            for(j=0;j<n;j++){
                c[i][j]=0;
                for(int k=0;k<m;k++){
                    c[i][j]=c[i][j]+a[i][k]*b[k][j];
                }
            }
        }
 
        cout<<"\n-----------------------------------------------------------\n";
 
        cout<<"\n\nMultiplication of Matrix A and Matrix B :\n\n";
 
        for(i=0;i<x;i++) {
            for(j=0;j<n;j++) {
                cout<<"\t"<<c[i][j];
            }
            cout<<"\n\n";
        }
    
 
    getch();
    return 0;
}
