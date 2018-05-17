#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int calc_min_cut(vector< vector<int> > graph)
{
	vector<int> vertices;
	for(int i = 1; i <= graph.size()-1; i++)
		vertices.push_back(i);

	while(vertices.size() > 2)
	{										
		int	a = vertices[rand() % vertices.size()]-1;		//choose an edge uniformly at random
		int b = rand() % graph[a].size();

		int u = a+1;
		int v = graph[a][b];

		graph[a].erase(graph[a].begin()+b);

		for(int i = 0; i < graph[v-1].size(); i++)		//contract the edge
		{
			int cur = graph[v-1][i];
			if(cur == u) continue;

			for(int j = 0; j < graph[cur-1].size(); j++)
				if(graph[cur-1][j] == v)
					graph[cur-1][j] = u;

			graph[a].push_back(cur);
		}

		for(int i = 0; i < graph[a].size();)		//remove self loops
		{	
			if(graph[a][i] == v)
				graph[a].erase(graph[a].begin()+i);
			else
				i++;
		}

		graph[v-1].clear();
		graph[v-1].push_back(0);
		for(int i = 0; i < vertices.size(); i++)
		{
			if(vertices[i] == v)
			{
				vertices.erase(vertices.begin()+i);
				break;
			}
		}
	}

	return graph[vertices[0]-1].size();			//return min-cut	
}

int main()
{
	vector< vector<int> > graph;
	vector<int> temp;
	srand(time(nullptr));
	fstream fp;
	fp.open("kargerMinCut.txt");

	while(!fp.eof())
	{
		string line;
		getline(fp, line);
		istringstream is(line);
		int n;
		is >> n;
		while(is >> n)
			temp.push_back(n);

		graph.push_back(temp);
		temp.clear();
	}

	int min_cut = 999999, temp1;
	int n = graph.size();
	for(int i = 0; i < n; i++)
	{
		temp1 = calc_min_cut(graph);
		if(temp1 < min_cut)
			min_cut = temp1;
	}

	cout << min_cut << endl;
	return 0;
}