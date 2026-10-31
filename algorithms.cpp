#include <bits/stdc++.h>
using namespace std;

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    cout << q.front() << "\n"; //10
    q.pop();
    cout << q.front() << "\n"; //20
	
    stack<int> s;
    s.push(10);
    s.push(20);
    cout << s.top() << "\n"; //20
    s.pop();
    cout << s.top() << "\n"; //10
    
    int n;
    cin >> n;
    vector<int> a; // 一維 vector
    vector<int> b(10); // 大小為十的 vector
    vector<int> c(n); // 大小為 n 的 vector
    vector<int> d(n,10); // 大小為 n 且每個元素預設是 10 的 vector
    vector<int> e={1,2,3}; // 元素為 1 2 3 的 vector
    vector<int> f=d; // 直接 = 某個結構一樣的 vector
    vector<int> g(d.begin()+2,d.end()); // 從 d 的第2項 (0-based) 取到最後一項
    vector<vector<int>> two(n,vector<int>(n,0)); // 二維 vector，預設全部都是 0

    vector<int> v(n);
    v[0]=1;
    v.clear();
    v.resize(10);
    v.reserve(100);
    v.push_back(48763);
    v.pop_back();
    int vsize = v.size();
    cout << vsize;
    return 0;
    
}