#include <iostream>
#include <cstdlib>
#include <thread>
#include <vector>
using namespace std;

vector<int> result_list;

void thread_delay(int seconds, int rate)
{
	chrono::duration<int> duration(seconds);
	this_thread::sleep_for(duration);

	//cout<< " Finished after " << seconds << " seconds" <<endl;
	result_list.push_back(seconds);
}


vector<int> sleep_sort(vector<int>::iterator vec_begin, vector<int>::iterator vec_end)
{
    int vec_size = vec_end - vec_begin ;
    vector<thread> thread_list;

    result_list.clear();
    thread_list.resize(vec_size);

	//Join threads to the main thread
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

    chrono::duration<int, std::ratio<2> > eight_second(4);

    auto start = chrono::high_resolution_clock::now();

    for (int i=0; i<10; ++i)
    {
        input.push_back(rand()%10);
    }

    output = sleep_sort(input.begin(), input.end());

	//Print the result
	for (int i=0; i<output.size(); ++i)
    {
        cout << i << " output. = " << output[i] << endl;
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed = end-start;
    cout << "Waited " << elapsed.count() << " ms\n";

    return 0;
}
