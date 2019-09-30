#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h> 


struct item_stock {
    int id;
    float uprice;
    int qty;
};

struct req {
    int id, qty, good;
    float tprice;
    char msg[50];
};

int main(void) {
    // filling data in amounts
    struct item_stock items[5];
    for(int i=0, idstart=1234; i<5; i++) {
        items[i].id = idstart+i;
        items[i].uprice = idstart+(i+1)*100;
        items[i].qty = (i+1)*10;

        printf("item: id=%d, uprice=%.2f, qty=%d \n", items[i].id, items[i].uprice, items[i].qty);
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
		printf("Received: Item id=%d, qty=%df \n", r.id, r.qty);
       
        int i;
        for(i=0; i<5; i++) {
            if(items[i].id == r.id) {
                if(items[i].qty < r.qty) {
                    printf("Err: Requested qty > Stock qty! \n");
                    strcpy(r.msg, "Err: Requested qty > Stock qty!");
                    r.good = 0;
                } else {
                    items[i].qty -= r.qty;
                    r.tprice = r.qty*items[i].uprice;   
                    printf("%.2f is the total price, remaining qty is %d \n", r.tprice, items[i].qty);
                    strcpy(r.msg, "Total price is ");
                    r.good = 1;
                }

                break;
            }
        }
    
        if(i==5) {
            printf("Err: Item id not found! \n");
            strcpy(r.msg, "Err: Item id not found!");
            r.good = 0;
        }
		
		send(clientSocket, &r, bufSize, flags);
		printf("[Sent] \n\n");

	close(socketfd);
	return 0;
}
