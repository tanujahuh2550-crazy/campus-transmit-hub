#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>

using namespace std;

class FileManager
{
public:
    bool writeData(const string& filename, const vector<string>& data);
    bool appendData(const string& filename, const string& data);
    vector<string> readData(const string& filename);
    bool fileExists(const string& filename);
};

#endif