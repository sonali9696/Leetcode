//we add most freq elements and keep idle time between them
//we fill other elements in these idle blocks until they are full
//case 1: they are full so we append remaining tasks at the end of the array so ans is len(tasks)
//case 2: idle slots remaining after filling all. Consider that n elements have max freq
//then those n elements will append one after other at the end as they are > idle slots between first max freq element
//so (n+1)*(maxF - 1) + n
//see visualization here - https://leetcode.com/problems/task-scheduler/solution/
//so ans is max of above 2 cases

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26];
        memset(freq,0,sizeof(freq));
        
        int fMax = 0;
        for(int i=0; i<tasks.size(); i++)
        {
            freq[tasks[i]-'A']++;
            if(fMax < freq[tasks[i] - 'A']) fMax = freq[tasks[i] - 'A']; 
        }
        
        int nMax = 0;
        for(int i=0; i<26; i++)
        {
            if(freq[i] == fMax) nMax++;
        }
        
        return (tasks.size() >= nMax + (fMax-1)*(n+1)) ? tasks.size() : nMax + (fMax-1)*(n+1);
    }
};
        
        
        
        
        //wrong ans because for ["A", "A", "A", "A", "A", "B", "B", "B", "B", "B", "C", "C", "C", "C", "C", "D", "D", "D"], n = 1
        //ans will come 13 but should be 12
        //reason is the last D doesn;t need to wait for the idle time between tasks because first D can be inserted between prev seq of repeated tasks as cool down period = n so the diff between 2 same tasks can also be n+1
        
        
        /*int t = 1;
        map<int, char> timeToTask; //at what time which task will be done
        map<char, int> lastTimeAtTask; //what was the time at the last occurrence of this task
        //this is to handle cases like [A,B,A] whose answer is 4 not 3.
        
        int l = tasks.size();
        int time[l]; //index to time at which task[index] will execute
        for(int i=0; i<l; i++) time[i] = 0;
        
        time[0] = 1;
        timeToTask[1] = tasks[0];
        lastTimeAtTask[tasks[0]] = 1;
        
        int biggest = 1;
        for(int i=1; i<l; i++)
        {
            if(lastTimeAtTask.find(tasks[i]) != lastTimeAtTask.end())
            {
                time[i] = lastTimeAtTask[tasks[i]] + n + 1;
                timeToTask[time[i]] = tasks[i];
                lastTimeAtTask[tasks[i]] = time[i];
                
                if(time[i] > biggest) biggest = time[i];
            }
            else
            {
                //new type of task - so search what time is not already taken
                while(timeToTask.find(t) != timeToTask.end())
                {
                    t++;
                }
                
                timeToTask[t] = tasks[i];
                lastTimeAtTask[tasks[i]] = t;
                time[i] = t;
                if(t > biggest) biggest = t;
            }
        }
        
        return biggest;*/
   