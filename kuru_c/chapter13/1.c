/* **複数の変数をまとめて扱う**
配列 >>> 同じ型の変数を複数宣言し、番号によって管理することで、複数のデータを一括して取り扱えるようにする仕組み。

**初期値の代入**
配列も、今までの変数と同様に、宣言と同時に初期化することが出来ます。
配列の初期化は、次のようにして行います。

**型名 配列名[要素数]={0番の数値,1番の数値,2番の数値,･･･};**

**要素数を求める**
配列全体のサイズを求め、それを要素1つのサイズで割れば要素の数がわかります。
C言語には、変数や配列のサイズを求める**sizeof(サイズオブ)演算子**があります。
sizeof演算子は、次のようにして使います。

sizeof(変数や配列名)

演算子を使って配列arrayの要素数を求めるには次のようにします。

sizeof(array) / sizeof(array[0])

※ 上の要素数を求める式をfor文に記述しても良いが、ループの度に毎回計算してしまうので（無駄な処理が発生）
int count = sizeof(array) / sizeof(array[0]);
とmain関数内で定義すると毎回計算させなくて済む。

**配列のコピー**
for文を使わなくても、**memcpy関数**を使うことが出来ます。
なお、memcpy関数を使うには、memory.h ファイルを #include する必要があります。

memcpy(コピー先配列名､コピー元配列名、配列全体のサイズ)

memcpy(array2,array1,sizeof(array1));  array1 の全要素を array2 にコピー

練習問題 3-1
入力された10個の数値を最後から表示するプログラムを作成せよ。 */

#include <stdio.h>

int main(void)
{
  int i;
  int array[10];
  int count = sizeof(array) / sizeof(array[0]);
  for (i = 0; i < count; i++) {
    scanf("%d", &array[i]);
  }

  for (i = 9; i >= 0; i--) {
    printf("array[%d]:%d\n", i, array[i]);
  }
  return 0;
}