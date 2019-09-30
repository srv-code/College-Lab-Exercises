#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h> 


struct acc_info {
    int accno;
    float bal;
};

struct req {
    int accno, good;
    float amt, rem;
    char msg[50];
};

int main(void) {
    // filling data in amounts
    struct acc_info accs[5];
    for(int i=0, accstart=1234; i<5; i++) {
        accs[i].accno = accstart+i;
        accs[i].bal = accstart+(i+1)*100;
    }

	struct sockaddr_in selfAddress, clientAddress;
	const int flags = 0;
	const int clientQueueSize = 1;
	int socketfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	selfAddress.sin_family = AF_INET;
	selfAddress.sin_port = htons(5300);
	selfAddress.sin_addr.s_addr = htonl(2130706433);

	unsigned int bufSize = sizeof(struct req);
	unsigned int clientAddressSize = sizeof(clientAddress);

	bind(socketfd, (struct sockaddr*) &selfAddress, sizeof(struct sockaddr));
	
	struct req r;

	listen(socketfd, clientQueueSize);
    printf("[Server started] \n");

	int clientSocket = accept(socketfd, (struct sockaddr*) &clientAddress, &clientAddressSize);

		recv(clientSocket, &r, bufSize, flags);
		printf("Received: accno=%d, amt=%.2f \n", r.accno, r.amt);
        
        int i;
        for(i=0; i<5; i++) {
            if(accs[i].accno == r.accno) {
                if(accs[i].bal < r.amt) {
                    printf("Err: Withdrawl amount > Account balance! \n");
                    strcpy(r.msg, "Err: Withdrawl amount > Account balance!");
                    r.good = 0;   
                } else {
                    accs[i].bal -= r.amt;
                    printf("%.2f/- debited from your account, remaining balance is %.2f \n", r.amt, accs[i].bal);
                    strcpy(r.msg, " debited from your account, remaining balance is ");
                    r.good = 1;
                    r.rem = accs[i].bal;
                }

                break;
            }
        }
    
        if(i==5) {
            printf("Err: Account number not found! \n");
            strcpy(r.msg, "Err: Account number not found!");
            r.good = 0;
        }
		
		send(clientSocket, &r, bufSize, flags);
		printf("[Sent] \n\n");

	close(socketfd);
	return 0;
}
