#ifndef REPORT_H
#define REPORT_H

#include <string>
#include "FileManager.h"

using namespace std;

class Report
{
private:
    // Report data
    string reportId;
    string reportType;
    string generatedDate;
    string content;

    // File handling
    FileManager fileManager;

public:
    // Constructors
    Report();
    Report(string reportId, string reportType,
           string generatedDate, string content);

    // Getters
    string getReportId() const;
    string getReportType() const;
    string getGeneratedDate() const;
    string getContent() const;

    // Setters
    void setReportType(string reportType);
    void setGeneratedDate(string generatedDate);
    void setContent(string content);

    // Report functions
    void displayReport() const;
    void generateDailyReport();
    void generateWeeklyReport();
    void generateMonthlyReport();
};

#endif