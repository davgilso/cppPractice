#include <string>

using namespace std;

template <typename T>
class Observer
{
    public:
        virtual void fieldChange(T& source,  string fieldName) = 0;
};