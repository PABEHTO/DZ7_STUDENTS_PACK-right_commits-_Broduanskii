#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <set>

using namespace std;

class Student{
private:
    vector<int> marks;
    string name;

public:

    bool operator == (const Student &other) const{
        return (name == other.name);
    }
    string getName(){
        return name;
    }

    vector<int> getMarks(){
        return marks;
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
    string name;
public:
    Teacher(string na): name(na){};
    void setMood(bool moo = 1){
        mood = moo;
        //if (mood == 0) cout<<"Mood is bad"<<endl;
        //else cout<<"Mood is well"<<endl;
    }
    virtual string getName(){
        return name;
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
    UnstableMood_Teaher(string naa): Teacher(naa){}
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
    string getName() override{
        return name;
    }
};

class FiveGiver_Tecaher: Teacher{
public:
    FiveGiver_Tecaher(string na): Teacher(na){};
    void markStudent(Student &student) override{
        student.giveMark(5);
    }
    string getName() override{
        return name;
    }
};

class TwoGiver_Teacher: Teacher{
public:
    TwoGiver_Teacher(string na): Teacher(na){};
    void markStudent(Student &student) override{
        student.giveMark(2);
    }
    string getName() override{
        return name;
    }
};

class Class{
public:
    Class(string na): name(na){};

    void addStudent(Student &stud){
        studList.push_back(stud);
    }
    vector<Student> getAllStudents(){
        return studList;
    }
    void giveAllMarks(Teacher &teach){
        teach_name = teach.getName();
        for (int i = 0; i<studList.size();i++){
            teach.markStudent(studList[i]);
        }
    }

    void giveAllMarks(FiveGiver_Tecaher &teach){
        teach_name = teach.getName();
        for (int i = 0; i<studList.size();i++){
            teach.markStudent(studList[i]);
        }
    }

    void giveAllMarks(TwoGiver_Teacher &teach){
        teach_name = teach.getName();
        for (int i = 0; i<studList.size();i++){
            teach.markStudent(studList[i]);
        }
    }

    void giveAllMarks(UnstableMood_Teaher &teach){
        teach_name = teach.getName();
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
    bool CertainIsFivePointer(Student &stud){
        float sum;
        for (int i = 1; i<stud.getMarks().size(); i++){
            sum += stud.getMarks()[i];
        }
            sum = (sum / ((stud.getMarks().size()) -1));
        if (sum == 5) return 1;
        return 0;
    }
    string getClassName(){
        return name;
    }
    string getTeacherName(){
        return teach_name;
    }
private:
    vector<Student> studList;
    string name;
    string teach_name;
};

class Parent{
private:
    bool isBabushka = 0;
protected:
    bool mood = rand() % 2;
    vector<Student> children;
    set<string> children_list;
public:
    string sayTHE_BEST(){
        return "THE BEST!";
    };
    bool checkBabushka(){
        return isBabushka;
    }
    virtual bool Bch(){
        return 0;
    }

    void addChild(Student &child){
        children.push_back(child);
        children_list.insert(child.getName());
    }
    set<string> getList(){
        return children_list;
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
        int counter = -1;
        for (int i = 0; i<children.size(); i++){
            if ((children[i].getName()) == NAME) counter = i;
            else continue;
        }
        if (counter != -1){
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
    vector<Student> getChildren(){
        return children;
    }
};

class Babushka: public Parent{
public:
    bool Bch() override{
        return 1;
    }
private:
    bool isBabushka = 1;
};

class Meeting{
private:
    set<string> listt;
    set<string> listt2;
    vector<Parent*> p;
    vector<Teacher> t;
    vector<Class> c;
public:
    void check(){

    }
    Meeting(){cout<<"New meeting starts"<<endl;}
    void showListt(){
        if (listt2.size() == 0) {cout<<endl; return;}
        cout<<"List of students whose parents didn't come: ";
        for (const auto& element : listt2) {
        cout << element << "  ";
    }
        cout<<endl;
    }
    void addParent(Parent *parent){
        p.push_back(parent);
    }
    void addParent(Babushka *babushka){
        p.push_back(babushka);
    }
    void addTeacher(Teacher &teacher){
        t.push_back(teacher);
    }
    void addClass(Class &clas){
        c.push_back(clas);
    }
    void talkAbout(){

        for (int i = 0; i<c.size(); i++){ // уроки 0-i
            for (int check = 0; check < t.size(); check++){
                if (t[check].getName() == c[i].getTeacherName()) goto here;
            }
            cout<<c[i].getClassName()<<" class: ";
            cout<<"Teacher is absent"<<endl; return;
            here:
            cout<<c[i].getClassName()<<" class: "<<endl;
            for (int j = 0; j< p.size(); j++){
                cout<<"Parent "<<(j+1)<<": ";
                for (int k = 0; k<p[j]->getChildren().size(); k++){
                    for (int n = 0; n < (c[i].getAllStudents()).size(); n++){

                            if ((c[i].getAllStudents())[n].getName() == p[j]->getChildren()[k].getName())
                            {

                                Student temp = (p[j]->getChildren()[k]);
                                if (c[i].CertainIsFivePointer(c[i].getAllStudents()[n])) {if (p[j]->Bch()) (cout<<temp.getName()<<"'s "<<p[j]->sayTHE_BEST()); else cout<<temp.getName()<<"'s working nice. ";}
                                else {if (p[j]->Bch()) (cout<<temp.getName()<<"'s "<<p[j]->sayTHE_BEST()); else cout<<temp.getName()<<"'s trying her(his) best. ";}

                            }
                    }
                }
                cout<<endl;
            }
            cout<<endl;
        }
        for (int i = 0; i<c.size(); i++){

            for (int j = 0; j<p.size(); j++){

                   for (int n = 0; n < (c[i].getAllStudents()).size(); n++){
                        if ((p[j]->getList().count(((c[i].getAllStudents())[n]).getName()))) listt.insert(((c[i].getAllStudents())[n]).getName());
                   }
            }
        }
        for (int i = 0; i<c.size(); i++){
            for (int j = 0; j<(c[i].getAllStudents().size()); j++){
                if (!(listt.count((c[i].getAllStudents())[j].getName()))) listt2.insert((c[i].getAllStudents())[j].getName());
            }
        }
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

    Teacher t1("art");
    Teacher t2("math");

    Parent p1;
    p1.addChild(a);
    p1.addChild(b);
    p1.addChild(c);
    p1.addChild(d);

    Parent p2;
    Student e("Sven");
    e.giveMark(5);
    p2.addChild(e);

    Babushka p3; //Появление БАБУШКИ
    Student f("Kate");
    f.giveMark(4);
    p3.addChild(f);

    Class art("Art");
    art.addStudent(a); art.addStudent(c); art.addStudent(e); art.addStudent(f);
    art.giveAllMarks(t1);
    art.giveAllMarks(t1);
    art.giveAllMarks(t1);

    Class mat("Math");
    mat.addStudent(b);
    mat.addStudent(e);
    mat.addStudent(d); mat.addStudent(f);
    mat.giveAllMarks(t2);
    mat.giveAllMarks(t2);

    Meeting m1;
    m1.addTeacher(t1);
    //m1.addTeacher(t2); Ситуация, когда учитель не пришёл на собрание (выводится сообщение о его отсутствии)
    m1.addParent(&p1); m1.addParent(&p2);m1.addParent(&p3);
    m1.addClass(art);
    m1.addClass(mat);
    m1.talkAbout();
    m1.showListt();

    Meeting m2;
    m2.addTeacher(t2);
    //m2.addParent(&p1); Ситуация,когда родитель не пришёл на собрание (в конце выводится список детей, у которых должны были прийти родители на обсуждение)
    m2.addParent(&p2);
    m2.addParent(&p3);
    m2.addClass(mat);
    m2.talkAbout();
    m2.showListt();

    return 0;
}
