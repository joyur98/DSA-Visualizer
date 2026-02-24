# DSA Visualizer  
A modern, animated Data Structures & Algorithms visualizer built in C++ using raylib.

---

## Overview

**DSA Visualizer** is a graphical tool for learning and teaching classic data structures through smooth real-time animations.

It visually demonstrates:
- **Stacks**
- **Queues**
- **Linked Lists**
- **Binary Trees**

The purpose of this project is to make learning DSA more intuitive, visual, and interactive.

---
## Build Instructions

### Requirements
- C++17 or newer  
- **raylib** installed  
- MinGW or any compiler that supports Windows raylib linking  



### Compilation Command

Use this command to build the entire project:

g++ main.cpp ui/UI.cpp visuals/Visualizer.cpp -I. -Istructures -Iui -Ivisuals -o DSAVisualizer.exe -lraylib -lopengl32 -lgdi32 -lwinmm -lkernel32 -luser32 -lshell32

If successful, it generates
**DSAVisualizer.exe**

Run it launch the applicaiton

---
##  Features

###  Animated Insertions  
Every time you press **Insert Random**, a random value is generated and animated into:

- Stack
- Queue
- Linked List
- Binary Search Tree

###  Smooth Sorting  
The **Sort** button sorts the selected data structure using:

- `std::sort()` for Array, Stack, Queue, Linked List  
- BST is inherently sorted  

###  Clean UI  
- Sidebar for selecting the structure  
- Buttons for Insert, Remove, Sort  
- Real-time animated drawing  

---

##  Data Structures Implemented

### Stack
- Push & Pop  

### Queue
- Enqueue & Dequeue  

### Linked List
- Insert at tail  
- Delete last  

### Binary Tree (BST)
- Auto-positioned nodes  
- Smooth transitions using `AnimatedPos`  
- Lines drawn between child/parent  

---

##  Tech Used

- C++
- raylib (graphics)
- std::vector, std::queue
- Custom animation system (`AnimatedPos`)

---

##  License
This project is open-source. You may modify and use it freely.

---

##  Author
Ruyoj KC  
DSA Visualizer Project


