#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void words_analysis(char *input ,char *token,int j,int k){      //������������ݴ������Լ���ʱ����j,kһ�𴫸��ʷ������� 
		while(input[k]!=';'){									//���ôʷ������� 
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
	token[j]='$';										//���ݴ���������һ���ַ���Ϊ'$' 
	printf("�ʷ��������ý����������﷨������\n");
}
