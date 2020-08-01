/* **番号と対応させる処理**
switch(スイッチ)文～case(ケース)を使うと美しく書くことができます。
switch文～caseの使い方は、次の通りです。

#include <stdio.h>
int main (void)
{
  int no;
  scanf("%d",&no);
  switch (no) {
    case 1:
      printf("野比のび太\n");
      break;
    case 2:
      printf("源静香\n");
      break;
    case 3:
      printf("剛田武\n");
      break;
    case 4:
      printf("骨川スネ夫\n");
      break;
    このように、他のcaseの値に当てはまらない場合に処理を実行させるには、
    default(デフォルト)を使用することができます。
    defaultは、case文の代わりとして使うことができます。
    default:
      printf("そんな番号の人はいない\n");
      break;
  }
  return 0;
}

実は、caseは、複数を連続させて使うことが可能です。
case自体には、switch文でジャンプする場所を示す意味しか無いので、
caseを**複数**つなげても、実行内容には影響がありません。

switch文～caseにおいて、caseにおくことができるのは**整数値**だけです
switch文～caseは、**変数と整数値**の比較にしか使うことができません。
複雑な判断が必要な場合には、if文を使う以外には方法がありません。

3-1
月を入力すると、対応する陰暦の月を表示するプログラムを作成せよ。
なお、存在しない月を入力した時にも何かのメッセージを表示せよ。
ヒント:陰暦は1月から順番に、
睦月,如月,弥生,卯月,皐月,水無月,文月,葉月,長月,神無月,霜月,師走*/

#include <stdio.h>

int main(void)
{
  int month;
  printf("検索したい陰暦の月を入力してください：");
  scanf("%d", &month);
  switch (month) {
    case 1:
      printf("睦月\n");
      break;
    case 2:
      printf("如月\n");
      break;
    case 3:
      printf("弥生\n");
      break;
    case 4:
      printf("卯月\n");
      break;
    case 5:
      printf("皐月\n");
      break;
    case 6:
      printf("水無月\n");
      break;
    case 7:
      printf("文月\n");
      break;
    case 8:
      printf("葉月\n");
      break;
    case 9:
      printf("長月\n");
      break;
    case 10:
      printf("神無月\n");
      break;
    case 11:
      printf("霜月\n");
      break;
    case 12:
      printf("師走\n");
      break;
    default:
      printf("入力した数値の月は存在しません。\n");
      break;
  }

  return 0;
}

