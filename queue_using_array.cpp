#include<iostream>
using namespace std;
class queueARR{ public:
    //data storage in array
    int arr[1000];
    //front and end pointers
    int * front;
    int *end;
    //constructor
    queueARR(){front=NULL;end=NULL;}
    //functions (enqueue, dequeue, size, isEmpty,display)
    bool isEmpty(){
            if(front==NULL){
                return true;
            }
            else return false;
    }
    //enqueue
    void enqueue(int value){
                if(front ==NULL){
                    front=arr;
                    end=arr;
                    *front=value;
                }
                else{
                    end++;
                    *end=value;
                }
        }
    void display(){
                int * temp=front;
                if(temp ==NULL)cout<<"q is empty"<<endl;
                else { while(temp!=end){
                        cout<<*temp<<"->";
                        temp++;
                            }
                          cout<<*temp;
                            cout<<endl;
                }
    }
    //deletion occurs from end of q
    void dequeue(){
        if(front==NULL)cout<<"nothing to delete"<<endl;
        else if(front==end){cout<<"u are deleting last element"<<endl;front=NULL;}
        else front++;
    }

};
int main(){
            queueARR q1;
            for(int i=1;i<6;i++)
                q1.enqueue(i);
                q1.display();
                q1.dequeue();
                q1.display();
                q1.dequeue();
                q1.display();
                                q1.enqueue(23);
                                                q1.enqueue(34);

                                                q1.display();




}
