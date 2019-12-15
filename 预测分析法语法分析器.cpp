/*
                                              预测分析表 
=========================================================================================================
  非终结符		                                       输入符号
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
#define STACK_INIT_SIZE 100						//给栈的初始空间分配量
int i=0; 
char token[50];
typedef struct SqStack{
	char elements[STACK_INIT_SIZE];				//存储元素数组 
	int top;
}SqStack;
SqStack s;
void InitStack(SqStack *s);						//初始化栈 
void push(SqStack *s,char e);					//压栈
void pop(SqStack *s,char *e);
void words_analysis();							//出栈
bool Compare(char ch);
int main()              
{
	InitStack(&s);
	int j=0,k=0;								//j和k分别代表暂存数组和输入数组的下标 
	char ch,input[50];
	printf("输入你要判断的表达式并且以;结束：\n"); 
	gets(input);								//输入字符串input判断 
	words_analysis(input,token,j,k); 			//调用词法分析器，对数字和标识符进行判断 
	push(&s,'$');								//以此把'$'和非终结符E压栈 
	push(&s,'E');								 
	while(s.elements[s.top]!='$'){				//当栈不为空，就一直比较 
		if(Compare(token[i])){}
		else{
			printf("错误的表达式，没有与之匹配的符号");
			return 0;
		}
	}
	printf("正确的表达式");
	return 0;
}

void InitStack(SqStack *s)						//初始化栈 
{
	s->top=-1;
}
void push(SqStack *s,char e)					//进栈,设置栈大小 
{
	if(s->top==100-1)
	{	
		printf("栈满\n");
	}
	s->elements[++s->top]=e;					//返回自身 
}
void pop(SqStack *s)							//出栈，并且判断栈是否为空 
{
	if(s->top==-1)
	{
		printf("栈空\n");
	}
	s->top--;
} 
bool Compare(char ch)				//栈按文法自顶向下栈自底向上初始为E,$ 
{
	if(ch==s.elements[s.top]){     //若符号表中的值与栈内的值相等则出栈 
		pop(&s);
		i++;
	}
	else if(s.elements[s.top]=='E'){	//s.elements[s.top]=='E',E'用e来表示 
		if(ch=='I'||ch=='N'||ch=='('){  //I：标识符 N：数字 ，按照预测分析表进行识别判断 
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
			printf("运算数异常！"); 
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




