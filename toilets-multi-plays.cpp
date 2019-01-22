#include <iostream>
#include <set>
#include <stdlib.h>
#include <time.h>

//Consider the following: You are at a concert, but the venue doesn't have dedicated toilets. Instead, a row of porta-potties is availble to use, but as you can imagine, they're disgusting. You're the first one in line, so you get to pick which you'll use. You proceed as follows; you open a toilet, and decide to use this one, or move on to the next one. If you move to the next one, the one you just looked at is immediately taken; you cannot go back. You have a perfect memory of the quality of all toilets you have seen.

//The goal is to find how many toilets you should look at first, only to keep the next one you've found better than any of the previous, such that you end up with the best toilet on average.

using namespace std;


int set_rand(set<int> &set_dumb)
{
  int size=int(set_dumb.size());
  int rand_index=rand()%size;
  int count=0;
  for(set<int>::iterator s=set_dumb.begin(); s!=set_dumb.end();s++)
    {
      if(count==rand_index)
	{
	  return *s;
	}
      count++;
    }
}

int main()
{
  srand(time(NULL)); //Makes each time the code is run random.

  //Controls for the problem.
  int n_toilets=100;
  int stop_point=15;
  int n_tries=100;
  
  set<int> toilets_list;
  double best_avg=0;

  //Make a set of all toilet values.
  for(int i=0;i<n_toilets;i++)
    {
      toilets_list.insert(i+1);
    }

  //Play the game multiple times.
  for(int j=0;j<n_tries;j++)
    {
      set<int> toilets_temp=toilets_list;
      int best_toilet=0;
      //Randomly assign those values to an array so that they're in an random order.
      int toilets[n_toilets];
      for(int i=0;i<n_toilets;i++)
	{
	  toilets[i]=set_rand(toilets_temp);
	  toilets_temp.erase(toilets[i]);
	}

  
      //go through the toilets until you've seen up to stop point.
      for(int i=0;i<stop_point;i++)
	{
	  if(toilets[i]>best_toilet)
	    {
	      best_toilet=toilets[i];
	    }
	}

      //Then go through the rest
      for(int i=stop_point;i<n_toilets;i++)
	{
	  //Stop if you find a new best
	  if(toilets[i]>best_toilet)
	    {
	      best_toilet=toilets[i];
	    }
	  //Or live with the last one if they all suck.
	  if(i==n_toilets-1)
	    {
	      best_toilet=toilets[i];
	    }
	}
      best_avg+=best_toilet;
    }
  cout<<"After "<<stop_point<<" skipped toilets, the best average toilet is: "<<best_avg/n_tries<<endl;
  
  return 0;
}
