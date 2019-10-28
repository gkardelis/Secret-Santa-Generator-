#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <Windows.h>

using namespace std;

bool check(vector<string> randOrder, int tempRand, vector<int> values); 
void assign(vector<string> &randOrder, vector<string> listNames, int numPeople);

int main()
{
    int numPeople = 0; 
    vector<string> listNames;
    vector<string> randOrder;
    string temp;

    cout << "How many people are participating: ";
    cin >> numPeople;
    cout << endl;

    //check to make sure there are enough people to give assignments 
    while (numPeople < 3)
    {
        cout << "Not enough people, has to be greater than 3. Re-enter number of participates: ";
        cin >> numPeople;
        cout << endl;
    }

    //get participates names
    for (int i = 1; i <= numPeople; i++)
    {
        cout << "Person " << i << " name: ";
        cin >> temp;
        listNames.push_back(temp);
    }

    //assign people in pairs 
    assign(randOrder, listNames, numPeople);

    cout << endl;

    //Display results 
    for (int i = 0; i < numPeople; i++)
    {
        if(cin.get() == '\n') //detect enter 
        cout << listNames[i] << " hit enter to find who are getting a gift for." << endl;

        if(cin.get() == '\n') 
        {
            system("CLS"); //clear screen to keep assignments anonymous 
            cout << "You are getting a gift for\t" << randOrder[i] << endl;
            cout << "Hit enter to clear screen" << endl << flush; 
            if(cin.get() == '\n')
                system("CLS");
        }
    }
}

bool check(vector<string> randOrder, int tempRand, vector<int> values) //check to see if already assigned this person
{
    for (int k = 0; k < size(values); k++)
    {
        if (values[k] == tempRand)
            return true;
    }
    return false;
}

 void assign(vector<string> &randOrder, vector<string> listNames, int numPeople)
{
    srand(unsigned(time(0)));
    vector<int> values;
    int tempRand;
    //randomly assign people to each other 
    for (int i = 0; i < numPeople; i++)
    {
        bool hasAnAssignment = false;
        tempRand = rand() % numPeople;
        bool alreadyAssigned = check(randOrder, tempRand, values);

        while (hasAnAssignment == false)
        {
            if (alreadyAssigned == false && tempRand != i && tempRand != numPeople)
            {
                randOrder.push_back(listNames[tempRand]);
                values.push_back(tempRand);
                hasAnAssignment = true;
            }
            else
            {
                tempRand = rand() % numPeople;
                alreadyAssigned = check(randOrder, tempRand, values);
            }
        }
    }
}