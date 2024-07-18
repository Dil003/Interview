// OOP Game Project
// Dragon Game

// Main_game.cpp

// Include class header files
#include "Menu.h"
#include "Player.h"
#include "OrangeEGG.h"
#include "GreenEGG.h"
#include "Grid.h"
#include "Keyboard.h"
#include "BlueEGG.h"
#include "Dragon.h"
#include "RedEGG.h"

// Include all libraries
#include <string>
#include <iostream>
#include <fstream>

int main(){
    // Initializing player object
    Player p1;
    // User input, asking users name
    std::cout << "Please enter your name: ";
    std::string name;
    std::cin >> name;
    p1.set_name(name);
    std::ofstream data_log("data_log.txt", std::ios::app);
    data_log << "Player Object initialized" << std::endl;

    // Initialize game menu
    Menu menu;
    bool run_game = true;

    // Program run_game until quit game
    while (run_game != false){
        data_log << "Program Loop initiated" << std::endl;

        bool start_game = false;
        // Menu loops until game begins OR quit game
        while (start_game != true){
            data_log << "Main Menu Loop initiated" << std::endl;

            menu.set_choice(0);    // reinitialize choice
            menu.display_menu();
            switch(menu.get_choice()){
                case 1:          // moption to start_game the game
                    start_game = true;
                    break;

                case 2:          // option to display rules
                    std::cout << std::endl;
                    menu.display_rules();
                    break;

                case 3:          // option to quit 
                    std::cout << std::endl;
                    std::cout << "           See you again, " << p1.get_name() << std::endl;
                    return 0;
                    break;
                default:         // when unassigned key is pressed
                    std::cout << std::endl;
                    std::cout << "       Invalid choice please try again\n";
                    start_game = false;
                    break;
            }
        }
        data_log << "Main Menu Loop exited" << std::endl;

        bool play_again = true;  
        data_log << "Gameplay Loop initiated" << std::endl;
        while (play_again != false){
            Keyboard key; // keyboard object

            // Initilizing dimensions of a 20X20 grid to play the game on
            int rows = 20;
            int cols = 20;

            // Intializing temporary dragon score
            int temp_score, dragon_score = 0;

            // Random seed generator for game items including: dragon, gE, 
            srand(time(NULL));

            // Generating random coordinates for the following items: dragon, gE
            int dragon_x = rand() % (cols - 2) + 1;                      // dragon random x-coordinate
            int dragon_y = rand() % (rows - 2) + 1;                      // dragon random y-coordinate

            int oE_x = rand() % (cols - 2) + 1;                      // OrangeEGG random x- coordinate
            int oE_y = rand() % (rows - 2) + 1;                      // OrangeEGG random y-coordinate

            int gE_x = rand() % (rows - 2) + 1;                     // gE random x- coordinate
            int gE_y = rand() % (rows - 2) + 1;                     // gE random y-coordinate

            int bE_x = rand() % (rows - 2) + 1;                       // BlueEGG random x- coordinate
            int bE_y = rand() % (rows - 2) + 1;                       // BlueEGG random y-coordinate

            int rE_x = rand() % (rows - 2) + 1;                       // RedEGG random x- coordinate
            int rE_y = rand() % (rows - 2) + 1;                       // RedEGG random y-coordinate

            bool game_over = false;
            while(game_over != true){
                data_log << "Game-over Loop initialized" << std::endl;

                Dragon *dragon;                                            // pointer to dragon object
                dragon = new Dragon(dragon_x, dragon_y, 'D');                // create dynamic dragon object

                OrangeEGG *oE;                                         // pointer to OrangeEGG object
                oE = new OrangeEGG(oE_x, oE_y, 'O');             // create dynamic OrangeEGG object

                GreenEGG *gE;                                          // pointer to gE object
                gE = new GreenEGG(gE_x, gE_y, 'G');            // create dynamic gE object

                BlueEGG *bE;                                         // pointer to BlueEGG object
                bE = new BlueEGG(bE_x, bE_y, 'B');               // create dynamic BlueEGG object

                RedEGG *rE;                                         // pointer to RedEGG object
                rE = new RedEGG(rE_x, rE_y, 'R');               // create dynamic RedEGG object

                // Creating the grid
                Grid Grid(rows, cols);

                // Setting 'objects' on the grid: Dragon(W), OrangeEGG(b), GreenEGG(D), BlueEGG(T)
                Grid.set_dragon(dragon);
                Grid.set_oE(oE);
                Grid.set_gE(gE);
                Grid.set_bE(bE);
                Grid.set_rE(rE);

                // Displaying 'objects' on the grid: Dragon(W), OrangeEGG(b), GreenEGG(D), BlueEGG(T)
                Grid.print_game();

                if(key.kbhit()){  // if a key press is detected
                    switch(key.getch()){ // getting the chracter of the key being pressed

                    case 'a': dragon->set_dragon_x(dragon_x--);            // moving the dragon towards left
                    break;

                    case 'd': dragon->set_dragon_x(dragon_x++);            // moving the dragon towards right
                    break;

                    case 'w': dragon->set_dragon_y(dragon_y--);            // moving the dragon towards top
                    break;

                    case 's': dragon->set_dragon_y(dragon_y++);            // moving the dragon towards bottom
                    break;

                    case 'q': game_over = true;                         // quitting the game
                    break;

                    default:                                            // any case unspecified (not 'a', 'd', 'w', 's', 'q'),  
                    break;                                              // switch statement breaks and moves on
                    }

                    // Collision detection between the Dragon and the edge
                    // If the the dragon collides with edge, game over
                    if(dragon_x < 1 || dragon_x > cols - 2 || dragon_y < 1 || dragon_y > rows - 2){
                        game_over = true;
                    } 
                    
                    else if(dragon_x == rE_x && dragon_y == rE_y){
                    temp_score = p1.get_current_score();

                    if (temp_score >= 2){                            // if score is greater then or equal to 2 then subtract 2
                            dragon_score = temp_score - 2;                // subtracting 2 from the score
                        }
                        else{
                            dragon_score = 0;                             // else set score to 0 
                        
                        }                 
                        
                    // RedEGG relocation after collision
                        rE_x = rand() % (cols - 2) + 1;
                        rE_y = rand() % (rows - 2) + 1;

                    }

                    // Collision detection between the dragon and OrangeEGG
                    else if(dragon_x == oE_x && dragon_y == oE_y){
                        temp_score = p1.get_current_score();

                      if (temp_score >= 1){                            // if score is greater then or equal to 1 then subtract 1
                            dragon_score = temp_score - 1;                // subtracting 1 from the score
                        }
                        else{
                            dragon_score = 0;                             // else set score to 0 
                        
                        }                 
                        
                    // OrangeEGG relocation after collision
                        oE_x = rand() % (cols - 2) + 1;
                        oE_y = rand() % (rows - 2) + 1;

                    }

                    // Collision detection between the dragon and gE
                    else if(dragon_x == gE_x && dragon_y == gE_y){
                        temp_score = p1.get_current_score();                       
                        dragon_score = temp_score + 1;
                    

                    // GreenEGG relocation after collision
                        gE_x = rand() % (cols - 2) + 1;
                        gE_y = rand() % (rows - 2) + 1;

                    }

                    // Collision detection between the dragon and BlueEGG
                    else if(dragon_x == bE_x && dragon_y == bE_y){

                        temp_score = p1.get_current_score();
                        dragon_score = temp_score + 2;                      // adding +2 to the score

                    // BlueEGG relocation after collision
                        bE_x = rand() % (cols - 2) + 1;
                        bE_y = rand() % (rows - 2) + 1;

                    }

                    p1.set_current_score(dragon_score);
                }
                
                std::cout << "Score:" << p1.get_current_score() << std::endl; // current score
                std::cout << "Press 'q' to quit game" << std::endl;

                system("clear");
            }

            data_log << " The Gameover loop is exited" << std::endl;


            std::string message = "              *GAME OVER*\n";
            std::cout << std::endl << message << std::endl;

            // Display scores
            std::cout << "Current Score: " << p1.get_current_score() << std::endl; // players current score
            std::cout << "Previous High Score: " << p1.get_high_score() << std::endl; // players high score

            // Check for new high score & write new score to file
            p1.update_high_score();
            std::cout << std::endl;
            p1.update_score_file(p1.get_current_score());

            std::ofstream data_log("data_log.txt", std::ios::app);
            data_log << "Score File successfully updated" << std::endl;

            // Gameover menu loops until valid entry
            bool valid = false;
            while (valid != true){
                data_log << "Gameover Menu initiated" << std::endl;

                menu.set_choice(0); // reinitialize choice
                menu.display_game_over();

                switch(menu.get_choice()){
                    case 0: // if the user doesnt enter 1,2,3
                        std::cout << std::endl;
                        std::cout << "       Invalid choice please try again\n";
                        break;
                    case 1: // play again
                        valid = true;
                        break;
                    case 2: // return to main menu
                        play_again = false;
                        valid = true;
                        break;
                    case 3: // quit the game
                        valid = true;
                        play_again = false;
                        run_game = false;
                        break;

                    default:
                    break;
                }
            }

            data_log << "Gameover Menu exited" << std::endl;
        }

        data_log << "Gameplay Loop exited" << std::endl;
    }

    data_log << "Program Loop exited" << std::endl;

    std::cout << std::endl;
    std::cout << "           See you again, " << p1.get_name() << " Thank you for playing! " << std::endl;
    data_log << "Program terminated" << std::endl;
    data_log.close();

    return 0;
}
