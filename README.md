# 📡 Minitalk – Interprocess Communication in C

Minitalk is a project that implements communication between processes using UNIX signals. It allows sending messages from a client to a server using SIGUSR1 and SIGUSR2, demonstrating low-level interprocess communication in C.
# 🚀 Features

    - Uses SIGUSR1 and SIGUSR2 for bitwise message transmission.
    - Implements signal handling for reliable data transfer.
    - Provides a simple client-server messaging system.

# 🛠 Installation & Compilation
```
make // or make bonus
```
This will generate the server and client executables.

To start the server:
```
./server // or ./server_bonus
```
The server will print its Process ID (PID).

To send a message from the client:
```
./client <server_pid> "Your message here" // or ./client_bonus
```
# 📜 Usage Example

Start the server:

$ ./server  
Server PID: 12345  

Send a message from the client:

$ ./client 12345 "Hello, minitalk!"  

The server will receive and print:

Received: Hello, minitalk!  

# 🏆 Learning Outcomes

✅ Understanding UNIX signals (SIGUSR1, SIGUSR2)

✅ Bitwise operations for message encoding

✅ Signal handling and interprocess communication
