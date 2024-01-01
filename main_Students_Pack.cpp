#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Student{
private:

    vector<int> marks;
    string name;

public:
    string getName(){
        return name;
    }
    Student(string na): name(na){};
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

class Parent{
private:
    bool mood = rand() % 2;
    vector<Student> children;
public:

    void addChild(Student &child){
        children.push_back(child);
    }

    void sayAboutEach(){
        if (children.size()==0) return;
        for (int i = 0; i<children.size();i++){
            if (children[i].isFivePointer() && mood == 1) cout<<children[i].getName()<<"'s the best. ";
            if (children[i].isFivePointer() && mood == 0) cout<<children[i].getName()<<"'s the best, but...would be better. ";
            if (!(children[i].isFivePointer()) && mood == 1) cout<<children[i].getName()<<"'s doing well. ";
            if (!(children[i].isFivePointer()) && mood == 0) cout<<children[i].getName()<<"'s...oh, so sad";
        }
        cout<<endl;
    }
    void sayAboutRandom(){
        int num = rand() % children.size();
        if (children[num].isFivePointer() && mood == 1) cout<<children[num].getName()<<"'s the best. ";
        if (children[num].isFivePointer() && mood == 0) cout<<children[num].getName()<<"'s the best, but...would be better. ";
        if (!(children[num].isFivePointer()) && mood == 1) cout<<children[num].getName()<<"'s doing well. ";
        if (!(children[num].isFivePointer()) && mood == 0) cout<<children[num].getName()<<"'s...oh, so sad";
        cout<<endl;
    }
    void sayAboutGeneral(){
        bool marker = 1;
        for (int i = 0; i<children.size(); i++){
            if (children[i].isFivePointer()) continue;
            else marker = 0;
        }
        if (marker == 1 && mood == 1) cout<<"They're all the best"<<endl;
        if (marker == 1 && mood == 0) cout<<"They're all nice...yes, nice"<<endl;
        if (marker == 0 && mood == 1) cout<<"They're doing well, but would be better"<<endl;
        if (marker == 0 && mood == 0) cout<<"They're...oh, at list they're trying suppose"<<endl;
    }
    void sayAboutCertain(string NAME){
        int counter = 10000;
        for (int i = 0; i<children.size(); i++){
            if ((children[i].getName()) == NAME) counter = i;
            else continue;
        }
        if (counter != 10000){
            bool marker = 1;
            for (int i = 0;i<children.size(); i++){
                if (!children[i].isFivePointer()) marker = 0;
        }
            if (marker == 1 && mood == 1) cout<<children[counter].getName()<<"'s the best"<<endl;
            if (marker == 1 && mood == 0) cout<<children[counter].getName()<<"'s the best, but...would be better. "<<endl;
            if (marker == 0 && mood == 1) cout<<children[counter].getName()<<"'s doing well. "<<endl;
            if (marker == 0 && mood == 0) cout<<children[counter].getName()<<"'s...oh, so sad"<<endl;
    }
    else cout<<NAME<<" isn't my chid"<<endl;
    }

};

int main()
{
    srand(time(NULL));
    Student a("Nick"),b("Jimy"),c("Bob"),d("Liza");
    a.giveMark(5);
    b.giveMark(3);
    c.giveMark(4);
    d.giveMark(5);

    Parent p;
    p.addChild(a);
    p.addChild(b);
    p.addChild(c);
    p.addChild(d);
    p.sayAboutEach();
    p.sayAboutRandom();
    p.sayAboutGeneral();
    p.sayAboutCertain("Liza");
    p.sayAboutCertain("Stifler");

    return 0;
}
