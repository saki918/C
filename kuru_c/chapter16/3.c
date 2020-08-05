/* **構造体の配列**

構造体も配列にすることが出来ます。方法は今までと同様です。
次は、student型で10個の要素を持つ構造体変数の配列を宣言する例です。

student data[10];

練習問題 2-1
3人分の、名前、年齢、性別、を入力して表示するプログラムを作りなさい。
ただし、データは構造体で記憶することとし、
また、データの入力と表示はそれぞれ専用の関数を作って行うこととする。 */

#include <stdio.h>

typedef struct {
  char name[30];
  int sex;
  int age;
} human;

// ポインタ変数でデータの書き換え
void input(human *person);
void output(human);

int main(void)
{
  human person[3];
  int i;
  for (i = 0; i < 3; i++) {
    input(&person[i]);
    output(person[i]);
  }
  return 0;
}

void input(human *person) {
  printf("名前を入力してください。");
  scanf("%s", person->name);
  printf("性別を数字で入力してください。男性は１、女性は２：");
  scanf("%d", &person->sex);
  printf("年齢を入力してください。");
  scanf("%d", &person->age);
}

void output(human person) {
  char *seibetu[10];
  printf("名前：%s\n", person.name);
  switch (person.sex) {
  case 1:
    *seibetu = "男性";
    break;
  case 2:
    *seibetu = "女性";
    break;
  }
  printf("性別：%s\n", *seibetu);
  printf("年齢：%d 歳\n", person.age);
}