// 与えられた二つの文字列が、アナグラム(並び替え)になっているかをチェック
// abcd　bdca　→　並び替えになっている。
// abcd　bdcc　→　aが出てこないので並び替えになっていない。

#include "string.h"

bool check(char* str1, char* str2){

	int n1 = strlen(str1);
	int n2 = strlen(str2);
	if(n1 != n2) return false; // 長さが違えば即終了.

	int table[128] = {0};

	while(*str1){
		table[*str1]++; // カウントアップ.
		str1++;
	}

	while(*str2){
		table[*str2]--; // カウントダウン.
		str2++;
	}

	for(int n = 0; n < 128; n++){
		if(table[n] != 0){	// 文字の出現合計が0以外ならアナグラムではない.
			return false;
		}
	}

	return true;
}

int main(int argc, char* argv[])
{

	if( check(argv[1], argv[2]) ){
		printf("success!\n");
	}else{
		printf("error!\n");
	}

	return 0;
}

