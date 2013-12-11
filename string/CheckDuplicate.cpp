
// ある文字列の中に重複した文字が含まれているか検査する
// abcde　→　重複なし
// abcede → 重複あり

#include <string.h>

int main(int argc, char* argv[])
{
	if(argc < 2){
		return 0;
	}

	char* s = argv[1];
	int len = (int)strlen(argv[1]);

	for(int n = 0; n < len; s++, n++){
		if( strchr(s + 1, *s) != NULL){
			printf("Duplicate detection!\n");
			return 0;
		}
	}

	printf("No Duplicate!\n");

	return 0;
}

