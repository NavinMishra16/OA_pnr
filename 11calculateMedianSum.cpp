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

int calculateMedianSum(vector<int>& packets, int channels) {
    if (packets.empty() || packets.size() > 500000)
        return -1; // Indicate invalid input
    for (int i = 0; i < packets.size(); ++i) {
        if (packets[i] < 1 || packets[i] > 1000000000)
            return -1; // Indicate invalid input
    }
    if (channels < 1 || channels > packets.size())
        return -1; // Indicate invalid input

    if (channels == 1) {
        int result = 0;
        for (int packet : packets) {
            result += packet;
        }
        return result;
    }

    sort(packets.begin(), packets.end(), greater<int>());
    int result = 0;
    for (int i = 0; i < channels - 1; ++i) {
        result += packets[i];
    }

    vector<int> median_temp(packets.begin() + channels - 1, packets.end());
    double temp = 0;
    if (median_temp.size() % 2 == 0) {
        temp = (double)(median_temp[median_temp.size() / 2] + median_temp[median_temp.size() / 2 - 1]) / 2;
    } else {
        temp = median_temp[median_temp.size() / 2];
    }

    result += round(temp);
    return result;

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>v = {5, 2, 2, 1, 5, 3};
    int k= 2;

    cout<<calculateMedianSum(v,k)<<"\n";
    // Your code here

    return 0;
}