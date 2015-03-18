#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head;

void prepend(int num)
{
    struct node *temp,*right;
    temp= (struct node *)malloc(sizeof(struct node));
    temp->data=num;
    right=(struct node *)head;
    while(right->next != NULL)
    right=right->next;
    right->next =temp;
    right=temp;
    right->next=NULL;
}


void append(int num)
{
    struct node *temp,*right;
    temp= (struct node *)malloc(sizeof(struct node));
    temp->data=num;
    right=(struct node *)head;
    while(right->next != NULL)
    right=right->next;
    right->next =temp;
    right=temp;
    right->next=NULL;
}

void add( int num )
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=num;
    if (head== NULL)
    {
      head=temp;
      head->next=NULL;
    }
    else
    {
      temp->next=head;
      head=temp;
    }
}

void addafter(int num, int loc)
{
    int i;
    struct node *temp,*left,*right;
    right=head;
    for(i=1;i<loc;i++)
    {
      left=right;
      right=right->next;
    }
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=num;
    left->next=temp;
    left=temp;
    left->next=right;
    
    return;
}



void insert(int num)
{
    int c=0;
    struct node *temp;
    temp=head;
    if(temp==NULL)
    {
      add(num);
    }
    else
    {
      while(temp!=NULL)
      {
        if(temp->data<num)
        c++;
        temp=temp->next;
      }
      if(c==0)
        add(num);
      else if(c<count())
        addafter(num,++c);
      else
        append(num);
    }
}


int delete(int num)
{
    struct node *temp, *prev;
    temp=head;
    while(temp!=NULL)
    {
      if(temp->data==num)
      {
        if(temp==head)
        {
          head=temp->next;
          free(temp);
          return 1;
        }
        else
        {
          prev->next=temp->next;
          free(temp);
          return 1;
        }
      }
      else
      {
        prev=temp;
        temp= temp->next;
      }
    }
    return 0;
}

void display(struct node *r)
{
    r=head;
    if(r==NULL)
    {
      return;
    }
    printf("%d ",r->data);
    printf("\n");
}

void rest(struct node *r)
{
    r=head->next;
    if(r==NULL)
    {
      return;
    }
    while(r!=NULL)
    {
      printf("%d ",r->data);
      r=r->next;
    }
    printf("\n");
}


int count()
{
    struct node *n;
    int c=0;
    n=head;
    while(n!=NULL)
    {
      n=n->next;
      c++;
    }
    return c;
}

int find(int num)
{

int flag = 0;
struct node *temp;

temp = head;
int n;

  while(temp!=NULL)
  {
    if(temp->data == num)
       return n; //Found
    temp = temp->next;
    n++;
  }

  if(flag == 0)
     return -1; // Not found

}

static struct node *bisectList(struct node *head)
{
    /* The fast pointer moves twice as fast as the slow pointer. */
    /* The prev pointer points to the node preceding the slow pointer. */
    struct node *fast = head, *slow = head, *prev = NULL;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    if (prev != NULL)
    {
        prev->next = NULL;
    }
    return slow;
}

static struct node* mergeList(struct node *list1, struct node *list2)
{
    struct node dummy_head = { 0, NULL }, *tail = &dummy_head;

    while ( (list1 != NULL) && (list2 != NULL) )
    {
        struct node **min = (list1->data < list2->data) ? &list1 : &list2;
        struct node *next = (*min)->next;
        tail = tail->next = *min;
        *min = next;
    }
    tail->next = list1 ? list1 : list2;
    return dummy_head.next;
}

void printList(struct node *root)
{
    while( root!= NULL)
    {
      printf("\n%d ", root->data);
      root = root->next;
    }

}


struct node *mergeSort(struct node *head)
{
    struct node *list1 = head;
    if ( (list1 == NULL) || (list1->next == NULL) )
    {
      return list1;
    }

    struct node *list2 = bisectList(list1);

    printf("\nList1 = ");
    printList(head);
    printf("\nList2 = ");
    printList(head);

    return mergeList( mergeSort(list1), mergeSort(list2) );
}

int  main()
{
    int i,num, c, pos, element;
    struct node *n, *temp;
    temp=head;
    head=NULL;
    while(1)
    {
      printf("\nList Operations\n");
      printf("===============\n");
      printf("1.Insert to front\n");
      printf("2.Insert to end\n");
      printf("3.Display first\n");
      printf("4.Display rest\n");
      printf("5.Size\n");
      printf("6.Delete\n");
      printf("7.Insert after\n");
      printf("8.Concat two lists\n");
      printf("9.Find an element\n");
      printf("10.Merge Sort\n");
      printf("0.Exit\n");
      printf("Enter your choice : ");
      
      if(scanf("%d",&i)<=0)
      {
        printf("Enter only an Integer\n");
        exit(0);
      } 
      else 
      {
        switch(i)
        {
        case 2:     printf("Enter the number to insert to the end: ");
                    scanf("%d",&num);
                    insert(num);
                    break;
	      case 1:     printf("Enter the number to insert to the front: ");
                    scanf("%d",&num);
		                if(temp==NULL)
		                {
    			            add(num);
    		            }
   	 	              else
    		            {
		                  c=count();
               	      addafter(num, c);
		                }
                    break;
        case 3:     if(head==NULL)
                    {
                      printf("List is Empty\n");
                    }
                    else
                    {
                      printf("Element(s) in the list are : ");
                    }
                    display(n);
                    break;
	case 4:     if(head==NULL)
                    {
                      printf("List is Empty\n");
                    }
                    else
                    {
                      printf("Element(s) in the list are : ");
                    }
                    rest(n);
                    break;
        case 5:     printf("Size of the list is %d\n",count());
                    break;
        case 6:     if(head==NULL)
                    printf("List is Empty\n");
                    else
                    {
                      printf("Enter the number to delete : ");
                      scanf("%d",&num);
                      if(delete(num))
                        printf("%d deleted successfully\n",num);
                      else
                        printf("%d not found in the list\n",num);
                    }
                    break;
	case 7:	    printf("Print the number and the element to print after\n");
		                scanf("%d%d", &num, &element);
		                addafter(num, element);
		                break;
	case 8:     printList(head); break;
	case 9:	    printf("Enter number to find\n");
		                scanf("%d", &num);
		                if((pos=find(num))>=0)
		                {
		                  printf("The element is in position %d", ++pos);
		                }
		                else
		                  printf("not found\n");
		                break;
	case 10:    mergeSort(NULL);
			              break;
        case 0:     return 0;
        default:    printf("Invalid option\n");
        }
      }
    }
    return 0;
}
