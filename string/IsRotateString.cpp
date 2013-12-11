// s2がs1を回転させたものかどうかを判定する
// たとえば「waterbottle」は「erbottlewat」を回転させたもの

#include <stdio.h>
#include <string.h>

bool isSubstring(char* s1, char* s2)
{
	return ( strstr( s1, s2) != NULL);
}


//「erbottlewat」「waterbottle」.

bool check(char* s1, char* s2)
{
	int len1 = strlen(s1);
	int len2 = strlen(s2);

	if(len1 != len2){
		return false;
	}


	// s2の最初の文字が、s1の中で出現する位置を探す.

	// 検索文字をセット.
	char c = s2[0];

	for(int n = 0; n < len1; n++){

		if( s1[n] != c ){
			continue;
		}

		// そこから末尾まで一致しなくなるまで検索する.
		bool b = true;
		int j = 1;
		for(int i = n + 1; i < len1; i++, j++){
			if( s1[i] != s2[j] ){
				b = false;
				break;
			}
		}

		// 末尾まですべて一致したら、s1全体の中からs2の残り全部をisSubString()で探す.
		if(b){

			char* ss2 = &(s2[j]);
			return isSubstring(s1, ss2);
		}

	}

	return false;
}


int main(int argc, char **argv)
{
	if(argc != 3) return 0;

	if( check(argv[1], argv[2]) ){
		printf("ok\n");
	}else{
		printf("ng\n");
	}

	return 0;
}

