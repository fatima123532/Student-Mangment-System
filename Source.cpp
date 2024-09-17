#include<iostream>
#include<string>
using namespace std;
class student_mangment_sytem {
private:
	static const int max_size = 100;
	string *name[max_size];
	int *id[max_size];
	string *GPA[max_size];
	int user_size;

public:
	student_mangment_sytem() { 
		for (int i = 0; i < max_size; i++) {
			name[i] = new string();
			id[i] = new int();
			GPA[i] = new string();
		}
		user_size = 0;
	}
	int add_student(const string &name,const int&id ,const string &gpa) {
		
			this->name[user_size] = new string(name);
			this->id[user_size] = new int(id);
			this->GPA[user_size] = new string(gpa);
			user_size++;
			return 1;
		
	}
	bool remove_student(const int& id) {
		int index = -1;
		for (int i = 0; i < user_size; i++) {
			if (*(this->id[i]) == id) {
				index = i;
				break;
			}
		}

		if (index != -1) {
			for (int i = index; i < user_size - 1; i++) {
				this->id[i] = this->id[i + 1];
				this->name[i] = this->name[i + 1];
				this->GPA[i] = this->GPA[i + 1];
			}
			user_size--;
			return true;
		}
		return false;
	}
	bool search_student_by_name(const string&name){
		for (int i = 0; i < user_size; i++) {
			if (*(this->name[i]) == name) {
				return true;
			}
	  }
		return false;
	}
	bool search_student_by_id(const int&id) {
		for (int i = 0; i < user_size; i++) {
			if (*(this->id[i]) == id) {
				return true;
			}
		}
		return false;
	}
	void display_all_students() {
		for (int i = 0; i < user_size; i++) {
			if (i < user_size) { 
				cout << "----Data of student " << i + 1 << " ----" << endl;
				cout << "Student " << " Name = " << *(this->name[i]) << endl;
				cout << "Student_Id = " << *(this->id[i]) << endl;
				cout << "GPA =" << *(this->GPA[i]) << endl;
			}
		}
	}
	float calculate_gpa() {
		float sum = 0;
		float average =0;
		for (int i = 0; i < user_size; i++) {
			 sum += stof(*(this->GPA[i]));

		 }
		average = sum / user_size;
		return average;
	}
	string highest_gpa()  {
		float highest_GPA = 0.0;
		int index=0;
		for (int i = 0; i < user_size; i++) {
			float student_GPA = stof(*(this->GPA[i])); // convert string to float
			if (student_GPA > highest_GPA) {
				highest_GPA = student_GPA; 
				index=i;
			}

		}
		return  *(this->name[index]);
	}
	~student_mangment_sytem() {
		for (int i = 0; i < user_size; i++) {
			delete this->id[i];
			delete this->name[i];
			delete this->GPA[i];
		}
	
	}
};

int main() {
	int option, number_of_students, id;
	float average;
	string name, GPA;
	char selection;
	student_mangment_sytem s1;
	do {
		cout << "\t\t///////////Welcome To Student Mangment System////////////\t\t" << endl;
		cout << endl;
		cout << endl;

		cout << "\t---Operations You can Do---\t" << endl;
		cout <<  endl;
		cout << "1) Add student with name,ID and GPA" << endl;
		cout << "2) Remove students from the university by id" << endl;
		cout << "3) Search for a student by ID or name " << endl;
		cout << "4) Display all students in the university " << endl;
		cout << "5)  Calculate the average GPA of all students" << endl;
		cout << "6) Find the student with the highest GPA" << endl;
		cout << endl;
		cout << "Press the number of operation you want to do:";
		cin >> option;
		switch (option) {
		case 1:
			system("cls");
			cout << "\t\tAdd student with name,ID and GPA\t\t " << endl;
			cout << endl;
			cout << endl;
			cout << "How much data of  students  you want to enter? ";
			cin >> number_of_students;
			cout << endl;
			for (int i = 0; i < number_of_students; i++) {
				cout << "Enter the name of student:";
				cin.ignore();
				getline(cin, name);
				cout << "Enter the ID: ";
				cin >> id;
				cout << "Enter the GPA: ";
				cin.ignore();
				cin >> GPA;
				if (s1.add_student(name, id, GPA) == 1) {
					cout << "Student added successfully" << endl;
					cout << endl;
				}
				else {
					cout << "!!!!Failed" << endl;
				}
			}
			break;
		case 2:
			system("cls");
			cout <<"\t\tRemove students from the university by id\t\t" << endl; 
			cout << endl;
			cout << endl;
			cout << "Enter the ID of the student you want to remove:";
			cin >> id;
			cout << endl;
			if (s1.remove_student(id) == true) {
				cout << "Student of ID " << id << " removed Successfully." << endl;
			}
			else {
				cout << "Student of this Id not found!!!!" << endl;
			}
			break;
		case 3:
			system("cls");
			cout << "\t\t\t Search for a student by ID or name\t\t\t " << endl;
			cout << endl;
			cout << endl;
			cout << "Do you want to search a student by name or by id:";
			cin >> name;
			cout << endl;
			if (name == "name") {
				cout << "Enter the name of student:";
				cin.ignore();
				getline(cin, name);
				if (s1.search_student_by_name(name) == true) {
					cout << "Student of name " << name << " found succcessfully" << endl;
				}
				else {
					cout << "Student Not Found!!!!!!!" << endl;
				}
				
			}
			if (name == "id") {
				cout << "Enter the id of student:";
				cin >> id;
				cout << endl;
				if (s1.search_student_by_id(id) == true) {
					cout << "Student found succcessfully" << endl;
				}
				else {
					cout << "Student Not Found!!!!!!!" << endl;
				};
			}

				
				break;
		case 4:
			system("cls");
			cout << "\t\t\tDisplay all students in the university\t\t\t " << endl;
			cout << endl;
			cout << endl;
			s1.display_all_students();

			break;
		case 5:
			system("cls");
			cout << "\t\t\t Calculate the average GPA of all students \t\t\t" << endl;
			cout << endl;
			cout << endl;
			average = s1.calculate_gpa();
			cout << "Average GPA = " << average << endl;
			break;
		case 6:
	
			system("cls");
			cout << "\t\t\t Find the student with the highest GPA\t\t\t" << endl;
			cout << endl;
			cout << endl;
			 name= s1.highest_gpa();
			cout << "Name of the student that have highest GPA is " << name << endl;
			break;
		default:
			cout << "Error!!!!Invalid option.Try Again." << endl;
			}
			cout << "******If you want to continue press Y(yes) else press any key to exit the system*****";
			cin >> selection;
			system("cls");



		} while (selection == 'y' || selection == 'Y');


	}

