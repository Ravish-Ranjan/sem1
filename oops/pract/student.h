#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include <vector>
#include <atomic>


class UniqueIdGenerator {
public:
    static int generate() {
        static std::atomic<int> currentID {0};
        return ++currentID;
    }
};

class Student{
    private:
        std::string name;
        int age;
        std::string department;
        double marks;
        int id;
    public:
        Student(int id,std::string name,int age,std::string department,double marks):id(id),name(name),age(age),department(department),marks(marks){}
        void print(){
            std::cout << "\n----- " << name << " -- Details -----" << std::endl;
            std::cout << "> Id : " << id << std::endl;
            std::cout << "> Name : " << name << std::endl;
            std::cout << "> Age : " << age << std::endl;
            std::cout << "> Department : " << department<< std::endl;
            std::cout << "> Marks : " << marks << std::endl;
            std::cout << "------------------------" << std::endl;
        }
        int getId(){
            return this->id;
        }
};

std::vector<Student*> students;

void AddStudent(std::string name,int age,std::string department,double marks){
    try {
        int newId = UniqueIdGenerator::generate();
        Student* newStudent = new Student(newId,name,age,department,marks);
        students.push_back(newStudent);
        std::cout << "New Student Added" << std::endl;
    } catch(const std::runtime_error& e){
        std::cout << "Error adding new student" << std::endl;
    }
    
}

void DisplayStudentById(int id){
    try{
        for(Student* student:students){
            if (student->getId() == id){
                student->print();
                return;
            }
        }
        throw std::runtime_error("Student Not Found");        
    } catch(const std::runtime_error& e) {
        std::cout << "Error : " << e.what() << std::endl;
    }
};

void DisplayStudents(){
    if (students.size() == 0){
        std::cout << "No Student Data found" << std::endl;
        return;
    }
    std::cout << "======== All Students (" << students.size() << ") ========" << std::endl;
    for(Student* student:students){
        student->print();
    }
    std::cout << "==============================" << std::endl;
};

#endif