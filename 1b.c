#include<stdio.h>
                #include<stdlib.h>
                
                typedef struct
                {
                  int id;
                  int at;  // Arrival Time
                  int bt;  // Burst Time
                  int rt;  // Remaining Time
                  int ct;  // Completion Time
                  int tat; // Turnaround Time
                  int wt;  // Waiting Time
                } process; //  processess
                
                void calculateTimes(process processes[], int n)
                
                {
                  int curr_time = 0, completed = 0;int INT_MAX;
                  int min_rt, shortest = 0, finish_time;
                  int total_tat = 0, total_wt = 0;
                  printf("the gantt chart\n");
                
                  // to execute untill all the programs completed
                  while (completed != n)
                  {
                    // to find shortest processess
                    min_rt = INT_MAX;
                    for (int i = 0; i < n; i++)
                    {
                      if (processes[i].at <= curr_time && processes[i].rt < min_rt && processes[i].rt > 0)
                      {
                        min_rt = processes[i].rt; // instead of burst time we should use remaining as its a preemptive
                        shortest = i;
                      }
                    }
                
                    // if no precess arrived just move
                    if (min_rt == INT_MAX)
                    {
                      curr_time++;
                      continue;
                    }
                     printf("P%d\t",processes[shortest].id);
                    // one second of execution
                    processes[shortest].rt--;
                    curr_time++;
                
                    if (processes[shortest].rt == 0)
                    {
                      completed++;
                      finish_time = curr_time;
                      processes[shortest].ct = finish_time;
                      processes[shortest].tat = finish_time - processes[shortest].at;
                      processes[shortest].wt = processes[shortest].tat - processes[shortest].bt;
                
                      total_tat += processes[shortest].tat;
                      total_wt += processes[shortest].wt;
                    }
                  }
                
                  printf("\nprocess\tArrival\tBurst\tComp\tTurnaround\tWaiting\n");
                  for (int i = 0; i < n; i++)
                  {
                    printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\n", processes[i].id,
                           processes[i].at, processes[i].bt,
                           processes[i].ct, processes[i].tat,
                           processes[i].wt);
                  }
                  printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);
                  printf("Average Waiting Time: %.2f\n", (float)total_wt / n);
                }
                
                int main()
                {
                  int n;
                
                  printf("Enter the number of processesses: ");
                  scanf("%d", &n);
                
                  process processes[n];
                  printf("Enter the arrival and burst time for each processess:\n");
                  for (int i = 0; i < n; i++)
                  {
                    processes[i].id = i + 1;
                    printf("processess P%d:\n", processes[i].id);
                    printf("Arrival time: ");
                    scanf("%d", &processes[i].at);
                    printf("Burst time: ");
                    scanf("%d", &processes[i].bt);
                    processes[i].rt = processes[i].bt; // here  iam using remaining time
                  }
                
                  calculateTimes(processes, n);
                
                  return 0;
                }
                