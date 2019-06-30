#include <string>
#include <iostream>

#include "../headers/uuid.hpp"
#include "../headers/employee.hpp"

Employee::Employee(): employee_id {0} {};

unsigned long int Employee::set_employee_id() {
  UUID new_uuid;
  std::string uuid = new_uuid.generate_id(); 

  std::cout << uuid << std::endl;
  return 1233242;
};

void Employee::CreateEmployee() {
  
};

Employee::~Employee() {};
