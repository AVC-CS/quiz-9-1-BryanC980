#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

const int NUMCOURSE = 2;
struct Student
{
    int id;
    string name;
    int score[NUMCOURSE];
    double sum;
    double avg;
    struct Student *next;
};
#define struct Student Student;
// typedef struct Student Student;

Student *makeStudent(int N);
void printStudent(Student *head);
int getLength(Student *head);
Student *sortStudent(Student *head, int asc);

Student *makeStudent(int N)
{
    ifstream file("student.txt");
    if (!file.is_open())
    {
        cerr << "Error: Unable to open file." << endl;
        return nullptr;
    }

    Student *head = nullptr;
    Student *current = nullptr;

    for (int i = 0; i < N; ++i)
    {
        Student *newStudent = new Student();
        file >> newStudent->id >> newStudent->name >> newStudent->score[0] >> newStudent->score[1];
        newStudent->sum = newStudent->score[0] + newStudent->score[1];
        newStudent->avg = newStudent->sum / NUMCOURSE;
        newStudent->next = nullptr;

        if (head == nullptr)
        {
            head = newStudent;
            current = head;
        }
        else
        {
            current->next = newStudent;
            current = newStudent;
        }
    }

    file.close();
    return head;
}
void printStudent(Student *head)
{
    Student *ptr = head;
    while (ptr != nullptr)
    {
        cout << ptr->id << "\t";
        cout << ptr->name << "\t";
        cout << ptr->score[0] << "\t";
        cout << ptr->score[1] << "\t";
        cout << ptr->sum << "\t";
        cout << ptr->avg << "\n";
        ptr = ptr->next;
    }
    cout << endl;

}
int getLength(Student *head)
{
    int length = 0;
    Student *ptr = head;
    while (ptr != nullptr)
    {
        length++;
        ptr = ptr->next;
    }
    return length;
}
Student *sortStudent(Student *head, int asc)
{
    /*******************************
     * Code your program here
     *******************************/
    return head;
}
