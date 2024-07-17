// Given the solution class only, as required on the question link.

class Solution
{
public:
    static bool sortcol(const vector<int> &v1, const vector<int> &v2)
    {
        return v1[1] < v2[1];
    }
    int scheduleCourse(vector<vector<int>> &courses)
    {
        int n = courses.size();

        sort(courses.begin(), courses.end(), sortcol);
        // for(int i=0;i<n;i++){
        //     cout << courses[i][0] << " " << courses[i][1] << endl;
        // }
        int currTime = 0;
        int totalCourses = 0;
        priority_queue<int> q;
        for (int i = 0; i < n; i++)
        {

            q.push(courses[i][0]);
            currTime += courses[i][0];
            totalCourses++;

            if (currTime > courses[i][1])
            {
                currTime -= q.top();
                totalCourses--;
                q.pop();
            }
        }
        return totalCourses;
    }
};
