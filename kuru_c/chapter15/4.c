/* **引数による情報の受け渡し**
**ポインタ型の引数**
ポインタ型を使うのは、ポインタ型はアドレスを受け取ることが出来るからです。
関数を呼び出す時に、既に存在する変数のアドレスを指定すれば、
呼び出された関数で、受け取ったアドレスをポインタ変数に代入すれば、
後はポインタ変数を通常変数モードに切り替えて、返す情報を代入出来ます。
返された情報は、呼び出し側で指定した変数に記憶されていることになります。

次のプログラムは、実際にポインタ型の引数を使って情報を返す例です。

#include <stdio.h>

void func(int *pvalue); プロトタイプ宣言

int main(void)
{
	int value = 10;
	printf("&value = %p\n",&value);
	func(&value); アドレスを渡す
	printf("value = %d\n",value);
	return 0;
}

void func(int *pvalue)
{
	printf("pvalue = %p\n",pvalue);
	*pvalue = 100; 通常変数モードに切り替えて代入
	return;
}
このプログラムの実行結果は、次のようになるかもしれません。

&value = 0F68
pvalue = 0F68
value = 100

次の3つは同じ意味の**仮引数宣言**です。
ただし、この3つが同じ意味になるのは関数の仮引数宣言の場合のみです。

int getaverage(int data[10]);
3つの中でおすすめのプロトタイプ宣言は、下の(int data[])を用いた宣言。
int getaverage(int data[])
int getaverage(int *data);

**宣言時と数式との違い**
配列を宣言する時には、[]で**要素数を指定**し、
配列の要素を使う時は、[]で**番号を指定する**のですが、
実は、この2つも全く別の記号です。

宣言時の[]は要素数を指定するという意味を持ちますが、
数式の中で使用する[]は、**アドレスに足し算する演算子**です。

**配列とポインタは全く別物**
配列とは、多数の変数を順番つけでまとめて扱う方法であり、
ポインタとは、変数のショートカットを作る方法です。

似たような使い方が出来るのは配列の設計と関係あります。
C言語では、配列を実現する手段として、ポインタを利用しているからです。
ポインタ変数では、配列と同等のことが出来てしまいます。

そのため、ポインタと配列は混同しやすいのですが、
配列はあくまでも多数の変数の先頭を示す**固定された変数**であり、
ポインタ変数は、好きな変数のアドレスを代入して、
好きなメモリ領域を使うことが出来る**可変的な変数**です。

**ポインタ専用の書き方**
ポインタ変数には、ポインタ変数用の書き方があります。
これは、ポインタ演算と呼ばれる書き方で、次のように書きます。

*(ポインタ変数 + 要素番号)

ポインタ変数は値を変更出来ることを利用した次のような書き方もあります。
一般的にポインタ演算と言えば、こちらを指すことが多いようです。

#include <stdio.h>

int main(void)
{
	int *data;
	int average = 0,array[10] = {15,78,98,15,98,85,17,35,42,15};

  ポインタ変数が(0から数えて)10番目の要素と同じ値になるまで繰り返します。
	for (data = array;data != &array[10];data++) {	 ここに注目
		average += *data;
	}

	printf("%d\n",average / 10);
	return 0;
}

練習問題 3-1
0～100の範囲で入力された複数の数値の中から、最大値と最小値を求めて表示するプログラムを作成せよ。
-1が入力された場合は入力の終わりと判定する。
ただし、最大値と最小値はmain関数以外の一つの関数の中で求める。
また、入力された数値を記憶する配列の要素数は10とし、それ以上入力された場合はエラーが起きても仕方ないこととする。
ヒント:配列の中に -1 があればデータの終わりだと判断できる。
ヒント:最小値を探すには、最大値を記憶した変数との比較を繰り返せば良い。 */

/*#include <stdio.h>
void maxmin(int num[],int max,int min);
int main(void)
{
  int i, num[10], max, min;

  for (i = 0; i < 10; i++) {
    scanf("%d", &num[i]);
    if (num[i] == -1){
      break;
    }
  }

  maxmin(num, &max, &min);
  printf("最大値%d\n", max);
  printf("最小値%d\n", min);
  return 0;
}

void maxmin(int num[],int max,int min) {
  *max = 0;
	*min = 100;
  for (int i = 0; i < 10; i++){
    if (num[i] < num[i + 1]) {
      max = num[i + 1];
    }
    if (num[i] > num[i + 1]) {
      min = num[i + 1];
    }
  }
}
*/

/* (解答例)

3-1 */
#include <stdio.h>

void maxmin(int array[],int max,int min);

int main(void)
{
	int i = 0,array[10],max,min;

	do {
		printf("%d 番目の数:",i + 1);
		scanf("%d",&array[i]);
		i++;
	} while (array[i - 1] != -1);

	maxmin(array,&max,&min);

	printf("最大値 %d : 最小値 %d\n",max,min);

	return 0;
}

void maxmin(int array[],int max,int min)
{
	int i = 0;

	*max = 0;
	*min = 100;

	while (array[i] != -1) {
		if (array[i] > max) max = array[i];
		if (array[i] < min) min = array[i];
		i++;
	}
}