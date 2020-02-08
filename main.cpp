/*Created by Yi Tao on 1/19/20.
 *This program is to receives five double
 *type inputs from user and
 *to calculate the sum, average,product
 *and the absolute value of each number to the console
*/

#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    double num1, num2, num3,num4,num5,sum;
    cout<< "Enter five numbers: ";
    cin >> num1 >> num2 >> num3 >> num4 >> num5;
    sum = num1+num2+num3+num4+num5;
    cout<<"Sum: "<< sum << endl;
    cout<< "Average: "<< sum/5 << endl;
    cout<< "Product: "<< num1 * num2*num3*num4*num5 << endl;
    cout<< "Absolute Values: "<< abs(num1)<< " "<<abs(num2) << " "<< abs(num3) <<" "<< abs(num4) << " "<< abs(num5) << endl;
    cout << "Done"<< endl;
    return 0;
}

