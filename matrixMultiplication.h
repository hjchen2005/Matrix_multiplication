#ifndef matrixMultiplication_h
#define matrixMultiplication_h

#define x 8
#define y 8
#define m 8
#define n 8

void multiplication(int i, int j, int c[][8], int a[][8], int b[][8]);
void multiplication(int i, int j, int c[][8], int a[][8], int b[][8]){
	for (i = 0; i<x; i++){
		for (j = 0; j<n; j++){
			c[i][j] = 0;
			for (int k = 0; k<m; k++){
				c[i][j] = c[i][j] + a[i][k] * b[k][j];
			}
		}
	}
}

#endif