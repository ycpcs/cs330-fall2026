---
layout: default
course_number: CS330
title: "Programming Assignment: Three Letter Match"
---

## Lab Summary: Three Letter Match
In this lab, you will modify the existing _tcp_client_ and _tcp_server_ programs to implement the word game *Three Letter Match*. The goal is to select a random three-letter combination and challenge yourself (as the player) to find as many valid dictionary words as possible that contain that substring.

---

### Game Rules and Functionality Overview

1. **Selecting the Substring**
   - The client starts by choosing a three-letter substring and sends it to the server using the `Set` command.
   - The substring must contain only alphabetic characters (no numbers or symbols).
   - Comparisons should be case-insensitive.

2. **Dictionary Validation**
   - The server will validate submitted words using the dictionary file [words](files/words.txt).
   - The client should not have direct access to the dictionary file.

3. **Submitting Words**
   - The client submits words using the `Submit` command.
   - The server checks two conditions:
     - **Validity:** The word must exist in the dictionary.
     - **Substring Match:** The word must contain the selected three-letter substring.

4. **Scoring**
   - If the word is valid and contains the substring, the client earns **+1 point**.
   - If the word is invalid or does not contain the substring, the client loses **1 point**.
   - Repeated submissions of the same word should not earn additional points.

5. **Listing Words**
   - The `List` command displays all dictionary words containing the current substring.
   - After listing, the client may continue submitting guesses unless the game has ended.

6. **Ending the Game**
   - The `Quit` command ends the game and displays the client’s final score.

7. **Available Commands**
   1. `Set`: Choose a new three-letter substring.
   2. `Submit`: Submit a word to check for validity and substring match.
   3. `List`: Request all words containing the current substring.
   4. `Quit`: Exit the game and display the final score.

8. **Client Input & Output**
   - All commands are read from standard input.
   - Responses (e.g., results, score updates, error messages) are displayed on standard output.
   - Each message sent between client and server should be newline-terminated ASCII text (e.g., `SUBMIT later\n`).

9. **Server Behavior**
   - The server runs continuously and may handle multiple clients.
   - It should remain active until explicitly terminated or instructed to shut down.

10. **Buffer Limits**
    - The maximum buffer size for client messages is **512 bytes**.

---

### Example Client–Server Interaction


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

### Client - Server Example Interaction Diagram 

```text
┌──────────┐             ┌────────────┐
│  Client  │             │   Server   │
└────┬─────┘             └────┬───────┘
     │                         │
     │  Connect (TCP Socket)   │
     ├────────────────────────>│
     │                         │
     │  SET ate                │
     ├────────────────────────>│
     │                         │  Save substring = "ate"
     │                         │  Respond "Substring set"
     │<────────────────────────┤
     │                         │
     │  SUBMIT late            │
     ├────────────────────────>│
     │                         │  Check in dictionary
     │                         │  Contains "ate" → +1 point
     │<────────────────────────┤
     │  "Valid! Score: 1"      │
     │                         │
     │  LIST                   │
     ├────────────────────────>│
     │                         │  Send all matches containing "ate"
     │<────────────────────────┤
     │                         │
     │  QUIT                   │
     ├────────────────────────>│
     │                         │  Send final score, close socket
     │<────────────────────────┤
     │ Connection closed       │

```
---

### Design Decisions

When completing the lab, you must make and document several design choices. Include your reasoning for each decision in your code comments and README file.

1. **Handling Multiple Clients**
   - How will the server handle multiple simultaneous clients?
   - Consider whether to use multithreading, multiprocessing (`fork()`), or synchronous I/O multiplexing (`select()`).
   - Explain why your chosen approach is suitable for this application.

2. **Tracking Client Scores**
   - How will you store each client’s score?
   - For example, you might use a dictionary or list that maps each connected client to its score.
   - Justify your chosen data structure.

3. **Behavior After `List`**
   - After a client uses `List`, can they continue submitting guesses?
   - Decide whether the game should continue normally or if the client’s turn should pause or reset.

4. **Handling Invalid Substrings**
   - How should the server respond if a client submits a substring that isn’t exactly three letters long?
   - Define clear error handling (e.g., reject and prompt to try again).

5. **General Input Validation**
   - How will you handle invalid input, such as empty strings or non-alphabetic characters?
   - Decide whether to reject the input, penalize the client, or display an error message.

---

### Documentation

1. **Code Comments**
   - Include clear and meaningful comments throughout your code that explain:
     - What changes you made to the original source.
     - Why each change was made (design rationale).
     - How you implemented the change.
   - Lack of proper documentation will result in point deductions.

2. **README File**
   - Include a `README` file with your submission that provides:
     - Instructions on how to run the client and server programs.
     - A summary of the game rules.
     - Descriptions of your key design decisions.
     - Any setup or configuration instructions.
     - Example commands and sample output (recommended).

---

### Pair Work and Submission

- If working in pairs, submit **one** copy of your code.
- Both partners’ names must appear in:
  - The source code comments, and
  - The README file.
- Both partners must contribute to all aspects of the project (design, coding, testing, documentation).
- Submit your report and source files via [Marmoset](https://cs.ycp.edu/marmoset) by the due date listed in the syllabus.

---

### References

- [Linux Socket Interface](https://linux.die.net/man/7/socket)
- [Beej’s Guide to Network Programming](https://beej.us/guide/bgnet/html/)
- [Debugging with GDB](https://ftp.gnu.org/old-gnu/Manuals/gdb/html_node/gdb_toc.html)
- [fork() — Create a Child Process](https://linux.die.net/man/2/fork)
- [select() — Synchronous I/O Multiplexing](https://www.man7.org/linux/man-pages/man2/select.2.html)
- [Netcat Utility](http://netcat.sourceforge.net/) — for testing connections to TCP/UDP ports

---

### Grading Criteria

| Category                | Requirements                                                                                                   |
| ----------------------- | -------------------------------------------------------------------------------------------------------------- |
| **README File**         | Clear instructions, rules, and design discussion                                                               |
| **Compile & Run**       | Programs compile and run without errors                                                                        |
| **Menu Flow**           | Supports Set → Submit → List → Quit sequence                                                                   |
| **Consecutive Runs**    | Supports multiple rounds (Set after List)                                                                      |
| **Score Tracking**      | Accurate scoring behavior                                                                                      |
| **Multiple Clients**    | Server supports concurrent clients                                                                             |
| **Static Buffer Limit** | All buffers ≤ 512 bytes                                                                                        |
| **Error Handling**      | Gracefully handles: invalid substring length, invalid characters, duplicate submissions, and Submit after List |
| **Test Substring**      | Use and test with substring `ate`                                                                              |
| **Client Restrictions** | Client must not read or access `words.txt` directly                                                            |

---

### Notes

> Example test for substring frequency:
> ```bash
> cat words.txt | perl -nlE '$_=lc; $l=length; next if $l < 3; m/(.{3,$l})(?{ $freq{$1}++ })^/; END { say "$freq{$_} $_" for keys %freq }' | sort -rg | head -10
> ```

---