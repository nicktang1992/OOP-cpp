#include <iostream>
#include <vector> 
#include <regex>

using namespace std;

class Student {
    public:
    string first_name;
    string last_name;
    string id;

    Student(string sid)
    {
        id = sid;
    }

    void print() 
    { 
        cout << "student: " << id << " with name: " << first_name << ", " << last_name;
    } 
};

class MySet {    
    public:
    vector<Student> mySet;

    int find(string studentId)
    {
        vector<Student>::iterator it;
        for (it = mySet.begin(); it != mySet.end(); it++) 
        {
            if((*it).id == studentId) {
                cout << "Found: ";
                (*it).print();
                return it - mySet.begin();
                break;
            }
        }
        cout << "Can't find: " << studentId << ".";
        return -1;
    }

//Insert new students, you should not accept duplicates!
    void insert(Student s)
    {
        if(find(s.id) == -1) {
            cout << " inserting." << endl;
            mySet.push_back(s);
        }
    }

//Remove a student from the set given her G#
    void remove(string studentId)
    {   
        vector<Student>::iterator it;
        int index = find(studentId);
        if(index != -1) {
            mySet.erase(mySet.begin() + index);
            cout << " removing." << endl;
            return;
        }
        cout << " no found no remove." << endl;
    }

/*find a student given her G# (it can return several students with similar G#s. 
  Make sure you can accept regular expression, e.g., G39*)*/
    void findSimilarId(string regexId) 
    {
    regex myRegex(regexId);
        vector<Student>::iterator it;
        for (it = mySet.begin(); it != mySet.end(); it++) 
        {
            if(regex_match((*it).id, myRegex)) {
                cout << "Found: ";
                (*it).print();
                cout << endl;
            }
        }
    }

/*List all the student (print them!) that match similar name (inputs: 1st name and/or last name). 
  Again regular expressions should be used, e.g., 1st Name: Y*, last name: Kim*. 
  So all students having the 1st name starting with Y and last name starting with Kim should be printed.*/

 void findFirstName(string firstRegex) 
 {
     return findSimilarName(firstRegex, ".*"); 
 }

  void findLastName(string lastRegex) 
 {
     return findSimilarName(".*",lastRegex);
 }

 void findSimilarName(string firstRegex, string lastRegex) 
    {
        regex firstname(firstRegex);
        regex lastname(lastRegex);

        vector<Student>::iterator it;
        for (it = mySet.begin(); it != mySet.end(); it++) 
        {
            if(regex_match((*it).first_name, firstname) && regex_match((*it).last_name, lastname)) 
            {
                cout << "Found: ";
                (*it).print();
                cout << endl;
            }
        }
    }

    void printSet()
    {
        vector<Student>::iterator it;
        for (it = mySet.begin(); it != mySet.end(); it++) 
        {   
            (*it).print();
            cout << endl;
        }
    }
};

int main() 
{
    // you must test with 10 students
    Student s1("G319817"); 
    s1.first_name = "jolie"; s1.last_name = "zhu";
    Student s2("G308030"); 
    s2.first_name = "leo"; s2.last_name = "liao";
    Student s3("G397515"); 
    s3.first_name = "tuanzi"; s3.last_name = "zhu";
    Student s4("G886210");
    s4.first_name = "hebe"; s4.last_name = "brown";
    Student s5("G886256");
    s5.first_name = "peiyao"; s5.last_name = "teng";
    Student s6("G986298");
    s6.first_name = "hebe"; s6.last_name = "teng";
    Student s7("G186298");
    s7.first_name = "rele"; s7.last_name = "wang";
    Student s8("G886222");
    s8.first_name = "jack"; s8.last_name = "williams";
    Student s9("G654398");
    s9.first_name = "tom"; s9.last_name = "smith";
    Student s10("G863598");
    s10.first_name = "jerry"; s10.last_name = "lee";

    MySet studentSet;
    studentSet.insert(s1);
    studentSet.insert(s2);
    studentSet.insert(s3);
    studentSet.insert(s4);
    studentSet.insert(s5);
    studentSet.insert(s6);
    studentSet.insert(s7);
    studentSet.insert(s8);
    studentSet.insert(s9);
    studentSet.insert(s10);
    cout << endl;

    studentSet.find("G123");
    cout << endl << endl;

    studentSet.find("G886222");
    cout << endl << endl;

    studentSet.remove("G319817");
    cout << endl;

    studentSet.findSimilarId("G3.*");
    cout << endl;

    studentSet.findFirstName("hebe.*");
    cout << endl;

    studentSet.findLastName("will.*");
    cout << endl;
    
    studentSet.findSimilarName("je.*","le.*");
    cout << endl;


    return 0;
}

