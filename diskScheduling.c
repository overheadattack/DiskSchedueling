#include <stdio.h>
#include <stdlib.h>

#define LOW 0 //need this for C-LOOK for it to know what is the lowest and highest
#define HIGH 250

//group4 Noah L, Allison S, Marcel J, Karen F
int main(){
//choose the disk algorithm  between 0-3
int choosenumber;
printf("Enter a number between 0-3 0=FCFS, 1=SSTF, 2=LOOK, 3=C-LOOK\n");
printf("otherwise program will exit\n");
scanf("%d", &choosenumber);

//every section is compartemelized by if statements
//could be improved with calling functions to make it less messy

if(choosenumber == 0){ //FCFS
    FILE *myFile;
    myFile = fopen("sequence", "r"); //file name sequence

    //read file into array
    int sequence[20]; //reads the 20 int input
    int numberArray[2]; //reads the head and direction
    int i;
    //variables
    int n, a, j, diff, head, seek=0,seek1=0, tmp, temp, que1[20], que2[20], temp1=0, temp2=0;
    n = 22;
    if (myFile == NULL){
        printf("Error Reading File\n");
        exit (0);
    }
    //reads the file and stores it into size 2 array
    for (i = 0; i < 2; i++){
        fscanf(myFile, "%d,", &numberArray[i] );
    }
    //gets the 20 int sequence for the disk schedueling to run
    for (i = 1; i < 21; i++){
        fscanf(myFile, "%d,", &sequence[i] );
    }
    //test prints
    //for (i = 0; i < 2; i++){
    //    printf("Number is: %d\n", numberArray[i]);

    //}
    //for (i = 1; i < 21; i++){
    //    printf("%d, ", sequence[i]);

    //}
    //	printf("\n");

	int Starting_Pos = numberArray[0]; //starting head postion
        int Direction  =  numberArray[1]; //direction
	sequence[0] = numberArray[0]; //sets postion 0 as head position
        // test prints
	//printf("\n");
        //printf("Starting Number is: %d\n", Starting_Pos);
        //printf("Direction is: %d\n", Direction);



	for(j=0;j<=19;j++)
            {
                        diff=abs(sequence[j+1]-sequence[j]);
                        seek+=diff;
                        printf("Disk head moves from %d to %d with seek %d\n",sequence[j],sequence[j+1],diff);
            }
	     printf("Total seek time is %d\n",seek);
	fclose(myFile);
	}




if(choosenumber == 1){ //SSTF

    FILE *myFile; //need this to read from a file
    myFile = fopen("sequence", "r"); //condition to read from file

    //arrays and vars
    int sequence[20];
    int numberArray[2];
    int i;
    int n, a, j, diff, head, seek=0,seek1=0, tmp, temp, que1[20], que2[20], temp1=0, temp2=0;
    n = 22;
    if (myFile == NULL){
        printf("Error Reading File\n");
        exit (0);
    }
    //same as before reads first 2 ints and then 20 ints
    for (i = 0; i < 2; i++){
        fscanf(myFile, "%d,", &numberArray[i] );
    }
    for (i = 1; i < 21; i++){
        fscanf(myFile, "%d,", &sequence[i] );
    }

    //sorts the array in lowest to highest
        for(int i = 0; i < 21; i++)
        {
                for(int j = i + 1; j < n; j++)
                {
                        if(sequence[j] < sequence[i])
                        {
                        int tmp = sequence[i];
                        sequence[i] = sequence[j];
                        sequence[j] = tmp;

                        }
                }

        }
	//prints the sorted array
        //for(i=0; i<21; i++)
        //{
        //printf("%d, ", sequence[i]);
        //}
        //printf("\n");
	sequence[0] = numberArray[0]; //1 equals to intial head postion
	//prints the disk head movements
	for(j=0;j<=19;j++)
            {
                        diff=abs(sequence[j+1]-sequence[j]);
                        seek1+=diff;
                        printf("Disk head moves from %d to %d with seek %d\n",sequence[j],sequence[j+1],diff);
            }
             printf("Total seek time is %d\n",seek1);
             fclose(myFile);
	}

if(choosenumber == 2){//LOOK
   //needed to read thee file
   FILE *myFile;
   myFile = fopen("sequence", "r");
   //vars and arrays
   int arr1[20], queue[20], q_size, head[0],a, i,j, seek=0, diff, max, temp[20], queue1[20], queue2[20], temp1=0, temp2=0;
   int  numberArray[2];

        //if file is not found
        if (myFile == NULL){
        printf("Error Reading File\n");
        exit (0);
        }
	//scans the file
        for (i = 0; i < 2; i++){
        fscanf(myFile, "%d,", &numberArray[i] );
        }
        head[0] = numberArray[0];
        //printf("%d\n", head[0]);
        int Direction  =  numberArray[1];
        // int test1[20];

        q_size = 20;
	//reads the file into an array
        for(i=0; i<30; i++){

        fscanf(myFile, "%d\n", &temp[i]);

        }
	//sorts the file based on starting head position
for(i=0; i<22; i++){
    //queue1 - elems greater than head
    if(temp[i] >= head[0]){
      queue1[temp1] = temp[i];
      temp1++;
    } else {
      queue2[temp2] = temp[i];
      temp2++;
    }
}
  //Sorts both arrays

  //sort queue1 - increasing order
  for(i=0; i<temp1-1; i++){
    for(j=i+1; j<temp1; j++){
      if(queue1[i] > queue1[j]){
        temp[j] = queue1[i];
        queue1[i] = queue1[j];
        queue1[j] = temp[j];
      }
    }
  }

  //sort queue2
  for(i=0; i<temp2-1; i++){
    for(j=i+1; j<temp2; j++){
      if(queue2[i] > queue2[j]){
        temp[i] = queue2[i];
        queue2[i] = queue2[j];
        queue2[j] = temp[i];
      }
    }
  }
  //calculates the head movements
  if(abs(head[i]-LOW) <= abs(head[i]-HIGH)){

     for(i=1,j=0; j<temp1; i++,j++){
          queue[i] = queue1[j];
      }

      for(i=temp1+1, j=0; j<temp2; i++, j++){
          queue[i] = queue2[j];
      }
  } else {

      for(i=1,j=0; j<temp2; i++,j++){
          queue[i] = queue2[j];
      }

      for(i=temp2+1, j=0; j<temp1; i++, j++){
          queue[i] = queue1[j];
      }

  }

  queue[0] = head[0];
  //prints out the head movements and calculates
  for(j=0; j<24; j++){
    diff=abs(queue[j+1] - queue[j]);
    seek += diff;
    printf("Disk head moves from %d to %d with seek %d\n",queue[j],queue[j+1],diff);

  }


  printf("Total seek time is %d\n", seek);
  fclose(myFile);
}
if(choosenumber == 3){//C-LOOK

   FILE *myFile;
   myFile = fopen("sequence", "r");
  //vars and arrays
  int arr1[20], queue[20], head[0], q_size, i,j, seek=0, diff, max, min, range, temp[20], queue1[20], queue2[20], temp1=0, temp2=0;
  int  numberArray[2];

	//same as before reads the file
        if (myFile == NULL){
        printf("Error Reading File\n");
        exit (0);
        }
        for (i = 0; i < 2; i++){
        fscanf(myFile, "%d,", &numberArray[i] );
        }
        head[0] = numberArray[0];
        // printf("%d\n", head[0]);
        int Direction  =  numberArray[1];
        int test1[20];

        q_size = 20;

        for(i=0; i<30; i++){

        fscanf(myFile, "%d\n", &temp[i]);

        }

  for(i=0; i<22; i++){
    //sorts into two arrays based on head
    //queue1 - elems greater than head
    if(temp[i] >= head[0]){
      queue1[temp1] = temp[i];
      temp1++;
    } else {
      queue2[temp2] = temp[i];
      temp2++;
    }
  }

  //sorts the arrays

  //sort queue1 - increasing order
  for(i=0; i<temp1-1; i++){
    for(j=i+1; j<temp1; j++){
      if(queue1[i] > queue1[j]){
        temp[j] = queue1[i];
        queue1[i] = queue1[j];
        queue1[j] = temp[j];
      }
    }

 //sort queue2
  for(i=0; i<temp2-1; i++){
    for(j=i+1; j<temp2; j++){
      if(queue2[i] > queue2[j]){
        temp[i] = queue2[i];
        queue2[i] = queue2[j];
        queue2[j] = temp[i];
      }
    }
  }
  //calculates the head movements
  if(abs(head[i]-LOW) <= abs(head[i]-HIGH)){

    for(i=1,j=temp2-1; j>=0; i++,j--){
        queue[i] = queue2[j];
    }

    queue[i] = LOW;
    queue[i+1] = HIGH;

    for(i=temp2+3,j=temp1-1; j>=0; i++,j--){
        queue[i] = queue1[j];
    }

  } else {

    for(i=1,j=0; j<temp1; i++,j++){
        queue[i] = queue1[j];
    }

    queue[i] = HIGH;
    queue[i+1] = LOW;

    for(i=temp1+3,j=0; j<temp2; i++,j++){
        queue[i] = queue2[j];
    }


  }
  queue[0] = head[0];
  //prints out the head movements
  for(j=0; j<24; j++){
    diff=abs(queue[j+1] - queue[j]);
    seek += diff;
    printf("Disk head moves from %d to %d with seek %d\n",queue[j],queue[j+1],diff);

  }


  printf("Total seek time is %d\n", seek);
  fclose(myFile);
}
}else{
//exits program
exit(0);

}
    return 0;
}

