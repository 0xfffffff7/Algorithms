// 各ノードの要素が1桁の数である連結リストで表された２つの数がある。
// 一の位がリストの先頭になるように、各位の数は逆順に並んでいる。
// 二つの数の和を求め、それを連結リストで表したものを返す。

// 例
// 入力:　(7->1->6) + (5->9->2) →　617 + 295
// 出力:　2 -> 1 -> 9 →　912


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

	while(current != NULL){
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

LINK_LIST* ListAddition(LINK_LIST* list1, LINK_LIST* list2, int carry)
{
	// 両方のリストが0で繰り上がりゼロなら終了.
	if( list1 == NULL && list2 == NULL && carry ==0){
		return NULL;
	}

	LINK_LIST* result = new LINK_LIST;

	// 繰り上がりとlist1とlist2のデータを加える.
	int value = carry;
	if(list1 != NULL){
		value += list1->data;
	}
	if(list2 != NULL){
		value += list2->data;
	}

	result->data = value % 10; // 1の位.

	// 再帰する.
	if(list1 != NULL || list2 != NULL || value >= 10){
		LINK_LIST* more = ListAddition(list1 == NULL ? NULL : list1->next,
										list2 == NULL ? NULL : list2->next,
										value >= 10 ? 1 : 0);

		result->next = more;
	}

	return result;
}


int NUM_ARRAY1[] = {7, 1, 6, -1};
int NUM_ARRAY2[] = {5, 9, 2, -1};

LINK_LIST* Add(LINK_LIST *head, int Data[])
{
	LINK_LIST* current = head;
	int n = 0;
	while(1){
		
		current->data = Data[n];
		if(Data[n + 1] == -1)break;

		LINK_LIST* newNode = new LINK_LIST;
		current->next = newNode;
		current = current->next;
		n++;
	}
	current->next = NULL;

	return head;
}


int main(int argc, char **argv)
{
	// 要素追加.
	LINK_LIST* list1 = new LINK_LIST;
	LINK_LIST* list2 = new LINK_LIST;
	LINK_LIST* head1 = Add(list1, NUM_ARRAY1);
	LINK_LIST* head2 = Add(list2, NUM_ARRAY2);

	Print(head1);

	Print(head2);

	LINK_LIST* result = ListAddition(head1, head2, 0);

	Print(result);

	Free(head1);
	Free(head2);
	Free(result);

	return 0;
}


