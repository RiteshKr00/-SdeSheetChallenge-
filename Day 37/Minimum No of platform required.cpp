/**********************************************************
 * M1:----------->
 * Sort ht array according to arrival time and
 * Use a priority queue for departing time ->pq will give earliest departing
 * train to compare with arrival of next train.
 * Declare a priority queue(min-heap) and store the departure time of the first train and also declare a counter cnt and initialize it with 1.
 * Iterate over arr from 1 to n-1 
 *check if the arrival time of current train is less than or equals to the departure time of previous train which is kept on top of the priority queue
 *If true, then push the new departure time and increment the counter cnt
  otherwise, we pop() the departure time
 *push new departure time in the priority queue
 *Finally, return the cnt.
 Time Complexity: O(N*log(N))
  Auxiliary Space: O(N)
 * M2------------>The idea is to consider all events in sorted 
    order. Once the events are in sorted order, 
    trace the number of trains at any time keeping track 
    of trains that have arrived, but not departed.
   T.C: O(N * log N)
    S.C:O(1)

  M3-> consider max hours in a day:2361
  we use an array of time duration size and stor the maximum no 
  of train at any given time.
  for arrival increment arr[arival time]++;
  for departing time decrement 1 sec after arr[depart + 1sec]
    T.C->O(N)
    S.C->O(N)
 ***********************************************************/

int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at,at+n);
    sort(dt,dt+n);
    int i=1,j=0;
    int plat=1,result=1;
    while(i<n&&j<n){
        if(at[i]<=dt[j])
        {   
            plat++;
            i++;
        }
        else if(at[i]>dt[j]){
            plat--;
            j++;
        }
        
        //update max
        if(plat>result)
            result=plat;
    }
    return result;
}