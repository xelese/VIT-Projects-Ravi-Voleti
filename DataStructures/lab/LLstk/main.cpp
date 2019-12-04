#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};
node *top=NULL;

void push(int stkitem){
    node *temp=new node();
    temp->data=stkitem;
    if(top==NULL)
        top=temp;
    else{
        temp->next=top;
        top=temp;
    }
}

void pop(){
    node *temp=top;
    top=top->next;
    cout<<"The popped value is: "<<temp->data<<"\n";
    delete(temp);
}
void display(){
    node *temp=top;
    while (temp!=NULL){
        cout<<temp->data<<"\n";
        temp=temp->next;
    }
}

main(){
    cout<<"1.push\t";
    cout<<"2.pop\t";
    cout<<"3.Display\n";
    int ch=0;int stkitem;
    do{
        cout<<("What do you want to do?:");
        cin>>ch;
        switch (ch){
            case 1:
            cout<<"Enter the value: ";
            cin>>stkitem;
            push(stkitem);
            break;
            case 2:
            pop();
            break;
            case 3:
            cout<<"status: \n";
            display();
            break;
        }
    }while(ch>0&&ch<4);
}
