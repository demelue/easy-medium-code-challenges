
#include <stdlib.h>
#include <stdio.h>

class NumberList
{
    //Do not initialize here do it in an init function or constructor
    uint16_t *ptrStorage;
    uint16_t storage_size;
    int current_sample_index;

public:
    void init(int size)
    {
      ptrStorage = (uint16_t *) calloc(size, sizeof(uint16_t));
      storage_size = size;
      current_sample_index = 0;
    }

    void addSample(uint16_t sample)
    {
      if (ptrStorage != NULL)
      {
        if (storage_size == 0)
        {
            printf("Initialize Storage");
            return;
        }

        if (current_sample_index < storage_size)
        {
          ptrStorage[current_sample_index] = sample;
          current_sample_index++;
          printf("Added %hu\n", sample);
        }
        else
        {
          printf("Array is full");
        }
      }
    }


    uint16_t * getSamples()
    {
      if (ptrStorage != NULL)
      {
        return ptrStorage;
        printf("Done\n");
      }
      else
      {
        printf("List is Null");
      }
      return NULL;
    }

    void printList()
    {
      for (int i = 0; i < storage_size; i++)
      {
        printf("%hu\n", *ptrStorage++);
      }
    }

    void destroy()
    {
      if (ptrStorage != NULL)
      {
        free(ptrStorage);
      }
    }
};
