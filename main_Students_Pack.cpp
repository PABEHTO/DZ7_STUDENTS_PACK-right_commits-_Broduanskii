#include <iostream>
#include <vector>

using namespace std;

class student{
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

int main()
{
    student a;
    a.giveMark(5);
    a.giveMark(5);
    a.isFivePointer();

    student b;
    b.giveMark(5);
    b.giveMark(4);
    b.isFivePointer();

    return 0;
}