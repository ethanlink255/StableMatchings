#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<string> split(string str, char splitter){
    vector<string> result;
    string current = ""; 
    for(int i = 0; i < str.size(); i++){
        if(str[i] == splitter){
            if(current != ""){
                result.push_back(current);
                current = "";
            } 
            continue;
        }
        current += str[i];
    }
    if(current.size() != 0)
        result.push_back(current);
    return result;
}

struct Pairing{
    string name;
    Pairing* partner;
    int* preflist;

    Pairing(string n, Pairing* p, int* pr){
        name = n;
        partner = p;
        preflist = pr;
    }
};

class Matching{
    private:
        Pairing* boys;
        Pairing* girls;
        int n;

    public:
        Matching(vector<string> b, vector<string> g, int** b_prefs, int** g_prefs){
            n = g.size();
            boys = (Pairing*) malloc(sizeof(Pairing) * n);
            girls = (Pairing*) malloc(sizeof(Pairing) * n);
            
            int i = 0;
            for(string x: b){
                boys[i] = Pairing(x, nullptr, b_prefs[i]);
                i++;
            }

            i = 0;
            for(string x: g){
                girls[i] = Pairing(x, nullptr, g_prefs[i]);
                i++;
            }
        }

        void GeneratePreferenceTables(){
            cout << "============== BOYS ==============" << endl;
            for(int i = 0; i < n; i++){
                cout << boys[i].name << ": ";
                for(int v = 0; v < n; v++) { cout << girls[boys[i].preflist[v]].name << " "; }
                cout << endl;
            }
            cout << endl;

            cout << "============== GIRLS ==============" << endl;
            for(int i = 0; i < n; i++){
                cout << girls[i].name << ": ";
                for(int v = 0; v < n; v++) { cout << boys[girls[i].preflist[v]].name << " "; }
                cout << endl;
            }
        }

};

int main(){
    int n;

    string boys;
    cout << "Enter the names of the boys delimited by spaces: ";
    getline(cin, boys);

    string girls;
    cout << "Enter the names of the girls delimited by spaces: ";
    getline(cin, girls);

    vector<string> bo;
    bo = split(boys, ' ');

    vector<string> go;
    go = split(girls, ' ');

    n = bo.size();
    if(bo.size() != go.size()){
        cout << endl << "INVALID INPUT: # boys must equal # girls" << endl;
        return -1;
    }

    int** b_prefs = (int**) malloc(sizeof(int*) * n);

    int i = 0;
    for(string x: bo){
        string tbr;
        cout << "Enter the pref list for " << x << " delimited by spaces (starting from 0)" << endl;
        getline(cin, tbr);

        b_prefs[i] = (int*) malloc(sizeof(int) * n);
        if(tbr.length() < n/2) { cout << "INVALID INPUT, wrong size" << endl; return -1; }
        for(int v = 0; v < tbr.length(); v += 2){   
          b_prefs[i][v/2] = atoi(&tbr[v]);
        } 

        i++;
    }

    int** g_prefs = (int**) malloc(sizeof(int*) * n);

    i = 0;
    for(string x: go){
        string tbr;
        cout << "Enter the pref list for " << x << " delimited by spaces (starting from 0)" << endl;
        getline(cin, tbr);

        g_prefs[i] = (int*) malloc(sizeof(int) * n);
        if(tbr.length() < n/2) { cout << "INVALID INPUT, wrong size" << endl; return -1; }
        for(int v = 0; v < tbr.length(); v += 2){   
          g_prefs[i][v/2] = atoi(&tbr[v]);
        } 

        i++;
    }

    Matching m = Matching(bo, go, b_prefs, g_prefs);
    m.GeneratePreferenceTables();

}