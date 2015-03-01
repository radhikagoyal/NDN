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
#include <stdlib.h>
//#include <ofstream>
#include <cstdio>
#include <cstdlib>

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
    
    int offset = 0;
    string line;
    string search = "Taken Date   : ";
    //string outline;
    char outline[100];
    //string result(19, ' ');



    ifile.open (fname);
    ofile.open ("output.txt", std::ios::app);

    if (ifile.is_open()) {
        while(!ifile.eof()) {
            getline(ifile, line);
            //cout << "looking through" << endl;
            if ((offset = line.find(search, 0)) != string::npos) {
                //cout << "found: " << offset << fname << endl;
                //cout << line << endl;
                line.copy(outline, 19, offset+15);
                outline[20] = '\0';
                cout << outline << endl;
                break; 
            }
        }
        //fread(outline, 1, 19, ifile);
        //ifile.seekg(offset);
        //ifile.read(&result[0], 19);
        //cout << result << endl;
        ifile.close();
    }

    ofile.close();

}

int main()
{
    string dir = string("./Bulkr/");
    vector<string> files = vector<string>();

    getdir(dir,files);

    for (unsigned int i = 0;i < files.size();i++) {
        //cout << files[i] << endl;
        parser(files[i]);
    }


    return 0;
}

