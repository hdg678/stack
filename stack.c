void stack_push(int data)
{ if(array_used < array_size - 1){
	array[array_used] = data;
	array_used = array_used + 1;
	return; 
  }
  int *array2 = malloc(array_size * sizeof(int) * 2);
  for(int i = 0; i < array_used; ++i) array2[i] = array[i]; 
  free(array);
  array = array2;
  array_size = array_size * 2;
  stack_push(data);
}

void stack_print(void)
{ for(int i = 0; i < array_used; ++i) printf("%d ", array[i]);
  printf("\n");
}

int stack_pop()
{	if(array_used == 0){ printf("There is nothing left to pop"); exit(1);}
	int t = array[array_used - 1];
	array_used = array_used - 1;
	return t;
}

int stack_peak()
{	if(array_used == 0){ printf("There is nothing left to peak"); exit(1);}
	int t = array[array_used - 1];
	return t;
}

int stack_size() 														// this is how much you can pop.
{	return array_used;
}

int main(void)
{
  printf("Hello World\n");
  stack_create();
  assert(stack_size() == 0);
  for(int n = 1; n < 15; ++n) stack_push(n);
  stack_print();
  stack_push(11);
  assert(stack_size() == 15);
  assert(stack_peak() == 11);
  stack_print();
  int f1 = stack_pop();
  printf("%d \n", f1);
  stack_push(4);
  int f2 = stack_pop();
  printf("%d \n", f2);
  return 0;
}   
