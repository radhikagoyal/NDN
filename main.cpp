/**
 * @file main.cpp
 * 
 */

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string.h>
#include <iostream>
#include <fstream>

#include <iostream>
#include <fstream>
#include <string>

#include <stdio.h>
#include <string.h>
//#include <ofstream>

using namespace std;


int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
       
    }
    closedir(dp);
    return 0;
}

void parser ( string fname ) 
{
    ifstream ifile;
    ofstream ofile;
    
    int offset;
    string line;
    string search = "Taken Date   : ";


    ifile.open (fname);
    ofile.open ("output.txt", std::ios::app);

    //cout << "opened " << fname << endl;

    if (ifile.is_open()) {
        while(!ifile.eof()) {
            getline(ifile, line);

            if ((offset = line.find(search, 0)) != string::npos) {
                cout << "found: " << search << endl;
                //write this date to file
                //ofile <<
                //break;
            }
        }
        ifile.close();
    }

/*


    //file << "Writing this to a file.\n";
    string str;
    str.clear();

    string * tptr;

    tptr = strstr (file,"Taken Date   : "); //15 chars

    strncpy(str, tptr+15, 19);
    file << str << '\n'; */



}

int main()
{
    string dir = string(".");
    vector<string> files = vector<string>();

    getdir(dir,files);

    for (unsigned int i = 0;i < files.size();i++) {
        cout << files[i] << endl;
        parser(files[i]);
    }


    return 0;
}

