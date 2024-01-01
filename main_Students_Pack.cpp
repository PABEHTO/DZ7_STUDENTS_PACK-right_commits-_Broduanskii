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
        cout<<"marks are: ";
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
protected:
    bool mood = rand()%2;
    int mood_counter = 0;
public:
    void setMood(bool moo = 1){
        mood = moo;
        if (mood == 0) cout<<"Mood is bad"<<endl;
        else cout<<"Mood is well"<<endl;
    }
     virtual void markStudent(Student &student){

        int randVal = rand() % 2;

        if ((mood == 1) && (student.isFivePointer()))
            student.giveMark(5);
        else if ((mood == 0) && (student.isFivePointer()))
            student.giveMark(5*randVal + 4*(1-randVal));
        else if ((mood == 1) && !(student.isFivePointer()))
            student.giveMark(4);
        else if ((mood == 0) && !(student.isFivePointer()))
            student.giveMark(3*randVal + 2*(1-randVal));
        mood_counter ++;
        if (mood_counter % 5 == 0){

            int mood_change = rand();
            setMood(mood_change % 2);
        }


    }
};

class UnstableMood_Teaher: Teacher{
private:
    bool mood = rand()%2;
public:
    void markStudent(Student &student) override{
        int randVal = rand() % 2;

        if ((mood == 1) && (student.isFivePointer()))
            student.giveMark(5);
        else if ((mood == 0) && (student.isFivePointer()))
            student.giveMark(5*randVal + 4*(1-randVal));
        else if ((mood == 1) && !(student.isFivePointer()))
            student.giveMark(4);
        else if ((mood == 0) && !(student.isFivePointer()))
            student.giveMark(3*randVal + 2*(1-randVal));
        mood_counter += randVal;
        if (mood_counter % 2 == 0){

            int mood_change = rand();
            setMood(mood_change % 2);
        }

    }
};

class FiveGiver_Tecaher: Teacher{
public:

    void markStudent(Student &student) override{
        student.giveMark(5);
    }
};

class TwoGiver_Teacher: Teacher{
public:

    void markStudent(Student &student) override{
        student.giveMark(2);
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

    void giveAllMarks(FiveGiver_Tecaher &teach){
        for (int i = 0; i<studList.size();i++){
            teach.markStudent(studList[i]);
        }
    }

    void giveAllMarks(TwoGiver_Teacher &teach){
        for (int i = 0; i<studList.size();i++){
            teach.markStudent(studList[i]);
        }
    }

    void giveAllMarks(UnstableMood_Teaher &teach){
        for (int i = 0; i<studList.size();i++){
            teach.markStudent(studList[i]);
        }
    }

    void showw(){
        int num = 0;
        for (int i = 0; i<studList.size();i++){
            num ++; cout<<num<<" student's ";
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
    art.giveAllMarks(t);
    art.giveAllMarks(t);
    art.giveAllMarks(t);
    art.showw();

    Class mat;
    mat.addStudent(a);
    mat.addStudent(b);
    mat.addStudent(c);
    mat.addStudent(d);
    UnstableMood_Teaher t3;
    mat.giveAllMarks(t3);
    mat.giveAllMarks(t3);
    mat.giveAllMarks(t3);
    mat.giveAllMarks(t3);
    mat.giveAllMarks(t3);
    mat.showw();

    return 0;
}
