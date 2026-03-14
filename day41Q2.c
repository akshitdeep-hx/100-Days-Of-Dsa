/*
You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

Return the minimum number of CPU intervals required to complete all tasks.

 

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2

Output: 8

Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.
*/
#include <stdio.h>
#include <stdlib.h>

int allDone(int freq[]) {
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0)
            return 0;
    }
    return 1;
}

int leastInterval(char* tasks, int tasksSize, int n) {
    int freq[26] = {0};
    int cooldown[26] = {0};

    for (int i = 0; i < tasksSize; i++) {
        freq[tasks[i] - 'A']++;
    }

    int time = 0;

    while (!allDone(freq)) {
        int taskIndex = -1;
        int maxFreq = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0 && cooldown[i] == 0 && freq[i] > maxFreq) {
                maxFreq = freq[i];
                taskIndex = i;
            }
        }

        if (taskIndex != -1) {
            freq[taskIndex]--;
            cooldown[taskIndex] = n + 1;
        }

        for (int i = 0; i < 26; i++) {
            if (cooldown[i] > 0)
                cooldown[i]--;
        }

        time++;
    }

    return time;
}