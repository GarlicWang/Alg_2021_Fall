using namespace std;

int Max_Planar_Subset(int *chord, int **Max, int start, int end)
{
    if (start >= end)
    {
        return 0;
    }
    if (Max[start][end - start] != 0)
    {
        return Max[start][end - start];
    }
    if (chord[end] > end || chord[end] < start)
    {
        Max[start][end - start] = Max_Planar_Subset(chord, Max, start, end - 1);
    }
    else if (chord[end] == start)
    {
        Max[start][end - start] = 1 + Max_Planar_Subset(chord, Max, start + 1, end - 1);
    }
    else
    {
        int b = Max_Planar_Subset(chord, Max, start, chord[end] - 1) + 1 + Max_Planar_Subset(chord, Max, chord[end] + 1, end - 1);
        int a = Max_Planar_Subset(chord, Max, start, end - 1);
        if (a >= b)
        {
            Max[start][end - start] = a;
        }
        else
        {
            Max[start][end - start] = b;
        }
    }
    return Max[start][end - start];
}
void find_line(int **Max, int *chord, int start, int end, vector<int> &final_start)
{
    if (start >= end)
    {
        return;
    }
    if (chord[end] > end || chord[end] < start)
    {
        find_line(Max, chord, start, end - 1, final_start);
    }
    else if (chord[end] == start)
    {
        final_start.push_back(start);
        find_line(Max, chord, start + 1, end - 1, final_start);
    }
    else
    {
        if (Max[start][end - 1 - start] >= Max[start][chord[end] - 1 - start] + 1 + Max[chord[end] + 1][end - 1 - (chord[end] + 1)])
        {
            find_line(Max, chord, start, end - 1, final_start);
        }
        else
        {
            final_start.push_back(chord[end]);
            find_line(Max, chord, start, chord[end] - 1, final_start);
            find_line(Max, chord, chord[end] + 1, end - 1, final_start);
        }
    }
}