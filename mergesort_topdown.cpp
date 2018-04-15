#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

void merge(vector<int>& input, int start, int mid, int end) {
    // left group [start, mid]
    // right group [mid+1, end]
    
    vector<int> buf(end - start +1);
    int left = start;
    int right = mid+1;
    int leftEnd = mid;
    int rightEnd = end;
    for(int pos=0; pos < end-start+1; ++pos) {
        bool chooseLeft;
        if(left>leftEnd)
            chooseLeft = false;
        else if(right>rightEnd)
            chooseLeft = true;
        else if(input[left] < input[right])
            chooseLeft = true;
        else
            chooseLeft = false;

        if(chooseLeft)
            buf[pos] = input[left++];
        else
            buf[pos] = input[right++];
    }

    for(int i=start; i<=end; ++i) {
        input[i] = buf[i-start];
    }
}

void mergesort(vector<int>& input, int start, int end) {
    if(start + 1 == end) {
        if(input[start] < input[end])
            ; // do nothing
        else {
            swap(input[start], input[end]);
        }
        return ;
    }


    int mid = (start + end) /2;
    if(start != mid)
        mergesort(input, start, mid);
    if(mid+1 != end)
        mergesort(input, mid+1, end);
    merge(input, start, mid, end);
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
    mergesort(test, 0, count -1);
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
