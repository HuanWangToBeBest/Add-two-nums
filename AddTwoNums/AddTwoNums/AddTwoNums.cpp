// AddTwoNums.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#include <stdlib.h>  
#include <malloc.h> 
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode * node= new struct ListNode(0) ;

        struct ListNode *p=l1,*q=l2,*root=node;

        int carry=0;
        while (p!=NULL || q!= NULL)

        {

            int x=(p==NULL)?0:p->val;

            int y=(q==NULL)?0:q->val;
            int result=x+y +carry;

            carry=result/10;
            node->next= new struct ListNode (result %10);

            node =node->next;
           if (p!=NULL) p=p->next;

           if (q!=NULL) q=q->next;

        }

       if (carry>0)
		   
	   {node->next=new struct ListNode(carry);}
        return root->next;
    }
	ListNode* createList(ListNode* pHead,bool flag){
    ListNode* p = pHead;
	p->next = NULL;
	int a[] = {5,6,4};
	int b[] = {2,4,3};
    for (int i = 1; i < 3; ++i) {
        ListNode* pNewNode = new ListNode(0);
		if(flag)
	    {
		   pNewNode->val = a[i]; // ���½ڵ��ֵ��ֵΪi
	    }
		else
		{
			pNewNode->val = b[i]; // ���½ڵ��ֵ��ֵΪi
		}
        p->next = pNewNode; // ��һ���ڵ�ָ������½����Ľڵ�
		pNewNode->next = NULL;
        p = pNewNode; // p�ڵ�ָ������µĽڵ�
    }
	
	return p;
	}

int _tmain(int argc, _TCHAR* argv[])
{
	
    ListNode* head = new ListNode(0);
    ListNode* tail = new ListNode(0);
	ListNode* l1 = createList(head,true);
	cout<<"head��"<<endl;
	while (head!=NULL)
	{
		cout<<head->val<<endl;
		head = head->next;
	}
	ListNode* l2 = createList(tail,false);
	cout<<"tail��"<<endl;
	while (tail!=NULL)
	{
		cout<<tail->val<<endl;
		tail = tail->next;
	}
	ListNode *res = addTwoNumbers(l1,l2);
	cout<<"��Ӻ�"<<endl;
	while (res!=NULL)
	{
		cout << res->val<<endl;
		res = res->next;
	}
	cin.get();
	return 0;
}

