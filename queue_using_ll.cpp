#include<iostream>
using namespace std;
//class for circles which will be connected
class circle{
	
	public:	//data part
	int radius;	
	//pointer part for forward linking
	circle *next;
	//constructr
		circle()
		{next=NULL;	}
		
	};
class link{  public:
		//for head part of linked list 
		circle *head;
		circle *tail;
	//constructr for making head null initialy
	link(){head=NULL;}
	//a.insert function
	void insert(int length);
	//b.insert at specific position func
	void insertAT(int pos,int length);
	//c.delete funcn
	void del();
	//d.delete at specific position
	void delAT(int pos);
	//e.display
	void display();
	//f.count no of items in the linked list
	int countITEMS();

	};
void link::insert(int length)
{ circle *temp=new circle;//new space for a circle in heap
	temp->radius=length;
	//for first node
	if(head==NULL)
	{head=temp;}
	else{ tail->next=temp;}	
	tail=temp;
}
void link::del()
{circle *temp=tail;//storing tail addrss in temp
	circle *current=head;
	while(current->next!=tail)
	{current=current->next;}
	//updating tail
	tail=current;
	current->next=NULL;
	delete temp;

}
void link::display()
{ circle *print=head;
	while(print!=NULL)
	{cout<<print->radius<<"->";
		print=print->next;
	}
cout<<endl;

}
void link::insertAT(int pos,int length)
{ circle *temp=new circle;//new heap alloacation for circle
		temp->radius=length;
		//go to position before pos in linklist
	circle *go=head;
	if(pos!=1){
	for(int i=1;i<pos-1;i++)
	{go=go->next;}
	temp->next=go->next;
	go->next=temp;
		}
	else{
		temp->next=head;
		head=temp;	}	

}
void link::delAT(int pos){
	//go to position -1
	if(pos!=1){
	circle *go=head;
	circle *go1=head;	
	for(int i=1;i<pos-1;i++)
	{go=go->next;go1=go;}
	circle* temp;
	temp=go->next;
	go1=go1->next;
	go->next=go1->next;
	delete temp;
	}
	else{
	circle* temp=head;
	head=head->next;
	delete temp;
	
	}

}
int link::countITEMS(){ 
	if(head!=NULL){int count=0;circle* current=head;
	while(current!=NULL)
	{count++;
	 current=current->next;}
	return count;}
	else return 0;
}
//////////////////////////////////////////////////////////////////
class QueueLL{
	public:
	link l1;
	//pointer pointing front
	circle * front;
	//pointer pointing end of queue
	circle * end;
	//consttrttr
	QueueLL(){front=NULL;end=NULL;}
	// queue is for fifo data management so....
	//enqueue, dequeue, size, isEmpty, top)
	//enqueue ::insertion at end
	void enqueue(int value){
		l1.insert(value);//use this ll funcn
		front=l1.head;
		end=l1.tail;

	}
	void shew(){
		l1.display();
	}
	void dequeue(){
		//deletion from front bcz fifo
		if(front!=NULL){
		l1.delAT(1);
		front=l1.head;	}
		else
		cout<<"nothing to delete"<<endl;	
	}

};

int main(){ QueueLL q1;
	for(int i=1;i<11;i++)
	q1.enqueue(i);
	q1.shew();
	q1.dequeue();
	q1.dequeue();
	q1.shew();
q1.dequeue();
	q1.dequeue();
q1.dequeue();
	q1.dequeue();
q1.dequeue();
	q1.dequeue();
q1.dequeue();
	q1.dequeue();
q1.dequeue();
	q1.dequeue();
q1.dequeue();
	q1.dequeue();
q1.dequeue();
	q1.dequeue();



}
