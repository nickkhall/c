#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
  private:
    const unsigned long int employee_id;
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
    unsigned long long int start_date;
    std::string emergency_contact;
    std::string gender;
    std::string ethnicity;
    std::string residency;
    std::string job_title;
    unsigned long int salary;

  public:
    Employee();

    // unsigned long int set_employee_id();
    void CreateEmployee();

    ~Employee();
};

#endif
