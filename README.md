# 42cursus - minitalk

## About

The purpose of this project is to code a small data exchange program using UNIX signals.<br>
*For more detailed information, look at the subject of this project.*

## How to use it  

### 1.Cloning the repositories  
```shell
$ git clone https://github.com/proche-c/minitalk.git
```
### 2.Compiling  
```shell
$ cd path/to/minitalk && make
```
### 3. Cleaning all binary and executable files
```shell
$ cd path/to/minitalk && make fclean
```
### 3. Testing. 
To test the program launch the 'server' and the 'client' in different shell tabs:
```shell
$ ./server
```
This will show the PID of the 'server'process and will wait to receive a message from the 'client'.
```shell
$ ./client "PID" "message"
```
By launching it, this will show "Your message string" on the server window.
