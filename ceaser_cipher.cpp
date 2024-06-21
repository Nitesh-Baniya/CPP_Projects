#include <iostream>
#include <string>
using namespace std;

/*commented code also does the same work
However, use of template is promoted*/
template <typename T, typename T1, typename T2 = int, typename T3, typename T4 = int>

T shift(T1 c, T2 shi, T3 range, T4 firstEle)
{
  int val = c - firstEle;
  val = (val + shi) % range;
  c = val + firstEle;
  return c;
}

// char lower(char c, int shi)
// {
//   int val = c - 'a';
//   val = (val + shi) % 26;
//   c = val + 'a';
//   return c;
// }
// char upper(char c, int shi)
// {
//   int val = c - 'A';
//   val = (val + shi) % 26;
//   c = 'A' + val;
//   return c;
// }
// char num(int n, int shi)
// {
//   int val = n - '0';
//   val = (val + shi) % 10;
//   n = '0' + val;
//   return n;
// }
string encode(string s, int shi)
{
  for (int i = 0; i < s.size(); i++)
  {
    if ('A' <= s[i] && s[i] <= 'Z')
    {
      // s[i] = upper(s[i], shi);
      s[i] = shift<char, char, int, int, int>(s[i], shi, 26, 'A');
    }
    else if ('a' <= s[i] && s[i] <= 'z')
    {
      // s[i] = lower(s[i], shi);
      s[i] = shift<char, char, int, int, int>(s[i], shi, 26, 'a');
    }
    else if ('0' <= s[i] && s[i] <= '9')
    {
      // s[i] = num(s[i], shi);
      s[i] = shift<char, char, int, int, int>(s[i], shi, 10, '0');
    }
    else
    {
      s[i] = s[i];
    }
  }
  return s;
}
int main()
{
  string s;
  cout << "Enter a string to encode: ";
  getline(cin, s);
  string encoded = encode(s, 4);
  cout << encoded;

  return 0;
}