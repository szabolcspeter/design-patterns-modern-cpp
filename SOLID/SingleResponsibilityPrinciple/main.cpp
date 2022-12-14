#include <iostream>
#include <cstdio>
#include <boost/lexical_cast.hpp>
#include <vector>
#include <fstream>

using namespace std;
using namespace boost;

struct Journal
{
	string title;
	vector<string> entries;

	Journal(const string &title) : title(title) {}

	void add_entry(const string &entry)
	{
		static int count = 1;
		entries.push_back(lexical_cast<string>(count++) + ": " + entry);
	}
};

struct PersistenceManager
{
	static void save(const Journal &j, const string &filename)
	{
		ofstream ofs(filename);
		for (auto &e : j.entries)
			ofs << e << endl;
	}
};

int main() {
	Journal journal{ "Dear Diary" };
	journal.add_entry("I ate a bug");
	journal.add_entry("I cried today");

	PersistenceManager::save(journal, "diary.txt");

	getchar();
	return 0;
}
