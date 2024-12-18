# Cursus 42 - Mini_talk
This project is a simple client-server communication system implemented using signals in C. The client sends a message to the server, and the server receives and displays the message character by character.
## Mandatory part

You must create a communication program in the form of a client and a server.
• The server must be started first. After its launch, it has to print its PID.
• The client takes two parameters: ◦ The server PID.
◦ The string to send.
• The client must send the string passed as a parameter to the server.
Once the string has been received, the server must print it.
• The server has to display the string pretty quickly. Quickly means that if you think it takes too long, then it is probably too long.
• Your server should be able to receive strings from several clients in a row without needing to restart.
• The communication between your client and your server has to be done only using UNIX signals.
• You can only use these two signals: SIGUSR1 and SIGUSR2.

## Bonus part
Bonus list:
• The server acknowledges every message received by sending back a signal to the client.
• Unicode characters support!
# Installation
1. git clone of repo
2. make
3. ./server
4. ./client <name from the server> <"any message you want to write in strings">

<img width="900" alt="Screenshot 2024-12-01 at 17 35 30" src="https://github.com/user-attachments/assets/49a8f749-1fd5-4530-bc09-244ee47722bc">


