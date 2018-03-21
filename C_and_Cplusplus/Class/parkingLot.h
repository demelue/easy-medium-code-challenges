#include <stdlib.h>
#include <stdio.h>


class parkingLot
{
  int lotA [14] = {0};
  int lotB [14] = {0};
  int lotC [16] = {0};
  int lotD [16] = {0};

  bool find_space_in_lot(int lot[], int lot_size, int car_size, )
  {
    int spot_counter = 0;
    for (int i = 0; i < lot_size; i++)
    {
      if (lot[i] == 0)
      {
        spot_counter ++;
      }

      if (spot_counter == car_size)
      {
        return true;
      }
    }
    return false;
  }

};
