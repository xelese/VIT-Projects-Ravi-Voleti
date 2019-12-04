#include <iostream>

using namespace std;
int i;
struct job{
string jb_title[10],file_type[10],author[10];
int stk[10],f = -1,r = -1;
} j;

void enq(int item,string ti,string fi,string au){

    if(j.f-j.r>=4){
        cout<<"\nque full";
    }
    else if(j.f == -1 and j.r == -1){
        j.f = 0;
        j.r = 0;
        j.stk[j.f] = item;
        j.jb_title[j.f] = ti;
        j.file_type[j.f] = fi;
        j.author[j.f] = au;
        ////cout<<j.f;
//cout<<j.r;
    }
    else{
        j.f+=1;
        j.stk[j.f] = item;
        //cout<<j.f;
        //cout<<j.r;
    }
}

void deq(){
    if(j.r ==-1 and j.f == -1){
        cout<<"\nque empty";
    }
    else if(j.r > j.f){
        cout<<"\nque empty";
    }
    else if(j.r == j.f){
        j.f = -1;
        j.r = -1;
        cout<<"\ndequed";
        //cout<<j.f;
        //cout<<j.r;
    }
    else{
        j.r+=1;
        cout<<"\ndequed";
        //cout<<j.f;
        //cout<<j.r;
    }
}

void display(){
    if(j.r<=j.f){
        for(i = j.r;i<=j.f;i++){
            cout<<j.stk[i];cout<<"\n";
            cout<<j.jb_title[i];cout<<"\n";
            cout<<j.file_type[i];cout<<"\n";
            cout<<j.author[i];cout<<"\n";
        }
    }
    else{
        cout<<"\nerror in printing";
    }
}

int main()
{
    string ti,fi,au;
   int item,choice,ch;
   do{
        cout<<"1.enqueue\t2.dequeue\t3.display\n";
        cout<<"\nwhat do you want to do:";
        cin>>ch;
        switch(ch){
            case 1: cout<<"\nenter the size: ";
                    cin>>item;
                    cout<<"\nenter the title: ";
                    cin>>ti;
                    cout<<"\nenter the file_type: ";
                    cin>>fi;
                    cout<<"\nenter the author: ";
                    cin>>au;
                    enq(item,ti,fi,au);
                    break;
            case 2: deq();
                    break;
            case 3: display();
                    break;
        }
        cout<<"\ndo you want to continue?";
        cin>>choice;
   }while(choice == 1);
 return 1;
}
