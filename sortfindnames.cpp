#include<iostream>  //iostream and file handling libraries cin cout
#include<fstream>  //fstream for file operations ofstream fout fout.close  
#include<string>   //string manipulation library strings   
#include<iomanip>   //iomanip for formatting output setw

using namespace std;    

void sortnames (string names[], string rank[], int age[], int n) { //insertion sort
    string tempname, temprank;
    int tempage;
    for (int i=1; i<n; i++) {
    tempname = names[i];
    temprank = rank[i];
    tempage = age[i];
    int j = i-1;
    while (j>=0 && names[j]>tempname) {
        names[j+1] = names[j];
        rank[j+1] = rank[j];
        age[j+1] = age[j];
        j--;
    }
    names[j+1] = tempname;
    rank[j+1] = temprank;
    age[j+1] = tempage;
        }
    }

void findname (string names[], string rank[], int age[], int n, string searchname, int& place) { //binary search
   int left = 0;
   int right = n - 1;
   int mid;
    while(left <= right){
        mid = left + (right - left) / 2;
        if(names[mid] == searchname){
            place = mid;
            return;
        }
        else if(names[mid] < searchname){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }}
}

    int main() {  
 //main function
    ofstream fout ("sorted_names.txt", ios::out | ios::app); //output file //appending mode
    string names[100], rank[100];
    int age[100], PLACE;
    cout << "Enter number of entries: (<100) ";
    int n;
    cin >> n;
    cout << "Enter names, ranks, and ages: " << endl; 
    for (int i=0; i<n; i++) {
        cin >> names[i] >> rank[i] >> age[i];
    }
    sortnames (names, rank, age, n); //sorting function call
    cout << "Names sorted succesfully! " << endl;
    for(int i=0; i<n; i++) 
        fout << "Name: " << names[i] << setw(10) << "Rank: " << rank[i] << setw(5) << "Age: " << age[i] << endl;
    cout << "Enter name to search: ";
    string searchname;
    cin >> searchname;
    findname (names, rank, age, n, searchname, PLACE); //search function call
    if (searchname != names[PLACE]) {
        cout << "Name not found." << endl;
        }
        else {cout << "Name found at position: " << PLACE + 1 << endl;
        cout<<"Name "<<searchname<<" found and details written to file."<<endl;
    fout << "Name searched: " << searchname << " rank: " << rank[PLACE] << " Age: " << age[PLACE] << endl;}
    fout.close(); //losing file
    return 0;
    }
