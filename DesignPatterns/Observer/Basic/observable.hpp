#include <vector>
#include <string>

template <typename> class Observer;

using namespace std;

template <typename T>
class Observable
{
    std::vector<Observer<T>*> observers;

    public:
        void subscribe(Observer<T>& observer)
        {
            observers.push_back(&observer);
        }

        void unsubscribe(Observer<T>& observer)
        {
            observers.erase(
                remove(observers.begin(), observers.end(), observer), observers.end() 
            );
        }
        void notify(T& source, string fieldName)
        {
            for (auto observer : observers)
            {
                observer->fieldChange(source, fieldName);
            }
        }
};