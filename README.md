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

## Folder Structure
DSA-VISUALIZER/
│
├── structures/
│ ├── Array.h
│ ├── Stack.h
│ ├── Queue.h
│ ├── LinkedList.h
│ └── BinaryTree.h
│
├── ui/
│ ├── UI.h
│ └── UI.cpp
│
├── visuals/
│ ├── Animation.h
│ ├── Visualizer.h
│ └── Visualizer.cpp
│
├── main.cpp
├── README.md
└── DSAVisualizer.exe (generated after build)


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
## 🎮 Features

### ✔ Animated Insertions  
Every time you press **Insert Random**, a random value is generated and animated into:

- Array
- Stack
- Queue
- Linked List
- Binary Search Tree

### ✔ Smooth Sorting  
The **Sort** button sorts the selected data structure using:

- `std::sort()` for Array, Stack, Queue, Linked List  
- BST is inherently sorted  

### ✔ Clean UI  
- Sidebar for selecting the structure  
- Buttons for Insert, Remove, Sort  
- Real-time animated drawing  

---

## 📘 Data Structures Implemented

### **Array**
- Push back  
- Remove last  
- Smooth element movement animation  

### **Stack**
- Push & Pop  
- Animated element stacking  

### **Queue**
- Enqueue & Dequeue  
- Elements slide forward smoothly  

### **Linked List**
- Insert at tail  
- Delete last  
- Nodes move smoothly across screen  

### **Binary Tree (BST)**
- Auto-positioned nodes  
- Smooth transitions using `AnimatedPos`  
- Lines drawn between child/parent  

---

## 🎨 Tech Used

- **C++**
- **raylib** (graphics)
- **std::vector**, **std::queue**
- Custom animation system (`AnimatedPos`)

---

## 📜 License
This project is open-source. You may modify and use it freely.

---

## 👤 Author
Ruyoj KC  
DSA Visualizer Project


