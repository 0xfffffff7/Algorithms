// pushとpopに加えて、最小の要素を返す関数minを持つスタック
// push、pop、min関数はすべてＯ(1)の実行時間になる


#include <stdio.h>
#include <string.h>

class LINK_DATA
{
public:
	LINK_DATA* next;
	LINK_DATA* prev;
	int data;
};

class stack
{
public:
	stack();
	~stack();
	void push(int n);
	int pop();
	int size(){return m_nSize;}
	int last(){ return current->data;}

private:
	LINK_DATA root;
	LINK_DATA* current;
	int m_nSize;
};

stack::stack()
{
	m_nSize = 0;
	root.data = 0;
	root.prev = 0;
	root.next = 0;
	current = &root;
}

stack::~stack()
{
	// 解放処理.
	for(int n = 0; n < m_nSize; n++){
		pop();
	}
}

int stack::pop()
{
	int n = current->data;

	// リンクを直前のものに戻して削除する.
	LINK_DATA* tmp = current;
	current = current->prev;
	delete tmp;

	// リストサイズのカウントダウン.
	m_nSize--;

	return n;
}

void stack::push(int n)
{
	LINK_DATA* tmp = current;

	// 新しいリンクノードを生成し、データを繋ぎかえる.
	LINK_DATA* NEW_DATA = new LINK_DATA;
	current->next = NEW_DATA;
	current = current->next;
	current->prev = tmp;
	current->data = n;

	// リストサイズのカウントアップ.
	m_nSize++;
}


//------------------------------------------------------------------------------
// 最小値をO(1)で返すには、スタックのその時点の最小値をセットで記憶すればいい。
// スタックは後入れ先出しなので、取り出される度にその時の状態に戻ることができる.
// 
// しかし、その方法だとスタックが巨大になると記憶しておく最小値の数も増えていく.
// そこで、もう一つ最小値記憶用のスタックを用意してメモリ空間を節約する.
// 以下のクラスStackWithMinにその実装を示す.
//------------------------------------------------------------------------------
class StackWithMin
{
public:
	void push(int n);
	int pop();
	int size(){return s1.size();}
	int min(){ return s2.last();}

private:
	stack s1;  // 通常の値を格納するスタック.
	stack s2;  // 最小値を保持するスタック.
};

void StackWithMin::push(int n)
{
	s1.push(n);

	if(s2.size() == 0){
		s2.push(n);
	}else{

		// 現在の追加値が最小値よりも小さい.
		if(n < s2.last()){
			s2.push(n);
		}
	}
}

int StackWithMin::pop()
{
	int n = s1.pop();

	// 最小値だった場合は一つ取り出して、以前の最小値を最新にする.
	if(n == s2.last() && s2.size() > 1){
		s2.pop();
	}

	return n;
}

int main(int argc, char **argv)
{

	StackWithMin s;

	s.push(100);
	s.push(50);
	s.push(70);
	s.push(90);
	s.push(30);

	printf("min = %d\n", s.min());
	printf("%d\n", s.pop());
	printf("min = %d\n", s.min());
	printf("%d\n", s.pop());
	printf("min = %d\n", s.min());
	printf("%d\n", s.pop());
	printf("min = %d\n", s.min());
	printf("%d\n", s.pop());
	printf("min = %d\n", s.min());
	printf("%d\n", s.pop());
	printf("min = %d\n", s.min());

	return 0;
}


