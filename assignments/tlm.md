---
layout: default
course_number: CS330
title: "Programming Assignment: Three Letter Word Match"
---

--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

## CS 330: Three Letter Word Match

## Due: Tuesday, Nov 12, 2026 by 11:59 PM

--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

## Overview

In this assignment, you will extend the basic client/server socket programs to implement a networked word game called Three Letter Match. The server manages the active substring, validates submitted words against a dictionary, tracks client scores, and responds to commands that allow a player to participate in the game.

The goal is to help you practice the core skills introduced in the networking units: socket programming, server/client communication, input validation, concurrency, and structured documentation.

---

## Objective

The objective of this assignment is to modify or build a TCP-based client/server application so that:

1. The client can choose a three-letter substring.
2. The server validates that substring and dictionary entries.
3. The client can submit words and receive score updates.
4. The server can list matching words for the current substring.
5. The server can handle multiple clients and maintain correct per-client score state.

By completing the assignment, you will gain practical experience in networked application design, concurrency, protocol handling, and robust error checking.

---

## Game Rules and Functionality

### 1. Selecting the Substring
- The client starts by choosing a three-letter substring and sends it to the server using the `SET` command.
- The substring must contain only alphabetic characters.
- Comparisons should be case-insensitive.
- Invalid input should be rejected with a clear error message.

### 2. Dictionary Validation
- The server validates submitted words using the dictionary file [words](files/words.txt).
- The client **must not have** direct access to the dictionary file.
- A word is valid only if it appears in the dictionary.

### 3. Submitting Words
- The client submits guesses using the `SUBMIT` command.
- The server checks both conditions:
  - The word exists in the dictionary.
  - The word contains the selected substring.

### 4. Scoring
- If a valid word contains the selected substring, the client earns `+1` point.
- If the word is invalid or does not contain the substring, the client loses `-1` point.
- Repeated submissions of the same word should not award additional points.

### 5. Listing Words
- The `LIST` command displays all dictionary words containing the active substring.
- After a client sends `LIST`, no further points may be awarded for that round.
- The client may not continue submitting guesses after `LIST`; the round is effectively ended until a new substring is chosen with `SET`.

### 6. Ending the Game
- The `QUIT` command ends the session and displays the final score.

### 7. Available Commands
1. `SET` — choose a new three-letter substring.
2. `SUBMIT` — submit a word to check for validity and substring match.
3. `LIST` — request all words containing the current substring.
4. `QUIT` — exit the game and display the final score.

### 8. Client Input and Output
- All commands are read from standard input.
- Responses are displayed on standard output.
- The user must type a command and press the Enter key to send it.
- Messages between the client and server should be newline-terminated ASCII text, for example `SUBMIT later\n`.

### 9. Server Behavior
- The server runs continuously and may handle multiple clients.
- It should remain active until explicitly terminated or instructed to shut down.

### 10. Buffer Limits
- The maximum buffer size for client messages is **512 bytes**.

---

## Example Client–Server Interaction

```bash
Client> SET ate
Server> Substring set to "ate"

Client> SUBMIT late
Server> "late" is valid! +1 point. Score: 1

Client> SUBMIT cat
Server> "cat" does not contain "ate". -1 point. Score: 0

Client> LIST
Server> Words containing "ate": ate, late, rate, fate, create, update, ...

Client> QUIT
Server> Final score: 0
Connection closed.
```

---

## Implementation Requirements

### 1. Connection Setup
- The server listens on a specified TCP port.
- The client connects to the server using an IP address and port number.
- For local testing, students may use `127.0.0.1` (localhost) as the server IP.
- The port should be passed as a command-line argument or otherwise clearly specified in the program interface.
- Example usage:
  ```bash
  ./tlm_server 9000
  ./tlm_client 127.0.0.1 9000
  ```

### 2. Server Requirements
- Implement a TCP server that accepts connections from one or more clients.
- Validate all command inputs before processing them.
- Read the dictionary file and compare submitted words against it.
- Track the current substring for each connected client or client session.
- Maintain score state for each client.
- Reject invalid commands or malformed input with clear feedback.

### 3. Client Requirements
- Implement a client that reads commands from standard input.
- Send commands to the server over a TCP socket.
- Display server responses clearly to the user.
- Do not directly access the dictionary file from the client.
- Handle repeated prompts and restart behavior correctly.

### 4. Error Handling
- Invalid substring lengths must be rejected.
- Non-alphabetic characters must be rejected.
- Empty input or malformed commands must be reported cleanly.
- Duplicate submissions should not award points again.

