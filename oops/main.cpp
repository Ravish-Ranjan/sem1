#include "./pract/student.h"
#include <cstdlib>

int main(){
    system("cls");
    int choice ;
    do {
        std::cout << "======== Student Management System ========" << std::endl;
        std::cout << "1. Show all students" << std::endl;
        std::cout << "2. Show student by Id" << std::endl;
        std::cout << "3. Add new student" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "===========================================" << std::endl;
        std::cout << "Enter your choice : ";
        std::cin >> choice;
        std::cout << std::flush;
        system("cls");
        switch (choice){
            case 1:
                DisplayStudents();
                std::cout << std::endl << std::endl;
                break;
            case 2:{
                int id;
                std::cout << "Enter student id : ";
                std::cin >> id; 
                DisplayStudentById(id);
                std::cout << std::endl << std::endl;
                break;
            } 
            case 3: {
                std::string name,department;
                int age;
                double marks;
                std::cout << "Enter student's name : ";
                std::cin >> name;
                std::cout << "Enter student's age : ";
                std::cin >> age;
                std::cout << "Enter student's department : ";
                std::cin >> department;
                std::cout << "Enter student's marks : ";
                std::cin >> marks;
                AddStudent(name,age,department,marks);
                std::cout << std::endl << std::endl;
                break;
            }
            case 4:{
                std::cout << "Exiting...." << std::endl;
                return 0;
            }
            default:
                std::cout << "Wrong choice" << std::endl;

        } 
    } while (choice != 4);   
    return 0;
}