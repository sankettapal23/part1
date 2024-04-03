#include <iostream>
#include <string>
#include<stdexcept>
using namespace std;
class Student {
private:
    string name;
    int rollNumber;
    string className;
    string division;
    string dateOfBirth;
    string bloodGroup;
    long contactNo;
    string address;
    long telephoneNo;
    string drivingLicenseNo;

    // Static member for counting students
    static int studentCount;

public:
    // Constructor
    Student(const string& n, int roll, const string& cls, const string& div,
            const string& dob, const string& bg, long cn, const string& addr,
            long tn, const string& dl) : name(n), rollNumber(roll), className(cls),
            division(div), dateOfBirth(dob), bloodGroup(bg), contactNo(cn), address(addr),
            telephoneNo(tn), drivingLicenseNo(dl) {
        studentCount++;
    }

    // Default constructor
    Student() : rollNumber(0), contactNo(0), telephoneNo(0) {
        studentCount++;
    }

    // Copy constructor
    Student(const Student& other) {
        name = other.name;
        rollNumber = other.rollNumber;
        className = other.className;
        division = other.division;
        dateOfBirth = other.dateOfBirth;
        bloodGroup = other.bloodGroup;
        contactNo = other.contactNo;
        address = other.address;
        telephoneNo = other.telephoneNo;
        drivingLicenseNo = other.drivingLicenseNo;
        studentCount++;
    }

    // Destructor
    ~Student() {
        studentCount--;
    }

    // Static member function to get the count of students
    static int getStudentCount() {
        return studentCount;
    }

    // Display student information
    void displayInfo() {
        cout << "Name: " << name << "\n";
        cout << "Roll Number: " << rollNumber << "\n";
        // Display other information...
    }
};

// Initialize the static member
int Student::studentCount = 0;

int main() {
    try {
        Student student1("John Doe", 101, "Class A", "A", "01/01/2000", "A+", 1234567890, "123 Main St",
                        9876543210, "DL12345");
        Student student2;
        Student student3 = student1;  // Copy constructor

        student1.displayInfo();
        student2.displayInfo();
        student3.displayInfo();

        cout << "Total Students: " << Student::getStudentCount() << "\n";
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}