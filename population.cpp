#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

int main(){
    ifstream inFile;
    inFile.open("pop.txt");
    if(inFile.fail()){
        cout<<"Unable to open file"<<endl;
        return -1;
    }
    string city;
    int population,ast;
    string city1,city2;
    int city1_pop=0,city2_pop=0,current_pop;
    cout<<"Enter how many people each asterisk represents: ";
    cin>>ast;
    cout<<"\tCity Populations"<<endl;
    cout<<"-----------------------------------"<<endl;

    while(!inFile.eof()){
        getline(inFile, city);
        inFile>>population;
        current_pop = population;
        population /= ast;
        cout<<setw(15)<<left<<city;
        while(population>0){
            cout<<"*";
            population--;
        }
        cout<<endl;
        if(city1_pop < current_pop)
        {
            city2_pop = city1_pop;
            city2 = city1;
            city1_pop = current_pop;
            city1 = city;
        }
        else if (city2_pop<current_pop)
        {
            city2_pop = current_pop;
            city2 = city;
        }
        inFile.ignore();
    }
    cout<<"-----------------------------------"<<endl;
    cout<<"KEY: (*) -> "<<ast<<" people"<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<"   Top 2 City "<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<setw(15)<<left<<city1<<"   "<<city1_pop<<endl;
    cout<<setw(15)<<left<<city2<<"   "<<city2_pop<<endl;
    cout<<"-----------------------------------"<<endl;
    inFile.close();
    return 0;
}     