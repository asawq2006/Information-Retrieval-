#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
using namespace std;

class InvertedIndex
{
 
public:
    void search(string filename, string word);
};

void InvertedIndex::search(string filename, string word) {

    ifstream fp;
    fp.open(filename, ios::in);
    if (!fp)
    {
        cout << "File Not Found\n";
        return;
    }

    string line, word2;
    int line_number = 0, word_number = 0;
    while (getline(fp, line))
    {
        line_number++;
        word_number = 0;
        stringstream s(line);
        while (s >> word2)
        {
            if (word == word2)
            {
                cout << line << endl;
                break;
            }
            break;
        }

    }
    fp.close();
}
int main(int argc, char* argv[])
{
    InvertedIndex Data;
   Data.search(argv[1], argv[2]);
}


