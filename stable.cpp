#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

void split(string const &str, const char* delim, vector<string> &out) 
{ 
    char *token = strtok(const_cast<char*>(str.c_str()), delim); 
    while (token != nullptr) 
    { 
        out.push_back(std::string(token)); 
        token = strtok(nullptr, delim); 
    } 
} 

struct Pairing{
    string name;
    Pairing* partner;
}

class Matching{
    private:
        Pairing* boys;
        Pairing* girls;

    public:
        Matching(string b, string g){
            vector<string> bo;
            split(b, " ", bo);

            vector<string> go;
            split(g, " ", go);

        }

}

void main(){
    int n;

    string boys;
    cout << "Enter the names of the boys delimited by spaces: ";
    getline(cin, boys);

    string girls;
    cout << "Enter the names of the girls delimited by spaces: ";
    getline(cin, girls);

    stirng 
    



}