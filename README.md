# Database Management System 

A Binary Search Tree (BST) implementation in C++ for storing and managing data efficiently. It supports insertion, search, and traversal operations, making it useful for organizing structured information.

## Installation  

1. **Download the project**:  
   - Click **Code** and **Download ZIP** on GitHub  
   - Extract the ZIP file  

2. **Install a C++ Compiler** (if not already installed):  
   - **Windows**: Install [MinGW-w64] and add `g++` to your system `PATH`.  
   - **macOS**: Install Xcode Command Line Tools with:  
     ```sh
     xcode-select --install
     ```  
   - **Linux**: Install `g++` with:  
     ```sh
     sudo apt install g++
     ```  

3. **Compile the project**:  
   - For **Windows**, **macOS**, and **Linux** users:  
     - Using **g++**:  
       ```sh
       g++ database.cpp states.cpp -o database
       ```  
     - Using **clang** (on **macOS** or systems with Clang):  
       ```sh
       clang++ database.cpp states.cpp -o database
       ```  

4. **Run the program**:  
   ```sh
   ./database
   ```

5. **Known issues**:
   - **Windows**: If the program does not run using **step 4**, try the following instead:
     ```sh
     database
     ```
   - **macOS**: If the program does not compile and returns an error, compile with the following:
     ```sh
     g++ -std=c++11 database.cpp states.cpp -o database
     ```
     **OR**
     ```sh
     clang++ -std=c++11 database.cpp states.cpp -o database
     ```
