#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int count = 0, Yes= 0, No = 0;
int Under12yearsold = 0, twelveToSeventyyears = 0, eighteenToTwentyFouryears = 0, twentyFiveToThirtyFouryears = 0, thirtyFiveOrOlder = 0;
int male=0,female=0;
int Employed = 0, SelfEmployedFreelance = 0, Unemployed = 0, Studying = 0, Retired = 0, Othe = 0;
int Islam = 0, Hinduism = 0, Christianity = 0, Buddhism = 0, Other = 0;
int Village = 0, Town = 0, City = 0;
int tenTOTwenty = 0, twentyOneToThrity = 0, thirtyOneTOFourty = 0, fourtyOneToFifty = 0;

processExcleFile()
{
    ifstream readFile;
    ofstream writefile;
    writefile.open("sample.txt");
    readFile.open("Dataset.csv");


    string file;

    while(readFile>>file)
    {
        for(int i=0; i<file.size(); i++)
        {
            if(file[i]==',')
            {
                file[i] = ' ';
            }
        }
        writefile<<file<<endl;
        count++;

    }
    readFile.close();
    writefile.close();

}

string targetGender()
{
    ifstream readFile;
    readFile.open("sample.txt");

    string age, gender, work, religion, live, product, price;

    while(readFile>>age>>gender>>work>>religion>>live>>product>>price)
    {
        if(product=="Yes")
        {
            Yes++;
            if(gender == "Male")
            {
                male++;
            }
            else
                female++;

        }

    }
    readFile.close();
    if(male>female)
        return "Male";
    else
        return "Female";
}

string targetAge()
{

    ifstream readFile;
    readFile.open("sample.txt");
    int Under12yearsold = 0, twelveToSeventyyears = 0, eighteenToTwentyFouryears = 0, twentyFiveToThirtyFouryears = 0, thirtyFiveOrOlder = 0;



    string age, gender, work, religion, live, product, price;

    while(readFile>>age>>gender>>work>>religion>>live>>product>>price)
    {
        if(product=="Yes")
        {
            if(age == "Under12yearsold")
            {
                Under12yearsold++;
                age[0]++;
            }
            else if(age == "12-17years")
            {
                twelveToSeventyyears++;

            }
            else if(age == "18-24years")
            {
                eighteenToTwentyFouryears++;

            }
            else if(age == "25-34years")
            {
                twentyFiveToThirtyFouryears++;

            }
            else if(age == "35orolder")
            {
                thirtyFiveOrOlder++;

            }

        }

    }
    readFile.close();

    if( (Under12yearsold > twelveToSeventyyears) && (Under12yearsold > eighteenToTwentyFouryears) && (Under12yearsold > thirtyFiveOrOlder))
        return "Under 12 years old";
    else if( (twelveToSeventyyears > Under12yearsold) && (twelveToSeventyyears > eighteenToTwentyFouryears) && (twelveToSeventyyears > thirtyFiveOrOlder))
        return "12-17 years ";
    else if( (eighteenToTwentyFouryears > Under12yearsold)  && (eighteenToTwentyFouryears > twelveToSeventyyears) && (eighteenToTwentyFouryears > thirtyFiveOrOlder))
        return "18-24 years";
    else if((thirtyFiveOrOlder > Under12yearsold) && (thirtyFiveOrOlder > twelveToSeventyyears) && (thirtyFiveOrOlder > eighteenToTwentyFouryears))
        return "35 or older";

}

string targetWork()
{

    ifstream readFile;
    readFile.open("sample.txt");

    int Employed = 0, SelfEmployedFreelance = 0, Unemployed = 0, Studying = 0, Retired = 0, Other = 0;

    string age, gender, work, religion, live, product, price;

    while(readFile>>age>>gender>>work>>religion>>live>>product>>price)
    {
        if(product=="Yes")
        {
            if(work == "Employed")
            {
                Employed++;
            }
            else if(work == "Self-employed/Freelance")
            {
                SelfEmployedFreelance++;
            }
            else if(work == "Unemployed")
            {
                Unemployed++;
            }
            else if(work == "Studying")
            {
                Studying++;
            }
            else if(work == "Retired")
            {
                Retired++;
            }
            else if(work == "Othe")
            {
                Othe++;
            }


        }

    }
    readFile.close();

    if( (Employed > SelfEmployedFreelance) && (Employed > Unemployed) && (Employed >Studying) && (Employed > Retired, Other))
        return "Employed";
    else if( (SelfEmployedFreelance > Employed) && (SelfEmployedFreelance > Unemployed) && (SelfEmployedFreelance > Studying) && (SelfEmployedFreelance > Retired) && (SelfEmployedFreelance > Other))
        return "Self-employed//Freelance";
    else if( (Unemployed > Employed) && (Unemployed > SelfEmployedFreelance) && (Unemployed > Studying) && (Unemployed > Retired) && (Unemployed > Other))
        return "Unemployed";
    else if( ( Studying > Employed ) && (Studying > SelfEmployedFreelance) && (Studying > Unemployed) && (Studying > Retired) && (Studying > Other))
        return "Studying";
    else if( (Retired > Employed) && (Retired > SelfEmployedFreelance) && (Retired > Unemployed) && (Retired > Studying) && (Retired > Other))
        return "Retired";
    else if( (Other > Employed) && (Other > SelfEmployedFreelance) && (Other > Unemployed) && (Other > Studying) && (Other > Retired))
        return "Other";

}

