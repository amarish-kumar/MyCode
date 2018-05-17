#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;
    
    for(int a0 = 0; a0 < n; a0++){
        int x;
        cin >> x;
        int weight = 0;
        bool match_found = false;
        for(int i = 0; i < s.length(); i++){
            weight = s[i]-'a'+1;
            
            if(weight == x)
                match_found = true;
            
            if(match_found){
                cout << "Yes" << endl;
                break;
            }
            
            while(i != s.length()-1 && s[i] == s[i+1]){
                weight += s[i++]-'a'+1;
                if(weight == x){
                    match_found = true;
                    break;
                }
            }
            
            if(match_found){
                cout << "Yes" << endl;
                break;
            }
        }
        if(!match_found)
            cout << "No" << endl;
    }
    return 0;
}

