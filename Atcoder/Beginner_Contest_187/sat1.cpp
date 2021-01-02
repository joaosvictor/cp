#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<string> S(N);
    for(string& s : S) cin >> s;
    unordered_set<string> h(S.begin(), S.end());
    for(string& s : S) if(h.count('!' + s)){
        cout << s << endl;
        return 0;
    }
    cout << "satisfiable" << endl;
}