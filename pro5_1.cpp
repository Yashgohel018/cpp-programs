//Yash Gohel-24CE035
//Program No: 5.1
#include<iostream>
#include<vector>
using namespace std;

class calculator{
    vector<double> result;
    public:
    int add(int a,int b){
        return a+b;

    }
    double add(double a,double b){
        return a+b;
    }
    double add(int a,double b){
        return a+b;
    }

};
int main(){
    calculator calc;
    vector<double>stlresults;//make vector for better sequence output.
    stlresults.push_back(calc.add(10,20));
    stlresults.push_back(calc.add(75.5,75.5));
    stlresults.push_back(calc.add(10,20.5));

    cout<<"Result using STL vector: "<<endl;
    for(size_t i=0;i<stlresults.size();i++){
        cout<<"Result "<<i+1<<": "<<stlresults[i]<<endl;
    }
    cout<<endl;

    

    double results[3]; // Array to store results

    // Compute the results
    results[0] = calc.add(10, 20);
    results[1] = calc.add(75.5, 75.5);
    results[2] = calc.add(10, 20.5);

    // Display the results
    cout << "Result using array: " << endl;
    for(size_t i = 0; i < 3; i++){
        cout << "Result " << i+1 << ": " << results[i] << endl;
    }
    cout << endl;

    return 0;
}