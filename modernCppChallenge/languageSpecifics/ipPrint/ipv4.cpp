#include <vector>
#include <iostream>

using namespace std;

// Store ipv4 and print.
class ipv4Data
{
    vector<char>ipAddress;
public:
    ipv4Data(char ocet1, char ocet2, char ocet3, char ocet4 )
    {
        ipAddress.push_back(ocet1);
        ipAddress.push_back(ocet2);
        ipAddress.push_back(ocet3);
        ipAddress.push_back(ocet4);
    }
    
    ipv4Data()
    {
        ipAddress.push_back(0);
        ipAddress.push_back(0);
        ipAddress.push_back(0);
        ipAddress.push_back(0);
    }

    ipv4Data& operator=(ipv4Data const &other)
    {
        ipAddress = other.ipAddress;
        return *this;
    }

    friend istream& operator>> (istream& is, ipv4Data& data) 
    {
        int ocet1, ocet2, ocet3, ocet4;
        char dot;

        is>>ocet1>>dot>>ocet2>>dot>>ocet3>>dot>>ocet4;

        data = ipv4Data(ocet1, ocet2, ocet3, ocet4);
        return is;
    }

    friend ostream& operator<< (ostream& os, ipv4Data& data) 
    {
        os << static_cast<int>(data.ipAddress[0]) << "." <<
            static_cast<int>(data.ipAddress[1]) << "." <<
            static_cast<int>(data.ipAddress[2]) << "." <<
            static_cast<int>(data.ipAddress[3]) << endl;
        return os;
    }
    
};


int main (int argc, char *argv[])
{
    ipv4Data ipData;

    cout << "Please enter an ipv4 address: ";
    cin >> ipData;
    cout << ipData;
    return 0;
}