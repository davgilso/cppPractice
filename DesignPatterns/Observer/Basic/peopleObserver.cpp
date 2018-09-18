#include <iostream>
#include <vector>

#include "observable.hpp"
#include "Observer.hpp"

using namespace std;


class person : public Observable<person>
{
    int age;

    public:
        int getAge() const
        {
            return age;
        }

        void setAge(int age)
        {
            if (this->age == age)
            {
                return;
            }
            else
            {
                this->age = age;
                notify(*this, "age");
            }

        }
};


class consolePersonObserver : public Observer<person>
{
    void fieldChange(person& source, string fieldName) override
    {
        if (fieldName == "age")
        {
            cout << "Age has changed to " << source.getAge() << "\n";
        }
        else
        {
            cout << "Invalid fieldName change. \n"; 
        }
    }
};

int main ()
{
    person p;
    consolePersonObserver cpo;

    p.subscribe(cpo);
    p.setAge(30);
    p.setAge(30);
    p.setAge(35);
    p.setAge(55);
    //p.unsubscribe(cpo);
    p.setAge(99);
}