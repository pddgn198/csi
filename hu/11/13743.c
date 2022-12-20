#include <stdlib.h>
#include <string.h>

#define STRLEN 51

typedef struct {
    int grade;
    char *name;
} Student;

// create a student list size n
Student *Create_(int n) {
    Student *r = malloc(sizeof(Student) * n);
    for (int i = 0; i < n; i++) {
        r[i].name = malloc(sizeof(char) * STRLEN);
    }
    return r;
}
// set value of the student's grade and name
void SetVal_(Student *students, int i, int grade, char name[]) {
    students[i].grade = grade;
    strcpy(students[i].name, name);
    return;
}
// compare the grades of the student, return 1 if id2 has higher priority than id1
int Compare_(Student *students, int id1, int id2) {
    if (students[id2].grade - students[id1].grade) return students[id2].grade - students[id1].grade;
    return strcmp(students[id2].name, students[id1].name);
}
// swap student
void Swap_(Student *students, int id1, int id2) {
    Student tmp = students[id1];
    students[id1] = students[id2];
    students[id2] = tmp;
    return;
}
// free the student list
void Free_(Student *students, int n) {
    for (int i = 0; i < n; i++) {
        free(students[i].name);
    }
    free(students);
    return;
}
