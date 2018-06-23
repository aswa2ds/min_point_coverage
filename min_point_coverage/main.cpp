#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class tree {
private:
	vector<int> in;
	vector<int> out;
	vector<int> parrent;
public:
	tree();
	void add_edge(int, int);
	void print();
	void travel();
};

int main() {
	string line;
	tree T;
	while (getline(cin, line, '\n')) {
		istringstream ss(line);
		int u, v;
		ss >> u;
		while (ss >> v)
			T.add_edge(u, v);
	}
	//T.print();
	T.travel();
	return 0;
}

tree::tree() {
	in.push_back(1);
	out.push_back(0);
	parrent.push_back(-1);
}

void tree::add_edge(int u, int v) {
	in.push_back(1);
	out.push_back(0);
	parrent.push_back(u);
}

void tree::print() {
	for (int i = 0; i < parrent.size(); ++i)
		cout << parrent[i] << " ";
	cout << endl;
}

void tree::travel() {
	for (int i = parrent.size() - 1; i > 0; --i) {
		int u = parrent[i];
		in[u] += (in[i] < out[i]) ? in[i] : out[i];
		out[u] += in[i];
	}
	cout << "I have read the rules about plagiarism punishment" << endl;
	int coverage = (in[0] < out[0]) ? in[0] : out[0];
	if (parrent.size() == 1)	coverage = 1;
	cout << coverage << endl;
}