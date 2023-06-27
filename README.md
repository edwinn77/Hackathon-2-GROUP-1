# Hackathon2 Group 1

#Members :
> Edwin Chia Yi Yang \\
> Eng Jun Xiang \\
> Goh Jia Wei \\


---


#Project Title: University Life: The Parallel Journey

##Description of game:
University Life: The Parallel Journey is an immersive role-playing text-based game set in a parallel time space. As a student at Universiti Sains Malaysia (USM), your mission is to navigate the challenges of university life and escape this unfamiliar reality untill you have graduate. Embark on a thrilling adventure as you immerse yourself in the world of USM, tackling five unique mini-games that represent various aspects of student life.

Your success in these mini-games will determine your future path, with the goal of passing at least four of them. Along the way, you'll uncover hidden secrets, solve puzzles, and make choices that shape the storyline. The fate of your character and the truth behind this parallel universe rest in your hands.

Will you unravel the mysteries and find your way back home, or will you remain trapped forever in this alternate reality? The answers lie within the immersive and captivating gameplay of University Life: The Parallel Journey. Embrace the role of a USM student, test your determination, and embark on an unforgettable adventure today!

##Problem Analysis

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

##Features of game

---
Start a New Game: Begin a fresh adventure in the parallel universe of University Life: The Parallel Journey. Create a character, graduate from USM, and escape the mysterious reality. Experience challenges, puzzles, and choices in this captivating text-based adventure.

Save and Exit: Save your progress and exit the game at any time. Preserve your accomplishments, choices, and current state to continue later.

Restore and Continue: Seamlessly jump back into the game from where you left off. Pick up your character's journey, re-engage with the storyline, and continue making impactful choices.

Engaging Mini-Games: Experience five unique mini-games that represent different aspects of university life, including solving puzzles and engaging in academic challenges.

Graduation Path: Your objective is to graduate from USM and escape the parallel reality. Your performance in the mini-games will determine the outcome and the path your character takes upon graduation.

Choices and Consequences: Make decisions that shape the storyline and have far-reaching consequences. Your choices can influence the overall outcome of the game.

Atmospheric Descriptions: Engage your senses with vivid and detailed descriptions of the environments, characters, and events that bring the parallel universe to life.

Replayability: With multiple mini-games, branching paths, and different endings, the game offers high replay value, encouraging players to explore various strategies and outcomes.

##Rules and regulation of game

---
At the beginning, you have the option to start a new game or continue from your previous progress. Our game features five separate mini-games, and you can choose which game to enter. To fulfill the credit requirement and graduate from the university, you need to successfully complete **at least four** of these games.

After complete one round of the mini-game, you have the choice to continue playing and move on to another game or save your progress and exit the game.

Each mini-game has its own unique rules, which will be explained separately along with instructions on how to play:

**1. Tic Tac Toe**

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


**2. Connect4**

Rules:

Connect Four is played on a grid consisting of six rows and seven columns.
Two players participate, usually referred to as Player 1 and Player 2 which is an AI player.
Players take turns dropping their colored discs into any column of the grid.
The discs fall to the lowest available position within the chosen column.
The objective is to be the first player to form a horizontal, vertical, or diagonal line of four discs of their color.
The game ends immediately when a player successfully connects four discs or when the grid is completely filled without a winner, resulting in a draw.

Instructions:

The game starts with an empty grid of six rows and seven columns.
![image.png](data:image/png;base64,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)

Player 1 begins the game and selects a column to drop their colored disc.
Enter the corresponding number or letter of the chosen column to place the disc.
The disc will fall to the lowest unoccupied position within the selected column.
AI player takes it's turn and drops the disc into a different column.
Players continue alternating turns, strategically placing their discs into the columns.
The game will check for a winning line after each move to determine if a player has connected four discs.
If a player successfully connects four discs horizontally, vertically, or diagonally, they win the game.
If all columns are filled and no player has connected four discs, the game ends in a draw.

**3. Number Guessing**

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

**4. Sudoku**

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

**5. Mini Math Game**

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

##Object-oriented concept used in develop the game

---
In our game, the implementation of five classes for our five mini-games exemplifies the effective utilization of object-oriented programming concepts. This approach enables the development of a well-structured and maintainable codebase while promoting modularity, reusability, code organization, readability, encapsulation, and abstraction.

By encapsulating each mini-game within a dedicated class, we achieve encapsulation and encapsulation allows us to hide the internal details of each mini-game and expose only the necessary functionality through public member functions. This ensures that the private variables of each class can only be accessed and modified in a controlled manner, preventing unintended modifications and maintaining data integrity.

Moreover, the use of objects and classes fosters modularity and code reusability. Each mini-game is encapsulated as an object, allowing us to treat them as independent entities with their own specific behaviors and attributes. This modularity facilitates the addition of new mini-games or modifications to existing ones without affecting the entire codebase. It also enables code reuse, as the same class can be instantiated multiple times to create instances of different mini-games, reducing duplication and improving efficiency.

Object-oriented programming promotes a structured approach to code organization, making the codebase more manageable and readable. The separation of concerns into distinct classes allows developers to focus on specific functionalities, leading to cleaner and more understandable code. Furthermore, the use of classes and objects enhances collaboration among developers. Each developer can work on a specific mini-game by utilizing the shared main function, facilitating parallel development and efficient debugging of individual tasks.

Additionally, object-oriented programming embraces the concept of abstraction, enabling us to define essential characteristics and behaviors of game objects while hiding unnecessary implementation details. This abstraction simplifies the understanding and usage of the game components, making the overall codebase more intuitive and easier to work with.

By incorporating these object-oriented programming principles into our game development, we have established a robust foundation for managing complexity, promoting code reuse, ensuring data integrity, and facilitating collaboration among developers.

##How linked lists plays a role in the game

---
A linked list is used to manage the game objects in the gameList variable. The linked list data structure allows for dynamic storage and efficient manipulation of the game objects.

The linked list is implemented using a custom LinkedList class, which contains a nested ListNode class representing each node in the list. Each node holds a game object as its value and a pointer to the next node in the list.

Here's a breakdown of how linked lists play a role in the game:

Creating and Appending Game Objects:

Game objects, such as Tic Tac Toe, Connect 4, Guess the Number, Math Game, and Sudoku Game, are created using the Game class constructor.
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

###**Main Menu**
![image.png](data:image/png;base64,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)
