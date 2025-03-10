#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

class Node {
public:
    string userID;
    string password;
    int age;
    string favoriteSport;
    string favoriteMusicGenre;
    string favoriteCodingLanguage;
    string favoriteTravelDestination;
    vector<Node*> followers;
    vector<Node*> following;

    Node(const string& userID, const string& password, int age, const string& favoriteSport,
         const string& favoriteMusicGenre, const string& favoriteCodingLanguage,
         const string& favoriteTravelDestination)
        : userID(userID), password(password), age(age), favoriteSport(favoriteSport),
          favoriteMusicGenre(favoriteMusicGenre), favoriteCodingLanguage(favoriteCodingLanguage),
          favoriteTravelDestination(favoriteTravelDestination) {}
};

class Graph {
public:
    vector<Node> nodes;

    Node* findNode(const string& userID) {
        for (Node& node : nodes) {
            if (node.userID == userID) {
                return &node;
            }
        }
        return nullptr;
    }

   
    void addNode(const string& userID, const string& password, int age, const string& favoriteSport,
                 const string& favoriteMusicGenre, const string& favoriteCodingLanguage,
                 const string& favoriteTravelDestination) {
        if (findNode(userID) != nullptr) {
            cout << "User ID " << userID << " already exists. Skipping this user.\n";
            return;
        }
        nodes.emplace_back(userID, password, age, favoriteSport, favoriteMusicGenre, favoriteCodingLanguage, favoriteTravelDestination);
        cout<< "user" << userID << "added successfully" << endl;
        
    }
    void addNodedummy(const string& userID, const string& password, int age, const string& favoriteSport,
                 const string& favoriteMusicGenre, const string& favoriteCodingLanguage,
                 const string& favoriteTravelDestination) {
        if (findNode(userID) != nullptr) {
            cout << "User ID " << userID << " already exists. Skipping this user.\n";
            return;
        }
        nodes.emplace_back(userID, password, age, favoriteSport, favoriteMusicGenre, favoriteCodingLanguage, favoriteTravelDestination);
        
        
    }

 
    void follow(const string& followerID, const string& followeeID) {
        Node* follower = findNode(followerID);
        Node* followee = findNode(followeeID);

        if (!follower || !followee) {
            cout << "One or both user IDs not found.\n";
            return;
        }

        if (find(follower->following.begin(), follower->following.end(), followee) != follower->following.end()) {
            cout << followerID << " is already following " << followeeID << ".\n";
            return;
        }

        follower->following.push_back(followee);
        followee->followers.push_back(follower);
        cout<< followerID << "is now following" << followeeID << endl;

    }
    void followdummy(const string& followerID, const string& followeeID) {
        Node* follower = findNode(followerID);
        Node* followee = findNode(followeeID);

        if (!follower || !followee) {
            cout << "One or both user IDs not found.\n";
            return;
        }

        if (find(follower->following.begin(), follower->following.end(), followee) != follower->following.end()) {
            // cout << followerID << " is already following " << followeeID << ".\n";
            return;
        }

        follower->following.push_back(followee);
        followee->followers.push_back(follower);
   

    }


void removeFriend(const string& followerID, const string& followeeID) {
        Node* follower = findNode(followerID);
        Node* followee = findNode(followeeID);

        if (!follower || !followee) {
            cout << "One or both user IDs not found.\n";
            return;
        }

        auto itFollower = find(follower->following.begin(), follower->following.end(), followee);
        if (itFollower != follower->following.end()) {
            follower->following.erase(itFollower);
        }

        auto itFollowee = find(followee->followers.begin(), followee->followers.end(), follower);
        if (itFollowee != followee->followers.end()) {
            followee->followers.erase(itFollowee);
        }

        cout << followerID << " is no longer following " << followeeID << ".\n";
    }
    void findInfluencers() const {
        vector<pair<int, string>> followerCounts;
        for (const Node& node : nodes) {
            followerCounts.emplace_back(node.followers.size(), node.userID);
        }

        
        sort(followerCounts.begin(), followerCounts.end(), greater<pair<int, string>>());

        cout << "\nTop influencers:\n";
        int i = 0;
        for (const auto& pair : followerCounts) {
            cout << i + 1 << ". " << pair.second << " with " << pair.first << " followers\n";
            i++;
            if (i == 10) break;
        }
    }
    void displayNodes() const {
        for (const Node& node : nodes) {
            cout << "\nUser ID: " << node.userID
                 << "\nAge: " << node.age
                 << "\nFavorite Sport: " << node.favoriteSport
                 << "\nFavorite Music Genre: " << node.favoriteMusicGenre
                 << "\nFavorite Coding Language: " << node.favoriteCodingLanguage
                 << "\nFavorite Travel Destination: " << node.favoriteTravelDestination
                 << "\nFollowers: ";

            for (const Node* follower : node.followers) {
                cout << follower->userID << " ";
            }
            cout << "\nFollowing: ";
            for (const Node* following : node.following) {
                cout << following->userID << " ";
            }
            cout << "\n";
        }
    }
    void displayNode(const string& userID)  {
        Node* node = findNode(userID);
        
        if (!node) {
            cout << "User ID " << userID << " not found.\n";
            return;
        }

        cout << "\nUser ID: " << node->userID
             << "\nAge: " << node->age
             << "\nFavorite Sport: " << node->favoriteSport
             << "\nFavorite Music Genre: " << node->favoriteMusicGenre
             << "\nFavorite Coding Language: " << node->favoriteCodingLanguage
             << "\nFavorite Travel Destination: " << node->favoriteTravelDestination
             << "\nFollowers: ";
        for (const Node* follower : node->followers) {
            cout << follower->userID << " ";
        }
        cout << "\nFollowing: ";
        for (const Node* following : node->following) {
            cout << following->userID << " ";
        }
        cout << "\n";
    }

  
    void mutualfriends(const string& friend1, const string& friend2) {
        Node* friend11 = findNode(friend1);
        Node* friend22 = findNode(friend2);
        vector<Node*> mutual;

        if (!friend11 || !friend22) {
            cout << "One or both user IDs not found.\n";
            return;
        }

       
        for (Node* person1 : friend11->following) {
        
            for (Node* person2 : friend22->following) {
                if (person1 == person2) {
                    mutual.push_back(person1);  
                    break;  
                }
            }
        }

        
        if (mutual.empty()) {
            cout << "No mutual friends found.\n";
        } else {
            cout << "Mutual friends between " << friend1 << " and " << friend2 << ":\n";
            for (Node* mutualFriend : mutual) {
                cout << mutualFriend->userID << endl;
            }
        }
    }
bool authenticateUser(const string& userID, const string& password) {
        Node* user = findNode(userID);
        if (user && user->password == password) {
            cout << "Login successful!\n";
            return true;
        } else {
            cout << "Invalid userID or password. Please try again.\n";
            return false;
        }
    }
  
void friendsuggestion(const string& userid) {
    Node* currentUser = findNode(userid);
    if (!currentUser) {
        cout << "User ID " << userid << " not found.\n";
        return;
    }

    vector<pair<Node*, int>> suggestions;

    for (Node* followingUser : currentUser->following) {
        if (!followingUser) continue;  

        for (Node* friendOfFollowing : followingUser->following) {
            if (friendOfFollowing == currentUser || 
                find(currentUser->following.begin(), currentUser->following.end(), friendOfFollowing) != currentUser->following.end()) {
                continue;  
            }

            int matchScore = 0;

            if (currentUser->favoriteSport == friendOfFollowing->favoriteSport) matchScore++;
            if (currentUser->favoriteMusicGenre == friendOfFollowing->favoriteMusicGenre) matchScore++;
            if (currentUser->favoriteCodingLanguage == friendOfFollowing->favoriteCodingLanguage) matchScore++;
            if (currentUser->favoriteTravelDestination == friendOfFollowing->favoriteTravelDestination) matchScore++;

            suggestions.push_back({friendOfFollowing, matchScore});
        }
    }

    sort(suggestions.begin(), suggestions.end(), [](const pair<Node*, int>& a, const pair<Node*, int>& b) {
        return a.second > b.second;  
    });

    cout << "\nFriend suggestions for " << userid << ":\n";
    int count = 0;
    for (const auto& suggestion : suggestions) {
        if (count >= 10) break;  
        cout << suggestion.first->userID << " - Match Score: " << suggestion.second << endl;
        count++;
    }
}

};


