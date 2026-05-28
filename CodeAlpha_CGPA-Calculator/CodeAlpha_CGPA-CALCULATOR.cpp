
#include <iostream>
using namespace std;
#include <iomanip>
#include <string>

class course
{
private:
	string course_name;
	string grade;
	int credit_hours;
	float grade_points;

public:
	void input_course()
	{
		cout << "enter course name: " << endl;
		cin.ignore();
		getline(cin, course_name);

		cout << "enter grade(A,A-,B+,B,B-,C+,C,C-,D,F):" << endl;
		cin >> grade;

		cout << "enter credit hours:" << endl;
		cin >> credit_hours;

		while (credit_hours <= 0)
		{
			cout << "Invalid Credit Hours..." << endl;
			cout << "Enter credit hours again: ";
			cin >> credit_hours;
		}

		calculate_grade_points();
	}

	void calculate_grade_points()
	{
		while (true)
		{
			if (grade == "A")
			{
				grade_points = 4.0;
				break;
			}
			else if (grade == "A-")
			{
				grade_points = 3.7;
				break;
			}
			else if (grade == "B+")
			{
				grade_points = 3.3;
				break;
			}
			else if (grade == "B")
			{
				grade_points = 3.0;
				break;
			}
			else if (grade == "B-")
			{
				grade_points = 2.7;
				break;
			}
			else if (grade == "C+")
			{
				grade_points = 2.3;
				break;
			}
			else if (grade == "C")
			{
				grade_points = 2.0;
				break;
			}
			else if (grade == "C-")
			{
				grade_points = 1.7;
				break;
			}
			else if (grade == "D")
			{
				grade_points = 1.0;
				break;
			}
			else if (grade == "F")
			{
				grade_points = 0.0;
				break;
			}
			else
			{
				cout << "Wrong Grade Entered..." << endl;
				cout << "Enter grade again: ";
				cin >> grade;
			}
		}
	}

	float get_gpa()
	{
		return grade_points * credit_hours;
	}

	int get_credit()
	{
		return credit_hours;
	}

	void display_course()
	{
		cout << left << setw(20) << course_name
			<< setw(10) << grade
			<< setw(10) << credit_hours
			<< setw(10) << grade_points << endl;
	}
};

class cgpa_calculator
{
private:
	course courses[50];
	int semesters;
	int num;
	float semester_gpa[10];
	float total_grade_points;
	int total_credits;
	float cgpa;
public:
	void input_data()
	{
		cout << "Enter number of semesters: ";
		cin >> semesters;
		float final_total = 0;
		for (int s = 0; s < semesters; s++)
		{
			cout << "Semester: " << s + 1 << " ";
			cout << "enter number of courses: " << endl;
			cin >> num;
			total_grade_points = 0;
			total_credits = 0;
			for (int i = 0; i < num; i++)
			{
				cout << "Course  " << i + 1 << "  ";
				courses[i].input_course();
				total_grade_points += courses[i].get_gpa();
				total_credits += courses[i].get_credit();
			}
			semester_gpa[s] = total_grade_points / total_credits;
			final_total += semester_gpa[s];
			displayResult(s);
		}

		cgpa = final_total / semesters;
	}

	void displayResult(int sem)
	{
		cout << "\n COURSE DETAILS " << endl;

		cout << left << setw(20) << "Course"
			<< setw(10) << "Grade"
			<< setw(10) << "Credits"
			<< setw(10) << "Points" << endl;

		for (int i = 0; i < num; i++)
		{
			courses[i].display_course();
		}

		cout << "Total Credits: " << total_credits << endl;
		cout << "Total Grade points: " << total_grade_points << endl;
		cout << fixed << setprecision(2);
		cout << "Semester " << sem + 1 << " GPA: " << semester_gpa[sem] << endl;
	}

	void final_result()
	{
		cout << "----------------------------------" << endl;
		cout << "Final CGPA: " << cgpa << endl;
	}
};

int main()
{
	cgpa_calculator student;
	student.input_data();
	student.final_result();

	return 0;
}
