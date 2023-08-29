#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define NUM_PHILOSOPHERS 5
#define NUM_CHOPSTICKS 5

void dine(int n);
pthread_t philosopher[NUM_PHILOSOPHERS];
pthread_mutex_t chopstick[NUM_CHOPSTICKS];

int main()
{
  int i;
  void *msg;
 for (i = 1; i <= NUM_CHOPSTICKS; i++)
  {
    pthread_mutex_init(&chopstick[i], NULL);
  }
  for (i = 1; i <= NUM_PHILOSOPHERS; i++)
  {
    pthread_create(&philosopher[i], NULL, (void *)dine, (int *)i);
    
  }

  for (i = 1; i <= NUM_PHILOSOPHERS; i++)
  {
    pthread_join(philosopher[i], &msg);
    
  }

  for (i = 1; i <= NUM_CHOPSTICKS; i++)
  {
    pthread_mutex_destroy(&chopstick[i]);
   
  }
  return 0;
}
void dine(int n)
{
  printf("\nPhilosopher % d is thinking ", n);

  pthread_mutex_lock(&chopstick[n]);

  pthread_mutex_lock(&chopstick[(n + 1) % NUM_CHOPSTICKS]);
  
  printf("\nPhilosopher % d is eating ", n);
  sleep(3);

  pthread_mutex_unlock(&chopstick[n]);

  pthread_mutex_unlock(&chopstick[(n + 1) % NUM_CHOPSTICKS]);

  printf("\nPhilosopher % d Finished eating ", n);
} 
