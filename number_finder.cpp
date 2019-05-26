#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void play_number_finder(int limit) {
	srand(time(0));
	int tought = rand()%limit + 1;
	int answer, answer_count = 0;
	do {
        cout << "Kérek egy számot 1 és " << limit << " között: ";
		cin >> answer;
        ++answer_count;
		if (tought < answer) cout << "Kisebbre gondoltam." << endl;
		if (tought > answer) cout << "Nagyobbra gondoltam." << endl;
	} while (answer != tought);

	cout << "Eltaláltad " << answer_count << " lépésbõl. Vége a játéknak" << endl;
}

void play_gold_finder(int limit) {
	srand(time(0));
	int goldX = rand()%limit + 1;
	int goldY = rand()%limit + 1;
	int answerX, answerY, answer_count = 0;
	bool found = false;
	while (!found) {
        cout << "Kerem az X koordinatat. Erteke 1 es " << limit << " kozott lehet: ";
		cin >> answerX;
        cout << "Kerem az Y koordinatat. Erteke 1 es " << limit << " kozott lehet: ";
		cin >> answerY;
        ++answer_count;
		if (goldX > answerX)
            cout << "A kincs keletebbre van." << endl;
		else if (goldX < answerX)
            cout << "A kincs nyugatabbra van." << endl;
        else
            cout << " A hosszusagi parameter rendben van." << endl;

        if (goldY > answerY)
            cout << "A kincs eszakabbra van." << endl;
		else if (goldY < answerY)
            cout << "A kincs delebbre van." << endl;
        else
            cout << " A szelessegi parameter rendben van." << endl;

       found = ((goldX == answerX) && (goldY == answerY));
	}
	cout << "Eltalaltad " << answer_count << " lepesbol. Vege a jateknak." << endl;
}

void play_general_finder(int limit, int dimensions) {

	int * tought_coords = new int[dimensions];
	int answer_coord, answer_count = 0;
	int * result_coords = new int[dimensions];
	bool found = false;

    //generate coordinates
    srand(time(0));
	for (int i=0; i<dimensions; ++i) {
        tought_coords[i] = rand()%limit + 1;
	}

	while (!found) {
        found = true;
        for (int i=0; i<dimensions; ++i) {
            cout << " Read " << (i+1) << " coordinate (between 1 and " << limit << "): ";
            cin >> answer_coord;

            if (tought_coords[i] > answer_coord)
                result_coords[i] = 1;
            else if (tought_coords[i] < answer_coord)
                result_coords[i] = -1;
            else
                result_coords[i] = 0;

            found = (found && (tought_coords[i] == answer_coord));
        }

        //print result
        for (int i=0; i<dimensions; ++i) {
            cout << result_coords[i] << ", ";
        }
        cout << endl;

        ++answer_count;
	}
    cout << "You found it by " << answer_count << " steps. Game over." << endl;
}

void generate_coords(int dimensions, int * coords, int * limit) {
	srand(time(0));
	for (int i=0; i<dimensions; ++i) {
        coords[i] = rand()%limit[i] + 1;
	}
}

int read_coord(int limit, int index, int dimensions, bool treasure) {
    int result;
    if (dimensions == 1) {
        cout << " Kerek egy szamot 1 es " << limit << " kozott." << endl;
    }
    else if (dimensions >= 2 && dimensions <= 3 && treasure) {
        if (index == 0)
            cout << "Kerem az X koordinatat. Erteke 1 es " << limit << " kozott lehet: ";
        if (index == 1)
            cout << "Kerem az Y koordinatat. Erteke 1 es " << limit << " kozott lehet: ";
        if (index == 2)
            cout << "Kerem a melyseget. Erteke 1 es " << limit << " kozott lehet: ";
    }
    else {
        cout << " Read " << (index+1) << " coordinate (between 1 and " << limit << "): ";
    }

    cin >> result;
    return result;
}

void print_result(int dimensions, int * result_coords, bool treasure) {

    if (dimensions == 1) {
 		if (result_coords[0] == -1)
            cout << "My number is lower." << endl;
		else if (result_coords[0] == 1)
            cout << "My number is greater." << endl;
        else
            cout << "Eltalaltad." << endl;
    }
    else if (dimensions >= 2 && dimensions <= 3 && treasure) {
		if (result_coords[0] == 1)
            cout << "The treasure is in the East." << endl;
		else if (result_coords[0] == -1)
            cout << "The treasure is in the West." << endl;
        else if (result_coords[0] == 0)
            cout << " The longitude is good." << endl;

        if (result_coords[1] == 1)
            cout << "The treasure is in the North." << endl;
		else if (result_coords[1] == -1)
            cout << "The treasure is in the South." << endl;
        else if (result_coords[1] == 0)
            cout << "The latitude is good." << endl;

        if (dimensions == 3) {
            if (result_coords[2] == 1)
                cout << "The treasure is deeper in the ground." << endl;
            else if (result_coords[2] == -1)
                cout << "The treasure is not so deep in the ground." << endl;
            else if (result_coords[2] == 0)
                cout << "The deepness is good." << endl;
            }
    }
    else {
        for (int i=0; i<dimensions; ++i) {
            cout << result_coords[i] << ", ";
        }
        cout << endl;
    }
}

int calc_result(int tought, int answer) {
    if (tought_coords[i] > answer_coord)
        return 1;
    if (tought_coords[i] < answer_coord)
        return -1;
    return 0;
}

void play_general_finder(int dimensions, int * limit, bool treasure) {

    if (dimensions <= 0 || dimensions > 255) {
        cerr << "Parameter error: dimension must be greater than 0 and less than 255 " << endl;
        return;
    }

	if (! limit) {
        cerr << "Parameter error: limit array" << endl;
        return;
	}

	int * tought_coords = new int[dimensions];
	int answer_coord, answer_count = 0;
	int * result_coords = new int[dimensions];
	bool found = false;

	generate_coords(dimensions, tought_coords, limit);

	while (!found) {
        found = true;
        for (int i=0; i<dimensions; ++i) {

            answer_coord = read_coord(limit[i], i, dimensions, treasure);
            result_coords[i] = calc_result(tought_coords[i], answer_coord);
            found = (found && (tought_coords[i] == answer_coord));
        }

        print_result(dimensions, result_coords, treasure);

        ++answer_count;
	}
    cout << "You found it by " << answer_count << " steps. Game over." << endl;
}

int main() {
    //play_number_finder(100);
    //play_gold_finder(10);
    //play_general_finder(100, 4);
    int limit[3] = {100, 50, 10};
    play_general_finder(3, limit, true);
}
