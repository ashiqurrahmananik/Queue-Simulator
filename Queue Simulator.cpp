#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
vector<int>v;
queue<int>q;
int hours, minutes, day, month, year;
double seconds;
void start_time()
{
    time_t now;

    time(&now);

    struct tm *local = localtime(&now);

    hours = local->tm_hour;
    minutes = local->tm_min;
    seconds = local->tm_sec;
    day = local->tm_mday;
    month = local->tm_mon + 1;
    year = local->tm_year + 1900;
}
void display()
{
    cout<<endl<<endl<<endl;
    cout<<"Arrival Time"<<"     "<<"               Service Start Time"<<"        "<<"Waiting Time(sec)"<<"        "<<"Service End Time"<<"        "<<"Elements IN The Queue"<<endl;
}
void please_wait()
{
    cout<<"P";
    Sleep(200);
    cout<<"l";
    Sleep(200);
    cout<<"e";
    Sleep(200);
    cout<<"a";
    Sleep(200);
    cout<<"s";
    Sleep(200);
    cout<<"e";
    Sleep(200);
    cout<<" ";
    cout<<"W";
    Sleep(200);
    cout<<"a";
    Sleep(200);
    cout<<"i";
    Sleep(200);
    cout<<"t";
    Sleep(200);
    cout<<".";
    Sleep(200);
    cout<<".";
    Sleep(200);
    cout<<".";
    Sleep(200);
    cout<<".";
    Sleep(200);
    cout<<".";
    Sleep(200);
     cout<<".";
    Sleep(200);
    cout<<".";
    Sleep(200);
    cout<<".";
    Sleep(200);
    cout<<".";
    Sleep(200);
    cout<<".";
    Sleep(200);
    cout<<endl;
}
void time_fixed(int s)
{
    double sum=s;
    int h=(sum/60)/60;
    double p=(sum/60)/60;
    double b=p-h;
    double q=b*60*60;
    int a=q/60;
    double e=q/60;
    double f=e-a;
    hours=h;
    minutes=a;
    seconds=f*60;
    if (hours < 12)
        printf("%02d:%02d:%0lf am", hours, minutes, seconds);

    else
        printf("%02d:%02d:%0lf pm", hours - 12, minutes, seconds);
    cout<<"               ";
}
void print_time()
{
    if (hours < 12)
        printf("%02d:%02d:%02lf am", hours, minutes, seconds);

    else
        printf("%02d:%02d:%02lf pm", hours - 12, minutes, seconds);
    cout<<"               ";
}
void design()
{
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                   ";
}
int main()
{
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                   ";
    cout<<"Welcome To Single Server Queue Simulator"<<endl;
    Sleep(1000);
    system("cls");
    while(1)
    {
        int n,x;
        design();
        cout<<"Number Of Customer :";
        cin>>n;
        system("cls");
        design();
        cout<<"Service Time(sec) :";
        cin>>x;
        system("cls");
        for(int i=1; i<=n; i++)
        {
            start_time();
            int l=rand()%n;
            int a=(hours*60*60)+(minutes*60)+seconds;
            if(i%2==0)
                Sleep(1000);
            else
                Sleep(2000);
            q.push(l);
            v.push_back(a);
        }
        double  sum_avg=0;
        design();
        please_wait();
        display();
        for(int i=0; i<n; i++)
        {
            cout<<"         "<<endl;
            time_fixed(v[i]);
            if(i==0)
            {
                print_time();
                //cout<<"Waiting Time"<<endl;
                cout<<0;
                cout<<"       ";
                //cout<<"service end time"<<endl;
                time_fixed(v[i]+x);
            }
            else
            {
                if(v[i]>v[i-1]+x)
                {
                    time_fixed(v[i]);
                    sum_avg+=(v[i])-(v[i]);
                    cout<<v[i]-(v[i]);
                    cout<<"       ";
                    time_fixed(v[i]+x);
                }
                else
                {
                    time_fixed(v[i-1]+x);
                    sum_avg+=(v[i-1]+x)-(v[i]);
                    cout<<(v[i-1]+x)-(v[i]);
                    cout<<"       ";
                    time_fixed(v[i]+x);
                }

            }
            cout<<i+1<<endl;
            cout<<"---------------------------------------------------------------------------------------------------------------------"<<endl;

        }
        cout<<endl;
        cout<<endl;
        cout<<"                                      Average waiting time(sec): ";
        cout<<sum_avg/n<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"    You Wanna Do Simulation Again?"<<endl<<endl;
        cout<<"    Press Any Number For Continue"<<endl;
        int aa;
        cin>>aa;
        system("cls");
    }
}
