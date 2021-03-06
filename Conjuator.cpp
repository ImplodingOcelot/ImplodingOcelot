// Written by Zach Ott (Imploding_Ocelot)
#include <iostream>
#include <vector>
#include <string>
std::string root, type, answer, ed1, ed2, ed3;
int word_type, personal, number, runthrough, ranthrough, tense, level;
bool irregular, ed1C, ed2C, ed3C;

bool hasEnding (std::string const &fullString, std::string const &ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

void irregularity_fixer();
void past_irregularity_fixer();
void future_irregularity_fixer();

int main()
{
    // determines basic start-up for best user experience
    // determines # of words
    std::cout << "Input the amount of times to run through: ";
    std::cin >> runthrough;
    runthrough = runthrough - 1;
    // eliminates non-grade level stuff
    std::cout << "What spanish level are you in (ex. '1' for spanish 1): ";
    std::cin >> level;
    std::cout << "For refrence: type 'e' to exit.\n";
    // runsthrough amount of times entered
    for (ranthrough = 0; runthrough >= ranthrough; ranthrough++)
    {
        ed1 = "ar", ed2 = "er", ed3 = "ir";
        std::cout << "Please enter a root word: ";
        std::cin >> root;
        std::cout << "Using '" << root << "' as root.\n";
        // determines current ending
        ed1C = hasEnding(root,ed1);
        ed2C = hasEnding(root,ed2);
        ed3C = hasEnding(root,ed3);
        if (ed1C == true)
        {
            word_type = 1;
        }
        else if (ed2C == true)
        {
            word_type = 2;
        }
        else if (ed3C == true)
        {
            word_type = 3;
        }
        else
        {

            std::cout << "That root is shit, but fine...\n";
        }
        if (root == "ir") // corrects for 2 letter root "ir"
        {
            root = "placeholder";
        }
        root.pop_back();
        root.pop_back();
        // determines ending wanted
        std::cout << "Are you talking in 1st, 2nd or 3rd person?\n"
                  << "Use 1/2/3 for your answer.\n";
        std::cin >> personal;
        std::cout << "Are you talking about multiple people?\n"
                  << "Use 1 for one person; 2 for multiple people.\n";
        std::cin >> number;
        if (level != 1)
        {
            std::cout << "Is this Past Tense (1); Present Tense (2); or Future Tense (3)?\n";
            std::cin >> tense;
        }
        if(level == 1)  {
            irregular= false;
            tense = 2;
        }
        // checks & fixes irregular vars - irregular roots go through diffrent function
        if (tense == 1)
        {
            past_irregularity_fixer();
        }
        else if (tense == 2)
        {
            irregularity_fixer();
        }
        else if (tense == 3)
        {
            future_irregularity_fixer();
        }
        // pastes on ending if its not an irregular
        if (irregular == false || level == 1)
        {
            // PAST tense -----------------------------------------------------------------------------
            if (tense == 1)
            {
                if (word_type == 3)
                {
                    word_type = 2; // quick fix for -ir and -er being the same in past
                }
                if (personal == 1)
                {
                    if (word_type == 1)
                    {
                        switch (number)
                        {
                        case 1:
                            root.append("??");
                            break;
                        case 2:
                            root.append("amos");
                            break;
                        default:
                            std::cout << "you good bro?\n";
                        }
                    }
                    else if (word_type == 2)
                    {
                        switch (number)
                        {
                        case 1:
                            root.append("??");
                            break;
                        case 2:
                            root.append("imos");
                            break;
                        default:
                            std::cout << "you good bro?\n";
                        }
                    }
                }
                else if (personal == 2)
                {
                    if (word_type == 1)
                    {
                        switch (number)
                        {
                        case 1:
                            root.append("aste");
                            break;
                        case 2:
                            root.append("asteis");
                            break;
                        default:
                            std::cout << "you good bro?\n";
                        }
                    }
                    else if (word_type == 2)
                    {
                        switch (number)
                        {
                        case 1:
                            root.append("iste");
                            break;
                        case 2:
                            root.append("isteis");
                            break;
                        default:
                            std::cout << "you good bro?\n";
                        }
                    }
                }
                else if (personal == 3)
                {
                    if (word_type == 1)
                    {
                        switch (number)
                        {
                        case 1:
                            root.append("??");
                            break;
                        case 2:
                            root.append("aron");
                            break;
                        default:
                            std::cout << "you good bro?\n";
                        }
                    }
                    if (word_type == 2)
                    {
                        switch (number)
                        {
                        case 1:
                            root.append("i??");
                            break;
                        case 2:
                            root.append("ieron");
                            break;
                        default:
                            std::cout << "you good bro?\n";
                        }
                    }
                }
            }
            // PRESENT TENSE --------------------------------------------------------------------------
            if (tense == 2)
            {
                if (personal == 1)
                {
                    if (word_type == 1)
                    {
                        switch (number)
                        {
                        case 1:
                            root.append("o");
                            break;
                        case 2:
                            root.append("amos");
                            break;
                        default:
                            std::cout << "you good bro?\n";
                        }
                    }
                    else if (word_type == 2)
                    {
                        switch (number)
                        {
                        case 1:
                            root.append("o");
                            break;
                        case 2:
                            root.append("emos");
                            break;
                        default:
                            std::cout << "you good bro?\n";
                        }
                    }
                    else if (word_type == 3)
                    {
                        switch (number)
                        {
                        case 1:
                            root.append("o");
                            break;
                        case 2:
                            root.append("imos");
                            break;
                        default:
                            std::cout << "you good bro?\n";
                        }
                    }
                }
                else if (personal == 2)
                {
                    if (word_type == 1)
                    {
                        switch (number)
                        {
                        case 1:
                            root.append("as");
                            break;
                        case 2:
                            root.append("??is");
                            break;
                        default:
                            std::cout << "you good bro?\n";
                        }
                    }
                    else if (word_type == 2)
                    {
                        switch (number)
                        {
                        case 1:
                            root.append("es");
                            break;
                        case 2:
                            root.append("??is");
                            break;
                        default:
                            std::cout << "you good bro?\n";
                        }
                    }
                    else if (word_type == 3)
                    {
                        switch (number)
                        {
                        case 1:
                            root.append("es");
                            break;
                        case 2:
                            root.append("??s");
                            break;
                        default:
                            std::cout << "you good bro?\n";
                        }
                    }
                }
                else if (personal == 3)
                {
                    if (word_type == 1)
                    {
                        switch (number)
                        {
                        case 1:
                            root.append("a");
                            break;
                        case 2:
                            root.append("an");
                            break;
                        default:
                            std::cout << "you good bro?\n";
                        }
                    }
                    if (word_type == 2)
                    {
                        switch (number)
                        {
                        case 1:
                            root.append("e");
                            break;
                        case 2:
                            root.append("en");
                            break;
                        default:
                            std::cout << "you good bro?\n";
                        }
                    }
                    else if (word_type == 3)
                    {
                        switch (number)
                        {
                        case 1:
                            root.append("e");
                            break;
                        case 2:
                            root.append("en");
                            break;
                        default:
                            std::cout << "you good bro?\n";
                        }
                    }
                }
            }
            // FUTURE TENSE ---------------------------------------------------------------------------
            if (tense == 3)
            {
                if (personal == 1)
                {
                    switch (number)
                    {
                    case 1:
                        root.append("??");
                        break;
                    case 2:
                        root.append("emos");
                        break;
                    default:
                        std::cout << "you good bro?\n";
                    }
                }
                else if (personal == 2)
                {
                    switch (number)
                    {
                    case 1:
                        root.append("??s");
                        break;
                    case 2:
                        root.append("??is");
                        break;
                    default:
                        std::cout << "you good bro?\n";
                    }
                }
                else if (personal == 3)
                {
                    switch (number)
                    {
                    case 1:
                        root.append("??");
                        break;
                    case 2:
                        root.append("??n");
                        break;
                    default:
                        std::cout << "you good bro?\n";
                    }
                }
            }
        }
        // outputs new conjgation
        std::cout << "The correct conjugation is:\n"
                  << root << "\n";
        std::cout << "\n";
    }
}
// diffrent areas to paste on ending

void irregularity_fixer()
{
    if (root == "ten")
    { // tener irregularity
        irregular = true;
        if (personal == 1)
        {
            if (number == 1)
            {
                root = "tengo";
            }
            if (number == 2)
            {
                root = "tenemos";
            }
        }
        else if (personal == 2)
        {
            if (number == 1)
            {
                root = "tienes";
            }
            if (number == 2)
            {
                root = "ten??is";
            }
        }
        else if (personal == 3)
        {
            if (number == 1)
            {
                root = "tiene";
            }
            if (number == 2)
            {
                root = "tienen";
            }
        }
    }
    else if (root == "s")
    { // ser irregularity
        irregular = true;
        if (personal == 1)
        {
            if (number == 1)
            {
                root = "soy";
            }
            if (number == 2)
            {
                root = "somos";
            }
        }
        else if (personal == 2)
        {
            if (number == 1)
            {
                root = "eres";
            }
            if (number == 2)
            {
                root = "sois";
            }
        }
        else if (personal == 3)
        {
            if (number == 1)
            {
                root = "es";
            }
            if (number == 2)
            {
                root = "son";
            }
        }
    }
    else if (root == "est")
    { // estar irregularity
        irregular = true;
        if (personal == 1)
        {
            if (number == 1)
            {
                root = "estoy";
            }
            if (number == 2)
            {
                root = "estamos";
            }
        }
        else if (personal == 2)
        {
            if (number == 1)
            {
                root = "est??s";
            }
            if (number == 2)
            {
                root = "est??is";
            }
        }
        else if (personal == 3)
        {
            if (number == 1)
            {
                root = "est??";
            }
            if (number == 2)
            {
                root = "est??n";
            }
        }
    }
    else if (root == "hab")
    { // haber irregularity
        irregular = true;
        if (personal == 1)
        {
            if (number == 1)
            {
                root = "he";
            }
            if (number == 2)
            {
                root = "hemos";
            }
        }
        else if (personal == 2)
        {
            if (number == 1)
            {
                root = "has";
            }
            if (number == 2)
            {
                root = "hab??is";
            }
        }
        else if (personal == 3)
        {
            if (number == 1)
            {
                root = "ha";
            }
            if (number == 2)
            {
                root = "han";
            }
        }
    }
    else if (root == "pod")
    { // poder irregularity
        irregular = true;
        if (personal == 1)
        {
            if (number == 1)
            {
                root = "puedo";
            }
            if (number == 2)
            {
                root = "podemos";
            }
        }
        else if (personal == 2)
        {
            if (number == 1)
            {
                root = "puedes";
            }
            if (number == 2)
            {
                root = "pod??is";
            }
        }
        else if (personal == 3)
        {
            if (number == 1)
            {
                root = "puede";
            }
            if (number == 2)
            {
                root = "pueden";
            }
        }
    }
    else if (root == "placehold")
    { // ir irregularity- doesnt have actual root because its too short XD
        irregular = true;
        if (personal == 1)
        {
            if (number == 1)
            {
                root = "voy";
            }
            if (number == 2)
            {
                root = "vamos";
            }
        }
        else if (personal == 2)
        {
            if (number == 1)
            {
                root = "vas";
            }
            if (number == 2)
            {
                root = "vais";
            }
        }
        else if (personal == 3)
        {
            if (number == 1)
            {
                root = "va";
            }
            if (number == 2)
            {
                root = "van";
            }
        }
    }
    else if (root == "pon")
    { // poner irregularity
        irregular = true;
        if (personal == 1)
        {
            if (number == 1)
            {
                root = "pongo";
            }
            if (number == 2)
            {
                root = "ponemos";
            }
        }
        else if (personal == 2)
        {
            if (number == 1)
            {
                root = "pones";
            }
            if (number == 2)
            {
                root = "pon??is";
            }
        }
        else if (personal == 3)
        {
            if (number == 1)
            {
                root = "pone";
            }
            if (number == 2)
            {
                root = "ponen";
            }
        }
    }
    else if (root == "dec")
    { // decir irregularity
        irregular = true;
        if (personal == 1)
        {
            if (number == 1)
            {
                root = "digo";
            }
            if (number == 2)
            {
                root = "decimos";
            }
        }
        else if (personal == 2)
        {
            if (number == 1)
            {
                root = "dices";
            }
            if (number == 2)
            {
                root = "dec??s";
            }
        }
        else if (personal == 3)
        {
            if (number == 1)
            {
                root = "dice";
            }
            if (number == 2)
            {
                root = "dicen";
            }
        }
    }
    else if (root == "v")
    { // ver irregularity
        irregular = true;
        if (personal == 1)
        {
            if (number == 1)
            {
                root = "veo";
            }
            if (number == 2)
            {
                root = "vemos";
            }
        }
        else if (personal == 2)
        {
            if (number == 1)
            {
                root = "ves";
            }
            if (number == 2)
            {
                root = "veis";
            }
        }
        else if (personal == 3)
        {
            if (number == 1)
            {
                root = "ve";
            }
            if (number == 2)
            {
                root = "ven";
            }
        }
    }
    else if (root == "quer")
    { // querer irregularity
        irregular = true;
        if (personal == 1)
        {
            if (number == 1)
            {
                root = "quiero";
            }
            if (number == 2)
            {
                root = "queremos";
            }
        }
        else if (personal == 2)
        {
            if (number == 1)
            {
                root = "quieres";
            }
            if (number == 2)
            {
                root = "quer??is";
            }
        }
        else if (personal == 3)
        {
            if (number == 1)
            {
                root = "quiere";
            }
            if (number == 2)
            {
                root = "quieren";
            }
        }
    }
    else if (root == "sab")
    { // saber irregularity
        irregular = true;
        if (personal == 1)
        {
            if (number == 1)
            {
                root = "s??";
            }
            if (number == 2)
            {
                root = "sabemos";
            }
        }
        else if (personal == 2)
        {
            if (number == 1)
            {
                root = "sabes";
            }
            if (number == 2)
            {
                root = "sab??is";
            }
        }
        else if (personal == 3)
        {
            if (number == 1)
            {
                root = "sabe";
            }
            if (number == 2)
            {
                root = "saben";
            }
        }
    }
    else if (root == "ven")
    { // Venir irregularity
        irregular = true;
        if (personal == 1)
        {
            if (number == 1)
            {
                root = "vengo";
            }
            if (number == 2)
            {
                root = "venimos";
            }
        }
        else if (personal == 2)
        {
            if (number == 1)
            {
                root = "vienes";
            }
            if (number == 2)
            {
                root = "ven??s";
            }
        }
        else if (personal == 3)
        {
            if (number == 1)
            {
                root = "viene";
            }
            if (number == 2)
            {
                root = "vienen";
            }
        }
    }
    else if (root == "pens")
    { // Pensar irregularity
        irregular = true;
        if (personal == 1)
        {
            if (number == 1)
            {
                root = "pienso";
            }
            if (number == 2)
            {
                root = "pensamos";
            }
        }
        else if (personal == 2)
        {
            if (number == 1)
            {
                root = "piensas";
            }
            if (number == 2)
            {
                root = "pens??is";
            }
        }
        else if (personal == 3)
        {
            if (number == 1)
            {
                root = "piensa";
            }
            if (number == 2)
            {
                root = "piensan";
            }
        }
    }
    else if (root == "conoc")
    { // Conocer irregularity
        irregular = true;
        if (personal == 1)
        {
            if (number == 1)
            {
                root = "conozco";
            }
            if (number == 2)
            {
                root = "conocemos";
            }
        }
        else if (personal == 2)
        {
            if (number == 1)
            {
                root = "conoces";
            }
            if (number == 2)
            {
                root = "conoc??is";
            }
        }
        else if (personal == 3)
        {
            if (number == 1)
            {
                root = "conoce";
            }
            if (number == 2)
            {
                root = "conocen";
            }
        }
    }
}
void past_irregularity_fixer()
{
    if (root == "v")
    { // ver past tense
        irregular = true;
        if (personal == 1)
        {
            if (number == 1)
            {
                root = "vi";
            }
            if (number == 2)
            {
                root = "vimos";
            }
        }
        else if (personal == 2)
        {
            if (number == 1)
            {
                root = "viste";
            }
            if (number == 2)
            {
                root = "error_code_69"; // ?????????????????????????????????????????
            }
        }
        else if (personal == 3)
        {
            if (number == 1)
            {
                root = "vio";
            }
            if (number == 2)
            {
                root = "vieron";
            }
        }
    }
    else if (root == "d")
    { // dir past tense
        irregular = true;
        if (personal == 1)
        {
            if (number == 1)
            {
                root = "di";
            }
            if (number == 2)
            {
                root = "dimos";
            }
        }
        else if (personal == 2)
        {
            if (number == 1)
            {
                root = "diste";
            }
            if (number == 2)
            {
                root = "error_code_69"; // ?????????????????????????????????????????
            }
        }
        else if (personal == 3)
        {
            if (number == 1)
            {
                root = "dio";
            }
            if (number == 2)
            {
                root = "dieron";
            }
        }
    }
    else if (root == "s" || root == "placehold")
    { // ser/ir past tense
        irregular = true;
        if (personal == 1)
        {
            if (number == 1)
            {
                root = "fui";
            }
            if (number == 2)
            {
                root = "fuimos";
            }
        }
        else if (personal == 2)
        {
            if (number == 1)
            {
                root = "fuiste";
            }
            if (number == 2)
            {
                root = "error_code_69"; // ?????????????????????????????????????????
            }
        }
        else if (personal == 3)
        {
            if (number == 1)
            {
                root = "fue";
            }
            if (number == 2)
            {
                root = "fueron";
            }
        }
    }
    else if (root == "hac")
    { // hacer past tense
        irregular = true;
        if (personal == 1)
        {
            if (number == 1)
            {
                root = "hice";
            }
            if (number == 2)
            {
                root = "hicimos";
            }
        }
        else if (personal == 2)
        {
            if (number == 1)
            {
                root = "hiciste";
            }
            if (number == 2)
            {
                root = "error_code_69"; // ?????????????????????????????????????????
            }
        }
        else if (personal == 3)
        {
            if (number == 1)
            {
                root = "hizo";
            }
            if (number == 2)
            {
                root = "hicieron";
            }
        }
    } // root
}
void future_irregularity_fixer()
{
    //Forms that Drop the e or i from the Infinitive Ending and Add a d
    if (root == "ten" || root == "pon" || root == "val" || root == "sal" || root == "ven")
    {
        irregular = true;
        root.append("r");

        if (personal == 1)
        {
            if (number == 1)
            {
                root.append("??");
            }
            if (number == 2)
            {
                root.append("emos");
            }
        }
        else if (personal == 2)
        {
            if (number == 1)
            {
                root.append("??s");
            }
            if (number == 2)
            {
                root.append("??is");
            }
        }
        else if (personal == 3)
        {
            if (number == 1)
            {
                root.append("??");
            }
            if (number == 2)
            {
                root.append("??n");
            }
        }
    }
    //Forms that Drop the e or i from the Infinitive Ending
    else if (root == "pod" || root == "cab" || root == "hab" || root == "sab" || root == "quer")
    {
        irregular = true;
        root.append("r");

        if (personal == 1)
        {
            if (number == 1)
            {
                root.append("??");
            }
            if (number == 2)
            {
                root.append("emos");
            }
        }
        else if (personal == 2)
        {
            if (number == 1)
            {
                root.append("??s");
            }
            if (number == 2)
            {
                root.append("??is");
            }
        }
        else if (personal == 3)
        {
            if (number == 1)
            {
                root.append("??");
            }
            if (number == 2)
            {
                root.append("??n");
            }
        }
    }
    //Irregular stems
    else if (root == "hac")
    {
        irregular = true;
        if (personal == 1)
        {
            if (number == 1)
            {
                root = ("har??");
            }
            if (number == 2)
            {
                root = ("haremos");
            }
        }
        else if (personal == 2)
        {
            if (number == 1)
            {
                root = ("har??s");
            }
            if (number == 2)
            {
                root = ("har??is");
            }
        }
        else if (personal == 3)
        {
            if (number == 1)
            {
                root = ("har??");
            }
            if (number == 2)
            {
                root = ("har??n");
            }
        }
    }
    else if (root == "dec")
    {
        irregular = true;
        if (personal == 1)
        {
            if (number == 1)
            {
                root = ("dir??");
            }
            if (number == 2)
            {
                root = ("diremos");
            }
        }
        else if (personal == 2)
        {
            if (number == 1)
            {
                root = ("dir??s");
            }
            if (number == 2)
            {
                root = ("dir??is");
            }
        }
        else if (personal == 3)
        {
            if (number == 1)
            {
                root = ("dir??");
            }
            if (number == 2)
            {
                root = ("dir??n");
            }
        }
    }
}
