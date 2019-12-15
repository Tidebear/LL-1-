#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void words_analysis(char *input ,char *token,int j,int k){      //把输入数组和暂存数组以及临时变量j,k一起传给词法分析器 
		while(input[k]!=';'){									//调用词法分析器 
		if(input[k]>='0'&&input[k]<='9'){
			token[j]='N';
			j++;
			k++;
			while(input[k]>='0'&&input[k]<='9'){
				k++;
			}
		}
		else if(input[k]>='a'&&input[k]<='z'){
			token[j]='I';
			j++;
			k++;
			while(input[k]>='a'&&input[k]<='z'){
				k++;
			}
		}
		else{
			token[j]=input[k];
			j++;
			k++; 
		}
	}
	token[j]='$';										//把暂存数组的最后一个字符置为'$' 
	printf("词法分析调用结束，进行语法分析：\n");
}
