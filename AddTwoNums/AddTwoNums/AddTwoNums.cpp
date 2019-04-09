// AddTwoNums.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
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

int _tmain(int argc, _TCHAR* argv[])
{
	ListNode *p1 = new ListNode(2);
	ListNode *p2 = new ListNode(4);
	ListNode *p3 = new ListNode(3);
	ListNode *q1 = new ListNode(5);
	ListNode *q2 = new ListNode(6);
	ListNode *q3 = new ListNode(4);
	ListNode *l1 = new ListNode(0);
	ListNode *l2 = new ListNode(0);
	l1 = p1;
	l1->next = p2;
	l1->next->next = p3;
	cout<<"链表l1："<<endl;
	while(l1!=NULL)
	{
		cout<<l1->val<<endl;
		l1 = l1->next;
	}
	l2 = q1;
	l2->next = q2;
	l2->next->next = q3;
	cout<<"链表l2:"<<endl;
	while (l2!=NULL)
	{
		cout<<l2->val<<endl;
		l2 = l2->next;
	}
	ListNode *res = addTwoNumbers(l1,l2);
	cout<<"相加后："<<endl;
	while(res!=NULL)
	{
		cout<<res->val<<endl;
		res = res->next;
	}
	cin.get();
	return 0;
}

