#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    vector<int> arr = {64, 25, 13, 22, 11};
    selectionSort(arr);
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}


#include <iostream>
using namespace std;

// 1 dimensi
// int main(){
//     int myArray[5]={10,20,30,40,50};
//     for(int i=0; i<5 ;i++){cout<<"value" <<i<<"is"<<myArray[i]<<endl;}
// }

//2 dimensi
int main(){
int arr[3][4];
for(int i=0;i<3;i++)
{
    for(int j=0;j<4;j++){
        arr[i][j]=i*j;
    }
}
for(int i=0;i<3;i++)
{
    for(int j=0;j<4;j++){
        cout<<arr[i][j]<< " ";}
        cout <<endl;}
}