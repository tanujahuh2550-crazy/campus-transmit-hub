#ifndef REPORT_H
#define REPORT_H

#include <string>
#include "FileManager.h"

using namespace std;

class Report
{
private:
    FileManager fileManager;

public:
    void generateDailyReport();
    void generateWeeklyReport();
    void generateMonthlyReport();
};

#endif