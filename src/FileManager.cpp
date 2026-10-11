#include "../include/FileManager.h"

#include <fstream>
#include <iostream>

bool FileManager::writeData(const std::string& filename,
                            const std::vector<std::string>& data)
{
    std::ofstream file(filename);

    if (!file)
    {
        std::cerr << "Error: Unable to open file for writing: "
                  << filename << std::endl;
        return false;
    }

    for (const std::string& line : data)
    {
        file << line << std::endl;
    }

    return file.good();
}

bool FileManager::appendData(const std::string& filename,
                             const std::string& data)
{
    std::ofstream file(filename, std::ios::app);

    if (!file)
    {
        std::cerr << "Error: Unable to open file for appending: "
                  << filename << std::endl;
        return false;
    }

    file << data << std::endl;

    return file.good();
}

std::vector<std::string> FileManager::readData(
    const std::string& filename)
{
    std::vector<std::string> data;
    std::ifstream file(filename);

    if (!file)
    {
        std::cerr << "Error: Unable to open file for reading: "
                  << filename << std::endl;
        return data;
    }

    std::string line;

    while (std::getline(file, line))
    {
        if (!line.empty())
        {
            data.push_back(line);
        }
    }

    return data;
}

bool FileManager::fileExists(const std::string& filename)
{
    std::ifstream file(filename);
    return file.good();
}
