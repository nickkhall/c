#include <string>
#include <iostream>

#include "../headers/uuid.hpp"
#include "../headers/employee.hpp"

Employee::Employee(
  std::string first_name,
  std::string middle_name,
  std::string last_name,
  std::string suffix,
  std::string email_address,
  std::string address,
  std::string home_phone_number,
  std::string cell_phone_number,
  std::string marital_status,
  std::string social_security_number,
  unsigned long long int start_date,
  std::string emergency_contact,
  std::string gender,
  std::string ethnicity,
  std::string residency,
  std::string job_title,
  unsigned long int salary
) :
  employee_id {set_employee_id()},
  first_name {first_name},
  middle_name {middle_name},
  last_name {last_name},
  suffix {suffix},
  email_address {email_address},
  address {address},
  home_phone_number {home_phone_number},
  cell_phone_number {cell_phone_number},
  marital_status {marital_status},
  social_security_number {social_security_number},
  start_date {start_date},
  emergency_contact {emergency_contact},
  gender {gender},
  ethnicity {ethnicity},
  residency {residency},
  job_title {job_title},
  salary {salary}
{};

unsigned long int Employee::set_employee_id() {
  UUID new_uuid;
  std::string uuid = new_uuid.generate_id(); 

  std::cout << uuid << std::endl;
  return 1233242;
};
