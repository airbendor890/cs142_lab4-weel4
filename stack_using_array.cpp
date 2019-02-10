#include<iostream>
using namespace std;
class stackARR{
    public:
        //top pointer
        int *top;
        //constructor
        stackARR(){top=NULL;}
        //array elements
        int arr[100];
        //push
        void push(int value){
            if(top==NULL){
                arr[0]=value;
                top=arr;
            }
            else{
                *(top+1)=value;
                top++;
            }
        }
        //pop function
        void pop(){
            if(top==NULL)cout<<"empty_stack"<<endl;
            else if(top==arr){cout<<"u deleted last element"<<endl;top=NULL;}
            else top--;
        }
        //shew
        void shew(){
             int * temp=top;
             if(temp==NULL)cout<<"empty_stack"<<endl;

             else{
                while(temp!=arr){
                    cout<<*temp<<"->";
                    temp--;
                }
                    cout<<*temp<<"->";
             }

            cout<<endl;
        }


};
int main(){
            stackARR s1;
            for(int i=1;i<11;i++)
                s1.push(i);
           s1.shew();
           s1.pop();
           s1.shew();
           s1.pop();
           s1.shew();
           s1.push(46);
           s1.shew();
           s1.pop();
           s1.pop();
           s1.pop();
           s1.shew();
           s1.pop();
           s1.shew();
           s1.pop();
           s1.pop();
           s1.shew();
           s1.pop();
           s1.pop();
           s1.shew();
           s1.pop();
            s1.pop();
            s1.pop();
            s1.pop();
           s1.shew();
           for(int i=3;i<8;i++)
            s1.push(i);
           s1.shew();
           cout<<"hello"<<endl;
            return 0;
    }

