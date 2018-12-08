#include <iostream>
#include <string>
using namespace std;

template <typename T>

inline void sort(T x[], int size) {
    for (int i = 0; i < size - 2; i++)
        for (int j = 0; j < size - 1; j++)
            if (x[j] > x[j + 1])
                swap(x[j], x[j + 1]);
}

template <typename T>
void print(T x[], int size){
    for(int i = 0; i < size; i++){
        cout << x[i] << ' ';
    }
}

template <typename T>
T sum(T x[], int size){
    T sum;
    for(int i=0; i < size; i++){
        sum+= x[i];
    }
    return sum;

}


int main() {
	int a[] = {5, 4, 3, 1, 7, 8, 9, 2, 1};
	sort(a, sizeof(a)/sizeof(int));
	print(a, sizeof(a)/sizeof(int));
	
	double b[] = {5.5, 4.5, 1.2, 2.9, 9.2, 5.2};
	sort(b, sizeof(b)/sizeof(double));
	print(b, sizeof(b)/sizeof(double));

	cout << sum(a, sizeof(a)/sizeof(int)) << '\n';
	cout << sum(b, sizeof(b)/sizeof(double)) << '\n';

	string c[] = {"yo", "ho", "test", "foo", "bar"};
	sort(c, sizeof(c)/sizeof(string));
	print(c, sizeof(c)/sizeof(string));
	//TODO?	cout << sum(c, sizeof(c)/sizeof(string)) << '\n';
}
