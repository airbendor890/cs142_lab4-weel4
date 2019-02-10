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
/*-----------------------------------------------------------------------------------*/
class StackLL{
	public:
	link l1;
	circle * top;
	StackLL(){top=NULL;}//initializing top to null through const
	//push an element on top of stack
	void push(int length){
		//pos,length:pos=1:
		l1.insertAT(1,length);
		top=l1.head;
	}
	//pop an element from top
	void pop(){//pos=1:
		if(top==NULL)cout<<"nothing to delete"<<endl;
		else
		l1.delAT(1);
		top=l1.head;
	}
	//finding size of stack
	int size(){ if(top==NULL)return 0;
		else return l1.countITEMS();
		}
	bool ISempty(){
	if(top==NULL)return true;
	else return false;
	}
	//show stacks function
	void show(){
		circle* temp=top;
		while(temp!=NULL){
			cout<<temp->radius<<"->";
			temp=temp->next;
		}
	cout<<endl;
	}


};
class queue_stack{public:
    //two stacks will be used
    StackLL s1,s2;
    //s1 main stack,s2 backup stack
    //pointers of queue
    circle *front;circle *end;
    //constructor
   // public:
    queue_stack(){front=NULL;end=NULL;}
    //functions enqueue, dequeue, size, isEmpty;
    void enqueue(int value){//insertion from end in q
        if(front==NULL){
            s1.push(value);
            front=s1.top;
            end=s1.top;
        }
        else{ s1.push(value);
                end=s1.top;
        }

    }
    //dequeue deletion from front in Q
    //USE of backup stack
	//--------------------------------------------------------------
    void dequeue(){
       if(front==NULL){cout<<"queue is empty"<<endl;}
        else{//fierst store in backup stack
             while(end!=front){
                s2.push(end->radius);
                s1.pop();
		//update end pointer otherwise infinite loop
		end=s1.top;
                		}
                s1.pop();
		end=NULL;
		front=NULL;
                //now restore from backup stack
		 circle* temp=s2.top;
             		  while(temp!=NULL){
	        //backup should imitate enqueue funcn otherwise end and front will be rogue pointers
				 if(front==NULL){
                    		  	s1.push(temp->radius);
					front=s1.top;end=s1.top;}
				 else{s1.push(temp->radius);
						//update end as in enqueue
						end=s1.top;}
                 		  s2.pop();
				  //update temp
				  temp=s2.top;
        				     }

        		  }	
	
		
  }
//---------------------------------------------------------------------------

    void disp()
    {	if(front==NULL)cout<<"Q is empty"<<endl;
	else
	s1.show();}

};
//-----------------------------main
int main(){ queue_stack q1;
    for(int i=1;i<8;i++)
        q1.enqueue(i);
        q1.disp();
        q1.dequeue();
        q1.disp();
        q1.dequeue();
        q1.disp();
	for(int i=9;i<12;i++)
	q1.enqueue(i);
	q1.disp();
	q1.dequeue();
	q1.disp();
	q1.dequeue();
	q1.disp();
q1.dequeue();
q1.dequeue();
q1.dequeue();
q1.dequeue();
q1.disp();
q1.dequeue();
q1.disp();
q1.dequeue();
q1.disp();
q1.dequeue();
	for(int i=1;i<5;i++)
		q1.enqueue(i);
		q1.disp();
		q1.dequeue();
	q1.disp();
	q1.enqueue(5);
	q1.disp();
	q1.dequeue();
	q1.disp();
}












