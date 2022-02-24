#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 100

struct City
{
    string name;
    double population;
}city[MAXSIZE];
 
void sort_by_city(City city[],int numCities)
{
    struct  City temp;
    
    for(int i=0;i<numCities;i++)
    {
        for(int j=i;j<numCities;j++)
        {
            if(city[i].name>city[j].name)
            {
                temp = city[j];
                city[j] = city[i];
                city[i] = temp;
            }
        }
    }
}

 
void sort_by_population(City city[],int numCities)
{
    struct  City temp;
    
    for(int i=0;i<numCities;i++)
    {
        for(int j=i;j<numCities;j++)
        {
            if(city[i].population<city[j].population)
            {
                temp = city[j];
                city[j] = city[i];
                city[i] = temp;
            }
        }
    }
}

void printTopCity(City city[])
{
    cout<<"\tTop 2 cities"<<endl;
    cout<<"====================================="<<endl;
    cout<<setw(20)<<left<<city[0].name<<" "<<city[0].population<<endl;
    cout<<setw(20)<<left<<city[1].name<<" "<<city[1].population<<endl;
    cout<<"====================================="<<endl;
}
void readCities(City city[],int &numCities)
{
    ifstream inFile;
    inFile.open("pop.txt");
    if(inFile.fail()){
        cout<<"Unable to open file"<<endl;
        exit(0);
    }
    while (!inFile.eof())
    {
        getline(inFile,city[numCities].name);
        inFile>>city[numCities].population;
        numCities++;
        inFile.ignore();
    }
    sort_by_city(city,numCities);
    inFile.close();
}

void printPopulations(City city[],int numCities,int ast)
{
    int population;
    cout<<"====================================="<<endl;
    for(int i=0;i<numCities;i++)
    {
        cout<<setw(15)<<left<<city[i].name;
        population = city[i].population;
        population /= ast;
        while(population>0){
            cout<<"*";
            population--;
        }
        cout<<endl;
    }
    cout<<"====================================="<<endl;
}

int main()
{
    int ast,numCities=0;
    readCities(city,numCities);
    cout<<"Enter how many people each asterisk represents: ";
    cin>>ast;
    cout<<"\tCity Population"<<endl;
    printPopulations(city,numCities,ast);
    sort_by_population(city,numCities);
    cout<<"   Cities sorted by population"<<endl;
    printPopulations(city,numCities,ast);
    printTopCity(city);
    return 0;
}
