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
    ifstream inputFile("students.txt");
    if (!inputFile)
    {
        cerr << "Error: Unable to open file." << endl;
        exit(1);
    }

    Student *head = NULL;
    Student *prev = NULL;

    for (int i = 0; i < N; ++i)
    {
        Student *newStudent = new Student;
        inputFile >> newStudent->id >> newStudent->name >> newStudent->score[0] >> newStudent->score[1];
        newStudent->sum = newStudent->score[0] + newStudent->score[1];
        newStudent->avg = newStudent->sum / NUMCOURSE;
        newStudent->next = nullptr;

        if (prev)
        {
            prev->next = newStudent;
        }
        else
        {
            head = newStudent;
        }

        prev = newStudent;
    }
    inputFile.close();
    return head;
}

void printStudent(Student *head)
{
    Student *ptr = head;
    while (ptr != NULL)
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
    /*******************************
     * Code your program here
     *******************************/
}
int getLength(Student *head)
{
    int length = 0;
    Student *ptr = head;
    while (ptr != NULL)
    {
        length++;
        ptr = ptr->next;
    }
    return length;
}
Student *sortStudent(Student *head, int asc)
{
    int length = getLength(head);
    Student *students[length];
    Student *ptr = head;
    for (int i = 0; i < length; ++i)
    {
        students[i] = ptr;
        ptr = ptr->next;
    }

    if (asc)
    {
        sort(students, students + length, [](const Student *a, const Student *b) {
            return a->sum < b->sum;
        });
    }
    else
    {
        sort(students, students + length, [](const Student *a, const Student *b) {
            return a->sum > b->sum;
        });
    }

    for (int i = 0; i < length - 1; ++i){
        students[i]->next = students[i + 1];
    }

    students[length - 1]->next = nullptr;
    return students[0];
}
