#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n,a,b,cnt = 0, moves = 0;
    int minElement=6;
    int maxElement=20;
    cout<<"Enter the size of an array (6-20): ";
    cin>>n;
    cout<<"Here is the array: ";
    if (n<minElement || n>maxElement) {
        cout << "Invalid array size. Please enter a value between 6 and 20" << endl;
        return 1;
    }
    vector<int> arr(n);
    vector<int> found(n, 0);

    arr={1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10};
    arr.resize(n);
    random_device rd;
    default_random_engine rng(rd());
    shuffle(arr.begin(), arr.end(), rng);
    while (true) {
        for (int i = 0; i < n; i++) {
            if (found[i] == 0) {
                cout << "? ";
            } else {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
        cout << "Enter two indices: ";
        cin >> a >> b;
        cout << "The number at index " << a << " is " << arr[a] << endl;
        cout << "The number at index " << b << " is " << arr[b] << endl;
        if (arr[a] == arr[b] && a!=b && a>=0 && b>=0 && a<n && b<n) {
            cout << "Great. The cards are matched" << endl;
            found[a] = 1;
            found[b] = 1;
            cnt += 2;
        } else if (a==b) {
            cout << "The indices are two same numbers , they must be different" << endl;
        }else if (a<0 || b<0) {
            cout << "Invalid indices"<<endl;
        }else if(a>=n || b>=n) {
            cout << "Invalid indice more than elements in array , it must be less" << endl;
        }else {
            cout << "The cards do not match. Try again!" <<endl;
        }
        moves++;
        if (cnt == n) {
            cout << "Great job! You found " << moves << " moves" << endl;
            break;
        }
    }
    return 0;
}
