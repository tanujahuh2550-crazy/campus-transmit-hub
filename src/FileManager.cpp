#include "../include/FileManager.h"

#include <fstream>
#include <iostream>

using namespace std;

bool FileManager::writeData(const string& filename, const vector<string>& data)
{
    ofstream file(filename);

    if (!file)
    {
        cerr << "Error: Unable to open file for writing: " << filename << endl;
        return false;
    }

    for (const string& line : data)
    {
        file << line << endl;
    }

    file.close();
    return true;
}


bool FileManager::appendData(const string& filename, const string& data)
{
    ofstream file(filename, ios::app);

    if (!file)
    {
        cerr << "Error: Unable to open file for appending: " << filename << endl;
        return false;
    }

    file << data << endl;

    file.close();
    return true;
}


vector<string> FileManager::readData(const string& filename)
{
    vector<string> data;
    ifstream file(filename);

    if (!file)
    {
        cerr << "Error: Unable to open file for reading: " << filename << endl;
        return data;
    }

    string line;

    while (getline(file, line))
    {
        if (!line.empty())
        {
            data.push_back(line);
        }
    }

    file.close();

    return data;
}


bool FileManager::fileExists(const string& filename)
{
    ifstream file(filename);

    return file.good();
}