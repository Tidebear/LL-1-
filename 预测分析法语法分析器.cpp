/*
                                              Ԥ������� 
=========================================================================================================
  ���ս��		                                       �������
=========================================================================================================								
		     (		 id	     num	       +	        -	      $	           )	    *	          /
    E		E->TE'	E->TE'	E->TE'						
    E'					               E->+TE'   E'->-TE'	E'->null	E'->null		
    T		T->FT'	T->FT'	T->FT'						
    T'					               T'->null	 T'->null	T'->null	T'->null	  T'->*FT'	  T'->/FT'
    F		F->(E)	F->id	F->num						
=========================================================================================================
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include"words_analysis.h"
#define STACK_INIT_SIZE 100						//��ջ�ĳ�ʼ�ռ������
int i=0; 
char token[50];
typedef struct SqStack{
	char elements[STACK_INIT_SIZE];				//�洢Ԫ������ 
	int top;
}SqStack;
SqStack s;
void InitStack(SqStack *s);						//��ʼ��ջ 
void push(SqStack *s,char e);					//ѹջ
void pop(SqStack *s,char *e);
void words_analysis();							//��ջ
bool Compare(char ch);
int main()              
{
	InitStack(&s);
	int j=0,k=0;								//j��k�ֱ�����ݴ����������������±� 
	char ch,input[50];
	printf("������Ҫ�жϵı��ʽ������;������\n"); 
	gets(input);								//�����ַ���input�ж� 
	words_analysis(input,token,j,k); 			//���ôʷ��������������ֺͱ�ʶ�������ж� 
	push(&s,'$');								//�Դ˰�'$'�ͷ��ս��Eѹջ 
	push(&s,'E');								 
	while(s.elements[s.top]!='$'){				//��ջ��Ϊ�գ���һֱ�Ƚ� 
		if(Compare(token[i])){}
		else{
			printf("����ı��ʽ��û����֮ƥ��ķ���");
			return 0;
		}
	}
	printf("��ȷ�ı��ʽ");
	return 0;
}

void InitStack(SqStack *s)						//��ʼ��ջ 
{
	s->top=-1;
}
void push(SqStack *s,char e)					//��ջ,����ջ��С 
{
	if(s->top==100-1)
	{	
		printf("ջ��\n");
	}
	s->elements[++s->top]=e;					//�������� 
}
void pop(SqStack *s)							//��ջ�������ж�ջ�Ƿ�Ϊ�� 
{
	if(s->top==-1)
	{
		printf("ջ��\n");
	}
	s->top--;
} 
bool Compare(char ch)				//ջ���ķ��Զ�����ջ�Ե����ϳ�ʼΪE,$ 
{
	if(ch==s.elements[s.top]){     //�����ű��е�ֵ��ջ�ڵ�ֵ������ջ 
		pop(&s);
		i++;
	}
	else if(s.elements[s.top]=='E'){	//s.elements[s.top]=='E',E'��e����ʾ 
		if(ch=='I'||ch=='N'||ch=='('){  //I����ʶ�� N������ ������Ԥ����������ʶ���ж� 
			pop(&s);
			push(&s,'e');
			push(&s,'T');
		}
		else{
			return false;
		}
	}
	else if(s.elements[s.top]=='e'){    //s.elements[s.top]=='e' 
		if(ch=='+'){
			pop(&s);
			push(&s,'e');
			push(&s,'T');
			push(&s,'+');
		}
		else if(ch=='-'){
			pop(&s);
			push(&s,'e');
			push(&s,'T');
			push(&s,'-');
		}
		else if(ch==')'||ch=='$'){
			pop(&s);
		}
		else{
			return false;
		}
	}
	else if(s.elements[s.top]=='T'){//s.elements[s.top]=='T' 
		if(ch=='I'||ch=='N'||ch=='('){
			pop(&s);
			push(&s,'t');
			push(&s,'F');
		}
		else{
			printf("�������쳣��"); 
			return false;
		}
	}
	else if(s.elements[s.top]=='t'){// s.elements[s.top]=='t'
		if(ch=='*'){
			pop(&s);
			push(&s,'t');
			push(&s,'F');
			push(&s,'*');
		}
		else if(ch=='/'){
			pop(&s);
			push(&s,'t');
			push(&s,'F');
			push(&s,'/');
		}
		else if(ch=='+'||ch=='-'||ch==')'||ch=='$'){
			pop(&s);
		}
		else{
			return false;
		}
	}
	else if(s.elements[s.top]=='F'){//s.elements[s.top]=='F' 
		if(ch=='I'){
			pop(&s);
			push(&s,'I');
		}
		else if(ch=='N'){
			pop(&s);
			push(&s,'N');
		}
		else if(ch=='('){
			pop(&s);
			push(&s,')');
			push(&s,'E');
			push(&s,'(');
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}




