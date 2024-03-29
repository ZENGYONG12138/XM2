#include <iostream>
#include <Windows.h>

using namespace std;

/*
        i   
		   j
       k1 k2
       123 45 678'\0'
       
最终 678 45 123
方法1                        方法2
初步 876 54 321        第一步：321 54 876
        678 45 123       第二步：678 45 123

*/

int main(void) {
	char str[256];
	int i = 0;

	cout << "请输入一句话(英文)：";
	gets_s(str, sizeof(str));
	
	while (str[i]) {
		//跳过前面的空格
		//该循环结束后，str[i]是下一个单词的第一个字母
		while (str[i] == ' ') i++;
        
		int j = i;
		//该循环结束之后，str[j]是这个单词后面的下一个位置
		while (str[j] && str[j] != ' ') j++;

		//逆转这个单词
		for (int k1 = i, k2 = j - 1; k1 < k2; k1++, k2--) {
			char tmp = str[k1];
			str[k1] = str[k2];
			str[k2] = tmp;
		}

		i = j; 
	}

	for (int k1 = 0, k2 = i - 1; k1 < k2; k1++, k2--) {
		char tmp = str[k1];
		str[k1] = str[k2];
		str[k2] = tmp;
	}

	cout << str << endl;

	system("pause");
	return 0;
}