#include "file2tab.h"

void file2tab::printTab()
{
    for (int i = 0; i < nb_to_show; i++)
    {
        cout << tab.at(i) << ' ';
    }
    cout << endl;
}

int file2tab::getLen()
{
    return nb_to_show;
}

void file2tab::setLen(int nb_to_show)
{
    this->nb_to_show = nb_to_show;
}

void file2tab::vector2tab(unsigned int tab[])
{
    for(int i; i < this->tab.size(); i++ )
    {
        tab[i] = this->tab.at(i);
    }
}

file2tab::file2tab(string filename, int nb, int tabl[])
{
    int j = 0;
    string var;

    ifstream fp;
    fp.open(filename);

    if(!fp)
	{
		cerr << "Cannot open the File : "<<filename<<endl;
	}

    while (j < nb)
    {
        getline(fp, var);
        tab.push_back(stoul(var));
        j++;
    }
    fp.close();
}

file2tab::~file2tab(){}