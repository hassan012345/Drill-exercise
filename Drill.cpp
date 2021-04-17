#include <iostream>
#include <vector>
using namespace std;
double convert_meter(double,string);
int main()
{
	double len,sum=0,smallest,largest;
	vector<double>all_lens;
	string unit;
	int no_of_values=0;
	bool enter=true;
	cout<<"Enter a double value followed by unit among m,cm,in and ft only.\n";
	while(cin>>len>>unit)
	{
		if(unit !="m" && unit !="cm" && unit!="in" && unit !="ft")
			cout<<"Invalid unit entered!Enter again.";
		else 
			{
				no_of_values++;
				sum +=convert_meter(len,unit);
				all_lens.push_back(len);
			}
			
		if(enter==true)
			{
				smallest=convert_meter(len,unit);
				largest=convert_meter(len,unit);
				enter=false;
			}
			
		if(convert_meter(len,unit)<smallest)
			smallest=convert_meter(len,unit);
		else if(convert_meter(len,unit)>largest)
			largest=convert_meter(len,unit);
		
		cout<<"\nTotal no of values are: "<<no_of_values;
		cout<<"\nSum of values is: "<<sum;
		cout<<"\nThe smallest value entered sofar is: "<<smallest;
		cout<<"\nThe largest value entered sofar is: "<<largest;
		
	}
	for(int i=0;i<all_lens.size()-1;i++)
			{
				double current_min=all_lens[i];
				int min_index=i;
				for(int j=i+1;j<all_lens.size();j++)
					{
						if(current_min>all_lens[j])
						{
							current_min=all_lens[j];
							min_index=j;
						}
					}
				if(min_index != i)
				{
					all_lens[min_index]=all_lens[i];
					all_lens[i]=current_min;
				}
			}
			
			cout<<"\nAll of your entered values converted into meters are:";
		for(int i=0;i<all_lens.size();i++)
			{
				cout<<all_lens[i]<<"m";
				cout<<'\t';
			}	
}
double convert_meter(double val,string uni)
{
	if(uni=="m")
		return val;
	else if(uni=="cm")
		return val/100;
	else if(uni=="in")
		return val/39.7;
	else if(uni=="ft")
		return val/3.281;
}
