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
int getMinErrors(string errorString ,int x ,int y){
    int n = errorString.size();
     const int mod = 1e9+7;
     vector<int>dp(n+1);
     dp[0]  = 0 ; 
     int cnt0 = errorString[0] == '0'? 1 : 0;
     int cnt1 = errorString[0] == '0'? 0 : 1;
     
     for(int i = 1 ; i < n ; i++){
        if(errorString[i]=='0'){
           dp[i] = (dp[i-1]+cnt1*y)%mod;
           dp[i] %=mod;
           cnt0++;
        }
       else if(errorString[i]=='1'){
          dp[i] = dp[i-1]+ cnt0*x;
          dp[i] %=mod;
          cnt1++;
       }
       else { 
      if (cnt1 * y <= cnt0 * x) {
        dp[i] = (dp[i - 1] + cnt1 * y)%mod;
        dp[i]%= mod;
        cnt0++;
      } else {
        dp[i] = (dp[i - 1] + cnt0 * x)%mod;
        dp[i]%= mod;
        cnt1++;
      }
       }   
     }
     return dp[n-1]%mod; 
}

vector<string> sortOrders(vector<string> orderList) {
vector<string>res; 
string build ="";
   for(string &o : orderList){
        int n = o.length();
        int cnt = 0 ;
        for(int i = 0 ; i < n ; i++){
           if(o[i]==' '){
              cnt++;
              res.push_back(build);
              build = "";
              
           }
           if(cnt==2)break;
           else {
                build += o[i];
           }
        }
        res.push_back(build);
   }
  
   res.push_back(build);
  return res;    
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //cout<<getMinErrors("01!01!0",2,3)<<endl;
      vector<string>tmp = {"zld 93 12", "fp kindle book" ,"10a echo show"};
    vector<string>res = sortOrders(tmp);
    for(auto s : res)cout<<s<<" " ;
    cout<<endl;

    return 0;
}
