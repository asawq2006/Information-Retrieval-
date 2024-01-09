** this code is a attempt to read a file of documents, built inverted index and provide queries. 
** futher work is needed to read the file from memory 


#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
using namespace std;

struct terms
{
    int line_number;
    int occurance;
};

class InvertedIndex
{
    map <string, vector<terms> > Dictionary;
    map <string, int> docID;
public:
    void addfile(string filename,string index_file);
 };

void InvertedIndex::addfile(string filename, string index_file)
{
    ifstream fp;
    fp.open(filename, ios::in);
     if (!fp)
    {
        cout << "File Not Found\n";
        return;
    }
    string line, term;
    int line_number = 0, term_number = 0;
    while (getline(fp, line))
    {
        line_number++;
        term_number = 0;
        stringstream s(line);
        while (s >> term)
        {
            term_number++;
            if (term_number == 1) {
                docID[term] = line_number;
                term_number++;
                continue;
            }
            if (Dictionary.find(term) != Dictionary.end()) {
                int size = (int)Dictionary[term].size();
                for (int counter = size - 1; counter >= 0; counter--) {
                    if (Dictionary[term][counter].line_number == line_number)
                    {
                        Dictionary[term][counter].occurance++;
                        break;
                    }
                    else {

                        terms obj;
                        obj.line_number = line_number;
                        obj.occurance = 1;
                        Dictionary[term].push_back(obj);
                        break;

                    }
                }

            }
            else {
                terms obj;
                obj.line_number = line_number;
                obj.occurance = 1;
                Dictionary[term].push_back(obj);
            }

        }

    }
    fp.close();

    ofstream index123(index_file);
    if (index123.is_open()) {

        for (auto it = Dictionary.cbegin(); it != Dictionary.cend(); ++it) {
            index123 << (*it).first << " ";
            vector <terms> temp = (*it).second;
            for (int j = 0; j < temp.size(); j++) {
                index123 << "<" << temp[j].line_number << "," << temp[j].occurance << "> ";
            }
            index123 << endl;
        }
    }
    index123.close();

    ofstream forDocIDs("DocIds");
    if (forDocIDs.is_open()) {
        for (auto it = docID.cbegin(); it != docID.cend(); ++it) {
            forDocIDs << (*it).first << " " << (*it).second << endl;
        }
    }
    forDocIDs.close();
}

int main(int argc, char* argv[])
{

    InvertedIndex Data;
    
        Data.addfile(argv[1],argv[2]);
   
    

}


