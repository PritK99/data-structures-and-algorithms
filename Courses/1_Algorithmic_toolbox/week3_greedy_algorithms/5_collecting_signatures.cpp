# include <iostream>

using namespace std ;

int main ()
{
  int n;
  cin >> n;

  int start[n] = {0};
  int end[n] = {0};

  for (int i = 0 ; i < n ; i++)
  {
    cin >> start[i] >> end[i] ;
  }

  // for (int i = 0 ; i < n ; i++)
  // {
  //   for (int j = 0 ; j < n ; j ++)
  //   {
  //     if (i == j)
  //     {
  //       continue ;
  //     }

  //     if ((start[i] > start[i] && start[i] < end[j]) || (end[i] > start[i] && end[i] < end[j]) )
  //     {
  //       int temp1 = parent[i] ;
  //       int temp2 = parent[j] ;
  //       for (int k = 0 ; k < n ; k++)
  //       {
  //         if (parent[k] == temp2)
  //         {
  //           parent[k] = temp1 ;
  //         }
  //       }
  //     }
  //   }
  // }


  return 0;
}