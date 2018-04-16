#include <iostream>
#include <vector>

using namespace std;

// use max heap to have an ascending sort result
void heapify(vector<int> &input) {
    for(int i=1; i<input.size(); ++i) {
        int check = i;
        while(true) {
            if(check/2 > 0 && input[check] >= input[check/2]) {
                swap(input[check], input[check/2]);
                check /=2;
            }
            else
                break;
        }
    }
    cout << "heapify result ";
    for(int i=1; i<input.size(); ++i)
        cout << input[i] << " ";
    cout << endl;
}

void heapsort(vector<int> &input) {
    input.insert(input.begin(), 0);
    heapify(input);

    for(int i=1; i<input.size(); ++i) {
        swap(input[1], input[input.size()-i]);
        int check = 1;
        while(true) {
            if(check*2+1 < input.size()-i) {
                if(input[check] < max(input[check*2+1], input[check*2])){
                    if(input[check*2+1] > input[check*2]) {
                        swap(input[check], input[check*2+1]);
                        check = check*2+1;
                    }
                    else {
                        swap(input[check], input[check*2]);
                        check = check*2;
                    }
                }
                else
                    break;
            }
            else if(check*2 < input.size()-i) {
                if(input[check] < input[check*2]) {
                    swap(input[check], input[check*2]);
                    break; 
                }
                else
                    break;
            }
            else
                break;
        }
    }

    input.erase(input.begin());
}

int main() {
    const int count = 500;
    const int max = 500;
    vector<int> test(count);
    cout << "test input ";
    srand(time(NULL));
    for(int i=0; i<count; ++i) {
        test[i] = rand() % max;
        cout << test[i] << " ";
    }
    cout << endl;
    heapsort(test);
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
