#include "../include/Report.h"
#include <iostream>
using namespace std;

Report::Report()
    : reportId(""), reportType(""),
      generatedDate(""), content("") {}

Report::Report(string reportId, string reportType,
               string generatedDate, string content)
    : reportId(reportId), reportType(reportType),
      generatedDate(generatedDate), content(content) {}

string Report::getReportId() const { return reportId; }
string Report::getReportType() const { return reportType; }
string Report::getGeneratedDate() const { return generatedDate; }
string Report::getContent() const { return content; }

void Report::setReportType(string reportType) {
    this->reportType = reportType;
}

void Report::setGeneratedDate(string generatedDate) {
    this->generatedDate = generatedDate;
}

void Report::setContent(string content) {
    this->content = content;
}

void Report::displayReport() const {
    cout << "\nReport ID: " << reportId
         << "\nReport Type: " << reportType
         << "\nGenerated Date: " << generatedDate
         << "\nContent: " << content << endl;
}

void Report::generateDailyReport() {
    cout << "\nDaily report generated successfully.\n";
}

void Report::generateWeeklyReport() {
    cout << "\nWeekly report generated successfully.\n";
}

void Report::generateMonthlyReport() {
    cout << "\nMonthly report generated successfully.\n";
}