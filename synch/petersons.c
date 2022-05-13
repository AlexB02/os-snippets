/* Algorithm to improve software solution to implement a critical region */

int turn = 0; // Records whos turn it is to enter the CR
int interested[2] = {0, 0}; // Records if a thread wants to enter CR

/* Returns when calling thread has exclusive access to CR */
void enter_critical(int thread) { 
  interested[thread] = 1; // Note interest
  int other = 1 - thread; // Other thread number
  
  /* Setting the turn to other, we allow for the other thread to have access
  to the CR first, if they are already interested in the CR when 
  the condition of the while loop is checked */
  turn = other;
  while (turn == other && interested[other]) {
    // wait busily
  }
}

/* Set the thread to no longer be interested in acquiring the CR */
void leave_critical(int thread) { interested[thread] = 0; }

// Example use:

void thread_0_entry() { 
  enter_critical(0);
  // now has access
  leave_critical(0);
}

void thread_1_entry() { 
  enter_critical(1);
  // now has access
  leave_critical(1);
}