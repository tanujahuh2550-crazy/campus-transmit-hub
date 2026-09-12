#include "../include/Report.h"

#include <iostream>
#include <ctime>

using namespace std;

void Report::generateDailyReport()
{
    string report = "Daily Report | Generated successfully";

    if (fileManager.appendData("data/reports.txt", report))
    {
        cout << "\nDaily report generated successfully.\n";
    }
    else
    {
        cout << "\nFailed to generate daily report.\n";
    }
}


void Report::generateWeeklyReport()
{
    string report = "Weekly Report | Generated successfully";

    if (fileManager.appendData("data/reports.txt", report))
    {
        cout << "\nWeekly report generated successfully.\n";
    }
    else
    {
        cout << "\nFailed to generate weekly report.\n";
    }
}


void Report::generateMonthlyReport()
{
    string report = "Monthly Report | Generated successfully";

    if (fileManager.appendData("data/reports.txt", report))
    {
        cout << "\nMonthly report generated successfully.\n";
    }
    else
    {
        cout << "\nFailed to generate monthly report.\n";
    }
}