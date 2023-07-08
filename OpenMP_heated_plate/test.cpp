#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() 
{

    string file_name, file_name1;
    double sum1 = 0;
    double sum2 = 0;

    file_name = "output.txt";
    file_name1 = "output_serial.txt";

    ifstream inFil(file_name);  // create a stream and connect it to a file for reading

    if (inFil) {  // test if stream is in good-state
        vector<double> numbers_list;

        double x = 0;

        inFil >> x;  // read first number

        while (inFil) { // test if stream is in good-state
            numbers_list.push_back(x);  // store number in the vector

            inFil >> x;  // read next number
        }

        for (double d : numbers_list) {
            sum1 = d + sum1;
        }

        cout << "\n";
    } else {
        cout << "File could not be opened!!";
    }

    ifstream inFil1(file_name1);
    if (inFil1) {  // test if stream is in good-state
        vector<double> numbers_list1;

        double y = 0;

        inFil1 >> y;  // read first number

        while (inFil1) { // test if stream is in good-state
            numbers_list1.push_back(y);  // store number in the vector

            inFil1 >> y;  // read next number
        }
        for (double m : numbers_list1) {
            sum2 = m + sum2;
        }

        cout << "\n";
    } else {
        cout << "File could not be opened!!";
    }
    cout << sum1 << ", " << sum2 << ", " << abs(sum1-sum2) << endl;
}