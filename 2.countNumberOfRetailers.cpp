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
vector<int> solve(vector<vector<int>> &retailers, vector<vector<int>> &requests)
{
    map<int, int> counter_x;
    map<int, int> counter_y;

    for (const auto &retailer : retailers)
    {
        counter_x[retailer[0]]++;
        counter_y[retailer[1]]++;
    }

    vector<pair<int, int>> prefix_x;
    vector<pair<int, int>> prefix_y;

    for (auto it = counter_x.rbegin(); it != counter_x.rend(); ++it)
    {
        int last = prefix_x.empty() ? 0 : prefix_x.front().second;
        prefix_x.insert(prefix_x.begin(), {it->first, it->second + last});
    }

    for (auto it = counter_y.rbegin(); it != counter_y.rend(); ++it)
    {
        int last = prefix_y.empty() ? 0 : prefix_y.front().second;
        prefix_y.insert(prefix_y.begin(), {it->first, it->second + last});
    }

    auto bsearch = [](const vector<pair<int, int>> &prefix, int value)
    {
        int lo = 0, hi = prefix.size() - 1;
        if (value > prefix[hi].first)
            return 0;
        if (value <= prefix[lo].first)
            return prefix[lo].second;

        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if (value == prefix[mid].first)
            {
                hi = mid;
                break;
            }
            else if (value < prefix[mid].first)
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return prefix[hi].second;
    };
    cout << "Prefix of X "
         << "\n";

    // for(auto it : prefix_x){
    //     cout<<it.first<<" "<<it.second<<"\n";
    // }
    // cout<<"Prefix of Y "<<"\n";

    // for(auto it : prefix_y){
    //     cout<<it.first<<" "<<it.second<<"\n";
    // }
    vector<int> ans;
    for (const auto &request : requests)
    {
        int max_x = bsearch(prefix_x, request[0]);
        int max_y = bsearch(prefix_y, request[1]);
        ans.push_back(min(max_x, max_y));
    }

    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> retailers = {{1, 2}, {2, 3}, {1, 5}};
    vector<vector<int>> requests = {{1, 1}, {1, 4}};
    vector<int> ans = solve(retailers, requests);

    for (auto it : ans)
        cout << it << " ";
    cout << "\n";

    // Your code here

    return 0;
}