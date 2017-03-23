#include<iostream>
#include<strstream>
#include<string>
#define type string
#include<windows.h>
#include<stdio.h>
using namespace std ;
template<class T>
class linked_list
{
public:
	T a;
	linked_list *next;
	linked_list():next(NULL),a(NULL){}
};
template<class T>
bool is__empty(linked_list<T> *&list)
{
	if(list == NULL)
		return true;
	else
		return false;
}
template <class T>
bool insert(linked_list<T> *&list,T item)
{
	linked_list<T> *new_item = new linked_list<T>;
	if(new_item==NULL)
	{
		cout << "Error allocating memory"<<endl;
		return false ;
	}
	else
	{
		new_item->a=item;
		new_item->next = list ;
		list = new_item;
		return true;
	}
}
template<class T>
bool insert(linked_list<T> *&list,T item,int loc)
{
	linked_list<T> *new_item = new linked_list<T>,*top=list;
	if(new_item==NULL)
	{
		cout << "Error allocating memory"<<endl;
		return false ;
	}
	else
	{
		if(loc==0)
		{
			new_item->a=item;
			new_item->next=list;
		list =new_item;
		return true ;
		}
		int i=0;
		while(i<loc &&top!=NULL&&top->next!=NULL)
		{
			top=top->next;
			++i;
		}
		if((top==NULL)||((top->next==NULL)&&(i==loc)))
		{
			cout << "INVALID LOCATION FOR INSERTION " <<endl;
			//Sleep(10);
			return true;
		}
		new_item->a=item;
		new_item->next = top->next ;
		top->next = new_item;
		return true;
	}
}
template <class T>
bool _delete(linked_list<T> *&list)
{
	if(is__empty(list)==true)
	{
		cout << "Cannot Delete !!!"<<endl<<"List Empty"<<endl;
		return false ;
	}
	else
	{
		linked_list<T> *ptr = list ;
		cout << ptr->a << " IS BEING DELETED " <<endl ;
		//Sleep(1000) ;
		list=list->next ;
		delete ptr ;
		return true ;
	}
}
template<class T>
bool _delete(linked_list<T> *&list,int loc)
{
	if(is__empty(list)==true)
	{
		cout << "Cannot Delete !!!"<<endl<<"List Empty"<<endl;
		return false ;
	}
	else
	{
		int i=0;
		linked_list<T> *ptr = list ;
		if(loc==0)
		{
			cout << ptr->a << " IS BEING DELETED " <<endl ;
		//Sleep(1000) ;
		list=list->next ;
		delete ptr ;
		return true ;
		}

		while (i<(loc-1) &&ptr!=NULL&& ptr->next!=NULL&& ptr->next->next!=NULL)
		{
			ptr=ptr->next;
			++i;
		}
		if((i!=(loc-1))&&(ptr==NULL||ptr->next==NULL||ptr->next->next==NULL))
		{
			cout <<"INVALID LOCATION FOR DELETION " <<endl;
			//Sleep(1000);
			return true;
		}
		if(ptr->next!=NULL)
		{
		cout << ptr->next->a << " IS BEING DELETED " <<endl ;
		linked_list<T> *tmp=ptr->next;
		ptr->next=ptr->next->next;
		//Sleep(1000) ;
		delete tmp ;
		}
		return true ;
	}
}
template<typename T>
linked_list<T>* search(linked_list<T> *&list,T item)
{
	linked_list<T> l=list;
	while(l!=NULL)
	{
		if(l->a==item)
			return l;
	}
	return NULL;
}
template<typename T>
linked_list<T>* next(linked_list<T> *&list)
{
	list = list->next ;
	return list->next ;
}
template<typename T>
struct vertex
{
	T data ;
	int status;
	int index;
	linked_list< vertex<T> *> *list ;
	vertex<T> *p;
	vertex():list(NULL),p(NULL){}
};
template<typename T>
bool dfs_visit(linked_list<vertex<T>*> *&graph,vertex<T> *&u,linked_list<vertex<T>*> *&V)
{
	u->status = 1 ;
	linked_list< vertex<T>* > *temp = u->list ;
	while(temp!=NULL)
	{
		if(temp->a->status == 0)
			dfs_visit<T>(graph,temp->a,V);
		temp = temp->next ;
	}
	u->status=2;
	insert(V,u);
	return true ;
}
template<typename T>
bool depth_first_search(linked_list<vertex<T>*> *&graph,linked_list<vertex<T>*> *&V)
{
	linked_list<vertex<T>*> *temp = graph ;
	while(temp!=NULL)
	{
		temp->a->status = 0 ;
		temp = temp -> next;
	}
	temp = graph ;
	while(temp != NULL)
	{
		if ( temp->a->status == 0 )
			dfs_visit<T>(graph,temp->a,V);
		temp=temp->next ;
	}
	return true ;
}
int graph_main()
{
	cout << "Enter all vertices of graph"<< endl;
	strstream stre;
	int i=1;
	type s;
	char str[256];
	bool loop  = true;
	gets(str);
	stre << str ;
	linked_list< vertex<type>* > *graph=NULL,*temp,*temp2 ,*temp3;
	vertex<type> *v ,vtemp;
	while(!stre.eof())
	{
		v= new vertex<type>;
		stre >> s ;
		v->data= s ;
		v->index=i;
		insert(graph,v);
		++i;
	}
	temp  = graph;
	temp2 = graph->a->list;
	cout << "To skip adjacency list of any vertex enter 0 when asked to enter adjacency list ." << endl ;
	for(int j=1;j<i;j++)
	{
		bool found = false;
		stre.clear();
		cout << "Enter adjacency list of " << temp->a->data <<endl ;
		gets(str);
		if(str[0]!='0')
		{
		stre << str ;
		while ((!stre.eof()))
		{
			stre >> s ;
			temp3 = graph ;
			while(temp3!=NULL)
				{
					if((temp3->a->data) == s )
					{
						found = true ;
						insert(temp->a->list,temp3->a);
						temp3 = NULL ;
					}
					else
					{
						temp3 = temp3 -> next ;
					}
				}
			if(found == false )
			{
				cout << "INVALID INPUT " << s << endl ;
				cout << "ENTER THE adjacency list of " << temp->a->data << " after " << s << endl ;
				stre.clear();
				gets(str) ;
				stre << str ;
			}
		}
		}
		temp = temp->next;

	}
	cout<<"\nAdjacency list\n";
	temp = graph ;
	temp2 = graph->a->list;
	while(temp!=NULL)
	{
		cout << temp ->a->data << "  ---  "  ;
		while(temp2!=NULL)
		{
			cout << temp2->a->data << " ";
			temp2=temp2->next ;
		}
		cout << endl ;
		temp = temp->next;
		if(temp!=NULL)
		temp2 = temp->a->list ;
	}
	cout << "TOPOLOGICAL SORT RESULT" << endl ;
	linked_list<vertex<type>*> *my_list = NULL ,*my_list_temp;
	depth_first_search<type>(graph,my_list);
	my_list_temp = my_list ;
	for(int j = 1 ; j < i ; j++)
	{
		cout << "   "<< my_list_temp->a->data << endl ;
		my_list_temp = my_list_temp ->next ;
	}
	system("pause");
	return 0;
}
