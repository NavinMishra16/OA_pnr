#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;

vector<string> solve(string &c)
{
    vector<string> build;
    int n = c.size();
    string tmp;
    for (int i = 0; i < n; i++)
    {
        if (c[i] == '|')
        {
            build.push_back(tmp);
            tmp = "";
        }
        else
        {
            tmp += c[i];
        }   
    }
    build.push_back(tmp);
    map<int, string> indexMap;
    for (string &s : build)
    {
        int index = s[3];
        if (indexMap.find(index) != indexMap.end())
            return {"Invalid configuration"};
        indexMap[index] = s.substr(4, s.size());
    }
    vector<string> ans;
    for (auto it : indexMap)
    {
        ans.push_back(it.second);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        string input;
        cin >> input;
        vector<string> ans;
        ans = solve(input);
        
        for(string & s : ans){
            cout<<s<<endl;
        }
    }

    return 0;
}