#include "1700.hpp"

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> studentsQueue;
    int counterSandwichPass = 0;
    for(int i = 0; i < students.size(); i++)
    {
        studentsQueue.push(students[i]);
    }

    for(int s : sandwiches)
    {
        while(counterSandwichPass != studentsQueue.size() && studentsQueue.front() != s)
        {
            counterSandwichPass++;
            studentsQueue.push(studentsQueue.front());
            studentsQueue.pop();
        }

        if(studentsQueue.front() == s)
        {
            studentsQueue.pop();
            counterSandwichPass = 0;
        }
        else
        {
            return studentsQueue.size();
        }
    }

    return 0;
}