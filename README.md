![Screenshot from 2023-11-01 17-11-44](https://github.com/reomelo/42Porto-minitalk/assets/73884501/2e1c603a-fc30-47af-999c-0bdb60a13ef5)

### Description of the project:
This project consists on a small data exchange between client and server programs using UNIX signals. In my case, the bonus part is already implemented with the mandatory part, even though the subject requires that they must be separated.

### Installing and running the project:
1- Clone this repository and enter it:  

	git clone https://github.com/reomelo/42Porto-minitalk.git && cd 42Porto-minitalk

2- Run `make` and execute the file `./server`:

	make && ./server

3- In another terminal execute the `./client` with the PID printed by the server and the message you want to send:

	./client <PID> <message>

### Makefile Available Targets:  
`make` or `make all` - creates minitalk.a      
`make clean` - wipes all object files   
`make fclean` - deletes minitalk.a and all object files   
`make re` - fclean  + all

___
######  At [42School](https://en.wikipedia.org/wiki/42_(school)), almost every project must be written in accordance to the [Norm](https://github.com/42School/norminette). As a result, parts of the code are not as clean, efficient or straight forward as they could be.
