#include <fstream>

using std::ifstream;

void input(ifstream& F, int row, int col, int arr[][8]);

void input(ifstream& F, int row, int col, int arr[][8]){
	int j, k;
	for (j = 0; j<row; j++){
		for (k = 0; k<col; k++){
			F >> arr[j][k];
		}
	}
	F.close();
}
