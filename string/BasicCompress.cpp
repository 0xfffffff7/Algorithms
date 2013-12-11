// aabccccaaa → a2b1c5a3

#include <stdio.h>
#include <string.h>

void Compress(char *str)
{
	int len = strlen(str);
	int count = 0;
	bool bOver = false;

	char* pBuf = new char[len];

	char c = str[0];
	pBuf[0] = str[0];
	int nPos = 1;

	for(int n =0; n < len; n++){

		// 元の文字列の長さを超えた.
		if(nPos > len){
			bOver = true;
			break;
		}

		// 連続している.
		if(str[n] == c){

			count++;
			continue;

		// 連続が終わった.
		}else{

			pBuf[nPos++]  = count + 0x30;
			count = 0;
		}

		c = str[n];

		pBuf[nPos++] = str[n];
		count++;
	}

	if(bOver == false && count > 0){
		pBuf[nPos++]  = count + 0x30;
	}

	if(bOver == false){

		pBuf[nPos] = '\0';
		int n;
		for(n = 0; n < nPos; n++){
			str[n] = pBuf[n];
		}
		str[n] = '\0';
	}

	delete [] pBuf;

	return;
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		return 0;
	}

	printf("%s\n", argv[1]);
	Compress(argv[1]);
	printf("%s\n", argv[1]);

	return 0;
}

