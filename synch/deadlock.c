/* A deadlock is when 2 or more threads cannot make progress as they are both waiting for a sema held by the other */

void down(void *sema); // obtains a sema
void up(void *sema); // release a sema

void *scanner; // pointer to scanner sema
void *dvd_writer; // pointer to dvd writer sema

// Obtains scanner then dvd writer -> p1 may have already got dvd writer so we deadlock
void p0(void) 
{
  down(scanner);
  down(dvd_writer);
  scan_and_record();
  up(dvd_writer);
  up(scanner);
}

// Obtains dvd writer then scanner -> p0 may already have scanner so we deadlock
void p1(void) 
{
  down(dvd_writer);
  down(scanner);
  scan_and_record();
  up(scanner);
  up(dvd_writer);
}