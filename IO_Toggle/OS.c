
int taskn(char*);
int task_num;
typedef void (*functiontype)();
struct task_struct
{
  int nr;
  char* name;
  functiontype func;
  int delay;
  short int paused;
  int period;
  short int elapsed;
} task[10];

void create_task(char* name,long delay,int period,functiontype f)
{
  task[task_num].name=name;
  task[task_num].nr=task_num;
  task[task_num].func=f;
  task[task_num].delay=delay;
  task[task_num].period=period;
  task_num++;
}

void task_SetDelay(char* name, int delay)
{
  for(int i =0;i<task_num;i++)
    if(name==task[i].name)
    {
      task[i].delay=delay;
      return;
    }
}

void task_Pause(char* name)
{
  for(int i=0;i<task_num;i++)
    if(name==task[i].name)
    {
      task[i].paused=1;
      return;
    }
}

void task_PauseOff(char* name)
{
  for(int i=0;i<task_num;i++)
    if(name==task[i].name)
    {
      task[i].paused=0;
      return;
    }
}

int taskn(char* name)
{
  for(int i=0;i<task_num;i++)
    if(name==task[i].name)
    {      
      return i;
    }
  return 101;
}


void do_task(int n)
{
  task[n].func();
}

void sys_scheduler()
{ 
  
  static int i;
  if(task[i].paused==0)
  {
    if(task[i].delay==0)
    {      
      if(task[i].elapsed==task[i].period)
      {
        task[i].elapsed=0;
        do_task(i);
        i++;
        if(i==task_num) 
          i=0;        
      }
      else{task[i].elapsed++; i++; if(i==task_num) i=0; sys_scheduler();}
    }
    else{ task[i].delay--; i++; if(i==task_num) i=0; sys_scheduler();}
  }
  else {i++; if(i==task_num) i=0; sys_scheduler();}
  
}










