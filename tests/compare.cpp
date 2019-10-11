#include <iostream>
#include <functional>
#include <string>

using namespace std;

int main() {
   string one_s, two_s; 
   bool result;
   one_s = "Hello";
   two_s = "Hello";

   result = one_s == two_s;
   cout << result << endl;
   //result = one_s.compare(two_s);
   cout << result << endl;
   //result = one_s.equal_to(two_s);
   cout << result << endl;

    
       

    return 0;
}
