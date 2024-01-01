#include <iostream>
#include <vector>

using namespace std;

class Student{
private:

    vector<int> marks;

public:
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
            return 1;
        }
        else {
            cout<<"NO Five-pointer"<<endl;
            return 0;
        }
    }
};

class Teacher{
public:
    void markStudent(Student &student, int MARK){
        student.giveMark(MARK);
    }
};

int main()
{
    Student a;
    a.giveMark(5);
    a.giveMark(5);
    a.isFivePointer();

    Teacher t;
    t.markStudent(a,4);

    a.isFivePointer();

    return 0;
}
