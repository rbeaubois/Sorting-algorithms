#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class file2tab
{
private:
    string filename;
    vector<unsigned int> tab;
    int nb_to_show;
public:
    file2tab(string filename, int nb, unsigned int tabl[]);
    ~file2tab();
    void printTab();
    void setLen(int nb_to_show);
    void vector2tab(unsigned int tab[]);
    int getLen();
};


