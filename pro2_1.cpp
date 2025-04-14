//Yash Gohel-24CE035
//Program No:2.1
#include<iostream>
using namespace std;
class rectangle{
    float wid,len,area,perimeter;
public:
    void getdata(){
        cout<<"Enter The width of the rectangle\n";
        cin>>wid;
        cout<<"Enter The length of the rectangle\n";
        cin>>len;
    }
    void putdata(){
        cout<<"The width of the rectangle: "<<wid<<endl;
        cout<<"The length of the rectangle: "<<len<<endl;
    }
    void a(){
        area=wid*len;
        cout<<"The Area of The Rectangle is: "<<area<<endl;
    }
    void p(){
        perimeter=2*(wid+len);
        cout<<"The Perimeter of The Rectangle is: "<<perimeter<<endl;
    }

};
int main(){
    int n;
    cout<<"Enter The Numbers of rectangles: ";
    cin>>n;

    if(n==0){
        
        return 0;
    }
    rectangle R1[n];

    cout<<"Enter The Details of given: \n";
    for(int i=0;i<n;i++){
        cout<<"Enter "<<i+1;
        cout<<" Rectangle details:\n";
        R1[i].getdata();
    }

    cout<<endl;
    for(int i=0;i<n;i++){
         cout<<i+1;
        cout<<" Rectangle details:\n";
        R1[i].putdata();
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<i+1;
        cout<<" Rectangle details:\n";
        R1[i].a();
        R1[i].p();
    }

    cout<<endl;
    cout<<endl;
    int choice;
    cout<<"If you want add rectangle then Type 1||0 "<<endl;
    cin>>choice;

    if(choice==1){
        int a;
    cout<<"Enter The Numbers of rectangles: ";
    cin>>a;

    rectangle R2[a];

    cout<<"Enter The Details of given: \n";
    for(int i=0;i<a;i++){
        cout<<"Enter "<<i+1;
        cout<<" Rectangle details:\n";
        R2[i].getdata();
    }

    cout<<endl;
    for(int i=0;i<a;i++){
         cout<<i+1;
        cout<<" Rectangle details:\n";
        R2[i].putdata();
    }
    cout<<endl;
    for(int i=0;i<a;i++){
        cout<<i+1;
        cout<<" Rectangle details:\n";
        R2[i].a();
        R2[i].p();
    }
    }
    else{
        cout<<"THANK YOU VUSIT AGAIN!";
    }

}