// M×Nの行列について、要素が0であれば、その行と列のすべてを0にする

#include <stdio.h>
#include <string.h>

const int LOW_COUNT = 6;
const int COL_COUNT = 6;

int Array[COL_COUNT][LOW_COUNT] =
					{{11,12,13,14,15,16},
					{21,22, 0 ,24, 0 ,26},
					{31,32,33,34,35,36},
					{41,42, 0 ,44,45,46},
					{51,52,53,54, 0 ,56},
					{61,62,63,64,65,66}};


void Show( int Array[COL_COUNT][LOW_COUNT])
{
	for(int i = 0; i < COL_COUNT; i++){
		for(int j = 0; j < LOW_COUNT; j++){
			printf("%d  ", Array[i][j] );
		}
		printf("\n");
	}

	printf("\n");
}

void setZero( int matrix[COL_COUNT][LOW_COUNT] )
{
	bool row[LOW_COUNT] = {false};
	bool col[COL_COUNT] = {false};

	for(int i = 0; i < COL_COUNT; i++){
		for(int j = 0; j < LOW_COUNT; j++){

			if( Array[i][j] == 0){
				row[j] = true;
				col[i] = true;
			}
		}
	}

	for(int i = 0; i < COL_COUNT; i++){
		for(int j = 0; j < LOW_COUNT; j++){

			if( row[j] || col[i]){
				Array[i][j] = 0;
			}
		}
	}
}

int main(int argc, char **argv)
{
	Show( Array);

	setZero( Array );

	Show( Array);

	return 0;
}

