// N×Nの行列を90度回転させる

#include <stdio.h>
#include <string.h>


int Array[6][6] =	{{11,12,13,14,15,16},
					{21,22,23,24,25,26},
					{31,32,33,34,35,36},
					{41,42,43,44,45,46},
					{51,52,53,54,55,56},
					{61,62,63,64,65,66}};

void Show( int Array[][6], int n)
{
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%d  ", Array[i][j] );
		}
		printf("\n");
	}

	printf("\n");
}

void rotate( int matrix[][6], int n )
{

	for(int layer = 0; layer < n / 2; ++layer){

		int first = layer;
		int last = n - 1 - layer;

		for(int i = first; i < last; ++i){

			int offset = i - first;

			// 上端の値を保存
			int top = matrix[first][i];

			// 左端　→　上端.
			matrix[first][i] = matrix[last - offset][first];

			// 下端　→　左端.
			matrix[last - offset][first] = matrix[last][last  - offset];

			// 右端　→　下端.
			matrix[last][last - offset] = matrix[i][last];

			// 上端　→　右端.
			matrix[i][last] = top;
		}

	}
}

int main(int argc, char **argv)
{
	Show( Array, 6);
	rotate( Array, 6);
	Show( Array, 6);

	return 0;
}

