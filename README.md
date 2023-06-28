# Hackathon2 Group 1

# Members :
> Edwin Chia Yi Yang
> 
> Eng Jun Xiang
> 
> Goh Jia Wei
> 
![Blue Brown Modern Meet Our Team Introduction Instagram Post](https://github.com/edwinn77/Hackathon-2-Group-1/assets/117069930/1c59199f-c25c-48a7-9ab9-f4830c10997c)


---


# Project Title: University Life: The Parallel Journey

## Description of game:
`University Life: The Parallel Journey` is an immersive role-playing text-based game set in a parallel time space. As a student at Universiti Sains Malaysia (USM), your mission is to navigate the challenges of university life and escape this unfamiliar reality untill you have graduate. Embark on a thrilling adventure as you immerse yourself in the world of USM, tackling five unique mini-games that represent various aspects of student life.

Your success in these mini-games will determine your future path, with the goal of passing at least four of them. Along the way, you'll uncover hidden secrets, solve puzzles, and make choices that shape the storyline. The fate of your character and the truth behind this parallel universe rest in your hands.

Will you unravel the mysteries and find your way back home, or will you remain trapped forever in this alternate reality? The answers lie within the immersive and captivating gameplay of University Life: The Parallel Journey. Embrace the role of a USM student, test your determination, and embark on an unforgettable adventure today!

## Problem Analysis

---
The task is to develop a text-based video game in C++ that showcases expertise in class and multiple class processing with relationships. The game should be engaging and elaborate, incorporating linked lists or their variations (stacks or queues) as a core component for efficient functionality.

To achieve this, we need to analyze the problem and identify the key requirements of the software solution. The main concept of our game involves five mini-games: 
1. Tic Tac Toe
2. Connect4
3. Number Guessing
4. Sudoku
5. Mini Math Game

These games, along with their corresponding storylines, create a role-playing experience that immerses the player.

The program should be built with a modular and scalable architecture, allowing for easy expansion and user-friendly input handling. It should provide clear instruction guidance, enforce rules and regulations, and deliver informative outputs. Proficiency in class relationships and linked list utilization will be crucial for efficient game mechanics and optimal performance.

By meeting these requirements, the resulting text-based game will demonstrate mastery of class processing, showcase effective use of linked lists, and offer an immersive role-playing experience for the players.

## Features of game

---
Start a New Game: Begin a fresh adventure in the parallel universe of University Life: The Parallel Journey. Create a character, graduate from USM, and escape the mysterious reality. Experience challenges, puzzles, and choices in this captivating text-based adventure.

Save and Exit: Save your progress and exit the game at any time. Preserve your accomplishments, choices, and current state to continue later.

Restore and Continue: Seamlessly jump back into the game from where you left off. Pick up your character's journey, re-engage with the storyline, and continue making impactful choices.

Engaging Mini-Games: Experience five unique mini-games that represent different aspects of university life, including solving puzzles and engaging in academic challenges.

Graduation Path: Your objective is to graduate from USM and escape the parallel reality. Your performance in the mini-games will determine the outcome and the path your character takes upon graduation.

Choices and Consequences: Make decisions that shape the storyline and have far-reaching consequences. Your choices can influence the overall outcome of the game.

Atmospheric Descriptions: Engage your senses with vivid and detailed descriptions of the environments, characters, and events that bring the parallel universe to life.

Replayability: With multiple mini-games, branching paths, and different endings, the game offers high replay value, encouraging players to explore various strategies and outcomes.

## Rules and regulation of game

---
At the beginning, you have the option to start a new game or continue from your previous progress. Our game features five separate mini-games, and you can choose which game to enter. To fulfill the credit requirement and graduate from the university, you need to successfully complete **at least four** of these games.

After complete one round of the mini-game, you have the choice to continue playing and move on to another game or save your progress and exit the game.

Each mini-game has its own unique rules, which will be explained separately along with instructions on how to play:

`**1. Tic Tac Toe**`

Rules:

The game is played on a 3x3 grid.
Two players participate, typically referred to as "X" and "O".
Players take turns placing their symbol on an empty cell of the grid.
The first player to achieve a line of three of their symbols wins the game.
If all cells are filled and no player has formed a line, the game is declared a draw.

Instructions:

The player can choose the mode of the game: Easy/Hard.
The game starts with an empty grid of 3x3 cells.
the player should key in the respective coordinate to place their symbol on an empty cell of their choice. the coordinate is shown below:

  1  |  2  |  3
-------------
  4  |  5  |  6
-------------
  7  |  8  |  9
-------------

The AI player will takes their turn and places the symbol.


`**2. Connect4**`

Rules:

Connect Four is played on a grid consisting of six rows and seven columns.
Two players participate, usually referred to as Player 1 and Player 2 which is an AI player.
Players take turns dropping their colored discs into any column of the grid.
The discs fall to the lowest available position within the chosen column.
The objective is to be the first player to form a horizontal, vertical, or diagonal line of four discs of their color.
The game ends immediately when a player successfully connects four discs or when the grid is completely filled without a winner, resulting in a draw.

Instructions:

The game starts with an empty grid of six rows and seven columns.

![Screenshot 2023-06-25 135916](https://github.com/edwinn77/Hackathon-2-Group-1/assets/116961771/1842d66d-8492-4754-8077-d5527614c61d)

Player 1 begins the game and selects a column to drop their colored disc.
Enter the corresponding number or letter of the chosen column to place the disc.
The disc will fall to the lowest unoccupied position within the selected column.
AI player takes it's turn and drops the disc into a different column.
Players continue alternating turns, strategically placing their discs into the columns.
The game will check for a winning line after each move to determine if a player has connected four discs.
If a player successfully connects four discs horizontally, vertically, or diagonally, they win the game.
If all columns are filled and no player has connected four discs, the game ends in a draw.

`**3. Number Guessing**`

Rules:

The player's objective is to guess a randomly generated number within a given range.
The range of numbers is from 0 to 100.
The player has a total of two chances to guess the correct number without penalty.
Each guess will be recorded and displayed as a previous guess.
If the player guesses the correct number within the allowed chances, they win the game.
If the player fails to guess the correct number within the allowed chances, they lose the game.

Instructions:

The game begins with a prompt to guess a number within the range of 0 to 100.
The player should enter their guess when prompted.
After each guess, the game will provide feedback to help the player adjust their subsequent guesses.
If the guess is too low, the game will display "Too low! Try again."
If the guess is too high, the game will display "Too high! Try again."
If the guess is correct, the game will display "Congratulations! You guessed the number correctly."
The player's previous guesses will be displayed after each guess, helping them keep track of their progress.
The player has a maximum of two chances to guess the correct number without penalty.
If the player fails to guess the correct number within the allowed chances, their score will be calculated based on the number of guesses made.
For each additional guess beyond the allowed chances, the player's score will be deducted by 10%.

`**4. Sudoku**`

Rules:

The Sudoku board consists of a 5x5 grid divided into 5 smaller 2x2 blocks.
The objective of the game is to fill in the numbers from 1 to 5 in each row, column, and block without repetition.
Initially, some numbers are already filled on the board, and you need to fill in the remaining empty cells.
Each row, column, and block must contain all numbers from 1 to 5 without repetition.

Instructions:

Fill in the numbers from 1 to 5 in each row, column, and block.
You will receive a penalty for each invalid move you make.
Each penalty deducts 10% from your score.
The game ends when you successfully fill in all the empty cells or when you reach the maximum number of penalties.
Your goal is to achieve a score of 70% or higher to pass the game.
You have a total of 3 chances to pass the game.

`**5. Mini Math Game**`

Rules:

The Math Game is a timed quiz consisting of math questions.
You will be asked a total of 5 questions.
Each question will have two randomly generated numbers between 1 and 50.
The numbers will be operated upon using one of the following operations: addition (+), subtraction (-), or multiplication (*).
You will have 10 seconds to answer each question.
For each correct answer, you will earn 10 points.
If you take longer than the time limit to answer a question, you will receive no points for that question.
Your final score will be calculated based on the total number of correct answers.

Instructions:

You will have 10 seconds to answer each question.
Answer each question by entering the result of the math operation.
The answer sgiuld be entered in 10 seconds.
If your answer is correct, you will earn 10 points.
If your answer is incorrect, the correct answer will be displayed.
The game will keep track of your score as you progress.

## Object-oriented concept used in develop the game

---
In our game, the implementation of five classes for our five mini-games exemplifies the effective utilization of object-oriented programming concepts. This approach enables the development of a well-structured and maintainable codebase while promoting modularity, reusability, code organization, readability, encapsulation, and abstraction.

By encapsulating each mini-game within a dedicated class, we achieve encapsulation and encapsulation allows us to hide the internal details of each mini-game and expose only the necessary functionality through public member functions. This ensures that the private variables of each class can only be accessed and modified in a controlled manner, preventing unintended modifications and maintaining data integrity.

Moreover, the use of objects and classes fosters modularity and code reusability. Each mini-game is encapsulated as an object, allowing us to treat them as independent entities with their own specific behaviors and attributes. This modularity facilitates the addition of new mini-games or modifications to existing ones without affecting the entire codebase. It also enables code reuse, as the same class can be instantiated multiple times to create instances of different mini-games, reducing duplication and improving efficiency.

Object-oriented programming promotes a structured approach to code organization, making the codebase more manageable and readable. The separation of concerns into distinct classes allows developers to focus on specific functionalities, leading to cleaner and more understandable code. Furthermore, the use of classes and objects enhances collaboration among developers. Each developer can work on a specific mini-game by utilizing the shared main function, facilitating parallel development and efficient debugging of individual tasks.

Additionally, object-oriented programming embraces the concept of abstraction, enabling us to define essential characteristics and behaviors of game objects while hiding unnecessary implementation details. This abstraction simplifies the understanding and usage of the game components, making the overall codebase more intuitive and easier to work with.

By incorporating these object-oriented programming principles into our game development, we have established a robust foundation for managing complexity, promoting code reuse, ensuring data integrity, and facilitating collaboration among developers.

## How linked lists plays a role in the game

---
A linked list is used to manage the game objects in the gameList variable. The linked list data structure allows for dynamic storage and efficient manipulation of the game objects.

The linked list is implemented using a custom LinkedList class, which contains a nested ListNode class representing each node in the list. Each node holds a game object as its value and a pointer to the next node in the list.

Here's a breakdown of how linked lists play a role in the game:

Creating and Appending Game Objects:

Game objects, such as `Tic Tac Toe`, `Connect 4`, `Guess the Number`, `Math Game`, and `Sudoku Game`, are created using the Game class constructor.
These game objects are then appended to the gameList linked list using the appendNode() method of the LinkedList class. We use a function pointer that points to different functions, each corresponding to a different game. This allows us to pass the appropriate play function as a parameter when appending a game to the linked list, even though the game objects themselves have different classes. This method creates a new node containing the game object and adds it to the end of the list.

Accessing and Manipulating Game Objects:

The gameList linked list allows accessing and manipulating individual game objects.
The head pointer of the linked list points to the first node in the list.
To iterate over the list and access each game object, a nodePtr pointer is used and initialized with the head pointer.
Various methods of the Game class, such as getPos(), getCredit(), getGPA(), setCredit(), and setGPA(), are called on the game objects through the nodePtr.
For example, the code reads the initial credit and GPA values from a file and updates the corresponding game objects using the setCredit() and setGPA() methods.
The linked list provides an efficient way to traverse and modify game objects without the need to search through an array or other data structures.

Displaying and Playing Games:

The linked list allows displaying and playing games based on user input.
The displayList() method of the LinkedList class is called to display the list of available games.
User input is used to select a game by its position (pos) within the list.
The playGame() method of the Game class is called on the selected game object, which triggers the execution of the corresponding game's play function.
The play function modifies the game object's private member variables (credit and GPA) based on the game's logic.
After playing a game, the updated game object's credit and GPA values are stored back into the linked list using the setCredit() and setGPA() methods.

Storing and Retrieving Game Progress:

The linked list allows storing and retrieving game progress.
The game progress is stored in a file named "Copy.txt".
The ofstream object is used to open the file for writing, and the linked list is traversed to retrieve each game object's credit and GPA values, which are then written to the file.
Similarly, the ifstream object is used to open the file for reading, and the stored credit and GPA values are retrieved and assigned back to the corresponding game objects in the linked list.

Overall, the linked list data structure provides a flexible and efficient way to manage the game objects, allowing for easy traversal, modification, and storage/retrieval of game progress. It enables the game to handle an arbitrary number of games and provides a dynamic structure to accommodate changes during runtime.

### **Main Menu**
![Screenshot 2023-06-27 091543](https://github.com/edwinn77/Hackathon-2-Group-1/assets/116961771/b5a04789-5efb-4dd8-8794-45a9632e1cba)


### **Choose which action would like to take**
![Screenshot 2023-06-27 091654](https://github.com/edwinn77/Hackathon-2-Group-1/assets/116961771/528bc9d4-04f6-45b0-ab67-8288b4ab2d7d)


### **Choose which mini game to play**
![Screenshot 2023-06-27 091911](https://github.com/edwinn77/Hackathon-2-Group-1/assets/116961771/fde0998f-a8b5-4418-918a-87fb0ae4e596)


### **Tic Tac Toe**
![Screenshot 2023-06-27 092131](https://github.com/edwinn77/Hackathon-2-Group-1/assets/116961771/9be0e8d0-d8ae-4117-8a07-1d6a6747ba55)
![Screenshot 2023-06-27 092307](https://github.com/edwinn77/Hackathon-2-Group-1/assets/116961771/4ac97b2d-ed2d-42b8-a977-dad160e35ff7)
![Screenshot 2023-06-27 092410](https://github.com/edwinn77/Hackathon-2-Group-1/assets/116961771/61df649e-9fa4-412a-8970-1f9b72d2f6aa)
![Screenshot 2023-06-27 092449](https://github.com/edwinn77/Hackathon-2-Group-1/assets/116961771/ecb17728-a8ab-465d-afef-67fc47af80a0)


### **Connect4**
![Screenshot 2023-06-27 092608](https://github.com/edwinn77/Hackathon-2-Group-1/assets/116961771/d266b443-646e-4bfb-a20a-5a3c8b042e43)
![Screenshot 2023-06-27 092647](https://github.com/edwinn77/Hackathon-2-Group-1/assets/116961771/4b16177d-4f84-4d9f-b783-972a059924bb)
![Screenshot 2023-06-27 092712](https://github.com/edwinn77/Hackathon-2-Group-1/assets/116961771/1706adf5-902c-4697-888e-73bbd310c556)
![Screenshot 2023-06-27 092903](https://github.com/edwinn77/Hackathon-2-Group-1/assets/116961771/4ad8f874-6bbc-45b0-b12a-6626436b60dc)


### **Number Guessing**
![Screenshot 2023-06-27 093217](https://github.com/edwinn77/Hackathon-2-Group-1/assets/116961771/9edb744c-4d20-4ec3-8dc2-1708c1b04d61)
![Screenshot 2023-06-27 093248](https://github.com/edwinn77/Hackathon-2-Group-1/assets/116961771/d88960a8-9ab6-486b-a371-ed840d6e4934)
![Screenshot 2023-06-27 093328](https://github.com/edwinn77/Hackathon-2-Group-1/assets/116961771/23753ab7-bd53-48fd-8e09-2adbf9ae5a82)
![Screenshot 2023-06-27 093341](https://github.com/edwinn77/Hackathon-2-Group-1/assets/116961771/2a8ca1c6-fef2-458e-b2a8-dad17e6d1853)
![Screenshot 2023-06-27 093357](https://github.com/edwinn77/Hackathon-2-Group-1/assets/116961771/a8b56740-710f-45b5-9024-8a4012c7188f)


### **Mini Math Calculation**
![Screenshot 2023-06-27 093640](https://github.com/edwinn77/Hackathon-2-Group-1/assets/116961771/fdc850bf-263d-4073-8c89-eb5ad04aa604)
![Screenshot 2023-06-27 093730](https://github.com/edwinn77/Hackathon-2-Group-1/assets/116961771/6ec1777e-3a9f-43c4-ac89-a5fec0452c2e)


### **Sudoku**
![Screenshot 2023-06-27 093957](https://github.com/edwinn77/Hackathon-2-Group-1/assets/116961771/c93c63b0-6dbf-4204-8d0b-bff72d4e6823)
![Screenshot 2023-06-27 094203](https://github.com/edwinn77/Hackathon-2-Group-1/assets/116961771/80395db9-413a-4437-82af-4c6972144bdf)
![Screenshot 2023-06-27 094305](https://github.com/edwinn77/Hackathon-2-Group-1/assets/116961771/5fa3a044-3c84-41d0-8532-3f980c9b796f)
![Screenshot 2023-06-27 094511](https://github.com/edwinn77/Hackathon-2-Group-1/assets/116961771/290e40ee-1ec1-4a8c-8cd2-4c561bb792aa)
![Screenshot 2023-06-27 095325](https://github.com/edwinn77/Hackathon-2-Group-1/assets/116961771/b477a2a7-3156-4a17-8196-6657df127b31)
![Screenshot 2023-06-27 095356](https://github.com/edwinn77/Hackathon-2-Group-1/assets/116961771/35483c60-df18-473d-88c0-e640772ff108)
![Screenshot 2023-06-27 095420](https://github.com/edwinn77/Hackathon-2-Group-1/assets/116961771/637bd5bf-b2c7-4725-9f7b-8c8860ce1725)
![Screenshot 2023-06-27 095436](https://github.com/edwinn77/Hackathon-2-Group-1/assets/116961771/e572ca9f-3727-4b1d-a0d7-3618108941d3)


### **Show result (Pass less than 4 mini game)**
![Screenshot 2023-06-27 095727](https://github.com/edwinn77/Hackathon-2-Group-1/assets/116961771/ca495a9a-e00f-4204-a53d-d3de4cb2074e)


### **Show result (Won 4 mini game or above as well as won the game)**
![Screenshot 2023-06-27 100010](https://github.com/edwinn77/Hackathon-2-Group-1/assets/116961771/94784236-0619-420e-8ea6-28828862bd21)
![Screenshot 2023-06-27 100055](https://github.com/edwinn77/Hackathon-2-Group-1/assets/116961771/6b3430ad-c8bc-4bef-8118-17269bae418e)


## Link of game demo video: [Group_1 Demo Video](https://youtu.be/wzFANjqGJAo)
