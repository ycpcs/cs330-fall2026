---
layout: default
course_number: CS330
title: "Programming Assignment: Chat Application using C Sockets"
---
  
### Background
In the digital age, chat applications are essential for real-time communication, whether for personal conversations, professional collaboration, or social networking. These applications often rely on client-server architectures where the server handles incoming messages from multiple clients, and the clients send and receive messages from one another.

In this assignment, you will gain hands-on experience with socket programming, multi-threading, and basic client-server design. By implementing a chat application in C, you will deepen your understanding of how communication between computers works over a network.

### Objective
The objective of this assignment is to implement a basic chat application that uses C sockets to enable client-server communication. Specifically, you will:
1. Create a server that listens for incoming client connections.
2. Develop a client application that connects to the server to send and receive messages.
3. Explore multi-threading by ensuring that the server can handle multiple clients simultaneously.
4. Learn how messages are passed over TCP/IP using sockets.

### Server Implementation

#### 1. **Socket Creation and Binding**
   - Create a TCP socket in the server.
   - Bind the socket to a specified port (e.g., 9090).
   - Make sure the server listens for incoming connections.

#### 2. **Handling Multiple Clients**
   - Use multi-threading (e.g., pthreads) or I/O multiplexing (e.g., `select()`) to handle multiple clients at once.
   - Each client connection should be handled by a separate thread or using non-blocking I/O, ensuring the server can continue to accept new clients while handling active ones.

#### 3. **Message Handling**
   - The server should receive messages from clients and broadcast these messages to all connected clients.
   - Print all received messages to the server console for debugging purposes.

#### 4. **Graceful Client Termination**
   - Implement signal handling (e.g., `Ctrl+C`) for graceful shutdown of the server.
   - Ensure that the server properly cleans up and closes any open sockets when shutting down.

### Client Implementation

#### 1. **Socket Creation**
   - Implement a client that creates a socket and connects to the server.

#### 2. **User Input**
   - The client should continuously accept user input from the console.

#### 3. **Message Sending**
   - Allow the client to send messages to the server when the user types a message and presses "Enter".

#### 4. **Receiving Messages**
   - The client should listen for incoming messages from the server and display them in the client console.

#### 5. **Exit Command (Extra Credit)**
   - Implement an "Exit" or "Escape" command that allows the user to gracefully leave the chat, disconnecting from the server.

### Technical Specifications

- **Programming Language**: C
- **Sockets**: TCP sockets using the `socket()`, `bind()`, `listen()`, `accept()`, `recv()`, and `send()` functions.
- **Concurrency**: Use the `select()` system call for non-blocking I/O or pthreads for handling multiple client connections.
- **Compilation**: Provide detailed instructions on how to compile the server and client code using `gcc` (e.g., `gcc -o server tcp_server.c -lpthread`).

### Simple Testing Procedure

1. **Start the Server**:
   - Compile and run the server using the provided instructions.
   - The server should output a message indicating that it is listening for connections, such as: 
     ```
     Server is listening on port 9090...
     ```

2. **Start Multiple Clients**:
   - Compile and run the client code in different terminal windows.
   - Each client should connect to the server and be able to send messages.
   - Messages sent from one client should be echoed back and visible on all connected clients' terminals.
   
3. **Testing Multiple Clients**:
   - Test with at least three clients to ensure the server is properly broadcasting messages to all connected clients.

### Grading Criteria

#### Functionality (60%)
- **Server**:
  - Correctly accepts and handles multiple client connections concurrently.
  - Broadcasts messages to all connected clients.
  - Gracefully handles client disconnections and server shutdown.
- **Client**:
  - Correctly sends and receives messages.
  - Handles user input and displays messages correctly.

#### Code Quality (20%)
- Clear, organized code with appropriate variable names and structure.
- Proper error handling for socket operations.
- Use of comments and documentation to explain key parts of the code.

#### Documentation (20%)
- A **README** file that includes:
  - A brief description of the application and its functionality.
  - Clear, step-by-step instructions on how to compile and run the server and client.
  - Example usage of the program with expected behavior.
  
### Code Snippets
- **[tcp_client.c](sockets/tcp_client.c)**: Client-side code for sending and receiving messages.
- **[tcp_server.c](sockets/tcp_server.c)**: Server-side code for handling multiple clients and broadcasting messages.
- **Synchronous I/O Multiplexing using [select](https://www.man7.org/linux/man-pages/man2/select.2.html)**: Information on how to use `select()` for non-blocking I/O multiplexing.

### Grading Submission
- Submit your completed code, along with the README and any other relevant files, to **Marmoset** by the due date specified in the course syllabus.
- Include a brief report summarizing your implementation, challenges faced, and solutions.

---

### Suggested Improvements/Extensions:
- **Extra Credit**:
  - Add a feature that timestamps messages.
  - Implement a private messaging system where users can message each other individually.
  - Include a "list users" command to show all connected clients.
