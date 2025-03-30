# MiniTalk

MiniTalk is a **1337 School** project that implements inter-process communication using **UNIX signals**.  
It consists of a **client** and a **server**, where the client sends messages to the server **bit by bit** using `SIGUSR1` and `SIGUSR2`.

## 🛠 Features

✅ **Basic Version**  
- The client sends a message to the server using UNIX signals.  
- The server reconstructs and displays the received message.  

## 🔥 Bonus

### Features:
- Handles **Unicode message** ex. Emojis.  
- Implements **acknowledgment signal**, ensuring the client confirms receipt of the message correctely.  

## Make
```sh
   make && make bonus
```
### To use the basic version:
1. **Start the basic server**:
   ```sh
   ./serve
   ```
2. **Send a message with the basic client:**
   ```sh
     ./client <server_pid> "Hello from basic!"
   ```

### To use the bonus version:

1. **Start the bonus server**:
   ```sh
   ./server_bonus
   ```
2. **Send a message with the bonus client:**
   ```sh
     ./client_bonus <server_pid> "Hello from bonus!"
   ```

❗ Error Handling
- Invalid arguments (e.g., missing PID, empty string).
- Invalid server PID (if process doesn’t exist).

[![License](https://img.shields.io/badge/License-MIT-blue.svg)](https://github.com/med-el-hamidi/miniTalk/blob/main/LICENSE.md)
