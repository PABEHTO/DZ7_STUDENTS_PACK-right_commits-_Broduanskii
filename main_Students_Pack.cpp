#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Student{
private:

    vector<int> marks;

public:
    void show(){
        cout<<"Marks are: ";
        for (int i = 0; i<marks.size();i++){
            cout<<marks[i]<<" ";
        }
        cout<<endl;
    }

    void giveMark(int m){
        marks.push_back(m);
    }

    bool isFivePointer(){
        float sum;
        for (int i = 0; i<marks.size(); i++){
            sum += marks[i];
        }
        sum = sum/(marks.size());
        if (sum == 5){
           // cout<<"Five-pointer"<<endl;
            sum = 0;
            return 1;
        }
        else {
           // cout<<"NO Five-pointer"<<endl;
            sum = 0;
            return 0;
        }
    }

};

class Teacher{
private:
    bool mood = rand()%2;
public:
    void setMood(bool moo = 1){
        mood = moo;
        if (mood == 0) cout<<"Mood is bad"<<endl;
        else cout<<"Mood is well"<<endl;
    }
    void markStudent(Student &student){
        int randVal = rand() % 2;

        if ((mood == 1) && (student.isFivePointer()))
            student.giveMark(5);
        else if ((mood == 0) && (student.isFivePointer()))
            student.giveMark(5*randVal + 4*(1-randVal));
        else if ((mood == 1) && !(student.isFivePointer()))
            student.giveMark(4);
        else if ((mood == 0) && !(student.isFivePointer()))
            student.giveMark(3*randVal + 2*(1-randVal));
    }
};

class Class{
public:
    void addStudent(Student &stud){
        studList.push_back(stud);
    }
    void giveAllMarks(Teacher &teach){
        for (int i = 0; i<studList.size();i++){
            teach.markStudent(studList[i]);
        }
    }

    void showw(){
        int num = 0;
        for (int i = 0; i<studList.size();i++){
            num ++; cout<<num<<" student's marks are: ";
            studList[i].show();
        }
        cout<<endl;
    }
    Student getStudent(int num){
        return studList[num];
    }
private:
    vector<Student> studList;
};

int main()
{
    srand(time(NULL));
    Student a,b,c,d;
    a.giveMark(5);
    b.giveMark(3);
    c.giveMark(4);
    d.giveMark(5);

    Teacher t;
    t.setMood(0);

    Class art;
    art.addStudent(a);
    art.addStudent(b);
    art.addStudent(c);
    art.addStudent(d);
    art.giveAllMarks(t);
    art.giveAllMarks(t);
    art.showw();

    return 0;
}
