#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	//输入字符串 
	int j;
	char c[101];
	scanf("%s",c);
	//判断 ：1，只有P T各一个，且P在前。其余都是A。2，PT不能连在一起。    才正确 
	int count=0,count1=0,count2=0;
	//只有一个p 
	for(j=0;j<=strlen(c);j++)
	{
		c[j]='P';
		count++; 
		if(count==2)
		{
		cout<<"NO"<<'\n';
		break;
		
		
	    }
		else {		
	         //只有一个T 
	         for(j=0;j<=strlen(c);j++)
	       {
		    c[j]='T';
		       count1++; 
		      if(count1==2)
		     {
			 cout<<"NO"<<'\n';break;}
		     //PT不挨着 
		        else
				 {
				 	string s=c;
				 	    count=s.find("P");//找字符对应位置 
					 	count1=s.find("T");
				 	j=count-count1;
				 	if(j<=-2)
				 	{
				 		cout<<"NO"<<'\n';
				 		break;
					 }
					 else//其余都是A 
					 {
					 	for(j=0;j<=count||count<j<count1||count1<j<=strlen(c);j++)
						 {
						 	if(c[j]=='A'){
							 
						 	cout<<"YES"; break;}
						 	else{
							 cout<<"NO";
						 	break;}
						  } 
						  break;
					 	
					 }
					 break;
				}
				break; 
            
                
			}
			break;
				     
		}	 		
	}
} 
 

