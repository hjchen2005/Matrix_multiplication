#include <windows.h>
#include <iostream>
#include "matrix_multiplication_dpps.h"

using namespace std;

int main(){
	double a[size][size],b[size][size],c[size][size];
	/*for (int row = 0; row <x; j++){
		for (int col = 0; col<n; k++){
			a[col][row]=2;
			b[col][row]=3;
		}
	}*/
	_int64 ctr1 = 0, ctr2 = 0, freq = 0;
	//int acc = 0;//, iter=0;
	if (QueryPerformanceCounter((LARGE_INTEGER *)&ctr1) != 0) {
		for (int tests=0; tests<10; tests++){
		QueryPerformanceCounter((LARGE_INTEGER *)&ctr2);
		cout << "Start value: " << ctr1 << endl;
		matrix_multiplication_dpps(a,b,c);
		cout << "ENd value: " << ctr2 << endl;

		QueryPerformanceCounter((LARGE_INTEGER *)&freq);
		cout << "QueryPerformanceCounter minimum resolution: 1/" << freq << " seconds" << endl;
		cout << "100 increment time: " << ((ctr2 - ctr1)*1.0 / freq) * 1000000 << " microsecs" << endl;
		}
	}
	else {
		DWORD dwerror = GetLastError();
		cout << "error value= " << dwerror << endl;
	}
	system("PAUSE");
	return 0;
}
