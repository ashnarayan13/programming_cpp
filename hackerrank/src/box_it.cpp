#include<bits/stdc++.h>

using namespace std;

class Box{
    private:
    int l, b, h;
    
    public:
    Box(){
        l=0;
        b=0;
        h=0;
    }
    Box(int _l, int _b, int _h){
        l = _l;
        b = _b;
        h = _h;
    }
    Box(const Box &_b){
        l = _b.l;
        b = _b.b;
        h = _b.h;
    }
    int getLength(){
        return l;
    }
    int getBreadth(){
        return b;
    }
    int getHeight(){
        return h;
    }
    long long CalculateVolume(){
        return (long long)l*b*h;
    }
    bool operator<(const Box &B){
        if(l < B.l || (b < B.b && l==B.l) || (h < B.h && b==B.b && l==B.l))
            return true;
        else
            return false;
    }
};

ostream& operator<<(ostream& out, Box B){
    return out<<B.getLength()<<' '<<B.getBreadth()<<' '<<B.getHeight();
}

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}