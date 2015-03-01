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
    string search_time = "Taken Date   : ";
    string search_lat = "Latitude:";
    string search_long = "Longitude:";
  
    char output_time[100];
    char output_lat[100];
    char output_long[100];




    ifile.open ("./bulkr/"+fname);

    if (ifile.is_open()) {
        while(!ifile.eof()) {
            getline(ifile, line);
            
            if ((offset = line.find(search_time, 0)) != string::npos) {
                line.copy(output_time, 19, offset+15);
                output_time[20] = '\0';
                cout << output_time << endl;
            }
            if ((offset = line.find(search_lat, 0)) != string::npos) {
                line.copy(output_lat, 5, offset+9);
                output_lat[6] = '\0';
                cout << output_lat << endl;
            }
            if ((offset = line.find(search_long, 0)) != string::npos) {
                line.copy(output_long, 5, offset+10);
                output_long[6] = '\0';
                cout << output_long << endl;
            }
        }
      
        ifile.close();
    }

    ofile.close();

}

int main()
{
    string dir = string("./bulkr/");
    vector<string> files = vector<string>();

    getdir(dir,files);

    for (unsigned int i = 0;i < files.size();i++) {
        //cout << files[i] << endl;
        parser(files[i]);
    }


    return 0;
}

