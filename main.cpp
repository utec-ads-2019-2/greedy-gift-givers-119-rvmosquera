#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

string *names;

int find_name(string name, int n) {
    for (int k = 0; k < n; k++) {
        if (names[k] == name)
            return k;
    }
}

int main(int argc, char *argv[]) {

    int *friends_money;
    int number;
    int givings;
    string name;
    bool first = true;
    int money, money_per_friend;

    while (cin >> number) {
        names = new string[number];
        friends_money = new int[number];

        for (int i = 0; i < number; i++) {
            cin >> names[i];
            friends_money[i] = 0;
        }

        for (int j = 0; j < number; j++) {
            cin >> name;

            auto index_giver = find_name(name, number);

            cin >> money;

            givings = 0;
            cin >> givings;

            if (givings != 0)
                friends_money[index_giver] = friends_money[index_giver] - money;

            if (givings != 0)
                money_per_friend = money / givings;
            else
                continue;

            friends_money[index_giver] = friends_money[index_giver] + (money - money_per_friend * givings);

            for (int i = 0; i < givings; i++) {
                cin >> name;

                auto index = find_name(name, number);

                friends_money[index] = friends_money[index] + money_per_friend;
            }
        }

        if (first)
            first = false;
        else
            cout << endl;

        for (int i = 0; i < number; i++)
            printf("%s %d\n", names[i].c_str(), friends_money[i]);


        friends_money = nullptr;
        delete[] friends_money;

        names = nullptr;
        delete[] names;
    }

    return EXIT_SUCCESS;
}
