#include <iostream>
#include <vector>
#include<assert.h>
using namespace std;

/*Sarah Ruth Nicholls*/

// function declarations
void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right);
void mergeSortedLists(vector<int>& a, vector<int>& tmp, int left, int middle, int right);

int main() {

    // get input: first is random seed, second is vector length
    int seed, length;
    cout<<"Please enter the seed and vector length"<<endl;
    cin >> seed >> length;
    srand(seed);

    vector<int> v(length);  // vector to be sorted
    vector<int> t(length);  // temporary workspace
    // unit test for merge

   vector<int>test={4,5,6,2};
   vector<int>testTemp={0, 0, 0, 0};
   cout<<"Unit Test Running"<<endl;

    mergeSortedLists(test,testTemp, 0,1,3);
    for(int i = 1; i < test.size()-1; i++) {
        assert(test.at(i-1) <= testTemp.at(i));
    }

    //print unit test
   /*for(int i = 0; i < testTemp.size()-1; i++) {
        cout << testTemp.at(i) << '\t';
    }
    cout << endl;*/

    // initialize and print input
    for(int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // sort v
    mergeSort(v,t,0,v.size()-1);


    // print output
    for(int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // check output, make sure it's sorted
    for(int i = 1; i < v.size(); i++) {
        assert(v.at(i-1) <= v.at(i));
    }

    return 0;
}

void mergeSortedLists(vector<int>& a, vector<int>& tmp, int left, int middle, int right) {
    int i=left;
    int j=middle+1;
    int k=left;

    while(k<right){

        if(a.at(i)<=a.at(j)){
            tmp.at(k)=a.at(i);
            i++;
            k++;
        }else{
            tmp.at(k)=a.at(j);
            j++;
            k++;
        }

    }
    //adds end of vector if remaining values are in right half

        while(j<=right){
            tmp.at(k)=a.at(j);
            j++;
        }


    //adds end of vector if remaining values are in left half

        while(i<=middle){
            tmp.at(k)=a.at(i);
            i++;
        }
for(int l=left;l<=k;l++){
    a.at(l)=tmp.at(l);
}


    for(int l=0;l<tmp.size();l++){

        cout<<tmp.at(l)<<" ";
    }
    cout<<endl;

}
void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right) {

    //base case
    int n = (right +left)/2;
    if (left==right) {
        return;
    } else if (left < right) {
    // recursive step
    mergeSort(a, tmp, left, n );
    mergeSort(a, tmp, n  + 1, right);

    //cout<<n;
    //sorts list
    mergeSortedLists(a, tmp, left, (n / 2)+1, right);

}



}