### 5. Concurrency and Data Structures
- The server should be able to support multiple clients concurrently.
- Use a reasonable design choice for storing scores, such as a dictionary keyed by client connection or socket descriptor.
- Explain your concurrency approach in code comments and in the README.

---

## Design Decisions

When completing the assignment, you must make and document several design choices. Include your reasoning for each decision in the source code comments and in your README.

1. **Handling Multiple Clients**
   - How will the server handle multiple simultaneous clients?
   - Consider whether to use multithreading, multiprocessing (`fork()`), or synchronous I/O multiplexing (`select()`).
   - Explain why your chosen approach is suitable for this application.

2. **Tracking Client Scores**
   - How will you store each client’s score?
   - For example, you might use a dictionary or list that maps each connected client to its score.
   - Justify your chosen data structure.

3. **Behavior After `LIST`**
   - After a client uses `LIST`, no more points may be awarded.
   - The round ends immediately after `LIST`, and the client must choose a new substring with `SET` before submitting more guesses.
   - Explain how your implementation enforces this rule and why it makes the game state predictable.

4. **Handling Invalid Substrings**
   - How should the server respond if a client submits a substring that is not exactly three letters long?
   - Define clear error handling, such as rejecting the input and prompting the user to try again.

5. **General Input Validation**
   - How will you handle invalid input, such as empty strings or non-alphabetic characters?
   - Decide whether to reject the input, penalize the client, or display an error message.

---

## Documentation Requirements

### 1. Code Comments
Include clear and meaningful comments throughout your code that explain:
- what changes were made,
- why the changes were necessary,
- how the implementation works,
- and what design decisions were made.

Lack of proper documentation will result in point deductions.

### 2. README File
Include a `README` file with your submission that contains:
- instructions for compiling and running the client and server,
- a summary of the game rules,
- descriptions of the key design decisions,
- setup or configuration notes,
- and sample command usage and expected output.

### 3. Pair Work and Submission
- If working in pairs, submit one copy of the code.
- Both partners’ names must appear in the source code comments and in the README.
- Both partners must contribute to planning, coding, testing, and documentation.
- Submit your report and source files via [Marmoset](https://cs.ycp.edu/marmoset) by the due date listed in the course syllabus.

---

## References

- [Linux Socket Interface](https://linux.die.net/man/7/socket)
- [Beej’s Guide to Network Programming](https://beej.us/guide/bgnet/html/)
- [Debugging with GDB](https://ftp.gnu.org/old-gnu/Manuals/gdb/html_node/gdb_toc.html)
- [fork() — Create a Child Process](https://linux.die.net/man/2/fork)
- [select() — Synchronous I/O Multiplexing](https://www.man7.org/linux/man-pages/man2/select.2.html)
- [Netcat Utility](http://netcat.sourceforge.net/) — for testing connections to TCP/UDP ports

---

## Grading Criteria

| Category                | Requirements                                                                                                        |
| ----------------------- | ------------------------------------------------------------------------------------------------------------------- |
| **README File**         | Clear instructions, rules, and design discussion                                                                    |
| **Compile & Run**       | Programs compile and run without errors                                                                             |
| **Command Flow**        | Supports `SET` → `SUBMIT` → `LIST` → `QUIT` sequence, with `LIST` ending the round so no more points can be awarded |
| **Consecutive Rounds**  | Supports multiple rounds and repeated substring changes after a new `SET`                                           |
| **Score Tracking**      | Accurate scoring behavior                                                                                           |
| **Multiple Clients**    | Server supports concurrent clients                                                                                  |
| **Static Buffer Limit** | All buffers are at or under 512 bytes                                                                               |
| **Error Handling**      | Gracefully handles invalid substring length, invalid characters, duplicate submissions, and invalid commands        |
| **Test Substring**      | Uses and tests the substring `ate`                                                                                  |
| **Client Restrictions** | Client does not read or access `words.txt` directly                                                                 |

---

## Helpful Testing Notes

> Example test for substring frequency:
>
> ```bash
> cat words.txt | perl -nlE '$_=lc; $l=length; next if $l < 3; m/(.{3,$l})(?{ $freq{$1}++ })^/; END { say "$freq{$_} $_" for keys %freq }' | sort -rg | head -10
> ```

This is a useful way to examine how often particular substrings appear in the dictionary and to validate the expected behavior of your game logic.

---