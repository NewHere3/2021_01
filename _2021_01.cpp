#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <fstream>

using namespace std;

void time(vector<array<int, 10>>& day);

int main()
{
    ifstream duom("Duomenys.txt");
    ofstream rez("Rezultatai.txt");
    int n;
    vector<array<int, 10>> day;
    duom >> n;
    for (int i = 0; i < n; i++)
    {
        array<int, 10> temp = {0};
        duom >> temp[0] >> temp[1] >> temp[2] >> temp[3] >> temp[4] >> temp[5] >> temp[6] >> temp[7] >> temp[8];
        day.push_back(temp);
    }

    time(day);
    int min_time = 24 * 60 + 100; // more than there are minutes in a day
    for (int i = 0; i < day.size(); i++) // find shortest run time
    {
        if (day[i][9] < min_time) { min_time = day[i][9]; }
    }
 
    rez << "Minimalus laikas\n" << min_time << "\nDienos\n";

    for (int i = 0; i < day.size(); i++) // print shortest run time
    {
        if (day[i][9] == min_time) { rez << day[i][0] << ' '; }
    }

    duom.close();
    rez.close();
    return 0;
}

void time(vector<array<int, 10>>& day)
{
    for (int i = 0; i < day.size(); i++)
    {
        if (day[i][0] == 0) { day[i][9] = 24 * 60 + 100; continue; }
        if (day[i][1] == 0) { day[i][9] = 24 * 60 + 100; continue; }
        if (day[i][5] == 0) { day[i][9] = 24 * 60 + 100; continue; }
        day[i][9] = (day[i][3] * 60 + day[i][4]) - (day[i][1] * 60 + day[i][2]) + (day[i][7] * 60 + day[i][8]) - (day[i][5] * 60 + day[i][6]);
    }
    return;
}
