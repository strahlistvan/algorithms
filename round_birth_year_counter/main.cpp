#include <iostream>
#include <cmath>
using namespace std;

int get_round_birth_year_count(int limit, int radix);

int main(int argc, char ** argv)
{
    int limit, radix;

    cout << "Hello world!" << endl;
    cout << "Age limit: ";
    cin  >> limit;
    cout << "Selected numeral system base: ";
    cin  >> radix;

    cout << "Round birth year count : " << get_round_birth_year_count(limit, radix);

    return 0;
}

int get_round_birth_year_count(int limit, int radix) {
    int current_age = 0, zeros = 1;
    int total_count = 0, count = 0;
//    int base_power = radix;

    while (current_age <= limit) {
        current_age += pow(radix, zeros);

        if (count == radix-1) {
            count = 0;
            ++zeros;
//            base_power *= radix;
        }
        else {
            ++count;
        }

        if (current_age <= limit) {
            cout << current_age << endl;
            ++total_count;
        }
    }

    return total_count;
}
