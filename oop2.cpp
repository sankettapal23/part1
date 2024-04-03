#include <iostream>
#include <cstring>

class Student {
private:
    char* name;
    int rollNumber;
    char className[50];
    char division;
    char dob[11];
    char bloodGroup[5];
    char* address;
    long long phoneNumber;
    char* drivingLicenseNumber;
    static int studentCount;

public:
    // Constructor
    Student(const char* n, int roll, const char* cls, char div, const char* birth, const char* blood, const char* addr, long long phone, const char* dl) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        rollNumber = roll;
        strcpy(className, cls);
        division = div;
        strcpy(dob, birth);
        strcpy(bloodGroup, blood);
        address = new char[strlen(addr) + 1];
        strcpy(address, addr);
        phoneNumber = phone;
        drivingLicenseNumber = new char[strlen(dl) + 1];
        strcpy(drivingLicenseNumber, dl);
        studentCount++;
    }

    // Copy Constructor
    Student(const Student& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        rollNumber = other.rollNumber;
        strcpy(className, other.className);
        division = other.division;
        strcpy(dob, other.dob);
        strcpy(bloodGroup, other.bloodGroup);
        address = new char[strlen(other.address) + 1];
        strcpy(address, other.address);
        phoneNumber = other.phoneNumber;
        drivingLicenseNumber = new char[strlen(other.drivingLicenseNumber) + 1];
        strcpy(drivingLicenseNumber, other.drivingLicenseNumber);
        studentCount++;
    }

    // Destructor
    ~Student() {
        delete[] name;
        delete[] address;
        delete[] drivingLicenseNumber;
        studentCount--;
    }

    // Static member function to get student count
    static int getStudentCount() {
        return studentCount;
    }

    // Friend class to access private members
    friend class Database;

    // Display student information
    void displayStudentInfo() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Roll Number: " << rollNumber << std::endl;
        std::cout << "Class: " << className << std::endl;
        std::cout << "Division: " << division << std::endl;
        std::cout << "Date of Birth: " << dob << std::endl;
        std::cout << "Blood Group: " << bloodGroup << std::endl;
        std::cout << "Address: " << address << std::endl;
        std::cout << "Phone Number: " << phoneNumber << std::endl;
        std::cout << "Driving License Number: " << drivingLicenseNumber << std::endl;
    }
};

int Student::studentCount = 0;

class Database {
public:
    // Add a new student to the database
    static void addStudent(Student* students[], int& studentIndex, Student* newStudent) {
        students[studentIndex++] = newStudent;
    }

    // Find and display a student's information by roll number
    static void findStudentByRollNumber(Student* students[], int studentIndex, int rollNumber) {
        for (int i = 0; i < studentIndex; i++) {
            if (students[i]->rollNumber == rollNumber) {
                students[i]->displayStudentInfo();
                return;
            }
        }
        std::cout << "Student with Roll Number " << rollNumber << " not found in the database." << std::endl;
    }
};

int main() {
    const int MAX_STUDENTS = 100;
    Student* students[MAX_STUDENTS];
    int studentIndex = 0;

    // Create and add students to the database
    Student student1("John Doe", 101, "12th", 'A', "01/05/2000", "AB+", "123 Main St, City", 1234567890, "DL12345");
    Student student2("Alice Smith", 102, "11th", 'B', "03/10/2001", "O-", "456 Elm St, Town", 9876543210, "DL67890");

    Database::addStudent(students, studentIndex, &student1);
    Database::addStudent(students, studentIndex, &student2);

    // Display student count
    std::cout << "Total Students: " << Student::getStudentCount() << std::endl;

    // Find and display a student by roll number
    Database::findStudentByRollNumber(students, studentIndex, 102);

    // Clean up memory
    for (int i = 0; i < studentIndex; i++) {
        delete students[i];
    }

    return 0;
}
