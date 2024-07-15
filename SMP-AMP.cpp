#include <bits/stdc++.h>
using namespace std;

void smp(vector<int>&tasks,int n) {
  int cnt = 0,total = 0;
  vector<int> queue;
  for(int i=1;i<=n;i++,cnt++) {
    queue.push_back(tasks[i-1]);
    cout << "Task " << cnt << " is assigned to processor " << i-1 << endl;
  }
  while(cnt<tasks.size()) {
    int mini = *min_element(queue.begin(),queue.end());
    for(int i=0;i<n;i++) {
      queue[i]-=mini;
      if(queue[i]==0) {
        queue[i] = tasks[cnt];
        cout << "Task " << cnt++ << " is assigned to processor " << i << endl;
        total+=mini;
      }
    }
  }
  total+=*max_element(queue.begin(),queue.end());
  cout << "Total time taken is " << total << "ms\n";
}

void amp(vector<int>&tasks,int n) {
  cout << "Assigned Processor 0 as Master\n";
  int cnt = 0,total = 0;
  vector<int> queue(n-1);
  for(int i=1;i<n;i++,cnt++) {
    queue[i-1] = tasks[i-1];
    cout << "Master assigned task " << i-1 << " to slave " << i << endl;
  }
  while(cnt<tasks.size()) {
    int mini = *min_element(queue.begin(),queue.end());
    for(int i=1;i<n;i++) {
      queue[i]-=mini;
      if(queue[i]==0) {
        queue[i] = tasks[cnt];
        cout << "Master assigned task " << cnt++ << " to slave " << i << endl;
        total+=mini;
      }
    }
  }
  total+=*max_element(queue.begin(),queue.end());
  cout << "Total time taken is " << total << " ms\n";
}

int main() {
  int n,processors,choice;
  cout << "Enter no.of tasks: ";
  cin >> n;
  vector<int> tasks(n);
  for (int i = 0; i < n; i++) {
    cout << "Enter task " << i << " duration: ";
    cin >> tasks[i];
  }
  cout << "Enter no.of processors: ";
  cin >> processors;
  do {
    printf("1: Symmetric  2: Asymmetric  3: Exit\n");
    cin >> choice;
    switch(choice) {
      case 1: cout << "SMP running...\n";
              smp(tasks,processors);
              break;
      case 2: cout << "AMP running...\n";
              amp(tasks,processors);
              break;
      case 3: break;
    }
  } while(choice != 3);
  return 0;
}
