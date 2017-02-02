#ifndef __MVC_H
#define __MVC_H

#include <iostream>

class Student {
    std::string name;
    int no;
public:
    void setName(const std::string &str) {
        name = str;
    }
    void setNo(int no) {
        this->no = no;
    }

    std::string& getName() {
        return name;
    }

    int getNo() {
        return no;
    }
};

class StudentView {
public:
    void printStudentDetails(const std::string &studentName, int studentNo) {
        std::cout << studentName << " " << studentNo << std::endl;
    }
};

class StudentController {
    Student student;
    StudentView view;
public:
    StudentController(Student &s, StudentView &v): student(s), view(v) {}

    void setStudentName(const std::string &str) {
        student.setName(str);
    }

    void setStudentNo(int no) {
        student.setNo(no);
    }

    void updateView() {
        view.printStudentDetails(student.getName(), student.getNo());
    }
};

#endif
