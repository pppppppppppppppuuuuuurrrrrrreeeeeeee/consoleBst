#include<bits/stdc++.h>
using namespace std;
typedef unsigned int ui;



struct node
{
    ui plateValue;
    string passedtime;
    string passedVehicleRecordId;
    struct node *left, *right;
};

struct node *create(ui pv, string pt, string pvri)
{
    struct  node *t;
	t = new node;
    t->plateValue = pv;
    t->passedtime = pt;
    t->passedVehicleRecordId = pvri;
    t->left = t->right = NULL;
    return t;
}

struct node* insert(struct node* n, ui pv, string pt, string pvri)
{
    if (n == NULL) 
	    return create(pv, pt, pvri);
 
    if (pv < n->plateValue)
        n->left  = insert(n->left , pv, pt, pvri);
        
    else if (pv > n->plateValue)
        n->right = insert(n->right, pv, pt, pvri);
 
    return n;
}

pair<bool, node*> search(struct node *r, ui plate)
{
    pair <bool, node*> p;
    while (r != NULL)
    {
        if (plate > r->plateValue)
            r = r->right;
 
        else if (plate < r->plateValue)
            r = r->left;
        else {
            p.first = true;
            p.second = r;
            return p;
        }
    }
    p.first = false;
    return p;
}

void inorder(struct node *r)
{
    if (r != NULL)
    {
        inorder(r->left);
        cout<< r->passedVehicleRecordId <<"  " << r->passedtime << "  " << r->plateValue << endl;
        inorder(r->right);
    }
}

ui randomPlate()
{
    return 100000000 + (rand() % static_cast<int>(999999999 - 100000000 + 1));
}
string randomDateTime()
{
    string year = to_string(2000 + (rand() % static_cast<int>(2020 - 2000 + 1)));
    string month = to_string(1 + (rand() % static_cast<int>(12 - 1 + 1)));
    string day = to_string(1 + (rand() % static_cast<int>(30 - 1 + 1)));

    if(month.size() == 1) month = "0" + month;
    if(day.size() == 1) day = "0" + day;
    string date = (year) + '-' + (month) + '-' + (day);

    string h = to_string(1 + (rand() % static_cast<int>(23 - 1 + 1)));
    string m = to_string(1 + (rand() % static_cast<int>(59 - 1 + 1)));
    string s = to_string(1 + (rand() % static_cast<int>(59 - 1 + 1)));
    if(h.size() == 1) h = "0" + h;
    if(m.size() == 1) m = "0" + m;
    if(s.size() == 1) s = "0" + s;
    string time = (h) + ':' + (m) + ':' + (s);

    return date + ' ' + time;
}

int main()
{
    struct node *r = NULL;

   
    r = insert(r, 0, "2020-01-01 00:00:00", "0");
    ui counter = 1;
   

    string dateTime;
    int num;
    pair<bool, node*> p;
    clock_t Start, End;
    while (1)
    {
        cout << "please choose your action:" << endl;
        cout << "1: add a node exclusivly: " << endl;
        cout << "2: add (n) nodes random" << endl;
        cout << "3: search by plate:" << endl;
        cout << "4: inorder traversal:" << endl;
        cout << "5: exit" << endl;
        cin >> num;
        switch (num)
        {
            case 1:
                cout << "insert plate:" << endl;
                ui plate;
                cin >> plate;
                cout << "insert date and time with format (yyyy-mm-dd hh:ii:ss)" << endl;
                cin.ignore();
                getline(cin, dateTime);
                insert(r, plate, dateTime, to_string(counter));
                counter++;
            break;

            case 2:
                cout << "how many nodes do u want to insert randomly?" << endl;
                ui count;
                cin >> count;
                for(auto i = 0; i < count; i++) {
                    insert(r, randomPlate(), randomDateTime(), to_string(counter));
                    counter++;
                }
            break;

            case 3:
                cout << "please insert your plate value:";
                ui fplate;
                cin >> fplate;
                Start = clock();
                p = search(r, fplate);
                if(p.first) {
                    cout << "**** plate founded! *****" << endl;
                    cout << "pid date      time      plate" << endl;
                    node *f = p.second;
                    cout<< f->passedVehicleRecordId <<"  " << f->passedtime << "  " << f->plateValue << endl;
                } else {
                    cout << "**** sorry, we cant find your plate ****" << endl;
                }
                End = clock();
                cout << "time difference : " << End - Start << " ms!" << endl;

            break;

            case 4:
                cout << "*************************************" << endl;
                cout << "pid date      time      plate" << endl;

                inorder(r);
                cout << "*************************************" << endl;
            break;

            case 5:
                return 0;
            break;
        }
    }
    
	return 0;
}
