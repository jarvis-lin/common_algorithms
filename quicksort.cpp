#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

int partition(vector<int>& input, int start, int end) {
    int pivot = input[end];

    int left = start; 
    int right =  end - 1;
    int store = start;
    for(int i=start; i<end; ++i) {
        if(input[i] < pivot) {
            swap(input[i], input[store]);
            ++store;
        }
    }
    swap(input[store], input[end]);
    return store;
}

void quicksort(vector<int>& input, int start, int end) {
    if(start>=end)
        return ;
    else {
        int index = partition(input, start, end);
        quicksort(input, start, index-1);
        quicksort(input, index+1, end);
    }
}

int main() {
    const int count = 50;
    const int max = 500;
    vector<int> test(count);
    cout << "test input ";
    for(int i=0; i<count; ++i) {
        test[i] = rand() % max;
        cout << test[i] << " ";
    }
    cout << endl;
    quicksort(test, 0, count -1);
    cout << "sorted result " << test[0] << " ";
    bool correct = true;
    for(int i=1; i<count; ++i) {
        cout << test[i] << " ";
        correct &= (test[i] >=test[i-1]);
    }
    cout << endl;
    cout << "result " << correct << endl;

    return 0;
}
