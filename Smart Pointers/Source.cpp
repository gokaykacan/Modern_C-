/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <memory>

using namespace std;

class Integer
{
    int* mp_Value;
public:
    Integer() // constructor
    {
        mp_Value = new int(0);
    }

    Integer(int value) // constructor
    {
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
        if (this != &other) // bunu yaparak, kendine eþitlendiðinde deegrin yok olmasýný önleriz
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

void Process(std::unique_ptr<Integer> ptr)
{
    cout << ptr->getValue() << endl;
}
void Process2(std::shared_ptr<Integer> ptr)
{
    cout << ptr->getValue() << endl;
}

int main()
{
    std::unique_ptr<Integer> p(new Integer(5));
    p->setValue(15);
    //cout << p->getValue() << endl;


    //auto p3(p); // copy constructor uniq pointerlarda delete oldugu için hata verir
    //Process(p); // copy constructor çaðýralacaðý için error verir
    auto p2(std::move(p)); // ancak move edilebilir

    std::shared_ptr<Integer> p3(new Integer(7)); // shared pointer'da birden fazla pointer ayný yeri point edebilir
    Process2(p3);
    return 0;
}
