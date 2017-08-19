#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <cstdlib>

#define NUM_FIELDS 3
struct SplitLine {
    std::string fields[NUM_FIELDS];
};

/* DONT MAKE ANY CHANGES ABOVE THIS LINE */

#include <algorithm>
#include <sstream>
#define MAX_SUB 6
using namespace std;

/* If you wish you can include any more files here.
   (from standard libraries only) */
class Student
{
    private:
        int _stdId;
        std::string _sub;
        int _marks;
    public:
        Student(int iStdId, std::string iSub, int iMarks) : 
            _stdId(iStdId),
            _sub(iSub),
            _marks(iMarks)
            {}
        Student(int iMarks) : _marks(iMarks)
        {}

        int getId() const
        {
            return _stdId;
        }

        int getMarks() const
        {
            return _marks;
        }

        string getSub() const
        {
            return _sub;
        }
};

class StudentList
{
    private:
        vector<Student> _sList;
    public:
        StudentList(int size)
        {
            _sList.reserve(size);
        }
        Student getTopper(string& iSub);
        void insertRecord(Student& iStd);
};


void StudentList::insertRecord(Student& iStd)
{
    _sList.push_back(iStd);
}

Student StudentList::getTopper(string& iSub)
{
    Student st(-1);
    for (auto itr = _sList.begin(); itr != _sList.end(); itr++)
    {
        if ((itr->getSub() == iSub) &&
            itr->getMarks() > st.getMarks())
        {
            st = *itr;
        }
    }
    return st;
}

std::map<std::string, int> process_data(std::vector<struct SplitLine> data) 
{
        /* 
         * Modify this function to process `data` as indicated
         * in the question. At the end, return the appropriate 
         * value.
         *
         * Please create appropriate classes, and use appropriate
         * data structures as necessary.
         *
         * Do not print anything in this function.
         *
         * Note: the existing program is not intended to be an example
         * of good programming practice. (For example, struct
         * SplitLine is not a very good way to hold the data for this
         * problem.)  However, the code that *you* write will be
         * evaluated on the basis of the quality of the code, use of
         * appropriate classes/data-structures, comments, and
         * efficiency of the algorithm used.
         *
         * Submit this entire program (not just this function)
         * as your answer
         */
    // Create a vector of unique subjects
    std::vector<std::string> aSubVect;
    aSubVect.reserve(MAX_SUB);
    for (auto itr = data.begin(); itr != data.end(); itr++)
    {
        auto ret = find(aSubVect.begin(), aSubVect.end(), itr->fields[1]);
        if(ret == aSubVect.end())
        {
            aSubVect.push_back(itr->fields[1]);
        }
    }

    // Create complete student List and reserve required space in advance
    StudentList aStList(data.size());
    
    for (auto itr = data.begin(); itr != data.end(); itr++)
    {
        stringstream aSId(itr->fields[0]);
        int aId =0;
        aSId >> aId;
        stringstream aSMarks(itr->fields[2]);
        int aMarks =0;
        aSMarks >> aMarks;
        Student aStd(aId, itr->fields[1], aMarks);

        aStList.insertRecord(aStd);
    }

    // Iterate through each subject, find student with maximum marks and insert into ret_val map
    std::map<std::string, int> ret_val;
    for (auto itr = aSubVect.begin(); itr != aSubVect.end(); itr++)
    {
        auto aTopper = aStList.getTopper(*itr);
        ret_val.insert(pair<std::string, int> (*itr, aTopper.getId()));
    }

    return ret_val;
}

/* DONT MAKE ANY CHANGES BELOW THIS LINE */

int main(void) {
    std::ifstream in("input.txt");
    std::vector<struct SplitLine> input_data;
    while (in) {
        struct SplitLine line;
        for (int i=0; i<NUM_FIELDS; i++) {
            if (i==NUM_FIELDS-1)
                std::getline(in, line.fields[i]);
            else
                std::getline(in, line.fields[i], '|');
        }
        if (line.fields[0] != "")
            input_data.push_back(line);
    }
    std::ofstream out("output.txt");
    std::map<std::string, int> ret_val = process_data(input_data);
    for (std::map<std::string, int>::iterator it = ret_val.begin();
            it != ret_val.end();
            it++) {
        out << it->first << ": " << it->second << std::endl;
    }
    return 0;
}
