// ソートされていない連結リストから重複する要素を削除する

#include <stdio.h>
#include <string.h>


class LINK_LIST
{
public:
	LINK_LIST* next;
	int data;
};

#define A_LENGTH 13
int Array[A_LENGTH] = {2,1,8,2,7,3,5,8,6,5,9,2,4};


void deleteDups(LINK_LIST* node)
{
	LINK_LIST* current = node;

	while(current != NULL){

		int data = current->data;
		LINK_LIST* chkPointer = current;

		while(chkPointer->next != NULL){

			// 重複している.
			if(data == chkPointer->next->data){
				chkPointer->next = chkPointer->next->next;
			}else{
				chkPointer = chkPointer->next;
			}
		}

		current = current->next;
	}
}

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

int main(int argc, char **argv)
{
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

	deleteDups(head);

	Print(head);

	Free(head);

	return 0;
}


