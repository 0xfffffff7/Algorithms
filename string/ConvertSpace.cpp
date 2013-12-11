// 文字列内に出現する全ての空白文字を「%20」に置き換える
//　　"Mr John Smith        "
//　　　　↓
//　　"Mr%20John%20Smith"


char	INPUT_STRING[] = "Mr John Smith        ";
int nStrLen = 13;

void ConvertSpace(char* str, int len)
{
	int nCount = 0;
	for(int n = 0; n < len; n++){
		if(str[n] == ' '){
			nCount++;
		}
	}

	// 変換後の長さ.
	int newLen = len + (nCount * 2);

	int nLast = newLen - 1;
	for(int n = len - 1; n >= 0; n--){

		if( str[n] == ' '){ // スペースを発見した.
			str[nLast--] = '0';
			str[nLast--] = '2';
			str[nLast--] = '%';
		}else{
			str[nLast] = str[n];
			nLast--;
		}
	}


}

int main(int argc, char* argv[])
{
	char* str = INPUT_STRING;
	ConvertSpace(str, nStrLen);

	printf("%s\n", str);

	return 0;
}

