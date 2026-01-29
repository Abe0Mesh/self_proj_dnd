//my dnd text base game project
//I hope this will help me practice my cpp skills and oop

#include <iostream>
#include <string>
#include <functional>

// enum works to essentaily name a value, so all in the enum
//are ints (hover over) so barbarian is 1... etc
enum class class_type {
    barbarian = 1,
    bard,
    cleric,
    druid,
    fighter,
    monk, 
    paladin,
    ranger, 
    rogue,  
    sorcerer, 
    warlock, 
    wizard
};

enum class race_type {
    aasimar = 1,
    dragonorn,
    dwarf,
    elf,
    gnome,
    goliath,
    halfing,
    human,
    orc,
    tiefling

};

struct stats {
    int strength;
    int dexterity;
    int constitution;
    int intelligence;
    int wisdom;
    int charisma;
};
 

struct player: public stats {
    
    class_type player_c;
    race_type player_r;

    player() {
        player_r = race_type::human;
        player_c = class_type::barbarian;
        strength = 0;
        dexterity = 0;
        constitution = 0;
        intelligence = 0;
        wisdom = 0;
        charisma = 0;

    }
    player(class_type typec, race_type typer, int s, int d, int c, int i, int w, int ch) { 

        player_c = typec;
        player_r = typer;
        strength = s;
        dexterity = d;
        constitution = c;
        intelligence = i;
        wisdom = w;
        charisma = ch;

    }


};

//The reason I decided to make user type int to choose class instead of 
// string style is because its harder to control string cin insertions lol
//also in the future I want to turn this into a program that executes and 
//displays pretty text and allows user to click instead of having to type everything.
void race_menu() {
    std::cout << 
                    "1:  Aasimar\n"
                    "2:  Dragonorn\n"
                    "3:  Dwarf\n"
                    "4:  Elf\n"
                    "5:  Gnome\n"
                    "6:  Goliath\n"
                    "7:  Halfing\n"
                    "8:  Human\n"
                    "9:  Orc\n"
                    "10: Tiefling\n";
                }

void class_menu() {
    std::cout << 
                    "1:  Barbarian\n"
                    "2:  Bard\n"
                    "3:  Cleric\n"
                    "4:  Druid\n"
                    "5:  Fighter\n"
                    "6:  Monk\n"
                    "7:  Paladin\n"
                    "8:  Ranger\n"
                    "9:  Rogue\n"
                    "10: Sorcerer\n"
                    "11: Warlock\n"
                    "12: Wizard\n";         
                }




void narrate(const std::string& text) {
    std::cout << "[Narration] " << text << '\n';
}

void speak(const std::string& speaker, const std::string& text) {
    std::cout << "[" << speaker << "] " << text << '\n';
}



int infoInput (std::string classOrRace, std::function<void()> printSelection ) { //replace class stuff into a single func to use for both class n race
    int choice{-1};
    while (true) {
        std::cout << "Select a " << classOrRace << " by typing in the coresponding number\n";
        printSelection();
       
        std::cin >> choice;

        if(choice >=1 && choice <=12) {
            std::cout << "Do you confirm " << choice << " is your " + classOrRace + " of choice?\n";
            char confirm_choice;
            std::cout << "Please Select (Y/N): "; //wording could be better may confuse user.
            std::cin >> confirm_choice;
                if(confirm_choice == 'y' || confirm_choice == 'Y') { return choice;}
                continue; //continue here to send user back to select to reselct class
            
        }
        else if (choice <=0 || choice >=13) {
            std::cout << "Invalid Choice, please select again\n\n";
            
        }
    }
}


void game_start () {

    narrate("You swing open the door, stubbling into the adventurers guild");
    narrate ("Looking around you notice the piercing glares throughout the room\n");

    speak("Guild Clerk", "Welcome in, I dont think I've ever seen your face before");
    speak("Guild Clerk", "Are you here to join the guild?\n");

    narrate("You nervously nod your head,");
    narrate("still feeling the piercing precence of the others\n");

    speak("Guild Clerk", "Alright then, what your name then");
    std::string player_name;
    std::getline(std::cin, player_name);
    speak("Guild Clerk", "Nice to meet you " + player_name + "!"); //using concatination within the function call, pretty cool lol
    speak("Guild Clerk", "What is your class " + player_name + "? \n");
    
    // int class_choice{-1};
    // while (true) {
    //     std::cout << "Select a class by typing in the coresponding number\n";
    //     class_menu();
       
    //     std::cin >> class_choice;

    //     if(class_choice >=1 && class_choice <=12) {
    //         std::cout << "Do you confirm " << class_choice << " is your class of choice?\n";
    //         char choice;
    //         std::cout << "Please Select (Y/N): "; //wording could be better may confuse user.
    //         std::cin >> choice;
    //             if(choice == 'y' || choice == 'Y') { break;}
    //             continue; //continue here to send user back to select to reselct class
            
    //     }
    //     else if (class_choice <=0 || class_choice >=13) {
    //         std::cout << "Invalid Choice, please select again\n\n";
            
    //     }
    // }

    int class_choice = infoInput("class", class_menu);

    
    class_type player_class; //calling enum, when I make my player class call I will use this as first param
    

    switch (class_choice) {
        case 1: 
            std::cout << "You choose the Barbarian class\n\n";
            player_class = class_type::barbarian; 
            break;
        case 2:            
            std::cout << "You choose the Bard class\n\n";
            player_class = class_type::bard;
            break;
        case 3: 
            std::cout << "You choose the Cleric class\n\n";
            player_class = class_type::cleric;
            break;
        case 4: 
            std::cout << "You choose the Druid class\n\n";
            player_class = class_type::druid;
            break;
        case 5: 
            std::cout << "You choose the Fighter class\n\n";
            player_class = class_type::fighter;
            break;
        case 6: 
            std::cout << "You choose the Monk class\n\n";
            player_class = class_type::monk;
            break;
        case 7: 
            std::cout << "You choose the Paladin class\n\n";
            player_class = class_type::paladin;
            break;
        case 8: 
            std::cout << "You choose the Ranger class\n\n";
            player_class = class_type::ranger;
            break;
        case 9: 
            std::cout << "You choose the Rogue class\n\n";
            player_class = class_type::rogue;
            break;
        case 10: 
            std::cout << "You choose the Sorcerer class\n\n";
            player_class = class_type::sorcerer;
            break;
        case 11: 
            std::cout << "You choose the Warlock class\n\n";
            player_class = class_type::warlock;
            break;
        case 12:
            std::cout << "You choose the Wizard class\n\n";
            player_class = class_type::wizard;
            break;
    }


    speak("Guild Clerk", "What race are you " + player_name + "? \n");

    







 
   speak("Guild Clerk", "Please put your hand on the crystal ball\n");

   narrate("Infront of you shines a crystal ball, after placing your hand on the ball it begins to glow a deep purple");
   narrate("You can feel the energy coursing through your body, through your arm into the crystal ball");
   narrate("Smoke begins to accumalte around the ball, then out of the smoke a mysterous figure appears\n");

   speak("???", "how do you wish to choose your stats...");

   //add some sort of function or something to let player assing stats using DnD style point assingment

   //to do next is that I forgot to add race, so I gotta go back and copy what I do for classes and let the user pick there race 
   //as each race has different begginign stats so gotta make sure those are ready before regular stat selection. 









}








int main() {


game_start();

return 0;
}
