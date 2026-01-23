//my dnd text base game project
//I hope this will help me practice my cpp skills and oop

#include <iostream>
#include <string>

// enum works to essentaily name a value, so all in the enum
//are ints (hover over) so barbarian is 1... etc
enum class class_type {
    barbarian = 1,
    bard,
    cleric,
    druid,
    fighter,
    monk, //
    paladin,
    ranger, 
    rogue,  
    sorcerer, 
    warlock, 
    wizard
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

    player() {
        player_c = class_type::barbarian;
        strength = 0;
        dexterity = 0;
        constitution = 0;
        intelligence = 0;
        wisdom = 0;
        charisma = 0;

    }
    player(class_type type, int s, int d, int c, int i, int w, int ch) { 

        player_c = type;
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


void game_start () {

    narrate("You swing open the door, stubbling into the adventurers guild.");
    narrate ("Looking around you notice the piercing glares throughout the room.\n");

    speak("Guild Clerk", "Welcome in, I dont think I've ever seen your face before.");
    speak("Guild Clerk", "Are you here to join the guild?\n");

    narrate("You nervously nod your head,");
    narrate("still feeling the piercing precence of the others\n");

    speak("Guild Clerk", "Alright then, what your name then");
    std::string player_name;
    std::getline(std::cin, player_name);
    speak("Guild Clerk", "Nice to meet you " + player_name + "!");
    speak("Guild Clerk", "What class are you? \n");
    
    int class_choice{-1};
    while (true) {
        std::cout << "Select a class by typing in the coresponding number\n";
        class_menu();
       
        std::cin >> class_choice;

        if(class_choice >=1 && class_choice <=12) {
            std::cout << "Do you confirm " << class_choice << " is your class of choice?\n";
            char choice;
            std::cout << "Please Select (Y/N): "; //wording could be better may confuse user.
            std::cin >> choice;
                if(choice == 'y' || choice == 'Y') { break;}
                continue; //continue here to send user back to select to reselct class
            
        }
        else if (class_choice <=0 || class_choice >=13) {
            std::cout << "Invalid Choice, please select again.\n\n";
            
        }
    }
    
    class_type player_class; //calling enum, when I make my player class call I will use this as first param
    

    switch (class_choice) {
        case 1: 
            std::cout << "You choose the Barbarian class";
            player_class = class_type::barbarian; 
            break;
        case 2:            
            std::cout << "You choose the Bard class";
            player_class = class_type::bard;
            break;
        case 3: 
            std::cout << "You choose the Cleric class";
            player_class = class_type::cleric;
            break;
        case 4: 
            std::cout << "You choose the Druid class";
            player_class = class_type::druid;
            break;
        case 5: 
            std::cout << "You choose the Fighter class";
            player_class = class_type::fighter;
            break;
        case 6: 
            std::cout << "You choose the Monk class";
            player_class = class_type::monk;
            break;
        case 7: 
            std::cout << "You choose the Paladin class";
            player_class = class_type::paladin;
            break;
        case 8: 
            std::cout << "You choose the Ranger class";
            player_class = class_type::ranger;
            break;
        case 9: 
            std::cout << "You choose the Rogue class";
            player_class = class_type::rogue;
            break;
        case 10: 
            std::cout << "You choose the Sorcerer class";
            player_class = class_type::sorcerer;
            break;
        case 11: 
            std::cout << "You choose the Warlock class";
            player_class = class_type::warlock;
            break;
        case 12:
            std::cout << "You choose the Wizard class";
            player_class = class_type::wizard;
            break;
    }




   //next step, add more diaolage about having player
   //walk over and put their hand on a cystal ball then allow them to assign stat points
   


    //plan is ot make probably a class of all the classes (lol)
    // then after player states class they put their hands on a magic ball
    //and I will ad a random feature which gives them random starting stats
    // w srand() player cant get op at the start but 
    // OR I do base stats for each class which I lowk like more



};








int main() {


game_start();

}
