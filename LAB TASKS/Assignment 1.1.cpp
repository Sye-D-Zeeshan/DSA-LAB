#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    string jobTitle;
    string dateOfJoining;

public:
    void getData() {
        cout << "Enter name: ";
        getline(cin, name);

        cout << "Enter job title: ";
        getline(cin, jobTitle);

        cout << "Enter date of joining: ";
        getline(cin, dateOfJoining);
    }

    void displayData() {
        cout << "Name: " << name << endl;
        cout << "Job Title: " << jobTitle << endl;
        cout << "Date of Joining: " << dateOfJoining << endl;
    }
};

class Teacher : public Employee {
protected:
    string qualification;

public:
    void getQualification() {
        cout << "Enter qualification: ";
        getline(cin, qualification);
    }

    void displayQualification() {
        cout << "Qualification: " << qualification << endl;
    }
};

class RegularTeacher : public Teacher {
protected:
    double monthlySalary;

public:
    void getMonthlySalary() {
        cout << "Enter monthly salary: ";
        cin >> monthlySalary;
    }

    void displayMonthlySalary() {
        cout << "Monthly Salary: " << monthlySalary << endl;
    }
};

class VisitingTeacher : public Teacher {
protected:
    double payRate;
    int hoursWorked;

public:
    void getPayRateAndHours() {
        cout << "Enter pay rate: ";
        cin >> payRate;

        cout << "Enter hours worked in a month: ";
        cin >> hoursWorked;
    }

    void displayPayRateAndHours() {
        cout << "Pay Rate: " << payRate << endl;
        cout << "Hours Worked: " << hoursWorked << endl;
    }
};

class Manager : public Employee {
protected:
    int totalExperience;

public:
    void getTotalExperience() {
        cout << "Enter total experience (in years): ";
        cin >> totalExperience;
    }

    void displayTotalExperience() {
        cout << "Total Experience: " << totalExperience << " years" << endl;
    }
};

int main() {
    RegularTeacher regularTeacher;
    VisitingTeacher visitingTeacher;
    Manager manager;

    cout << "Enter details for Regular Teacher:" << endl;
    regularTeacher.getData();
    regularTeacher.getQualification();
    regularTeacher.getMonthlySalary();

    cout << "\nEnter details for Visiting Teacher:" << endl;
    visitingTeacher.getData();
    visitingTeacher.getQualification();
    visitingTeacher.getPayRateAndHours();

    cout << "\nEnter details for Manager:" << endl;
    manager.getData();
    manager.getTotalExperience();

    cout << "\nDetails of Regular Teacher:" << endl;
    regularTeacher.displayData();
    regularTeacher.displayQualification();
    regularTeacher.displayMonthlySalary();

    cout << "\nDetails of Visiting Teacher:" << endl;
    visitingTeacher.displayData();
    visitingTeacher.displayQualification();
    visitingTeacher.displayPayRateAndHours();

    cout << "\nDetails of Manager:" << endl;
    manager.displayData();
    manager.displayTotalExperience();

    return 0;
}
