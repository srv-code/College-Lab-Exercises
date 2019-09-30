/* 14) The client stores an operator and corresponding 
		operands in a shared memory. These contents are 
		read by the server and the result is processed 
		and returned back to the client accordingly.
		
	>> Global data
*/

/* Signals for client server communication */
const int SIG_EXEC = 1; /* Signal from client to server: start processing with provided data in shm */
const int SIG_DONE = 2; /* Signal from server to client: processed result has been placed in shm */
const int SIG_STOP = 3; /* Signal from client to server: stop waiting for any further inputs and prepare to shutdown */

/* Shared mem size:
 *	[0]: 1 for int signal
 *	[1]: 1 for int operator (in ASCII)
 *	[2]: 1 for int operand 1
 *	[3]: 1 for int operand 2
 *	[4]: 1 for int result
 * Total = 5;
 */
const int SHMSZ = 5*sizeof(int);