typedef struct {
	char* uuid;
  int age;
  char* first;
  char* last;
  char* phone;
  char* email;
	char gender;
} Employee;

Employee create_employee(
	int age,
	char* first,
	char* last,
	char* phone,
	char* email,
	char gender
);

char* create_uuid();
