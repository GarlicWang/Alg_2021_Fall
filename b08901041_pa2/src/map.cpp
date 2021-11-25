#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "maxLine.h"

using namespace std;

// input will be like ./mps 12.in 12.out
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "wrong input length" << endl;
        return 0;
    }
    fstream fin;
    fin.open(argv[1], ios::in);
    if (!fin.is_open())
    {
        cout << "fail to open file." << endl;
        return 0;
    }
    fstream fout;
    fout.open(argv[2], ios::out);

    int length_num;
    fin >> length_num;
    length_num /= 2;
    int **data;
    data = new int *[length_num];
    for (int i = 0; i < length_num; i++)
    {
        data[i] = new int[2];
    }
    for (int i = 0; i < length_num; i++)
    {
        fin >> data[i][0] >> data[i][1];
        if (data[i][0] > data[i][1])
        {
            swap(data[i][0], data[i][1]);
        }
    }
    fin.close();
    int *chord;
    chord = new int[2 * length_num];
    for (int i = 0; i < length_num; i++)
    {
        chord[data[i][0]] = data[i][1];
        chord[data[i][1]] = data[i][0];
    }
    for (int i = 0; i < length_num; i++)
    {
        delete[] data[i];
    }
    delete[] data;

    int start = 0;
    int end = 2 * length_num - 1;

    int **Max;
    Max = new int *[2 * length_num];
    for (int i = 0; i < 2 * length_num; i++)
    {
        Max[i] = new int[(2 * length_num) - i];
        for (int j = 0; j < (2 * length_num) - i; j++)
        {
            Max[i][j] = 0;
        }
    }
    int ans = Max_Planar_Subset(chord, Max, start, end);
    fout << ans << endl;

    vector<int> final_start;

    find_line(Max, chord, start, end, final_start);

    for (int i = 0; i < 2 * length_num; i++)
    {
        delete[] Max[i];
    }
    delete[] Max;

    //sorting the answer chord
    sort(final_start.begin(), final_start.end());

    //export the answer to the output file
    for (int i = 0; i < final_start.size(); i++)
    {
        fout << final_start[i] << " " << chord[final_start[i]] << endl;
    }
    delete[] chord;

    fout.close();
}