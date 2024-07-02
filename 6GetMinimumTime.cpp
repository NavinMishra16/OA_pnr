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
 int getMinTime(int total_servers, vector<int> servers) {
    map<int, int> serverMap;
    for (int index = 1; index <= total_servers; ++index) {
        serverMap[index] = index-1;
    }
    sort(servers.begin(), servers.end());

    int clock = 0;
    for (int i = 0; i < servers.size() - 1; ++i) {
        int first = serverMap[servers[i]]; 
        int second = serverMap[servers[i + 1]];
        clock += second - first;
    }
    int anti = 0;
    rotate(servers.begin(), servers.begin() + 1, servers.end());
    for (int i = servers.size() - 1; i > 0; --i) {
        int first = serverMap[servers[i]], second = serverMap[servers[i - 1]];
        if (first - second < 0) {
            anti += first - second + total_servers;
        } else {
            anti += first - second;
        }
    }

    return min(clock, anti);
    }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int>servers = {2,6,8};
    int tottalserver = 8; 
    cout<<getMinTime(tottalserver,servers);

    // Your code here

    return 0;
}