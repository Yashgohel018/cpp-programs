//Yash Gohel-24CE035
//Program No:4.5
#include<iostream>
#include<vector>
using namespace std;

class student
{
protected:
    float marks;

public:
    void setmarks(float m){
        marks=m;
    }

    virtual string computeGrade()=0;

    ~student() {}


};

class Undergraduate : public student{
    public:
    string computeGrade() override{
        if(marks >=85) return "A";
        else if(marks >= 75)return "B";
        else if(marks >= 60) return "C";
        else return "F";
    }
};

class postgraduate : public student{
    public:
    string computeGrade() override{
        if(marks >=85) return "A";
        else if(marks >= 75)return "B";
        else if(marks >= 60) return "C";
        else return "F";
    }
};

int main(){
    vector<student*>students;

    int n;
    cout<<"Enter The number of Students: ";
    cin>>n;

    student *s =nullptr;

    for(int i=0;i<n;i++){
        int type;
        float m;

        cout<<"\nEnter student type (1 for UG, 2 for PG): ";
        cin>>type;
        cout<<"\nEnter The marks: ";
        cin>>m;

        if(type==1){
            s=new Undergraduate();
        }
        else if(type==2){
            s=new postgraduate();
        }
        else{
            cout<<"INVALID student type skipping....\n";
            continue;
        }
        s->setmarks(m);
        students.push_back(s);
    }

    cout << "\nStudent Grades:\n";
    for (size_t i = 0; i < students.size(); ++i) {
        cout << "Student " << i + 1 << " Grade: " << students[i]->computeGrade() << endl;
    }

    for (size_t i = 0; i < students.size(); ++i) {
        delete students[i];
    }

    return 0;
}