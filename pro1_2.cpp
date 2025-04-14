//Yash Gohel-24CE035
//Program No:1.2
#include<iostream>
using namespace std;

class store{
    int ID;
    char name[200];
    int quantity,oquantity;
    int price,Total_price;

public:
    void getdata(){
        cout<<"\nEnter Your ID: ";
        cin>>ID;
         cout<<"Enter Your Name: ";
        cin>>name;
         cout<<"Enter The Quantity of the product: ";
        cin>>quantity;
         cout<<"Enter The price of the product: ";
        cin>>price;
    }
    void putdata(){
        cout<<"\nYour ID is: "<<ID<<endl;
        cout<<"\nYour Name is: "<<name<<endl;
        cout<<"\nThe quantity of product: "<<quantity<<endl;

        }
    void process(){
        cout<<"\nEnter the quantity you have want: "<<endl;
        cin>>oquantity;
        quantity=quantity+oquantity;
        Total_price=quantity*price;
        cout<<"The Total price is "<<Total_price<<endl;
    }



};
int main(){
    int n,i;
    cout<<"------>How many person are input The data: ";
    cin>>n;

    store I1[n];
    for ( i = 0; i < n; i++)
    {
        cout<<"\n For Person "<<(i+1);
        I1[i].getdata();
    }
    for ( i = 0; i < n; i++)
    {
        cout<<"\nFor Person "<<(i+1);
        I1[i].putdata();
    }
    int j,a;
    cout<<"If you want customize the purchese press 1 or 0";
    cin>>j;
    if(j==1){
    cout<<"Which person you want";
    cin>>i;
    for (i = 0; i < n; i++)
    {
        cout<<"\nFor Person "<<(i+1);
        I1[i].process();
    }
}
    else
    {
        cout<<"Thank You VISIT AGAIN...!!";
    }
}