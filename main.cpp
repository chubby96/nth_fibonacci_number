#include <iostream>
#include <vector>

using namespace std;

/* This program calculates the Fibonacci numbers using vectors. The method for counting the sum of the previous numbers is based on the written addition method.
(The Fibonacci sequence is calculated with: (n-2)th number+(n-1)th number=nth number.)
I might upgrade the code later with more features and better optimized running time, but this did the trick for now*/


vector<int> fibonacci(int n) {

vector<int> first;  // The (n-2)th number.
vector<int> second;  // The n-1)th number.
vector<int> requestednum;  // The nth number.
vector<vector<int>>numbers; // This is where we store the sequence.

first.push_back(0);   // The first two number is 0 and 1.
second.push_back(1);    // The first two number is 0 and 1.

int resnum =0;

    for (int i=0; i<n;i++){   //This for loop is how many times we do the addition on the previous two number of the sequence.

    bool endofnum = false;
    int j=0;
    int k=0;
    requestednum.clear();
    resnum=0;   // This is the remainder.

        while (endofnum ==false){  // The addition of the vectors is in the while loop.
            int nrsinglesum=0;          // nrsinglesum means notrightsinglesum, which is the sum of two single digit. We need to divide that by 10 and the remainder.
                    if(k==second.size()){
                        if(resnum!=0){
                            requestednum.push_back(resnum);
                        }
                        break;
                    }
                    if(j<first.size()){
                        nrsinglesum= first[j]+second[k]+resnum;
                    }
                    else{
                        nrsinglesum=second[k]+resnum;
                    }
            int rsinglesum=0;  //rsinglesum is the right singlesum.

                    if(nrsinglesum>10){
                        resnum =0;
                        rsinglesum= nrsinglesum%10;
                        resnum=1;
                    }
                    else if(nrsinglesum==10){
                        resnum =0;
                        rsinglesum=0;
                        resnum=1;
                    }
                    else if(nrsinglesum<10){
                        resnum =0;
                        rsinglesum= nrsinglesum;
                        }

            requestednum.push_back(rsinglesum);
            j++;
            k++;
        }
    numbers.push_back(requestednum);   // We store the number in the numbers vector.
    first = second;                 //We switch the n-2th and n-1th number for the calculation of the next nth number.
    second =numbers.back();         //We switch the n-2th and n-1th number for the calculation of the next nth number.
    }
return numbers.back();
}


int main()
{
    int nthnumber;
    cout<< "This program gives you the nth Fibonacci number. Type the n in the next line. "<<endl;
    cin>> nthnumber;

    vector<int> fibonaccinum=fibonacci(nthnumber-1);
    cout << endl;
    cout <<"The number is: ";

    for(int i=(fibonaccinum.size()-1);i>=0;i--){
        cout<< fibonaccinum[i];
    }

    cout << endl;
    cout << endl;
    cout<<"Number of digits: "<<fibonaccinum.size()<<endl;
    cout << endl;
    cout << endl;
    cout<< "---------"<<endl;
    cout<<" THE END"<<endl;

    return 0;
}