string targetReligion()
{
    ifstream readFile;
    readFile.open("sample.txt");



    string age, gender, work, religion, live, product, price;

    while(readFile>>age>>gender>>work>>religion>>live>>product>>price)
    {
        if(product=="Yes")
        {
            if(religion == "Islam")
            {
                Islam++;
            }
            else if(religion == "Hinduism")
            {
                Hinduism++;
            }
            else if(religion == "Christianity")
            {
                Christianity++;
            }
            else if(religion == "Buddhism")
            {
                Buddhism++;
            }
            else if(religion == "Other")
            {
                Other++;
            }

        }

    }
    readFile.close();

    if ( (Islam >  Hinduism) && (Islam >  Christianity) && (Islam >  Buddhism) && (Islam >  Other ))
        return "Islam";
    else if( (Hinduism > Islam) && (Hinduism >Christianity) && (Hinduism >Buddhism) && (Hinduism >Other))
        return "Hinduism";
    else if ( (Christianity > Islam) && (Christianity >Hinduism) && (Christianity >Buddhism) && (Christianity >Other ))
        return "Christianity";
    else if( (Buddhism > Islam) && (Buddhism > Hinduism) && (Buddhism > Christianity) && (Buddhism > Other ))
        return "Buddhism";
    else if ( (Other > Islam) && (Other >Hinduism) && (Other > Christianity) && (Other >Buddhism ))
        return "Other";


}

string targetArea()
{
    ifstream readFile;
    readFile.open("sample.txt");


    string age, gender, work, religion, live, product, price;

    while(readFile>>age>>gender>>work>>religion>>live>>product>>price)
    {
        if(product=="Yes")
        {
            if(live == "Village")
            {
                Village++;
            }
            else if(live == "Town")
            {
                Town++;
            }
            else if(live == "City")
            {
                City++;
            }


        }

    }
    readFile.close();

    if( (Village > Town) && (Village >City))
        return "Village";
    else if( (Town > Village) && (Town > City))
        return "Town";
    else if( (City > Village) && (City >Town))
        return "City";

}

string targetPrice()
{

    ifstream readFile;
    readFile.open("sample.txt");

    string age, gender, work, religion, live, product, price;

    while(readFile>>age>>gender>>work>>religion>>live>>product>>price)
    {
        if(product=="Yes")
        {
            if(price == "10-20Taka")
            {
                tenTOTwenty++;
            }
            else if(price == "21-30Taka")
            {
                twentyOneToThrity++;
            }
            else if(price == "31-40Taka")
            {
                thirtyOneTOFourty++;
            }
            else if(price == "41-50Taka")
            {
                fourtyOneToFifty++;
            }

        }

    }
    readFile.close();
    if( (tenTOTwenty > twentyOneToThrity) &&  (tenTOTwenty > thirtyOneTOFourty) && (tenTOTwenty >fourtyOneToFifty))
        return "10-20 Taka";
    else if( (twentyOneToThrity > tenTOTwenty) && (twentyOneToThrity > thirtyOneTOFourty) && (twentyOneToThrity > fourtyOneToFifty))
        return "21-30 Taka";
    else if( (thirtyOneTOFourty > tenTOTwenty) && (thirtyOneTOFourty > twentyOneToThrity) && (thirtyOneTOFourty > fourtyOneToFifty))
        return "31-40 Taka";
    else if( (fourtyOneToFifty > tenTOTwenty) && (fourtyOneToFifty > twentyOneToThrity) && (fourtyOneToFifty > thirtyOneTOFourty ))
        return "41-50 Taka";

}

int main()
{

    processExcleFile();
    cout<<"Target Gender : "<<targetGender()<<endl;
    cout<<"Target Age Range: "<<targetAge()<<endl;
    cout<<"Target Occupation: "<<targetWork()<<endl;
    cout<<"Target Religion: "<<targetReligion()<<endl;
    cout<<"Target Area: "<<targetArea()<<endl;
    cout<<"Optimal Price Range: "<<targetPrice()<<endl;

    cout<<"Consumer Rate: "<<(Yes*100/count)<<"%"<<endl;

    return 0;
}
