class Solution {
public:
  int maximumScore(int a, int b, int c) {
    // int par = (a + b + c) % 2 == 0;
    
    // if (par) {
    //   return (a+b+c)/2;
    // }
    return min((a+b+c)/2, a+b+c-max(max(a, b), c));
  }
};