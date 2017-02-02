#include <iostream>
#include "MVC.h"

int main() {
    Student student;
    student.setName("John");
    student.setNo(10);
    
    StudentView view;
    
    StudentController controller(student, view);
    
    controller.updateView();
    controller.setStudentNo(11);
    controller.updateView();   

    return 0;
}
