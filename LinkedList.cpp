#include<iostream>
using namespace std;

struct node{
	int number;
	struct node *pNext;
};

typedef struct node NODE;

struct list{
	NODE *pHead;
	NODE *pTail;
};

typedef struct list LIST;


void createList(LIST &l)
{
	l.pHead=NULL;
	l.pTail=NULL;
}

NODE *createNode(int x)
{
	NODE *temp=new NODE;
	temp->number=x;
	temp->pNext=NULL;
	return temp;
	
}

NODE addHead(LIST &l,NODE *temp)
{
	if(l.pHead==NULL)
	{
		l.pHead=l.pTail=temp;	
	}
	else
	{
		temp->pNext=l.pHead;
		l.pHead=temp;
	}
}
NODE addTail(LIST &l,NODE *temp)
{
	if(l.pHead==NULL)
	{
		l.pHead=l.pTail=temp;	
	}
	else
	{
		l.pTail->pNext=temp;
		l.pTail=temp;
	}
}
NODE outputList(LIST l)
{
	for(NODE *k=l.pHead;k!=NULL;k=k->pNext)
	{
		cout<<k->number<<"\n";	
	}
}
NODE add(LIST &l,NODE *temp)
{
	int x;
	cout<<"\nnhap nut p:";
	cin>>x;
	NODE *p=createNode(x);
	if(p->number==l.pHead->number && l.pHead->pNext==NULL)
	{
		addTail(l,temp);
	}
	else
	{
		for(NODE *k=l.pHead;k!=NULL;k=k->pNext)
		{
			if(p->number==k->number)
			{
				NODE *c=k->pNext;
				temp->pNext=c;
				k->pNext=temp;
			}
		}
	}
}


NODE addByvt(LIST &l,NODE *temp,int vt)
{
	int n=0;
	for(NODE *k=l.pHead;k!=NULL;k=k->pNext)
	{
		n++;
	}
	if(l.pHead==NULL||vt==1)
	{
		addHead(l,temp);
	}
	else if(vt==n+1)
	{
		addTail(l,temp);
	}
	else
	{
		int dem=0;
		
		for(NODE *k=l.pHead;k!=NULL;k=k->pNext)
		{
			dem++;
			if(dem==vt)
			{
				NODE *c=k->pNext;
				temp->pNext=c;
				k->pNext=temp;
			}
		
		}
	}
}

NODE delHead(LIST &l)
{
    if(l.pHead==NULL)
	{
		cout<<"\nDanh sach dang rong!!!";
	}
	else
	{
	 l.pHead=l.pHead->pNext;	
	}	
}

void delTail(LIST &l)
{
	if(l.pHead==NULL)
	{
		cout<<"\nDanh sach dang rong!!!";
	}
	else
	{
		for(NODE *k=l.pHead;k!=NULL;k=k->pNext)
		{
			if(k->pNext==l.pTail)
			{
				k->pNext==NULL;
				l.pTail=k;
			}
		}
	}
}

void delByvt(LIST &l,int vt)
{
	if(l.pHead==NULL)
	{
		cout<<"\nDanh sach lien ket dang rong";
	}
	int n=0;
	for(NODE *k=l.pHead;k!=NULL;k=k->pNext)
	{
		n++;
	}
	if(l.pHead!=NULL && vt==1)
	{
		delHead(l);
	}
	if(l.pTail!=NULL && vt==n+1)
	{
		delTail(l);
	}
	else
	{
		int c=0;
		for(NODE *k=l.pHead;k!=NULL;k=k->pNext)
		{
			c++;
			if(c==vt-1)
			{
				NODE *p=k->pNext;
				k->pNext=p->pNext;
				delete p;
			}
		}
	}
}

int findMax(LIST l)
{
	int max=l.pHead->number;
	for(NODE *k=l.pHead->pNext;k!=NULL;k=k->pNext)
	{
		if(max<k->number)
		{
			max=k->number;
		}
	}
	return max;
}

void Menu(LIST &l)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t =========== MENU ===========";
		cout << "\n1. Nhap du lieu node";
		cout << "\n2. Xuat danh sach lien ket";
		cout << "\n3. Them nut vao danh sach lien ket";
		cout << "\n4. Xoa node dau";
		cout << "\n5. Xoa node cuoi";
		cout << "\n6. Xoa node";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t ============================";

		int luachon;
		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon < 0 || luachon >6)
		{
			cout << "\nLua chon khong hop le";
			system("pause");
		}
		else if (luachon == 1)
		{
			int x;
			cout<<"\nnhap gia tri node : ";
			cin>>x;
			NODE *temp=createNode(x);
			addTail(l,temp);
		}
		else if (luachon == 2)
		{
			cout<<"\nxuat danh sach lien ket :";
			outputList(l);
			system("pause");
		}
		else if (luachon == 3)
		{
			int x,vt;
			cout<<"\nnhap gia tri nut can them : ";
			cin>>x;
			cout<<"\nNhap vi tri can them : ";
			cin>>vt;
			NODE *temp=createNode(x);
			addByvt(l,temp,vt);
			
		}
		else if (luachon == 4)
		{
			delHead(l);
			system("pause");
		}
		else if (luachon == 5)
		{
			delTail(l);
			system("pause");
		}
		else if (luachon == 6)
		{
			int vt;
			cout<<"\nnhap vi tri can xoa:";
			cin>>vt;
			delByvt(l,vt);
		}
		else
		{
			break;
		}
	}
}

int main()
{
	LIST l;
	createList(l);
	Menu(l);
	system("pause");
}
