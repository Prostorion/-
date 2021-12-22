
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
const int height = 9;
const int width = 9;
void generate(int m[height][width]); // generate numbers in matrix
void output( int m[height][width]); // output matrix
void solve( int m[height][width]); // operations from task

int main()
{	

	srand(time(NULL));
	int matrix[height][width];
	generate(matrix);
	output( matrix);
	cout << "===========================================" << endl;
	solve(matrix);
	output(matrix);
}

void generate(int m[height][width]) {
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			m[j][i] = rand() % 101;
		}
	}
}

void output(int m[height][width]) {
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			cout << setw(4) << m[j][i];
		}
		cout << endl;
	}
}

void solve(int m[height][width]) {
	int middle;
		if (width % 2 != 0) {
			middle = width / 2 ;

		}
		else middle = width / 2 -1;
	for (int j = 0; j < height; j++) {
		int min = INT_MAX, minw;
		for (int i = 0; i < width; i++) {
			if (m[j][i] <= min) {
				min = m[j][i];
				minw = i;
			}
		}
		m[j][minw] = m[j][middle];
		m[j][middle] = min;
	}
}