/* Algorithm to improve software solution to implement a critical region */

int turn = 0;
int interested[2] = {0, 0};

void enter_critical(int thread) { 
  int other = 1 - thread;
  interested[thread] = 1;
  turn = other;
  while (turn == other && interested[other]) {
    // loop
  }
}

void leave_critical(int thread) { interested[thread] = 0; }