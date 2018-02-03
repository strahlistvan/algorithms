#include <iostream>
#include <cstdlib>
#include <thread>
#include <vector>
using namespace std;

const int MAX_INPUT_VALUE = 1000;
const int INPUT_SIZE = 100;
const int TIME_SLOT_RATE = 100;

vector<int> result_list;

void thread_delay(int seconds)
{
	chrono::duration<int, ratio<1, TIME_SLOT_RATE> > duration(seconds);
	this_thread::sleep_for(duration);

    //push the number to the global result list after thread delaying
	result_list.push_back(seconds);
}


vector<int> sleep_sort(vector<int>::iterator vec_begin, vector<int>::iterator vec_end)
{
    int vec_size = vec_end - vec_begin ;
    vector<thread> thread_list;

    result_list.clear();
    thread_list.resize(vec_size);

	//Running threads
	auto it = vec_begin;
	for (int i=0; i<vec_size; ++i)
	{
		thread_list[i]= thread(thread_delay, *it);
		++it;
	}

	//Join threads to the main thread
	for (int i=0; i<vec_size; ++i)
	{
	    if (thread_list[i].joinable())
            thread_list[i].join();
	}

    return result_list;
}

int main(int arc, char ** argv)
{
    srand(time(0));
    std::vector<int> input, output;
    double approx_run_time = (double)(1.0/TIME_SLOT_RATE)*MAX_INPUT_VALUE;

    cout << "Sleep sort is running." << endl;
    cout << "INPUT SIZE : " << INPUT_SIZE << endl;
    cout << "MAXIMUM INPUT ELEMENT VALUE: " << MAX_INPUT_VALUE << endl;
    cout << "Approximate running time is " << approx_run_time << " seconds" << endl;

    auto start = chrono::high_resolution_clock::now();

    //Generate random input
    for (int i=0; i<INPUT_SIZE; ++i)
    {
        input.push_back(rand()%MAX_INPUT_VALUE+1);
    }

    output = sleep_sort(input.begin(), input.end());

	//Print the result
	for (int i=0; i<output.size(); ++i)
    {
        cout << "output[" << i << "] = " << output[i] << endl;
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed = end-start;
    cout << "Real running time: " << elapsed.count() << " ms\n";

    return 0;
}
