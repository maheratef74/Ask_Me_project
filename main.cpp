#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define ll long long
using namespace std;
struct question_and_answer
{
    string id;
    string question;
    string answer;

};
map<pair<string , string> , int> read_user_fill();
map<pair<string , string> , int>user_in_system = read_user_fill();
string id , user_name;

void Delete_question();
void write_in_user_fill();
void feed();
void login_and_signin();
void list_system_users();
bool print_questions_from_me();
void home_page();
bool print_questions_to_me();
void answer_question();
 void ask_question();
void run()
{
    login_and_signin();
}

int main()
{
    run();
    return 0;
}
    map<pair<string,string>,int> read_user_fill()
    {
        map<pair<string , string> , int> user_in_systemm;
        string name, idd;
        ifstream myfill("user_in_system.txt", ios::in);
        if(myfill.is_open())
        {
            while (!myfill.eof())
            {
                myfill >> name >> idd;
                user_in_systemm[{name , idd}] = 1;
            }
            myfill.close();
        }
        else
        {
          cout << "there is a problem in user_in_system.txt" << '\n';
        }
          return user_in_systemm;
    }
    void write_in_user_fill()
    {
        ofstream myfill("user_in_system.txt", ios::out | ios::app);
        if(myfill.is_open())
        {
            myfill << '\n' << user_name + " "  + id;
            myfill.close();
        }
        else
        {
          cout << "there is a problem in user_in_system.txt" << '\n';
        }
    }
    void login_and_signin()
    {
      read_user_fill();
      static int number_of_wrong_answer = 0;

       if(number_of_wrong_answer == 3) return;
        cout << " 1 : login " << '\n'
             << " 2 : sign in " << '\n';
         string op; cin >> op;
         if(op != "1" and op != "2")
         {
             cout << "Wrong...\n";
             login_and_signin();
         }
        if(user_in_system.size() == 1 && op == "1")
        {
            cout << "There is no users in the system ,please sign up " << '\n';
            login_and_signin();
        }
        cout << "please, enter your user name\n" ;
        cin >> user_name;
        cout << "please, enter your id\n";
        cin >> id;
    if(op == "1")
    {
        if( user_in_system[{user_name,id}])
        {
           home_page();
        }
        else
        {
            number_of_wrong_answer++;
          cout << "Your user name or your id is wrong please try again..." << '\n';
          login_and_signin();
        }
    }
    else if(op == "2")
    {
        if(user_in_system[{user_name , id}])
        {
            cout << "This name and id used before ,please sign in with another name or id \n";
            login_and_signin();
        }
        write_in_user_fill();
        home_page();
    }
    else
    {
      cout << "wrong.... please try again... " << '\n';
      login_and_signin();
    }
    }
    void list_system_users()
{
    string name , idd;
    vector<pair<string , string>>users;
    ifstream myfill("user_in_system.txt" , ios::in | ios::app);
    if(myfill.is_open())
    {
        while (!myfill.eof())
        {
            myfill >> name >> idd;
          cout <<"ID: " <<  idd << "       Name: " + name +"\n";
        }
          myfill.close();
    }
    else
    {
      cout << "there is a problem in user_in_system.txt" << '\n';
    }
}
    void home_page()
    {
        cout << "Menu: " << '\n' << "1: Print questions to me: " << '\n';
        cout << "2: Print questions from me: " << '\n';
        cout << "3: Answer a question: " << '\n';
        cout << "4: Delete question:" << '\n';
        cout << "5: Ask question:" << '\n';
        cout << "6: List system users:" << '\n';
        cout << "7: Feed:" << '\n';
        cout << "8: Go to login and signin page \n";
        cout << "9: Logout: " << '\n';
        cout << "Enter number from 1 : 9 " << '\n';
        int ch; cin >> ch;
        if(ch == 1)
        {
            print_questions_to_me();
            cout << "\n=============================================================\n";
           home_page();
        }
        else if(ch == 2)
        {
            print_questions_from_me();
            cout << "\n=============================================================\n";
            home_page();
        }
        else if(ch == 3)
        {
            answer_question();
            cout << "\n=============================================================\n";
            home_page();
        }
        else if(ch == 4)
        {
            Delete_question();
            cout << "\n=============================================================\n";
            home_page();
        }
        else if(ch == 5)
        {
            ask_question();
            cout << "\n=============================================================\n";
            home_page();
        }
        else if(ch == 6)
        {
            list_system_users();
            cout << "\n=============================================================\n";
            home_page();
        }
        else if(ch == 7)
        {
            feed();
            cout << "\n=============================================================\n";
          home_page();
        }
        else if(ch == 8)
        {
            cout << "\n=============================================================\n";
           login_and_signin();
        }
        else if(ch == 9)
        {
            login_and_signin();
        }
        else
        {
            cout << "wrong...try again." << '\n';
            cout << "\n=============================================================\n";
            home_page();
        }
    }
    bool print_questions_from_me() {

        ifstream myfill("questions.txt", ios::in | ios::app);
        unordered_map<string, vector<string>> question_from;
        if (myfill.is_open()) {
            while (!myfill.eof()) {
                string idd,iddd , from, ques, to, line;
                getline(myfill, idd, ',');

                if(idd == "Answer(")
                {
                    getline(myfill , line);
                    continue;
                }
                getline(myfill, to, ',');
                getline(myfill, from, ',');
                getline(myfill, ques);
                string answer;
                if (from == user_name) {
                    question_from[idd].push_back(to+','+ques);
                    while (getline(myfill, answer) ) {
                        if(answer[0] == 'A' and answer[1] == 'n' and answer[2] == 's')
                        {
                            question_from[idd].push_back(answer);
                        }
                        else break;
                    }
                }
                }
                myfill.close();
            }

                 else {
                    cout << "there is a problem in user_in_system.txt" << '\n';
                }

                if (!question_from.size()) {
                    cout << "You don't ask any one.\n";
                    return 0;
                }
                for (auto qu: question_from) {
                    cout << "\n==================================\n";
                    vector<string> v = qu.second;
                    cout << "ID question: " ;
                    for (int i = 0; i < qu.first.size(); i++)
                    {
                        if(qu.first[i] != ' ') cout << qu.first[i];
                        else cout << "her";
                    }
                    cout << " to: ";
                    for (auto it: v)
                    {
                        for(int i = 0; i  < it.size(); i++)
                        {
                            if(it[i] != ',') cout << it[i];
                            else cout << ' ';
                        }
                        cout << '\n';
                    }
                    cout << "\n==================================\n";
                }
                cout << '\n';
                return 1;
    }
    bool print_questions_to_me()
    {
        string idd , from , ques , to , line ;
        ifstream myfill("questions.txt" , ios::in|ios::app);
         map<string , vector<string>>questionn;
        if(myfill.is_open())
        {
            while (!myfill.eof())
            {
                getline(myfill , idd , ',');
                getline(myfill , to , ',');
                getline(myfill , ques);
                if(to == user_name and idd != "Answer(")
                {
                    string answer;
                    questionn[idd].push_back(from+" "+ques);
                    while (getline(myfill, answer) ) {

                        if(answer[0] == 'A' and answer[1] == 'n' and answer[2] == 's')
                        {
                            questionn[idd].push_back(answer);
                        }
                        else break;
                    }
                }
            }
            myfill.close();
        }
        else
        {
            cout << "there is a problem in user_in_system.txt" << '\n';
        }
        if(!questionn.size())
        {

            cout << "There is no questions to you \n";
            return 0;
        }
        for(auto qu:questionn) {
            vector<string> v = qu.second;
            cout << "\n==================================\n";
            cout << "ID question: ";
            for (int i = 0; i < qu.first.size(); i++)
            {
                if(qu.first[i] != ' ') cout << qu.first[i];
            }
            cout << "  from: ";
            for (auto it: v)
            {
                for(int i = 0; i  < it.size(); i++)
                {
                    if(it[i] != ',') cout << it[i];
                    else cout << ' ';
                }
                cout << '\n';
            }

        }
        return 1;
    }
    void ask_question()
    {
        cout << "who you want to ask ? " << '\n';
        string to; cin >> to;
        cout << "what is his id?" << '\n';
        string id; cin >> id;
        if(!user_in_system[{to,id}])
        {
            cout << "This user is not in the system...try again \n";
            home_page();
        }
        cout << "Enter Id question: \n";
        string id_question; cin >> id_question;
        cout << "Enter your question: " << '\n';
        string question;
        std::cin >> std::ws; // remove cin.ignor
        getline(cin , question);
        ofstream myfill("questions.txt" , ios::out | ios::app);
        if(myfill.is_open())
        {
             // id_qus and to and user_name and ques

            myfill  << "\n\n"+ id_question + ","  + to  + ","+ user_name + "," + question ;
            myfill.close();
            cout << '\n';
            cout << "your question had sent \n";
        }
        else
        {
            cout << "there is a problem in user_in_system.txt" << '\n';
        }
    }
    void feed()
    {
        ifstream myfill("questions.txt" , ios::in | ios::app);
        bool q = 0;
        if(myfill.is_open())
        {
            while (!myfill.eof())
            {
                string idd = "" , from ="" , ques = "" , to = "" , line = "";
                getline(myfill , line);
                int i = 0;
                for( ; i < line.size();)
                {
                    if(line[i] == ',')
                    {
                        i++;
                        break;
                    }
                    else
                    {
                        idd += line[i];
                        i++;
                    }
                }

                for( ; i < line.size();)
                {
                    if(line[i] == ',')
                    {
                        i++;
                        break;
                    }
                    else
                    {
                        to += line[i];
                        i++;
                    }
                }
                for( ; i < line.size();)
                {
                    if(line[i] == ',')
                    {
                        i++;
                        break;
                    }
                    else
                    {
                        from += line[i];
                        i++;
                    }
                }


                for( ; i < line.size();)
                {
                    if(line[i] == ',')
                    {
                        i++;
                        break;
                    }
                    else
                    {
                        ques += line[i];
                        i++;
                    }
                }

                if(idd == "Answer(")
                {
                    cout << idd << to << from << '\n';
                }
                else if(idd != "")
                {
                    q = 1;
                    cout << "\n=================================\n";
                    cout << "ID question: " << idd << "  From: " << from << "  To: " << to << "  Question: " << ques << '\n';
                }
            }
            myfill.close();
        }
        else
        {
            cout << "there is a problem in user_in_system.txt" << '\n';
        }
        if(!q)
        {
            cout << "Ther is nothing in the system: " << '\n';
        }
    }
    void answer_question()
    {
        ifstream myfill("questions.txt" , ios::in);
        unordered_map<string, vector<string>>question , total_questions;

        if(myfill.is_open())
        {
            while (!myfill.eof())
            {
                string idd ="", from ="" , ques="" , to="" , line ="";

                getline(myfill , line);
                int i = 0;
                for( ; i < line.size();)
                {
                    if(line[i] == ',')
                    {
                        i++;
                        break;
                    }
                    else
                    {
                        idd += line[i];
                        i++;
                    }
                }

                  for( ; i < line.size();)
                  {
                      if(line[i] == ',')
                      {
                          i++;
                          break;
                      }
                      else
                      {
                          to += line[i];
                          i++;
                      }
                  }

                  for( ; i < line.size();)
                  {
                      if(line[i] == ',')
                      {
                          i++;
                          break;
                      }
                      else
                      {
                          from += line[i];
                          i++;
                      }
                  }

                for( ; i < line.size();)
                {
                    if(line[i] == ',')
                    {
                        i++;
                        break;
                    }
                    else
                    {
                        ques += line[i];
                        i++;
                    }
                }

                if(to == user_name)
                {
                      string answer;
                    question[idd].push_back(to +"," + from +","+ques);
                    while (getline(myfill, answer) ) {
                        if(answer[0] == 'A' and answer[1] == 'n' and answer[2] == 's')
                        {
                            question[idd].push_back(answer);
                        }
                        else break;
                    }
                }
                else
                {
                    if(idd == "Answer(")
                    {
                        total_questions[to].push_back(idd+','+to+','+from);
                    }
                    else
                    {
                        total_questions[idd].push_back( idd + ','+to + "," + from + ',' + ques);
                    }

                }
            }
            myfill.close();
        }
        else
        {
            cout << "there is a problem in user_in_system.txt" << '\n';
        }

        if(!print_questions_to_me())
        {
            cout << "So, you don't have questions to answer.\n";
            home_page();
        }
        cout << "\n========================================\n";
        cout << "enter ID of question you need to answer: \n";
        std::cin >> std::ws; // remove cin.ignor
        string id_question;
        getline(cin , id_question);
        if(!question[id_question].size())
        {
            if(total_questions[id_question].size())
            {
                cout << "\nThis question doesn't belonge to you so, you don't have the right to answer it.\n";
            }
            else cout << "There is no question with this id\n";
            answer_question();
        }
        if(question[id_question].size() > 1)
        {
            cout << "take care this question has been answered if you want to add another answer press 1\n";
            string op; cin >> op;
            if(op != "1")
            {
                home_page();
            }
        }
        cout << "The question of the id you need to answer is " ;
        vector<string>m = question[id_question];
        for(auto q:m)
        {
            if(q[0] != 'A') // not Answer it is question
            {
                string to = "" , from = "" , ques = "";
                bool t = 0 , f = 0;
                int coma = 0;
                for(int i = 0; i < q.size(); i++)
                {
                    if(q[i] == ',')
                    {
                        i++;
                        coma++;
                    }
                    if(coma == 1) t = 1;
                    if(coma == 2) f = 1;
                    if(!t)
                    {
                        to += q[i];
                    }
                    if(t and !f)
                    {
                        from += q[i];
                    }
                    if(coma == 2)
                    {
                        ques += q[i] ;
                    }

                }
                cout << "from : " << from << '\n' << "Question: " << ques << '\n';
            }
            else cout << q << '\n';
        }
        cout << "\n==================================\n";
        cout << "Enter your answer:\n";
        string answer;
        std::cin >> std::ws;
        getline(cin , answer);
        answer =  "Answer(," + id_question+", ) "+ answer;
        question[id_question].push_back(answer);
        cout << "Your answer had sent.\n";
        ofstream fill("questions.txt" , ios::out);

        if(fill.is_open())
        {
           for(auto it:total_questions)
           {
               if(it.first[0] != 'A' )
               {
                   fill << '\n';
               }
               vector<string>v = it.second;
               for(auto s:v)
               {
                   if(s == ",,,") continue;
                   fill << s << '\n';
               }
           }
           fill << '\n';
            for(auto it:question)
            {
                string last ;
                vector<string>v = it.second;
                if(it.first[0] != 'A' )
                {
                    fill << '\n';
                }
                fill  <<  it.first << "," ;
                for(auto s:v)
                {
                    fill  << s << "\n" ;
                }
            }
            fill.close();
        }
        else
        {
            cout << "there is a problem in user_in_system.txt" << '\n';
        }
    }
    void Delete_question() {
        ifstream myfill("questions.txt" , ios::in);
        unordered_map<string, vector<string>>question , total_questions;

        if(myfill.is_open())
        {
            while (!myfill.eof())
            {
                string idd ="", from ="" , ques="" , to="" , line ="";

                getline(myfill , line);
                int i = 0;
                for( ; i < line.size();)
                {
                    if(line[i] == ',')
                    {
                        i++;
                        break;
                    }
                    else
                    {
                        idd += line[i];
                        i++;
                    }
                }

                for( ; i < line.size();)
                {
                    if(line[i] == ',')
                    {
                        i++;
                        break;
                    }
                    else
                    {
                        to += line[i];
                        i++;
                    }
                }
                for( ; i < line.size();)
                {
                    if(line[i] == ',')
                    {
                        i++;
                        break;
                    }
                    else
                    {
                        from += line[i];
                        i++;
                    }
                }

                for( ; i < line.size();)
                {
                    if(line[i] == ',')
                    {
                        i++;
                        break;
                    }
                    else
                    {
                        ques += line[i];
                        i++;
                    }
                }

                if(from == user_name)
                {
                    string answer;

                    question[idd].push_back(to +"," + from +","+ques);
                    while (getline(myfill, answer) ) {
                        if(answer[0] == 'A' and answer[1] == 'n' and answer[2] == 's')
                        {
                            question[idd].push_back(answer);
                        }
                        else break;
                    }
                }
                else
                {
                    if(idd == "Answer(")
                    {
                        total_questions[to].push_back(idd+','+to+','+from);
                    }
                    else
                    {
                        total_questions[idd].push_back( idd + ','+to + "," + from + ',' + ques);
                    }

                }
            }
            myfill.close();
        }
        else
        {
            cout << "there is a problem in user_in_system.txt" << '\n';
        }

        if(!print_questions_from_me())
        {
            cout << "\n==================================\n";
            cout << "So, you don't have questions to delet.\n";
            home_page();
        }
        cout << "enter ID of question you need to delet: \n";
        std::cin >> std::ws; // remove cin.ignor
        string id_question;
        getline(cin , id_question);

        if(!question[id_question].size())
        {
            if(total_questions[id_question].size())
            {
                cout << "\n==================================\n";
                cout << "This question don't belonge to you so isn't allow to you to delete." << '\n';
            }
            else
            {
                cout << "\n==================================\n";
                cout << "There is no question with this id\n";
            }
            home_page();
        }
        cout << "The question of the id you need to delet is " ;
        vector<string>m = question[id_question];
        for(auto q:m)
        {
            if(q[0] != 'A') // not Answer it is question
            {
                string to = "" , from = "" , ques = "";
                bool t = 0 , f = 0;
                int coma = 0;
                for(int i = 0; i < q.size(); i++)
                {
                    if(q[i] == ',')
                    {
                        i++;
                        coma++;
                    }
                    if(coma == 1) t = 1;
                    if(coma == 2) f = 1;
                    if(!t)
                    {
                        to += q[i];
                    }
                    if(t and !f)
                    {
                        from += q[i];
                    }
                    if(coma == 2)
                    {
                        ques += q[i] ;
                    }

                }
                cout << "to : " << to << '\n' << "Question: " << ques << '\n';
            }
            else
            {
                for(int i = 0; i < q.size(); i++)
                {
                    if(q[i] != ',') cout << q[i];
                }
                cout <<'\n';
            }
            cout << "\n==================================\n";
        }
       question.erase(id_question);

        cout << "Your question had deleted.\n";
        ofstream fill("questions.txt" , ios::out);

        if(fill.is_open())
        {
            for(auto it:total_questions)
            {
                if(it.first[0] != 'A' )
                {
                    fill << '\n';
                }
                vector<string>v = it.second;

                for(auto s:v)
                {
                    if(s == ",,,") continue;

                    fill << s << '\n';
                }
            }
            for(auto it:question)
            {
                string last ;
                vector<string>v = it.second;

                if(it.first[0] != 'A' )
                {
                     fill << '\n';
                }
                fill  <<  it.first << "," ;
                for(auto s:v)
                {
                    fill  << s << "\n" ;
                }
            }
            fill.close();
        }
        else
        {
            cout << "there is a problem in user_in_system.txt" << '\n';
        }
}
