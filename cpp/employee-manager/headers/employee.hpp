#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
  private:
    unsigned long int employee_id;
    unsigned long int salary;
    std::string first_name;
    std::string middle_name;
    std::string last_name;
    std::string suffix;
    std::string email_address;
    std::string address;
    std::string home_phone_number;
    std::string cell_phone_number;
    std::string marital_status;
    std::string social_security_number;
    std::string start_date;
    std::string emergency_contact;
    std::string gender;
    std::string ethnicity;
    std::string residency;
    std::string job_title;

  public:
      Employee();



      ~Employee();
};

#endif
