// 単方向連結リストにおいて、中央の要素のみアクセス可能であり、その要素を削除する
//
// 例　入力　a->b->c->d->e　という連結リストのcが与えられます。
// 結果　a->b->d->e

void deleteMid(LINK_LIST* mid)
{
	LINK_LIST* prev = NULL;
	LINK_LIST* current = mid;

	while(current->next != NULL){

		// ポインタを消すとまずいので、データを一つずつシフトさせる.
		prev = current;
		current->data = current->next->data;
		current = current->next;
	}

	// 最後を消す.
	delete current;

	// 覚えておいたひとつ前のノードを末尾にする.
	prev->next = NULL;

	return;
}

