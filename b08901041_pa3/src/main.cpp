#include "header.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "wrong input length" << endl;
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
    char graph_type;
    int ver_num, edge_num;
    fin >> graph_type >> ver_num >> edge_num;
    int h, t, w;
    vector<int> head, tail, weight, del;
    for (int i = 0; i < edge_num; i++)
    {
        fin >> h >> t >> w;
        head.push_back(h);
        tail.push_back(t);
        weight.push_back(w);
    }
    fin.close();
    if (graph_type == 'u')
    {

        fout << Kruskal(head, tail, weight, del, ver_num, edge_num) << endl;
        for (int i = 0; i < del.size(); i++)
        {
            fout << head[del[i]] << " " << tail[del[i]] << " " << weight[del[i]] << endl;
        }
        fout.close();
    }
    else if (graph_type == 'd')
    {
        Graph my_graph(ver_num);
        my_graph.Kruskal_d(head, tail, weight, edge_num);
        my_graph.write(fout);
        fout.close();
    }
}