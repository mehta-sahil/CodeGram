# **CodeGram - Social Network Simulation**  

## **📌 Project Description**  
CodeGram is a **C++-based social network simulation** that models user interactions like **friendship, follow relationships, friend suggestions, mutual friends, and influencer detection**. The program creates **dummy user profiles** with attributes like favorite sports, music genres, coding languages, and travel destinations. Users can register, log in, and interact with others based on shared interests.

---

## **🚀 Features**  
✅ **User Management**: Create accounts with attributes like age, favorite sport, music, coding language, and travel destination.  
✅ **Follow/Unfollow System**: Users can follow and unfollow other users.  
✅ **Friend Suggestions**: Recommends friends based on shared interests and mutual connections.  
✅ **Mutual Friends Finder**: Identifies common friends between two users.  
✅ **Top Influencers**: Ranks users based on the number of followers.  
✅ **User Authentication**: Login system for verifying users.  
✅ **Dummy Data Generation**: Creates **200 users** and **500 follow relationships** for testing.  

---

## **📜 How to Run**  
### **1️⃣ Compile the Code**  
Make sure you have a C++ compiler installed (e.g., g++). Run the following command:  

```bash
g++ -o codegram codegram.cpp
```

### **2️⃣ Run the Executable**  
```bash
./codegram
```

---

## **🖥️ Menu Options**  
Upon running, you will see the following menu:  
```
Welcome To CodeGram
1. Create Account
2. Login
3. Add Friend
4. Remove Friend
5. Find Mutual Friends
6. View Your Followers and Following
7. View Friend Suggestions
8. View Top 10 Coders
9. View All Users
10. Exit
```
Choose an option by entering the corresponding number.

---

## **🛠️ Example Usage**  
1️⃣ **Create an account** by selecting **option 1**, then enter details like user ID, password, age, and preferences.  
2️⃣ **Login** using **option 2** and enter your credentials.  
3️⃣ **Follow friends** using **option 3** by entering two user IDs.  
4️⃣ **Check friend suggestions** with **option 7** based on common interests.  
5️⃣ **Find top influencers** with **option 8** to see the most followed users.

---

## **📌 Project Structure**  
- **Node Class**: Represents a user with attributes like `userID`, `password`, `age`, and social connections (`followers`, `following`).  
- **Graph Class**: Handles user management, friend connections, authentication, and recommendations.  
- **Main Function**: Provides a CLI menu for user interaction.  

---

## **💡 Future Enhancements**  
🔹 Add a **Graphical User Interface (GUI)**.  
🔹 Implement **message exchange** between users.  
🔹 Store user data in a **database or file** for persistence.  

---

## **📜 License**  
This project is open-source and free to use.  

👨‍💻 Developed with ❤️ in C++  
```
