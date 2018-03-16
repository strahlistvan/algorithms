#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
using namespace std;

int get_round_birth_year_count(int limit, int radix);

int main(int argc, char ** argv){
    int limit, radix, result;
    ofstream fout;
    stringstream filename;

    cout << "Age limit: ";
    cin  >> limit;

    filename << "number_" << limit << ".csv";
    fout.open(filename.str());
    fout << "radix;count";

    for (radix = 2; radix < limit; ++radix) {
        result = get_round_birth_year_count(limit, radix);
        cout << "Round birth year count in base " << radix << ": "<< result << endl;
        fout << radix << ";" << result << endl;
    }

    fout.close();
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
//            cout << current_age << endl;
            ++total_count;
        }
    }

    return total_count;
}
