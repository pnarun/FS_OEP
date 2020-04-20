#include<iostream>
#include<string>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<cstring>
using namespace std;
class items
{
    char itemname[25];
    float itemid;
    float itemprice;
    float itemrating;
    public:void read()
           {
                items it;
                ofstream fp;
                fp.open("itemfeed.dat");
                for(int i=0;i<5;i++)
                {
                    cout<<"DETAILS:"<<endl;
                    cout<<"ID:";
                    cin>>it.itemid;
                    cin.ignore();
                    cout<<"NAME:";
                    cin>>it.itemname;
                    cout<<"PRICE:";
                    cin>>it.itemprice;
                    cout<<"RATING:";
                    cin>>it.itemrating;
                    fp.write((char*)&it,sizeof(it));
                }
                fp.close();
           }
           void display()
           {
                fstream fp;
                fp.open("itemfeed.dat");
                items it;
                fp.read((char*)&it,sizeof(it));
                while(!fp.eof())
                {
                    cout<<"*********************************************************"<<endl;
                    cout<<"ID:";
                    cout<<it.itemid<<endl;
                    cout<<"NAME:";
                    cout<<it.itemname<<endl;
                    cout<<"PRICE:";
                    cout<<it.itemprice<<endl;
                    cout<<"RATING:";
                    cout<<it.itemrating<<endl;
                    cout<<"*********************************************************"<<endl;
                    fp.read((char*)&it,sizeof(it));
                }
                fp.close();

           }

};

int main()
{
    items i1;
    i1.read();
    i1.display();
    return(0);
}
