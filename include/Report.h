#ifndef REPORT_H
#define REPORT_H

#include <string>
using namespace std;

class Report {
private:
    string reportId;
    string reportType;
    string generatedDate;
    string content;

public:
    Report();
    Report(string reportId, string reportType,
           string generatedDate, string content);

    string getReportId() const;
    string getReportType() const;
    string getGeneratedDate() const;
    string getContent() const;

    void setReportType(string reportType);
    void setGeneratedDate(string generatedDate);
    void setContent(string content);

    void displayReport() const;
};

#endif