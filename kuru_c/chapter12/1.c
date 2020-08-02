/* **ローカル変数の寿命**
関数の中で宣言された変数の寿命は関数の中だけであるということです。
この様に、関数の中で寿命が終わる変数を、**ローカル変数**と呼びます。
また、変数の寿命や有効範囲などをまとめて、**スコープ**と呼ぶことがあります。

ローカル変数 >>> 関数の中で宣言された変数。仮引数の変数も同様。
**その関数が終わると捨てられ、再度関数が呼ばれた時には新しく作られる。**
また、他の関数から使用することは出来ない。
**ローカル変数が有効なのは、宣言された関数の中のみです。**

スコープ >>> 識別子が有効な範囲を制限する仕組みの総称。
一般的には、変数の寿命と有効範囲を決定する仕組み。

#include <stdio.h>

int countfunc(void);

int main(void)
{
	countfunc();
	countfunc();
	countfunc();
	return 0;
}

int countfunc(void)
{
  // ローカル変数で定義
	int count = 0; 初期化
	count++;
	printf("%d\n",count);
	return count;
}

実行結果 ローカル変数を1回1回呼び出す度に、count変数が初期化されるので、数が1,2,3と増えていかない。
1
1
1

**グローバル変数で上のコードを記述した場合**
グローバル変数は、プログラムの**開始時**に自動的に0に初期化されるのです。

#include <stdio.h>

int count;	グローバル変数

int countfunc(void);

int main(void)
{
	countfunc();
	countfunc();
	countfunc();
	return 0;
}
int countfunc(void)
{
	count++;
	printf("%d\n",count);
	return count;
}

このプログラムの実行結果 グローバル変数
1
2
3

**グローバル変数と同名のローカル変数ではローカル変数が優先**されるのです。

静的なローカル変数の寿命
関数内で変数を宣言する時に、型名の前にstatic(スタティック)とつけることで、
静的なローカル変数を宣言することが出来ます。

**静的なローカル変数の特徴**
関数内で宣言されているので、使用出来るのは宣言された関数内のみですが、
その値は**プログラムが終了するまで残る**のです。
また、特に初期化しなくても、自動的に0に初期化されます。

**静的なローカル変数で上のコードを記述した場合**

#include <stdio.h>

int countfunc(void);

int main(void)
{
	countfunc();
	countfunc();
	countfunc();
	return 0;
}
int countfunc(void)
{
	static int count; 静的なローカル変数
	count++;
	printf("%d\n",count);
	return count;
}

このプログラムの実行結果は、次の通りになります。
関数内で宣言されているので、使用出来るのは宣言された関数内のみですが、値は**プログラムが終了するまで残る**のです。
1
2
3
*/