/* **まとめてデータを扱いたい場合**
複数の異なる型の変数を1つにまとめて取り扱う方法として、**構造体**という機能が用意されています。
student という構造体タグ名
struct student {
	int year; 学年
  // C++ でclassという予約語がある為、clasになっている。
	int clas; クラス
	int number; 出席番号
	char name[64]; 名前
	double stature; 身長
	double weight; 体重
};
構造体の型を宣言する時には、始めに**struct(ストラクト)**をつけます。
その次には、変数と同じルールの元、新しく宣言する構造体の型名をつけます。この型名を特に、**構造体タグ名**と呼ぶことがあります。

実際に使うには、構造体の型の変数を宣言。構造体の型の変数を宣言するには、次のようにします。

struct student data;

この例では、student構造体タグの、data構造体変数を宣言しています。構造体タグの変数を宣言する場合、始めにstructをつけます。
次に、構造体の型名、最後に、構造体変数の名前を指定します。
今後、構造体の型を構造体タグ、構造体タグで宣言された変数を構造体変数と呼びます。

構造体変数の比較
構造体変数は、それ自体を1つの変数として使えると説明しましたが、残念ながら、構造体変数同士での演算や比較は行えません。

構造体タグを、新しい型として1度に宣言してしまう方法があります。

C言語では、新しい型を宣言するtypedef(タイプデフ)が用意されています。typedefを使うと新しい型を宣言出来ます。

**typedef 新しい型の形 新しい型名**
これを利用すると、構造体タグを直接**新しい型**に出来ます。次のプログラムは、構造体タグを元に新しい型を作る例です。

struct student_tag {
	int year; 学年
	int clas; クラス
	int number; 出席番号
	char name[64]; 名前
	double stature; 身長
	double weight; 体重
};

構造体型 student型
typedef struct student_tag student;

この例では、student＿tagタグを、student型にすることが出来ます。こうすれば、構造体変数を宣言する時に、structが不要になります。
今後、先ほどの方法で宣言された型を、構造体型と呼ぶことにします。

構造体タグと構造体型を1度に宣言してしまうことが出来ます。
typedef struct student_tag {
	int year;  学年
	int clas;  クラス
	int number;  出席番号
	char name[64];  名前
	double stature;  身長
	double weight;  体重
} student;

更に、この場合、新しい型を定義出来れば、**構造体タグを省略**できます。
typedef struct {
	int year; 学年
	int clas; クラス
	int number; 出席番号
	char name[64]; 名前
	double stature; 身長
	double weight; 体重
} student;

この方法が、1番簡潔に構造体型を宣言することが出来ます。 */