#include <iostream>
#include <cmath>
using namespace std;

int get_round_birth_year_count(int limit, int radix);

int main(int argc, char ** argv){
    int limit, radix;

    cout << "Age limit: ";
    cin  >> limit;
    cout << "Selected numeral system base: ";
    cin  >> radix;

    cout << "Round birth year count : " << get_round_birth_year_count(limit, radix);

    return 0;
}

int get_round_birth_year_count(int limit, int radix) {
    int current_age = 0, base_power = radix;
    int total_count = 0, count = 0;

    while (current_age <= limit) {

        if (count == radix-1) {
            base_power *= radix;
            current_age = base_power;
            count = 1;
        }
        else {
            current_age += base_power;
            ++count;
        }

        if (current_age <= limit) {
            cout << current_age << endl;
            ++total_count;
        }
    }

    return total_count;
}
