// ある数xが与えられたとき、連結リストの要素を並び替え、xより小さいものが前にくるようにする

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


// 与えられたxよりも小さい値を前に移動するメソッド.
void partition(LINK_LIST* head, int x)
{
	LINK_LIST* current = head;

	// 前から検査して、
	// xより大きい値の位置を覚えておく。
	// 次にxより小さい数字が出てきたら、お互いを入れ替える.
	while(current->next != NULL){

		// xより大きい値の出現.
		if(current->data >= x){

			LINK_LIST* p1 = current;
			while(current->next != NULL){

				// xより小さい値の出現.
				if(current->data < x){

					// 入れ替え.
					int tmp = p1->data;
					p1->data = current->data;
					current->data = tmp;
					break;
				}
				current = current->next;
			}
			if(current->next == NULL) break;

			// 続きの位置まで戻って探索.
			current = p1;
		}
		current = current->next;
	}

	Print(head);

	// 前から検査してxより大きい数字とxを入れ替える.
	current = head;
	while(current->next != NULL){

		// xより大きい値の出現.
		if(current->data > x){

			LINK_LIST* p1 = current;

			while(current->next != NULL){

				// xを発見.
				if(current->data == x){

					// 入れ替え.
					int tmp = p1->data;
					p1->data = current->data;
					current->data = tmp;
					break;
				}
				current = current->next;
			}
			if(current->next == NULL) break;

			// 続きの位置まで戻って探索.
			current = p1;
		}
		current = current->next;
	}

	return;
}

#define A_LENGTH 13
int Array[A_LENGTH] = {0,3,13,2,4,11,9,3,5,1,0,7,3};


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

	// 与えられた数より小さいものを前に並べる.
	partition(head, 3);

	Print(head);

	Free(head);

	return 0;
}


