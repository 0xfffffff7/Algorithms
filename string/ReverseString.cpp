// 与えられた文字列を逆順に変換する
// abcdefg　→　gfedcba

void reverse(char* str)
{
	int nLen = strlen(str) - 1;
	int nStart = 0;

	for( ; nLen >= nStart; nLen--, nStart++){

		char swap = str[nStart];
		str[nStart] = str[nLen];
		str[nLen] = swap;

	}
}

int main(int argc, char* argv[])
{
	if(argc < 2) return 0;

	reverse( argv[1] );

	printf("%s\n", argv[1]);

	return 0;
}

