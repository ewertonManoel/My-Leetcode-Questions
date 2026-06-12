# 💡 LeetCode Solutions

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Node.js](https://img.shields.io/badge/Node.js-43853D?style=for-the-badge&logo=node.js&logoColor=white)
![LeetCode](https://img.shields.io/badge/LeetCode-000000?style=for-the-badge&logo=LeetCode&logoColor=#d16c00)
![Status](https://img.shields.io/badge/Status-Active-success?style=for-the-badge)

This repository contains my solutions to LeetCode problems. I started doing LeetCode some time ago and I had the idea of showing my solutions directly on my GitHub. However, I noticed that having to submit them by myself every time I finished a question was very repetitive. 

To fix that, I made a simple automation in Node.js to help with this process. When I am practicing, I leave a local script running in my terminal. Once a solution is accepted, I use a browser button to send the code and the problem's name to the script, which creates the `.cpp` file and pushes it to this repository. This setup helps me keep my focus on solving the problems and makes it easier to share my progress.

Focusing on the questions, my main goals with this project are:
* **Improve my problem-solving skills and pattern recognition.**
* **Prepare myself for competitive programming.**
* **Code Optimization:** Trying to achieve the best time and space complexity that I can for each solution.
* **Future expansion:** I am planning to use this repository to post Codeforces and programming olympiad questions too.

---

## 📊 Solutions

| Problem | Difficulty | Time Complexity | Space Complexity |
| :--- | :--- | :--- | :--- |
| Reverse Pairs (Fenwick Tree) | Hard | $O(n \log n)$ | $O(n)$ |
| Longest Happy Prefix (KMP) | Hard | $O(n)$ | $O(n)$ |
| Sort an Array (Introsort) | Medium | $O(n \log n)$ | $O(\log n)$ |

---

## ⚙️ How the Automation Works

* **Browser Bookmarklet:** A JavaScript button reads the problem title and code from the LeetCode editor page.
* **Local Server:** A Node.js background script receives this data and saves it as a formatted `.cpp` file in the local folder.
* **Git Integration:** The script then executes the standard Git commands to commit and push the file to this repository.

---

## Author: 
**Ewerton M. F. L. de Carvalho**
