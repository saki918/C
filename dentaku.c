#include <stdio.h>
#include <string.h>
int main()
{
  char str[100];
  char sign[1];
  int a, b;
	printf("演算します。式を入力してください> ");
  fgets(str, sizeof(str), stdin);
  sscanf(str, "%d %[+-*/] %d", &a, sign, &b);
  if (strcmp(sign,"+") == 0) {
    printf("%d\n", a + b);
  } else if (strcmp(sign,"-") == 0) {
    printf("%d\n", a - b);
  } else if (strcmp(sign,"*") == 0) {
    printf("%d\n", a * b);
  } else if (strcmp(sign,"/") == 0) {
    printf("%d\n", a / b);
  }
  return 0;
}