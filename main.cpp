#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
 
int token[10][3];

int prevNumber(string str, int pos) {
    string acum;
    for (register int i = pos-1; i > -1; i--) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*') {
            break;
        }
        else {
            acum.push_back(str[i]);
        }
    }
    return atoi(_strrev((char*)acum.c_str()));
}
int nxtNumber(string str, int pos) {
    string acum;
    for (register int i = pos + 1; i <= str.length(); i++) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*') {
            break;
        }
        else {
            acum.push_back(str[i]);
        }
    }
    return atoi(acum.c_str());
}

vector<int> SygPos(string str) {
    vector <int> acum;
    for (int k = 0; k <=  str.length(); k++) {
        if (str[k] == '*' || str[k] == '+' || str[k] == '-' || str[k] == '/') {
            acum.push_back(k);
        }
    }
    return acum;
}

void GenerateToken(string str) {
    vector <int> pos = SygPos(str);
    for (register int j = 0; j <= pos.size()-1 ; j++) {
        token[j][0] = (int) str[pos[j]];
        token[j][1] = prevNumber(str, pos[j]);
        token[j][2] = nxtNumber(str, pos[j]);
        continue;
    }
}
double eval(string str) {
    vector <int> pos = SygPos(str);
    vector <int> acum;
    double reduce = 0.0;
    for (register int i = 0; i <= pos.size() - 1; i++) {
            switch ((char) ( token[i][0]) ) {
                case '+': 
                    reduce+=(token[i][1] + token[i][2]);
                    break;
                case '-':
                    reduce += (token[i][1] - token[i][2]);
                    break;
                case '*':
                    reduce += (token[i][1] * token[i][2]);
                    break;
                case '/':
                    reduce += (token[i][1] / token[i][2]);
                    break;
                default: perror("ouve um erro");
            }
    }

    return reduce;
}
int main()
{
    while (true) {
        string userentry;
        cout << "calc >>> ";
        cin >> userentry;
        if (userentry == ":q") {
            break;
        }
        vector <int> pos = SygPos(userentry);
        GenerateToken(userentry);
        cout << eval(userentry) << endl;

        userentry.clear();
    }
}
