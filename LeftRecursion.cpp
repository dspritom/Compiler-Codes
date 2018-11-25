#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);

    string productions;
    cin >> productions;

    vector<string> recursive, non_recursive;

    string temp = "";
    char start_var = productions[0];

    for (int i = 3; i < productions.length(); i++)
    {
        if (productions[i] == '|')
        {
            if (temp[0] == start_var)
            {
                recursive.push_back(temp);
                temp = "";
            }
            else
            {
                non_recursive.push_back(temp);
                temp = "";
            }
        }
        else
        {
            temp += productions[i];
        }
    }
    if (temp != "")
    {
        if (temp[0] == start_var)
        {
            recursive.push_back(temp);
            temp = "";
        }
        else
        {
            non_recursive.push_back(temp);
            temp = "";
        }
    }
    if (temp == "empty")
    {
        non_recursive.push_back(temp);
        temp = "";
    }

    cout << start_var << "->";
    for (int i = 0; i < non_recursive.size()-1; i++)
    {
        cout << non_recursive[i] << start_var << "'" << "|";
    }
    cout << non_recursive[non_recursive.size()-1] << start_var << "'" << endl;
    cout << start_var << "'->";
    for (int i = 0; i < recursive.size(); i++)
    {
        string alpha = "";
        for (int j = 1; j < recursive[i].size(); j++)
        {
            alpha += recursive[i][j];
        }

        cout << alpha << start_var << "'|";
    }
    cout << "empty" << endl;

    return 0;
}


/* You can check these :
    Input: E->E+T|T
    Output: E->TE'
            E'->+TE'|empty
    Input: A->Ac|Aad|bd|empty
    Output: A->bdA'|emptyA'
            A'->cA'|adA'|empty
    Input: E->E+T|E-T|+T|-T|T
    Output: E->+TE'|-TE'|TE'
            E'->+TE'|-TE'|empty
*/
