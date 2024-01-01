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
            cout<<"Five-pointer"<<endl;
            sum = 0;
            return 1;
        }
        else {
            cout<<"NO Five-pointer"<<endl;
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

int main()
{
    srand(time(NULL));
    Student a;
    a.giveMark(5);
    a.giveMark(5);
    a.isFivePointer();

    Teacher t;
    t.setMood(0);
    t.markStudent(a);

    a.show();
    a.isFivePointer();
    return 0;
}
