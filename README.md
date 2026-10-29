# Browser History Management System

A console-based Browser History Management System developed using **C programming** and a **Doubly Linked List**. This project demonstrates how browser navigation works using fundamental Data Structures and Algorithms (DSA).

## Features

* 🌐 Visit a new website
* ⬅️ Navigate to the previous website
* ➡️ Navigate to the next website
* 📍 Display the current website
* 📜 Display complete browsing history
* 🗑️ Clear browser history
* 🔄 Automatically remove forward history when visiting a new website

## Technologies Used

* **Programming Language:** C
* **Data Structure:** Doubly Linked List
* **Memory Management:** Dynamic memory allocation (`malloc` and `free`)
* **Concepts:** Pointers, insertion, deletion, and traversal

## Project Structure

```text
Browser-History-Management-System/
├── browser_history.c
└── README.md
```

## How to Compile and Run

### Step 1: Compile the program

```bash
gcc browser_history.c -o browser
```

### Step 2: Run the program

**Linux / macOS:**

```bash
./browser
```

**Windows:**

```bash
browser.exe
```

## Menu Options

1. Visit Website
2. Go Back
3. Go Forward
4. Current Website
5. Display History
6. Clear History
7. Exit

## How It Works

The system stores visited websites as nodes in a doubly linked list. Each node contains a website URL and pointers to the previous and next nodes.

* **Back:** Moves the current pointer to the previous node.
* **Forward:** Moves the current pointer to the next node.
* **Visit Website:** Adds a new node after the current page and removes any forward history.
* **Display History:** Traverses the linked list and displays all stored websites.

## Time Complexity

| Operation       | Time Complexity                                              |
| --------------- | ------------------------------------------------------------ |
| Go Back         | O(1)                                                         |
| Go Forward      | O(1)                                                         |
| Current Website | O(1)                                                         |
| Display History | O(n)                                                         |
| Clear History   | O(n)                                                         |
| Visit Website   | O(k), where k is the number of forward-history nodes removed |

Here, `n` is the total number of websites and `k` is the number of nodes deleted from forward history.

## Future Enhancements

* Save browsing history using file handling
* Add bookmarks
* Search previously visited websites
* Store website visit dates and times
* Implement a graphical user interface

## Learning Outcomes

This project helps develop practical knowledge of:

* Doubly linked lists
* Dynamic memory allocation
* Pointer manipulation
* Insertion and deletion operations
* Data Structures and Algorithms in C

## License

This project is open source and available for educational purposes.
