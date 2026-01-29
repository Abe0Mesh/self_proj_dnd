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

 

struct character: public stats {
    
    std::string name;
    class_type character_c;
    race_type character_r;

    character() {
        name = "Unnamed";
        character_r = race_type::human;
        character_c = class_type::barbarian;
        strength = 0;
        dexterity = 0;
        constitution = 0;
        intelligence = 0;
        wisdom = 0;
        charisma = 0;

    }
    character(std::string n, class_type typec, race_type typer, int s, int d, int c, int i, int w, int ch) { 
        name = n;
        character_c = typec;
        character_r = typer;
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

std::array<std::string, 6> arr_stats {
    "Strength\n",
    "Dexterity\n",
    "Constitution\n",
    "Intelligence\n",
    "Wisdom\n",
    "Charisma\n"
};

void stat_menu() {
    std::cout << 
        "1:  Strength\n"
        "2:  Dexterity\n"
        "3:  Constitution\n"
        "4:  Intelligence\n"
        "5:  Wisdom\n"
        "6:  Charisma\n";
}


std::array<std::string, 10> arr_races {
    "Aasimar",
    "Dragonorn",
    "Dwarf",
    "Elf",
    "Gnome",
    "Goliath",
    "Halfing",
    "Human",
    "Orc",
    "Tiefling"


};

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

std::array<std::string, 12> arr_classes{
    "Barbarian",
    "Bard",
    "Cleric",
    "Druid",
    "Fighter",
    "Monk",
    "Paladin",
    "Ranger",
    "Rogue",
    "Sorcerer",
    "Warlock",
    "Wizard"   
};
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



int infoInput (std::string classOrRace, std::function<void()> printSelection, int max ) { //replace class stuff into a single func to use for both class n race
    int choice{-1};
    while (true) {
        std::cout << "Select a " << classOrRace << " by typing in the coresponding number\n";
        printSelection();
       
        std::cin >> choice;
        

        if(choice >=1 && choice <=max) {
            std::cout << "Do you confirm " << choice << " is your " + classOrRace + " of choice?\n";
            char confirm_choice;
            std::cout << "Please Select (Y/N): "; //wording could be better may confuse user.
            std::cin >> confirm_choice;
                if(confirm_choice == 'y' || confirm_choice == 'Y') { return choice;}
                continue; //continue here to send user back to select to reselct class
            
        }
        else if (choice <=0 || choice >max) {
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
    
    int class_choice = infoInput("class", class_menu, 12);

    class_type player_class = static_cast<class_type>(class_choice);
    std::string class_choice_string = arr_classes.at(class_choice - 1); // doing - 1 because user input is 1 based while my arrays are 0 based
    std::cout << "\nYou choose the " << class_choice_string << " class!\n" << std::endl; //flushing cuz cout not connected to anything and important user sees this 


    speak("Guild Clerk", "What race are you " + player_name + "? \n");
    int race_choice = infoInput("race", race_menu, 10);
    race_type player_race = static_cast<race_type>(race_choice);
    std::string race_choice_string = arr_races.at(race_choice - 1); // doing - 1 because user input is 1 based while my arrays are 0 based
    std::cout << "\nYou choose the " << race_choice_string << " race!\n" << std::endl; //flushing cuz cout not connected to anything and important user sees this 
    
    



 
   speak("Guild Clerk", "Please put your hand on the crystal ball\n");

   narrate("Infront of you shines a crystal ball, after placing your hand on the ball it begins to glow a deep purple");
   narrate("You can feel the energy coursing through your body, through your arm into the crystal ball");
   narrate("Smoke begins to accumulate around the ball, then out of the smoke a mysterous figure appears\n");

   speak("???", "how do you wish to choose your stats...");

   std::array<int,6> stat_points { 15, 14, 13, 12, 10, 8};
   std::array<int, 6> stat_builder {0, 0, 0, 0, 0, 0};
    //so a loop that runs through this vector, but also checks if the stat is greater then 0 meaning it already has stats applied to it
    //also checks if choosen int is within range given in menu
    //inside loop makes user choose again if they choose a invalid menu choice or repeated one
 
    for (int i = 0; i < stat_points.size(); i++) {
        bool valid_choice = false;
        while (!valid_choice) {
            std::cout <<"What stat would you like to assign " << stat_points.at(i) << " points to?" << std::endl;
            stat_menu();
            int choosen_stat;
            std::cin >> choosen_stat;
        
            if (choosen_stat > 6 || choosen_stat <= 0) { 
                std::cout << "Invalid choice, please choose a number 1-6\n";
                
                
            }
            else if (stat_builder.at(choosen_stat-1) != 0) {
                std::cout << "Already assigned a stat to this\n";
            }
            else {
                stat_builder.at(choosen_stat-1) = stat_points.at(i);
                valid_choice = true;
         }

        }

    }
    character current_player ( //player object call adding all the stuff taken from user input
        player_name,
        player_class, 
        player_race, 
        stat_builder[0], 
        stat_builder[1], 
        stat_builder[2], 
        stat_builder[3], 
        stat_builder[4], 
        stat_builder[5]
    );




}








int main() {


game_start();

return 0;
}
