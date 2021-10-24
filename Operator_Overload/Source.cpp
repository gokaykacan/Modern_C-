/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class Integer
{
    int* mp_Value;
public:
    Integer() // constructor
    {
        cout << "Integer())" << endl;
        mp_Value = new int(0);
    }

    Integer(int value) // constructor
    {
        cout << "Integer(int value)" << endl;
        mp_Value = new int(value);
    }

    Integer(const Integer& other) // copy constructor
    {
        cout << "Integer(const Integer& other)" << endl;
        mp_Value = new int(*other.mp_Value);

    }
    Integer(Integer&& other) // move constructor
    {
        cout << "Integer(Integer&& other)" << endl;
        mp_Value = other.mp_Value;
        other.mp_Value = nullptr;

    }
    ~Integer() // destructor
    {
        cout << "~Integer()" << endl;
        delete mp_Value;
    }

    Integer operator+(const Integer& other)
    {
        Integer temp;
        *temp.mp_Value = *mp_Value + *other.mp_Value;
        return temp;
    }

    Integer& operator=(const Integer& other) //assingment overload
    {
        cout << "Integer & operator=(const Integer& other)" << endl;
        if (this != &other) // bunu yaparak, kendine eþitlendiðinde degerin yok olmasýný önleriz
        {
            delete mp_Value;
            mp_Value = new int(*other.mp_Value);
        }

        return *this;
    }
    Integer& operator=(Integer&& other) //move assingment overload
    {
        cout << "Integer & operator=(Integer&& other)" << endl;
        if (this != &other) // bunu yaparak, kendine eþitlendiðinde degerin yok olmasýný önleriz
        {
            delete mp_Value;
            mp_Value = new int(*other.mp_Value);
        }

        return *this;
    }
    int getValue()
    {
        return *mp_Value;
    }
    void setValue(int value)
    {
        *mp_Value = value;
    }


};

Integer operator +(int x, Integer& other) // sol taraf primitive oldugunda bu overload gelecek
{
    Integer temp;
    temp.setValue(x + other.getValue());
    return temp;
}

ostream& operator <<(ostream& out, Integer& other) // ostream << overload
{
    out << other.getValue();
    return out;
}

int main()
{
    Integer a(5), b(8);
    Integer sum = a + b;
    Integer sum2 = a + 4;

    cout << "Sum: " << sum.getValue() << endl;
    cout << "Sum2: " << sum2.getValue() << endl;

    Integer sum3 = 9 + b;
    cout << "Sum3: " << sum3 << endl; // ostream overload ile sum3 yazdýrabildik

    Integer c = a;
    cout << "c: " << c.getValue() << endl;


    return 0;
}
