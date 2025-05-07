//Yash Gohel-24CE035
//Program No: 5.2
#include <iostream>
using namespace std;

class Complex {
    double real;
    double imaginary;

public:
    // Method to get data from the user
    void getData() {
        cout << "Enter the real part: ";
        cin >> real;
        cout << "Enter the imaginary part: ";
        cin >> imaginary;
    }

    // Method to display the complex number
    void display() {
        cout << "Complex number: " << real;
        if (imaginary >= 0)
            cout << " + " << imaginary << "i" << endl;
        else
            cout << " - " << -imaginary << "i" << endl;
    }

    // Method to add two complex numbers and return the result
    Complex add(Complex c) {
        Complex result;
        result.real = real + c.real;
        result.imaginary = imaginary + c.imaginary;
        return result;
    }

    Complex sub(Complex c)
    {
        Complex result;
        result.real=real - c.real;
        result.imaginary = imaginary - c.imaginary;
        return result;
    }
};

int main() {
    Complex c1, c2, sum,sub;

    cout << "Enter first complex number:" << endl;
    c1.getData();

    cout << "Enter second complex number:" << endl;
    c2.getData();

    sum = c1.add(c2);
    sub = c1.sub(c2);

    cout << "\nFirst ";
    c1.display();

    cout << "Second ";
    c2.display();

    int n=0;
    cout<<"If you need 'sum' press one and press 0 for 'subtact'\n";
    cin>>n;

    if(n==1){
    cout << "Sum ";
    sum.display();
    }
    else if(n==0){
        cout<<"subtract ";
        sub.display();
    }

    return 0;
}