int main() {
    Graph graph;
    srand(time(0)); 

    vector<string> sports = {"Football", "Basketball", "Tennis", "Cricket", "Baseball"};
    vector<string> musicGenres = {"Rock", "Jazz", "Pop", "Classical", "Hip Hop"};
    vector<string> codingLanguages = {"C++", "Python", "Java", "JavaScript", "Ruby"};
    vector<string> travelDestinations = {"Paris", "Tokyo", "New York", "Sydney", "London"};


    for (int i = 1; i <= 200; ++i) {
        string userID = "user" + to_string(i);
        string password = "pass" + to_string(i);
        int age = rand() % 30 + 20;  
        string favoriteSport = sports[rand() % sports.size()];
        string favoriteMusicGenre = musicGenres[rand() % musicGenres.size()];
        string favoriteCodingLanguage = codingLanguages[rand() % codingLanguages.size()];
        string favoriteTravelDestination = travelDestinations[rand() % travelDestinations.size()];

      
        graph.addNodedummy(userID, password, age, favoriteSport, favoriteMusicGenre, favoriteCodingLanguage, favoriteTravelDestination);
    }
    cout << "dummy users created!" <<endl;

    
    for (int i = 0; i < 500; ++i) {  
        int followerIndex = rand() % 200;
        int followedIndex = rand() % 200;
        if (followerIndex != followedIndex) {
            graph.followdummy("user" + to_string(followerIndex + 1), "user" + to_string(followedIndex + 1));
        }
    }
    cout << "Followings generated!" <<endl;
    while (true)
    {
        cout << "Welcome To CodeGram" <<endl;
        cout << "1.Create Account" << endl;
        cout << "2.Login" << endl;
        cout << "3.Add Friend" << endl;
        cout << "4.Remove friend" << endl;
        cout << "5.Find Mutual Friends" << endl;
        cout << "6.View Your Followers and Following" << endl;
        cout << "7.View Friend Suggestions" << endl;
        cout << "8.View Top 10 Coders" << endl;
        cout << "9.View All Users" << endl;
        cout << "10.Exit" << endl;

        int num;
        cin >> num;
        switch (num)
        {
            case 1: {
                string userID, password, favoriteSport, favoriteMusicGenre, favoriteCodingLanguage, favoriteTravelDestination;
                int age, choice;

                cout << "Enter user ID: ";
                cin >> userID;
                
                cout << "Enter password: ";
                cin >> password;
                
                cout << "Enter age: ";
                cin >> age;
                
                cout << "Choose your favorite sport:\n";
                for (int i = 0; i < sports.size(); ++i) {
                    cout << i + 1 << ". " << sports[i] << endl;
                }
                cout << "Enter choice (1-5): ";
                cin >> choice;
                favoriteSport = sports[choice - 1];

                cout << "\nChoose your favorite music genre:\n";
                for (int i = 0; i < musicGenres.size(); ++i) {
                    cout << i + 1 << ". " << musicGenres[i] << endl;
                }
                cout << "Enter choice (1-5): ";
                cin >> choice;
                favoriteMusicGenre = musicGenres[choice - 1];

                cout << "\nChoose your favorite coding language:\n";
                for (int i = 0; i < codingLanguages.size(); ++i) {
                    cout << i + 1 << ". " << codingLanguages[i] << endl;
                }
                cout << "Enter choice (1-5): ";
                cin >> choice;
                favoriteCodingLanguage = codingLanguages[choice - 1];

                cout << "\nChoose your favorite travel destination:\n";
                for (int i = 0; i < travelDestinations.size(); ++i) {
                    cout << i + 1 << ". " << travelDestinations[i] << endl;
                }
                cout << "Enter choice (1-5): ";
                cin >> choice;
                favoriteTravelDestination = travelDestinations[choice - 1];

                graph.addNode(userID, password, age, favoriteSport, favoriteMusicGenre, favoriteCodingLanguage, favoriteTravelDestination);
                break;
            }
        case 2:
        {
            string id;
            string password;
            cout<<"Enter Userid:" <<endl;
            cin>>id;
            cout<<"Enter Password:" <<endl;
            cin>>password;
            graph.authenticateUser(id,password);
            break;


        }
        case 3:
        {
            string userID1,userID2;
            cout <<"Enter first Userid:" <<endl;
            cin>> userID1;
            cout <<"Enter second Userid:" <<endl;
            cin>>userID2;
            graph.follow(userID1,userID2);
            break;
        }
        case 4:
        {
            string userID1,userID2;
            cout <<"Enter first Userid:" <<endl;
            cin>> userID1;
            cout <<"Enter second Userid:" <<endl;
            cin>>userID2;
            graph.removeFriend(userID1,userID2);
            break;
        }
        case 5:
        {
            string userID1;
            cout<<"Enter User1:" <<endl;
            cin>>userID1;
            string userID2;
            cout<<"Enter User2:" <<endl;
            cin>>userID2;

            graph.mutualfriends(userID1,userID2);
            break;
        }
        case 6:
        {
            string userID;
            cout<<"Enter User:" <<endl;
            cin>>userID;
            graph.displayNode(userID);
            break;
        }
        case 7:
        {
            string userID;
            cout<<"Enter User:" <<endl;
            cin>>userID;
            graph.friendsuggestion(userID);
            break;
        }
        case 8:
        {
            graph.findInfluencers();
            break;
        }
        case 9:
        {
            graph.displayNodes();
            break;
        }
        case 10:
        {
            cout << "Exiting...." <<endl;
            return 0;
        }
        default:
        {
            cout << "Selected option does not exist!" <<endl;
            break;
        }
        }
    }
  

    return 0;
}
