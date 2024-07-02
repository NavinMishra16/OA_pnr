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
int numIdleDrives(vector<int>&x, vector<int>&y){
    unordered_map<int, vector<int>> col_ranges;
    unordered_map<int, vector<int>> row_ranges;

    for (size_t i = 0; i < x.size(); ++i) {
        col_ranges[x[i]].push_back(y[i]);
        row_ranges[y[i]].push_back(x[i]);
    }

    for (auto& pair : col_ranges) {
        sort(pair.second.begin(), pair.second.end());
    }

    for (auto& pair : row_ranges) {
        sort(pair.second.begin(), pair.second.end());
    }

    int active_cnt = 0;
    for (size_t i = 0; i < x.size(); ++i) {
        bool is_active = false;
        if (x[i] == row_ranges[y[i]][0] || x[i] == row_ranges[y[i]].back() ||
            y[i] == col_ranges[x[i]][0] || y[i] == col_ranges[x[i]].back()) {
            is_active = true;
        }
        if (is_active) {
            active_cnt++;
        }
    }
    return x.size() - active_cnt;
    
 }



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   vector<int>x = {1, 1, 1, 2, 2, 2, 2, 3, 3, 3};
   vector<int>y = {1, 2, 3, 1, 2, 3, 5, 1, 2, 3};
   cout<<numIdleDrives(x,y)<<"\n";
   return 0;
}