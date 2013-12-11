// 単方向リストにおいて、末尾から数えてK番目の要素を見つける

#include <stdio.h>
#include <string.h>

class LINK_LIST
{
public:
	LINK_LIST* next;
	int data;
};

void Print(LINK_LIST *node)
{
	LINK_LIST* current = node;

	while(current->next != NULL){
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

void Free(LINK_LIST *node)
{
	LINK_LIST* current = node;

	while(current != NULL){
		LINK_LIST* tmp = current->next;
		delete current;
		current = tmp;
	}
}

int search_N(LINK_LIST* head, int n)
{
	LINK_LIST* p1 = head;
	LINK_LIST* p2 = head;

	// p2をp1からn個進んだ位置にする.
	for(int i = 0; i < n; i++){
		if(p2 == NULL) return -1;
		p2 = p2->next;
	}
	if(p2 == NULL) return -1;

	// p1とp2を同じ1つずつ前に進める.
	// p2が終端にたどり着いた時、p1は目的の位置にある.
	while(p2->next != NULL){
		p1 = p1->next;
		p2 = p2->next;
	}

	return p1->data;
}

#define A_LENGTH 13
int Array[A_LENGTH] = {2,1,8,2,7,3,5,8,6,5,9,2,4};

int main(int argc, char **argv)
{

	// 要素追加.
	LINK_LIST* head = new LINK_LIST;
	LINK_LIST* current = head;

	for(int n = 0; ; n++){

		current->data = Array[n];
		if(n >= A_LENGTH){
			current->next = NULL;
			break;
		}

		LINK_LIST* next = new LINK_LIST;
		current->next = next;
		current = next;
	}
	
	Print(head);

	printf( "%d\n", search_N(head, 4) );

	Free(head);

	return 0;
}

