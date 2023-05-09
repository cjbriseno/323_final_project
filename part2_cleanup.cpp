#include <iostream>
using namespace std;

#program s2023
int main()
{
int p1, p2q, pr;

p1 = 33;
p2q = 412;
pr = p1 + p2q;
cout << pr << endl;

pr = p1 * (p2q + 2 * pr);

cout << "Value = " << pr << endl;

return 0;
}
